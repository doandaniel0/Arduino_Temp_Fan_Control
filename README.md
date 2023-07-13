# Temperature control for a 4-pin fan with PWM
This code is written to control a  12v 4-pin fan based on temperature readings from a dht22 sensor through pwm.This project used an arduino uno.
## Circuit/Wiring
The code assumes that the dht22 sensor's output pin is connected to the arduino's pin 2. Connect the dht22 sensors ground to a ground on the arduino and its vcc pin to the arduino's 5v pin.
Connect the fans pwm pin to arudino pin 3. A seperate 12v power supply is needed to power the fan. Connect the 12v power supply to the fan's 12v pin out and ensure that that the fan shares a common ground with the arduino.
