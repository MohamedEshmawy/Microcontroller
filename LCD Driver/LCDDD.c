	#include "tm4c123gh6pm.h"
#include "LCDDD.h"

#define lcd_Clear            0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home             0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode        0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff       0x08          // turn display off
#define lcd_DisplayOn        0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset    0x30          // reset the LCD
#define lcd_FunctionSet8bit  0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet8bit4 0x28          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor        0x80          // set cursor position
//----------------------------------------------------------------------------------------------
void delay_milli(int n);
void delay_micro(int n);
void LCD_Init_Pins(){
	
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= 0x18 ;  // PortF clock enable
  delay = SYSCTL_RCGCGPIO_R;        				// Delay   
  GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;   			// Unlock PORTD Commit register  
	GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;   			// Unlock PORTE Commit register  
  
	GPIO_PORTD_CR_R |= 0x0f;          				// Allow changes to first four pins of data pins      
  GPIO_PORTA_CR_R |= 0x07;         				  // Allow changes to PE1 and PE2     
  
  GPIO_PORTD_AMSEL_R &= ~0x0f;      				// Disable analog function
  GPIO_PORTA_AMSEL_R &= ~0x07;      	      // Disable analog function
  
	GPIO_PORTD_PCTL_R &= ~0xff;  			        // GPIO clear bit PCTL  
 	GPIO_PORTA_PCTL_R &= ~0xff;  			        // GPIO clear bit PCTL  

	GPIO_PORTD_AFSEL_R &= ~0xff;              // No alternate function
	GPIO_PORTA_AFSEL_R &= ~0xff;              // No alternate function
	
	GPIO_PORTD_DIR_R |= 0x0f;                 // First PORTD output
	GPIO_PORTA_DIR_R |= 0x07;                 // 2nd and third PORTE output
 
	GPIO_PORTD_DEN_R |= 0x0f;                 // Enable digital pins PD0 to PD3
	GPIO_PORTA_DEN_R |= 0x07;                 // Enable digital pins PE1 and PE2
 
}

void LCD_CMD(unsigned int cmd){
	unsigned long x = 10;
	GPIO_PORTE_DATA_R &=~0x08;
	
	GPIO_PORTE_DATA_R &=~ 0x02;	//Set register select to 0 
	delay_milli(x);
	GPIO_PORTD_DATA_R |= cmd;
	GPIO_PORTE_DATA_R |= 0x04;  //ENABLE
	delay_milli(x);
	GPIO_PORTE_DATA_R &=~ 0x04;
	delay_milli(x);
}
	

void LCD_Init(){
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
void Display_Char(char letter,unsigned int position){
		LCD_CMD(position);
		GPIO_PORTE_DATA_R  |= 0x02;		//set Register select to 1
		GPIO_PORTE_DATA_R  |= 0x04;		// set Enable to 1 while writing data to the data pins
		GPIO_PORTD_DATA_R  |= letter;delay(100000);
		GPIO_PORTE_DATA_R  &=~ 0x04;
}
void Display_str(char* str){
		int pos = 0x8F;
		char i =0;
		for(i = 0;i<3;i++,pos--)
		{
				Display_Char(str[i],pos);
				delay_milli(10);
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