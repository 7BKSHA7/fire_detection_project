#include "UART_interface.h"

static void (*PF_UartRX)(u16)= Null; 
static void (*PF_UartTX)(void)= Null; 
static void (*PF_UartRE)(void)= Null; 

static Uart_Config_t GlobaleUart_Config = {0};

// Initialization API
void UART_Init(Uart_Config_t Uart_Config)
{
    u8 Local_UCSRCValue = 0 ;
    GlobaleUart_Config = Uart_Config ; 

    // UCSRC -> Register Select must be 1 
    SetBit (Local_UCSRCValue ,Uart_URSEL);

    // 1- Mode Select 
    if(Uart_Config.ModeSelect==Uart_AsynchronousMode)
    {
        ClearBit(Local_UCSRCValue,Uart_UMSEL);
    }
    else if (Uart_Config.ModeSelect==Uart_SynchronousMode)
    {
        SetBit(Local_UCSRCValue,Uart_UMSEL);
    }
    //2-Parity 
    if (Uart_Config.ParitySelect==Uart_ParityEven)
    {
        SetBit(Local_UCSRCValue,Uart_UPM1);
        ClearBit(Local_UCSRCValue,Uart_UPM0);
    }
    else if (Uart_Config.ParitySelect==Uart_ParityOdd)
    {
        SetBit(Local_UCSRCValue,Uart_UPM0);
        SetBit(Local_UCSRCValue,Uart_UPM1);
    }
    else //Disabled 
    {
        ClearBit(Local_UCSRCValue,Uart_UPM0);
        ClearBit(Local_UCSRCValue,Uart_UPM1); 
    }
    //3-Stop 
    if(Uart_Config.StopBitSelect==Uart_1StopBit)
    {
        ClearBit(Local_UCSRCValue,Uart_USBS);
    }
    else if(Uart_Config.StopBitSelect==Uart_2StopBit)
    {
        SetBit(Local_UCSRCValue,Uart_USBS);
    }
    //4- Character Size 
    if(Uart_Config.SizeCharacterSelect==Uart_5BitSize)
    {
        ClearBit(Local_UCSRCValue,Uart_UCSZ0);
        ClearBit(Local_UCSRCValue,Uart_UCSZ1);
        ClearBit(UCSRB,Uart_UCSZ2);
            
    }
    else if(Uart_Config.SizeCharacterSelect==Uart_6BitSize)
    {
        SetBit(Local_UCSRCValue,Uart_UCSZ0);
        ClearBit(Local_UCSRCValue,Uart_UCSZ1);
        ClearBit(UCSRB,Uart_UCSZ2);            
    }
    else if(Uart_Config.SizeCharacterSelect==Uart_7BitSize)
    {
        ClearBit(Local_UCSRCValue,Uart_UCSZ0);
        SetBit(Local_UCSRCValue,Uart_UCSZ1);
        ClearBit(UCSRB,Uart_UCSZ2);            
    }
    else if(Uart_Config.SizeCharacterSelect==Uart_8BitSize)
    {
        SetBit(Local_UCSRCValue,Uart_UCSZ0);
        SetBit(Local_UCSRCValue,Uart_UCSZ1);
        ClearBit(UCSRB,Uart_UCSZ2);            
    }
    else if(Uart_Config.SizeCharacterSelect==Uart_9BitSize)
    {
        SetBit(Local_UCSRCValue,Uart_UCSZ0);
        SetBit(Local_UCSRCValue,Uart_UCSZ1);
        SetBit(UCSRB,Uart_UCSZ2);            
    }
    UCSRC= Local_UCSRCValue;
    //5- Speed Mode 
    if(Uart_Config.SpeedMode==Uart_NormalSpeed)
    {
        ClearBit(UCSRA,Uart_U2X);
    }
    else if(Uart_Config.SpeedMode==Uart_DoubleSpeed)
    {
        SetBit(UCSRA,Uart_U2X);
    }
    //6-BaudRate 
    u16 Local_UBRRValue = 0 ; 
    if(Uart_Config.SpeedMode==Uart_DoubleSpeed)
    {
        Local_UBRRValue = (FCPU / (8UL * Uart_Config.BaudRate))-1 ;   
    }
    else if(Uart_Config.SpeedMode==Uart_NormalSpeed)
    {
        Local_UBRRValue = (FCPU / (16UL * Uart_Config.BaudRate))-1 ;   
    }
    UBRRL= (Local_UBRRValue);    //1 0 0 1 0 1 1 0
    UBRRH= (Local_UBRRValue>>8); //0 0 0 0 0 1 1 1 
    //Local_UBRRValue 
    // 0 0 0 0 0 1 1 1
    // 1 0 0 1 0 1 1 0 
    //(Local_UBRRValue>>8)
    // 0 0 0 0 0 0 0 0 
    // 0 0 0 0 0 1 1 1
    
    // Interrupt 
    UART_DisableRXInterrupt();
    UART_DisableTXInterrupt();
    UART_DisableREInterrupt();

    if(Uart_Config.InterruptSelect == Uart_InterruptRxOnly)
    {
        UART_EnableRXInterrupt();
    }
    else if(Uart_Config.InterruptSelect == Uart_InterruptTxOnly)
    {
        UART_EnableTXInterrupt();
    }
    else if(Uart_Config.InterruptSelect == Uart_InterruptUdreOnly)
    {
        UART_EnableREInterrupt();
    }
    else if(Uart_Config.InterruptSelect == Uart_InterruptRxTx)
    {
        UART_EnableRXInterrupt();
        UART_EnableTXInterrupt();
    }
    else if(Uart_Config.InterruptSelect == Uart_InterruptRxUdre)
    {
        UART_EnableRXInterrupt();
        UART_EnableREInterrupt();
    }
    else if(Uart_Config.InterruptSelect == Uart_InterruptTxUdre)
    {
        UART_EnableTXInterrupt();
        UART_EnableREInterrupt();
    }
    else if(Uart_Config.InterruptSelect == Uart_InterruptAll)
    {
        UART_EnableTXInterrupt();
        UART_EnableRXInterrupt();
        UART_EnableREInterrupt();
    }

    // Enable 
    if(Uart_Config.EnbaleSelect == Uart_EnableRxOnly)
    {
        UART_EnableRX();
        UART_DisableTX();
    }
    else if(Uart_Config.EnbaleSelect == Uart_EnableTxOnly)
    {
        UART_EnableTX();
        UART_DisableRX();
    }
    else if(Uart_Config.EnbaleSelect == Uart_EnableRxAndTx)
    {
        UART_EnableRX();
        UART_EnableTX();
    }
}

