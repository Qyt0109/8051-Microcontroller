#ifndef _UART_MODE_1_H_
#define _UART_MODE_1_H_

// Khoi tao UART o mode 1
void UART1_INIT(unsigned int BAUD_RATE);

// Gui 1 ky tu ra UART
void UART1_Char(char c);

// Gui 1 chuoi ra UART
void UART1_Write(char *str);

// Kiem tra xem co nhan duoc byte du lieu chua
// Tra ve 1: Da nhan duoc
//        0: Chua nhan duoc
char UART1_Data_Ready();

// Doc byte nhan duoc tu UART
char UART1_Read();

/*
Cac baurate co the cai dat:
FREQ_OSC = 12000000:	1200	2400
FREQ_OSC = 11059200:	1200	2400	9600	19200
*/
void UART1_SET_BAUD_RATE(unsigned int BAUD_RATE);

#endif
