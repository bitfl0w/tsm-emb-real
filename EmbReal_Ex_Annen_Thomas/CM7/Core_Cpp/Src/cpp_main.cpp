#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "BlinkingLed.h"
#include "AccGyroSensor.h"

void cpp_main() {
	BlinkingLed MyLed1 = BlinkingLed(LD1_GPIO_Port, LD1_Pin, (1/0.50f), 50);
	uint32_t count = 0;
	const std::string CRLF = "\r\n";
	AccGyroSensor MyAccGyroSensor;
	MyAccGyroSensor.InitSensor();


	while(1) {
		if(MyLed1.CheckDelayExpired()) {
			MyLed1.ProcessBlinking();
			MyAccGyroSensor.UpdateValues();
			int32_t xAxis, yAxis, zAxis;
			MyAccGyroSensor.Acc.GetValue(&xAxis, &yAxis, &zAxis);
			std::cout << "Toggled Led. Counter: " << count << CRLF;
			count++;
		}
	}
}

// EOF
