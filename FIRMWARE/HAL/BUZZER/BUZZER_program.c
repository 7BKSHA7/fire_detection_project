/**
* @file    Buzzer_Program.c
* @author (developer)  
* @author (reviewer)
* @brief  
* @details
* @version
* @date
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