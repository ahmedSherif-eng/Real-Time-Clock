#ifndef SEGMENT
#define SEGMENT
void seven_seg_vinit(unsigned char port);
/*  Name: seven_seg_vint
 *  Description: initialize specified port to be output for 7 segment
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *
 *  Return: void */
void seven_seg_vwrite(unsigned char port,unsigned char number);
/*  Name: seven_seg_vwrite
 *  Description: write a specified number on a 7 segment
 *  Arguments:   First Argument:   u8port,        options(A,a,b,B,c,C,d,D)
 *			     Second Argument   u8number       option(from 1 to 15);
 *  Return: void */
void bcd_vinit_lownipple(unsigned char port);
void bcd_vinit_highnipple(unsigned char port);
void bcd_vwrite_highnipple(unsigned char port,unsigned char value);
void bcd_vwrite_lownipple(unsigned char port,unsigned char value);
#endif 