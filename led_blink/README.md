About
=====

Blinking an LED is the “Hello World” example of the microcontroller world. It’s a nice way to warm up and start your journey into the land of embedded hardware. For this example, you will need a Spark Core (duh!), a Breadboard, an LED, a Resistor (we will soon find out a suitable value) and an USB cable. Note, that if you don't have these things, the example will still work, and simply blink the on-board LED instead of the external one.

[Read more about this project here](http://docs.spark.io/#/examples/blink-an-led) on the Spark Docs site.


**Items required:**
 - 330 Ohm Resistor 
 - LED of your color choice
 - Tinker App or Cloud IDE

**Schematic diagram:**

![Example LED](/images/ex-led.png)

**Hands-on Activity:**

 In example code:
      
  1. Change the `1000` in the `delay(1000)` to `250`
  2. You will notice that the led blinks faster!
  3. Try other values but keep it below `2000`
  4. You can also make it turn on/off longer or shorter be varying the 2 numbers in `delay()`
      
  eg. Slow blink (Short On, Long Off)

```
  digitalWrite(D0,LOW);  //turn off LED
  delay(500);            //wait for 500ms
  digitalWrite(D0,HIGH); //turn on LED
  delay(1000);            //wait for 1s
```
       
 In hardware:  
      
   1. Change the 330 Ohm resistor to a 1K Ohm. You will notice that the LED becomes much dimmer.
