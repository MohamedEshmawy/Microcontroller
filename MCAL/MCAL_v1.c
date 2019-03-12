#include "MCAL.h"
#include <stdlib.h>



Pin initPin(char portIndex, int pinNum ,_Bool ioState)
{
		
	volatile unsigned long delay; 
	unsigned long pinMask = GPIO_PX_M(pinNum);
	unsigned long pctlPinMask = GPIO_PCTL_PX_M(pinNum);
	
	Pin pin;
	pin.pinNum = pinNum;
	pin.portIndex = portIndex;
	pin.state = ioState;

	  			         				
	
	// Port clock enable
	switch(pin.portIndex) {
      case 'a' :
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;  
        break;
			case 'b' :
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;  
        break;
			case 'c' :
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;  
        break;
			case 'd' :
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;  
        break;
			case 'e' :
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;  
        break;
			case 'f' :
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;  
        break; 
   }
	
	delay = SYSCTL_RCGCGPIO_R; // Delay
	delay = SYSCTL_RCGCGPIO_R; // Delay
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // Unlock PortF Commit register 

	 
	if (pin.state == INPUT)
	{		  
		GPIO_PORTF_CR_R |= pinMask;          	 
		GPIO_PORTF_AMSEL_R &= ~pinMask;      
		GPIO_PORTF_PCTL_R &= ~pctlPinMask;  
		GPIO_PORTF_AFSEL_R &= ~pinMask;      
		GPIO_PORTF_DIR_R &= ~pinMask;
		GPIO_PORTF_PUR_R |= pinMask;
		GPIO_PORTF_DEN_R |= pinMask;	
	}
	else if (pin.state == OUTPUT)
	{
		GPIO_PORTF_CR_R |= pinMask;          // Allow changes to Pin     
		GPIO_PORTF_AMSEL_R &= ~pinMask;      // Disable analog function
		GPIO_PORTF_PCTL_R &= ~pctlPinMask;  // GPIO clear bit PCTL  
		GPIO_PORTF_AFSEL_R &= ~pinMask;      // No alternate function
		GPIO_PORTF_DIR_R |= pinMask;         // Pin state is output
		GPIO_PORTF_DEN_R |= pinMask;         // Enable digital pins PF4-PF0
		GPIO_PORTF_DATA_R &= ~pinMask;			// Initalize Pin to be off
	}
	
	
	return pin;
}


void setPin(Pin *pin , unsigned char out)
{
	if (pin->state == INPUT) return;
	if (out == 1)
		GPIO_PORTX_DATA_R(pin->portIndex) |= GPIO_PX_M(pin->pinNum);
	else if (out == 0)
		GPIO_PORTX_DATA_R(pin->portIndex) &= ~GPIO_PX_M(pin->pinNum);
}

unsigned char readPin(Pin *pin)
{
	return ((GPIO_PORTX_DATA_R(pin->portIndex) & GPIO_PX_M(pin->pinNum))!=GPIO_PX_M(pin->pinNum));
}
