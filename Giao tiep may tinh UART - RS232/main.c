#include "main.h"
#include "..\Library\UART mode 1.h"
#include "..\Library\Delay.h"

void main()
{
	UART1_INIT(9600);
	
	while(1)
	{
		UART1_Write("Hello, it's me!\r\n");
		Delay_ms(1000);
	}
}