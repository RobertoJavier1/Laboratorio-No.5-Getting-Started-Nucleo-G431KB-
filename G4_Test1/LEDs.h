/* Universidad Galileo
 * Turing Research Lab
 * Julio E. Fajardo
 * Microprocesadores 2020
 * LED Driver
 * Aug-08-2020
 * LEDs.h
 */

#ifndef LEDS_H_
#define LEDS_H_

#include <stdint.h>

void LEDs_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif /* LEDS_H_ */
