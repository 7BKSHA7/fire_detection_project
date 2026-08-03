/**
 * @file      LM35_private.h
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the LM35 Temperature Sensor Driver.
 * @details   This file contains internal macros used for temperature calculations, 
 *            such as the ADC reference voltage and resolution. These values are 
 *            hardware-specific and should not be modified by upper layers.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _LM35_PRIVATE_H_
#define _LM35_PRIVATE_H_

// ADC reference voltage in millivolt (5v = 5000mv) 
#define LM35_Vref             5000UL

// ADC resolution (10-bit = 1024)
#define LM35_ADC_Resolution   1024UL

#endif
