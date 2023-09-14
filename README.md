# PTR_Zero_Controller

This repository contains the Arduino script used for running the PTR Zero Controller instrument.

The script performs the following functions:

If the instrument recieves a serial command of '111\n', the instrument responds with a serial message reporting the activation state ('0\n' for solenoids off and '1\n' for solenoids on).

If the instrument recieves a serial command containing an integer n (other than 111) followed by a newline character, the instrument will activate the solenoids for n seconds. The instrument will also immediately send a serial message of '1\n' to indicate that the solenoids are activated and the instrument will remain available for the activation state to be polled by the '111\n' command.

The JAQFactory repository (https://github.com/BAAQMD-AMSP/JAQFactory) contains two programs to control the PTR Zero Controller instrument from a control computer. These are daq/PTR_zero_controller.pyw (for running scheduled zeros automatically), and daq/manual_PTR_zero_controller.py (for manual zeros).
