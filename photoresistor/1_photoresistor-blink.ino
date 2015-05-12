//photoresistor-blink.ino

/*---OH HI THERE, WELCOME TO THE PHOTORESISTOR PROGRAM---

We've heavily commented this code for you. If you're a pro, feel free to ignore it.

Comments start with two slashes or are blocked off by a slash and a star.

You can read them, but your device can't.

It's like a secret message just for you.

Ready to start?
---------------------------------------*/

// We're going to start by declaring which pins everything is plugged into.

int led = D0; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.

int photoresistor = A0; // This is where your photoresistor is plugged in. The other side goes to the "power" pin (below).

int power = A4; // This is the other end of your photoresistor. The other side is plugged into the "photoresistor" pin (above).
// The reason we have plugged one side into an analog pin instead of to "power" is because we want a very steady voltage to be sent to the photoresistor.
// That way, when we read the value from the other side of the photoresistor, we can accurately calculate a voltage drop.

// The following values get set up when your device boots up and calibrates:
int ledOnValue; // This is the average value that the photoresistor reads when the LED is on.
int ledOffValue; // This is the average value that the photoresistor reads when the LED is off.
int ledThreshold; // This is a value halfway between ledOnValue and ledOffValue, above which we will assume the led is on and below which we will assume it is off.


// We start with the setup function.

void setup() {
  // The setup function is a part of every microcontroller app.
  // The setup function is called once when your device turns on or resets.
  // Steps taken in this function should be things you only want to have to do once, when your device starts running.
  // For this app, our steps are as follows:

  // First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.
  pinMode(led,OUTPUT); // Our LED pin is output (lighting up the LED)
  pinMode(photoresistor,INPUT);  // Our photoresistor pin is input (reading the photoresistor)
  pinMode(power,OUTPUT); // The pin powering the photoresistor is output (sending out consistent power)

  // Next, write the power of the photoresistor to be the maximum possible, which is 4095 in analog.
  analogWrite(power,4095);

  // Since everyone sets up their leds differently, we are also going to start by calibrating our photoresistor.
  digitalWrite(led,HIGH); // turn led on
  delay(300); // wait 300 milliseconds
  int on_1 = analogRead(photoresistor); // read photoresistor
  delay(300); // wait 300 milliseconds
  digitalWrite(led,LOW); // turn led off
  delay(300); // wait 300 milliseconds
  int off_1 = analogRead(photoresistor); // read photoresistor
  delay(300); // wait 300 milliseconds
  int on_2 = analogRead(photoresistor); // and do it all again...
  delay(300);
  digitalWrite(led,LOW);
  delay(300);
  int off_2 = analogRead(photoresistor);
  delay(300);

  // Now we average the "on" and "off" values to get an idea of what the resistance will be when the LED is on and off
  ledOnValue = (on_1+on_2)/2;
  ledOffValue = (off_1+off_2)/2;

  // Let's also calculate the value between ledOn and ledOff, above which we will assume the led is on and below which we assume the led is off.
  ledThreshold = (ledOnValue+ledOffValue)/2;

}

void loop() {
  /* The loop function is a part of every microcontroller app.
  After the setup function is done running, the loop function gets called
  as much as possible and as often as possible, over and over again
  until your device turns off or is reset.

  In this loop function, we're going to check to see if the LED is on or off.
  If it is on, we'll send a Spark.publish() to the cloud so that if we want to,
  we can check from other devices when the LED is on or off.

  We'll also turn the D7 LED on when the Photoresistor reads that the LED is off.
  
  */

  if (analogRead(photoresistor)>ledThreshold) {
    // If you are above the threshold, we'll assume the led is on.

    // Send a publish...
    Spark.publish("ledStatus","on",60,PRIVATE);
    
    // Wait a second, and then turn the LED off.
    delay(800);
    digitalWrite(led,LOW);
  }

  else {
    // If you are below the threshold, the led is probably off.

    // Send a publish...
    Spark.publish("ledStatus","off",60,PRIVATE);
    
    // Wait a second, and then turn the LED on.
    delay(800);
    digitalWrite(led,HIGH);
  }
  
}



