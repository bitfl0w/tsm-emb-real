/*
 * STM32H7led.cpp
 *
 *  Created on: Mar 13, 2022
 *      Author: dominique.kunz
 */

#include "STM32H7led.h"

myhal::STM32H7_led::STM32H7_led(void) {
	// TODO Auto-generated constructor stub
}

myhal::STM32H7_led::STM32H7_led(GPIO_TypeDef *Port,uint16_t Pin) {
	// TODO Auto-generated constructor stub
	STM32H7_led::Port=Port;
	STM32H7_led::Pin=Pin;
}


myhal::STM32H7_led::~STM32H7_led() {
	// TODO Auto-generated destructor stub
}

void myhal::STM32H7_led::toggleLED(void) {
	  HAL_GPIO_TogglePin(Port, Pin);
}
