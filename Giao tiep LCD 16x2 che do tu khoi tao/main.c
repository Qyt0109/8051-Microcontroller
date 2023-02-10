#include "main.h"
#include "port.h"
#include "..\Library\Delay.h"


/*
__________________________________________________________________
___CAC CHAN LCD 16x2___

VSS: 0V						VDD: 5V						VEE: Dieu chinh do tuong phan
RS: Chon thanh ghi (RS=0: Doc/ghi lenh, RS=1: Doc/du lieu)
R/W': Che do doc/ghi (R/W'=1: Doc (Read), R/W'=0: Ghi (Write))
E: Chan cho phep (Du lieu duoc doc/ghi tai thoi diem chan E chuyen
									trang thai tu cao xuong thap)
DB7-DB0: Bus du lieu de giao tiep voi LCD
LED+: Cuc duong den nen							LED-: Cuc am den nen
__________________________________________________________________

___CAC LENH CO BAN LCD 16x2___

Lenh									Chuc nang														T(us)

0x01		Xoa toan bo noi dung dang hien thi (Clear all)		1502
0x02		Di chuyen con tro ve vi tri dau man hinh					1502
0x06		Tu dong di chuyen con tro den vi tri tiep theo		 37
				moi khi xuat ra LCD 1 ky tu
0x0C		Bat hien thi va tat con tro												 37
0x0E		Bat hien thi va bat con tro												 37
0x80		Di chuyen con tro ve dau dong 1										 37
0xC0		Di chuyen con tro ve dau dong 2
0x38		Giao tiep 8 bit, hien thi 2 dong, font 5x7				 37
0x28		Giao tiep 4 bit, hien thi 2 dong, font 5x7				 37
___________________________________________________________________

___GUI LENH RA LCD___

B1: R/W'=0									Chon che do ghi ra LCD
B2: RS=0										Chon che do doc/ghi lenh
B3: Gui ma Lenh tuong ung		Gui lenh can giao tiep
		toi DB7-DB0
B4: E=0											Tao xung de LCD nhan lenh
		E=1
B5: Delay_us(T)							Delay de LCD thuc thi xong lenh
___________________________________________________________________

___GUI DATA RA LCD___

B1: R/W'=0									Chon che do ghi ra LCD
B2: RS=1										Chon che do doc/ghi du lieu
B3: Gui ma ASCII cua ky tu	Gui ky tu can hien thi
		toi DB7-DB0
B4: E=0											Tao xung de LCD nhan du lieu
		E=1
B5: Delay_us(T=37us)				Delay de LCD hien thi xong ky tu

*LUU Y: Ky tu duoc gui ra LCD se duoc hien thi tai vi tri con tro
___________________________________________________________________

___KHOI TAO LCD___

Tu khoi tao (HD44780): Che do giao tiep 8 bit, hien thi 1 dong tren,
											 tu dong tang con tro, tat hien thi
											 
											 
*/

void LCD_CMD(unsigned char CMD)
{
	LCD_RS = 0;
	LCD_BUS = CMD;
	LCD_EN = 0;
	LCD_EN = 1;
	if(CMD<=0x02)
		Delay_ms(2);
	else
		Delay_ms(1);
}

void LCD_CHAR_CP(char CHAR)		//Hien thi ky tu char tai vi tri hien tai cua con tro (Current Position)
{
	LCD_RS = 1;
	LCD_BUS = CHAR;
	LCD_EN = 0;
	LCD_EN = 1;
	Delay_ms(1);
}

void LCD_OUT_CP(char *p_str)	//Truyen con tro
{
	unsigned char i = 0;
	while(p_str[i] != 0)			//Check Null trong mang
	{
		LCD_CHAR_CP(p_str[i]);
		i++;
	}
}

void main()
{
	LCD_CMD(0x0E);
	LCD_CHAR_CP('A');
	LCD_OUT_CP(", xin chao");
	while(1)
	{
	
	}
}


















