#include "RingBuffer.h"
#include <cstdint>
#include <iomanip>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "BlinkingLed.h"
#include <random>
//#include "NonBlockingDelay.h"


void cpp_main() {
	BlinkingLed MyLed1 = BlinkingLed(LD1_GPIO_Port, LD1_Pin, 1/0.25, 50);
	BlinkingLed MyLed2 = BlinkingLed(LD2_GPIO_Port, LD2_Pin, 1/0.5, 50);
	BlinkingLed MyLed3 = BlinkingLed(LD3_GPIO_Port, LD3_Pin, 1/1.0, 50);

	RingBuffer MyBuf = RingBuffer(10);
//	auto LoopCount = 0;
	NonBlockingDelay MyDelay = NonBlockingDelay();
	MyDelay.StartNewDelay(250);

	float Test = 0.23456789f;
	std::uniform_int_distribution<> distribution(1, 100);
	std::random_device rd;  // Non-deterministic random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine
	while(1) {
		//MY CODE STARTS HERE...
		//MY CODE ENDS HERE...
		MyLed1.ProcessBlinking();
		MyLed2.ProcessBlinking();
		MyLed3.ProcessBlinking();

//		if(MyDelay.CheckDelayExpired()) {
//			MyBuf.Append(distribution(gen));
//			std::cout << "Average " << MyBuf.GetAverageCount() << "\r" << std::endl;
//			MyDelay.StartNewDelay(250);
////		}
//		std::cout << "Loop " << std::fixed << std::setprecision(5) << Test << "\r" << std::endl;
//		Test += 1.0;
	}
}

// EOF
