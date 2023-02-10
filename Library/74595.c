//Mo rong ngo ra dung IC 74HC595
//Can them file thu vien vao main.c
//#include "port.h"
//#include "74595.h"

#include "main.h"
#include "74595.h"
#include "port.h"
/*LUU Y: Tao file header port.h tuong tu theo vi du sau:

#ifndef _PORT_H_
#define _PORT_H_

sbit IC74HC595_SH_CP = P2^0;
sbit IC74HC595_DS		 = P2^1;
sbit IC74HC595_ST_CP = P2^2;

#endif

*/

void Xuat_Byte(unsigned char *p, unsigned char So_Byte)
//								Con tro p		 ,	So byte muon truyen
{
	unsigned char Data_Byte, iii, jjj ;
	for(iii=0;iii<So_Byte;iii++)
	{
		Data_Byte = *(p+(So_Byte-iii)-1); //Lay byte cao nhat truoc
		for(jjj=0;jjj<8;jjj++)
		{
			IC74HC595_DS = Data_Byte & (0x80>>jjj);
			IC74HC595_SH_CP = 0;
			IC74HC595_SH_CP = 1;
		}
	}
	IC74HC595_ST_CP = 0;
	IC74HC595_ST_CP = 1;
}
		//VD su dung de xuat 0x55AA tu byte co chi so cao nhat (luu tren dinh stack cua mang)
		//buffer[0] = 0xAA;	//Byte 
		//buffer[1] = 0x55;
		//Xuat_Byte(buffer,2);