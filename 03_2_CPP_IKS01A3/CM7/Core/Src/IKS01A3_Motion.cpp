#include <algorithm>	// for std::rotate
#include <numeric> 		// for std::accumulate
#include "IKS01A3_Motion.h"
#include "printf.h"

// constructor
IKS01A3_Motion::IKS01A3_Motion() {
	AxisValues.x = 0;
	AxisValues.y = 0;
	AxisValues.z = 0;
	AxisOffsets.x = 0;
	AxisOffsets.y = 0;
	AxisOffsets.z = 0;

	// initialize the ringbuffer
#ifdef ARRAY_SOLUTION
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
		std::rotate(RingBufferAxisX.begin(), RingBufferAxisX.begin()+1, RingBufferAxisX.end());
		RingBufferAxisX[5] = AxisValues.x;

		std::rotate(RingBufferAxisY.begin(), RingBufferAxisY.begin()+1, RingBufferAxisY.end());
		RingBufferAxisY[5] = AxisValues.y;

		std::rotate(RingBufferAxisZ.begin(), RingBufferAxisZ.begin()+1, RingBufferAxisZ.end());
		RingBufferAxisZ[5] = AxisValues.z;
	}
}


void IKS01A3_Motion::GetValue(uint32_t p_Instance, uint32_t p_Function, int32_t *p_XAxis, int32_t *p_YAxis, int32_t *p_ZAxis) {
	*p_XAxis = AxisValues.x;
	*p_YAxis = AxisValues.y;
	*p_ZAxis = AxisValues.z;
}

int32_t GetAv(std::array<int32_t, 6> &arr) {
	if(!arr.empty()) {
		int64_t Sum = 0;
		int NumberOfElements = 0;
		for(auto iterator = arr.cbegin(); iterator < arr.cend(); iterator++) {
			Sum += *iterator;
			NumberOfElements++;
		}
		return Sum/NumberOfElements;
	}
	return 0;
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
	printf("X-axis: %i\r\n", AxisValues.x);
	printf("Y-axis: %i\r\n", AxisValues.y);
	printf("Z-axis: %i\r\n", AxisValues.z);
}
