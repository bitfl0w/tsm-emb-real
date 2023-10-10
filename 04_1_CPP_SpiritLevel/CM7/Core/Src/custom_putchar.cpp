#include "stm32h7xx_hal.h"

extern UART_HandleTypeDef huart3;

#ifdef __cplusplus
extern "C" {
#endif

// custom implementation of putchar, link it to VCOM
void _putchar(char character) {
	HAL_UART_Transmit(&huart3, (const uint8_t*)&character, 1, 0xFFFF);
}

#ifdef __cplusplus
}
#endif

// EOF
