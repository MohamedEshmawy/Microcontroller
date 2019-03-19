#include "stdint.h"
#include "MCAL_Bouns.h"
#include "tm4c123gh6pm.h"

void Port_Init(unsigned char port_index)
{
 if (port_index ==0)
 {
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;         			  
  GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;   			 
  GPIO_PORTA_CR_R |= 0xFF;                
  GPIO_PORTA_AMSEL_R &= 0x00;
  GPIO_PORTA_PCTL_R &= 0x00;
  GPIO_PORTA_AFSEL_R &= 	0x00;
  GPIO_PORTA_DEN_R |= 0xFF;
 
 }
 else if (port_index ==1)
 {
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;         			  
  GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;   			 
  GPIO_PORTB_CR_R |= 0xFF;                
  GPIO_PORTB_AMSEL_R &= 0x00;
  GPIO_PORTB_PCTL_R &= 0x00;
  GPIO_PORTB_AFSEL_R &= 	0x00;
  GPIO_PORTB_DEN_R |= 0xFF;
 
 
 }
 else if (port_index ==2)
 {
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;         			  
  GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;   			 
  GPIO_PORTC_CR_R |= 0xFF;                
  GPIO_PORTC_AMSEL_R &= 0x00;
  GPIO_PORTC_PCTL_R &= 0x00;
  GPIO_PORTC_AFSEL_R &= 	0x00;
  GPIO_PORTC_DEN_R |= 0xFF;
 
 
 }
 else if (port_index ==3)
 {
 
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;         			  
  GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;   			 
  GPIO_PORTD_CR_R |= 0xFF;                
  GPIO_PORTD_AMSEL_R &= 0x00;
  GPIO_PORTD_PCTL_R &= 0x00;
  GPIO_PORTD_AFSEL_R &= 	0x00;
  GPIO_PORTD_DEN_R |= 0xFF;
 
 }
 else if (port_index ==4)
 {
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;         			  
  GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;   			 
  GPIO_PORTE_CR_R |= 0xFF;                
  GPIO_PORTE_AMSEL_R &= 0x00;
  GPIO_PORTE_PCTL_R &= 0x00;
  GPIO_PORTE_AFSEL_R &= 	0x00;
  GPIO_PORTE_DEN_R |= 0xFF;
 
 
 }
 
 else if (port_index ==5)
 {
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;         			  
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;   			 
  GPIO_PORTF_CR_R |= 0xFF;                
  GPIO_PORTF_AMSEL_R &= 0x00;
  GPIO_PORTF_PCTL_R &= 0x00;
  GPIO_PORTF_AFSEL_R &= 	0x00;
  GPIO_PORTF_DEN_R |= 0xFF;
 
 
 }


}




void Port_SetPinDirection(unsigned char port_index, unsigned char pins_mask, Port_PinDirectionType pins_direction)
	
{
  if (port_index ==0)
		
{
   if (pins_direction== PORT_PIN_IN)
		 
	{
	GPIO_PORTA_DIR_R  &= ~ pins_mask;
	}
	
	else if (pins_direction== PORT_PIN_OUT)		
	{
	GPIO_PORTA_DIR_R |= pins_mask;
	}

}

 else if (port_index ==1)
		
{
   if (pins_direction== PORT_PIN_IN)
		 
	{
	GPIO_PORTB_DIR_R  &= ~ pins_mask;
	}
	
	else if (pins_direction== PORT_PIN_OUT)		
	{
	GPIO_PORTB_DIR_R |= pins_mask;
	}

}


 else if (port_index ==2)
		
{
   if (pins_direction== PORT_PIN_IN)
		 
	{
	GPIO_PORTC_DIR_R  &= ~ pins_mask;
	}
	
	else if (pins_direction== PORT_PIN_OUT)			
	{
	GPIO_PORTC_DIR_R |= pins_mask;
	}

}


 else if (port_index ==3)
		
{
   if (pins_direction== PORT_PIN_IN)
		 
	{
	GPIO_PORTD_DIR_R  &= ~ pins_mask;
	}
	
	else if (pins_direction== PORT_PIN_OUT)			
	{
	GPIO_PORTD_DIR_R |= pins_mask;
	}

}


 else if (port_index ==4)
		
{
   if (pins_direction== PORT_PIN_IN)
		 
	{
	GPIO_PORTE_DIR_R  &= ~ pins_mask;
	}
	
	else if (pins_direction== PORT_PIN_OUT)		
	{
	GPIO_PORTE_DIR_R |= pins_mask;
	}

}


 else if (port_index ==5)
		
{
   if (pins_direction== PORT_PIN_IN)
		 
	{
	GPIO_PORTF_DIR_R  &= ~ pins_mask;
	}
	
	else if (pins_direction== PORT_PIN_OUT)			
	{
	GPIO_PORTF_DIR_R |= pins_mask;
	}

}



}



void Port_SetPinPullUp(unsigned char port_index, unsigned char pins_mask,unsigned char enable)
	
{
	
if (enable==1)
{
  if (port_index ==0)
 {
 
 GPIO_PORTA_PUR_R |= pins_mask;
 
 }
 else if (port_index ==1)
 {
 
 GPIO_PORTB_PUR_R |= pins_mask;
 
 }
 else if (port_index ==2)
 {
 
 GPIO_PORTC_PUR_R |= pins_mask;
 
 }
 else if (port_index ==3)
 {
 
 GPIO_PORTD_PUR_R |= pins_mask;
 
 }
 else if (port_index ==4)
 {
 
 GPIO_PORTE_PUR_R |= pins_mask;
 
 }
 else if (port_index ==5)
 {
 
 GPIO_PORTF_PUR_R |= pins_mask;
 
 }


}

else if (enable==0)
{
	if (port_index ==0)
 {
 
 GPIO_PORTA_PUR_R &= ~ pins_mask;
 
 }
 else if (port_index ==1)
 {
 
 GPIO_PORTB_PUR_R &= ~ pins_mask;
 
 }
 else if (port_index ==2)
 {
 
 GPIO_PORTC_PUR_R &= ~ pins_mask;
 
 }
 else if (port_index ==3)
 {
 
 GPIO_PORTD_PUR_R &= ~ pins_mask;
 
 }
 else if (port_index ==4)
 {
 
 GPIO_PORTE_PUR_R &= ~ pins_mask;
 
 }
 else if (port_index ==5)
 {
 
 GPIO_PORTF_PUR_R &= ~ pins_mask;
 
 }



}


}





