/**
 * @file      LM35_config.h
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the LM35 Temperature Sensor Driver.
 * @details   This file contains user-configurable parameters such as the hardware 
 *            port, pin, and the specific ADC channel to which the LM35 sensor is connected.
 *            Users can easily migrate the sensor to another ADC pin by updating these macros.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

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
