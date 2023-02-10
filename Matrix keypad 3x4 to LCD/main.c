#include "main.h"
#include "..\Library\LCD 16x2.h"
#include "..\Library\3x4 keypad.h"
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
		if(Keypad != No_Key_Pressed)
		{
			Delay_ms(30);
			Keypad_Check = Check_Keypad();
			if(Keypad == Keypad_Check)
			{
				if(Keypad == '#')
				{
					LCD_CHAR_CL(Keypad);
					Delay_ms(200);
					Keypad_Check = Check_Keypad();
					if(Keypad == Keypad_Check)
					{
						Delay_ms(300);
						Keypad_Check = Check_Keypad();
						if(Keypad == Keypad_Check)
						{
							Delay_ms(300);
							Keypad_Check = Check_Keypad();
							if(Keypad == Keypad_Check)
							{
								Delay_ms(300);
								Keypad_Check = Check_Keypad();
								if(Keypad == Keypad_Check)
								{
								LCD_CMD(LCD_CLEAR);
								Delay_ms(500);
								LCD_OUT_SL(0,2,"PHONE NUMBER:");
								LCD_SL(1,0);
								}
							}
						}
					}
				}
				else if(Keypad == '*')
				{
					LCD_CHAR_CL(Keypad);
					Delay_ms(200);
					Keypad_Check = Check_Keypad();
					if(Keypad == Keypad_Check)
					{
						Delay_ms(300);
						Keypad_Check = Check_Keypad();
						if(Keypad == Keypad_Check)
						{
							Delay_ms(300);
							Keypad_Check = Check_Keypad();
							if(Keypad == Keypad_Check)
							{
								Delay_ms(300);
								Keypad_Check = Check_Keypad();
								if(Keypad == Keypad_Check)
								{
								LCD_CMD(LCD_CLEAR);
								LCD_OUT_SL(0,3,"CALLING...");
								Delay_ms(1000);
								LCD_OUT_SL(1,0,"HOLD # TO CANCEL");
								}
							}
						}
					}
				}
				else
				{
				LCD_CHAR_CL(Keypad);
				Delay_ms(200);
				}
			}
		}
	}
}