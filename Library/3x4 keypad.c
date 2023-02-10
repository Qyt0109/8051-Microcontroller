#include "main.h"
#include "3x4 keypad.h"
#include "port.h"
/*
Can tao file header port.h de khai bao ket noi phan cung
VD:

#ifndef _PORT_H_
#define _PORT_H_

sbit Keypad_Row_A = P1^0;
sbit Keypad_Row_B = P1^1;
sbit Keypad_Row_C = P1^2;
sbit Keypad_Row_D = P1^3;
sbit Keypad_Col_1 = P1^4;
sbit Keypad_Col_2 = P1^5;
sbit Keypad_Col_3 = P1^6;


#endif

*/


char Keypad_Value[4][3] = {'1', '2', '3',
													 '4', '5', '6',
													 '7', '8', '9',
													 '*', '0', '#'};
													 
void Set_All()
{
	Keypad_Col_1 = 1;
	Keypad_Col_2 = 1;
	Keypad_Col_3 = 1;
	Keypad_Row_A = 1;
	Keypad_Row_B = 1;
	Keypad_Row_C = 1;
	Keypad_Row_D = 1;
}

char Check_Keypad()
{
	char Keypad_Return = No_Key_Pressed;
	Set_All();
	
	Keypad_Row_A = 0;
	if (Keypad_Col_1 == 0)
		Keypad_Return = Keypad_Value[0][0];
	if (Keypad_Col_2 == 0)
		Keypad_Return = Keypad_Value[0][1];
	if (Keypad_Col_3 == 0)
		Keypad_Return = Keypad_Value[0][2];
	Keypad_Row_A = 1;
	
	Keypad_Row_B = 0;
	if (Keypad_Col_1 == 0)
		Keypad_Return = Keypad_Value[1][0];
	if (Keypad_Col_2 == 0)
		Keypad_Return = Keypad_Value[1][1];
	if (Keypad_Col_3 == 0)
		Keypad_Return = Keypad_Value[1][2];
	Keypad_Row_B = 1;
	
	Keypad_Row_C = 0;
	if (Keypad_Col_1 == 0)
		Keypad_Return = Keypad_Value[2][0];
	if (Keypad_Col_2 == 0)
		Keypad_Return = Keypad_Value[2][1];
	if (Keypad_Col_3 == 0)
		Keypad_Return = Keypad_Value[2][2];
	Keypad_Row_C = 1;
	
	Keypad_Row_D = 0;
	if (Keypad_Col_1 == 0)
		Keypad_Return = Keypad_Value[3][0];
	if (Keypad_Col_2 == 0)
		Keypad_Return = Keypad_Value[3][1];
	if (Keypad_Col_3 == 0)
		Keypad_Return = Keypad_Value[3][2];
	Keypad_Row_D = 1;

	return Keypad_Return;
}









