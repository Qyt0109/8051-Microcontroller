/*Neu can nhieu ngo ra, vdk khong dap ung duoc thi can
su dung IC mo rong ngo ra nhu IC 74HC595
Du lieu duoc dich noi tiep tu 1 chan cua vdk ra IC, sau do
duoc xuat song song ra ben ngoai
Can 3 chan: 1 chan du lieu, 2 chan dieu khien dich du lieu, xuat du lieu
Co the ghep noi tiep nhieu IC 74HC595 de mo rong nhieu ngo ra hon nua
ma van su dung chi 3 chan cua vdk, luu y, toc do du lieu se bi giam di*/
//Sau day la chuong trinh dich 1 byte noi tiep sang IC 74HC595 duoi dang song song:

//DS: nhan du lieu tu vdk
//SH_CP: xung nhan du lieu noi tiep tu vdk
//ST_CP: xuat song song du lieu ra
//MR': chan reset (Noi Vcc)
//OE': chan chon chip (Noi Gnd)

#include "regx52.h"

//Khai bao ket noi
sbit IC_74HC595_ST_CP 	= P2^0;
sbit IC_74HC595_DS 		= P2^1;
sbit IC_74HC595_SH_CP 	= P2^2;

void Delay_ms(unsigned int t)
{
	unsigned int x,y;
	for(x=0;x<t;x++)
	{
		for(y=0;y<123;y++);
	}	
}
void Xuat_Byte(unsigned char Data_Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		//Chon bit thu i cua byte Data muon gui de xuat ra DS
		IC_74HC595_DS = Data_Byte & (0x80>>i);
		//	b0 b1 b2 b3 b4 b5 b6 b7
		//						&
		//	1  0  0  0  0  0  0  0 >> i
		
		//Nhan bit tu DS
		IC_74HC595_ST_CP = 0;
		//Tra lai xung 1 cua ST_CP, san sang nhan bit tiep theo
		IC_74HC595_ST_CP = 1;
	}
	//Xuat byte ra 74HC595
	IC_74HC595_SH_CP = 0;
	//Tra lai xung 1 cua SH_CP, san sang xuat byte tiep theo
	IC_74HC595_SH_CP = 1;
}

void main()
{
	while(1)
	{
		unsigned char Test;
		for(Test = 0; Test < 0x10000; Test++)
		{
			Xuat_Byte(Test);
			Delay_ms(100);
		}
	}
}