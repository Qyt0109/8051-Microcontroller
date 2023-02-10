#include "main.h"
#include "..\Library\Soft_I2c.h"
#include "..\Library\Lcd4.h"
#include "..\Library\Rtc_Ds1307.h"
#include "..\Library\LunarCalendar.h"
#include "port.h"

unsigned char * code Days[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
unsigned char Hour, Minute, Second, Mode, Day, Date, Month, Year, old_second;
unsigned char SolarDate, SolarMonth;
char SolarYear;

void main()
{
	Soft_I2c_Init();
	Ds1307_Init();
	Lcd_Init();
	
	Ds1307_Write(0x07, 0x10);	//Tao SOUT tan so 1 Hz
	
	//Cho phep ngat canh xuong INTR1 (bit IT1 trong thanh ghi TCON = 1)
	IT1 = 1;
	//Cho phep ngat Timer 1 (bit EX1 = 1)
	EX1 = 1;
	//Cho phep ngat toan cuc (bit EA = 1)
	EA = 1;

	while(1)
	{
		Ds1307_Read_Time(&Hour, &Minute, &Second, &Mode);
		Lcd_Chr(1,5,Hour/10+0x30);
		Lcd_Chr_Cp(Hour%10+0x30);
		Lcd_Chr_Cp(':');
		Lcd_Chr_Cp(Minute/10+0x30);
		Lcd_Chr_Cp(Minute%10+0x30);
		Lcd_Chr_Cp(':');
		Lcd_Chr_Cp(Second/10+0x30);
		Lcd_Chr_Cp(Second%10+0x30);

		Ds1307_Read_Date(&Day, &Date, &Month, &Year);
		if(BTN == 1)
		{
			Lcd_Out(2,1,"                ");
			Lcd_Out(2,2,Days[Day-1]);
			Lcd_Chr_Cp(' ');
			Lcd_Chr_Cp(Date/10+0x30);
			Lcd_Chr_Cp(Date%10+0x30);
			Lcd_Chr_Cp('/');
			Lcd_Chr_Cp(Month/10+0x30);
			Lcd_Chr_Cp(Month%10+0x30);
			Lcd_Out_Cp("/20");
			Lcd_Chr_Cp(Year/10+0x30);
			Lcd_Chr_Cp(Year%10+0x30);
		}
		else
		{
			Solar2Lunar(Date, Month, Year, &SolarDate, &SolarMonth, & SolarYear);
			Lcd_Out(2,1,"LUNAR:");
			Lcd_Chr_Cp(SolarDate/10+0x30);
			Lcd_Chr_Cp(SolarDate%10+0x30);
			Lcd_Chr_Cp('/');
			Lcd_Chr_Cp(SolarMonth/10+0x30);
			Lcd_Chr_Cp(SolarMonth%10+0x30);
			Lcd_Chr_Cp('/');
			Lcd_Chr_Cp((Year+2000)/1000+0x30);
			Lcd_Chr_Cp((Year+2000)/100%10+0x30);
			Lcd_Chr_Cp((Year+2000)/10%10+0x30);
			Lcd_Chr_Cp((Year+2000)%10+0x30);
		}
		PCON = PCON | 0x01;
	}
}

void EX1_ISR(void) interrupt 2
{
	
}