/**
 * @file      Buzzer_Program.c
 * @author    Youssef
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the Buzzer Driver.
 * @details   This file contains the initialization function for the buzzer and 
 *            functions to control its state (Turn On, Turn Off, and Toggle).
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../MCAL/REG_MAP.h"

#include "BUZZER_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

void BUZZER_init(void)
{
    DIO_set_pin_direction(BUZZER_PORT, BUZZER_PIN, output);
    DIO_set_pin_value(BUZZER_PORT, BUZZER_PIN, low); 
}

void BUZZER_On(void)
{
    DIO_set_pin_value(BUZZER_PORT, BUZZER_PIN, high);
}

void BUZZER_Off(void)
{
    DIO_set_pin_value(BUZZER_PORT, BUZZER_PIN, low);
}

void BUZZER_Toggle(void)
{
    u8 current = DIO_get_pin_value(BUZZER_PORT, BUZZER_PIN);
    DIO_set_pin_value(BUZZER_PORT, BUZZER_PIN, !current);
}
