/* Calculated values for PGMOUT and SWAP registers of WEX */
#define PATTERN                 (0xAA)
#define COMPLEMENTARY_PATTERN   (0x55)
#define PGM_OVERRIDE_DISABLE    (0x00)
#define PGM_OVERRIDE_ENABLE     (0xFF)
#define SWAP_CHANNELS_ENABLE    (0x0F)
#define SWAP_CHANNELS_DISABLE   (0x00)


#include "mcc_generated_files/system/system.h"
#include <util/delay.h>

int main(void)
{
    SYSTEM_Initialize();


    while(1)
    {
        /* Set which pins can be overridden in Pattern Generation Mode, take control of the output pins from TCE */
        WEX0_PatternGenerationOverrideSet(PGM_OVERRIDE_ENABLE);
        
        /* Disable channel swap feature */
        WEX0_SwapChannelSet(SWAP_CHANNELS_DISABLE);
        
        _delay_ms(10);
        
        /* Set a pattern for WEX's outputs */
        WEX0_PatternGenerationOutputSet(PATTERN);
        
        _delay_ms(10);
        
        /* Set a complementary pattern for WEX's outputs */
        WEX0_PatternGenerationOutputSet(COMPLEMENTARY_PATTERN);
        
        _delay_ms(10);
        
        /* Set a pattern for WEX's outputs */
        WEX0_PatternGenerationOutputSet(PATTERN);
        
        _delay_ms(10);
        
        /* Set a complementary pattern for WEX's outputs */
        WEX0_PatternGenerationOutputSet(COMPLEMENTARY_PATTERN);
        
        _delay_ms(10);
        
        /* Disable pin override with WEX in PAttern Generation Mode, give pin control back to TCE,
         * TCE is never stopped, it always runs in background */
        WEX0_PatternGenerationOverrideSet(PGM_OVERRIDE_DISABLE);
        
        /* GPIO Toggle to show when WEX gives or takes control of output port pins from TCE */
        IO_PD5_Toggle();
        
        _delay_ms(100);
        
        /* Set which pins can be overridden in Pattern Generation Mode, take control of the output pins from TCE */
        WEX0_PatternGenerationOverrideSet(PGM_OVERRIDE_ENABLE);
        
        /* Enable channel swap feature */
        WEX0_SwapChannelSet(SWAP_CHANNELS_ENABLE);
        
        _delay_ms(10);
        
        /* Set a pattern for WEX's outputs with swap feature active */
        WEX0_PatternGenerationOutputSet(PATTERN);
        
        _delay_ms(10);
        
        /* Set a complementary pattern for WEX's outputs with swap feature active */
        WEX0_PatternGenerationOutputSet(COMPLEMENTARY_PATTERN);
        
        _delay_ms(10);
        
        /* Set a pattern for WEX's outputs with swap feature active */
        WEX0_PatternGenerationOutputSet(PATTERN);
        
        _delay_ms(10);
        
        /* Set a complementary pattern for WEX's outputs with swap feature active */
        WEX0_PatternGenerationOutputSet(COMPLEMENTARY_PATTERN);
        
        _delay_ms(10);
        
        /* Disable pin override with WEX in PAttern Generation Mode, give pin control back to TCE,
         * TCE is never stopped, it always runs in background */
        WEX0_PatternGenerationOverrideSet(PGM_OVERRIDE_DISABLE);
        
        /* GPIO Toggle to show when WEX gives or takes control of output port pins from TCE */
        IO_PD5_Toggle();
        
        _delay_ms(100);
    }    
}