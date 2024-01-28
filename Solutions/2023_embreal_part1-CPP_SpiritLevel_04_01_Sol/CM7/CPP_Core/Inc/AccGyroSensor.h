/*
 * AccGyroSensor.h
 *
 *  Created on: Mar 25, 2022
 *      Author: dominique.kunz
 */

#ifndef SRC_ACCGYROSENSOR_H_
#define SRC_ACCGYROSENSOR_H_

#include "IKS01A3Motion.h"

class AccGyroSensor {
private:
    const uint32_t INSTANCE=0;
    const uint32_t FUNCTION_INIT_ACC_GYRO=MOTION_ACCELERO|MOTION_GYRO;
    const uint32_t FUNCTION_ACC=MOTION_ACCELERO;
    const uint32_t FUNCTION_GYRO=MOTION_GYRO;

public:
    IKS01A3_Motion Gyro;
    IKS01A3_Motion Acc;
	AccGyroSensor();
	virtual ~AccGyroSensor();
    void initSensor(void);
    void updateValues(void);
    void setZero(void);
};

#endif /* SRC_ACCGYROSENSOR_H_ */
