/**
* @file    Normal_Config.h
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
* @copyright Copyright (c) 2026, Gestell Company
*/

#ifndef NORMAL_CONFIG_H
#define NORMAL_CONFIG_H

#ifndef NORMAL_CONFIG_H
#define NORMAL_CONFIG_H

#include "../../../LIB/STD_TYPES.h"

/* Thresholds that decide when we must LEAVE the normal state
 * and hand control to the warning state.
 * Tune these to your MQ2 / LM35 calibration.
 */
#define NORMAL_TEMP_THRESHOLD      45   // degrees C, above this -> warning
#define NORMAL_SMOKE_THRESHOLD     70   // smoke reading, above this -> warning


#endif /* NORMAL_CONFIG_H */
