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

/**
 * @brief  Initializes the button pin.
 * @details Sets the button pin as an input and activates the internal pull-up resistor.
 * @param  void
 * @return void
 */
void BUTTON_init(void)
{
    DIO_set_pin_direction(BUTTON_PORT, BUTTON_PIN, input);
    DIO_set_pin_value(BUTTON_PORT, BUTTON_PIN, high); 
}

/**
 * @brief  Gets the current state of the button.
 * @details Reads the digital value of the button pin to determine if it is pressed or released 
 *          (Active Low configuration).
 * @param  void
 * @return u8 Returns BUTTON_PRESSED if the button is pressed, or BUTTON_RELEASED if it is released.
 */
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

