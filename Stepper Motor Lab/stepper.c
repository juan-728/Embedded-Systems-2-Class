// Initialize Stepper Interface
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "SysTick.h"

#define STEPPER  (*((volatile uint32_t *)0x4000703C))

struct State{
uint8_t Out;// Output
const struct State *Next[2];// CW/CCW
};

typedef const struct State StateType;
typedef StateType *StatePtr;


#define clockwise 0        // index
#define counterclockwise 1 // Next index

StateType fsm[4]={
{10,{&fsm[1],&fsm[3]}},
{9,{&fsm[2],&fsm[0]}},
{5,{&fsm[3],&fsm[1]}},
{6,{&fsm[0],&fsm[2]}}
};

uint8_t Pos;
const struct State *Pt;

/* STEPPER = LED   SENSOR = SWITCH
 void Stepper_Rotate(uint32_t delay){
   unsigned char input = SENSOR;
   Pt = Pt->Next[input];
   STEPPER = Pt->Out;
   SysTick_Wait(delay);
}
*/

void Stepper_Init(void){
SYSCTL_RCGCGPIO_R |= 0x18;
SysTick_Init();
Pos = 0;
Pt = &fsm[0];
GPIO_PORTD_AMSEL_R &= ~0x0F;
GPIO_PORTD_PCTL_R &= ~0x0000FFFF;
GPIO_PORTD_DIR_R |=0x0F;
GPIO_PORTD_AFSEL_R &= ~0x0F;
GPIO_PORTD_DR8R_R |=0x0F;
GPIO_PORTD_DEN_R |=0x0F;
}



void Stepper_CW(uint32_t delay){
Pt = Pt->Next[clockwise];
STEPPER = Pt->Out;
if(Pos==199){
Pos = 0;
}
else {
Pos++;
}
SysTick_Wait(delay);
}


void Stepper_CCW(uint32_t delay){
Pt = Pt->Next[counterclockwise];
STEPPER = Pt->Out;
if(Pos==0){
Pos = 199;
}
else {
Pos--;
}
SysTick_Wait(delay);
}

void Stepper_Seek(uint8_t desired, uint32_t time){
short CWsteps;
if ((CWsteps = (desired-Pos)) < 0 ){
CWsteps += 200;
}
if(CWsteps>100){
while(desired != Pos){
   Stepper_CCW(time);
}
}
else{
  while(desired != Pos){
  Stepper_CW(time);
  }
}
}

/*
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "SysTick.h"
#define clockwise 0
#define counterclockwise 1



#define STEPPER (*((volatile unsigned long *)0x4000703C))

uint8_t	Pos;
const struct State *Pt; 
struct State{
	uint8_t Out; 
	const struct State *Next[2]; 
}; 

typedef const struct State StateType; 
typedef StateType	*StatePtr; 

StateType fsm[4]={
	{10,{&fsm[1],&fsm[3]}},
	{9,{&fsm[2],&fsm[0]}},
	{5,{&fsm[3],&fsm[1]}},
	{6,{&fsm[0],&fsm[2]}}
};


void Stepper_CW(unsigned long delay){
	Pt = Pt ->Next[clockwise];
	STEPPER = Pt->Out;
	if(Pos ==199){
	Pos = 0;
	}
	else{
		Pos++;
	}
	SysTick_Wait(delay);
}
void Stepper_CCW(unsigned long delay){
	Pt = Pt ->Next[counterclockwise];
	STEPPER = Pt->Out; 
	if(Pos ==199){
	Pos = 0;
	}
	else{
		Pos--;
	}
	SysTick_Wait(delay);
}

void Stepper_Init(void){

SYSCTL_RCGCGPIO_R |= 0x08; // 1) activate port D
SysTick_Init();
Pos = 0;
Pt = &fsm[0];
// 2) no need to unlock PD3-0
GPIO_PORTD_AMSEL_R &= ~0x0F; // 3) disable analog functionality on PD3-0
GPIO_PORTD_PCTL_R &= ~0x0000FFFF; // 4) GPIO configure PD3-0 as GPIO
GPIO_PORTD_DIR_R |= 0x0F; // 5) make PD3-0 out
GPIO_PORTD_AFSEL_R &= ~0x0F; // 6) disable alt funct on PD3-0
GPIO_PORTD_DR8R_R |= 0x0F; // enable 8 mA drive
GPIO_PORTD_DEN_R |= 0x0F; // 7) enable digital I/O on PD3-0 

}


void Stepper_Seek(uint8_t desired, uint32_t time){
short CWsteps;
if((CWsteps = (desired-Pos))<0){
CWsteps+=200;
} // CW steps is 0 to 199
if(CWsteps > 100){
while(desired != Pos){
Stepper_CCW(time);
}
}
else{
while(desired != Pos){
Stepper_CW(time);
		}
	}
}
*/