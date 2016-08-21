/* 
 * Analog to Digital conversion for power meter
 * 
 * Copyright C. Harrison
 * BSD 2-clause license http://opensource.org/licenses/BSD-2-Clause
 *
 */
#include <project.h>
#include "ADC_proc.h"

volatile int32 adc_result[2*ADC_TOTAL_CHANNELS_NUM];
int32 accum[ADC_TOTAL_CHANNELS_NUM];
int32 sqaccum[ADC_TOTAL_CHANNELS_NUM];
int16 accum_count;
int16 midpoint;


CY_ISR(ADC_ISR_LOC)
{
    uint32 intr_status;

    /* Read interrupt status registers */
    intr_status = ADC_SAR_INTR_MASKED_REG;
    /* Check for End of Scan interrupt */
    if((intr_status & ADC_EOS_MASK) != 0u)
    {
        if(++accum_count >= NUM_ACCUMS) {
            accum_count = 0;
        }
        unsigned int chan;
        for (chan=0; chan<ADC_TOTAL_CHANNELS_NUM; ++chan)
        {
            /* save accumulated reading if ready*/
            if(accum_count==0) {
                adc_result[chan] = accum[chan];
                accum[chan] = 0;
				adc_result[chan+ADC_TOTAL_CHANNELS_NUM] = sqaccum[chan];
				sqaccum[chan] = 0;
            }
            /* Read conversion result */
			uint32 t = (uint16)ADC_GetResult16(chan)-midpoint;
            accum[chan] += t;
            sqaccum[chan] += t*t;
        } 
    }    

    /* Clear handled interrupt */
    ADC_SAR_INTR_REG = intr_status;
}

void adc_setup() {
	midpoint = 0x7FFF; /* ADC reading for zero signal */
    /* Init and start sequencing SAR ADC */
    ADC_Start();
    ADC_StartConvert();
    /* Enable interrupt and set interrupt handler to local routine */
    ADC_IRQ_StartEx(ADC_ISR_LOC);
}
