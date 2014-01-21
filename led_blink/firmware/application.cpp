#include "application.h"

// We name pin D0 as led
int led = D0; 

// This routine runs only once upon reset
void setup() 
{
  // Initialize D0 pin as an output
  pinMode(led, OUTPUT);
}

// This routine loops forever 
void loop() 
{
  digitalWrite(led, HIGH);   // Turn ON the LED
  delay(1000);               // Wait for 1000mS = 1 second
  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(1000);               // Wait for 1 second
}