void Port_SetPinPullDown(unsigned char port_index, unsigned char pins_mask,unsigned char enable)
{
if (enable==1)
{
  if (port_index ==0)
 {
 
 GPIO_PORTA_PDR_R |= pins_mask;
 
 }
 else if (port_index ==1)
 {
 
 GPIO_PORTB_PDR_R |= pins_mask;
 
 }
 else if (port_index ==2)
 {
 
 GPIO_PORTC_PDR_R |= pins_mask;
 
 }
 else if (port_index ==3)
 {
 
 GPIO_PORTD_PDR_R |= pins_mask;
 
 }
 else if (port_index ==4)
 {
 
 GPIO_PORTE_PDR_R |= pins_mask;
 
 }
 else if (port_index ==5)
 {
 
 GPIO_PORTF_PDR_R |= pins_mask;
 
 }


}

else if (enable==0)
{
	if (port_index ==0)
 {
 
 GPIO_PORTA_PDR_R &= ~ pins_mask;
 
 }
 else if (port_index ==1)
 {
 
 GPIO_PORTB_PDR_R &= ~ pins_mask;
 
 }
 else if (port_index ==2)
 {
 
 GPIO_PORTC_PDR_R &= ~ pins_mask;
 
 }
 else if (port_index ==3)
 {
 
 GPIO_PORTD_PDR_R &= ~ pins_mask;
 
 }
 else if (port_index ==4)
 {
 
 GPIO_PORTE_PDR_R &= ~ pins_mask;
 
 }
 else if (port_index ==5)
 {
 
 GPIO_PORTF_PDR_R &= ~ pins_mask;
 
 }



}


}



Dio_LevelType DIO_ReadPort(unsigned char port_index, unsigned char pins_mask)
{
	
 unsigned char data;
	
	if (port_index ==0)
 {
 data= (GPIO_PORTA_DATA_R &=  pins_mask) ;
  return data;
 
 }
 else if (port_index ==1)
 {
  data= (GPIO_PORTB_DATA_R &=  pins_mask) ;
  return data;

 
 }
 else if (port_index ==2)
 {
 
  data= (GPIO_PORTC_DATA_R &=  pins_mask) ;
  return data;
 
 }
 else if (port_index ==3)
 {
 
  data= (GPIO_PORTD_DATA_R &=  pins_mask) ;
  return data;
 
 }
 else if (port_index ==4)
 {
  data= (GPIO_PORTE_DATA_R &=  pins_mask) ;
  return data;

 
 }
 else if (port_index ==5)
 {
 data= (GPIO_PORTF_DATA_R &=  pins_mask) ;
  return data;
 
 }



}







void DIO_WritePort(unsigned char port_index, unsigned char pins_mask,unsigned char pins_level)
	
{
if( pins_level==1)
{
if (port_index ==0)
 {
 GPIO_PORTA_DATA_R |=  pins_mask;
 }
 else if (port_index ==1)
 {
  
GPIO_PORTB_DATA_R |=  pins_mask;
 
 }
 else if (port_index ==2)
 {
 GPIO_PORTC_DATA_R |=  pins_mask;
 
 
 }
 else if (port_index ==3)
 {
 GPIO_PORTD_DATA_R |=  pins_mask;
  
 }
 else if (port_index ==4)
 {
 GPIO_PORTE_DATA_R |=  pins_mask;

 
 }
 else if (port_index ==5)
 {
 
 GPIO_PORTF_DATA_R |=  pins_mask;
 }




}
else if( pins_level==0)
{

if (port_index ==0)
 {
 GPIO_PORTA_DATA_R &= ~ pins_mask;
 }
 else if (port_index ==1)
 {
  
GPIO_PORTB_DATA_R &= ~ pins_mask;
 
 }
 else if (port_index ==2)
 {
 GPIO_PORTC_DATA_R &= ~  pins_mask;
 
 
 }
 else if (port_index ==3)
 {
 GPIO_PORTD_DATA_R &= ~  pins_mask;
  
 }
 else if (port_index ==4)
 {
 GPIO_PORTE_DATA_R &= ~  pins_mask;

 
 }
 else if (port_index ==5)
 {
 
 GPIO_PORTF_DATA_R &= ~  pins_mask;
 }




}





}






void DIO_FlipPort(unsigned char port_index, unsigned char pins_mask)
{


if (port_index ==0)
 {
 GPIO_PORTA_DATA_R ^=  pins_mask;
 }
 else if (port_index ==1)
 {
  
GPIO_PORTB_DATA_R ^=  pins_mask;
 
 }
 else if (port_index ==2)
 {
 GPIO_PORTC_DATA_R ^=  pins_mask;
 
 
 }
 else if (port_index ==3)
 {
 GPIO_PORTD_DATA_R ^=  pins_mask;
  
 }
 else if (port_index ==4)
 {
 GPIO_PORTE_DATA_R ^=  pins_mask;

 
 }
 else if (port_index ==5)
 {
 
 GPIO_PORTF_DATA_R ^=  pins_mask;
 }



}






	
	

