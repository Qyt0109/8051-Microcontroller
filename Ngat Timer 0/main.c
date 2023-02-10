#include "main.h"

int cnt = 0, Count = 2;	//Delay Count lan 50ms
void main()
{
	TMOD &= 0xF0;		//Xoa cai dat Timer 0
	TMOD |= 0x01;		//Cai dat Timer 0 mode 1
	
	TH0 = 0x3C;			//Crystal 12MHz => Xung cap cho Timer = 12MHz/12 = 1MHz => 1 chu ky xung = 1/1MHz = 1us
									//De delay 50ms can 50ms/1us = 50000 chu ky xung
									//=> Timer can dem nguoc tu 2^16 - 50000 = 0x3CB0 = THx TLx
	TL0 = 0xB0;
	
	EA = 1;					//Cho phep ngat toan cuc
	ET0 = 1;				//Cho phep ngat Timer 0
	TR0 = 1;				//Start Timer
	
	while(1)
	{

	}
}

void Timer0_Overflow() interrupt 1
{
	TH0 = 0x3C;
	TL0 = 0xB0;	//Nap lai gia tri cho thanh ghi Timer 0
	
	cnt++;
	if(cnt == Count)
	{
		cnt = 0;
		//Code
		
		P2_0 = !P2_0;
		
		//Code
	}
}