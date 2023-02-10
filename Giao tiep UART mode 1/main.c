#include "main.h"
#include "port.h"
#include "stdio.h"
#include "..\Library\UART mode 1.h"
#include "..\Library\LCD 16x2.h"
#include "..\Library\Delay.h"

/*
Day la vdk nhan UART mode 1 (U2)
Co su dung LCD 16x2 hien thi xem nut nao da duoc bam ben U1
*/

void main()
{
	LCD_INIT();
	UART1_INIT(19200);	//Cai dat UART mode 1, baudrate 2400
	LCD_OUT_SL(0,3,"THONG BAO:");
	while(1)
	{
		LCD_OUT_SL(1,0,"RD");
		if(RI==1)
		{
			LCD_OUT_SL(1,2,"RD");
			if(UART1_Read()==0x0E)
				LCD_OUT_SL(1,5,"Nut 0");
		}
	}
}

