/*
 * SpiritLevelSinglAxis3LED.h
 *
 *  Created on: Mar 25, 2022
 *      Author: dominique.kunz
 */

#ifndef SRC_SPIRITLEVELSINGLAXIS3LED_H_
#define SRC_SPIRITLEVELSINGLAXIS3LED_H_

#include "AccGyroSensor.h"
#include "stm32H7xx_hal.h"
#include "STM32H7led.h"

class SpiritLevelSinglAxis3LED {
private:
    const int32_t Threshold=200;
    AccGyroSensor AccSensor;
    STM32H7_led LedNegAngle;
    STM32H7_led LedBalanced;
    STM32H7_led LedPosAngle;

public:
	SpiritLevelSinglAxis3LED();
	virtual ~SpiritLevelSinglAxis3LED();
    void init(void);
    void updateValues(void);
    void show(void);
    void setZero(void);
};

#endif /* SRC_SPIRITLEVELSINGLAXIS3LED_H_ */
