#include "NoneBlockSystemTickDelay.h"

void myhal::NoneBlockSystemTickDelay::StartNewDelay(uint16_t p_Delay) {
	m_DesiredDelay = p_Delay;
	m_InitialSysTick = HAL_GetTick();
}

uint8_t myhal::NoneBlockSystemTickDelay::CheckDelayExpired() {
	int32_t currentTickValue = HAL_GetTick(); // just to simplify debugging
	return ((currentTickValue - m_InitialSysTick) >= m_DesiredDelay);
}
