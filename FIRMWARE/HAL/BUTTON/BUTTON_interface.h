/**
 * @file      Button_Interface.h
 * @author    Youssef
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the Button Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to initialize and read the state of the Button module.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../../LIB/STD_TYPES.h"
#include "BUTTON_config.h"
#include "BUTTON_private.h"

void BUTTON_init();
u8   BUTTON_GetState(void);

#endif /* BUTTON_INTERFACE_H */
