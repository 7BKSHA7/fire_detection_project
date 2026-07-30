
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_Init(u8 Mode) 
{
    switch(Mode)
    {
    case ADC_AREF:
    ClearBit(ADMUX, ADC_REFS0);
    ClearBit(ADMUX, ADC_REFS1);
    break;

    case ADC_AVCC:
    SetBit(ADMUX, ADC_REFS0);
    ClearBit(ADMUX, ADC_REFS1);
    break;

    case ADC_Internal:
    SetBit(ADMUX, ADC_REFS0);
    SetBit(ADMUX, ADC_REFS1);
    break;

    default:
    break;
    }
    ADC_Prescaler(ADC_Prescaler_64); //8MHZ SO ION NEED TO MAKE IT 8MHZ IN MIAN
    SetBit(ADCSRA, ADC_ADEN);
}

void ADC_Enable()
{
    SetBit(ADCSRA,ADC_ADEN);
}

void ADC_Disable()
{
    ClearBit(ADCSRA,ADC_ADEN);
}

void ADC_Adjust(u8 Adjust_Direction)
{
     if(Adjust_Direction== ADC_RIGHT_ADJUST)
     {
     ClearBit(ADMUX, ADC_ADLAR);
     }
     else if(Adjust_Direction== ADC_LEFT_ADJUST)
     {
     SetBit(ADMUX, ADC_ADLAR);
     }
}

void ADC_Channel(u8 Channel)
{
    ADMUX = (ADMUX & ~ADC_ChannelMask) | Channel;
    /*
       ChannelMask=0x1F after ~ ChannelMask will= 0xE0
       then i will and it with ADMUX to delete MUX4:0 Bits
       then or with channel to write its value
    */
}

void ADC_StartConversion(u8 Mode)
{
    if(Mode==ADC_SINGLE_CONVERSION)
    {
    SetBit(ADCSRA,ADC_ADSC);
    }
}


void ADC_Prescaler(u8 Prescaler)
{
    ADCSRA=(ADCSRA&~ADC_PrescalerMask)|Prescaler;
    /*
       PrescalerMask=0x07 after ~ PrescalerMask will= 0xF8
       then i will and it with ADCSRA to delete  ADPS2:0 Bits
       then or with Prescaler to write its value
    */
}

u16 ADC_ReadResult(void)
{ 
    SetBit(ADCSRA, ADC_ADSC); //to start conversion
    /*CUZ I USE POLLING I NEED TO CHECK FLAG THEN CLEAR IT*/
    while(ReadBit(ADCSRA, ADC_ADIF) == 0); //CHECK FLAG
    SetBit(ADCSRA, ADC_ADIF);   // CLEAR FLAG

     u16 Data = 0;
     Data = ADCL;   //right adjust
     Data |= ((u16)ADCH << 8);
     return Data;
}
