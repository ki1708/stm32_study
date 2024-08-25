/*
 * ap.c
 *
 *  Created on: Aug 2, 2024
 *      Author: ki1708
 */

#include "ap.h"


//uint32_t adc_vol = 0 ;

//extern UART_HandleTypeDef huart1; // main에서 선언된것을 여기에서 쓰도록 extern
float adc_vol = 0 ;


void apInit(void)
{
	adcInit();
	uartInit();
}

void apMain(void)
{
	uint32_t pre_time ;
	//uint32_t pre_time_2 ;

	pre_time = millis();
	//pre_time_2 = millis();

	//uint8_t temp_buf[5] = {0};
	//uint8_t temp_index = 0;


	while(1)
	{
		if (millis() - pre_time >= 500)	// 논블락킹 코드
		{
			pre_time = millis();
			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
			//uartPrintf(_DEF_CH1, "dma cndtr : %d\n" , huart1.hdmarx->Instance->NDTR ); // huart1 을통해서 dma 핸들러로 진입.
			//uartPrintf (_DEF_CH1,"q_remain : %d\n", uartAvailable(_DEF_CH1) ) ;
		}



		if(uartAvailable(_DEF_CH1) > 0) // 수신된 데이터있음.
		{
			uint8_t rx_data ;
			rx_data = uartRead(_DEF_CH1) ;
			uartPrintf(_DEF_CH1, "rx data : 0x%02X (%c)\n", rx_data , rx_data);
		}



		/*
		if (millis() - pre_time_2 >= 10000)	// 논블락킹 코드
		{
			pre_time_2 = millis();
			temp_index = 0;
			while(uartAvailable(_DEF_CH1) > 0)
			{
				temp_buf[temp_index] = uartRead(_DEF_CH1) ;
				uartPrintf(_DEF_CH1, "temp_buf : 0x%02X (%c)\n", temp_buf[temp_index] , temp_buf[temp_index]);
				temp_index++;
			}
		}
		*/



		//adc_vol = (float)adcReadVoltage(_DEF_CH1) / 100.f;
	}
}
