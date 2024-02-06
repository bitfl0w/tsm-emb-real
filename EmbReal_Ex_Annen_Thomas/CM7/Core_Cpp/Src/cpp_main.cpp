#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
#include "AdcAvg.h"

// dummy ADC channel readout
float ADC_ReadChannel(uint8_t Channel) {
	static uint8_t count = 0;

	if(count == 0) {
		count++;
		return 19.5f;
	}
	if(count == 1) {
		count++;
		return 21.5f;
	}
	if(count == 2) {
		count=0;
		return 20.0f;
	}
}

void cpp_main() {
	AdcAvg MyAdcObj;
	const uint8_t Channel = 0;
	while(1) {
		ADC_ReadChannel(Channel);
	}
}

// EOF
