#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "BlinkingLed.h"
#include "AccGyroSensor.h"
#include "EnvSensor.h"
#include <array>
#include <algorithm>

void cpp_main() {
	BlinkingLed MyLed1 = BlinkingLed(LD1_GPIO_Port, LD1_Pin, (1/5.0f), 50);
	AccGyroSensor MyAccGyroSensor;
	MyAccGyroSensor.InitSensor();

	EnvSensor MyEnvSensor;
	MyEnvSensor.InitSensor();

	// array sorting
	std::array<uint32_t, 8> MyArray = { 0, 2, 6, 8, 3, 5, 1, 7 };
	std::cout << "Unsorted container:" << std::endl;
	for(auto i:MyArray) {
	    std::cout << i << " ";
	}
	std::cout << std::endl << std::endl;

	std::sort(std::begin(MyArray), std::end(MyArray));
	std::cout << "Ascending sorted container:" << std::endl;
	for(auto i:MyArray) {
		std::cout << i << " ";
	}
	std::cout << std::endl << std::endl;

	std::sort(std::begin(MyArray), std::end(MyArray), std::greater<uint32_t>());
	std::cout << "Descending sorted container:" << std::endl;
	for(auto i:MyArray) {
		std::cout << i << " ";
	}
	std::cout << std::endl << std::endl;

	while(1) {
		if(MyLed1.CheckDelayExpired()) {
			MyLed1.ProcessBlinking();
			int32_t XAxis, YAxis, ZAxis;
			MyAccGyroSensor.UpdateValues();
			MyAccGyroSensor.Acc.GetAvgValues(&XAxis, &YAxis, &ZAxis);

			float Temperature;
			MyEnvSensor.UpdateValues();
			MyEnvSensor.Temp.GetAvgValues(&Temperature);
			std::cout << "Averaged Temp: " << Temperature << std::endl;
		}
	}
}

// EOF
