//EE 3450 Term Project
//3x3x3 LED Cube
//Juan Avila and Carlos Ochoa

#include "inc/tm4c123gh6pm.h"
#include <stdio.h>
#include "PLL.h"
#include "SysTick.h"

void GPIO_init(){
	
	SYSCTL_RCGC2_R |= 0x0F;      // 1) Port A-D
 
  GPIO_PORTA_AMSEL_R &= ~0x1C; 
  GPIO_PORTA_PCTL_R &= ~0x00000FFF; 
  GPIO_PORTA_DIR_R |= 0x1C;   
  GPIO_PORTA_AFSEL_R &= ~0x1C; // 6) regular function on PA 2-0
  GPIO_PORTA_DEN_R |= 0x1C;    // 7) enable digital on PA 2-0
	
  GPIO_PORTB_AMSEL_R &= ~0x07; // 3) disable analog function on PB 2-0
  GPIO_PORTB_PCTL_R &= ~0x00FFFFFF; // 4) enable regular GPIO
  GPIO_PORTB_DIR_R |= 0x07;    // 5) outputs on PB 2-0
  GPIO_PORTB_AFSEL_R &= ~0x07; // 6) regular function on PB 2-0
  GPIO_PORTB_DEN_R |= 0x07;    // 7) enable digital on PB 2-0
  
	GPIO_PORTC_AMSEL_R &= ~0x70;
  GPIO_PORTC_PCTL_R &= ~0x0000FFFF; 
  GPIO_PORTC_DIR_R |= 0x70;   
  GPIO_PORTC_AFSEL_R &= ~0x70; 
  GPIO_PORTC_DEN_R |= 0x70;    
	
	GPIO_PORTD_AMSEL_R &= ~0x03; 
  GPIO_PORTD_PCTL_R &= ~0x0000FFFF;
  GPIO_PORTD_DIR_R &= ~0x03;   
  GPIO_PORTD_AFSEL_R &= ~0x03; 
  GPIO_PORTD_DEN_R |= 0x03;    
	
}

int main(void){

	GPIO_init();
	SysTick_Init();

	while(1){
	
	if(GPIO_PORTD_DATA_R == 0x00){
	
		GPIO_PORTA_DATA_R |= 0x1C;
		GPIO_PORTB_DATA_R |= 0x07;
		GPIO_PORTC_DATA_R |= 0x70;
		
	}
	else if (GPIO_PORTD_DATA_R == 0x01){
		GPIO_PORTA_DATA_R |= 0x1C;
		GPIO_PORTB_DATA_R &= ~0x05;
		GPIO_PORTC_DATA_R |= 0x70;
		}	
	else if(GPIO_PORTD_DATA_R  == 0x02){
		
		GPIO_PORTA_DATA_R |= 0x1C;
		GPIO_PORTB_DATA_R &= ~0x02;
		GPIO_PORTC_DATA_R |= 0x70;
		
		}
	else if(GPIO_PORTD_DATA_R == 0x03) {
		GPIO_PORTA_DATA_R |= 0x1C;
		GPIO_PORTB_DATA_R |= 0x03;
		GPIO_PORTB_DATA_R &= ~0x04;
		GPIO_PORTC_DATA_R |= 0x70;
	}
	}
	return 0;
}