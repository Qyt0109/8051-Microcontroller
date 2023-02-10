#include "main.h"
#include "..\Library\Delay.h"
#include "..\Library\LCD 16x2.h"

/*
Thanh ghi Timer 16 bit => 2^16-1 = 65535 gia tri
Thach anh 12MHz => Xung cap cho Timer = 12M/12 = 1MHz ~ 1us

*/

void main()
{
	unsigned int t,f;
	
	LCD_INIT();
	LCD_OUT_SL(0,0,"T = 00000 us");
	LCD_OUT_SL(1,0,"f = 00000 Hz");
	
	//Cai dat Timer
	TMOD &= 0xF0;
	TMOD |= 0x09;		//Gate = 1; M0 = 1; CT = 0 (Mode 1, che do Timer)
	
	while(1)
	{
		TH0 = 0;
		TL0 = 0;
		
		while(INT0);	//Cho chan do tan so xung == 0		|
		while(!INT0);	//Cho chan do tan so xung == 1		| Bo qua xung dau tien, tranh do duoc 1 phan xung
		TR0 = 1;			//Bat dau Timer
		while(INT0);	//Cho chan do tan so xung == 0
		TR0 = 0;
		
		t = TH0;
		t <<= 8;
		t |= TL0;			//t = TH0 TL0
		
		t = t*2;				//us
		
		LCD_CHAR_SL(0,4,t/10000 	+ 0x30);		//Number + 0x30 = Number in ACSII
		LCD_CHAR_CL(t%10000/1000 	+ 0x30);
		LCD_CHAR_CL(t%1000	/100 	+ 0x30);
		LCD_CHAR_CL(t%100	/10 		+ 0x30);
		LCD_CHAR_CL(t%10				 	+ 0x30);
		
		f = 1000000/t;			//Hz
		
		LCD_CHAR_SL(1,4,f/10000 	+ 0x30);
		LCD_CHAR_CL(f%10000/1000 	+ 0x30);
		LCD_CHAR_CL(f%1000	/100 	+ 0x30);
		LCD_CHAR_CL(f%100	/10 		+ 0x30);
		LCD_CHAR_CL(f%10				 	+ 0x30);
	}
}