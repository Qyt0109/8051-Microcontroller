#include "main.h"
#include "port.h"
#include "DHT11.h"
#include "Delay.h"

void Request()
{
	DHT11_Pin = 0;
	Delay_ms(20);
	DHT11_Pin = 1;
}

void Response()
{
	while(DHT11_Pin == 1);
	while(DHT11_Pin == 0);
	while(DHT11_Pin == 1);
}

int DHT11_Data()
{
	int q,c = 0;
	for(q=0;q<8;q++)
	{
		while(DHT11_Pin == 0);
		Delay_ms(1);
		if(DHT11_Pin == 1)
			c = (c<<1)|1;
		else
			c = (c<<1);
		while(DHT11_Pin == 1);
	}
	return c;
}





















