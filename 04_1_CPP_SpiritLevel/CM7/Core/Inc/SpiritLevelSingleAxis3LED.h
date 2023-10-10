#pragma once

#include <cstdint>
#include "STM32H7Led.h"
#include "AccGyroSensor.h"

class SpiritLevelSingleAxis3LED {
public:
	// constructor
	SpiritLevelSingleAxis3LED();

	// methods declarations
	void Init(void);
	void UpdateValues(void);
	void ShowValues(bool SendToVCP = false);
	void SetZero();

private:
	const int32_t Threshold = 200;
	AccGyroSensor MyAccGyroSensor;
	STM32H7Led LedNegAngle;
	STM32H7Led LedBalanced;
	STM32H7Led LedPosAngle;
};
