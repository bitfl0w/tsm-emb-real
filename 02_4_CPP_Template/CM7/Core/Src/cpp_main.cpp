#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include "stm32h7xx_hal.h"
#include <iostream> // for cout

template<typename T>
float CalculateAverage(const T* p_Memory, const uint8_t p_Size) {
	T sum = 0;
	for(uint8_t i = 0; i < p_Size; i++) {
		sum += p_Memory[i];
	}
	return (float)sum/p_Size;
}

void cpp_main() {
	// fill array with random values
	int16_t myArray[6];
	uint8_t ArraySize = INT8_C(sizeof(myArray)/sizeof(myArray[0]));
	for (uint8_t i = 0; i < ArraySize; i++) {
		myArray[i] = rand();
	}

	float Average = CalculateAverage<int16_t>(&myArray[0], ArraySize);
	std::cout << "The average is" << Average << std::endl;
	// apply template function
	while(1) {
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		HAL_Delay(250);
	}
}

// EOF
