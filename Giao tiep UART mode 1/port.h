#ifndef _PORT_H_
#define _PORT_H_

sbit LCD_RS = P1^0;				//Chan RS cua LCD
sbit LCD_EN = P1^1;				//Chan EN cua LCD
#define LCD_BUS P2				//Bus truyen nhan du lieu, ma lenh cua LCD (D7-D0)

#endif
