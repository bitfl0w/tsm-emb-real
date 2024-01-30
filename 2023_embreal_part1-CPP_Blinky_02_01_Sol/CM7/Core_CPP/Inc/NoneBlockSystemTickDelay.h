/*
 * NoneBlockSystemTickDelay.h
 *
 *  Created on: 14.03.2022
 *      Author: dominique.kunz
 */

#ifndef SRC_NONEBLOCKSYSTEMTICKDELAY_H_
#define SRC_NONEBLOCKSYSTEMTICKDELAY_H_

#include "stm32H7xx_hal.h"


class NoneBlockSystemTickDelay {
public:
	NoneBlockSystemTickDelay();
	virtual ~NoneBlockSystemTickDelay();

	void initialise(const uint32_t Delay);
	uint8_t checkExpiration(void);

protected:
	uint32_t Wait = 0;
	uint32_t Tickstart =0;
};


#endif /* SRC_NONEBLOCKSYSTEMTICKDELAY_H_ */
