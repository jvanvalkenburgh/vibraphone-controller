# Knowledge Building Plan

This plan's goal is to establish basic microcontroller skills that can be combined into our final product.

Key resources should include Google, Youtube, etc. A very basic tutorial on DC electronics to demonstrate
the relationship between current, voltage, and resistance, etc. is heklpful as this knowledge will be used
to calculate resistor values for LED's, etc.

Our controller is an ESP32 although most Arduino tutorials apply since the principles and software 
tooling is the same. What you will want to do is look at the dev board's datasheet and pick unused
pins. If you use a non-free pin you might find there's side effects (like if you use the reset pin 
by mistake, as i did).

## Skills build-up

For the IR-based speed sensor:
- turn on (and off) a visible LED (not the one on the board but a newly wired up one with a resistor)
- sense when a switch is open or closed (see pull up and pull-down resistors)

For computer/humnan interaction:
- read the potentiometer's position from none to full in order to determine the range of values
- wire up 3-digit LED display and display digits

For motor speed:
- use pre-wired motor control board to make motor go from slow to fast (note: motor needs separate power supply,
which most tutprials get around by using an artificially small motor that can be powered by the microcontroller.
