//Giao tiep LCD 16x2
/*Can khai bao cac file thu vien vao main.c

#include "main.h"
#include "..\Library\LCD 16x2.h"

*/

#include "main.h"
#include "LCD 16x2.h"
#include "port.h"
#include "Delay.h"

/*

LUU Y: Tao file header port.h de khai bao ket noi phan cung tuong tu theo vi du sau:

#ifndef _PORT_H_
#define _PORT_H_

//Neu su dung che do giao tiep 8 bit:

//sbit LCD_RS = P2^0;				//Chan RS cua LCD
//sbit LCD_EN = P2^1;				//Chan EN cua LCD
//#define LCD_BUS P3				//Bus truyen nhan du lieu, ma lenh cua LCD (D7-D0)

//Neu su dung che do giao tiep 4 bit:

//sbit LCD_RS	= P0^0;
//sbit LCD_RW = P0^1;
//sbit LCD_EN	= P0^2;
//sbit LCD_D4	= P2^4;
//sbit LCD_D5 = P2^5;
//sbit LCD_D6 = P2^6;
//sbit LCD_D7 = P2^7;

#endif

*/

/*

__________________________________________________________________
___CAC CHAN LCD 16x2___

VSS: 0V						VDD: 5V						VEE: Dieu chinh do tuong phan
RS: Chon thanh ghi (RS=1: Doc/ghi du lieu, RS=0: Doc/ghi lenh)
R/W': Che do doc/ghi (R/W'=1: Doc (Read), R/W'=0: Ghi (Write))
E: Chan cho phep (Du lieu duoc doc/ghi tai thoi diem chan E chuyen
									trang thai tu cao xuong thap)
DB7-DB0: Bus du lieu de giao tiep voi LCD
LED+: Cuc duong den nen							LED-: Cuc am den nen
__________________________________________________________________

___CAC LENH CO BAN LCD 16x2___

Lenh									Chuc nang														T(us)

0x01		Xoa toan bo noi dung dang hien thi (Clear all)		1502
0x02		Di chuyen con tro ve vi tri dau man hinh					1502
0x06		Tu dong di chuyen con tro den vi tri tiep theo		 37
				moi khi xuat ra LCD 1 ky tu
0x0C		Bat hien thi va tat con tro												 37
0x0E		Bat hien thi va bat con tro												 37
0x80		Di chuyen con tro ve dau dong 1										 37
0xC0		Di chuyen con tro ve dau dong 2
0x38		Giao tiep 8 bit, hien thi 2 dong, font 5x7				 37
0x28		Giao tiep 4 bit, hien thi 2 dong, font 5x7				 37
___________________________________________________________________

___GUI LENH RA LCD___

B1: R/W'=0									Chon che do ghi ra LCD
B2: RS=0										Chon che do doc/ghi lenh
B3: Gui ma Lenh tuong ung		Gui lenh can giao tiep
		toi DB7-DB0
B4: E=0											Tao xung de LCD nhan lenh
		E=1
B5: Delay_us(T)							Delay de LCD thuc thi xong lenh
___________________________________________________________________

___GUI DATA RA LCD___

B1: R/W'=0									Chon che do ghi ra LCD
B2: RS=1										Chon che do doc/ghi du lieu
B3: Gui ma ASCII cua ky tu	Gui ky tu can hien thi
		toi DB7-DB0
B4: E=0											Tao xung de LCD nhan du lieu
		E=1
B5: Delay_us(T=37us)				Delay de LCD hien thi xong ky tu

*LUU Y: Ky tu duoc gui ra LCD se duoc hien thi tai vi tri con tro
___________________________________________________________________

___KHOI TAO LCD___

Tu khoi tao (HD44780): Che do giao tiep 8 bit, hien thi 1 dong tren,
											 tu dong tang con tro, tat hien thi
Khoi tao tuy chinh:
Cap nguon LCD, Delay 15-40ms (100ms)
Gui ma lenh 0011 xxxx	(Lay 0x38 cho de nho)
Delay 4100us	(5ms)
Gui ma lenh 0011 xxxx
Delay 100us		(1ms)
Gui ma lenh 0011 xxxx
Gui ma lenh 001[DL] [N][F]xx (Thuong lay 0x38)
trong do: [DL]=0: Giao tiep 8 bit (DB7-DB0)
					[DL]=1:	Giao tiep 4 bit (DB7-DB4), byte lenh/du lieu se duoc gui/nhan 4 bit cao truoc, 4 bit thap sau
					[N]	=0: Hien thi 1 dong
					[N] =1: Hien thi 2 dong
					[F] =0: Font 5x8	(hien thi ky tu o dong tren hoac dong duoi)
					[F] =1: Font 5x10 (hien thi ky tu ton mat ca 2 dong)
____________________________________________________________________

___VUNG NHO DDRAM LCD___

Vung DDRAM 80 byte luu cac ky tu can hien thi.
Danh dau dia chi che do 2 dong:
 /																													 \
|00	01	02	03	04	05	06	07	08	09	0A	0B	0C	0D	0E	0F| 10 11 ... 27
|H	E		L		L		O				W		O		R		L		D											|
|																															|
|40	41	42	43	44	45	46	47	48	49	4A	4B	4C	4D	4E	4F|	50 51 ... 67
 \																													 /
											 Vung hien thi
Set dia chi DDRAM de di chuyen con tro toi 1 vi tri trong DDRAM, tu do hien thi ky tu/chuoi ky tu tai 1 vi tri bat ki
Ma lenh:	1[7 bit DDRAM address]
VD: Xuat ky tu 'W' ra LCD tai dong 1 cot thu 7:
Gui lenh 1000 0110 (0x86)
Gui char 'W'

_____________________________________________________________________

___BANG MA ACSII___

20	space
21	!
22	"
23	#
24	$
25	%
26	&
27	'
28	(
29	)
2A	*
2B	+
2C	,
2D	-
2E	.
2F	/
30	0
31	1
32	2
33	3
34	4
35	5
36	6
37	7
38	8
39	9
3A	:
3B	;
3C	<
3D	=
3E	>
3F	?
40	@
41	A
42	B
43	C
44	D
45	E
46	F
47	G
48	H
49	I
4A	J
4B	K
4C	L
4D	M
4E	N
4F	O
50	P
51	Q
52	R
53	S
54	T
55	U
56	V
57	W
58	X
59	Y
5A	Z
5B	[
5C	\
5D	]
5E	^
5F	_
60	`
61	a
62	b
63	c
64	d
65	e
66	f
67	g
68	h
69	i
6A	j
6B	k
6C	l
6D	m
6E	n
6F	o
70	p
71	q
72	r
73	s
74	t
75	u
76	v
77	w
78	x
79	y
7A	z
7B	{
7C	|
7D	}
7E	~
________________________________________________________________________
											
*/

