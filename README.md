# Real-Time Clock AVR Project

This project is an AVR-based real-time clock that uses an Atmega 32 microcontroller uses internal 8 Mhz clock, an LCD, a keypad, and a 7-segment display to display time and allow users to set the clock.

<b><font face="Arial" >Hardware Requirements</font></b>  
- Atmega 32 microcontroller  
- LCD Display  
- Keypad  
- 7-segment display  
- Capacitors and resistors  
- Breadboard or PCB  
- Jumper wires  

<b><font face="Arial" >Software Requirements</font></b>  
- AVR Studio 6  
- WinAVR  
- Proteus Design Suite (for simulation)    

<b><font face="Arial" >Features</font></b>  
- Real-time clock with hour, minute, and second display  
- User can set the time using the keypad  
- 7-segment display for clock display  
- LCD display for setting display  


![image](https://user-images.githubusercontent.com/72231218/237036530-c3dcb345-94ca-4383-9a3d-12559e7950ef.png)


![image](https://user-images.githubusercontent.com/72231218/237036744-8032acf3-de12-4b06-b236-a877a16b2138.png)

<b><font face="Arial" >Setup</font></b>  
- Connect the Atmega 32 microcontroller to the breadboard or PCB.    
- Connect the capacitors and resistors as required by the crystal oscillator.  
- Connect the LCD display to the microcontroller's PORTC and POTRB pins.  
- Connect the keypad to the microcontroller's PORTD pins.  
- Connect the 7-segment display to the microcontroller's PORTA pins.  
- Connect power and ground to the appropriate pins.  

<b><font face="Arial" >Usage</font></b> 
- Compile the code using AVR Studio 6 and WinAVR.  
- Upload the hex file to the Atmega 32 microcontroller.  
- Power on the circuit.  
- The clock will start running automatically.  
- To set the clock, press the '1' button on the keypad.  
- Use the keypad to set the hour, minute, and second values.  
- The clock will now display the updated time.  
 
<b><font face="Arial" >Credits</font></b>   
This project was developed by Ahmed Sherif as a part of Microcontroller Course at Helwan University. 


