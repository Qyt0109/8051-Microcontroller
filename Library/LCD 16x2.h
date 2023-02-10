#ifndef _LCD_16X2_
#define _LCD_16X2_

//LCD CMD:
#define LCD_CLEAR								0x01  		
#define LCD_RETURN_HOME					0x02
#define LCD_ENTRY_MODE					0x06
#define LCD_TURN_OFF						0x08
#define LCD_TURN_ON							0x0C
#define LCD_CURSOR_OFF					0x0C  
#define LCD_UNDERLINE_ON				0x0E
#define LCD_BLINK_CURSOR_ON			0x0F
#define LCD_MOVE_CURSOR_LEFT		0x10
#define LCD_MOVE_CURSOR_RIGHT		0x11
#define LCD_SHIFT_LEFT					0x18
#define LCD_SHIFT_RIGHT					0x1C
#define LCD_4BIT_1LINE_5x7FONT	0x20
#define LCD_4BIT_2LINE_5x7FONT	0x28
#define LCD_8BIT_1LINE_5x7FONT	0x30
#define LCD_8BIT_2LINE_5x7FONT	0x38
#define LCD_FIRST_ROW						0x80
#define LCD_SECOND_ROW					0xC0

//Nguyen mau ham:
void LCD_CMD(unsigned char CMD);
void LCD_SL(unsigned char ROW, unsigned char COL);
void LCD_CHAR_CL(char CHAR);
void LCD_CHAR_SL(unsigned char ROW, unsigned char COL, char CHAR);
void LCD_OUT_CL(char *p_str);
void LCD_OUT_SL(unsigned char ROW, unsigned char COL, char *p_str);
void LCD_INIT(void);

#endif