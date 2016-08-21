/* 
 * Analog to Digital conversion for HiveBio Ministat
 * 
 * Copyright C. Harrison
 * BSD 2-clause license http://opensource.org/licenses/BSD-2-Clause
 *
 */


#ifndef ADC_PROC_H
#define ADC_PROC_H
#include <project.h>
    
extern volatile int32 adc_result[];

#define NUM_ACCUMS 100

enum {
    adc_chan_CT_L1,
    adc_chan_CT_L2
};

void adc_setup();

#endif
