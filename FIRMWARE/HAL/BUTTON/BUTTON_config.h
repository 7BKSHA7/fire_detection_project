/**
 * @file      Button_Config.h
 * @author    Youssef
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the Button Driver.
 * @details   This file contains user-configurable parameters such as the hardware 
 *            port and pin to which the button is connected. Users can modify 
 *            these values based on the hardware schematic.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef BUTTON_CONFIG_H
#define BUTTON_CONFIG_H

#include "../../MCAL/DIO/DIO_private.h"

#define BUTTON_PORT   Dio_groupB
#define BUTTON_PIN    Dio_pin0

#endif /* BUTTON_CONFIG_H */
