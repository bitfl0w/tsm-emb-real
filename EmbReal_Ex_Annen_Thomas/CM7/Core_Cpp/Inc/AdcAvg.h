/*
 * AdcAvg.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Thomas
 */

// MY CODE STARTS HERE
#pragma once

// includes
#include <array>
#include <algorithm>
#include <numeric>

// class declaration
class AdcAvg {
public:
	static constexpr int ARRAY_SIZE = 10; // to improve maintainability

	// parameterless constructor
	AdcAvg();
	void SetNewValue(float Value);
	float GetAvg();

private:
	std::array<uint32_t, ARRAY_SIZE> MeasValues;
	uint8_t IndexNextElement = 0;
	float Avg = 0.0f;
};

// MY CODE ENDS HERE
