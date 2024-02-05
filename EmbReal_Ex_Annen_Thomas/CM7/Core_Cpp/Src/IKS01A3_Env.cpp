#include <algorithm>	// for std::rotate
#include <numeric> 		// for std::accumulate
#include <iostream> 	// for cout
#include "IKS01A3_Env.h"

// constructor
IKS01A3_Env::IKS01A3_Env() {
	// initialize the ringbuffer
	std::fill(std::begin(RingBuffer), std::end(RingBuffer), 0.0f);
	std::fill(std::begin(RingBufferInt32), std::end(RingBufferInt32), 0);
}

// public method definitions
void IKS01A3_Env::Init(uint32_t p_Instance, uint32_t p_Function) {
	IKS01A3_ENV_SENSOR_Init(p_Instance, p_Function);
}

void IKS01A3_Env::Enable(uint32_t p_Instance, uint32_t p_Function) {
	IKS01A3_ENV_SENSOR_Enable(p_Instance, p_Function);
}


void IKS01A3_Env::UpdateValues(uint32_t p_Instance, uint32_t p_Function, bool AddToRingBuffer) {
	IKS01A3_ENV_SENSOR_GetValue(p_Instance, p_Function, &Value);
	if(AddToRingBuffer) {
		static uint32_t count;
#ifdef VECTOR_SOLUTION
		if(RingBuffer.size() >= ARRAY_SIZE) {
			RingBuffer.erase(RingBuffer.begin());
			RingBufferInt32.erase(RingBufferInt32.begin());
		}
		RingBuffer.push_back(Value);
		RingBufferInt32.push_back(count);
		count++;

		std::cout << "Current Buffer Content:\r\n";
		uint32_t Position = 0;
		for(auto iterator = RingBuffer.cbegin(); iterator < RingBuffer.cend(); iterator++) {
			std::cout << "float Idx " << Position << ": " << *iterator << "\r\n";
			Position++;
		}

		Position = 0;
		for(auto iterator = RingBufferInt32.cbegin(); iterator < RingBufferInt32.cend(); iterator++) {
			std::cout << "int32_t Idx " << Position << ": " << *iterator << "\r\n";
			Position++;
		}
#endif
	}
}

void IKS01A3_Env::GetAvgValues(float *p_Value) {
	*p_Value = (float)std::accumulate(RingBuffer.begin(), RingBuffer.end(), 0.0f) / RingBuffer.size();
}

void IKS01A3_Env::PrintValuesToConsole() {
	std::cout << "Temperature: " << Value << "\r\n";
}
