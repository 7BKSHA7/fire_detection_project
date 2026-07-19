#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/REG_MAP.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

/* beshoy
    the port is the group which is a b c d 
    the pin is the pin number from 0 to 7
    the direction is 1 or 0  
    0 is input
    1 is output 
*/

// to change 1 pin direction to output(1) or input (0)
void DIO_set_pin_direction(u8 port , u8 pin , u8 direction)
{
    switch(port) // to check on each port 
    {
        case DIO_portA :
            if(direction == output)
            {
                SetBit(DDRA , pin);
            }
            else 
            {
                ClearBit(DDRA , pin);
            }
            break;
        case DIO_portB :
            if(direction == output)
            {
                SetBit(DDRB , pin);
            }
            else 
            {
                ClearBit(DDRB , pin);
            }
            break;
        case DIO_portC :
            if(direction == output)
            {
                SetBit(DDRC , pin);
            }
            else 
            {
                ClearBit(DDRC , pin);
            }
            break;
        case DIO_portD :
            if(direction == output)
            {
                SetBit(DDRD , pin);
            }
            else 
            {
                ClearBit(DDRD , pin);
            }
            break;

    }
}
// to set only 1 pin to make sure if we want it high(1) or low(0)
void DIO_set_pin_value(u8 port , u8 pin , u8 value)
{
    switch(port)
    {
        case DIO_portA :
            if(value == DIO_high)
            {
                SetBit(PORTA , pin);
            }
            else 
            {
                ClearBit(PORTA , pin);
            }
            break;
        case DIO_portB :
            if(value == DIO_high)
            {
                SetBit(PORTB , pin);
            }
            else 
            {
                ClearBit(PORTB , pin);
            }
            break;
        case DIO_portC :
            if(value == DIO_high)
            {
                SetBit(PORTC , pin);
            }
            else 
            {
                ClearBit(PORTC , pin);
            }
            break;
        case DIO_portD :
            if(value == DIO_high)
            {
                SetBit(PORTD , pin);
            }
            else 
            {
                ClearBit(PORTD , pin);
            }
            break;

    }
}
// to read the value directily 
u8 DIO_get_pin_value(u8 port , u8 pin)
{
    switch(port)
    {
        case DIO_portA :
            return ReadBit(PINA , pin);
            break;
        case DIO_portB :
            return ReadBit(PINB , pin);
            break;
        case DIO_portC :
            return ReadBit(PINC , pin);
            break;
        case DIO_portD :
            return ReadBit(PIND , pin);
            break;
        default :
            return 0 ;
            break; 
    }
}
// to set the whole port at once by setting direction so 0xFF or 0xF0 anything
void DIO_set_port_direction(u8 port , u8 direction)
{
    switch(port) // to check on each port 
    {
        case DIO_portA :
            DDRA = direction;
            break;
        case DIO_portB :
            DDRB = direction;
            break;
        case DIO_portC :
            DDRC = direction;
            break;
        case DIO_portD :
            DDRD = direction;
            break;
    }
}


void DIO_set_port_value(u8 port , u8 value)
{
    switch(port) // to check on each port 
    {
        case DIO_portA :
            PORTA = value;
            break;
        case DIO_portB :
            PORTB = value;
            break;
        case DIO_portC :
            PORTC = value;
            break;
        case DIO_portD :
            PORTD = value;
            break;
    }
}

u8 DIO_get_port_value(u8 port)
{
    switch(port)
    {
        case DIO_portA :
            return PINA;
            break;
        case DIO_portB :
            return PINB;
            break;
        case DIO_portC :
            return PINC;
            break;
        case DIO_portD :
            return PIND;
            break;
        default :
            return 0 ;
            break; 
    }
}
