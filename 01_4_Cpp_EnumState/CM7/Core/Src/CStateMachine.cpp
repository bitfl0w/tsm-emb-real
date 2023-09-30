#include "CStateMachine.h"

CStateMachine::CStateMachine(int test) {
	DelayTime1 = test;
}

/*
CStateMachine::CStateMachine(EBlinkerStateEnum pFirstState, EBlinkerStateEnum pSecondState) {
	// set state and assign transitional states
	CurrentState = EBlinkerStateEnum::INIT;
	DelayTime1 = (uint16_t)pFirstState * 1000;
	DelayTime2 = (uint16_t)pSecondState * 1000;
}
*/

void CStateMachine::Start() {

}
