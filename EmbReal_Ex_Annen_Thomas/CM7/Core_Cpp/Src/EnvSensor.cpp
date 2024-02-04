#include "EnvSensor.h"

void EnvSensor::InitSensor(void) {
	Temp.Init(INSTANCE, FUNCTION_INIT_TEMP_HUM);
	Temp.Enable(INSTANCE, FUNCTION_INIT_TEMP_HUM);
	HAL_Delay(100);

	// perform initial readout
	Temp.UpdateValues(INSTANCE, FUNCTION_TEMP, false);
	Hum.UpdateValues(INSTANCE, FUNCTION_HUM, false);
}

void EnvSensor::UpdateValues(void) {
	Temp.UpdateValues(INSTANCE, FUNCTION_TEMP);
	Hum.UpdateValues(INSTANCE, FUNCTION_HUM);
}
