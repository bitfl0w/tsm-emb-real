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

typedef std::map<const char*, int32_t, StrCompare, util::ring_allocator_std< std::pair<const char*, int32_t> > > MyDef;

class IKS01A3_Motion {
public:
	static constexpr int ARRAY_SIZE = 10;

	enum class EStatisticalValuesEnum {
		Min = 0,
		Max = 1,
		Avg = 2
	};

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
	void GetMaxValues(int32_t *p_YAxis);
	void GetMinValues(int32_t *p_YAxis);

	MyDef ProfsMap;
private:
	IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
	IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;
#ifdef ARRAY_SOLUTION
	std::array<int32_t, ARRAY_SIZE> RingBufferAxisX;
	std::array<int32_t, ARRAY_SIZE> RingBufferAxisY;
	std::array<int32_t, ARRAY_SIZE> RingBufferAxisZ;
#endif

#ifdef VECTOR_SOLUTION
	std::vector<int32_t, util::ring_allocator_std<int32_t>> RingBufferAxisX;
	std::vector<int32_t, util::ring_allocator_std<int32_t>> RingBufferAxisY;
	std::vector<int32_t, util::ring_allocator_std<int32_t>> RingBufferAxisZ;

	//std::map<EStatisticalValuesEnum, int32_t, EnumClassComparator, util::ring_allocator<std::pair<EStatisticalValuesEnum, int32_t>>> StatAxisY;
	//std::map<int32_t, int32_t, std::less<int32_t>, util::ring_allocator_std<std::pair<int32_t, int32_t>>> StatAxisY;


//	struct EnumClassComparator {
//	public:
//		bool operator() (EStatisticalValuesEnum left, EStatisticalValuesEnum right) const {
//			return static_cast<int>(left) < static_cast<int>(right);
//		}
//	};
//
//	//alternatively with ring allocator, has some issues with allocation
//	std::map<EStatisticalValuesEnum, int32_t, EnumClassComparator, util::ring_allocator_std< std::pair<EStatisticalValuesEnum, int32_t> > > StatAxis_t;



#endif
};

