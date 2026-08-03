/**
 * @file      System_Private.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the core System application layer.
 * @details   This file contains internal macros representing the different 
 *            states of the Fire Alarm System (State Machine) and acknowledgment 
 *            flags used by the system logic.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _SYSTEM_PRIVATE_H_
#define _SYSTEM_PRIVATE_H_

// states 
#define  NORMAL     0
#define  WARNING    1
#define  FIRE_ALARM 2
#define  EMERGENCY  3

// acknowledged
#define ACK      1
#define NOT_ACK  0



#endif /* SYSTEM_PRIVATE_H */
