#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "BlinkingLed.h"

void cpp_main() {
//	constexpr uint16_t c_Delay = 500;
//	NoneBlockSystemTickDelay MyDelay;
//	MyDelay.StartNewDelay(c_Delay);

	BlinkingLed MyLed1 = BlinkingLed(LD1_GPIO_Port, LD1_Pin, (1/0.25f), 50);
	BlinkingLed MyLed2 = BlinkingLed(LD2_GPIO_Port, LD2_Pin, (1/0.50f), 50);
	BlinkingLed MyLed3 = BlinkingLed(LD3_GPIO_Port, LD3_Pin, (1/1.00f), 50);

	while(1) {
		MyLed1.ProcessBlinking();
		MyLed2.ProcessBlinking();
		MyLed3.ProcessBlinking();


//		if(MyDelay.CheckDelayExpired()) {
//			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
//			MyDelay.StartNewDelay(c_Delay);
//		}


	}
}

// EOF
