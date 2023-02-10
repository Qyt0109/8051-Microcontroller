#include "main.h"
#include "..\Library\Delay.h"
#include "..\Library\74595.h"

//common anode 7 segment led code
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};


void main()
{
	unsigned char i,j;
	unsigned char buffer[4];
	while(1)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				buffer[j]=Code7Seg[i*4+j];
			}
			Xuat_Byte(buffer,4);
			Delay_ms(1000);
		}
	}
}