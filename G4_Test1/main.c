#include "RTE_Components.h"
#include CMSIS_device_header
#include "LEDs.h"

//frecuencia en hz a la que va parpadear el led
#define FREQ   50

//variable para contar cuantas vueltas ha dado el bucle while
uint64_t ticks;

uint8_t copy;

int main(void){
	//habilita el reloj del GPIOB y configura el pin del LED como salida
	LEDs_Init();

	//SysTick es un temporizor de 24 bits
	//configura el SysTick para que genere una interrupcion cada 1/FREQ segundos
	SysTick_Config(SystemCoreClock/FREQ);

	//para que el cpu no se quede sin hacer nada, se puede poner un bucle infinito que cuente ticks
	while(1){
		ticks++;
	}
}

//rutina de servcio de la interrupcion del SysTick, se ejecuta cada 1/FREQ segundos
void SysTick_Handler(void){
	// la variable sirve para contar cuantas veces se ha ejecutado la interrupcion
	// static conserva su valor entre llamadas a la funcion
	static uint32_t data;
	data++;
	copy = data;
	//invierte el estado del led cada vez que se ejecuta la interrupcion
	//usando XOR con el registro ODR del GPIOB
	LED_Toggle();
}

