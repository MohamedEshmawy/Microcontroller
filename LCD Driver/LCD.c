
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


void delay_milli(int n);
void delay_micro(int n);
void LCD_init(void);
void LCD_Init_Pins(void);
void LCD_STR(char * str,int position,int length);

 
  Pin Data[4];
	Pin ENABLE ;
	Pin REGSEL ;
	Pin R_W    ;
 
 
void LCD_Init_Pins(){
	int i;
	for(i=0;i<4;i++) Data[i] = initPin('d',i,OUTPUT);
	 
	ENABLE = initPin('b',1,OUTPUT);
	 REGSEL = initPin('b',0,OUTPUT);
	 R_W     = initPin('b',2,OUTPUT);
} 

void LCD_init_V2()
{
	LCD_Init_Pins();
	delay_milli(20);
	setPins(Data,0x3,4);
	delay_milli(10);
	setPins(Data,0x3,4);
	delay_milli(10);
	setPins(Data,0x3,4);
	delay_milli(10);
	setPins(Data,0x2,4);
	delay_milli(10);
	
	LCD_init();
}

void LCD_STR(char * str,int position,int length){
		 int i;
		
	for(i=0;i<length;i++,position++){
		 setPin(&ENABLE,0);
		 setPin(&REGSEL,0);
		 setPin(&R_W, 0);
		 delay_milli(10);
		 
	   LCD_CMD(position );
		 setPin(&ENABLE,1);
		 delay_milli(10);
		 setPin(&ENABLE,0);
   	 delay_milli(10);
		 setPin(&REGSEL,1);
		 delay_milli(10);
		 setPins(Data,str[i],4);
		 setPin(&ENABLE,1);
		 delay_milli(30);
		 setPin(&ENABLE,0);
	}
	
	
}
 
void delay_milli(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}
 
void delay_micro(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}
 
}
