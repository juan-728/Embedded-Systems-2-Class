#include "inc/tm4c123gh6pm.h"

/*
Color Code: 
0x02		//Red
0x28		//Green
0x24		//Blue
0x0E		//White
*/

int main(void){
	////initialize Ports & Pins/////
	SYSCTL_RCGC2_R = 0x02; 					// activate PF
	int delay = SYSCTL_RCGC2_R;			//waste time ==> delay ==>
																	//stabalize ports
	GPIO_PORTB_DIR_R |= 0X0E;				//PF1 becomes output
	GPIO_PORTB_AMSEL_R &= ~0x0E;		//no analog feature for PF1
	GPIO_PORTB_AFSEL_R &= ~0x0E;		//no alternative features for PF1
	GPIO_PORTB_DEN_R |= 0X0E;				//Enable digital feature for PF1
	
	while(1){
		int i = 1000000;
		GPIO_PORTB_DATA_R ^= 0X0E;		//Turn on LED
		while(i >= 1){
			i--;
		}
	}
	////////////////////////////////
	
	return 0; 
}