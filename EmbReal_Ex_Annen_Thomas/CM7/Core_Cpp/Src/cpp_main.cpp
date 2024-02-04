#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "BlinkingLed.h"
#include "AccGyroSensor.h"
#include "EnvSensor.h"

void cpp_main() {
	BlinkingLed MyLed1 = BlinkingLed(LD1_GPIO_Port, LD1_Pin, (1/5.0f), 50);
	uint32_t count = 0;
	AccGyroSensor MyAccGyroSensor;
	MyAccGyroSensor.InitSensor();

	const std::string CRLF = "\r\n";

	EnvSensor MyEnvSensor;
	MyEnvSensor.InitSensor();

	while(1) {
		if(MyLed1.CheckDelayExpired()) {
			MyLed1.ProcessBlinking();
			int32_t XAxis, YAxis, ZAxis;
			MyAccGyroSensor.UpdateValues();

//			std::vector<int32_t, util::ring_allocator<int32_t>> Copy;
//			MyAccGyroSensor.Acc.GetRingBufferAxisZ(&Copy);
//			for(auto iterator = Copy.cbegin(); iterator < Copy.cend(); iterator++) {
//				std::cout << "Value: " << *iterator << CRLF;
//			}
			MyAccGyroSensor.Acc.GetAvgValues(&XAxis, &YAxis, &ZAxis);
			//std::cout << "Toggled Led. Counter: " << count << CRLF;
//			std::cout << "X: " << XAxis << "Y: " << YAxis << "; Z: " << ZAxis << CRLF;
//			count++;

			float Temperature;
			MyEnvSensor.UpdateValues();
			MyEnvSensor.Temp.GetAvgValues(&Temperature);
			std::cout << "Averaged Temp: " << Temperature << CRLF;
		}
	}
}

// EOF
