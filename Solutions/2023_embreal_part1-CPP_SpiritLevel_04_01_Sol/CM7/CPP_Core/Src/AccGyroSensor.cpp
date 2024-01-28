/*
 * AccGyroSensor.cpp
 *
 *  Created on: Mar 25, 2022
 *      Author: dominique.kunz
 */

#include "AccGyroSensor.h"

AccGyroSensor::AccGyroSensor() {
	// TODO Auto-generated constructor stub

}

AccGyroSensor::~AccGyroSensor() {
	// TODO Auto-generated destructor stub
}

void AccGyroSensor::initSensor(void){
    AccGyroSensor::Gyro.init(INSTANCE, MOTION_ACCELERO|MOTION_GYRO);
}

void AccGyroSensor::updateValues(void){
	Gyro.updateValues(INSTANCE, FUNCTION_GYRO);
	Acc.updateValues(INSTANCE, FUNCTION_ACC);
}

void AccGyroSensor::setZero(void ) {
    Acc.setZero();
    Gyro.setZero();
}
