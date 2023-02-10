#include "main.h"
#include "..\Library\Delay.h"

unsigned char code Code7Seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define LED_PORT P3
sbit LED0_PIN = P2^0;
sbit LED1_PIN = P2^1;
void main()
{
	unsigned char dem;
	unsigned char chuc, donvi;
	unsigned int i;
	while(1)
	{
		for(dem = 0; dem < 60; dem++)
		{
			chuc = dem/10;
			donvi = dem%10;
		
		for(i=0; i<500;i++)
			{
				LED_PORT = Code7Seg[chuc];
				LED0_PIN = 0;
				Delay_ms(10);
				LED0_PIN = 1;
				LED_PORT = Code7Seg[donvi];
				LED1_PIN = 0;
				Delay_ms(10);
				LED1_PIN = 1;
//		LED0_PIN = 1;
//		for(i=0;i<=9;i++)
//		{
//		LED_PORT = Code7Seg[i];
//		Delay_ms(1000);
			}
		}
	}
}

