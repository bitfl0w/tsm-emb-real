#pragma once

#include <stdint.h>
#include <array>
#include <vector>
#include "util_ring_allocator.h"
#include "stm32h7xx_hal.h"
#include "iks01a3_env_sensors.h"
#include "cpp_main.h"

class IKS01A3_Env {
public:
	static constexpr int ARRAY_SIZE = 10;

	// constructors
	IKS01A3_Env();

	// methods
	void Init(uint32_t p_Instance, uint32_t p_Function);
	void Enable(uint32_t p_Instance, uint32_t p_Function);
	void UpdateValues(uint32_t p_Instance, uint32_t p_Function, bool AddToRingBuffer = true);
	void GetValue(uint32_t p_Instance, uint32_t p_Function, float *p_Value);
	void GetAvgValues(float *p_Value);
	void PrintValuesToConsole();

private:
	float Value;

#ifdef VECTOR_SOLUTION
	std::vector<float> RingBuffer;
#endif
};

