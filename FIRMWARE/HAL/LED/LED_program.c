#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/REG_MAP.h"

#include <util/delay.h>

#include "LED_interface.h"

#include "../../MCAL/DIO/DIO_interface.h"

void LED_initialization() //to initialization every led with its pin + make them output
{
    DIO_set_pin_direction(GREEN_LED_PORT , GREEN_LED_PIN , output);
    DIO_set_pin_direction(YELLOW_LED_PORT, YELLOW_LED_PIN, output);
    DIO_set_pin_direction(RED_LED_PORT , RED_LED_PIN , output);
}

void LED_SetStatus(u8 led_state)
{
    switch(led_state)                                            //switch case to check which led will work
    {                                                           //high 1 for on , low 0 for off
        case LED_STATE_NORMAL:
            DIO_set_pin_value(GREEN_LED_PORT , GREEN_LED_PIN , high);
            DIO_set_pin_value(YELLOW_LED_PORT, YELLOW_LED_PIN, low);
            DIO_set_pin_value(RED_LED_PORT , RED_LED_PIN , low);
            break;

        case LED_STATE_WARNING:
            DIO_set_pin_value(GREEN_LED_PORT , GREEN_LED_PIN , low);
            DIO_set_pin_value(YELLOW_LED_PORT, YELLOW_LED_PIN, high);
            DIO_set_pin_value(RED_LED_PORT , RED_LED_PIN , low);
            break;

        case LED_STATE_NOTICE_FIRE:
            DIO_set_pin_value(GREEN_LED_PORT , GREEN_LED_PIN , low);
            DIO_set_pin_value(YELLOW_LED_PORT, YELLOW_LED_PIN, low);
            DIO_set_pin_value(RED_LED_PORT , RED_LED_PIN , high);
            break;

        case LED_STATE_EMERGENCY:
            DIO_set_pin_value(GREEN_LED_PORT , GREEN_LED_PIN , low);
            DIO_set_pin_value(YELLOW_LED_PORT, YELLOW_LED_PIN, low);

            ToggleBit(PORTB, RED_LED_PIN); // to make the red led BLinking
            _delay_ms(500);
            break;

        default:
            DIO_set_pin_value(GREEN_LED_PORT , GREEN_LED_PIN , low);
            DIO_set_pin_value(YELLOW_LED_PORT, YELLOW_LED_PIN, low);
            DIO_set_pin_value(RED_LED_PORT , RED_LED_PIN , low);
            break;
    }
}
