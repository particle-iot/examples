int led = D7; 
int state = LOW;

int toggle_led(String args) {
    if (state == HIGH){
        state = LOW;       
    } else {
        state = HIGH;
    }
    digitalWrite(led2, state);
    return 0;
}

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Spark.function("toggle_led", toggle_led);
}

void loop() {}
