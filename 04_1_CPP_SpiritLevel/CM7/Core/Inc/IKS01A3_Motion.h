#include <stdint.h>
#include <array>
#include <vector>
#include <map>
#include <utility>
#include <numeric>
#include <iostream>
#include <cstring>
#include <functional>
#include "util_ring_allocator_std.h"
#include "stm32h7xx_hal.h"
#include "iks01a3_motion_sensors.h"
#include "cpp_main.h"

struct StrCompare : public std::binary_function<const char*, const char*, bool> {
public:
    bool operator() (const char* str1, const char* str2) const
    { return std::strcmp(str1, str2) < 0; }
};

typedef std::map<char* const, int32_t, StrCompare, util::ring_allocator_std< std::pair<char* const, int32_t> > > ProfDef;


class IKS01A3_Motion {
public:
	static constexpr int ARRAY_SIZE = 10;

	enum EStatisticalValuesEnum {
		Min = 0,
		Max = 1,
		Avg = 2
	};

	typedef std::map<const EStatisticalValuesEnum, int32_t, std::less<uint8_t>, util::ring_allocator_std< std::pair<const EStatisticalValuesEnum, int32_t>>> StatisticalValues_t;
//	struct EnumClassComparator
//	public:
//		bool operator() (EStatisticalValuesEnum left, EStatisticalValuesEnum right) const {
//			return static_cast<int>(left) < static_cast<int>(right);
//		}
//	};

	// constructors
	IKS01A3_Motion();

	// methods
	void Init(uint32_t p_Instance, uint32_t p_Function);
	void Enable(uint32_t p_Instance, uint32_t p_Function);
	void SetZero(void);
	void UpdateValues(uint32_t p_Instance, uint32_t p_Function, bool AddToRingBuffer = true);
	void GetValue(uint32_t p_Instance, uint32_t p_Function, int32_t *p_XAxis, int32_t *p_YAxis, int32_t *p_ZAxis);
	void GetAvgValues(int32_t *p_XAxis, int32_t *p_YAxis, int32_t *p_ZAxis);
	void PrintValuesToConsole();
	void UpdateStatVal(const std::vector<int32_t, util::ring_allocator_std<int32_t>>* Buffer, StatisticalValues_t* StatValMap); // , StatisticalValues_t* StatValMap);
	void GetStatVal(StatisticalValues_t* StatValX, StatisticalValues_t* StatValY, StatisticalValues_t* StatValZ);

	// attributes


private:
	IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
	IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;

	std::vector<int32_t, util::ring_allocator_std<int32_t>> RingBufferAxisX;
	std::vector<int32_t, util::ring_allocator_std<int32_t>> RingBufferAxisY;
	std::vector<int32_t, util::ring_allocator_std<int32_t>> RingBufferAxisZ;

	StatisticalValues_t StatsAxisX;
	StatisticalValues_t StatsAxisY;
	StatisticalValues_t StatsAxisZ;
};

