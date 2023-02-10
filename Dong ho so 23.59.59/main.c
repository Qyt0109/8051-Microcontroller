#include "main.h"
#include "..\Library\Delay.h"

#define LED_PORT P2		//Data cho led tu port 2
sbit LEDH0_PIN = P3^0;	//Chan led gio 0
sbit LEDH1_PIN = P3^1;	//Chan led gio 1
sbit LEDM0_PIN = P3^2;	//Chan led phut 0
sbit LEDM1_PIN = P3^3;	//Chan led phut 1
sbit LEDS0_PIN = P3^4;	//Chan led giay 0
sbit LEDS1_PIN = P3^5;	//Chan led giay 1

unsigned char code Code7Seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void main()
{
	unsigned char gio, phut, giay, chuc, donvi, i;
	gio = phut = giay = 0;
	while(1)
	{
		for(i = 0; i<1; i++)
		{
			//Hien gio
			chuc = gio/10;
			donvi = gio%10;
			LED_PORT = Code7Seg[chuc];
			LEDH0_PIN = 0;
			Delay_ms(1);
			LEDH0_PIN = 1;

			LED_PORT = Code7Seg[donvi];
			LEDH1_PIN = 0;
			Delay_ms(1);
			LEDH1_PIN = 1;

					//Hien phut
			chuc = phut/10;
			donvi = phut%10;
			LED_PORT = Code7Seg[chuc];
			LEDM0_PIN = 0;
			Delay_ms(1);
			LEDM0_PIN = 1;

			LED_PORT = Code7Seg[donvi];
			LEDM1_PIN = 0;
			Delay_ms(1);
			LEDM1_PIN = 1;

					//Hien giay
			chuc = giay/10;
			donvi = giay%10;
			LED_PORT = Code7Seg[chuc];
			LEDS0_PIN = 0;
			Delay_ms(1);
			LEDS0_PIN = 1;

			LED_PORT = Code7Seg[donvi];
			LEDS1_PIN = 0;
			Delay_ms(1);
			LEDS1_PIN = 1;
		}
		//Tang 1s
		giay++;
		if(giay==60)
		{
			giay = 0;
			phut++;
			if(phut==60)
			{
				phut = 0;
				gio++;
				if(gio==24)
					gio = 0;
			}
		}
	}
}













