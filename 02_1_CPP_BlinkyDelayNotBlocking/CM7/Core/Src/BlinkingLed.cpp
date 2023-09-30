#include "BlinkingLed.h"

// constructor
BlinkingLed::BlinkingLed(GPIO_TypeDef* p_Port, uint16_t p_Pin, float p_Frequency, uint8_t p_DutyCycle) :
	m_Frequency(p_Frequency),
	m_DutyCycle(p_DutyCycle) {
	m_STM32H7Led = STM32H7Led(p_Port, p_Pin);
	m_NoneBlockSystemTickDelay = NoneBlockSystemTickDelay();

	uint16_t delayTime = UINT16_C(1000.0f/(2 * p_Frequency));
	m_NoneBlockSystemTickDelay.StartNewDelay(delayTime);
}

BlinkingLed::BlinkingLed(GPIO_TypeDef* p_Port, uint16_t p_Pin) : BlinkingLed(p_Port, p_Pin, 0.0f, 0) {
	// we call the fully qualified constructor
}

// method definitions
void BlinkingLed::SetDutyCycle(uint8_t p_DutyCycle) {
	m_DutyCycle = p_DutyCycle;
}

void BlinkingLed::SetFrequency(float p_Frequency) {
	m_Frequency = p_Frequency;
}

void BlinkingLed::ProcessBlinking() {
	if(m_NoneBlockSystemTickDelay.CheckDelayExpired()) {
		m_STM32H7Led.ToggleLed();
	}
}
