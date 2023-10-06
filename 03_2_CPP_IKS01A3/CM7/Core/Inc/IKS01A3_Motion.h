#include <stdint.h>
#include <array>
#include "stm32h7xx_hal.h"
#include "iks01a3_motion_sensors.h"

class IKS01A3_Motion {
private:
	IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
	IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;
	std::array<int32_t, 6> RingBufferAxisX;	// ringbuffers for 6 values
	std::array<int32_t, 6> RingBufferAxisY;
	std::array<int32_t, 6> RingBufferAxisZ;

public:
	// constructor
	IKS01A3_Motion();

	// methods
	void Init(uint32_t p_Instance, uint32_t p_Function);
	void Enable(uint32_t p_Instance, uint32_t p_Function);
	void SetZero(void);
	void UpdateValues(uint32_t p_Instance, uint32_t p_Function);
	void GetValue(uint32_t p_Instance, uint32_t p_Function, int32_t *p_XAxis, int32_t *p_YAxis, int32_t *p_ZAxis);
	void GetAvgValues(int32_t *p_XAxis, int32_t *p_YAxis, int32_t p_ZAxis);
	void PrintValuesToConsole();
};

