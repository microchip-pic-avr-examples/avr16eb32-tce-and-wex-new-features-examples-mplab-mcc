/* Maximum value for duty cycle */
#define MAX_DCY (0x20)  


#include "mcc_generated_files/system/system.h"
#include <util/delay.h>

void Duty_Cycle_Update(void)
{
    /* Start with a duty cycle value of 10 peripheral clocks */
    static uint8_t dcy = 10;
    
    /* Increase duty cycle with one peripheral clock on each overflow interrupt */
    dcy++;
    
    /* Check if the duty cycle value has reached maximum */
    if(dcy > MAX_DCY)
        dcy = 10;
    
    /* update the values from CMP channels */
    TCE0_CompareAllChannelsBufferedSet(dcy, dcy + 1, dcy + 2, dcy + 3);
}

int main(void)
{
    SYSTEM_Initialize();
    TCE0_OverflowCallbackRegister(Duty_Cycle_Update);

    while(1)
    {
        TCE0_HighResSet(TCE_HREN_OFF_gc);
        IO_PD5_Toggle();
        _delay_ms(2000);
        TCE0_HighResSet(TCE_HREN_4X_gc);
        IO_PD5_Toggle();
        _delay_ms(2000);
        TCE0_HighResSet(TCE_HREN_8X_gc);
        IO_PD5_Toggle();
        _delay_ms(2000);
    }    
}