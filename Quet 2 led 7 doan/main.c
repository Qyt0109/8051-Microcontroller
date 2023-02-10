#include "main.h"
#include "..\Library\Delay.h"

unsigned char code Code7Seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x0F, 0x7F, 0x6F};
#define LED_PORT P3
sbit LED0_PIN = P2^0;
sbit LED1_PIN = P2^1;
void main()
{
	while(1)
	{
		LED_PORT = Code7Seg[0];
		LED0_PIN = 0;
		Delay_ms(100);
		LED0_PIN = 1;
		LED_PORT = Code7Seg[1];
		LED1_PIN = 0;
		Delay_ms(100);
		LED1_PIN = 1;
	}
}