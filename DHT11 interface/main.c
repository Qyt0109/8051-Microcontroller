#include "main.h"
#include "..\Library\LCD4.h"
#include "..\Library\Delay.h"
#include "..\Library\DHT11.h"

int I_RH,D_RH,I_Temp,D_Temp,CheckSum; 

void main()
{
	unsigned char Data[20];
	Lcd_Init();
	while(1)
	{
		Request();
		Response();
		
		I_RH = DHT11_Data();
		D_RH = DHT11_Data();
		I_Temp = DHT11_Data();
		D_Temp = DHT11_Data();
		CheckSum = DHT11_Data();
		
		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
		{
			Lcd_Out(0,0,"Error");
		}
		else
		{
			sprintf(Data,"Hum = %d.%d",I_RH,D_RH);
			Lcd_Out(0,0,Data);
			sprintf(Data,"Tem = %d.%d",I_Temp,D_Temp);   
			Lcd_Out(1,0,Data);
			Lcd_Chr_Cp(0xDF);
			Lcd_Chr_Cp('C');
			memset(Data,0,20);
			sprintf(Data,"%d   ",CheckSum);
			Lcd_Out(1,13,Data);
		}		
		Delay_ms(500);
	}
}









