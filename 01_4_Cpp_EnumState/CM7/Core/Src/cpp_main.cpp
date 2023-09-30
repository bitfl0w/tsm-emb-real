#include <cstdint>
#include "cpp_main.h"
#include "main.h"
#include <iostream> // for cout
//#include "CStateMachine.h"

class CStateMachine {
	public:
		enum class EBlinkerStateEnum {
			INIT = 0,
			BLINK_1HZ = 1,
			BLINK_2HZ = 2,
			BLINK_3HZ = 3
		};

		// member variables
		enum EBlinkerStateEnum State1;
		enum EBlinkerStateEnum State2;
		enum EBlinkerStateEnum CurrentState;
		uint8_t LedNumber; // LD1 PB0 or LD2 (PE1)
		uint8_t NumberOfBlinks; // How many blinks (on/off) the LED already performed
		const uint8_t NumberOfBlinksToPerform = 5; // how many blinks the LED shall perform before switching frequencies

		// constructor
		CStateMachine(uint8_t pLedNumber, EBlinkerStateEnum pFirstState, EBlinkerStateEnum pSecondState);

		// method declaration

		void CheckForToggle();
		void CheckForStateChange();

	private:
		uint32_t LastTickTimer;
		uint16_t GetDelayFromState(EBlinkerStateEnum pState);
		void Begin();
};

// Constructor Definition (content of cpp file)
CStateMachine::CStateMachine(uint8_t pLedNumber, CStateMachine::EBlinkerStateEnum pFirstState, CStateMachine::EBlinkerStateEnum pSecondState) {
	// set state and assign transitional states
	LedNumber = pLedNumber;
	CurrentState = EBlinkerStateEnum::INIT;
	std::cout << "Initialization finished" << std::endl;
	State1 = pFirstState;
	State2 = pSecondState;
	NumberOfBlinks = 0;
	LastTickTimer = HAL_GetTick();
	Begin();
}

// Function Definitions (content of cpp file)
uint16_t CStateMachine::GetDelayFromState(EBlinkerStateEnum pState) {
		float PauseTime = (1000.0f / (2 * (uint8_t)pState));
		return (uint16_t(PauseTime + 0.5f) * 10) / 10;
}

void CStateMachine::Begin() {
	CurrentState = State1;
}

void CStateMachine::CheckForToggle() {
	if(CurrentState == CStateMachine::EBlinkerStateEnum::INIT) {
		return;
	}

	if((HAL_GetTick() - LastTickTimer) >= GetDelayFromState(CurrentState) ) {
		if(LedNumber == 1) {
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
			NumberOfBlinks++;
		}
		if(LedNumber == 2) {
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			NumberOfBlinks++;
		}

		// save time (ticks) of last toggle
		LastTickTimer = HAL_GetTick();
	}
}

void CStateMachine::CheckForStateChange() {
	if(CurrentState == CStateMachine::EBlinkerStateEnum::INIT) {
		return;
	}

	if(NumberOfBlinks >= 2 * NumberOfBlinksToPerform) {
		if(CurrentState == State1) {
			CurrentState = State2;
			NumberOfBlinks = 0;
		} else {
			CurrentState = State1;
			NumberOfBlinks = 0;
		}
	}
}

void cpp_main() {
	CStateMachine SM1(1, CStateMachine::EBlinkerStateEnum::BLINK_1HZ, CStateMachine::EBlinkerStateEnum::BLINK_3HZ);
	CStateMachine SM2(2, CStateMachine::EBlinkerStateEnum::BLINK_1HZ, CStateMachine::EBlinkerStateEnum::BLINK_2HZ);

	while(1) {
		// check if the LED must be toggled
		SM1.CheckForToggle();
		SM2.CheckForToggle();

		// check if the frequency must be updated
		SM1.CheckForStateChange();
		SM2.CheckForStateChange();
	}
}

// EOF
