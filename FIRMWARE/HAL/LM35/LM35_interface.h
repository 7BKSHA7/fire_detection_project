/**
* @file    LM35_Interface.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

#include "LM35_config.h"
#include "LM35_private.h"

void LM35_init();
u8 LM35_read_temp();

#endif /* LM35_INTERFACE_H */
