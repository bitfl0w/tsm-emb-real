#include "RingBuffer.h"
#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "BlinkingLed.h"
#include <random>
#include "NonBlockingDelay.h"

void cpp_main() {
	BlinkingLed MyLed1 = BlinkingLed(LD1_GPIO_Port, LD1_Pin, (1/0.50f), 50);
	RingBuffer MyBuf = RingBuffer(10);
//	auto LoopCount = 0;
	NonBlockingDelay MyDelay = NonBlockingDelay();
	MyDelay.StartNewDelay(250);

	std::uniform_int_distribution<> distribution(1, 100);
	std::random_device rd;  // Non-deterministic random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine

	while(1) {
		//MY CODE STARTS HERE...
		//MY CODE ENDS HERE...
		MyLed1.ProcessBlinking();

		if(MyDelay.CheckDelayExpired()) {
			MyBuf.Append(distribution(gen));
			std::cout << "Average " << MyBuf.GetAverageCount() << "\r" << std::endl;
			MyDelay.StartNewDelay(250);
		}
//		std::cout << "Loop " << Counter2 << "\r" << std::endl;
	}
}

// EOF
