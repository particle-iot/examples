/*---OH HI THERE, WELCOME TO THE PHOTORESISTOR PROGRAM---

Part Three-- Publish and Subscribe with your Photoresistor and a Buddy

We will assume here that you've already done part one.
Now for Part Two-- the part where you get a buddy.

Go find a buddy who also has a Spark device.
Each of you will pick a unique event name
   (make it weird so that no one else will have it)
   (no more that 63 ASCII characters, and no spaces)

In the following code, replace "your_unique_event_name" with your chosen name.
Replace "buddy_unique_event_name" with your buddy's chosen name.

Have your buddy do the same on his or her IDE.

Then, each of you should flash the code to your device.

Breaking the beam on one device will turn on the D7 LED on the second device.

Now you can send each other morse code messages!


But how does this magic work? Through the miracle of publish and subscribe.

We are going to Spark.publish a public event to the cloud.
That means that everyone can see you event and anyone can subscribe to it.
You and your buddy will both publish an event, and listen for each others events.

---------------------------------------*/


int led = D0;
int boardLed = D7;
int photoresistor = A0;
int power = A5;

int intactValue;
int brokenValue;
int beamThreshold;

bool beamBroken = false;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(boardLed,OUTPUT);
  pinMode(photoresistor,INPUT);
  pinMode(power,OUTPUT);
  
  analogWrite(power,4095);

  // Here we are going to subscribe to your buddy's event using Spark.subscribe
  Spark.subscribe("buddy_unique_event_name", myHandler);
  // Subscribe will listen for the event buddy_unique_event_name and, when it finds it, will run the function myHandler()
  // (Remember to replace buddy_unique_event_name with your buddy's actual unique event name that they have in their firmware.)
  // myHandler() is declared later in this app.

  // Calibrate:
  digitalWrite(boardLed,HIGH);
  delay(2000);
  
  // Then, the D7 LED will go off and the LED will turn on.
  digitalWrite(boardLed,LOW);
  digitalWrite(led,HIGH);
  delay(500);
  
  // Now we'll take some readings...
  int on_1 = analogRead(photoresistor); // read photoresistor
  delay(200); // wait 200 milliseconds
  int on_2 = analogRead(photoresistor); // read photoresistor
  delay(1000); // wait 1 second
  
  // Now the D7 LED will go on to tell you to remove your hand...
  digitalWrite(boardLed,HIGH);
  delay(2000);
  
  // The D7 LED will turn off...
  digitalWrite(boardLed,LOW);
  
  // ...And we will take two more readings.
  int off_1 = analogRead(photoresistor); // read photoresistor
  delay(200); // wait 200 milliseconds
  int off_2 = analogRead(photoresistor); // read photoresistor
  delay(300); // wait 300 milliseconds

  // Now flash the D7 LED on and off three times to let us know that we're ready to go!
  digitalWrite(boardLed,HIGH);
  delay(100);
  digitalWrite(boardLed,LOW);
  delay(100);
  digitalWrite(boardLed,HIGH);
  delay(100);
  digitalWrite(boardLed,LOW);
  delay(100);
  digitalWrite(boardLed,HIGH);
  delay(100);
  digitalWrite(boardLed,LOW);
  

  intactValue = (on_1+on_2)/2;
  brokenValue = (off_1+off_2)/2;
  beamThreshold = (intactValue+brokenValue)/2;

}


void loop() {
  // This loop sends a publish when the beam is broken.
  if (analogRead(photoresistor)>beamThreshold) {
    if (beamBroken==true) {
        Spark.publish("your_unique_event_name","intact");
        // publish this public event
        // rename your_unique_event_name with your actual unique event name. No spaces, 63 ASCII characters.
        // give your event name to your buddy and have them put it in their app.
        
        // Set the flag to reflect the current status of the beam.
        beamBroken=false;
    }
  }

  else {
      if (beamBroken==false) {
        // Same deal as before...
        Spark.publish("your_unique_event_name","broken");
        beamBroken=true;
      }
  }
}


// Now for the myHandler function, which is called when the cloud tells us that our buddy's event is published.
void myHandler(const char *event, const char *data)
{
  /* Spark.subscribe handlers are void functions, which means they don't return anything.
  They take two variables-- the name of your event, and any data that goes along with your event.
  In this case, the event will be "buddy_unique_event_name" and the data will be "intact" or "broken"
  
  Since the input here is a char, we can't do
     data=="intact"
    or
     data=="broken"
  
  chars just don't play that way. Instead we're going to strcmp(), which compares two chars.
  If they are the same, strcmp will return 0.
  */

  if (strcmp(data,"intact")==0) {
    // if your buddy's beam is intact, then turn your board LED off
    digitalWrite(boardLed,LOW);
  }
  else if (strcmp(data,"broken")==0) {
    // if your buddy's beam is broken, turn your board LED on
    digitalWrite(boardLed,HIGH);
  }
  else {
    // if the data is something else, don't do anything.
    // Really the data shouldn't be anything but those two listed above.
  }
}