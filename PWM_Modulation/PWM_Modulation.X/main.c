/* Set the frequency of the Signal in Hz in the range of 0 - 1000Hz */
#define FREQ_HZ(X)                (uint16_t)(3.33 * (float)(X)) 

/* Set the amplitude of the sinewave in the range of 0 - 100% */
#define AMPLITUDE_PERCENT(X)      (uint16_t)((float)(X) * 327.68)          

#include "mcc_generated_files/system/system.h"
#include <util/delay.h>
#include <stdint.h>


/* Lookup table used to generate a complete period of the sine signal */
const uint16_t sine_lookup_table[] = 
{
  16384, 16786, 17187, 17589, 17989, 18389, 18788, 19185, 19580, 19973, 20364, 
  20753, 21140, 21523, 21903, 22280, 22653, 23023, 23389, 23750, 24107, 24459, 24807, 
  25149, 25486, 25818, 26143, 26463, 26777, 27085, 27386, 27681, 27969, 28250, 28523, 
  28790, 29049, 29300, 29543, 29779, 30006, 30226, 30437, 30639, 30833, 31018, 31194, 
  31362, 31520, 31670, 31810, 31941, 32062, 32174, 32276, 32369, 32453, 32526, 32590, 
  32644, 32689, 32723, 32748, 32763, 32768, 32763, 32748, 32723, 32689, 32644, 32590, 
  32526, 32453, 32369, 32276, 32174, 32062, 31941, 31810, 31670, 31520, 31362, 31194, 
  31018, 30833, 30639, 30437, 30226, 30006, 29779, 29543, 29300, 29049, 28790, 28523, 
  28250, 27969, 27681, 27386, 27085, 26777, 26463, 26143, 25818, 25486, 25149, 24807, 
  24459, 24107, 23750, 23389, 23023, 22653, 22280, 21903, 21523, 21140, 20753, 20364, 
  19973, 19580, 19185, 18788, 18389, 17989, 17589, 17187, 16786, 16384, 15981, 15580, 
  15178, 14778, 14378, 13979, 13582, 13187, 12794, 12403, 12014, 11627, 11244, 10864, 
  10487, 10114, 9744, 9378, 9017, 8660, 8308, 7960, 7618, 7281, 6949, 6624, 6304, 5990, 
  5682, 5381, 5086, 4798, 4517, 4244, 3977, 3718, 3467, 3224, 2988, 2761, 2541, 2330, 
  2128, 1934, 1749, 1573, 1405, 1247, 1097, 957, 826, 705, 593, 491, 398, 314, 241, 
  177, 123, 78, 44, 19, 4, 0, 4, 19, 44, 78, 123, 177, 241, 314, 398, 491, 593, 705, 
  826, 957, 1097, 1247, 1405, 1573, 1749, 1934, 2128, 2330, 2541, 2761, 2988, 3224, 
  3467, 3718, 3977, 4244, 4517, 4798, 5086, 5381, 5682, 5990, 6304, 6624, 6949, 7281, 
  7618, 7960, 8308, 8660, 9017, 9378, 9744, 10114, 10487, 10864, 11244, 11627, 12014, 
  12403, 12794, 13187, 13582, 13979, 14378, 14778, 15178, 15580, 15981
};

uint16_t frequency;
uint16_t amplitude;

void Sinewave_Modulation(void)
{
    uint16_t pwm;
    static uint16_t sinewave = 0;
    
    /* Increment LUT counter depending on the frequency set at runtime */
    sinewave += frequency;
    
    /* Select a new value from LUT */
    pwm = sine_lookup_table[(sinewave >> 8)];
    
    /* Update the AMP register with the amplitude set at runtime */
    TCE0_AmplitudeSet(amplitude);
    
    /* Update CMP register of TCE with a new value from LUT */
    TCE0_PWM_BufferedDutyCycle0Set(pwm);
}

int main(void)
{
    SYSTEM_Initialize();
    TCE0_OverflowCallbackRegister(Sinewave_Modulation);
    frequency = 0;
    amplitude = 0;

    while(1)
    {
        /* Set the ampitude of the sine to be 100%, duty cycles values range from 0 to 100% minus added dead time */
        amplitude = AMPLITUDE_PERCENT(100);
        
        /* Set sine frequency in Hz */
        frequency = FREQ_HZ(500);
        
        _delay_ms(1000);
        
        /* Set the ampitude of the sine to be 50%, duty cycles values range from 0 to 50% */
        amplitude = AMPLITUDE_PERCENT(50);
        
        /* Set sine frequency in Hz */
        frequency = FREQ_HZ(1000);
        
        _delay_ms(1000);
    }    
}