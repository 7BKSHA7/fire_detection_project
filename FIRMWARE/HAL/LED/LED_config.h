/**
 * @file      LED_config.h
 * @author    Rohayem
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Configuration file for the LED Driver.
 * @details   This file contains user-configurable parameters such as the hardware 
 *            ports and pins to which the Green, Yellow, and Red LEDs are connected.
 *            Hardware Note: LEDs are configured in a source connection (Active High).
 *            The LED's anode is connected to the MCU pin, and the cathode goes to ground.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _LED_CONFIG_H_
#define _LED_CONFIG_H_

#include "../../MCAL/DIO/DIO_private.h"
// LEDs connected in source connection
// The LED's anode is connected to the MCU pin, and the cathode goes to ground

//here i set place for each led in group B + its own pin
#define GREEN_LED_PORT   Dio_groupB
#define GREEN_LED_PIN    Dio_pin6

#define YELLOW_LED_PORT  Dio_groupB
#define YELLOW_LED_PIN   Dio_pin2

#define RED_LED_PORT     Dio_groupB
#define RED_LED_PIN      Dio_pin1

#endif
