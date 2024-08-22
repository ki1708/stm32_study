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
	uartInit();
}

void apMain(void)
{
	uint32_t pre_time ;

	pre_time = millis();
	while(1)
	{
		if (millis() - pre_time >= 500)	// 논블락킹 코드
		{
			pre_time = millis();
			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
			//uartPrintf(_DEF_CH1, "dma cndtr : %d\n" ,huart1.hdmarx->Instance->NDTR ); // huart1 을통해서 dma 핸들러로 진입.

		}
		if(uartAvailable(_DEF_CH1) > 0) // 수신된 데이터있음.
		{
			uint8_t rx_data ;
			rx_data = uartRead(_DEF_CH1) ;
			uartPrintf(_DEF_CH1, "rx data : 0x%02X (%c)\n", rx_data , rx_data);
		}

		//adc_vol = (float)adcReadVoltage(_DEF_CH1) / 100.f;
	}
}
