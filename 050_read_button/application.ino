// Define the pins we're going to call pinMode on
int led = D0;  // You'll need to wire an LED to this one to see it blink.
int led2 = D7; // This one is the built-in tiny one to the right of the USB jack
int inputpin = D1;	//used to read the Pushbutton

// This routine runs only once upon reset
void setup() {
  // Initialize D0 + D7 pin as output
  // It's important you do this here, inside the setup() function rather than outside it or in the loop function.
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(inputpin, INPUT);
}

// This routine gets called repeatedly, like once every 5-15 milliseconds.
// Spark firmware interleaves background CPU activity associated with WiFi + Cloud activity with your code. Note: Code that blocks for too long (like more than 5 seconds), can make weird things happen (like dropping the network connection).  The built-in delay function shown below safely interleaves required background activity, so arbitrarily long delays can safely be done if you need them.
void loop() {
  if(digitalRead(inputpin) == HIGH){
	digitalWrite(led, HIGH);   // Turn ON the LED pins
	digitalWrite(led2, HIGH);
  }	
  else{
    digitalWrite(led, LOW);    // Turn OFF the LED pins
    digitalWrite(led2, LOW); 
  }
}
