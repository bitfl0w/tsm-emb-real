/*
 * STM32H7led.h
 *
 *  Created on: Mar 13, 2022
 *      Author: dominique.kunz
 */

#ifndef SRC_STM32H7LED_H_
#define SRC_STM32H7LED_H_

#include "stm32H7xx_hal.h"


class STM32H7_led {
public:
	STM32H7_led(void);
	STM32H7_led(GPIO_TypeDef *Port,uint16_t Pin);
	virtual ~STM32H7_led();
    void init(GPIO_TypeDef *Port,uint16_t Pin);
	void toggleLED(void);
	void setLED(void);
	void unsetLED(void);
protected:
	GPIO_TypeDef *Port;
	uint16_t Pin;
};

#endif /* SRC_STM32H7LED_H_ */
