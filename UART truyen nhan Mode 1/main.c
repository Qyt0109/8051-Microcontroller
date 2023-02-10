#include "main.h"
#include "..\Library\UART mode 1.h"
#include "..\Library\Delay.h"

void main()
{
	UART1_INIT(1200);
	while(1)
	{
		UART1_Write("1");
		Delay_ms(500);
		UART1_Write("23");
		Delay_ms(500);
		UART1_SET_BAUD_RATE(2400);
		UART1_Write("4");
		Delay_ms(500);
		UART1_Write("56");
		Delay_ms(500);
		UART1_SET_BAUD_RATE(9600);
		UART1_Write("7");
		Delay_ms(500);
		UART1_Write("89");
		Delay_ms(500);
		UART1_SET_BAUD_RATE(19200);
		UART1_Write("A");
		Delay_ms(500);
		UART1_Write("BC");
		Delay_ms(500);
		UART1_SET_BAUD_RATE(1200);
	}
}