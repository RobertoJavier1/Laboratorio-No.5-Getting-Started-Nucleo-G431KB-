/* Universidad Galileo
 * Turing Research Lab
 * Julio E. Fajardo
 * CMSIS-DSP Application
 * LED Driver
 * Aug-08-2020
 * LEDs.c
 */

#include "RTE_Components.h"
#include CMSIS_device_header
#include "LEDs.h"

/* 0 - STM32F3-EVALBOARD
	 1 - STM32F3-DISCOVERY
	 2 - NUCLEO-F303K8
	 3 - NUCLEO-F303RE
	 4 - NUCLEO-G431KB
*/

#define TARGET 4	

const uint32_t leds_mask[] = { 1<<13, 1<<13, 1<<3, 1<<5, 1<<8 };

// LEDs Initialization
void LEDs_Init(void){
	#if ((TARGET == 0)||(TARGET == 1))
			RCC->AHBENR |= RCC_AHBENR_GPIOEEN;		// GPIOE Clock Enable
			GPIOE->MODER |= (1<<26);
			GPIOE->ODR &= ~(1<<13);
	#elif (TARGET == 2)		
			RCC->AHBENR |= RCC_AHBENR_GPIOBEN;		// GPIOB Clock Enable
			GPIOB->MODER &= ~(1<<7);			
			GPIOB->MODER |= (1<<6);
			GPIOB->ODR &= ~(1<<9);
	#elif (TARGET == 3)		
			RCC->AHBENR |= RCC_AHBENR_GPIOAEN;		// GPIOE Clock Enable
			GPIOA->MODER |= (1<<10);
			GPIOA->ODR &= ~(1<<5);	
	#elif (TARGET == 4)	
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;		// GPIOB Clock Enable
			GPIOB->MODER &= ~(1<<17);
			GPIOB->MODER |= (1<<16);
			GPIOB->ODR &= ~(1<<8);
			
	#endif	
}

// Turn OFF LED, receives as argument the led number (0 is G, 1 is Y, 2 is R and 3 is B)
void LED_Off(void){
	#if((TARGET==0)||(TARGET==1))
	GPIOE->ODR |= leds_mask[TARGET];
	#elif (TARGET==2)
	GPIOB->ODR |= leds_mask[TARGET];
	#elif (TARGET==3)
	GPIOA->ODR |= leds_mask[TARGET];
	#elif (TARGET==4)
	GPIOB->ODR &= ~leds_mask[TARGET];
	#endif
}

// Turn ON LED, receives as argument the led number (0 is G, 1 is Y, 2 is R and 3 is B)
void LED_On(void){
	#if((TARGET==0)||(TARGET==1))
	GPIOE->ODR &= ~leds_mask[TARGET];
	#elif (TARGET==2)
	GPIOB->ODR &= ~leds_mask[TARGET];
	#elif(TARGET==3)
	GPIOA->ODR &= ~leds_mask[TARGET];
	#elif(TARGET==4)
	GPIOB->ODR |= leds_mask[TARGET];
	#endif
}

// LED Toggle, receives as argument the led number (0 is G, 1 is Y, 2 is R and 3 is B)
void LED_Toggle(void){
	#if((TARGET==0)||(TARGET==1))
	GPIOE->ODR ^= leds_mask[TARGET];
	#elif(TARGET==2)
	GPIOB->ODR ^= leds_mask[TARGET];
	#elif(TARGET==3)
	GPIOA->ODR ^= leds_mask[TARGET];
	#elif(TARGET==4)
	GPIOB->ODR ^= leds_mask[TARGET];
	#endif
}


