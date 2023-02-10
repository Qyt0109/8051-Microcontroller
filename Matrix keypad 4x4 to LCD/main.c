#include "main.h"
#include "..\Library\LCD 16x2.h"
#include "..\Library\4x4 keypad.h"
#include "..\Library\Delay.h"

void main()
{
	char Keypad, Keypad_Check;
	LCD_INIT();
	LCD_OUT_SL(0,2,"KEY PRESSED:");
	LCD_SL(1,0);
	while(1)
	{
		Keypad = Check_Keypad();
		if(Keypad != 0x00)
		{	
			Delay_ms(30);
			Keypad_Check = Check_Keypad();
			if(Keypad == Keypad_Check)
			{
				LCD_CHAR_CL(Keypad);
				Delay_ms(200);
			}
		}
		
		if(Keypad == ON_C)
		{
			LCD_CMD(LCD_CLEAR);
			LCD_OUT_SL(0,2,"KEY PRESSED:");
			LCD_SL(1,0);
		}
	}
}