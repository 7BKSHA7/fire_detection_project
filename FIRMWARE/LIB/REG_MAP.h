#ifndef _ATMEGA32REGMAP_H_
#define _ATMEGA32REGMAP_H_

#include "STD_TYPES.h"

// ========================================//
// -----------------DIO--------------------//
// ========================================//
/*

the dio is the Digtal input output 

DDR  : (data direction register)  it tells us if its gonna become output or input
PORT : it allows us to output a value 
PIN  : it allwos us to recive input
*/

// gorup A
#define DDRA           *((volatile u8*)0x3A)
#define PORTA          *((volatile u8*)0x3B)
#define PINA           *((volatile u8*)0x39)
// gorup B
#define PORTB          *((volatile u8*)0x38)
#define DDRB           *((volatile u8*)0x37)
#define PINB           *((volatile u8*)0x36)
// gorup C
#define DDRC           *((volatile u8*)0x34)
#define PORTC          *((volatile u8*)0x35)
#define PINC           *((volatile u8*)0x33)
// gorup D
#define DDRD           *((volatile u8*)0x31)
#define PORTD          *((volatile u8*)0x32)
#define PIND           *((volatile u8*)0x30)



#endif 