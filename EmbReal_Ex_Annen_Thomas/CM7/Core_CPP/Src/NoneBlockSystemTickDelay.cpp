#include "NoneBlockSystemTickDelay.h"

void NoneBlockSystemTickDelay::StartNewDelay(uint16_t p_Delay) {
	m_DesiredDelay = p_Delay;
	m_InitialSysTick = HAL_GetTick();
}

uint8_t NoneBlockSystemTickDelay::CheckDelayExpired() {
	int32_t currentTickValue = HAL_GetTick();
	return ((currentTickValue - m_InitialSysTick) >= m_DesiredDelay);
}
