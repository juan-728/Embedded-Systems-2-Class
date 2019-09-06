#include <stdint.h>

void Stepper_Init(void);
//Move 1.8 degrees clockwise
// delay is the time to wait after each step in the bys cycles
void Stepper_CW(uint32_t delay);
//Move 1.8 degrees counterclockwise,
//Delay is the time to wait after each step in bus cycles

void Stepper_CCW(uint32_t delay);
//Turn stepper motor to desired position
//(0 <= desired <= 199)
// time is the nbumber of bus cycles to wait 
void Stepper_Seej(uint8_t desired, uint32_t time);
