/**
* @file    MQ2_Config.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef MQ2_CONFIG_H
#define MQ2_CONFIG_H

#include "../../MCAL/DIO/DIO_private.h"
#include "../../MCAL/ADC/ADC_private.h"

// select MQ2 connection group and pin
#define MQ2_Port           Dio_groupA
#define MQ2_Pin            Dio_pin1

// select ADC channel connected to MQ2
#define MQ2_ADC_Channel    ADC_Channel1


#endif /* MQ2_CONFIG_H */
