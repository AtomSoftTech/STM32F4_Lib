#ifndef DELAY_H
#define DELAY_H

#include "stm32f4xx.h"

#define SystemCoreClock 168000000
#define Cycle  SystemCoreClock
#define Micro  1000000
#define Milli  1000
#define Second 1


extern volatile uint32_t myTicks;

void SysTick_Handler(void) ;
void Delay (uint32_t dlyTicks, uint32_t type);

#endif