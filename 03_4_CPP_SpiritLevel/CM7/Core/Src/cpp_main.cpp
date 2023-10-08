#include "cpp_main.h"
#include "main.h"
#include "SpiritLevelSingleAxis3LED.h"
#include "printf.h"

uint32_t lastGetTick;

void cpp_main() {
	SpiritLevelSingleAxis3LED MySensorLevel;
	printf("Starting up sensor level...\r\n");
	MySensorLevel.Init();
	HAL_Delay(250);
	printf("Starting main loop now.\r\n");

	bool ButtonPressed = false;
	bool ButtonPressedOld = false;

	while(1) {
		// detect sensor pressing
		GPIO_PinState ButtonState = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
		if(ButtonState == GPIO_PIN_SET) {
			ButtonPressed = true;
		} else {
			ButtonPressed = false;
		}
		if(ButtonPressed & !ButtonPressedOld) {
			MySensorLevel.SetZero();
		}

		// update delay
		if((HAL_GetTick() - lastGetTick) >= 50) {
			lastGetTick = HAL_GetTick();

			MySensorLevel.UpdateValues();
			MySensorLevel.ShowValues(true);		// send to VCP
		}

		// save previous button state
		ButtonPressedOld = ButtonPressed;
	}
}
