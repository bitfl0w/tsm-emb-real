#include "NoneBlockSystemTickDelay.h"

/*
 * NoneBlockSystemTickDelay.c
 *
 *  Created on: Mar 18, 2022
 *      Author: dominique.kunz
 */

/**
  * @brief This function provides minimum delay (in milliseconds) based
  *        on variable incremented.
  * @note In the default implementation , SysTick timer is the source of time base.
  *       It is used to generate interrupts at regular time intervals where uwTick
  *       is incremented.
  * @note This is  none blocking solution.
  * @param Delay  specifies the delay time length, in milliseconds.
  * @retval TickstartTimerValue needed for check in expiration function
  */

void NoneBlockSystemTickDelay__DelayNoneBlockingInit(uint32_t *DelayNoneBlocking_tickstart, uint32_t *Delay)
{
	*DelayNoneBlocking_tickstart = HAL_GetTick();

  /* Add a uwTickFreq to guarantee minimum wait */
	  if (*Delay < 1)
	  {
		  *Delay += (uint32_t)(uwTickFreq);
	  }
}

/**
  * @brief This function provides minimum delay (in milliseconds) based
  *        on variable incremented.
  * @note In the default implementation , SysTick timer is the source of time base.
  *       It is used to generate interrupts at regular time intervals where uwTick
  *       is incremented.
  * @note
  * @param Delay  specifies the delay time length, in milliseconds.
  * @retval None
  */

uint8_t NoneBlockSystemTickDelay__DelayNoneBlockingCheckExpiration(uint32_t DelayNoneBlocking_tickstart, uint32_t Delay)
{
  if ((HAL_GetTick() - DelayNoneBlocking_tickstart) < Delay)return(0); //time is not expired
  else return(0xFF);
}
