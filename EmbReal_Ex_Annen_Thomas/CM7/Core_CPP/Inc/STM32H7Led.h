#pragma once
#include "stm32h7xx_hal.h"

class STM32H7Led {
	public:
		GPIO_TypeDef* Port;
		uint16_t Pin;
		STM32H7Led(GPIO_TypeDef* Port, uint16_t Pin);
		STM32H7Led();
		void ToggleLED();
};
