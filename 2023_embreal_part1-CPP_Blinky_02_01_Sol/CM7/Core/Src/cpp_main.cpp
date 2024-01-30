#include "cpp_main.h"
#include "main.h"

//YOUR CODE STARTS HERE
#include "BlinkingLed.h"
//YOUR CODE ENDS HERE

void cpp_main(){
	//YOUR CODE STARTS HERE
	BlinkingLed Led1Blinker{LD1_GPIO_Port,LD1_Pin};
	Led1Blinker.setFrequency(0.5);

	BlinkingLed Led2Blinker{LD2_GPIO_Port,LD2_Pin};
	Led2Blinker.setFrequency(1.0);

	BlinkingLed Led3Blinker{LD3_GPIO_Port,LD3_Pin};
	Led3Blinker.setFrequency(2.0);
	//YOUR CODE ENDS HERE

while (1)
	{
	//YOUR CODE STARTS HERE
	Led1Blinker.processBlinking();
	Led2Blinker.processBlinking();
	Led3Blinker.processBlinking();
	//YOUR CODE ENDS HERE
	}
}

