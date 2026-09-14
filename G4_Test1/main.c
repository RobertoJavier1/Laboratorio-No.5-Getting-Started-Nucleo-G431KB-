#include "RTE_Components.h"
#include CMSIS_device_header
#include "USART.h"



int main(void){
	
	USART_config(115200);
	
	USART_putString("\n\r         Proyecto Final Microprocesadores 2022       \n\r");
	USART_putString("                    Programa Monitor                 \n\r");
	USART_putString("                      Julio Fajardo                  \n\r\n\r");
	USART_putString(">> ");
	
	while(1){
		if(cmd_ready){
			USART_putString("\n\rUn comando ha llegado!!!\n\r");
			cmd_ready = 0;
		}
	}
}


