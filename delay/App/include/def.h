/*
 * def.h
 *
 *  Created on: Aug 2, 2024
 *      Author: ki1708
 */

#ifndef INCLUDE_DEF_H_
#define INCLUDE_DEF_H_


#include <stdbool.h>
#include <stdint.h>


#include "main.h"


/*
 * 딜레이 함수관련 정의만 해서 쓸수있게 하기, 기능상 유틸에 포함되는게 맞으나 유틸중에서 거의필수기때문
 */
void delay(uint32_t time_ms);
uint32_t millis(void);


#define _DEF_CH1 0
#define _DEF_CH2 1
#define _DEF_CH3 2
#define _DEF_CH4 3
#define _DEF_CH5 4



#endif /* INCLUDE_DEF_H_ */
