#include "cpp_main.h"
#include "main.h"

uint32_t lastGetTick;


void cpp_main() {
	while(1) {
		// non blocking variant
		if((HAL_GetTick() - lastGetTick) >= 500 ) {
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			lastGetTick = HAL_GetTick();
		}
	}
}
