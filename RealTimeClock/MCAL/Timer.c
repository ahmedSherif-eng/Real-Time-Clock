/*
 * Timer.c
 *
 * Created: 4/10/2023 3:02:34 PM
 *  Author: Ahmed Sherif
 */ 
#include <avr/io.h>
#include<avr/interrupt.h>
#include "bitwise.h"
#include"Timer.h"
void Timer_NormalMode()
{
	SET(ASSR,AS2);//for external clock
	SET(TCCR2,CS20);
	SET(TCCR2,CS22);//choose clock as prescaler of 256 of MP freq
	sei();
	SET(TIMSK,TOIE2);//enable interrupt of overflow

}
void Timer0_CTC_vint()
{
	SET(TCCR0,WGM01);
	CLEAR(TCCR0,WGM00);//choose CTC mode
	SET(TCCR0,CS00);
	SET(TCCR0,CS02);//choose clock as prescaler of 1024 of MP freq
	OCR0=value;
	SET(TIMSK,OCIE0);//enable interrupt of CTC
	sei();
	
}
void Timer_WG_nonPWM()
{
	DIO_SET_PIN_DIRECTION('b',3,1);
	SET(TCCR0,WGM01);
	CLEAR(TCCR0,WGM00);//choose CTC mode
	SET(TCCR0,CS00);
	SET(TCCR0,CS02);//choose clock as prescaler of 1024 of MP freq
	OCR0=value;
	SET(TCCR0,COM00); //toggle OC0
	
}
void Timer_FastPWM()
{
		DIO_SET_PIN_DIRECTION('b',3,1);
		SET(TCCR0,WGM01);
		SET(TCCR0,WGM00);//choose fast PWM mode
		OCR0=value;
		SET(TCCR0,CS00);
		SET(TCCR0,CS02);//choose clock as prescaler of 1024 of MP freq
		SET(TCCR0,COM01); //clear on compare match
		CLEAR(TCCR0,COM00);
}
void Timer_PhasePWM()
{
		DIO_SET_PIN_DIRECTION('b',3,1);
		SET(TCCR0,WGM00);//choose fast PWM mode
		OCR0=value;
		SET(TCCR0,CS00);
		SET(TCCR0,CS02);//choose clock as prescaler of 1024 of MP freq
		SET(TCCR0,COM01); //clear on compare match
		CLEAR(TCCR0,COM00);
}