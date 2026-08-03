/**
 * @file      Fire_Interface.h
 * @author    Ali
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface for the Fire State.
 * @details   This file contains the function prototypes and public APIs 
 *            for the Fire state. It includes the Normal interface to 
 *            share the global FIRE_STATE_t enumeration.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef FIRE_INTERFACE_H
#define FIRE_INTERFACE_H

#include "../Normal/Normal_Interface.h"
#include "Fire_Private.h"
#include "Fire_Config.h"

u8 FIRE_voidRun(void);

#endif /* FIRE_INTERFACE_H */
