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

Mode 1: thu phat bat dong bo 8 bit, toc do baud thay doi boi Timer
Khung truyen:	[START] [DATA] [STOP]
							1 bit		8 bit	 1 bit
Neu nhan du lieu, bit [STOP] se duoc luu vao bit [RB8] trong thanh ghi SCON
Toc do Baud: thiet lap boi toc do tran cua Timer
Nguon cung cap xung clock de dong bo cac thanh ghi truyen du lieu noi tiep Mode 1 2 3 duoc thiet lap boi bo dem 16.
Ngo ra cua bo dem la xung clock tao toc do baud, xung ngo vao co the lap trinh bang phan mem
										 - - - - - - - - - - - - - - -
										|				Baud rate clock				|
										|	Serial port shift register	|
										 - - - - - - - - - - - - - - -
											^ ^ ^ ^
											|	|	|	|
										 - - - - -
16 x baudrate - - ->|		/12		|
										 - - - - -
										
Khi 1 lenh ghi du lieu len thanh ghi SBUF thi qua trinh truyen bat dau nhung phai doi cho toi khi bo chia 16 bi tran.
Co phat TI = 1 cung thoi diem bit Stop xuat hien tren chan TXD

Thiet lap toc do baud dung timer 1:
Khoi tao thanh ghi TMOD tu dong nap 8 bit va dat gia tri nap lai vao thanh ghi TH1 cua Timer 1 de tao ra toc do tran chinh xac
de thiet lap toc do baud. Thanh ghi TMOD duoc khoi tao de thiet lap toc do baud nhu sau:
							TMOD = 0010xxxx
	Baud rate = timer 1 overflow rate/32
VD: Toc do baud can truyen 1200, su dung thach anh 12MHz
Toc do tran timer 1 = baud rate x 32 = 38.4KHz
Xung cung cap cho Timer 1 = f_crystal/12 = 1MHz
	=> So xung dem moi lan tran = Xung/Toc do tran = 1M/38.4K = 26.041667 ~ 26
	=> Can nap TH1 = 256 - 26 hoac TH1 = -26

Toc do baud			Tan so thach anh	SMOD(PCON.7)	Gia tri TH1			Toc do thuc		Sai so
		9600							12MHz						1			 		-7	(0xF9)					8923				7%
		2400							12MHz						0					-13	(0xF3)					2404			 0.16%
		1200							12MHz						0					-26	(0xE6)					1202			 ~0%
	 19200					11.059MHz						1			 		-3	(0xFD)	 			 19200				0%
		9600					11.059MHz						0			 		-3	(0xFD)					9600				0%
		2400					11.059MHz						0					-12	(0xF4)					2400				0%
		1200					11.059MHz						0					-24	(0xE8)					1200				0%


*/

#include "main.h"
#include "UART mode 1.h"

void UART1_INIT(unsigned int BAUD_RATE)
{	
	SM0 = 0; SM1 = 1;		// Chon UART mode 1

	TMOD &= 0x0F;            // 0010 xxxx - Timer1 hoat dong o che do 8bit tu dong nap lai
	TMOD |= 0x20;
	
#if (FREQ_OSC == 11059200)
	if(BAUD_RATE==9600)
	{
		TH1 = 0xFD;				// Toc do baud 9600
		PCON&=0x7F;
	}
	else if(BAUD_RATE==2400)
	{
		TH1 = 0xF4;
		PCON&=0x7F;
	}
	else if(BAUD_RATE==1200)
	{
		TH1 = 0xE8;
		PCON&=0x7F;
	}
	else if(BAUD_RATE==19200)
	{
		TH1 = 0xFD;
		PCON|=0x80;
	}
	#elif (FREQ_OSC == 12000000)
	if(BAUD_RATE==9600)
	{
		TH1 = 0xF9;				// Toc do baud 9600
		PCON|=0x80;
	}
	else if(BAUD_RATE==2400)
	{
		TH1 = 0xF3;
		PCON&=0x7F;
	}
	else if(BAUD_RATE==1200)
	{
		TH1 = 0xE6;
		PCON&=0x7F;
	}
#else
	#error "Chi su dung FREQ_OSC = 12000000 hoac 11059200"
#endif
	
	TR1 = 1;				// Timer1 bat dau chay
	TI  = 1;					// San sang gui du lieu
	REN = 1;				// Cho phep nhan du lieu
}

void UART1_SET_BAUD_RATE(unsigned int BAUD_RATE)
{
	//while(TI == 0 || REN == 0);
#if (FREQ_OSC == 11059200)
	if(BAUD_RATE==9600)
	{
		TH1 = 0xFD;				// Toc do baud 9600
		PCON&=0x7F;
	}
	else if(BAUD_RATE==2400)
	{
		TH1 = 0xF4;
		PCON&=0x7F;
	}
	else if(BAUD_RATE==1200)
	{
		TH1 = 0xE8;
		PCON&=0x7F;
	}
	else if(BAUD_RATE==19200)
	{
		TH1 = 0xFD;
		PCON|=0x80;
	}
#elif (FREQ_OSC == 12000000)
	if(BAUD_RATE==9600)
	{
		TH1 = 0xF9;				// Toc do baud 9600
		PCON|=0x80;
	}
	else if(BAUD_RATE==2400)
	{
		TH1 = 0xF3;
		PCON&=0x7F;
	}
	else if(BAUD_RATE==1200)
	{
		TH1 = 0xE6;
		PCON&=0x7F;
	}
#endif
}
	

void UART1_Char(char c)
{
 	while(TI == 0);
	TI = 0;
	SBUF = c;
}

void UART1_Write(char * str)
{
	unsigned char i = 0;
 	while(str[i]!=0)
	{
		UART1_Char(str[i]);
		i++;
	}
}

char UART1_Data_Ready()
{
	return RI;
}

char UART1_Read()
{
	RI = 0;
	return SBUF;
}