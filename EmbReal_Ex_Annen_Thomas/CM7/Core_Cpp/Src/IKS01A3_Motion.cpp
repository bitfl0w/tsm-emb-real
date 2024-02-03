#include <algorithm>	// for std::rotate
#include <numeric> 		// for std::accumulate
#include "IKS01A3_Motion.h"
#include <iostream> // for cout

// constructor
IKS01A3_Motion::IKS01A3_Motion() {
	AxisValues.x = 0;
	AxisValues.y = 0;
	AxisValues.z = 0;
	AxisOffsets.x = 0;
	AxisOffsets.y = 0;
	AxisOffsets.z = 0;

	// initialize the ringbuffer
	std::fill(std::begin(RingBufferAxisX), std::end(RingBufferAxisX), 0);
	std::fill(std::begin(RingBufferAxisY), std::end(RingBufferAxisY), 0);
	std::fill(std::begin(RingBufferAxisZ), std::end(RingBufferAxisZ), 0);
}

// public method definitions
void IKS01A3_Motion::Init(uint32_t p_Instance, uint32_t p_Function) {
	IKS01A3_MOTION_SENSOR_Init(p_Instance, p_Function);
}

void IKS01A3_Motion::Enable(uint32_t p_Instance, uint32_t p_Function) {
	IKS01A3_MOTION_SENSOR_Enable(p_Instance, p_Function);
}

void IKS01A3_Motion::SetZero(void) {
	AxisOffsets.x = -AxisValues.x;
	AxisOffsets.y = -AxisValues.y;
	AxisOffsets.z = -AxisValues.z;
}

void IKS01A3_Motion::UpdateValues(uint32_t p_Instance, uint32_t p_Function, bool AddToRingBuffer) {
	IKS01A3_MOTION_SENSOR_Axes_t NewAxisValues;
	IKS01A3_MOTION_SENSOR_GetAxes(p_Instance, p_Function, &NewAxisValues);

	// add offset values before putting values to ringbuffer
	AxisValues.x = NewAxisValues.x + AxisOffsets.x;
	AxisValues.y = NewAxisValues.y + AxisOffsets.y;
	AxisValues.z = NewAxisValues.z + AxisOffsets.z;

	if(AddToRingBuffer) {
#ifdef ARRAY_SOLUTION
		std::rotate(RingBufferAxisX.begin(), RingBufferAxisX.begin()+1, RingBufferAxisX.end());
		RingBufferAxisX[ARRAY_SIZE-1] = AxisValues.x;

		std::rotate(RingBufferAxisY.begin(), RingBufferAxisY.begin()+1, RingBufferAxisY.end());
		RingBufferAxisY[ARRAY_SIZE-1] = AxisValues.y;

		std::rotate(RingBufferAxisZ.begin(), RingBufferAxisZ.begin()+1, RingBufferAxisZ.end());
		RingBufferAxisZ[ARRAY_SIZE-1] = AxisValues.z;
#endif

#ifdef VECTOR_SOLUTION
		if(RingBufferAxisX.size() >= ARRAY_SIZE) {
			RingBufferAxisX.erase(RingBufferAxisX.begin());
		}
		RingBufferAxisX.push_back(AxisValues.x);

		if(RingBufferAxisY.size() >= ARRAY_SIZE) {
			RingBufferAxisY.erase(RingBufferAxisY.begin());
		}
		RingBufferAxisY.push_back(AxisValues.y);


//		static int count = 0;
//		std::cout << "Adding Z  : " << count << "\r\n";
//		std::cout << "Size Buf Z: " << RingBufferAxisZ.size() << "\r\n";
		if(RingBufferAxisZ.size() >= ARRAY_SIZE) {
//			std::cout << "Evicting from Buf Z: " << *RingBufferAxisZ.begin() << "\r\n";
			RingBufferAxisZ.erase(RingBufferAxisZ.begin());
		}
		RingBufferAxisZ.push_back(AxisValues.z);

		std::cout << "Current Buffer Content:\r\n";
		uint32_t Position = 0;
		for(auto iterator = RingBufferAxisZ.cbegin(); iterator < RingBufferAxisZ.cend(); iterator++) {
			std::cout << "Idx " << Position << ": " << *iterator << "\r\n";
			Position++;
		}
//		count++;

#endif
	}
}

void IKS01A3_Motion::GetRingBufferAxisZ(std::vector<int32_t, util::ring_allocator<int32_t>> *BufCopy) {
	for (int i=0; i<RingBufferAxisZ.size(); i++) {
		BufCopy->push_back(RingBufferAxisZ[i]);
	}

}

void IKS01A3_Motion::GetValue(uint32_t p_Instance, uint32_t p_Function, int32_t *p_XAxis, int32_t *p_YAxis, int32_t *p_ZAxis) {
	*p_XAxis = AxisValues.x;
	*p_YAxis = AxisValues.y;
	*p_ZAxis = AxisValues.z;
}

void IKS01A3_Motion::GetAvgValues(int32_t *p_XAxis, int32_t *p_YAxis, int32_t *p_ZAxis) {
//	*p_XAxis = GetAv(RingBufferAxisX);
//	*p_YAxis = GetAv(RingBufferAxisY);
//	*p_ZAxis = GetAv(RingBufferAxisZ);

	// prof's solution:
	*p_XAxis = std::accumulate(RingBufferAxisX.begin(), RingBufferAxisX.end(), 0LL) / RingBufferAxisX.size();
	*p_YAxis = std::accumulate(RingBufferAxisY.begin(), RingBufferAxisY.end(), 0LL) / RingBufferAxisY.size();
	*p_ZAxis = std::accumulate(RingBufferAxisZ.begin(), RingBufferAxisZ.end(), 0LL) / RingBufferAxisZ.size();
}

void IKS01A3_Motion::PrintValuesToConsole() {
	std::cout << "X-axis: " << AxisValues.x << "\r\n";
	std::cout << "Y-axis: " << AxisValues.y << "\r\n";
	std::cout << "Z-axis: " << AxisValues.z << "\r\n";
}
