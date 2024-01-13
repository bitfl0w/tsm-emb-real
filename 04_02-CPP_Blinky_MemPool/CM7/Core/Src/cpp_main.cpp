#include "cpp_main.h"
#include "main.h"
#include "BlinkingLed.h"
#include <memory>
#include "MemPool.hpp"

void cpp_main(){

	//YOUR CODE STARTS HERE
    auto SmartPointerOnLedMemPool  = std::make_unique<MemPool<BlinkingLed,4>> ();

    ///WARNING_ There is a problem with the first object in the pool, initialize a dummy object first
    /// bad work around: initialise first a dummy  object
    BlinkingLed *Led0Blinker=SmartPointerOnLedMemPool->Allocate();
    BlinkingLed *Led1Blinker=SmartPointerOnLedMemPool->Allocate();
	Led1Blinker->setFrequency(0.5);
	Led1Blinker->setPinPort(LD1_GPIO_Port,LD1_Pin);

    BlinkingLed *Led2Blinker=SmartPointerOnLedMemPool->Allocate();
    Led2Blinker->setFrequency(1.0);
    Led2Blinker->setPinPort(LD2_GPIO_Port,LD2_Pin);

    BlinkingLed *Led3Blinker=SmartPointerOnLedMemPool->Allocate();
    Led3Blinker->setFrequency(2.0);
    Led3Blinker->setPinPort(LD3_GPIO_Port,LD3_Pin);
   	//YOUR CODE ENDS HERE

while (1)
	{
	//YOUR CODE STARTS HERE
	Led1Blinker->processBlinking();
	Led2Blinker->processBlinking();
	Led3Blinker->processBlinking();
	//YOUR CODE ENDS HERE
	}
}

