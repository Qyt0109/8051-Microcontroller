#include "main.h"
#include "port.h"
#include "..\Library\Delay.h"

void main()
{
	//Ngat ngoai 1
	IT1 = 1;
	EX1 = 1;
	EA  = 1;
	Led0 = Led1 = Led2 = Led3 = 0;
	while(1)
	{
		PCON = PCON | 0x01;
	}
}

void EX1_INTR(void)	interrupt 2
{
	Delay_ms(20);		//Chong nhieu phim
	if(But0 == 0)
	{
		Led0 = !Led0;	//Dao trang thai Led
		while(!But0);	//Cho nha nut bam
	}
	if(But1 == 0)
	{
		Led1 = !Led1;	//Dao trang thai Led
		while(!But1);	//Cho nha nut bam
	}
	if(But2 == 0)
	{
		Led2 = !Led2;	//Dao trang thai Led
		while(!But2);	//Cho nha nut bam
	}
	if(But3 == 0)
	{
		Led3 = !Led3;	//Dao trang thai Led
		while(!But3);	//Cho nha nut bam
	}
}