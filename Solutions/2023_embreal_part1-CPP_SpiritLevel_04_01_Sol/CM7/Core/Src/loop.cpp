/*
 * looper.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: dominique.kunz
 */

#include "loop.h"
#include "main.h"
#include "SpiritLevelSinglAxis3LED.h"
#include "util_ring_allocator.h"

SpiritLevelSinglAxis3LED SpiritLevelYAxis;



void loop()
{

    SpiritLevelYAxis.init();

while (1)
	{

    if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin))SpiritLevelYAxis.setZero();

  //  HAL_GPIO_WritePin(TriggerStartPE0_GPIO_Port, TriggerStartPE0_Pin, GPIO_PIN_SET);
    //no optimisation
    //ET 2.653ms + 9.599us Jitter
    // WCET 1.75us,  Jitter 9.599us ca .ServiceTime 2.54ms
    //optimised for speed
    // ET 2.544ms + 7.96us Jitter
    // WCET 2.55ms,  Jitter us ca .ServiceTime ms
    SpiritLevelYAxis.updateValues();
  //  HAL_GPIO_WritePin(TriggerStartPE0_GPIO_Port, TriggerStartPE0_Pin, GPIO_PIN_RESET);

 //   HAL_GPIO_WritePin(TriggerStartPE0_GPIO_Port, TriggerStartPE0_Pin, GPIO_PIN_SET);
    SpiritLevelYAxis.show();
    //no optimisation
    //ET 1.95us + 30ns Jitter (source if else structure!)
    // WCET us,  Jitter us ca .ServiceTime ms
    //optimised for speed
    // ET 1.19us + 55ns Jitter (source if else structure!)
    // WCET 1.135us,  Jitter us ca .ServiceTime ms
 //   HAL_GPIO_WritePin(TriggerStartPE0_GPIO_Port, TriggerStartPE0_Pin, GPIO_PIN_RESET);


    HAL_Delay(100);

}
}

