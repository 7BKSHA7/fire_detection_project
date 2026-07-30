/**
* @file    System_Private.h
* @author (beshoy)  
* @author (beshoy)
* @brief  
* @details
* @version
* @date
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

typedef struct
{
    // sensor values 
    u8 temprature ;
    u8 smoke ;

    // ACK acknowledged
    u8 acknowledged ;

    // state
    u8 current_state;
    u8 prev_state;

}system_manager_t;

extern system_manager_t config;

#endif /* SYSTEM_PRIVATE_H */
