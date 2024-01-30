/*
 * RingBufExample.cpp
 *
 *  Created on: Jan 12, 2024
 *      Author: Thomas
 */

#include "RingBuffer.h"

// constructor
RingBuffer::RingBuffer(uint16_t MaxCapacity) {
	Capacity = MaxCapacity;

	std::fill(Buffer.begin(), Buffer.end(), 0);
}

// add new value
void RingBuffer::Append(uint32_t NewValue) {
	if(Buffer.size() >= Capacity) {
		Buffer.erase(Buffer.begin());
	}
	Buffer.push_back(NewValue);
}

uint32_t RingBuffer::GetAverageCount() const {
	uint32_t sum = 0;
	if(!Buffer.empty()) {  // always check if vector is empty!
		sum = std::accumulate(Buffer.begin(), Buffer.end(), 0);
		return sum / Buffer.size();
	} else {
	    return 0;
	}
}
