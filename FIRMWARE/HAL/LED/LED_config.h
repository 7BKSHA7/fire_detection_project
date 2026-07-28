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