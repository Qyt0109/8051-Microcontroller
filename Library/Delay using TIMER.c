#include "Delay using TIMER.h"

void Delay_ms_Timer(unsigned int t)
{
	TMOD &= 0xF0;	//Xoa cac bit dieu khien cua Timer0, giu mode Timer1
	TMOD |= 0x01;	//Mode 1 cho Timer0
		while (t!=0)
	{
		TL0 = 0x27;
		TH0 = 0xfc;
		TR0 = 1;	//Start dem
		while(TF0!=1);
		TR0 = 0;	//Stop dem
		TF0 = 0;
		t--;
	}
}