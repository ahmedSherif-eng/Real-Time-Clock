#include"../MCAL/bitwise.h"
#include "../MCAL/DIO_DRIVER.h"
#include <avr/io.h>
unsigned char num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7f,0x39,0x3f,0x79,0x71};
void seg_vinit(unsigned char port)
{
	DIO_SET_PORT_DIRECTION(port,0xff);
}
void seg_vwrite(unsigned char port,unsigned char number)
{
	DIO_WRITE_PORT(port,num[number]);
}
void bcd_vinit_lownipple(unsigned char port)
{
	DIO_SET_PIN_DIRECTION(port,0,1);
	DIO_SET_PIN_DIRECTION(port,1,1);
	DIO_SET_PIN_DIRECTION(port,2,1);
	DIO_SET_PIN_DIRECTION(port,3,1);
}
void bcd_vinit_highnipple(unsigned char port)
{
	DIO_SET_PIN_DIRECTION(port,4,1);
	DIO_SET_PIN_DIRECTION(port,5,1);
	DIO_SET_PIN_DIRECTION(port,6,1);
	DIO_SET_PIN_DIRECTION(port,7,1);
}
void bcd_vwrite_lownipple(unsigned char port,unsigned char val)
{
  DIO_WRITE_LowNipple(port,val);
}
void bcd_vwrite_highnipple(unsigned char port,unsigned char val)
{
	DIO_WRITE_highNipple(port,val);
}
void seg_set_enable_pin(char port, uint8_t pin)
{
	DIO_SET_PIN_DIRECTION(port,pin,1);
}
void seg_enable(char port, char pin)
{
	DIO_WRITE(port,pin,0);
}
void seg_disable(char port, char pin)
{
	DIO_WRITE(port,pin,1);
}