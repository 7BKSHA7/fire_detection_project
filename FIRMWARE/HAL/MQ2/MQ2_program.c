/**
 * @file      MQ2_program.c
 * @author    Moaaz
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the MQ2 Smoke/Gas Sensor Driver.
 * @details   This file contains the initialization function for the MQ2 sensor 
 *            and the core logic to read the analog signal, process it through 
 *            the ADC, and calculate the output voltage representing smoke concentration.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/REG_MAP.h"

#include "MQ2_config.h"
#include "MQ2_interface.h"
#include "MQ2_private.h"

void MQ2_init(void){

    // set the MQ2 pin as input 
    DIO_set_pin_direction(MQ2_Port,MQ2_Pin,input);
    
    // initialize the ADC 
    ADC_Init(ADC_AVCC);

    // set right adjust result
    ADC_Adjust(ADC_RIGHT_ADJUST);

}

u16 MQ2_read_smoke(void){

    u16 adc_value = 0;
    u16 milli_volt = 0;

    // read the ADC channel connected to MQ2
    ADC_Channel(MQ2_ADC_Channel);

    // start single conversion
    ADC_StartConversion(ADC_SINGLE_CONVERSION);

    // read the digital result
    adc_value = ADC_ReadResult();

    // convert digital result to voltage in millivolt  
    milli_volt = ((u32)adc_value * MQ2_Vref) / MQ2_ADC_Resolution;

    return milli_volt;

}
