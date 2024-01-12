#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "BlinkingLed.h"

extern UART_HandleTypeDef huart3;

void cpp_main() {
	BlinkingLed MyLed1 = BlinkingLed(LD1_GPIO_Port, LD1_Pin, (1/0.25f), 50);
	BlinkingLed MyLed2 = BlinkingLed(LD2_GPIO_Port, LD2_Pin, (1/0.50f), 50);
	BlinkingLed MyLed3 = BlinkingLed(LD3_GPIO_Port, LD3_Pin, (1/1.00f), 50);

//	std::string Info = "Init finished.";
//	HAL_UART_Transmit(&huart3, Info, sizeof(Info), 0xFFFF);
	while(1) {
		MyLed1.ProcessBlinking();
		MyLed2.ProcessBlinking();
		MyLed3.ProcessBlinking();
	}
}

// EOF
