/* Function prototypes -------------------------------------------------------*/


/* A comment */
int rcCarControl(String command);

/* Globals -------------------------------------------------------------------*/
int leftMotorEnable   = D1;
int rightMotorEnable  = A7;
int leftMotorDir    = D3;
int rightMotorDir   = D4;


/* This function is called once at start up ----------------------------------*/
void setup()
{
  //Register Spark function
  Spark.function("rccar", rcCarControl);

  pinMode(leftMotorDir, OUTPUT);
  pinMode(leftMotorEnable, OUTPUT);
  pinMode(rightMotorDir, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT);

  pinMode(D7,OUTPUT);
}

/* This function loops forever --------------------------------------------*/
void loop()
{
  // Nothing to do here
}

/*******************************************************************************
 * Function Name  : rcCarControl
 * Description    : Parses the incoming API commands and sets the motor control
          pins accordingly
 * Input          : RC Car commands
          e.g.: rc,FORWARD
            rc,BACK
 * Output         : Motor signals
 * Return         : 1 on success and -1 on fail
 *******************************************************************************/
int rcCarControl(String command)
{
  if(command.substring(3,7) == "STOP")
  {
    digitalWrite(leftMotorEnable,LOW);
    digitalWrite(rightMotorEnable,LOW);

    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,LOW);

    return 1;
  }

  if(command.substring(3,7) == "BACK")
  {
    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,HIGH);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    return 1;
  }

  if(command.substring(3,10) == "FORWARD")
  {
    digitalWrite(leftMotorDir,HIGH);
    digitalWrite(rightMotorDir,LOW);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    return 1;
  }

  if(command.substring(3,8) == "RIGHT")
  {
    digitalWrite(leftMotorDir,HIGH);
    digitalWrite(rightMotorDir,HIGH);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    return 1;
  }

  if(command.substring(3,7) == "LEFT")
  {
    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,LOW);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    return 1;
  }

  // If none of the commands were executed, return false
  return -1;
}
