#pragma once

#include <cstdint>
#include "STM32H7Led.h"
#include "NonBlockingDelay.h"

class BlinkingLed : protected STM32H7Led, public NonBlockingDelay {
public:
	void SetDutyCycle(uint8_t DutyCycle);

	uint8_t getDutyCycle() const {
		return DutyCycle;
	}

	void setDutyCycle(uint8_t dutyCycle) {
		DutyCycle = dutyCycle;
	}

	float getFrequency() const {
		return Frequency;
	}

	void setFrequency(float frequency) {
		Frequency = frequency;
	}

	void ProcessBlinking();
	BlinkingLed(GPIO_TypeDef* Port, uint16_t Pin, float Frequency, uint8_t DutyCycle);
	BlinkingLed(GPIO_TypeDef* Port, uint16_t Pin);
private:
	float Frequency;
	uint8_t DutyCycle;
};
