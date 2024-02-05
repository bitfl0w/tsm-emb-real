/*
 * NoneBlockSystemTickDelay.cpp
 *
 *  Created on: 14.03.2022
 *      Author: dominique.kunz
 */

#include <NoneBlockSystemTickDelay.h>

 myhal::NoneBlockSystemTickDelay::NoneBlockSystemTickDelay() {
	// TODO Auto-generated constructor stub

}

 myhal::NoneBlockSystemTickDelay::~NoneBlockSystemTickDelay() {
	// TODO Auto-generated destructor stub
}


void  myhal::NoneBlockSystemTickDelay::initialise(const uint32_t Delay)
{
	Wait = Delay;
	Tickstart = HAL_GetTick();

  /* Add a freq to guarantee minimum wait */
  if (Wait < 1)
  {
	  Wait += (uint32_t)(uwTickFreq);
  }
}

const bool  myhal::NoneBlockSystemTickDelay::checkExpiration(void)
{
if(Wait != 0)
	  if ((HAL_GetTick() - Tickstart) < Wait) return(false); //time is not expired
	  else
	  {
					  //time is expired
		  Wait = 0;
		  return(true);
	  }
else  return(true); //time is expired or has not been set
}
