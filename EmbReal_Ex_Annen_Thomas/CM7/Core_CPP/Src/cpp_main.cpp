#include "RingBuffer.h"
#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "BlinkingLed.h"
#include <random>


void cpp_main() {
	BlinkingLed MyLed1 = BlinkingLed(LD1_GPIO_Port, LD1_Pin, (1/0.25f), 50);
	RingBuffer MyBuf = RingBuffer(10);
	auto LoopCount = 0;

	std::uniform_int_distribution<> distribution(1, 100);
	std::random_device rd;  // Non-deterministic random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine

	while(1) {
		//MY CODE STARTS HERE...
		//MY CODE ENDS HERE...
		MyLed1.ProcessBlinking();
		MyBuf.Append(distribution(gen));
		std::cout << "Average " << MyBuf.GetAverageCount() << "\r" << std::endl;
//		std::cout << "Loop " << Counter2 << "\r" << std::endl;
	}
}

// EOF