// Polling (Blocking)API
void UART_SendBytePolling(u16 Data)
{   // 0 1 1 1 1 0 0 1 0 
    // 1 1 1 1 1 0 0 1 0 
    // 1- Make Sure the Regiser is Empty 
    while(ReadFlag(UCSRA,Uart_UDRE)==FlagDown);
    // 2- Check on size 
    if(GlobaleUart_Config.SizeCharacterSelect==Uart_9BitSize)
    {
        //TXB8 -> UCSRB
        ClearBit(UCSRB,Uart_TXB8);
        if(ReadBit(Data,8)==1) 
        {
            SetBit(UCSRB,Uart_TXB8);
        }
    }
    // 3- Update the UDR 
    UDR=(u8)Data;
}
u16 UART_ReceiveBytePolling()
{
    u16 LocalData = 0;
    while(ReadFlag(UCSRA,Uart_RXC)==FlagDown);
    if(GlobaleUart_Config.SizeCharacterSelect==Uart_9BitSize)
    {
        if(ReadBit(UCSRB,Uart_RXB8)==1)
        {
            SetBit(LocalData,8);
        }
    }
    LocalData|=UDR;
    return UDR;
}
void UART_SendStringPolling(u8* String)
{
    u8 LocalCount = 0;
    while(String[LocalCount] != NullChar)
    {
        UART_SendBytePolling(String[LocalCount]);
        LocalCount++;
    }
}
void UART_ReceiveStringPolling(u8* Buffer, u8 Terminator)
{
    u8 LocalCount = 0;
    if(Buffer!=Null)
    {
        Buffer[LocalCount] = (u8)UART_ReceiveBytePolling();
        while(Buffer[LocalCount] != Terminator)
        {
            LocalCount++;
            Buffer[LocalCount] = (u8)UART_ReceiveBytePolling();
        }
        Buffer[LocalCount] = '\0';
    }

}
void UART_SendBufferPolling(u8 * Buffer , u16 Length)
{
    u16 LocalCount = 0;
    for(LocalCount = 0; LocalCount < Length; LocalCount++)
    {
        UART_SendBytePolling(Buffer[LocalCount]);
    }
}//Raw Data 

// Driver Control API
void UART_EnableRX()
{
    //UCSRB
    SetBit(UCSRB,Uart_RXEN);
}
void UART_EnableTX()
{
    SetBit(UCSRB,Uart_TXEN);
}
void UART_DisableRX()
{
    ClearBit(UCSRB,Uart_RXEN);
}
void UART_DisableTX()
{
    ClearBit(UCSRB,Uart_TXEN);
}



// Interrupt API
void UART_SendByteInterrupt(u16 Data)
{

}
void UART_EnableRXInterrupt()
{
    // UCSRB
    SetBit(UCSRB,Uart_RXCIE);
}
void UART_EnableTXInterrupt()
{
    // UCSRB
    SetBit(UCSRB,Uart_TXCIE);
}
void UART_EnableREInterrupt()
{
    // UCSRB 
    SetBit(UCSRB,Uart_UDRIE); 
}
void UART_DisableRXInterrupt()
{
    // UCSRB 
    ClearBit(UCSRB,Uart_RXCIE);
}
void UART_DisableTXInterrupt()
{
    // UCSRB 
    ClearBit(UCSRB,Uart_TXCIE);
}
void UART_DisableREInterrupt()
{
    // UCSRB 
    ClearBit(UCSRB,Uart_UDRIE);
}



void UART_SetRXCallback(void (*PF)(u16))
{
    if(PF!=Null)
    {
        PF_UartRX=PF;
    }
}
void UART_SetTXCallback(void (*PF)(void))
{
    if(PF!=Null)
    {
        PF_UartTX=PF;
    }
}
void UART_SetRECallback(void (*PF)(void))
{
    if(PF!=Null)
    {
        PF_UartRE=PF;
    }
}


// RX Complete
void __vector_13(void)
{
    if(PF_UartRX!=Null)
    {
        u16 LocalData = 0 ;
        //Check on the Size of character 
        // if Size less than 9  -> LocalData = UDR;
        // if Size  == 9
        // Read the RXB8 Update in LocalData 
        // Update the UDR 
        PF_UartRX(LocalData);
    }

}
// TX Complete
void __vector_15(void)
{
    if(PF_UartTX!=Null)
    {
        PF_UartTX();
    }
}

void __vector_14(void)
{
    if(PF_UartRE!=Null)
    {
        PF_UartRE();
    }
}