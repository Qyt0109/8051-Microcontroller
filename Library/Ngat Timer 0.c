/*
Thanh ghi Timer 0: TH0 TL0
Thanh ghi Timer 1: TH1 TL1
Thanh ghi TMOD: [Gate][C/T][M1][M0] [Gate][C/T][M1][M0]
											TIMER 1							 TIMER 0
		[M1][M0]	Mode		Che do hoat dong
			0	 0		 0		Timer 13 bit: 8 bit THx, 5 bit TLx
			0	 1     1		Timer 16 bit: khong co dat truoc
			1  0     2		Timer 8  bit: auto reload
			1  1     3		Che do bo dinh thoi chia tach
			
		[C/T] = 0: Timer
					= 1: Counter
			Tan so Timer/Counter = Tan so thach anh/12
			VD: FREQ_OSC = 12MHz => f = 1MHz, t = 1/f = 1us
	Thuong 8051 su dung 11,0592MHz vi no cho phep truyen thong UART khong co loi
		[GATE] = 0: Cho phep start/stop Timer 0 bang TR0, Timer 1 bang TR1
		[GATE] = 1: Cho phep start/stop Timer 0 bang TR0, Timer 1 bang TR1, phan cung tu ben ngoai
	
Thanh ghi TCON:	[TF1][TR1][TF0][TR0] [IE1][IT1][IE0][IT0]
		[TFx]: Co bao tran Timer x (=1: tran)
		[TRx]: Co start/stop Timer x (0:stop, 1:start)
		
		Mode 0: Timer/Counter 13 bit (0x0000-0x1FFF)
		Mode 1: Timer/Counter 16 bit (0x0000-0xFFFF)
		Mode 2: Timer/Counter 8  bit (0xXX-0xFF voi XX la gia tri duoc cai dat trong thanh ghi THx)
						Khi dem, se tang dan gia tri TLx, khi = FF, TFx = 1
						Sau do, thanh ghi TLx se duoc nap gia tri tu thanh ghi THx
						De bat dau dem lai, can xoa co TFx bang phan mem
						=> Ung dung: Thiet lap toc do Baud cua
		Mode 3: It duoc su dung
		
		***
		Ngat trong 8051:
		- RESET: Khi reset, chuong trinh nhay ve dia chi 0x0000					STT ngat: -
		- 2 ngat Timer: Timer 0 (TF0) co dia chi chuong trinh ngat 0x000B			>>> 1 <<<
										Timer 1 (TF1) co dia chi chuong trinh ngat 0x001B					3
		- Ngat ngoai: IE0 0x0003 																									0
									IE1 0x0013																									2
		- Ngat truyen thong: RI/TI  0x0023																				4
		
		Khi co ngat xay ra:
		- Hoan thanh not cong viec dang thuc hien
		- Luu dia chi cua lenh ke tiep vao stack, luu tinh trang hien tai cua cac ngat
		- Nhay den dia chi cua truong trinh phuc vu ngat (Vung nho co dinh)
		- Thuc hien het cac lenh trong chuong trinh ngat
		- Tra lai dia chi lenh ke tiep da luu trong stack
		
		
		EA: Cho phep/Cam toan bo cac nguon ngat
		ES: Cho phep/Cam cong truyen thong noi tiep
		ETx: Ngat timer x
		EXx: Ngat ngoai x
*/

#include "main.h"
#include "Ngat Timer 0.h"

unsigned int Count, cnt, Timer0_Done;

//Thiet lap Timer 0 mode 1
void INTR_Timer0_INIT()
{
	TMOD &= 0xF0;		//Xoa cai dat Timer 0
	TMOD |= 0x01;		//Cai dat Timer 0 mode 1
	
	TH0 = 0x3C;			//Crystal 12MHz => Xung cap cho Timer = 12MHz/12 = 1MHz => 1 chu ky xung = 1/1MHz = 1us
									//De delay 50ms can 50ms/1us = 50000 chu ky xung
									//=> Timer can dem nguoc tu 2^16 - 50000 = 0x3CB0 = THx TLx
	TL0 = 0xB0;
	
	EA = 1;					//Cho phep ngat toan cuc
	ET0 = 1;				//Cho phep ngat Timer 0
	TR0 = 1;				//Start Timer
}

void Timer0_Overflow() interrupt 1
{
	//Reload Thanh ghi Timer 0
	TH0 = 0x3C;
	TL0 = 0xB0;
	cnt++;
	if(cnt==Count)
	{
		cnt = 0;
		P2_0 = !P2_0;
	}
	
}

void Set_Timer0_Time_ms(unsigned long time)
{
	Count = time/50;
	cnt = 0;
}

int Check_Timer0_Done()
{
	return Timer0_Done;
	Timer0_Done =0;
}
























