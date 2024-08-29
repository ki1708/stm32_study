/*
 * adc.c
 *
 *  Created on: Aug 29, 2024
 *      Author: addmin
 */

#include "adc.h"

extern ADC_HandleTypeDef hadc1;


bool adcInit(void)
{
	return true;
}

uint16_t adcRead(uint8_t rank)
{
	static const uint16_t Timeout = 10;
	uint16_t ret;

	HAL_ADC_Start(&hadc1);

	for (int i = 1; i < hadc1.Init.NbrOfConversion; i++)
	{
		HAL_ADC_PollForConversion(&hadc1, Timeout);

		ret = HAL_ADC_GetValue(&hadc1);

		if (i == rank)
		{
			return ret;
		}
		else if (i > rank)
		{
			return 0;
		}
	}
	return 0 ;
}

uint16_t adcReadVoltage(uint8_t rank)
{
	uint16_t ret ;
	ret = adcRead(rank);
	ret =  (330 * ret ) / 4096 ;
	return ret ;
}

