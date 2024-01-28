#pragma once

#include "stm32h7xx_hal.h"

class NonBlockingDelay {
public:
	NonBlockingDelay();
	void StartNewDelay(uint16_t p_Delay);
	uint8_t CheckDelayExpired();
protected:
	uint16_t m_DesiredDelay;
	uint32_t m_InitialSysTick;
};
