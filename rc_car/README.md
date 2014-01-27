About
=====

A simple RC car kit firmware and simple bash script to control it via curl commands.

How to build
------------

See [this Spark Docs page](http://docs.spark.io/#/shields/spark-rc-car-kit) for details of how to build

How to Use
----------

The bash script is essentially a loop that listens for keyboard input and invokes API
commands corresponding with forware, backword, left, right, and stop instructions.

### Open up a bash shell + go to controllers dir

    cd rc_car/controllers

### Set 2 env vars:

    export SPARK_CORE_DEVICE_ID="PUT_YOUR_DEVICE_ID_HERE!!!! i.e. acefdc000a01a411587f65d5"
    export SPARK_CORE_ACCESS_TOKEN="PUT_YOUR_ACCESS_TOKEN_HERE!!!! i.e. 3651b73e632b86881d47c65e7b0f59d511e97520"

### Load some bash functions into the current shell:

    source application.sh

### Then run the input loop function:

    rc_while
