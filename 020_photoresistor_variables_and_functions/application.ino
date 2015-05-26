// We're going to start by declaring which pins everything is plugged into.

int led = D0; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.

int photoresistor = A0; // This is where your photoresistor is plugged in. The other side goes to the "power" pin (below).

int power = A4; // This is the other end of your photoresistor. The other side is plugged into the "photoresistor" pin (above).
// The reason we have plugged one side into an analog pin instead of to "power" is because we want a very steady voltage to be sent to the photoresistor.
// That way, when we read the value from the other side of the photoresistor, we can accurately calculate a voltage drop.

int analogvalue; // Here we are declaring the integer variable analogvalue, which we will use later to store the value of the photoresistor.


// Next we go into the setup function.

void setup() {
    /* The setup function is a part of every microcontroller app.
    The setup function is called once when your device turns on or resets.
    Steps taken in this function should be things you only want to have to do once, when your device starts running.
    For this app, our steps are as follows:
    */

    // First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.
    pinMode(led,OUTPUT); // Our LED pin is output (lighting up the LED)
    pinMode(photoresistor,INPUT);  // Our photoresistor pin is input (reading the photoresistor)
    pinMode(power,OUTPUT); // The pin powering the photoresistor is output (sending out consistent power)

    // Next, write the power of the photoresistor to be the maximum possible, which is 4095 in analog.
    analogWrite(power,4095);

    // We are going to declare a Spark.variable here so that we can access the value of the photoresistor from the cloud.
    Spark.variable("analogvalue", &analogvalue, INT);
    // This is saying that when we ask the cloud for "analogvalue", this will reference the variable analogvalue in this app, which is an integer variable.

    // We are also going to declare a Spark.function so that we can turn the LED on and off from the cloud.
    Spark.function("led",ledToggle);
    // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.
}


// Next is the loop function...

void loop() {
    /* The loop function is a part of every microcontroller app.
    After the setup function is done running, the loop function gets called
    as much as possible and as often as possible, over and over again
    until your device turns off or is reset.

    In this loop function, we're goint to check to see what the value
    of the photoresistor is and store it in the int variable analogvalue
    */

    // This will store the value of the photoresistor in our int variable, analogvalue:
    analogvalue = analogRead(photoresistor);
}


// Finally, we will write out our ledToggle function, which is referenced by the Spark.function() called "led"

int ledToggle(String command) {
    /* Spark.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can write instructions on how the function should be used.
    In this case, telling the function "on" will turn the LED on and telling it "off" will turn the LED off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 for the LED turning on, 0 for the LED turning off,
    and -1 if we received a totally bogus command that didn't do anything to the LED.
    */

    if (command=="on") {
        digitalWrite(led,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(led,LOW);
        return 0;
    }
    else {
        return -1;
    }
}

/* Paste the code between the dashes below into a .txt file and save it as an .html file. Replace your-device-ID-goes-here with your actual device ID and your-access-token-goes-here with your actual access token.

---------------------------
<!-- Replace your-device-ID-goes-here with your actual device ID
and replace your-access-token-goes-here with your actual access token-->
<center>
<br>
<br>
<br>
<form action="https://api.particle.io/v1/devices/your-device-ID-goes-here/led?access_token=your-access-token-goes-here" method="POST">
Tell your device what to do!<br>
<br>
<input type="radio" name="args" value="on">Turn the LED on.
<br>
<input type="radio" name="args" value="off">Turn the LED off.
<br>
<br>
<input type="submit" value="Do it!">
</form>
</center>
---------------------------
*/
