/*
 * BlinkingLed.cpp
 *
 *  Created on: 14.03.2022
 *      Author: dominique.kunz
 */

#include "BlinkingLed.h"
#include <array>
#include <algorithm>

BlinkingLed::BlinkingLed(GPIO_TypeDef *Port, uint16_t Pin) {
	// TODO Auto-generated constructor stub
	BlinkingLed::Port=Port;
	BlinkingLed::Pin=Pin;
}

BlinkingLed::~BlinkingLed() {
	// TODO Auto-generated destructor stub
}

void BlinkingLed::setDutyCycle(const uint8_t DutyCycle){
	BlinkingLed::DutyCycle=DutyCycle;
}
void BlinkingLed::setFrequency(const float Frequency){
	BlinkingLed::Frequency=Frequency;
}
void BlinkingLed::processBlinking(void){
	if(BlinkingLed::checkExpiration())
	  {
		BlinkingLed::initialise(1/Frequency*1000);
		BlinkingLed::toggleLED();
	  }

}

