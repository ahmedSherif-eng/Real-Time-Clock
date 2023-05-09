#include "KEYPAD.h"
void Keypad_vInt( char port)
{
	 DIO_SET_PIN_DIRECTION(port,0,1);
	 DIO_SET_PIN_DIRECTION(port,1,1);
	 DIO_SET_PIN_DIRECTION(port,2,1);
	 DIO_SET_PIN_DIRECTION(port,3,1);
	 DIO_SET_PIN_DIRECTION(port,4,0);
	 DIO_SET_PIN_DIRECTION(port,5,0);
	 DIO_SET_PIN_DIRECTION(port,6,0);
	 DIO_SET_PIN_DIRECTION(port,7,0);
	 DIO_vConnectPullUp(port,4,1);
	 DIO_vConnectPullUp(port,5,1);
	 DIO_vConnectPullUp(port,6,1);
	 DIO_vConnectPullUp(port,7,1);
	

}	
  char  KeypadRead( char port){
	
	 char arr[4][4]={{'1','2','3','+'},{'4','5','6','-'},{'7','8','9',' '},{'*','0','=','.'}};
	 char row,coloumn,x;
	 char returnval=NotPressed;
	 for(row=0;row<=3;row++)
	 {
		 DIO_WRITE(port,0,1);
		 DIO_WRITE(port,1,1);
		 DIO_WRITE(port,2,1);
		 DIO_WRITE(port,3,1);
		 DIO_WRITE(port,row,0);
		 
		 for(coloumn=0;coloumn<=3;coloumn++)
		 {
			 x=DIO_READ(port,(coloumn+4));
			 if(x==0)
			 {
				 returnval=arr[row][coloumn];
				 break;
			 }
		 }
		 if(x==0)
		 {
			 break;
		 }
	 }
	 return returnval ;
 }