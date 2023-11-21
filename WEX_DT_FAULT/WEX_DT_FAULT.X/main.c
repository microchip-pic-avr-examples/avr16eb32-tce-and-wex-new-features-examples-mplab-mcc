#include "mcc_generated_files/system/system.h"
#include <util/delay.h>

void Create_Fault(void)
{
    /* Fault creation, repeat in main loop to see it on LogicA. This is an event
     * generated using the logic level of PORTD Pin 5 */
    IO_PD5_SetHigh();
}

void Clear_Fault(void)
{
    /* Clear fault condition using a software command and disable the fault condition */
    IO_PD5_SetLow();
    WEX0_SoftwareCommand(WEX_CMD_FAULTCLR_gc); 
}

int main(void)
{
    SYSTEM_Initialize();
    

    while(1)
    {
        Create_Fault();
        _delay_ms(100);
        Clear_Fault();
        _delay_ms(100);
    }    
}