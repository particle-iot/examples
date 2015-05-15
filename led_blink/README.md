About
=====
This is me trying to learn this stuff!

Blinking an LED is the "Hello World" example of the microcontroller world. It’s a nice way to warm up and start your journey into the land of embedded hardware. 

Required Materials
---

* a LED (optional)
* a Resistor (optional)

Note, that if you don't have these two things, the example will still work, and simply blink the on-board LED instead of the external one.
The value of the resistor doesn't matter much, something around 330 Ohms will work.

Schematic diagram
---

![Example LED](/led_blink/images/ex-led.png)

Note, LEDs have polarity (i.e. they only work when the "+" and "-" are wired correctly), the illustrated bent LED wire above corresponds to the physical LED wire that is longer.

How to Use
---

There isn't much to this. 1) flash it, 2) watch the LED blink, 3) fork the example, 4) try the activities below.

Activities
---

### Change the blink rate

- Change the `1000` in the `delay(1000)` to `250`, flash it, watch it blink faster!
- You can also make it turn on/off longer or shorter be varying the two numbers in `delay()`, watch it blink differently!

  eg. Slow blink (Short On, Long Off)

```
  digitalWrite(D0,LOW);  //turn off LED
  delay(500);            //wait for 500ms
  digitalWrite(D0,HIGH); //turn on LED
  delay(1000);            //wait for 1s
```
      
### Make external LED less bright

In hardware:

   1. Change the 330 Ohm resistor to a 1K Ohm. You will notice that the LED becomes much dimmer.
