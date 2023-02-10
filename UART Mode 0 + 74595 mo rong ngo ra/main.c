#include "main.h"
#include "port.h"
#include "..\Library\UART mode 0 mo rong ngo ra dung IC 74595.h"
#include "..\Library\Delay.h"

void main()
{
	UART0_INIT();
	while(1)
	{
		UART0_Write(0xAF);
		Delay_ms(1000);
		UART0_Write(0x50);
		Delay_ms(1000);
	}
	
}