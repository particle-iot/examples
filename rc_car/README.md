About
=====

A simple rc car kit firmware and simple bash script to control it with via curl commands.

Controller Usage
----------------

Open up a bash shell + go to controllers dir

    cd rc_car/controllers

Set 2 env vars:

    export SPARK_CORE_DEVICE_ID="PUT_YOUR_DEVICE_ID_HERE!!!! i.e. acefdc000a01a411587f65d5"
    export SPARK_CORE_ACCESS_TOKEN="PUT_YOUR_ACCESS_TOKEN_HERE!!!! i.e. 3651b73e632b86881d47c65e7b0f59d511e97520"

Load some bash functions into the current shell:

    source application.sh

Then run the input loop function:

    rc_while

Requirements
------------

TODO
