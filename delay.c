#include "delay.h"


volatile uint32_t myTicks;

void SysTick_Handler(void) {
  myTicks++;                                     /* increment timeTicks counter */
}

void Delay (uint32_t dlyTicks, uint32_t type) {
  SysTick_Config (SystemCoreClock / type);
  while (myTicks < dlyTicks);
  myTicks = 0;
}