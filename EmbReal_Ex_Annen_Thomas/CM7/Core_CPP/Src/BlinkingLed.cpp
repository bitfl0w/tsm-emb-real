#include "BlinkingLed.h"

BlinkingLed::BlinkingLed(GPIO_TypeDef* Port, uint16_t Pin, float Frequency, uint8_t DutyCycle) {
	BlinkingLed::Port = Port;
	BlinkingLed::Pin = Pin;
	BlinkingLed::Frequency = Frequency;
	BlinkingLed::DutyCycle = DutyCycle;


	//StartNewDelay(1000/BlinkingLed::Frequency);
}

BlinkingLed::BlinkingLed(GPIO_TypeDef* Port, uint16_t Pin) {

}

void BlinkingLed::ProcessBlinking() {
	if(CheckDelayExpired()) {
		ToggleLED();
		StartNewDelay((uint16_t)(1000/Frequency));
	}
}
