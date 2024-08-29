/*
 * ap.c
 *
 *  Created on: Aug 29, 2024
 *      Author: addmin
 */


#include "ap.h"
#include "adc.h"

uint16_t adc_vol = 0;


void apInit(void)
{

}



void apMain(void)
{

	while(1)
	{
		adc_vol =adcReadVoltage(_DEF_CH1);
	}
}
