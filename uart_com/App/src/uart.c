/*
 * uart.c
 *
 *  Created on: Aug 7, 2024
 *      Author: ki1708
 */


#include "uart.h"


extern UART_HandleTypeDef huart1; // main에서 선언된것을 여기에서 쓰도록 extern



bool 	 uartInit(void) //코어에서 실제로 초기화를 함.
{
	return true ;
}
uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
	uint32_t ret = 0;
	HAL_StatusTypeDef hal_ret;

	switch(ch)
	{
		case _DEF_CH1:
			hal_ret = HAL_UART_Transmit(&huart1, p_data, length, 100); //timeout으로 100ms 주기
			if(hal_ret == HAL_OK)
			{
				ret = length ;	// HAL_OK일 경우가 아니면 ret은 0으로 초기화된그대로,.
			}
			break;
	}
	return ret ;
}


uint32_t uartAvailable(uint8_t ch)
{

}


uint32_t uartRead(uint8_t ch)
{

}


uint32_t uartPrintf(uint8_t ch ,const char *fmt, ... ) //가변인자를 사용한 형식화 출력함수, 프로그램만들때 매우 용이
{
	uint32_t ret = 0;

	va_list arg ;
	char print_buf[256];

	va_start(arg,fmt);
	int len;
	len = vsnprintf(print_buf , 256, fmt, arg);
	va_end(arg);

	if (len > 0)
	{
		ret = uartWrite(ch,(uint8_t *)print_buf,len);
	}

	return ret;
}
