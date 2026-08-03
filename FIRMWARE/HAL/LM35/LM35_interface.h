/**
 * @file      LM35_interface.h
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the LM35 Temperature Sensor Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to initialize the LM35 sensor and read the temperature data.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _LM35_INTERFACE_H_
#define _LM35_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void LM35_init(void);
u8 LM35_get_temperature(void);

#endif
