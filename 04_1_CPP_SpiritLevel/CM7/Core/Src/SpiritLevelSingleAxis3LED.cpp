#include "SpiritLevelSingleAxis3LED.h"
#include "printf.h"
#include "stm32h7xx_hal.h"
#include "main.h"

SpiritLevelSingleAxis3LED::SpiritLevelSingleAxis3LED() :
	LedNegAngle(LD1_GPIO_Port, LD1_Pin),
	LedBalanced(LD2_GPIO_Port, LD2_Pin),
	LedPosAngle(LD3_GPIO_Port, LD3_Pin) {
}

void SpiritLevelSingleAxis3LED::Init(void) {
	MyAccGyroSensor.InitSensor();
}

void SpiritLevelSingleAxis3LED::UpdateValues(void) {
	MyAccGyroSensor.UpdateValues();
}

void SpiritLevelSingleAxis3LED::ShowValues(bool SendToVCP) {
	int32_t xVal, yVal, zVal;
	MyAccGyroSensor.Acc.GetAvgValues(&xVal, &yVal, &zVal);

	IKS01A3_Motion::StatisticalValues_t StatValX;
	IKS01A3_Motion::StatisticalValues_t StatValY;
	IKS01A3_Motion::StatisticalValues_t StatValZ;
	MyAccGyroSensor.Acc.GetStatVal(&StatValX, &StatValY, &StatValZ);

	if(SendToVCP) {
		printf("          : %+07i %+07i %+07i\r\n", xVal, yVal, zVal);
		printf("   ACC Min: %+07i %+07i %+07i\r\n",
				StatValX.find(IKS01A3_Motion::EStatisticalValuesEnum::Min)->second,
				StatValY.find(IKS01A3_Motion::EStatisticalValuesEnum::Min)->second,
				StatValZ.find(IKS01A3_Motion::EStatisticalValuesEnum::Min)->second);
		printf("   ACC Max: %+07i %+07i %+07i\r\n",
				StatValX.find(IKS01A3_Motion::EStatisticalValuesEnum::Max)->second,
				StatValY.find(IKS01A3_Motion::EStatisticalValuesEnum::Max)->second,
				StatValZ.find(IKS01A3_Motion::EStatisticalValuesEnum::Max)->second);
		printf("   ACC Avg: %+07i %+07i %+07i\r\n\r\n",
				StatValX.find(IKS01A3_Motion::EStatisticalValuesEnum::Avg)->second,
				StatValY.find(IKS01A3_Motion::EStatisticalValuesEnum::Avg)->second,
				StatValZ.find(IKS01A3_Motion::EStatisticalValuesEnum::Avg)->second);
	}

	// set spirit level LEDs
	if(yVal > Threshold) {
	        LedNegAngle.SetLed(false);
	        LedBalanced.SetLed(false);
	        LedPosAngle.SetLed(true);
	} else {
		if(yVal < -Threshold) {
			LedNegAngle.SetLed(true);
			LedBalanced.SetLed(false);
			LedPosAngle.SetLed(false);
		} else { // balanced
			LedNegAngle.SetLed(false);
			LedBalanced.SetLed(true);
			LedPosAngle.SetLed(false);
		}
	}

//	MyAccGyroSensor.Gyro.GetAvgValues(&xVal, &yVal, &zVal);
//	if(SendToVCP) {
//		printf("   GYR: %+07i %+07i %+07i\r\n\r\n", xVal, yVal, zVal);
//	}
}

void SpiritLevelSingleAxis3LED::SetZero() {
	MyAccGyroSensor.SetZero();
}
