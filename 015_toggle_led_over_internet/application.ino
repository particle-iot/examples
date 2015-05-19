// define what pin our LED is connected to. D7 is the built-in LED
int led = D7;

// define the initial state of the LED pin (LOW means off)
int state = LOW;

// define a function that will be called in firmware
// when someone uses the REST API to call it over the internet
// It simply changes the state and returns the current state
// The return value of the function will be available in the API response as well.
int toggle_led(String args) {
  if (state == HIGH){
    state = LOW;
  } else {
    state = HIGH;
  }
  digitalWrite(led, state);
  return state;
}

// The magic here is the Spark.function usage, it's what makes an HTTP POST request
// to `https://api.particle.io/v1/devices/DEVICE_ID/toggle_led` call the toggle_led firmware function.
// Check out the documentation for more details.
void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, state);
  Spark.function("toggle_led", toggle_led);
}

// All of our behavior is coming via the Spark.function + API requests, 
// so we don't do anything here.
void loop() {}
