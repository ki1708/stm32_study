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
			//uartWrite(_DEF_CH1, (uint8_t *)"test\n", 5); // uart test code
			//uartPrintf(_DEF_CH1,"test %d\n",millis() );	//uartprintf 구현 code
			//uartPrintf(_DEF_CH1,"adc_vol : %d.%d\n",(int)adc_vol, ((int)(adc_vol * 100)) %100 );	//uartprintf 구현 code + printf에서 float을 정수로 변경해서 출력
			uartPrintf(_DEF_CH1, "rx cnt %d\n", uartAvailable(_DEF_CH1));	//uartAvaillable 구현 확인 (입력된 버퍼갯수 출력)
		}

		if(uartAvailable(_DEF_CH1) > 0) // 수신된 데이터있음.
		{
			uint8_t rx_data ;
			rx_data = uartRead(_DEF_CH1) ;
			uartPrintf(_DEF_CH1, "rx data : 0x%02X (%c)\n",rx_data , rx_data ); // 0x%02X 헥사 출력
		}

		//HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		//HAL_Delay(500);
		adc_vol = (float)adcReadVoltage(_DEF_CH1) / 100.f;
		//printf("adc_data : %d \n\r" ,adc_data );
		//printf("adc_vol : %d \n\r" ,adc_vol );
	}
}
