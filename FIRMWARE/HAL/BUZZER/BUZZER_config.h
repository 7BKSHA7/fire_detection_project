/**
 * @file      Buzzer_Config.h
 * @author    Youssef
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the Buzzer Driver.
 * @details   This file contains user-configurable parameters such as the hardware 
 *            port and pin to which the buzzer is connected. Users can modify 
 *            these values based on the hardware schematic without touching the core logic.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef BUZZER_CONFIG_H
#define BUZZER_CONFIG_H

#include "../../MCAL/DIO/DIO_private.h"

#define BUZZER_PORT   Dio_groupB
#define BUZZER_PIN    Dio_pin7

#endif /* BUZZER_CONFIG_H */
