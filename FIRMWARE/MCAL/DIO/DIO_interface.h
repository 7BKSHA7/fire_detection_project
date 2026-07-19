#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "../LIB/STD_TYPES.h"

/*
void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void DIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8   DIO_GetPinValue(u8 Port, u8 Pin);

void DIO_SetPortDirection(u8 Port, u8 Direction);
void DIO_SetPortValue(u8 Port, u8 Value);
u8   DIO_GetPortValue(u8 Port);

void DIO_TogglePin(u8 Port, u8 Pin);
*/

void DIO_set_pin_direction(u8 port , u8 pin , u8 direction);
void DIO_set_pin_value(u8 port , u8 pin , u8 value);
u8 DIO_get_pin_value(u8 port , u8 pin);

void DIO_set_port_direction(u8 port , u8 direction);
void DIO_set_port_value(u8 port , u8 value);
u8 DIO_get_port_value(u8 port);


#endif