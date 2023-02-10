#ifndef _KEYPAD3X4_H_
#define _KEYPAD3X4_H_

//char Value[3][4] = {'0', '1', '2',
//										'3', '4', '5',
//										'6', '7', '8',
//										'*', '0', '#'};
#define No_Key_Pressed 0x00
#define ON_C 0x01

void Set_All();
char Check_Keypad();
											
#endif