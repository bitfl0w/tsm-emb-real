/*
 * SpiritLevelSinglAxis3LED.cpp
 *
 *  Created on: Mar 25, 2022
 *      Author: dominique.kunz
 */

#include "SpiritLevelSinglAxis3LED.h"
#include "main.h"
#include <string>
#include "util_ring_allocator_std.h"

#define ASCII_TAB 	(0x09)
#define ASCII_LF 	(0x0A)
#define ASCII_CR	(0x0D)

SpiritLevelSinglAxis3LED::SpiritLevelSinglAxis3LED() {
	// TODO Auto-generated constructor stub

}

SpiritLevelSinglAxis3LED::~SpiritLevelSinglAxis3LED() {
	// TODO Auto-generated destructor stub
}

void SpiritLevelSinglAxis3LED::init(void){
    LedNegAngle.init(LD1_GPIO_Port,LD1_Pin);
    LedBalanced.init(LD2_GPIO_Port,LD2_Pin);
    LedPosAngle.init(LD3_GPIO_Port,LD3_Pin);
    AccSensor.initSensor();
}

void SpiritLevelSinglAxis3LED::updateValues(void){
	AccSensor.updateValues();
}

void SpiritLevelSinglAxis3LED::show(void){
    int32_t AccAvgXAxis=0;
    int32_t AccAvgYAxis=0;
    int32_t AccAvgZAxis=0;
    int32_t AccMinXAxis=0;
    int32_t AccMinYAxis=0;
    int32_t AccMinZAxis=0;
    int32_t AccMaxXAxis=0;
    int32_t AccMaxYAxis=0;
    int32_t AccMaxZAxis=0;

    AccSensor.Acc.getAVGValues(&AccAvgXAxis, &AccAvgYAxis, &AccAvgZAxis);
    AccSensor.Acc.getMinValues(&AccMinXAxis, &AccMinYAxis, &AccMinZAxis);
    AccSensor.Acc.getMaxValues(&AccMaxXAxis, &AccMaxYAxis, &AccMaxZAxis);

    if(AccAvgYAxis>200){
        LedNegAngle.unsetLED();
        LedBalanced.unsetLED();
        LedPosAngle.setLED();

    }
    else {
        if((AccAvgYAxis< (-200))){
            LedNegAngle.setLED();
            LedBalanced.unsetLED();
            LedPosAngle.unsetLED();
        }
        else
        {
            LedNegAngle.unsetLED();
            LedBalanced.setLED();
            LedPosAngle.unsetLED();
        }
    }
float flotter =23.3;
    std::cout<<"TEST"<<flotter<<std::endl;

//	//2. dynamic string class
    auto *PointString = new std::basic_string<char,std::char_traits<char>,util::ring_allocator_std<char>>;
    //auto *PointString = new std::string;
    *PointString=  "Acc.: \t";
    PointString->append( "Y-Axis: ");//+ AccAvgXAxis+ "\tMin: " + AccMinXAxis +"\tMax: "<< AccMaxXAxis;
   // StringObj.append(std::to_string(AccAvgXAxis));
    PointString->append(std::to_string(AccAvgYAxis).c_str());
    PointString->append("\tMin: ");
    PointString->append(std::to_string(AccMinYAxis).c_str());
    PointString->append("\tMax: ");
    PointString->append(std::to_string(AccMaxYAxis).c_str());
    std::cout<<*PointString;
    std::cout<< (char) ASCII_LF << (char) ASCII_CR;
    fflush(stdout);
	delete PointString;
    PointString = nullptr;

}

void SpiritLevelSinglAxis3LED::setZero(void){
    AccSensor.setZero();
}
