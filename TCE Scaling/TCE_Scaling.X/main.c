#define DUTY_CYCLE_20_PERCENT           (0x1999)
#define DUTY_CYCLE_40_PERCENT           (0x3333)
#define DUTY_CYCLE_60_PERCENT           (0x4CCC)
#define DUTY_CYCLE_80_PERCENT           (0x660C)
#define AMPLITUDE_MAX_DCY_50_PERCENT    (0x4000)
#define AMPLITUDE_MAX_DCY_75_PERCENT    (0x6000)
#define AMPLITUDE_MAX_DCY_100_PERCENT   (0x8000)
#define AMPLITUDE_MAX_DCY_150_PERCENT   (0xC000)

#include "mcc_generated_files/system/system.h"
#include <util/delay.h>

void Scale_Mode_Change(uint8_t scale_mode)
{
    /* Set the scale mode */
    TCE0_ScaleModeSet(scale_mode);
    
    /* Set the amplitude levele so that the maximum duty cycle possible is 50% */
    TCE0_AmplitudeSet(AMPLITUDE_MAX_DCY_50_PERCENT);
    
    /* Update the values of CMP registre so that the amplitude change takes place */
    TCE0_CompareAllChannelsBufferedSet(DUTY_CYCLE_20_PERCENT, DUTY_CYCLE_40_PERCENT, DUTY_CYCLE_60_PERCENT, DUTY_CYCLE_80_PERCENT);
    
    /* Used to know when the amplitude level has changed */
    IO_PD5_Toggle();
    
    _delay_ms(10);
    
    /* Set the amplitude levele so that the maximum duty cycle possible is 75% */
    TCE0_AmplitudeSet(AMPLITUDE_MAX_DCY_75_PERCENT);
    
    /* Update the values of CMP registre so that the amplitude change takes place */
    TCE0_CompareAllChannelsBufferedSet(DUTY_CYCLE_20_PERCENT, DUTY_CYCLE_40_PERCENT, DUTY_CYCLE_60_PERCENT, DUTY_CYCLE_80_PERCENT);
    
    /* Used to know when the amplitude level has changed */
    IO_PD5_Toggle();
    
    _delay_ms(10);
    
    /* Set the amplitude levele so that the maximum duty cycle possible is 100% */
    TCE0_AmplitudeSet(AMPLITUDE_MAX_DCY_100_PERCENT);
    
    /* Update the values of CMP registre so that the amplitude change takes place */
    TCE0_CompareAllChannelsBufferedSet(DUTY_CYCLE_20_PERCENT, DUTY_CYCLE_40_PERCENT, DUTY_CYCLE_60_PERCENT, DUTY_CYCLE_80_PERCENT);
    
    /* Used to know when the amplitude level has changed */
    IO_PD5_Toggle();
    
    _delay_ms(10);
    
    /* Set the amplitude levele so that the maximum duty cycle possible is 150% */
    TCE0_AmplitudeSet(AMPLITUDE_MAX_DCY_150_PERCENT);
    
    /* Update the values of CMP registre so that the amplitude change takes place */
    TCE0_CompareAllChannelsBufferedSet(DUTY_CYCLE_20_PERCENT, DUTY_CYCLE_40_PERCENT, DUTY_CYCLE_60_PERCENT, DUTY_CYCLE_80_PERCENT);
    
    /* Used to know when the amplitude level has changed */
    IO_PD5_Toggle();
    
    _delay_ms(10);
    
    /* Used to know when the scale mode has changed */
    IO_PD4_Toggle();
}

int main(void)
{
    SYSTEM_Initialize();


    while(1)
    {
        Scale_Mode_Change(TCE_SCALEMODE_BOTTOM_gc);
        Scale_Mode_Change(TCE_SCALEMODE_CENTER_gc);
        Scale_Mode_Change(TCE_SCALEMODE_TOP_gc);
        Scale_Mode_Change(TCE_SCALEMODE_TOPBOTTOM_gc);
    }    
}