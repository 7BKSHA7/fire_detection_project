#ifndef _LM35_CONFIG_H_
#define _LM35_CONFIG_H_

#include "../../MCAL/DIO/DIO_private.h"
#include "../../MCAL/ADC/ADC_private.h" 

// select LM35 connection group and pin
#define LM35_Port           Dio_groupA
#define LM35_Pin            Dio_pin0

// select ADC channel connected to LM35
#define LM35_ADC_Channel    ADC_Channel0

#endif
