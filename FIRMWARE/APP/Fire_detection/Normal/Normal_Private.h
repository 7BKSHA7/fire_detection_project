/**
 * @file      Normal_Private.h
 * @author    Ali
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the Normal Fire State.
 * @details   This file is reserved for internal macros, private constants, 
 *            and internal states specific to the Normal state logic.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef NORMAL_PRIVATE_H
#define NORMAL_PRIVATE_H

/* internal helper, not exposed to other layers */

#include "../../../LIB/STD_TYPES.h"

static u8 NORMAL_CheckTransition(u8 temp, u8 smoke);

#endif /* NORMAL_PRIVATE_H */
