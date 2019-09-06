#include "inc/tm4c123gh6pm.h"

void delay(){
	while((GPIO_PORTE_DATA_R &0x09) == 0x01){
	GPIO_PORTE_DATA_R ^= 0x04;
		int i = 1000000;
		while(i>0)
			i--;
	}
}

	void wait(){
		int j = 1000000;
		while (j>0)
			j--;
	}

void init () {
	SYSCTL_RCGC2_R = 0x10; //Activates Port E
	
	GPIO_PORTE_DIR_R |= 0x06; //output PE 2-1
	GPIO_PORTE_DIR_R &=  ~0x09; //PE0 and PE3 are inputs
	GPIO_PORTE_AMSEL_R &= ~0x0F;// No analog feature
	GPIO_PORTE_AFSEL_R &= ~0x0F;//No alternative feature
	GPIO_PORTE_DEN_R |= 0x0F;//Digital Enable
	
}

int main(void){
	init();
	wait();
	GPIO_PORTE_DATA_R |= 0x02;
	wait();
		GPIO_PORTE_DATA_R |= 0x04;
	wait();
	
	
	

	while(1){
		if((GPIO_PORTE_DATA_R &0x09) == 0x00){
			GPIO_PORTE_DATA_R |= 0x06;
		}
				else if((GPIO_PORTE_DATA_R &0x09) == 0x08){
			GPIO_PORTE_DATA_R |= 0x02;
			GPIO_PORTE_DATA_R &= ~0x04;
		
	}
		else if((GPIO_PORTE_DATA_R &0x09) == 0x01){
			GPIO_PORTE_DATA_R |= 0x04;
			GPIO_PORTE_DATA_R &= ~0x02;
			delay();
		}
else{
	wait();
	GPIO_PORTE_DATA_R |= 0x02;
	wait();
		GPIO_PORTE_DATA_R |= 0x04;
	wait();
		}
	}
}



