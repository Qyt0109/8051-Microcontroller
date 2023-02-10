//Mo rong ngo ra dung IC 74HC595
/*LUU Y: Tao file header port.h tuong tu theo vi du sau:

#ifndef _PORT_H_
#define _PORT_H_

sbit IC74HC595_SH_CP = P2^0;
sbit IC74HC595_DS		 = P2^1;
sbit IC74HC595_ST_CP = P2^2;

#endif

*/

#ifndef _74595_H_
#define _74595_H_

void Xuat_Byte(unsigned char *p, unsigned char So_Byte);

#endif