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
	uint32_t pre_time = 0 ;

	while(1)
	{
		if (millis() - pre_time >= 500)	// 논블락킹 코드
		{
			pre_time = millis();
			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		}


		//HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		//HAL_Delay(500);

		adc_vol = (float)adcReadVoltage(_DEF_CH1) / 100.f;


		//printf("adc_data : %d \n\r" ,adc_data );
		//printf("adc_vol : %d \n\r" ,adc_vol );
	}
}
