/**
 * @file      MQ2_private.h
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the MQ2 Smoke/Gas Sensor Driver.
 * @details   This file contains internal macros used for ADC calculations, 
 *            such as the reference voltage and ADC resolution. These values are 
 *            hardware-specific and should not be modified by upper layers.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef MQ2_PRIVATE_H
#define MQ2_PRIVATE_H

// ADC reference voltage in millivolt (5v = 5000mv) 
#define MQ2_Vref             5000UL

// ADC resolution (10-bit = 1024)
#define MQ2_ADC_Resolution   1024UL


#endif /* MQ2_PRIVATE_H */
