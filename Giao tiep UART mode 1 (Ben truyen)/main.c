#include "main.h"
#include "port.h"
#include "..\Library\UART mode 1.h"
#include "..\Library\Delay.h"

/*
Day la vdk truyen UART mode 1 (U1)
Co su dung che do tiet kiem nang luong, chi khi nao co nut bam, xay ra interrupt
moi thuc hien chuong trinh, sau khi thuc hien quay lai che do sleep
*/

void main()
{
	//Ngat ngoai 1
	IT1 = 1;
	EX1 = 1;
	EA  = 1;
	
	UART1_INIT(19200);	//Cai dat UART mode 1, baudrate 2400
	while(1)
	{
		PCON = PCON | 0x01;
	}
}

void EX1_INTR(void)	interrupt 2
{
	Delay_ms(20);		//Chong nhieu phim
	if(But0 == 0)
	{
		UART1_Char(0x70);
		while(!But0);	//Cho nha nut bam
	}
	if(But1 == 0)
	{
		UART1_Char(0x71);
		while(!But1);	//Cho nha nut bam
	}
	if(But2 == 0)
	{
		UART1_Char(0x72);
		while(!But2);	//Cho nha nut bam
	}
}
