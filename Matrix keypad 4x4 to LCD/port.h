#ifndef _PORT_H_
#define _PORT_H_

//Ket noi keypad 3x4
sbit Keypad_Row_A = P1^0;
sbit Keypad_Row_B = P1^1;
sbit Keypad_Row_C = P1^2;
sbit Keypad_Row_D = P1^3;
sbit Keypad_Col_1 = P1^4;
sbit Keypad_Col_2 = P1^5;
sbit Keypad_Col_3 = P1^6;
sbit Keypad_Col_4 = P1^7;

//Ket noi LCD 16x2
sbit LCD_RS = P2^0;				//Chan RS cua LCD
sbit LCD_EN = P2^1;				//Chan EN cua LCD
#define LCD_BUS P3				//Bus giao tiep LCD

#endif
