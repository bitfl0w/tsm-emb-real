/*
 * BlinkingLed.h
 *
 *  Created on: 14.03.2022
 *      Author: dominique.kunz
 */

#ifndef SRC_BLINKINGLED_H_
#define SRC_BLINKINGLED_H_
#include "STM32H7led.h"
#include "NoneBlockSystemTickDelay.h"
#include <cstdint>

class BlinkingLed: protected myhal::STM32H7_led, myhal::NoneBlockSystemTickDelay{
public:
	BlinkingLed();
	BlinkingLed( GPIO_TypeDef *Port, uint16_t Pin);
	virtual ~BlinkingLed();
	void setDutyCycle(const uint8_t DutyCycle);
	void setFrequency(const float Frequency);
	void processBlinking(void);
	void setPinPort( GPIO_TypeDef *Port, uint16_t Pin);

private:
	float Frequency = 1.0;
	uint8_t DutyCycle =50;
};


#endif /* SRC_BLINKINGLED_H_ */
