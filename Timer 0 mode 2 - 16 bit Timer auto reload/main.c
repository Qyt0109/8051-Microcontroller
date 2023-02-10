#include "main.h"


void Delay_Timer2_s(unsigned int sec)
{
	unsigned int i;
	TR2 = 1;		//Start Timer 2
	for(i=0;i<20*sec;i++)
	{
		while(!TF2);
		TF2 = 0;
	}
	TR2 = 0;
}

void main()
{
	T2CON = 0x00;
	T2MOD = 0x00;
	
	RCAP2H = 0x3C;
	RCAP2L = 0xB0;
	
	TH2 = 0x3C;
	TL2 = 0xB0;
	while(1)
	{
		P2=~P2;
		Delay_Timer2_s(2);
	}
}



