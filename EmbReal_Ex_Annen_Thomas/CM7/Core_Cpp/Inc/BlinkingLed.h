#include <cstdint>
#include "stm32h7xx_hal.h"
#include "STM32H7Led.h" // we derivate from this class, therefore we need this include!
#include "NonBlockingDelay.h" // dito

#pragma once

class BlinkingLed : public NonBlockingDelay {
private:
	float m_Frequency;
	uint8_t m_DutyCycle;
	STM32H7Led m_STM32H7Led;
public:
	void SetDutyCycle(uint8_t p_DutyCycle);
	void SetFrequency(float p_Frequency);
	void ProcessBlinking();

	// constructors
	BlinkingLed(GPIO_TypeDef* p_Port, uint16_t p_Pin);
	BlinkingLed(GPIO_TypeDef* p_Port, uint16_t p_Pin, float p_Frequency, uint8_t p_DutyCycle);

	uint8_t getMDutyCycle() const {
		return m_DutyCycle;
	}

	void setMDutyCycle(uint8_t mDutyCycle) {
		m_DutyCycle = mDutyCycle;
	}

	float getMFrequency() const {
		return m_Frequency;
	}

	void setMFrequency(float mFrequency) {
		m_Frequency = mFrequency;
	}

	const STM32H7Led& getMStm32H7Led() const {
		return m_STM32H7Led;
	}

	void setMStm32H7Led(const STM32H7Led &mStm32H7Led) {
		m_STM32H7Led = mStm32H7Led;
	}
};
