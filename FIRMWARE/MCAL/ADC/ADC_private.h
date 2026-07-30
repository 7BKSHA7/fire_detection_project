#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*HERE ADMUX BITS*/
#define ADC_MUX0      0  // 0:4 channels selection
#define ADC_MUX1      1
#define ADC_MUX2      2
#define ADC_MUX3      3
#define ADC_MUX4      4
#define ADC_ADLAR     5 /*if =0 right adjust__if =1 left adjust__LEFT IS BETTER IF I ONLY NEED 8 BITS (RESULT=ADCH)*/
#define ADC_REFS0     6    //7_6 refrence selection bits
#define ADC_REFS1     7   // 0 0 AREF   0 1 AVCC ,  1 0 DONCARE  ,  1 1 INTERNAL 2.56V

#define ADC_AREF          0
#define ADC_AVCC          1
#define ADC_Internal      2

#define ADC_RIGHT_ADJUST  0
#define ADC_LEFT_ADJUST   1

#define ADC_SINGLE_CONVERSION  0
#define ADC_FREE_RUNNING       1

#define ADC_Channel0       0 
#define ADC_Channel1       1
#define ADC_Channel2       2
#define ADC_Channel3       3
#define ADC_Channel4       4
#define ADC_Channel5       5
#define ADC_Channel6       6
#define ADC_Channel7       7

#define ADC_Prescaler_2      0
#define ADC_Prescaler_4      2
#define ADC_Prescaler_8      3
#define ADC_Prescaler_16     4
#define ADC_Prescaler_32     5
#define ADC_Prescaler_64     6
#define ADC_Prescaler_128    7

/*HERE ADSCRA BITS*/
#define ADC_ADPS0     0
#define ADC_ADPS1     1
#define ADC_ADPS2     2
#define ADC_ADIE      3 //ADC interrupt enable ==1 enable__==0 disable
#define ADC_ADIF      4 //ADC interrupt flag to delete it ==1
#define ADC_ADATE     5 //ADC auto trigglr ==1 auto triggle mode__==0 single conv mode
#define ADC_ADSC      6 //ADC start conv__==1 back bit to 0 automatic
#define ADC_ADEN      7 //ADC==1 for enable __==0 for disable

/*HERE SFIOR BITS*/
#define ADC_ADTS0     5 //triggle source selection (000)FreeRunning   (010)External1Interrupt
#define ADC_ADTS1     6 //(011)timer0ComoareMatch  (100)Timer0OverFlow
#define ADC_ADTS2     7

#define ADC_ChannelMask      0x1F    // 00011111
#define ADC_PrescalerMask    0x07    // 00000111
#define ADC_ADTSMask         0xE0    // 11100000

#endif