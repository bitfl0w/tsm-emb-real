#include "cpp_main.h"
#include "main.h"

#include "IKS01A3_Motion.h"
#include "printf.h"

uint32_t lastGetTick;

void cpp_main() {
	IKS01A3_Motion MySensor;
	printf("Starting up...\r\n");
	MySensor.Init(IKS01A3_LSM6DSO_0, MOTION_ACCELERO);
	HAL_Delay(500);
	MySensor.Enable(IKS01A3_LSM6DSO_0, MOTION_ACCELERO);
	HAL_Delay(500);
	MySensor.SetZero();
	HAL_Delay(500);
	printf("Init(), Enable() and SetZero() executed.\r\n");
	printf("Starting main loop now.\r\n");

	while(1) {
		// non blocking variant
		if((HAL_GetTick() - lastGetTick) >= 500) {
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			lastGetTick = HAL_GetTick();
			MySensor.UpdateValues(IKS01A3_LSM6DSO_0, MOTION_ACCELERO);
			printf("\r\n");
			MySensor.PrintValuesToConsole();
		}
	}
}
