# CTC-3D-Printer-Driver-Dual-extruder-Bizer
This is a driver for the dual extruder CTC 3D printer board to controll the steppers, LEDs, display, buttons, buzzer and endstops

# USE AT YOUR OWN RISK!

# Preparation
To use this software you might have to upload the Arduino bootloader onto the ATMEGA1280 on the board. For this you may use Arduino as ISP if you have an Arduino board available. Otherwise use an USB-ISP adapter. This procedure is well documented in the Arduino documentation.

# Uploading the software
This software was written using VS-Code and the Platform.io extension. You might also upload it via the Arduino IDE. To do this, copy the .ino file into a folder with the same name as the .ino file and open the file using the Arduino IDE.
Note that in order to upload any sketch to the board of the CTC printer you will have to press the reset button of the board the moment the IDE sais "Uploading...". To avoid having to do this, a 100nf capacitor can be soldered onto the empty socket labeled C20. This will enable auto reset on upload.

# Compatibility
This software might be compatible with the board of the Replicator Dual (2x) printer. As of now this was not tested.

# Troubleshooting
If something does not work the way it should, try the following:
1. Unplug both the USB cable and the external power supply
2. Connect all steppers you want to use
3. Connect the USB-cable
4. Connect the power supply again
5. Re-upload your code



