Toggle LED with API
===

This example illustrates how to toggle an LED over the internet using `Spark.function`

How to Use
---

We'll use curl examples below to invoke HTTP API requests, if you're on windows or don't have curl installed, you can
also use the Postman browser extension.

### Observe the available function defined on the core

A HTTP Get request like follows:

    curl 'https://api.particle.io/v1/devices/DEVICE_ID_OR_NAME?access_token=1234512312sdfefdf'

You should see something like this:

    {
      "id": "DEVICE_ID",
      "name": "DEVICE_NAME",
      "connected": true,
      "variables": {},
      "functions": [
        "toggle_led"
      ]
    }

Call the function and toggle the LED like this:

    curl https://api.particle.io/v1/devices/DEVICE_ID_OR_NAME/toggle_led -d 'access_token=123412341234234fdfeff'

You should see the LED turn on or off on the core, and the curl command should return something like this:

    {
      "id": "DEVICE_ID",
      "name": "DEVICE_NAME",
      "last_app": null,
      "connected": true,
      "return_value": 1
    }

