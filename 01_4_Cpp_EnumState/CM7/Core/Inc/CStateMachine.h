#pragma once
#include <cstdint>

class CStateMachine {
	public:
		enum class EBlinkerStateEnum {
			INIT = 0,
			BLINK_1HZ = 1,
			BLINK_2HZ = 2,
			BLINK_3HZ = 3
		};

		// member variables
		enum EBlinkerStateEnum CurrentState;
		uint16_t DelayTime1;
		uint16_t DelayTime2;
		const uint8_t NumberOfBlinksToPerform = 5;

		// constructor
		CStateMachine(int test);
		//CStateMachine(EBlinkerStateEnum pFirstState, EBlinkerStateEnum pSecondState);

		void Start();

	private:
		uint32_t LastTickTimer;
};
