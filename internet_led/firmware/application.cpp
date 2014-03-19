int led = D7; // This one is the built-in tiny one to the right of the USB jack

int toggleLed(String command);

void setup() {
    pinMode(led, OUTPUT);
    //register the Spark function
    Spark.function("led", toggleLed);
}

void loop() {
    //this loops forever
}

//this function automagically gets called upon a matching POST request
int toggleLed(String command) {
    if (command == "on") {
        digitalWrite(led, HIGH);
    } else if (command == "off") {
        digitalWrite(led, LOW);
    } else {
        //unknown command
        return -1;
    }
    return 1;
}

