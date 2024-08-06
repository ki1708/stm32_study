/*
 * utils.c
 *
 *  Created on: Aug 7, 2024
 *      Author: ki1708
 */

#include "utils.h"


void delay(uint32_t time_ms) // Hal 추상화용
{
	HAL_Delay(time_ms);
}



uint32_t millis(void)
{
	return HAL_GetTick();
}
