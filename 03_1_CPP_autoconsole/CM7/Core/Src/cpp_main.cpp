#include "cpp_main.h"
#include "main.h"
#include "stm32h7xx_hal.h"
#include <string>

extern UART_HandleTypeDef huart3;

void cpp_main() {

	auto incrementMe = UINT8_C(0);
	uint8_t buffer[5];

	while (1) {
		for (; incrementMe < 255; incrementMe++) {
			uint8_t value = incrementMe;

			buffer[2] = (value % 10) + 48;
			value /= 10;
			buffer[1] = (value % 10) + 48;
			value /= 10;
			buffer[0] = (value) + 48;

			// add line break
			buffer[3] = '\r';
			buffer[4] = '\n';
			HAL_UART_Transmit(&huart3, buffer, sizeof(buffer)/sizeof(buffer[0]), 0xFFFF);
			HAL_Delay(250);
		}
	}
}
