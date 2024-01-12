#include <vector>
#include <numeric> // for accumulate
#include "util_ring_allocator.h"

#pragma once

class RingBuffer {
public:
	// constructor
	RingBuffer(uint16_t MaxCapacity);

	// members
	std::vector<int32_t, util::ring_allocator<int32_t>> Buffer;
	
	// methods
	uint32_t GetAverageCount() const;
	void Append(uint32_t NewValue);
private:
	uint16_t Capacity;
};
