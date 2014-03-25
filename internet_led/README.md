Controlling LEDs over the Internet
===

A simple firmware application for setting the state of a couple of LEDs
that are wired up and registered with `Spark.function('led',the_func)`, which calls the `the_func` when you issue an HTTP POST request to a url like `/v1/devices/DEVICE_ID/led`.

How to use
---

A curl request like follows should work:

    curl https://api.spark.io/v1/devices/YOUR_DEVICE_ID_HERE/led \
    -d access_token=YOUR_ACCESS_TOKEN_HERE \
    -d params=l1,HIGH

