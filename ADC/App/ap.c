/*
 * ap.c
 *
 *  Created on: Aug 2, 2024
 *      Author: ki1708
 */

#include "ap.h"


//uint32_t adc_vol = 0 ;
float adc_vol = 0 ;

void apInit(void)
{
	adcInit();
}

void apMain(void)
{
	while(1)
	{
		//HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		//HAL_Delay(500);

		adc_vol = (float)adcReadVoltage(_DEF_CH1) / 100.f;


		//printf("adc_data : %d \n\r" ,adc_data );
		//printf("adc_vol : %d \n\r" ,adc_vol );
	}
}
