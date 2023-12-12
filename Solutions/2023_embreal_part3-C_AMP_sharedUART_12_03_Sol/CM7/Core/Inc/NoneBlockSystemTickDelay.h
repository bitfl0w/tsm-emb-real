/*
 * NoneBlockSystemTickDelay.h
 *
 *  Created on: Mar 18, 2022
 *      Author: dominique.kunz
 */

#include <stdint.h>
#include "stm32h7xx_hal.h"

#ifndef INC_NONEBLOCKSYSTEMTICKDELAY_H_
#define INC_NONEBLOCKSYSTEMTICKDELAY_H_

void NoneBlockSystemTickDelay__DelayNoneBlockingInit(uint32_t *DelayNoneBlocking_tickstart, uint32_t *Delay);
uint8_t NoneBlockSystemTickDelay__DelayNoneBlockingCheckExpiration(uint32_t DelayNoneBlocking_tickstart, uint32_t Delay);

#endif /* INC_NONEBLOCKSYSTEMTICKDELAY_H_ */
