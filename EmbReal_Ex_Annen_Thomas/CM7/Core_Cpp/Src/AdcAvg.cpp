/*
 * AdcAvg.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: Thomas
 */

// MY CODE STARTS HERE
#include "AdcAvg.h"


// parameterless constructor
AdcAvg::AdcAvg() {
	// initialize all values to zero
	std::fill(std::begin(MeasValues), std::end(MeasValues), 0.0f);
}

void AdcAvg::SetNewValue(float Value) {
	MeasValues[IndexNextElement] = Value;
	IndexNextElement++;
	IndexNextElement %= ARRAY_SIZE;

	// calculate the average ADC value
	Avg = (float)std::accumulate(MeasValues.begin(), MeasValues.end(), 0.0f) / MeasValues.size();
}

float AdcAvg::GetAvg() {
	return Avg;
}

// MY CODE ENDS HERE
