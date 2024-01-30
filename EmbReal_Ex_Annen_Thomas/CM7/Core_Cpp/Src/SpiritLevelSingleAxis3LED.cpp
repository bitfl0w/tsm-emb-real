#include "SpiritLevelSingleAxis3LED.h"
#include "stm32h7xx_hal.h"
#include "main.h"
#include <iostream> // for cout

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
	if(SendToVCP) {
		std::cout << "   ACC: " << xVal << "; " << yVal << "; " << zVal << "\r\n";
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

	MyAccGyroSensor.Gyro.GetAvgValues(&xVal, &yVal, &zVal);
	if(SendToVCP) {
		std::cout << "   GYR: " << xVal << "; " << yVal << "; " << zVal << "\r\n";
	}
}

void SpiritLevelSingleAxis3LED::SetZero() {
	MyAccGyroSensor.SetZero();
}
