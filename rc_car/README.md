About
=====

A simple rc car kit controlled by a bash script.

Who should check this out
-------------------------

People that want to get more comfortable working with REST APIs on the command line.

Usage
-----

Open up a bash shell, for Mac users, just open up a terminal.
For Windows users, ...

First, set 2 key environment variables:

    export SPARK_CORE_DEVICE_ID="PUT_YOUR_DEVICE_ID_HERE!!!! i.e. acefdc000a01a411587f65d5"
    export SPARK_CORE_ACCESS_TOKEN="PUT_YOUR_DEVICE_ID_HERE!!!! i.e. 3651b73e632b86881d47c65e7b0f59d511e97520"

Then load some bash functions into the current shell:

    source main.sh

Then run the input loop function:

    rc_while

Check out the [rc() function in main .sh](main.sh) for details what keys do what.


### Other things This readme might include:

* Bill of Materials
* Schematic Diagrams
* Level of Complexity for the Project
