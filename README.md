# Arduino-shuttle
Arduino based shuttle module for model railroads

```
  1                      3
_____________________________
______/               \______
  2                      4
```

## Equipment
This project uses the following:
* Arduino Mega: https://amzn.to/3XlKSjc
* Motor shield V1: https://amzn.to/4emLI6f
* 4 channel relay: https://amzn.to/47vmTTy
* IR sensors: https://amzn.to/3zlgZHO
* SEEP PM2 Solenoid motors: https://amzn.to/3TtZM5Z
* CDU

## Purpose
We needed a shuttle for a model railway exhibition layout that automatically switched between different locos. This module supports 3 locos, but can easily suport more by using more relays, motors and sensors, and extending the code.

## Setup
Relays for Turnout 1 on pins 22 & 23, relays for Turnout 2 on pins 24 & 25.
Sensor 1: pin 38
Sensor 2: pin 40
Sensor 3: pin 42
Sensor 4: pin 44

## Running
Put a loco in siding 1, 2 & 3, leaving siding 4 free. Turn on power to the arduino, motor shield and CDU.

* Siding 1 -> Siding 4
* Siding 3 -> Siding 1
* Siding 2 -> Siding 3
* Siding 4 -> Siding 2
