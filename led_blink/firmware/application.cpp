// This program will blink an led on and off every second.
// It blinks the D7 LED on your Particle device. If you have an LED wired to D0, it will blink that LED as well.

// First, define the pins we are going to use.
int led = D0;  // You'll need to wire an LED to this one to see it blink.
int led2 = D7; // This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.

// This routine runs only once when the device boots up or is reset
void setup() {
  // We are going to tell our device that D0 and D7 (which we named led and led2 respectively) are going to be output
  // (That means that we will be sending voltage to them, rather than monitoring voltage that comes from them)
  // It's important you do this here, inside the setup() function rather than outside it or in the loop function.
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

// This next routine gets called over and over, as much as possible, after your device boots up.
// Spark firmware interleaves background CPU activity associated with WiFi + Cloud activity with your code. Note: Code that blocks for too long (like more than 5 seconds), can make weird things happen (like dropping the network connection).  The built-in delay function shown below safely interleaves required background activity, so arbitrarily long delays can safely be done if you need them.
void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED pins
  digitalWrite(led2, HIGH);
  delay(1000);               // Wait for 1000mS = 1 second
  digitalWrite(led, LOW);    // Turn OFF the LED pins
  digitalWrite(led2, LOW); 
  delay(1000);               // Wait for 1 second in off mode
}
