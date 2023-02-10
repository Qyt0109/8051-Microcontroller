#include "main.h"
#include "port.h"
#include "..\Library\UART mode 0 mo rong ngo vao dung IC 74165.h"
#include "..\Library\Delay.h"

void main()
{
	UART0_INIT();
	while(1)
	{
		P2 = UART0_Read();
	}
}