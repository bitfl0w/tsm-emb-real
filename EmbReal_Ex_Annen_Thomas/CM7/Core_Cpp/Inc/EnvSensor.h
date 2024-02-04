#pragma once

#include <cstdint>
#include "IKS01A3_Env.h"

class EnvSensor {
private:
	const uint32_t INSTANCE = 0;
	const uint32_t FUNCTION_INIT_TEMP_HUM = ENV_TEMPERATURE | ENV_HUMIDITY;
	const uint32_t FUNCTION_TEMP = ENV_TEMPERATURE;
	const uint32_t FUNCTION_HUM = ENV_HUMIDITY;

public:
	IKS01A3_Env Temp;
	IKS01A3_Env Hum;

	void InitSensor(void);
	void UpdateValues(void);
	void SetZero(void);
};
