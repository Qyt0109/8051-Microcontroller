#include "main.h"
#include "..\Library\Delay.h"

sbit IC74HC595_SH_CP = P2^0;
sbit IC74HC595_DS		 = P2^1;
sbit IC74HC595_ST_CP = P2^2;
unsigned char Data_Byte, i, j ;


void Xuat_Byte(unsigned char *p, unsigned char So_Byte)
//								Con tro p		 ,	So byte muon truyen
{
	for(i=0;i<So_Byte;i++)
	{
		Data_Byte = *(p+So_Byte-i-1); //Lay byte cao nhat truoc
		for(j=0;j<8;j++)
		{
			IC74HC595_DS = Data_Byte & (0x80>>j);
			IC74HC595_SH_CP = 0;
			IC74HC595_SH_CP = 1;
		}
	}
	IC74HC595_ST_CP = 0;
	IC74HC595_ST_CP = 1;
}

void main()
{
	unsigned char buffer[2];
	buffer[0] = 0x10;	//Byte 
	buffer[1] = 0x0A;
	Xuat_Byte(buffer,2);	
	while(1)
	{
	}
}






