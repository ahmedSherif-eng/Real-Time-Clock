/*
 * RealTimeClock.c
 *
 * Created: 4/11/2023 10:04:30 PM
 *  Author: Ahmed Sherif
 */ 

#include <avr/io.h>
#include<avr/interrupt.h>
#include "MCAL/bitwise.h"
#include "MCAL/DIO_DRIVER.h"
#include "MCAL/Timer.h"
#include "HAl/KEYPAD.h"
#include "HAl/LCD.h"

volatile uint8_t seconds=0;
volatile uint8_t minutes=0;
volatile uint8_t hours=0;
uint8_t numbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7f,0x39,0x3f,0x79,0x71};
int main(void)
{ 
	DIO_SET_PORT_DIRECTION('a',1);
	DIO_SET_PIN_DIRECTION('c',4,1);
	DIO_SET_PIN_DIRECTION('c',5,1);
	DIO_SET_PIN_DIRECTION('B',3,1);
	DIO_SET_PIN_DIRECTION('B',4,1);
	DIO_SET_PIN_DIRECTION('B',5,1);
	DIO_SET_PIN_DIRECTION('B',6,1);
	DIO_SET_PIN_DIRECTION('B',7,1);
	DIO_WRITE('c',4,1);
	DIO_WRITE('c',5,1);
	DIO_WRITE('B',3,1);
	DIO_WRITE('B',4,1);
	DIO_WRITE('B',5,1);
	DIO_WRITE('B',6,1);
	DIO_WRITE('B',7,1);
	LCD_vInit();
	Keypad_vInt('d');
	LCD_vSend_string("Press 1 to");
	LCD_vMove_Cursor(2,1);
	LCD_vSend_string("set clock");
	uint8_t val=NotPressed;
		Timer_NormalMode();
	
    while(1)
    {
		if(seconds>=60)
		{
			seconds=0;
			minutes++;
		}
		if(minutes>=60)
		{
				minutes=0;
				hours++;
		}
		if(hours>=24)
			hours=0;
		CLEAR(PORTC,4);
		SET(PORTC,5);
		PORTA=numbers[seconds%10];
		_delay_ms(1);
		CLEAR(PORTC,5);
		SET(PORTC,4);
		PORTA=numbers[seconds/10];
		_delay_ms(1);
		
		SET(PORTC,5);	
		CLEAR(PORTB,4);
		PORTA=numbers[minutes%10];
		_delay_ms(1);
		CLEAR(PORTB,5);
		SET(PORTB,4);
		PORTA=numbers[minutes/10];
		_delay_ms(1);
		
		SET(PORTB,5);
		CLEAR(PORTB,6);
		PORTA=numbers[hours%10];
		_delay_ms(1);
		CLEAR(PORTB,7);
		SET(PORTB,6);
		PORTA=numbers[hours/10];
		_delay_ms(1);
		SET(PORTB,7);
		_delay_ms(5);
			val=KeypadRead('d');
			if(val=='1')
			{
				val=NotPressed;
				LCD_vClear_Screen();
				LCD_vSend_string("hours: ");
				_delay_ms(300);
				do
				{
					val=KeypadRead('d');
				}
				while(val==NotPressed);
				_delay_ms(300);					
				hours=(val-48)*10;
				LCD_vSend_char(val);
				val=NotPressed	;	
				do
				{
					val=KeypadRead('d');
				}while(val==NotPressed );
				_delay_ms(300);
				hours+=(val-48);
				LCD_vSend_char(val);
				_delay_ms(1000);
				val=NotPressed;
				LCD_vClear_Screen();
				LCD_vSend_string("minutes: ");
				_delay_ms(300);
				do
				{
					val=KeypadRead('d');
				}
				while(val==NotPressed);
				_delay_ms(300);					
				minutes=(val-48)*10;
				LCD_vSend_char(val);
				val=NotPressed	;	
				do
				{
					val=KeypadRead('d');
				}while(val==NotPressed );
				_delay_ms(300);
				minutes+=(val-48);
				LCD_vSend_char(val);
				_delay_ms(1000);
				val=NotPressed;
				LCD_vClear_Screen();
				LCD_vSend_string("seconds: ");
				_delay_ms(300);
				do
				{
					val=KeypadRead('d');
				}
				while(val==NotPressed);
				_delay_ms(300);
				seconds=(val-48)*10;
				LCD_vSend_char(val);
				val=NotPressed	;
				do
				{
					val=KeypadRead('d');
				}while(val==NotPressed );
				_delay_ms(300);
				seconds+=(val-48);
				LCD_vSend_char(val);
				_delay_ms(1000);
				LCD_vClear_Screen();
				LCD_vSend_string("Press 1 to");
				LCD_vMove_Cursor(2,1);
				LCD_vSend_string("set clock");
				uint8_t val=NotPressed;
				
			}

		
		
		
		
    }
}
ISR(TIMER2_OVF_vect)
{
	seconds++;
	
}