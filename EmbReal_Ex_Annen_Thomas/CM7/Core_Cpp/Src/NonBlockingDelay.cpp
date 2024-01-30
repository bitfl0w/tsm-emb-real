#include "NonBlockingDelay.h"

NonBlockingDelay::NonBlockingDelay() :
	m_DesiredDelay(0), m_InitialSysTick(0) {
}

void NonBlockingDelay::StartNewDelay(uint16_t p_Delay) {
	m_DesiredDelay = p_Delay;
	m_InitialSysTick = HAL_GetTick();
}

uint8_t NonBlockingDelay::CheckDelayExpired() {
	int32_t currentTickValue = HAL_GetTick();
	return ((currentTickValue - m_InitialSysTick) >= m_DesiredDelay);
}
