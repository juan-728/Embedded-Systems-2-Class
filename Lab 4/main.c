#include "inc/tm4c123gh6pm.h"



void init(){
	
	SYSCTL_RCGC2_R |= 0x02; // PORT B
	int delay = SYSCTL_RCGC2_R;
	GPIO_PORTB_DIR_R &= ~ 0x01;
	GPIO_PORTB_DIR_R |= 0x48;
	GPIO_PORTB_AMSEL_R &= ~0x0F;
	GPIO_PORTE_AFSEL_R &= ~0x0F;
	GPIO_PORTE_DEN_R |= 0x48;

}
int main (){
	init();
	
	while (1){
		int temp = (GPIO_PORTB_DATA_R & 0x01);
		temp <<= 3; 
		GPIO_PORTB_DATA_R &= ~0x08;
	
		GPIO_PORTB_DATA_R |= temp;
		
		
	delay();
		
		
			int temp2 = (GPIO_PORTB_DATA_R & 0x01);
			temp2 <<= 6;
			
			GPIO_PORTB_DATA_R &= ~0x40;
			GPIO_PORTB_DATA_R |= (~temp2);
			
	}
}
