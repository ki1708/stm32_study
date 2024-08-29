/*
 * adc.h
 *
 *  Created on: Aug 29, 2024
 *      Author: addmin
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_


#include "def.h"

bool adcInit(void);
uint16_t adcRead(uint8_t ch);
uint16_t adcReadVoltage(uint8_t ch);


#endif /* INC_ADC_H_ */
