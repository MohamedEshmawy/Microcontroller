#include "tm4c123gh6pm.h" 
 
#define LCD_CTRLP GPIO_PORTD_DATA_R
#define LCD_DATAP GPIO_PORTB_DATA_R
#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */
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
 
void delay_milli(int n);
void delay_micro(int n);
void LCD_init(void);
void LCD4bit_Cmd(unsigned char command);
void LCD4bit_Data(unsigned char data);
void LCD_Init_Pins();
void SystemInit(){LCD_init();}
 
int main()
{
 LCD_init();
 LCD4bit_Cmd(0x01);
	 delay_milli(500);
 LCD4bit_Cmd(0x80);
 delay_milli(500);
 
 LCD4bit_Data('a');
 delay_micro(20);
// LCD4bit_Data('E');
 delay_milli(500);
	while(1);
 
}
 
void LCD_Init_Pins(){
	
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= 0x0A ;  // PortF clock enable
  delay = SYSCTL_RCGCGPIO_R;        				// Delay   
  GPIO_PORTD_LOCK_R = 0x4C4F434B ;   			// Unlock PORTD Commit register  
	GPIO_PORTA_LOCK_R = 0x4C4F434B ;   			// Unlock PORTE Commit register  
  
	GPIO_PORTD_CR_R |= 0x0f;          				// Allow changes to first four pins of data pins      
  GPIO_PORTB_CR_R |= 0x07;         				  // Allow changes to PE1 and PE2     
  
  GPIO_PORTD_AMSEL_R &= ~0x0f;      				// Disable analog function
  GPIO_PORTB_AMSEL_R &= ~0x07;      	      // Disable analog function
  
	GPIO_PORTD_PCTL_R &= ~0xff;  			        // GPIO clear bit PCTL  
 	GPIO_PORTB_PCTL_R &= ~0xff;  			        // GPIO clear bit PCTL  

	GPIO_PORTD_AFSEL_R &= ~0xff;              // No alternate function
	GPIO_PORTB_AFSEL_R &= ~0xff;              // No alternate function
	
	GPIO_PORTD_DIR_R |= 0x0f;                 // First PORTD output
	GPIO_PORTB_DIR_R |= 0x07;                 // 2nd and third PORTE output
 
	GPIO_PORTD_DEN_R |= 0x0f;                 // Enable digital pins PD0 to PD3
	GPIO_PORTB_DEN_R |= 0x07;                 // Enable digital pins PE1 and PE2
 
} 
void LCD_init(){
		LCD_Init_Pins();
		LCD4bit_Cmd(lcd_Home); 
		delay_milli(10);
		LCD4bit_Cmd(lcd_FunctionSet8bit4);
		delay_milli(10);
		LCD4bit_Cmd(lcd_DisplayOn);
		delay_milli(10);
		LCD4bit_Cmd(lcd_Clear);
		delay_milli(10);
		LCD4bit_Cmd(lcd_Home);
		delay_milli(10);
}
void LCD4bit_Data(unsigned char data)
{
	LCD_CTRLP &=~ 0x07;
	delay_milli(10);
 LCD_CTRLP |= RS;
 LCD_CTRLP &= ~RW;
 delay_milli(10);
 LCD_DATAP = data;
 LCD_CTRLP = EN;
 delay_milli(10);
 LCD_CTRLP = RS;
 delay_micro(37);
 LCD_CTRLP &=~ EN;
}
 
void LCD4bit_Cmd(unsigned char command)
{
 
 LCD_CTRLP = 0x00;
 
 LCD_DATAP  =command;
 LCD_CTRLP |= EN ;
 LCD_CTRLP &=~ RW;
 LCD_CTRLP &=~ RS;
 delay_micro(2000);
 LCD_CTRLP = 0x00;
 LCD_CTRLP &=~ EN;
	
 
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