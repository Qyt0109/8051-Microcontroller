#include "main.h"
#include "port.h"
#include "..\Library\LCD 16x2.h"
#include "..\Library\Delay.h"
#include "..\Library\UART mode 1.h"

char LCD_NUM_Char[] = {'0','1','2','3','4','5','6','7','8','9'};

void LCD_OUT_NUM(X,Y,unsigned int NUM)
{
	unsigned int A;
	LCD_SL(X,Y);
	
	A = NUM/	10000;
	NUM = NUM%10000;
	LCD_CHAR_CL(LCD_NUM_Char[A]);
	
	A = NUM/	1000;
	NUM = NUM%1000;
	LCD_CHAR_CL(LCD_NUM_Char[A]);
	
	A = NUM/	100;
	NUM = NUM%100;
	LCD_CHAR_CL(LCD_NUM_Char[A]);
	
	A = NUM/	10;
	NUM = NUM%10;
	LCD_CHAR_CL(LCD_NUM_Char[A]);
	LCD_CHAR_CL(LCD_NUM_Char[NUM]);
}

unsigned int Read_Timer_Value()
{
	unsigned char Timer_Low_Value, Timer_High_Value;	//Cac bien luu gia tri trong thanh ghi Timer
	unsigned int Timer_Value;
	Timer_Low_Value = TL0;					//LLLL LLLL
	Timer_High_Value = TH0;					//HHHH HHHH
	Timer_Value = TH0;							//XXXX XXXX HHHH HHHH
	Timer_Value <<= 8;							//HHHH HHHH 0000 0000
	Timer_Value |= Timer_Low_Value; //HHHH HHHH LLLL LLLL
	return Timer_Value;
}


void main()
{
	TMOD &= 0xF0;		//Counter 0 mode 1, dem xung tu ben ngoai dua vao chan T0 (P3^4)
	TMOD |= 0x05;
	TR0 = 1;				//Bat dau count
	
	LCD_INIT();
	LCD_OUT_SL(0,4,"COUNTED:");
	LCD_OUT_NUM(1,5,"00000");
	while(1)
	{
		LCD_OUT_NUM(1,5,Read_Timer_Value());
		if(Count_Reset == 0)
		{
			Delay_ms(20);
			if(Count_Reset == 0)
			{
				TH0 = TL0 = 0;
				while(Count_Reset == 0);
			}
		}
	}
}