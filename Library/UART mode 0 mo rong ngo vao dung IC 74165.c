/*
UART la chuan truyen noi tiep khong dong bo, co kha nang truyen song cong
UART trong 8051:
TxD: Chan truyen			RxD: Chan nhan
SBUF: Thanh ghi dem (address 0x99)
SCON: Thanh ghi trang thai, dieu khien hoat dong truyen (address 0x98)
										[SM0][SM1][SM2][REN] [TB8][RB8][TI][RI]
			
			 bit																Mo ta																							Dia chi
			[SM0]	 bit 0 chon kieu truyen noi tiep																									0x9F
			[SM1]	 bit 1 chon kieu truyen noi tiep																									0x9E
			[SM2]	 bit cho phep truyen ket noi nhieu VXL o mode 2 va mode 3,												0x9D
						 RI se khong tich cuc neu bit thu 9 nhan duoc la 0.
			[REN]	 bit cho phep nhan ky tu. REN = 0 khong cho phep, REN = 1 cho phep nhan ky tu			0x9C
			[TB8]	 Luu bit 9 de truyen di khi hoat dong o mode 2 va 3.															0x9B
						 TB8 = 0 hay 1 la do nguoi lap trinh thiet lap
			[RB8]	 Nhan bit 9 khi hoat dong o mode 2 va 3																						0x9A
			[TI]	 TI = 1 bao hieu truyen xong 1 ky tu. TI khong tu dong xoa,												0x99
						 nguoi lap trinh tu xoa khi san sang truyen ky tu tiep theo
			[RI]	 RI = 1 bao hieu nhan xong 1 ky tu. RI khong tu dong xoa,													0x98
						 nguoi lap trinh tu xoa khi san sang nhan ky tu tiep theo

Kieu truyen:
		[SM0] [SM1]	Mode				Mo ta										Baud																										Chuc nang
			0			0			0			Thanh ghi dich		Co dinh  (f_crystal/12)										Mo rong ngo vao, ngo ra cho vxl 								(Dong bo)
			0			1			1				UART 8 bit			Thay doi (duoc dat boi Timer)							Truyen nhan du lieu vxl <-> ngoai vi, vxl,...	(Bat dong bo)
			1			0			2				UART 9 bit			Co dinh	 (f_crystal/12 hoac f_crystal/64)	Truyen nhan du lieu vxl <-> ngoai vi, vxl,...	(Bat dong bo)
			1			1			3				UART 9 bit			Thay doi (duoc dat boi Timer)							Truyen nhan du lieu vxl <-> ngoai vi, vxl,...	(Bat dong bo)

Luu y: gui va nhan UART bit LSB truoc, lan luot toi bit MSB
			
			
Mode 0 ung dung mo rong ngo vao:
			8051	 				Shift Register (VD: 74165)
								 - - - - - - - - - - -
			TXD	<-----|	Clock (CLK)					|<-----		8
			RXD	<-----|	Data	(S0)					|<-----	Extra
UART_SH_LD<-----| Xuat du lieu (SH_LD)|. . .	INput
			GND <-----|	INH									|<-----
								 - - - - - - - - - - - 
								 
*/
#include "main.h"
#include "port.h"

/*
Can tao port.h nhu vi du sau:

#ifndef _PORT_H_
#define _PORT_H_

sbit UART_SH_LD = P3^2;

#endif
*/

void UART0_INIT()
{
	SM0 = SM1 = 0;
	REN = 1;	//Cho phep nhan du lieu
}
unsigned char UART0_Read()
{
	UART_SH_LD = 0;
	UART_SH_LD = 1;
	
	RI = 0;
	while(RI == 0);
	return SBUF;
}












