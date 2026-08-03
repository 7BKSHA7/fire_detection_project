/**
 * @file      Button_Program.c
 * @author    Youssef
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the Button Driver.
 * @details   This file contains the initialization function for the button (enabling internal pull-up) 
 *            and the function to read the current state of the button (Pressed / Released).
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../MCAL/REG_MAP.h"

#include "BUTTON_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"


void BUTTON_init(void)
{
    DIO_set_pin_direction(BUTTON_PORT, BUTTON_PIN, input);
    DIO_set_pin_value(BUTTON_PORT, BUTTON_PIN, high); 
}


u8 BUTTON_GetState(void)
{
    u8 pinLevel = DIO_get_pin_value(BUTTON_PORT, BUTTON_PIN);

    if (pinLevel == low) 
    {
        return BUTTON_PRESSED;
    }
    else
    {
        return BUTTON_RELEASED;
    }
}

