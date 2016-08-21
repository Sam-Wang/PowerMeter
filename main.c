/* 
 * HiveBio Ministat turbidostat system
 * 
 * Copyright C. Harrison
 * BSD 2-clause license http://opensource.org/licenses/BSD-2-Clause
 *
 */
#include <project.h>
#include <math.h>
#include "SysTimer.h"
#include "isnprintf.h"
#include "ADC_proc.h"
#include "Thermistor_linearize.h"

// LED thermal drift correction
#define NOM_LEDVOLT 2970000L
#define OFFSET_LEDVOLT (1./3. * 32768 * 100) // LED cathode is at Vref
#define LED_CORR_FACTOR (6.2)  // % change in light per 1% change in LED voltage

enum { LED_on, collect_on, LED_off, collect_off } detector_phase = LED_on;

int main()
{
    systimer_setup(); // sets up millisec() hardware timer
    Host_UART_Start(); // serial port
    adc_setup(); // A to D converter
    CyGlobalIntEnable; // Enable interrupts
    
    uint32 report_interval_ms = 100;
    uint32 next_report_time = millis() + report_interval_ms;
    uint32 reports_remaining = 0;
    uint32 reboot_timer = millis();
    uint8 reboot_count =0;
	
    char buf[30];
	enum {
		serin_idle,
		serin_cmd,
		serin_g,
		serin_gg,
		serin_ge,
		serin_fault
	} serin_state;
	serin_state = serin_idle;
	
    for(;;)
    {

        // periodically report results 
        if (reports_remaining > 0 && (int32)(millis()-next_report_time) >= 0) {
            next_report_time += report_interval_ms;
            reports_remaining -= 1;
            int32 count;
            char buf[30];
			int32 mean = adc_result[adc_chan_CT_L1]/NUM_ACCUMS;
			int32 rms = (int32)(sqrt(adc_result[adc_chan_CT_L1+ADC_TOTAL_CHANNELS_NUM]/NUM_ACCUMS
			                         - mean*mean));
            count = isnprintf(buf, 30, "OK %d %d\r\n", mean, rms);
            Host_UART_SpiUartPutArray((uint8*)buf, count);

        }
        P1_6_Write(reports_remaining>0); // Blue LED on while reporting
        
       
        // watch for serial input
        // mimic OpenEVSE RAPI GG query
		//

        if (Host_UART_SpiUartGetRxBufferSize() != 0) do {
            char in_char = (char)(Host_UART_SpiUartReadRxData() & 0xFF);
			if (serin_state == serin_idle) {
				if (in_char == '$') {
					serin_state = serin_cmd;
				} break;
			} else if (serin_state == serin_cmd) {
				if (in_char == 'G') {
					serin_state = serin_g;
				} else {
					serin_state = serin_fault;
				} break;
			} else if (serin_state == serin_g) {
				if (in_char == 'G') {
					serin_state = serin_gg;
				} else if (in_char == 'E') {
					serin_state = serin_ge;
				} else {
					serin_state = serin_fault;
				} break;
			} else if (serin_state == serin_fault) {
				if (in_char == '\r') {
					Host_UART_SpiUartPutArray("$NK\r",4);
					serin_state = serin_idle;
				} break;
			} else if (serin_state == serin_gg) {
				if (in_char == '\r') {
                    int32 count;
				    int32 mean = adc_result[adc_chan_CT_L1]/NUM_ACCUMS;
				    int32 rms_L1 = (int32)(sqrt(adc_result[adc_chan_CT_L1+ADC_TOTAL_CHANNELS_NUM]/NUM_ACCUMS
			                         - mean*mean));
                    count = isnprintf(buf, 30, "$OK %d %d\r", rms_L1,-1);
                    Host_UART_SpiUartPutArray((uint8*)buf, count);
					serin_state = serin_idle;
				} break;
			} else if (serin_state == serin_ge) {
				if (in_char == '\r') {
                    int32 count;
				    int32 mean = adc_result[adc_chan_CT_L2]/NUM_ACCUMS;
				    int32 rms_L2 = (int32)(sqrt(adc_result[adc_chan_CT_L2+ADC_TOTAL_CHANNELS_NUM]/NUM_ACCUMS
			                         - mean*mean));
                    count = isnprintf(buf, 30, "$OK %d %d\r", rms_L2, 0);
                    Host_UART_SpiUartPutArray((uint8*)buf, count);
					serin_state = serin_idle;
				} break;
			}
		} while (0);
        // clear serial RX error flags if any
        if (Host_UART_CHECK_INTR_RX(Host_UART_INTR_RX_ERR)) {
            Host_UART_ClearRxInterruptSource(Host_UART_INTR_RX_ERR);
        }

        // watch for pushbutton
        //   Stop RX8 transmission
        //   Held down 1-2 sec = reboot request
        if ((int32)(millis()-reboot_timer) >= 0) {
            if(Button_Read()) {
                reboot_count = 0;
            } else {
                reports_remaining = 0;
                if(++reboot_count > 1) {
                    Bootloadable_Load();
                }
            }
            reboot_timer += 1000;
        }
    }
}
