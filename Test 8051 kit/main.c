#include "..\Library\Delay.h"
#include <regx52.h>



main()
{
	while(1)
	{
		P0=P1=P2=P3=0x00;
		Delay_ms(50000);
		P0=P1=P2=P3=0xFF;
		Delay_ms(50000);
	}
}