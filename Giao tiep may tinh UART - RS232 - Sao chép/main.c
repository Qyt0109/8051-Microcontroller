#include "main.h"
#include "..\Library\UART mode 1.h"
#include "..\Library\Delay.h"

void main()
{
	UART1_INIT(9600);
	
	while(1)
	{
		UART1_Write("10002000");
		Delay_ms(500);
		UART1_Write("12001800");
		Delay_ms(500);
		UART1_Write("14001600");
		Delay_ms(500);
		UART1_Write("16001400");
		Delay_ms(500);
	}
}