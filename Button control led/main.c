#include <../Library/Delay using TIMER.h>
#define Delay_time 20
void main()
{
	unsigned int i,j;
	
	while(1)
	{
		if(P1_0==1)
		{
			P0=3;
			for(j=0;j<10;j++)
			{
				Delay_ms_Timer(Delay_time);
				if(P1_0==0)
					break;
			}
			for(i=1;i<=4;i++)
			{
				P0 <<= 2;
				for(j=0;j<10;j++)
			{
				Delay_ms_Timer(Delay_time);
				if(P1_0==0)
					break;
			}
		}
	}
		else
		{
			P0=0xAA;
			for(i=0;i<10;i++)
			{
				Delay_ms_Timer(Delay_time);
				if(P1_0==1)
					break;
			}
			for(i=1;i<=4;i++)
			{
				P0 =~P0;
				for(j=0;j<10;j++)
			{
				Delay_ms_Timer(Delay_time);
				if(P1_0==1)
					break;
			}
		}
	}
}
}