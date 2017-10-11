#include <SoftwareSerial.h> //include library serial port /1 bit Ẻ͹ء��

SoftwareSerial myGsm(2,3); //set TX,RX = pin 2,3

const int US100_TX = 8;  // set TX = pin 8 inteter constance �����Ū�Դ�ӹǹ��� �����ͷ�� 2 byte -32,768 �֧ 32,767
const int US100_RX = 9; //  set RX = pin 9 

//ultrasonic detection range: 2 cm-450 cm
//distance = (�����觤���价��ҹ����ش * �������Ǣͧ����͹���§ (340 M/S)) / 2
SoftwareSerial puertoUS100(US100_RX, US100_TX); //���ҧ function puretoUS100 Ẻ Serial pin (8,9) 

unsigned int MSByteDist = 0; //�����Ū�Դ�ӹǹ��� ���Դ����ͧ���� 0 �֧ 65,535
unsigned int LSByteDist = 0; 

float mmDist = 0; //�����Ū�Դ�Ţ�ȹ��� �����ͷ�� 4 byte
int temp = 0;
String level;

void setup() {
    Serial.flush();  // ������Buffer �ͧ port (Serial) �����ҧ
    myGsm.flush(); // ������Buffer �ͧ port (myGsm) �����ҧ
    delay(10000);
    Serial.begin(9600); //set baud rate to 9600 ��������㹡���Ѻ-�� ������
    toSerial();
    myGsm.begin(9600); //set baud rate to 9600 ��������㹡���Ѻ-�� ������
    toSerial();
    Serial.println("Config SIM800...");
    delay(2000);
    Serial.println("Done!...");
    toSerial();
    myGsm.println("AT+CGATT?"); //��Ǩ�ͺʶҹ������ packet Ṻ��������� 0= ����� 1= ��
    delay(100);
    toSerial();
    
    //AT+SAPBR=1,1 Enable the GPRS
    //AT+SAPBR=2,1 Get ip address
    //AT+SAPBR=3,2 Set the connection type to GPRS
    
    myGsm.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
    delay(2000);
    toSerial();
  
    myGsm.println("AT+SAPBR=3,1,\"APN\",\"taif\"");
    delay(2000);
    toSerial();
  
    myGsm.println("AT+SAPBR=1,1");
    delay(2000);
    toSerial();
    puertoUS100.begin(9600); //set baud rate to 9600 ��������㹡���Ѻ-�� ������

}

void loop() {

    puertoUS100.flush(); // ������Buffer �ͧ port (Serial) �����ҧ

    puertoUS100.write(0x55); // ��¹����͡�������Ѵ���зҧ (����觢ͧ����Ѵ���зҧ)

    delay(100); 

     if(puertoUS100.available() >= 2) // ���Ǩ�ͺ��� buffer �����ҡѺ�����ҡ��� 2 byte �������

    {

        MSByteDist = puertoUS100.read(); //�觤�ҷ���Ѻ�ҡ port �͡�� ��ҹ�ҡ byte ��� 2

        LSByteDist  = puertoUS100.read();

        mmDist  = MSByteDist * 256 + LSByteDist; // distancia
       
        
        if((mmDist > 1) && (mmDist < 10000)) // ��Ǩ�ͺ���зҧ�������㹪�ǧ���

        {

//           Serial.print("distance: ");
//
//           Serial.print(mmDist/1000, DEC);
//
//           Serial.println(" M");
              level = String(mmDist/1000);
           
        }
    }
    puertoUS100.flush(); 
    puertoUS100.write(0x50); 
    delay(500); 

    if(puertoUS100.available() >= 1) // ���Ǩ�ͺ��� buffer �����ҡѺ�����ҡ��� 1 byte �������

    {
        temp = puertoUS100.read(); // ��ҹ��� byte �á

        if((temp > 1) && (temp < 130)) // ��Ǩ�ͺ�س�����

        {

            temp -= 45; // �����س�����

//            Serial.print("temp: ");
//
//            Serial.print(temp, DEC);
//
//            Serial.println(" C.");

        }
    }

    delay(100);

   myGsm.println("AT+HTTPINIT"); // ������鹡���� http protocal
   delay(2000); 
   toSerial();

   myGsm.println("AT+HTTPPARA=\"URL\",\"http://www.rmuti-water.com/project_final/data.php?Action=ADD&LEVEL="+level+"\"");    // Ṻ��ҷ���Ѵ��仡Ѻ http-get
   Serial.println(level);
   delay(2000);
   toSerial();

   myGsm.println("AT+HTTPACTION=0"); // ��駤���ٻẺ����� 0 = GET, 1 = POST, 2 = HEAD
   delay(2000);
   toSerial();

   myGsm.println("AT+HTTPREAD"); // ��ҹ��õͺʹͧ�ͧ server
   delay(1000);
   toSerial();

   myGsm.println("AT+HTTPTERM"); //¡��ԡ������ԡ�� http
   toSerial();
   delay(1000);

}

void toSerial()
{
while(myGsm.available()!=0)
  Serial.write(myGsm.read());
}