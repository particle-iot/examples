#include <SoftwareSerial.h> //include library serial port /1 bit แบบอนุกรม

SoftwareSerial myGsm(2,3); //set TX,RX = pin 2,3

const int US100_TX = 8;  // set TX = pin 8 inteter constance ข้อมูลชนิดจำนวนเต็ม ใช้เนื้อที่ 2 byte -32,768 ถึง 32,767
const int US100_RX = 9; //  set RX = pin 9 

//ultrasonic detection range: 2 cm-450 cm
//distance = (เวลาส่งคลื่นไปที่นานที่สุด * ความเร็วของคลื่อนเสียง (340 M/S)) / 2
SoftwareSerial puertoUS100(US100_RX, US100_TX); //สร้าง function puretoUS100 แบบ Serial pin (8,9) 

unsigned int MSByteDist = 0; //ข้อมูลชนิดจำนวนเต็ม ไม่คิดเครื่องหมาย 0 ถึง 65,535
unsigned int LSByteDist = 0; 

float mmDist = 0; //ข้อมูลชนิดเลขทศนิยม ใช้เนื้อที่ 4 byte
int temp = 0;
String level;

void setup() {
    Serial.flush();  // เคลียร์Buffer ของ port (Serial) ให้ว่าง
    myGsm.flush(); // เคลียร์Buffer ของ port (myGsm) ให้ว่าง
    delay(10000);
    Serial.begin(9600); //set baud rate to 9600 ความเร็วในการรับ-ส่ง ข้อมูล
    toSerial();
    myGsm.begin(9600); //set baud rate to 9600 ความเร็วในการรับ-ส่ง ข้อมูล
    toSerial();
    Serial.println("Config SIM800...");
    delay(2000);
    Serial.println("Done!...");
    toSerial();
    myGsm.println("AT+CGATT?"); //ตรวจสอบสถานะว่ามี packet แนบมาหรือไม่ 0= ไม่มี 1= มี
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
    puertoUS100.begin(9600); //set baud rate to 9600 ความเร็วในการรับ-ส่ง ข้อมูล

}

void loop() {

    puertoUS100.flush(); // เคลียร์Buffer ของ port (Serial) ให้ว่าง

    puertoUS100.write(0x55); // เขียนค่าออกมาเพื่อวัดระยะทาง (คำสั่งของการวัดระยะทาง)

    delay(100); 

     if(puertoUS100.available() >= 2) // ใช้ตรวจสอบว่า buffer ว่าเท่ากับหรือมากว่า 2 byte หรือไม่

    {

        MSByteDist = puertoUS100.read(); //ส่งค่าที่รับจาก port ออกมา อ่านจาก byte ที่ 2

        LSByteDist  = puertoUS100.read();

        mmDist  = MSByteDist * 256 + LSByteDist; // distancia
       
        
        if((mmDist > 1) && (mmDist < 10000)) // ตรวจสอบระยะทางที่อยู่ในช่วงนี้

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

    if(puertoUS100.available() >= 1) // ใช้ตรวจสอบว่า buffer ว่าเท่ากับหรือมากว่า 1 byte หรือไม่

    {
        temp = puertoUS100.read(); // อ่านที่ byte แรก

        if((temp > 1) && (temp < 130)) // ตรวจสอบอุณหภูมิ

        {

            temp -= 45; // ชดเชยอุณหภูมิ

//            Serial.print("temp: ");
//
//            Serial.print(temp, DEC);
//
//            Serial.println(" C.");

        }
    }

    delay(100);

   myGsm.println("AT+HTTPINIT"); // เริ่มต้นการใช้ http protocal
   delay(2000); 
   toSerial();

   myGsm.println("AT+HTTPPARA=\"URL\",\"http://www.rmuti-water.com/project_final/data.php?Action=ADD&LEVEL="+level+"\"");    // แนบค่าที่วัดได้ไปกับ http-get
   Serial.println(level);
   delay(2000);
   toSerial();

   myGsm.println("AT+HTTPACTION=0"); // ตั้งค่ารูปแบบการส่ง 0 = GET, 1 = POST, 2 = HEAD
   delay(2000);
   toSerial();

   myGsm.println("AT+HTTPREAD"); // อ่านการตอบสนองของ server
   delay(1000);
   toSerial();

   myGsm.println("AT+HTTPTERM"); //ยกเลิกการใช้บริการ http
   toSerial();
   delay(1000);

}

void toSerial()
{
while(myGsm.available()!=0)
  Serial.write(myGsm.read());
}