#include "GIE_Interface.h"


void GIE_Enable()
{
    SetBit(SREG,I_Bit);
}
void GIE_Disable()
{
    ClearBit(SREG,I_Bit);
}