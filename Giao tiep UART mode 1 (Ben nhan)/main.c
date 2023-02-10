#include "main.h"
#include "port.h"
#include "..\Library\UART mode 1.h"
#include "..\Library\LCD 16x2.h"
#include "..\Library\Delay.h"

/*
Day la vdk nhan UART mode 1 (U2)
Co su dung LCD 16x2 hien thi xem nut nao da duoc bam ben U1
*/

void main()
{
	UART1_INIT(2400);	//Cai dat UART mode 1, baudrate 2400
	LCD_INIT();
	while(1)
	{
		if(UART1_Read() == "Nut 0")
		{
			LCD_CMD(LCD_CLEAR);
			LCD_OUT_SL(0,5,"THONG BAO:");
			LCD_OUT_SL(1,3,"Nut 0 da duoc bam");
		}
		if(UART1_Read() == "Nut 1")
		{
			LCD_CMD(LCD_CLEAR);
			LCD_OUT_SL(0,5,"THONG BAO:");
			LCD_OUT_SL(1,3,"Nut 1 da duoc bam");
		}
		if(UART1_Read() == "Nut 2")
		{
			LCD_CMD(LCD_CLEAR);
			LCD_OUT_SL(0,5,"THONG BAO:");
			LCD_OUT_SL(1,3,"Nut 2 da duoc bam");
		}
	}
}

