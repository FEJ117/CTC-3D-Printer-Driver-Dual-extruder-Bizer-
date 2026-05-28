# CTC-3D-Printer-Driver-Dual-extruder-Bizer-
This is a driver for the dual extruder CTC 3D printer board to controll the steppers, LEDs and Endstops

# Preparation
To use this software you might have to upload the Arduino bootloader onto the ATMEGA1280 on the board. For this you may use Arduino as ISP if you have an Arduino board available. Otherwise use an USB-ISP adapter. This procedure is well documented in the Arduino documentation.

# Uploading the software
Note that in order to upload any sketch to the board of the CTC printer you will have to press the reset button of the board the moment the Arduino IDE sais "Uploading..."

# Using the software
The software (as of now) only contains the definitions of pins for the steppers and end-stops as well as the LEDs. Others may follow.
