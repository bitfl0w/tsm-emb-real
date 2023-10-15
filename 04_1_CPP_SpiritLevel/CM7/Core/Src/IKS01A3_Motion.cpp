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
	std::fill(std::begin(RingBufferAxisX), std::end(RingBufferAxisX), 0);
	std::fill(std::begin(RingBufferAxisY), std::end(RingBufferAxisY), 0);
	std::fill(std::begin(RingBufferAxisZ), std::end(RingBufferAxisZ), 0);

	// fill statistical values
	StatsAxisX.insert(std::make_pair(EStatisticalValuesEnum::Min, 0));
	StatsAxisX.insert(std::make_pair(EStatisticalValuesEnum::Max, 0));
	StatsAxisX.insert(std::make_pair(EStatisticalValuesEnum::Avg, 0));
	StatsAxisY.insert(std::make_pair(EStatisticalValuesEnum::Min, 0));
	StatsAxisY.insert(std::make_pair(EStatisticalValuesEnum::Max, 0));
	StatsAxisY.insert(std::make_pair(EStatisticalValuesEnum::Avg, 0));
	StatsAxisZ.insert(std::make_pair(EStatisticalValuesEnum::Min, 0));
	StatsAxisZ.insert(std::make_pair(EStatisticalValuesEnum::Max, 0));
	StatsAxisZ.insert(std::make_pair(EStatisticalValuesEnum::Avg, 0));
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
		if(RingBufferAxisX.size() >= ARRAY_SIZE) {
			RingBufferAxisX.erase(RingBufferAxisX.begin());
		}
		RingBufferAxisX.push_back(AxisValues.x);

		if(RingBufferAxisY.size() >= ARRAY_SIZE) {
			RingBufferAxisY.erase(RingBufferAxisY.begin());
		}
		RingBufferAxisY.push_back(AxisValues.y);

		if(RingBufferAxisZ.size() >= ARRAY_SIZE) {
			RingBufferAxisZ.erase(RingBufferAxisZ.begin());
		}
		RingBufferAxisZ.push_back(AxisValues.z);

		// update statistical values
		UpdateStatVal(&RingBufferAxisX, &StatsAxisX);
		UpdateStatVal(&RingBufferAxisY, &StatsAxisY);
		UpdateStatVal(&RingBufferAxisZ, &StatsAxisZ);
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

void IKS01A3_Motion::UpdateStatVal(const std::vector<int32_t, util::ring_allocator_std<int32_t>>* Buffer, StatisticalValues_t* StatValMap) { //, StatisticalValues_t* StatValMap) {
	auto minmax = std::minmax_element(Buffer->begin(), Buffer->end());
	StatValMap->find(EStatisticalValuesEnum::Min)->second = *minmax.first;	// assign value of map
	StatValMap->find(EStatisticalValuesEnum::Max)->second = *minmax.second;


	int32_t sum = std::accumulate((Buffer)->begin(), (Buffer)->end(), 0LL);
	int32_t size = (Buffer)->size();
	int32_t average = sum / size;
	StatValMap->find(EStatisticalValuesEnum::Avg)->second = average;	// assign value of map
}

void IKS01A3_Motion::GetStatVal(StatisticalValues_t* StatValX, StatisticalValues_t* StatValY, StatisticalValues_t* StatValZ) {
	 *StatValX = this->StatsAxisX;
	 *StatValY = this->StatsAxisY;
	 *StatValZ = this->StatsAxisZ;
}

void IKS01A3_Motion::PrintValuesToConsole() {
	printf("X-axis: %i\r\n", StatsAxisX.find(EStatisticalValuesEnum::Min)->second);
	printf("Y-axis: %i\r\n", AxisValues.y);
	printf("Z-axis: %i\r\n", AxisValues.z);
}
