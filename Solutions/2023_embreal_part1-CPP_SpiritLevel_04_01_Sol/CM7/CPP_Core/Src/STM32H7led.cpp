/*
 * STM32H7led.cpp
 *
 *  Created on: Mar 13, 2022
 *      Author: dominique.kunz
 */

#include "STM32H7led.h"

STM32H7_led::STM32H7_led(void) {
	// TODO Auto-generated constructor stub
}

STM32H7_led::STM32H7_led(GPIO_TypeDef *Port,uint16_t Pin) : Port(Port),Pin(Pin)
{
}
//alterantiv
//STM32H7_led::STM32H7_led(GPIO_TypeDef *Port,uint16_t Pin): {
//	STM32H7_led::Port=Port;
//	STM32H7_led::Pin=Pin;
//}

void STM32H7_led::init(GPIO_TypeDef *Port,uint16_t Pin){
    //alternative solution to construction init
    //needed if object is instantiated outside of functions (main and others)
    STM32H7_led::Port=Port;
    STM32H7_led::Pin=Pin;
}

STM32H7_led::~STM32H7_led() {
	// TODO Auto-generated destructor stub
}

void STM32H7_led::toggleLED(void) {
	  HAL_GPIO_TogglePin(Port, Pin);
}

void STM32H7_led::setLED(void){
	  HAL_GPIO_WritePin(Port, Pin, GPIO_PIN_SET);
}

void STM32H7_led::unsetLED(void){
	HAL_GPIO_WritePin(Port, Pin, GPIO_PIN_RESET);
}
