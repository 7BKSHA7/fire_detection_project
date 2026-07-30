#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/REG_MAP.h"

#include "LM35_config.h"
#include "LM35_interface.h"
#include "LM35_private.h"

void LM35_init(void){

    // set the LM35 pin as input 
    DIO_set_pin_direction(LM35_Port,LM35_Pin,input);
    
    // initialize the ADC 
    ADC_Init(ADC_AVCC);

    // set right adjust result
    ADC_Adjust(ADC_RIGHT_ADJUST);

}

u8 LM35_get_temperature(void){

    u16 adc_value = 0;
    u32 milli_volt = 0;
    u8  temp_celsius = 0;

    // read the ADC channel connected to LM35
    ADC_Channel(LM35_ADC_Channel);

    // start single conversion
    ADC_StartConversion(ADC_SINGLE_CONVERSION);

    // read the digital result
    adc_value = ADC_ReadResult();

    // convert digital result to voltage in millivolt  
    milli_volt = ((u32)adc_value * LM35_Vref) / LM35_ADC_Resolution;

    // convert mv value to celsius (10mv = 1 c) 
    temp_celsius = milli_volt / 10;

    return temp_celsius;

}