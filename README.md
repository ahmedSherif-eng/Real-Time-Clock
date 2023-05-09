
****
<b><font face="Arial" size="17">Real-Time Clock AVR Project</font></b>

This project is an AVR-based real-time clock that uses an Atmega 32 microcontroller, an LCD, a keypad, and a 7-segment display to display time and allow users to set the clock.

**Hardware Requirements
Atmega 32 microcontroller
LCD Display
Keypad
7-segment display
16MHz crystal oscillator
Capacitors and resistors
Breadboard or PCB
Jumper wires
Software Requirements
AVR Studio 6
WinAVR
Proteus Design Suite (for simulation)
Features
Real-time clock with hour, minute, and second display
User can set the time using the keypad
7-segment display for clock display
LCD display for setting display
Setup
Connect the Atmega 32 microcontroller to the breadboard or PCB.
Connect the 16MHz crystal oscillator to the microcontroller's XTAL1 and XTAL2 pins.
Connect the capacitors and resistors as required by the crystal oscillator.
Connect the LCD display to the microcontroller's PORTC pins.
Connect the keypad to the microcontroller's PORTA pins.
Connect the 7-segment display to the microcontroller's PORTB pins.
Connect power and ground to the appropriate pins.
Usage
Compile the code using AVR Studio 6 and WinAVR.
Upload the hex file to the Atmega 32 microcontroller.
Power on the circuit.
The clock will start running automatically.
To set the clock, press the '#' button on the keypad.
Use the keypad to set the hour, minute, and second values.
Press the '*' button to save the new time.
The clock will now display the updated time.
Credits
This project was developed by [Your Name] as a part of [Your Course/Program] at [Your University/Institution].

License
This project is licensed under the MIT License. See the LICENSE file for details.
