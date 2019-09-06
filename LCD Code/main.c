#include <stdint.h>
#include "PLL.h"
#include "LCD.h"
#include "systick.h"

int main(void){
  uint32_t n;
  PLL_Init();              // set system clock to 50 MHz

  LCD_Init();              // initialize LCD
  n = 0;
  LCD_Clear();
  LCD_OutString("Test LCD");
  SysTick_Wait10ms(100);
  while(1){
    LCD_Clear();
    LCD_OutUDec(n);
    SysTick_Wait10ms(50);
    LCD_OutChar(32);
    LCD_OutUHex(n);
    SysTick_Wait10ms(100);
    if(n%5 == 0{
			
			n++;
  }
}

