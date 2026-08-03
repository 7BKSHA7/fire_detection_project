/**
 * @file      MQ2_Interface.h
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the MQ2 Smoke/Gas Sensor Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to initialize the MQ2 sensor and read the smoke concentration data.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef MQ2_INTERFACE_H
#define MQ2_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

void MQ2_init();
u16 MQ2_read_smoke();

#endif /* MQ2_INTERFACE_H */
