#include "main.h"
#include "..\Library\Delay.h"
#include "..\Library\LCD 16x2.h"

void main()
{
	LCD_INIT();
	while(1)
	{
		LCD_CHAR_CL('q');
		Delay_ms(1000);
		LCD_SL(0,0);
		Delay_ms(1000);
		LCD_OUT_CL("QYT");
		Delay_ms(1000);
		LCD_CHAR_SL(1,15,'1');
		Delay_ms(1000);
		LCD_OUT_SL(1,2,"ET-E9");
		Delay_ms(1000);
		LCD_CMD(LCD_CLEAR);
		Delay_ms(1000);
//		char ABC;
//		for(ABC=0x20;ABC<=0xFF;ABC++)
//		{
//		LCD_CHAR_SL(0,0,ABC);
//			Delay_ms(1000);
//		}
	}
}


















