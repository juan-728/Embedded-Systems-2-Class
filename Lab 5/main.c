#include "inc/tm4c123gh6pm.h"

/*
While system is running, counter counts up.
When system turns on, counter begins counting from 0.
System's counts 0, 1, ... to 9 and then repeats.
*/


void SysTick_init(void){
	
	NVIC_ST_CTRL_R = 0x00;				//Disable CTRL
	NVIC_ST_RELOAD_R = 0xFF; 			//Load max
	NVIC_ST_CURRENT_R = 0x00;			// Clear current value

	NVIC_ST_CTRL_R = 0x05;				// Enable Timer

}

int main(void){
	SYSCTL_RCGC2_R = 0x02; 				//Port B
	
	GPIO_PORTB_DIR_R |= 0xFF; 		//output PB 0-7
	GPIO_PORTB_AMSEL_R &= ~0xFF;	// Enabled?
	GPIO_PORTB_AFSEL_R &= ~0xFF;	// Enabled? 
	GPIO_PORTB_DEN_R |= 0xFF;
	
	while(1){
			SysTick_init(); 
		GPIO_PORTB_DATA_R = 0xF7; 	//turn on all LED , 0xF7: all on except decimal point

	}
	
}
	
