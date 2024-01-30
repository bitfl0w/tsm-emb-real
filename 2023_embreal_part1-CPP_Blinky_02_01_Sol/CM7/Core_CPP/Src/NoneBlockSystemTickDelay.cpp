/*
 * NoneBlockSystemTickDelay.cpp
 *
 *  Created on: 14.03.2022
 *      Author: dominique.kunz
 */

#include <NoneBlockSystemTickDelay.h>

NoneBlockSystemTickDelay::NoneBlockSystemTickDelay() {
	// TODO Auto-generated constructor stub

}

NoneBlockSystemTickDelay::~NoneBlockSystemTickDelay() {
	// TODO Auto-generated destructor stub
}


void NoneBlockSystemTickDelay::initialise(const uint32_t Delay)
{
	Wait = Delay;
	Tickstart = HAL_GetTick();

  /* Add a uwTickFreq to guarantee minimum wait */
  if (Wait < 1)
  {
	  Wait += (uint32_t)(uwTickFreq);
  }
}

uint8_t NoneBlockSystemTickDelay::checkExpiration(void)
{
if(Wait != 0)
	  if ((HAL_GetTick() - Tickstart) < Wait) return(0); //time is not expired
	  else
	  {
					  //time is expired
		  Wait = 0;
		  return(0xFF);
	  }
else  return(0xFF); //time is expired or has not been set
}
