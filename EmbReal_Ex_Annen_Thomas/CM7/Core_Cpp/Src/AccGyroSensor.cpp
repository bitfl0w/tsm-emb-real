#include "AccGyroSensor.h"

void AccGyroSensor::InitSensor(void) {
	Acc.Init(INSTANCE, FUNCTION_INIT_ACC_GYRO);
	Acc.Enable(INSTANCE, FUNCTION_INIT_ACC_GYRO);
//	Gyro.Init(INSTANCE, FUNCTION_GYRO);
//	Gyro.Enable(INSTANCE, FUNCTION_GYRO);
	HAL_Delay(100);

	// perform initial readout
	Acc.UpdateValues(INSTANCE, FUNCTION_ACC, false);
	Gyro.UpdateValues(INSTANCE, FUNCTION_GYRO, false);

	Acc.SetZero();
	Gyro.SetZero();
}

void AccGyroSensor::UpdateValues(void) {
	Acc.UpdateValues(INSTANCE, FUNCTION_ACC);
	//Gyro.UpdateValues(INSTANCE, FUNCTION_GYRO);
}

void AccGyroSensor::SetZero(void) {
	Acc.SetZero();
	Gyro.SetZero();
}
