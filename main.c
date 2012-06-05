#include "stm32f4xx.h"
#include "delay.h"

#define BLUE 15


void LED_Config(void);
void Pin_State(GPIO_TypeDef *port, char pin, char val);

int main (void) {
  SysTick_Config (SystemCoreClock / 1000);
  
  LED_Config();                                  /* configure the LEDs */                            
 
  while(1) {
    Pin_State (GPIOD,BLUE,1);                    
    Delay (250,Milli);                                
    Pin_State (GPIOD,BLUE,0);                         
    Delay (250,Milli);                               
  }
}



void LED_Config(void)
{
  RCC->AHB1ENR = 0xFF; //All GPIO Clock Enabled...

  GPIOD->MODER |= (1 << (BLUE * 2));      //Set to Output
  GPIOD->OTYPER &= !(1 << BLUE);          //Set to Push-Pull
  GPIOD->OSPEEDR |= (0x02 << (BLUE * 2)); //Set Max of 50MHz Speed
  GPIOD->PUPDR &= (0x03 << (BLUE * 2));   //Set it for NO PUPD
}

void Pin_State(GPIO_TypeDef *port, char pin, char val)
{
  if(val) 
    port->BSRRL |= (1<<pin);    //Pin SET
  else
    port->BSRRH |= (1<<pin);    //Pin CLEAR
}