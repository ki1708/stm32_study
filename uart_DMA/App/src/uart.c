/*
 * uart.c
 *
 *  Created on: Aug 7, 2024
 *      Author: ki1708
 */


#include "uart.h"

#define UART_Q_BUF_MAX 256

extern UART_HandleTypeDef huart1; // main에서 선언된것을 여기에서 쓰도록 extern

static uint16_t q_in = 0;
static uint16_t q_out = 0;
static uint8_t q_buf[UART_Q_BUF_MAX];


bool uartInit(void) //코어에서 실제로 초기화를 함.
{
	HAL_UART_Receive_DMA(&huart1, &q_buf[0], UART_Q_BUF_MAX);
	return true;
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
	uint32_t ret = 0 ;

	switch(ch)
	{
	case _DEF_CH1:
		q_in = (UART_Q_BUF_MAX - huart1.hdmarx->Instance->NDTR) % UART_Q_BUF_MAX ;
		ret = (UART_Q_BUF_MAX + q_in - q_out ) % UART_Q_BUF_MAX ;  // 큐에 남아있는 버퍼 갯수를 리턴
		break;
	}
	return ret ;
}


uint8_t uartRead(uint8_t ch)	//버퍼를 출력하기
{
	uint8_t ret = 0 ;

	switch(ch)
	{
	case _DEF_CH1:
		if(q_out != q_in)
		{
			ret = q_buf[q_out];
			q_out = (q_out + 1) % UART_Q_BUF_MAX ;
		}
		break;
	}

	return ret ;
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








