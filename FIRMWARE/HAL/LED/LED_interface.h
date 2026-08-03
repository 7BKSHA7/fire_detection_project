/**
 * @file      LED_interface.h
 * @author    Rohayem
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the LED Driver for the Fire Detection System.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to initialize and control the state of the system's LEDs 
 *            based on the fire detection logic.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "LED_private.h"
#include "LED_config.h"
void LED_initialization();
void LED_SetStatus(u8 led_state);

#endif
