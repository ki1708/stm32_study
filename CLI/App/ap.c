/*
 * ap.c
 *
 *  Created on: Aug 2, 2024
 *      Author: ki1708
 */

#include "ap.h"
#include "string.h"
#include "stdlib.h"


//uint32_t adc_vol = 0 ;

//extern UART_HandleTypeDef huart1; // main에서 선언된것을 여기에서 쓰도록 extern
float adc_vol = 0 ;

char cli_buf[128];
uint16_t cli_buf_index = 0;

uint16_t cli_argc = 0;
char *cli_argv[8]; // cli 인수 포인터 배열


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
		if (millis() - pre_time >= 500)
		{
			pre_time = millis();
			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		}


		if(uartAvailable(_DEF_CH1) > 0)
		{
			uint8_t rx_data ;
			rx_data = uartRead(_DEF_CH1) ;
			//uartPrintf(_DEF_CH1, "rx_data : %c \n ",rx_data ); // 프롬프트라고 알리는 출력


			if (rx_data == '\r') {
				cli_buf[cli_buf_index] = 0; // CLI 라인마지막 'r'다음 null값을 주기
				cli_buf_index = 0;
				uartPrintf(_DEF_CH1, "\r\n"); // 터미널쪽에 줄바꿈
				//RUN CMD

				char *tok;
				char *str_ptr = cli_buf;
				cli_argc = 0;

				while ((tok = strtok_r(str_ptr, " ", &str_ptr)) != NULL) {
					cli_argv[cli_argc] = tok;
					cli_argc++;
				}
/* 기본 구조
				if(cli_argc > 0)
				{
					if (strcmp(cli_argv[0], "test") ==0 )
					{
						uartPrintf(_DEF_CH1, "run test\n");

						for(int i = 0 ; i < cli_argc; i++)
						{
							uartPrintf(_DEF_CH1, "%d : %s\n", i, cli_argv[i]);
						}
					}
				}
*/

				// 명령어의 정수 파라메터 사용 시

				if(cli_argc > 0)
				{
					if ( cli_argc == 2 && strcmp(cli_argv[0], "test") ==0 )
					{
						int32_t test_data ;
						test_data = (int32_t) strtoul ( cli_argv[1],(char **)NULL,0);
						uartPrintf(_DEF_CH1, "test_data : %d\n", test_data);
					}
				}





				uartPrintf(_DEF_CH1, "cli# "); // 프롬프트라고 알리는 출력
			}
			else if(cli_buf_index < (128 - 1))	// 버퍼 경계처리 128은 버퍼크기 , -1은 null값 고려
			{
				cli_buf[cli_buf_index] = rx_data ;
				cli_buf_index ++ ;
				uartWrite(_DEF_CH1, &rx_data, 1) ; // 에코
			}

		}


		//adc_vol = (float)adcReadVoltage(_DEF_CH1) / 100.f;
	}
}
