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
#include "HAl/7Segment.h"

volatile uint8_t seconds=0;
volatile uint8_t minutes=0;
volatile uint8_t hours=0;
extern unsigned char num[];
int main(void)
{ 
	seg_vinit('a');
	seg_set_enable_pin('c',4);
	seg_set_enable_pin('c',5);
	seg_set_enable_pin('B',4);
	seg_set_enable_pin('B',5);
	seg_set_enable_pin('B',6);
	seg_set_enable_pin('B',7);
	seg_disable('c',4);
	seg_disable('c',5);
	seg_disable('B',4);
	seg_disable('B',5);
	seg_disable('B',6);
	seg_disable('B',7);
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
		seg_enable('c',4);
		seg_disable('c',5);
		seg_vwrite('a',seconds%10);
		_delay_ms(1);
		
		seg_enable('c',5);
		seg_disable('c',4);
		seg_vwrite('a',seconds/10);
		_delay_ms(1);
		
		seg_disable('c',5);
		seg_enable('b',4);
		seg_vwrite('a',minutes%10);
		_delay_ms(1);
		
		seg_enable('b',5);
		seg_disable('b',4);
		seg_vwrite('a',minutes/10);
		_delay_ms(1);
		
		seg_disable('b',5);
		seg_enable('b',6);
		seg_vwrite('a',hours%10);
		_delay_ms(1);
		
		seg_enable('b',7);
		seg_disable('b',6);
		seg_vwrite('a',hours/10);
		_delay_ms(1);
		
		seg_disable('b',7);
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