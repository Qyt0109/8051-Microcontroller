#include "main.h"
#include "..\Library\Delay.h"
#include "..\Library\UART mode 1.h"
#include "stdio.h"

sbit LED_Pin = P2^0;
sbit LED_But = P1^0;
char RX_Data, TX_Data;

main()
{
	UART1_INIT(9600);
	while(1)
	{
		if(UART1_Data_Ready())
		{
			RX_Data = UART1_Read();
			if(RX_Data = '@')
			{
				UART1_Char('1');
				LED_Pin = 0;
			}
			else if(RX_Data = 'F')
			{
				UART1_Char('0');
				LED_Pin = 1;
			}
		}
		
		if(LED_But == 0)
		{
			Delay_ms(20);
			if(LED_But == 0)
			{
				while(LED_But == 0);
				UART1_Write("X");
				LED_Pin = !LED_Pin;
			}
		}
	}
}