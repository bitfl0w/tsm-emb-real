#include <cstdint>
#include "stm32h7xx_hal.h"

#pragma once

namespace myhal {
	class NoneBlockSystemTickDelay {
	public:
		void StartNewDelay(uint16_t p_Delay);
		uint8_t CheckDelayExpired();
	private:
		uint16_t m_DesiredDelay;
		uint32_t m_InitialSysTick;
	};
}
