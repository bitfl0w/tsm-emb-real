#include "AccGyroSensor.h"
#include "IKS01A3_Motion.h"

AccGyroSensor::AccGyroSensor() {
	Acc	 = IKS01A3_Motion::IKS01A3_Motion(FUNCTION_ACC, INSTANCE);
	Gyro = IKS01A3_Motion::IKS01A3_Motion(FUNCTION_GYRO, INSTANCE);
}

void AccGyroSensor::InitSensor(void) {
	Acc.Init();
	Acc.Enable();
//	Gyro.Init(INSTANCE, FUNCTION_GYRO);
//	Gyro.Enable(INSTANCE, FUNCTION_GYRO);
	HAL_Delay(100);

	// perform initial readout
	Acc.UpdateValues(false);
	Gyro.UpdateValues(false);

	Acc.SetZero();
	Gyro.SetZero();
}

void AccGyroSensor::UpdateValues(void) {
	Acc.UpdateValues();
	Gyro.UpdateValues();
}

void AccGyroSensor::SetZero(void) {
	Acc.SetZero();
	Gyro.SetZero();
}
