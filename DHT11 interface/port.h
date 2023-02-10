#ifndef _PORT_H_
#define _PORT_H_

sbit DHT11_Pin = P2^1;

sbit LCD_RS	= P0^0;
sbit LCD_RW = P0^1; //(optional)
sbit LCD_EN	= P0^2;
sbit LCD_D4	= P2^4;
sbit LCD_D5 = P2^5;
sbit LCD_D6 = P2^6;
sbit LCD_D7 = P2^7;

#endif