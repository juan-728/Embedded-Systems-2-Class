#include "Inc/tm4c123gh6pm.h"

void init(){
//////// initialize Ports & Pins//////
	SYSCTL_RCGC2_R = 0x02;  // Activate Port
	int delay = SYSCTL_RCGC2_R;  // waste time ==> delay==>
	
	GPIO_PORTB_DIR_R |= 0x03;   // PF1 is output
	GPIO_PORTB_AMSEL_R &= ~0x03;  // no analog feature ofr PF1
	GPIO_PORTB_AFSEL_R &= ~0x03; // No alternative features for PF1
	GPIO_PORTB_DEN_R |= 0x03; //Enable digital feature for PF1
}
/*void delay(){
	int i = 100000;
	while (i>0){
		i--;
	}
	}*/
int main(void) {
	init();
	while(1){
		
		GPIO_PORTB_DATA_R |= 0x01;  //LED1
		GPIO_PORTB_DATA_R |= 0x02;	//LED2
		//delay(); //BUY ME A TECATE

	}
	/*
	Code
	0x02 = red
	0x28 = green
	0x24 = blue
	*/
	
	///////////////////////////////////////////
	 
	return 0;
	
}




/*
void init() {
/////initialize Ports & Pins///
SYSCTL_RCGC2_R = 0x20; //activate PF
int delay = SYSCTL_RCGC2_R; //waste time ==> delay ==>
//stablize ports
GPIO_PORTF_DIR_R |= 0x0E; //PF1 is output
GPIO_PORTF_AMSEL_R &= ~0x0E; //no analog feature for PF1
GPIO_PORTF_AFSEL_R &= ~0x0E; //no alterntaive features for PF1
GPIO_PORTF_DEN_R |= 0x0E; //Enable digital feature for PF1
}
void delay(){
int i = 1000000;
while(i >= 1) {
i--;
	}
}
int main(void) {
init();
while(1){
GPIO_PORTF_DATA_R ^= 0x0E;
	delay();
}

return 0;
}




/*
int main(){
	SYSCTL_RCGC2_R = 0x20;					//activate PF
	int delay = SYSCTL_RCGC2_R;			// delay
	GPIO_PORTF_DIR_R |= 0X02;				//PF1 is output
	GPIO_PORTF_AMSEL_R &=~ 0x02;		//Clear Analog Feature
	GPIO_PORTF_AFSEL_R &=~ 0x02;		//Clear Alternative Feature
	GPIO_PORTF_DEN_R |= 0x02;				//Enable Digital Feature
	
	while(1){
		GPIO_PORTF_DATA_R |= 0x02;
		
	}
		return(0);
		
}
*/
*/