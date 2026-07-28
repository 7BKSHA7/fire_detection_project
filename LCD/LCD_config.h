#ifndef _LCD_CONFIG_C_
#define _LCD_CONFIG_C_

#include "../../MCAL/DIO/DIO_private.h"

#define LCD_RSPin      Dio_pin2 // Register_Select pin + group
#define LCD_RSGroup    Dio_groupC

 // RW(read_write) will be with ground

#define LCD_EPin       Dio_pin3 //enable pin + group
#define LCD_EGroup     Dio_groupC

#define LCD_DataGroup  Dio_groupC //DataGroup: its for pins for 8bit Modetype(D0 : D7)
                                 //                for pins for 4bit Modetype(D4 : D7)


#endif