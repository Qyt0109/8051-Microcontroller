#ifndef _PORT_H_
#define _PORT_H_

sbit LCD_RS = P3^6;				//Chan RS cua LCD
sbit LCD_EN = P3^7;				//Chan EN cua LCD
#define LCD_BUS P2				//Bus truyen nhan du lieu, ma lenh cua LCD (D7-D0)

sbit Count_Reset = P3^5;

#endif