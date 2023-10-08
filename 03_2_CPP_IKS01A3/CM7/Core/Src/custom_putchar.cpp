#include "stm32h7xx_hal.h"

#pragma once

extern UART_HandleTypeDef huart3;

#ifdef __cplusplus
extern "C" {
#endif

// custom implementation of putchar, link it to VCOM
void _putchar(char character) {
	const uint8_t* tmp = (const uint8_t*)&character;
	HAL_UART_Transmit(&huart3, tmp, 1, 0xFFFF);
}

#ifdef __cplusplus
}
#endif

// EOF
