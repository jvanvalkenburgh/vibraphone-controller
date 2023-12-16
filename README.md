# vibraphone-controller

Drop-in replacement for Adams vibraphone board.

## Background

When students replaced the power cord on the High School's Adams vibraphone, they discovered that the motor control does not work. The sliding potentiometer and three-digit display have erratic effects. Replacing the control board from Adams is deemed to likely be economically impractical given the power cord cost more than $100.00. 

This project's objective is to replace the proprietary control board and controls with a functional equivalent using off-the-shelf components.  

## High-Level Requirements

- Same form, fit and function as proprietary controller, as to preserve integrity of the instrument.
- Control vibraphone motor
  - Control speed from 40-140 RPM using slider
  - Maintain steady RPM; speed not be exact but should be maintained if possible
  - Optional - level tampers at speed-down / power-off
- Display motor speed in RPM
- Respond to button control consistent with existing function

## Vibraphone Components

| Component                                            | Source in Production                                                                                                                                                                                                                                                                                               |
|------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------| 
| Motor assembly and mounted OPB991L11Z optical switch | Existing vibraphone; silent DC motors are difficult to find / assess and so this motor is particularly valuable in that its known-quiet. Its operating parameters such as DC rating remain unknown.                                                                                                                |
| DIN-3 26v DC Power Cord                              | Existing Vibraphone. The power plug has a weather-tight locking lug that makes the connection rugged. We can re-use this power adapter and/or wire another adapter to use a DIN-3 connector.                                                                                                                       |
| Translucent Buttons                                  | Existing; these are soft clear rubber with an inset square of conductor along the edge, which closes a connection pad on the Adams PCB. The PCB has an LED under the button sensor.                                                                                                                                |
| Slider Control                                       | New PCB Mounted                                                                                                                                                                                                                                                                                                    |
| 3-digit RPM Display                                  | New 3-digit display or LED display if able to find fit                                                                                                                                                                                                                                                             |
| Control PCB                                          | New board to fit within existing mount with components aligned to fit the pass-throughs to the outside of the unit. <br> <br> This board will need to mount the potentiometer slider, pads for the two translucent buttons with backing LEDs, and pin connectors for power in, DC motor power, and optical switch. | 

## Development Cycle

### Prototype 1

See [Initial Functinal Prototype](docs/PROTOTYPE-1.md)

### Production Board

See [Production Board Design](docs/BOARD.md)
