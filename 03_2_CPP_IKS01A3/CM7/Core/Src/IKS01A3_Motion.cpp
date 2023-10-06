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

void IKS01A3_Motion::UpdateValues(uint32_t p_Instance, uint32_t p_Function) {
	IKS01A3_MOTION_SENSOR_Axes_t NewAxisValues;
	IKS01A3_MOTION_SENSOR_GetAxes(p_Instance, p_Function, &NewAxisValues);
	AxisValues.x = NewAxisValues.x;
	AxisValues.y = NewAxisValues.y;
	AxisValues.z = NewAxisValues.z;
}

void IKS01A3_Motion::GetValue(uint32_t p_Instance, uint32_t p_Function, int32_t *p_XAxis, int32_t *p_YAxis, int32_t *p_ZAxis) {
	*p_XAxis = AxisValues.x;
	*p_YAxis = AxisValues.y;
	*p_ZAxis = AxisValues.z;
}


void IKS01A3_Motion::GetAvgValues(int32_t *p_XAxis, int32_t *p_YAxis, int32_t p_ZAxis) {

}

void IKS01A3_Motion::PrintValuesToConsole() {
	printf("X-axis: %i\r\n", AxisValues.x);
	printf("Y-axis: %i\r\n", AxisValues.y);
	printf("Z-axis: %i\r\n", AxisValues.z);
}
