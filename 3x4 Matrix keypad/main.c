#include "main.h"
#include "..\Library\3x4 keypad.h"

void main()
{
	while(1)
	{
		P3 = Check_Keypad();
	}
}