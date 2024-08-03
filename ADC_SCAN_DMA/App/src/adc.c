/*
 * adc.c
 *
 *  Created on: Aug 3, 2024
 *      Author: ki1708
 */

#include "adc.h"
extern ADC_HandleTypeDef hadc1;




uint16_t adc_data[3];



bool adcInit(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_data, 3);		//핸들러, 배열, 채널 수
	return true;
}
uint16_t adcRead(uint8_t ch)
{
	uint16_t ret = 0;
	switch(ch)
	{
		case _DEF_CH1 :
			ret = adc_data[ch];
		break;
	}
	return ret;
}


uint32_t adcReadVoltage(uint8_t ch)
{
	uint32_t ret ;
	uint32_t adc_data;
	adc_data = adcRead(ch);
	ret = (330 * adc_data ) / 4096 ;	// float 안쓰고 330 (3.3v) * adc_data / 2의 12승(해상도)
	return ret ;
}
