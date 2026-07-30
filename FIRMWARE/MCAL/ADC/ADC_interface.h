#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void ADC_Init(u8 Mode);
void ADC_Enable();
void ADC_Disable();
void ADC_Adjust(u8 Adjust_Direction);
void ADC_Channel(u8 Channel);
void ADC_StartConversion(u8 Mode);
void ADC_Prescaler(u8 Prescaler);
u16  ADC_ReadResult(void); //i use u16 cuz maybew i will use 10bits
/* 8bit >> 255    10bit >> 1024 */

#endif