void LCD_CMD(unsigned char CMD)
{
	LCD_RS = 0;
	LCD_BUS = CMD;
	LCD_EN = 0;
	LCD_EN = 1;
	if(CMD==0x01||CMD==0x02)
		Delay_ms(2);
	else
		Delay_ms(1);
}

void LCD_SL(unsigned char ROW, unsigned char COL)	//Select Location (SL) cua con tro
{
	unsigned char CMD;
	if(ROW==0)
		CMD = 0x80 | COL;
	if(ROW==1)
		CMD = 0xC0 | COL;
	LCD_CMD(CMD);
}

void LCD_CHAR_CL(char CHAR)		//Hien thi ky tu char tai vi tri hien tai cua con tro (Current LOCATION (CL))
{
	LCD_RS = 1;
	LCD_BUS = CHAR;
	LCD_EN = 0;
	LCD_EN = 1;
	Delay_ms(1);
}

void LCD_CHAR_SL(unsigned char ROW, unsigned char COL, char CHAR)
{
	LCD_SL(ROW, COL);
	LCD_CHAR_CL(CHAR);
}

void LCD_OUT_CL(char *p_str)	//Truyen con tro chuoi ky tu
{
	unsigned char i = 0;
	while(p_str[i] != 0)			//Check Null trong mang
	{
		LCD_CHAR_CL(p_str[i]);
		i++;
	}
}

void LCD_OUT_SL(unsigned char ROW, unsigned char COL, char *p_str)
{
	LCD_SL(ROW, COL);
	LCD_OUT_CL(p_str);
}

void LCD_INIT()
{
	
	LCD_CMD(0x38);
	Delay_ms(5);
	LCD_CMD(0x38);
	Delay_ms(1);
	LCD_CMD(0x38);
	
	LCD_CMD(0x38);		// Ma lenh thiet lap che do 8 bit, 2 dong, font 5x8
										// 001[1] [1][0]xx
	LCD_CMD(0x0C);		// Bat hien thi, bat con tro
	
}
