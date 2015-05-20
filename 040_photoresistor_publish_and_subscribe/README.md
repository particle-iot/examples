Publish and Subscribe with Photoresistors
====

![](http://docs.particle.io/assets/images/photon-photoresistor-fritzing.png)

In the last example, we sent a private publish. This publish went to you alone; it was just for you and your own apps, programs, integrations, and devices. We can also send a public publish, though, which allows anyone anywhere to see and subscribe to our event in the cloud. All they need is our event name.

Go find a buddy who has a Core or Photon. Your buddy does not have to be next to you-- he or she can be across the world if you like! All you need is Wi-Fi.

Connect your device and copy the firmware on the right into a new app. Pick a weird name for your event. If your core were named `starfish` for example, you could make your event name something like `starfish_special_event_20150515`. Have your buddy pick a name for their event as well.

Now replace `your_unique_event_name` with your actual event name and `buddy_unique_event_name` with your buddy's unique event name.

Have your buddy do the same thing, only with their event name and yours (swap 'em).

Flash the firmware to your devices. Calibrate your device when it comes online (same as in the previous example). When the beam is broken on your device, the D7 LED on your buddy's device will light up! Now you can send little messages to each other in morse code.
