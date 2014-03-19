About
=====

This example shows how to blink a built-in Spark led through a Spark Cloud REST API calls.

Requirements
============

`access token` - grab it from the Setting sections of Spark IDE

`device id` - your Spark core id shown as Device ID on the details section of the Spark Core in the IDE

Running
=======

Load the `application.cpp` in the Spark IDE and flash it on your Spark.

Replace the `device id` and `access_token` in the following `curl` call:
```
curl https://api.spark.io/v1/devices/ddddddddddddddddddddd/led \
         -d access_token=xxxxxxxxxxxxxxxxxxxxxxxxxxx \
         -d "args=on"
```

Use `args=off` to switch off the led.