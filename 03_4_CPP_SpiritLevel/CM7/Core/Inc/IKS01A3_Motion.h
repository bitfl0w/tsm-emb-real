#include <stdint.h>
#include <array>
#include <vector>
#include "util_ring_allocator.h"
#include "stm32h7xx_hal.h"
#include "iks01a3_motion_sensors.h"
#include "cpp_main.h"

class IKS01A3_Motion {
public:
	static constexpr int ARRAY_SIZE = 10;

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

private:
	IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
	IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;
#ifdef ARRAY_SOLUTION
	std::array<int32_t, ARRAY_SIZE> RingBufferAxisX;
	std::array<int32_t, ARRAY_SIZE> RingBufferAxisY;
	std::array<int32_t, ARRAY_SIZE> RingBufferAxisZ;
#endif

#ifdef VECTOR_SOLUTION
	std::vector<int32_t, util::ring_allocator<int32_t>> RingBufferAxisX;
	std::vector<int32_t, util::ring_allocator<int32_t>> RingBufferAxisY;
	std::vector<int32_t, util::ring_allocator<int32_t>> RingBufferAxisZ;
#endif
};

