/*
 * IKS01A3Motion.h
 *
 *  Created on: Mar 25, 2022
 *      Author: dominique.kunz
 */

#ifndef SRC_IKS01A3MOTION_H_
#define SRC_IKS01A3MOTION_H_

#include <iostream>
#include <algorithm>
#include <map>

//#define STD_ARRAY

#include <vector>
#include <iterator>


#include <numeric>
#include "util_ring_allocator_std.h"
#include "iks01a3_motion_sensors.h"

#include <functional>
#include <cstring>

//for container map when searching the key
struct StrCompare : public std::binary_function<const char*, const char*, bool> {
public:
    bool operator() (const char* str1, const char* str2) const
    { return std::strcmp(str1, str2) < 0; }
};

//alternatively with ring allocator, has some issues with allocation
//typedef std::map<const char*, int32_t, StrCompare, util::ring_allocator_std< std::pair<const char*, int32_t> > > StatAxis_t;
typedef std::map<const char*, int32_t, StrCompare, util::ring_allocator_std< std::pair<const char* const, int32_t>>> StatAxis_t;

//using a map with char (C-String) as key to reduce complexity, therefore a compare operator is needed see: StrCompare
//typedef std::map<const char*, int32_t, StrCompare> StatAxis_t;


class IKS01A3_Motion {
private:
    IKS01A3_MOTION_SENSOR_Axes_t AxisValues;
    IKS01A3_MOTION_SENSOR_Axes_t AxisOffsets;


    std::vector<int32_t , util::ring_allocator_std<int32_t>>  RingBufferAxisX;
    std::vector<int32_t , util::ring_allocator_std<int32_t>>  RingBufferAxisY;
    std::vector<int32_t , util::ring_allocator_std<int32_t>>  RingBufferAxisZ;
    StatAxis_t StatsAxisX;
    StatAxis_t StatsAxisY;
    StatAxis_t StatsAxisZ;


public:
	IKS01A3_Motion();
	virtual ~IKS01A3_Motion();
	void enable(uint32_t Instance, uint32_t Function);
    void getValue(uint32_t Instance, uint32_t Function,int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis);
    void init(uint32_t Instance, uint32_t Function);
    void setZero(void);
    void updateValues(uint32_t Instance, uint32_t Function);
    void getAVGValues(int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis);
    void getMinValues(int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis);
    void getMaxValues(int32_t *XAxis, int32_t *YAxis, int32_t *ZAxis);
};

#endif /* SRC_IKS01A3MOTION_H_ */
