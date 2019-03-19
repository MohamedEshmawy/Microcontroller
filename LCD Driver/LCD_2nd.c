
#include "LCD.h"

#define HIGH 1
#define LOW 0
#define lcd_Clear            0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home             0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode        0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff       0x08          // turn display off
#define lcd_DisplayOn        0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset    0x30          // reset the LCD
#define lcd_FunctionSet8bit  0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet8bit4 0x28          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor        0x80          // set cursor position
#define NUMBER(x)            0x30+x
void LCD_CHAR(int num );
void LCD_CMD(unsigned char command);
void  display_num (int x);
void LCD_init();



void  display_num (int x)
{
	int first = x%10;
	int second = (x/10)%10;
	int third = x/100;
	
	LCD_CMD(0x87);
	LCD_CHAR(third);
	LCD_CHAR(second);
	LCD_CHAR(first);
}
void LCD_init(){
		LCD_Init_Pins();
		LCD_CMD(lcd_Home); 
		delay_milli(10);
		LCD_CMD(lcd_FunctionSet8bit4);
		delay_milli(10);
		LCD_CMD(lcd_DisplayOn);
		delay_milli(10);
		LCD_CMD(lcd_Clear);
		delay_milli(10);
		LCD_CMD(lcd_Home);
		delay_milli(10);
}
void LCD_CHAR(int num )
{
		 char x = (NUMBER(num))>>4;
		 setPin(&REGSEL,1);
		 delay_milli(10);
		 setPins(Data,x,4);
		 delay_milli(10);
		 setPin(&ENABLE,1);
		 delay_milli(10);
		 setPin(&ENABLE,0);
	
		 setPins(Data,(NUMBER(num)),4);
		 delay_milli(10);
		 setPin(&ENABLE,1);
		 delay_milli(10);
		 setPin(&ENABLE,0);
		 
}

void LCD_CMD(unsigned char command)
{
		char x = command >>4;
		setPin(&ENABLE,0);
		setPin(&REGSEL,0);
		setPin(&R_W,   0);
		delay_milli(10);
		setPins(Data,x,4);
		setPin(&ENABLE,1);
		delay_milli(10);
		setPin(&ENABLE,0);
	//-----------------------
		delay_milli(10);
		setPins(Data ,command,4);
		setPin(&ENABLE,1);
		delay_milli(10);
		setPin(&ENABLE,0);
		delay_milli(10);
}