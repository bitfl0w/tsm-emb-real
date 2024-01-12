#include <cstdint>
#include "stm32h7xx_hal.h"
#include "STM32H7Led.h" // we derivate from this class, therefore we need this include!
#include "NonBlockingDelay.h" // dito

#pragma once

class BlinkingLed: public NonBlockingDelay {
private:
	float m_Frequency;
	uint8_t m_DutyCycle;
	STM32H7Led m_STM32H7Led;
	NonBlockingDelay m_NoneBlockSystemTickDelay;
public:
	void SetDutyCycle(uint8_t p_DutyCycle);
	void SetFrequency(float p_Frequency);
	void ProcessBlinking();

	// constructors
	BlinkingLed(GPIO_TypeDef* p_Port, uint16_t p_Pin);
	BlinkingLed(GPIO_TypeDef* p_Port, uint16_t p_Pin, float p_Frequency, uint8_t p_DutyCycle);
};
