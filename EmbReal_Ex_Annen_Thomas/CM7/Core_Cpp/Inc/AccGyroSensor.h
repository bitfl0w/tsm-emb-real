#pragma once

#include <cstdint>
#include "IKS01A3_Motion.h"

class AccGyroSensor {
private:
	const uint32_t INSTANCE = 0;
	const uint32_t FUNCTION_INIT_ACC_GYRO = MOTION_ACCELERO | MOTION_GYRO; // initialize both!
	const uint32_t FUNCTION_ACC = MOTION_ACCELERO;
	const uint32_t FUNCTION_GYRO = MOTION_GYRO;

public:
	IKS01A3_Motion Gyro;
	IKS01A3_Motion Acc;

	void InitSensor(void);
	void UpdateValues(void);
	void SetZero(void);
};
