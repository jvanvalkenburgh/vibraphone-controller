# Prototype 1

## Goals

- establish the core principals of motor operation and control
- capture our target circuit design. This includes pin assignments, pull up/down configurations, motor control logic and noise protection.

## Anti-Goals

- PCB layout / physical design. This revision has surrogates for all physical controls, with the intent to protect the existing components from unintended harm.  

##  Requirements

| Ref | Requirement                                                          | Priority    | Status |
|-----|----------------------------------------------------------------------|-------------|--------| 
| tbd | Control the motor speed using the slider potentiometer               | Must Have   | To-do  |
| tbd | Calculate and display motor speed in RPM using optical switch inputs | Must Have   | To-do  |
| tbd | Respond to button control alike current unit (to be documented)      | Must Have   | To-do  |
| tbd | Cap motor RPM to 140 RPM to protect motor                            | Must Have   | To-do  |
| tbd | Maintain a constant motor RPM                                        | Should Have | To-do  |
| tbd | Dampen (level) valves upon power down                                | Could Have  | To-do  |

## BOM

* ESP32 Microcontroller Dev board with USB power & JTAG
  - Cheaper than Arduino and all pins have interrupts. This will be useful assuming we will need to use interrupts for RPM sensing and can use it for other sensors as well (e.g. we can have one pattern for all sensors).
  - Bluetooth and Wi-Fi were NOT part of criteria but are interesting for the future
  - Multiple dev board form factors (wide, narrow, all different pins)
  - Narrow ESP32 Dev Board:
    - [Shen Zhen Shi Ya Ying Technology ESP32 Wi-Fi & Bluetooth Development Board](https://fccid.io/2A4RQ-ESP32/User-Manual/Users-Manual-5713740)
* L293D Motor controller IC
  - Easy to find on Aliexpress and has a built-in diode, so it saves some time
* [OPB991L11Z Optical switch (identical)](../docs/datasheets/OPB960-990.pdf)
* 12V DC Motor, ~200RPM (approximation)
* (2) momentary push-buttons
* (2) status LEDs
* 10K&#937; sliding potentiometer (&#937; coming from legacy slider's parameters)
* (1) LED display (3-digit to come)
* Power regulation IC (s)
* Power-in via external source (voltage TBD)
* Assorted pull up/down resistors
* Capacitor to protect DC motor
* DIN connectors (for power harness, etc - optional)

## Development Platform

Initially the intent was to use Micropython, but functional and IDE limitations on ESP32 drove the decision for Arduino / C++, which uses the Espressif SDK and FreeRTOS, meaning we get options for multi-threading, etc.
