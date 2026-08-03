/**
 * @file      MQ2_config.h
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the MQ2 Smoke/Gas Sensor Driver.
 * @details   This file contains user-configurable parameters such as the hardware 
 *            port, pin, and the specific ADC channel to which the MQ2 sensor is connected.
 *            Users can easily migrate the sensor to another ADC pin by updating these macros.
 * @version   1.0.0
 * @date      3 August 2026
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
