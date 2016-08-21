/*******************************************************************************
* File Name: PUMP_PWM.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the PUMP_PWM
*  component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PUMP_PWM.h"

uint8 PUMP_PWM_initVar = 0u;


/*******************************************************************************
* Function Name: PUMP_PWM_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default PUMP_PWM configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (PUMP_PWM__QUAD == PUMP_PWM_CONFIG)
        PUMP_PWM_CONTROL_REG = PUMP_PWM_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        PUMP_PWM_TRIG_CONTROL1_REG  = PUMP_PWM_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        PUMP_PWM_SetInterruptMode(PUMP_PWM_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        PUMP_PWM_SetCounterMode(PUMP_PWM_COUNT_DOWN);
        PUMP_PWM_WritePeriod(PUMP_PWM_QUAD_PERIOD_INIT_VALUE);
        PUMP_PWM_WriteCounter(PUMP_PWM_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (PUMP_PWM__QUAD == PUMP_PWM_CONFIG) */

    #if (PUMP_PWM__TIMER == PUMP_PWM_CONFIG)
        PUMP_PWM_CONTROL_REG = PUMP_PWM_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        PUMP_PWM_TRIG_CONTROL1_REG  = PUMP_PWM_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        PUMP_PWM_SetInterruptMode(PUMP_PWM_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        PUMP_PWM_WritePeriod(PUMP_PWM_TC_PERIOD_VALUE );

        #if (PUMP_PWM__COMPARE == PUMP_PWM_TC_COMP_CAP_MODE)
            PUMP_PWM_WriteCompare(PUMP_PWM_TC_COMPARE_VALUE);

            #if (1u == PUMP_PWM_TC_COMPARE_SWAP)
                PUMP_PWM_SetCompareSwap(1u);
                PUMP_PWM_WriteCompareBuf(PUMP_PWM_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == PUMP_PWM_TC_COMPARE_SWAP) */
        #endif  /* (PUMP_PWM__COMPARE == PUMP_PWM_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (PUMP_PWM_CY_TCPWM_V2 && PUMP_PWM_TIMER_UPDOWN_CNT_USED && !PUMP_PWM_CY_TCPWM_4000)
            PUMP_PWM_WriteCounter(1u);
        #elif(PUMP_PWM__COUNT_DOWN == PUMP_PWM_TC_COUNTER_MODE)
            PUMP_PWM_WriteCounter(PUMP_PWM_TC_PERIOD_VALUE);
        #else
            PUMP_PWM_WriteCounter(0u);
        #endif /* (PUMP_PWM_CY_TCPWM_V2 && PUMP_PWM_TIMER_UPDOWN_CNT_USED && !PUMP_PWM_CY_TCPWM_4000) */
    #endif  /* (PUMP_PWM__TIMER == PUMP_PWM_CONFIG) */

    #if (PUMP_PWM__PWM_SEL == PUMP_PWM_CONFIG)
        PUMP_PWM_CONTROL_REG = PUMP_PWM_CTRL_PWM_BASE_CONFIG;

        #if (PUMP_PWM__PWM_PR == PUMP_PWM_PWM_MODE)
            PUMP_PWM_CONTROL_REG |= PUMP_PWM_CTRL_PWM_RUN_MODE;
            PUMP_PWM_WriteCounter(PUMP_PWM_PWM_PR_INIT_VALUE);
        #else
            PUMP_PWM_CONTROL_REG |= PUMP_PWM_CTRL_PWM_ALIGN | PUMP_PWM_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (PUMP_PWM_CY_TCPWM_V2 && PUMP_PWM_PWM_UPDOWN_CNT_USED && !PUMP_PWM_CY_TCPWM_4000)
                PUMP_PWM_WriteCounter(1u);
            #elif (PUMP_PWM__RIGHT == PUMP_PWM_PWM_ALIGN)
                PUMP_PWM_WriteCounter(PUMP_PWM_PWM_PERIOD_VALUE);
            #else 
                PUMP_PWM_WriteCounter(0u);
            #endif  /* (PUMP_PWM_CY_TCPWM_V2 && PUMP_PWM_PWM_UPDOWN_CNT_USED && !PUMP_PWM_CY_TCPWM_4000) */
        #endif  /* (PUMP_PWM__PWM_PR == PUMP_PWM_PWM_MODE) */

        #if (PUMP_PWM__PWM_DT == PUMP_PWM_PWM_MODE)
            PUMP_PWM_CONTROL_REG |= PUMP_PWM_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (PUMP_PWM__PWM_DT == PUMP_PWM_PWM_MODE) */

        #if (PUMP_PWM__PWM == PUMP_PWM_PWM_MODE)
            PUMP_PWM_CONTROL_REG |= PUMP_PWM_CTRL_PWM_PRESCALER;
        #endif  /* (PUMP_PWM__PWM == PUMP_PWM_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        PUMP_PWM_TRIG_CONTROL1_REG  = PUMP_PWM_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        PUMP_PWM_SetInterruptMode(PUMP_PWM_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (PUMP_PWM__PWM_PR == PUMP_PWM_PWM_MODE)
            PUMP_PWM_TRIG_CONTROL2_REG =
                    (PUMP_PWM_CC_MATCH_NO_CHANGE    |
                    PUMP_PWM_OVERLOW_NO_CHANGE      |
                    PUMP_PWM_UNDERFLOW_NO_CHANGE);
        #else
            #if (PUMP_PWM__LEFT == PUMP_PWM_PWM_ALIGN)
                PUMP_PWM_TRIG_CONTROL2_REG = PUMP_PWM_PWM_MODE_LEFT;
            #endif  /* ( PUMP_PWM_PWM_LEFT == PUMP_PWM_PWM_ALIGN) */

            #if (PUMP_PWM__RIGHT == PUMP_PWM_PWM_ALIGN)
                PUMP_PWM_TRIG_CONTROL2_REG = PUMP_PWM_PWM_MODE_RIGHT;
            #endif  /* ( PUMP_PWM_PWM_RIGHT == PUMP_PWM_PWM_ALIGN) */

            #if (PUMP_PWM__CENTER == PUMP_PWM_PWM_ALIGN)
                PUMP_PWM_TRIG_CONTROL2_REG = PUMP_PWM_PWM_MODE_CENTER;
            #endif  /* ( PUMP_PWM_PWM_CENTER == PUMP_PWM_PWM_ALIGN) */

            #if (PUMP_PWM__ASYMMETRIC == PUMP_PWM_PWM_ALIGN)
                PUMP_PWM_TRIG_CONTROL2_REG = PUMP_PWM_PWM_MODE_ASYM;
            #endif  /* (PUMP_PWM__ASYMMETRIC == PUMP_PWM_PWM_ALIGN) */
        #endif  /* (PUMP_PWM__PWM_PR == PUMP_PWM_PWM_MODE) */

        /* Set other values from customizer */
        PUMP_PWM_WritePeriod(PUMP_PWM_PWM_PERIOD_VALUE );
        PUMP_PWM_WriteCompare(PUMP_PWM_PWM_COMPARE_VALUE);

        #if (1u == PUMP_PWM_PWM_COMPARE_SWAP)
            PUMP_PWM_SetCompareSwap(1u);
            PUMP_PWM_WriteCompareBuf(PUMP_PWM_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == PUMP_PWM_PWM_COMPARE_SWAP) */

        #if (1u == PUMP_PWM_PWM_PERIOD_SWAP)
            PUMP_PWM_SetPeriodSwap(1u);
            PUMP_PWM_WritePeriodBuf(PUMP_PWM_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == PUMP_PWM_PWM_PERIOD_SWAP) */
    #endif  /* (PUMP_PWM__PWM_SEL == PUMP_PWM_CONFIG) */
    
}


/*******************************************************************************
* Function Name: PUMP_PWM_Enable
********************************************************************************
*
* Summary:
*  Enables the PUMP_PWM.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    PUMP_PWM_BLOCK_CONTROL_REG |= PUMP_PWM_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (PUMP_PWM__PWM_SEL == PUMP_PWM_CONFIG)
        #if (0u == PUMP_PWM_PWM_START_SIGNAL_PRESENT)
            PUMP_PWM_TriggerCommand(PUMP_PWM_MASK, PUMP_PWM_CMD_START);
        #endif /* (0u == PUMP_PWM_PWM_START_SIGNAL_PRESENT) */
    #endif /* (PUMP_PWM__PWM_SEL == PUMP_PWM_CONFIG) */

    #if (PUMP_PWM__TIMER == PUMP_PWM_CONFIG)
        #if (0u == PUMP_PWM_TC_START_SIGNAL_PRESENT)
            PUMP_PWM_TriggerCommand(PUMP_PWM_MASK, PUMP_PWM_CMD_START);
        #endif /* (0u == PUMP_PWM_TC_START_SIGNAL_PRESENT) */
    #endif /* (PUMP_PWM__TIMER == PUMP_PWM_CONFIG) */
}


/*******************************************************************************
* Function Name: PUMP_PWM_Start
********************************************************************************
*
* Summary:
*  Initializes the PUMP_PWM with default customizer
*  values when called the first time and enables the PUMP_PWM.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PUMP_PWM_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time PUMP_PWM_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the PUMP_PWM_Start() routine.
*
*******************************************************************************/
void PUMP_PWM_Start(void)
{
    if (0u == PUMP_PWM_initVar)
    {
        PUMP_PWM_Init();
        PUMP_PWM_initVar = 1u;
    }

    PUMP_PWM_Enable();
}


/*******************************************************************************
* Function Name: PUMP_PWM_Stop
********************************************************************************
*
* Summary:
*  Disables the PUMP_PWM.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_BLOCK_CONTROL_REG &= (uint32)~PUMP_PWM_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the PUMP_PWM. This function is used when
*  configured as a generic PUMP_PWM and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the PUMP_PWM to operate in
*   Values:
*   - PUMP_PWM_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - PUMP_PWM_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - PUMP_PWM_MODE_QUAD - Quadrature decoder
*         - PUMP_PWM_MODE_PWM - PWM
*         - PUMP_PWM_MODE_PWM_DT - PWM with dead time
*         - PUMP_PWM_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_MODE_MASK;
    PUMP_PWM_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - PUMP_PWM_MODE_X1 - Counts on phi 1 rising
*         - PUMP_PWM_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - PUMP_PWM_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_QUAD_MODE_MASK;
    PUMP_PWM_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - PUMP_PWM_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - PUMP_PWM_PRESCALE_DIVBY2    - Divide by 2
*         - PUMP_PWM_PRESCALE_DIVBY4    - Divide by 4
*         - PUMP_PWM_PRESCALE_DIVBY8    - Divide by 8
*         - PUMP_PWM_PRESCALE_DIVBY16   - Divide by 16
*         - PUMP_PWM_PRESCALE_DIVBY32   - Divide by 32
*         - PUMP_PWM_PRESCALE_DIVBY64   - Divide by 64
*         - PUMP_PWM_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_PRESCALER_MASK;
    PUMP_PWM_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PUMP_PWM runs
*  continuously or stops when terminal count is reached.  By default the
*  PUMP_PWM operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_ONESHOT_MASK;
    PUMP_PWM_CONTROL_REG |= ((uint32)((oneShotEnable & PUMP_PWM_1BIT_MASK) <<
                                                               PUMP_PWM_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetPWMMode(uint32 modeMask)
{
    PUMP_PWM_TRIG_CONTROL2_REG = (modeMask & PUMP_PWM_6BIT_MASK);
}



/*******************************************************************************
* Function Name: PUMP_PWM_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_PWM_SYNC_KILL_MASK;
    PUMP_PWM_CONTROL_REG |= ((uint32)((syncKillEnable & PUMP_PWM_1BIT_MASK)  <<
                                               PUMP_PWM_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_PWM_STOP_KILL_MASK;
    PUMP_PWM_CONTROL_REG |= ((uint32)((stopOnKillEnable & PUMP_PWM_1BIT_MASK)  <<
                                                         PUMP_PWM_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_PRESCALER_MASK;
    PUMP_PWM_CONTROL_REG |= ((uint32)((deadTime & PUMP_PWM_8BIT_MASK) <<
                                                          PUMP_PWM_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - PUMP_PWM_INVERT_LINE   - Inverts the line output
*         - PUMP_PWM_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_INV_OUT_MASK;
    PUMP_PWM_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: PUMP_PWM_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_WriteCounter(uint32 count)
{
    PUMP_PWM_COUNTER_REG = (count & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 PUMP_PWM_ReadCounter(void)
{
    return (PUMP_PWM_COUNTER_REG & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - PUMP_PWM_COUNT_UP       - Counts up
*     - PUMP_PWM_COUNT_DOWN     - Counts down
*     - PUMP_PWM_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - PUMP_PWM_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_UPDOWN_MASK;
    PUMP_PWM_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_WritePeriod(uint32 period)
{
    PUMP_PWM_PERIOD_REG = (period & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 PUMP_PWM_ReadPeriod(void)
{
    return (PUMP_PWM_PERIOD_REG & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_RELOAD_CC_MASK;
    PUMP_PWM_CONTROL_REG |= (swapEnable & PUMP_PWM_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_WritePeriodBuf(uint32 periodBuf)
{
    PUMP_PWM_PERIOD_BUF_REG = (periodBuf & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 PUMP_PWM_ReadPeriodBuf(void)
{
    return (PUMP_PWM_PERIOD_BUF_REG & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_CONTROL_REG &= (uint32)~PUMP_PWM_RELOAD_PERIOD_MASK;
    PUMP_PWM_CONTROL_REG |= ((uint32)((swapEnable & PUMP_PWM_1BIT_MASK) <<
                                                            PUMP_PWM_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_WriteCompare(uint32 compare)
{
    #if (PUMP_PWM_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */

    #if (PUMP_PWM_CY_TCPWM_4000)
        currentMode = ((PUMP_PWM_CONTROL_REG & PUMP_PWM_UPDOWN_MASK) >> PUMP_PWM_UPDOWN_SHIFT);

        if (((uint32)PUMP_PWM__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)PUMP_PWM__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */
    
    PUMP_PWM_COMP_CAP_REG = (compare & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 PUMP_PWM_ReadCompare(void)
{
    #if (PUMP_PWM_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */

    #if (PUMP_PWM_CY_TCPWM_4000)
        currentMode = ((PUMP_PWM_CONTROL_REG & PUMP_PWM_UPDOWN_MASK) >> PUMP_PWM_UPDOWN_SHIFT);
        
        regVal = PUMP_PWM_COMP_CAP_REG;
        
        if (((uint32)PUMP_PWM__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)PUMP_PWM__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & PUMP_PWM_16BIT_MASK);
    #else
        return (PUMP_PWM_COMP_CAP_REG & PUMP_PWM_16BIT_MASK);
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: PUMP_PWM_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_WriteCompareBuf(uint32 compareBuf)
{
    #if (PUMP_PWM_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */

    #if (PUMP_PWM_CY_TCPWM_4000)
        currentMode = ((PUMP_PWM_CONTROL_REG & PUMP_PWM_UPDOWN_MASK) >> PUMP_PWM_UPDOWN_SHIFT);

        if (((uint32)PUMP_PWM__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)PUMP_PWM__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */
    
    PUMP_PWM_COMP_CAP_BUF_REG = (compareBuf & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 PUMP_PWM_ReadCompareBuf(void)
{
    #if (PUMP_PWM_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */

    #if (PUMP_PWM_CY_TCPWM_4000)
        currentMode = ((PUMP_PWM_CONTROL_REG & PUMP_PWM_UPDOWN_MASK) >> PUMP_PWM_UPDOWN_SHIFT);

        regVal = PUMP_PWM_COMP_CAP_BUF_REG;
        
        if (((uint32)PUMP_PWM__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)PUMP_PWM__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & PUMP_PWM_16BIT_MASK);
    #else
        return (PUMP_PWM_COMP_CAP_BUF_REG & PUMP_PWM_16BIT_MASK);
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: PUMP_PWM_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 PUMP_PWM_ReadCapture(void)
{
    return (PUMP_PWM_COMP_CAP_REG & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 PUMP_PWM_ReadCaptureBuf(void)
{
    return (PUMP_PWM_COMP_CAP_BUF_REG & PUMP_PWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PUMP_PWM_TRIG_LEVEL     - Level
*     - PUMP_PWM_TRIG_RISING    - Rising edge
*     - PUMP_PWM_TRIG_FALLING   - Falling edge
*     - PUMP_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_TRIG_CONTROL1_REG &= (uint32)~PUMP_PWM_CAPTURE_MASK;
    PUMP_PWM_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PUMP_PWM_TRIG_LEVEL     - Level
*     - PUMP_PWM_TRIG_RISING    - Rising edge
*     - PUMP_PWM_TRIG_FALLING   - Falling edge
*     - PUMP_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_TRIG_CONTROL1_REG &= (uint32)~PUMP_PWM_RELOAD_MASK;
    PUMP_PWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PUMP_PWM_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PUMP_PWM_TRIG_LEVEL     - Level
*     - PUMP_PWM_TRIG_RISING    - Rising edge
*     - PUMP_PWM_TRIG_FALLING   - Falling edge
*     - PUMP_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_TRIG_CONTROL1_REG &= (uint32)~PUMP_PWM_START_MASK;
    PUMP_PWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PUMP_PWM_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PUMP_PWM_TRIG_LEVEL     - Level
*     - PUMP_PWM_TRIG_RISING    - Rising edge
*     - PUMP_PWM_TRIG_FALLING   - Falling edge
*     - PUMP_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_TRIG_CONTROL1_REG &= (uint32)~PUMP_PWM_STOP_MASK;
    PUMP_PWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PUMP_PWM_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PUMP_PWM_TRIG_LEVEL     - Level
*     - PUMP_PWM_TRIG_RISING    - Rising edge
*     - PUMP_PWM_TRIG_FALLING   - Falling edge
*     - PUMP_PWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_TRIG_CONTROL1_REG &= (uint32)~PUMP_PWM_COUNT_MASK;
    PUMP_PWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PUMP_PWM_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - PUMP_PWM_CMD_CAPTURE    - Trigger Capture command
*     - PUMP_PWM_CMD_RELOAD     - Trigger Reload command
*     - PUMP_PWM_CMD_STOP       - Trigger Stop command
*     - PUMP_PWM_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PUMP_PWM_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PUMP_PWM_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the PUMP_PWM.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - PUMP_PWM_STATUS_DOWN    - Set if counting down
*     - PUMP_PWM_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 PUMP_PWM_ReadStatus(void)
{
    return ((PUMP_PWM_STATUS_REG >> PUMP_PWM_RUNNING_STATUS_SHIFT) |
            (PUMP_PWM_STATUS_REG & PUMP_PWM_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - PUMP_PWM_INTR_MASK_TC       - Terminal count mask
*     - PUMP_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetInterruptMode(uint32 interruptMask)
{
    PUMP_PWM_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: PUMP_PWM_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - PUMP_PWM_INTR_MASK_TC       - Terminal count mask
*     - PUMP_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PUMP_PWM_GetInterruptSourceMasked(void)
{
    return (PUMP_PWM_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: PUMP_PWM_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - PUMP_PWM_INTR_MASK_TC       - Terminal count mask
*     - PUMP_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PUMP_PWM_GetInterruptSource(void)
{
    return (PUMP_PWM_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: PUMP_PWM_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - PUMP_PWM_INTR_MASK_TC       - Terminal count mask
*     - PUMP_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_ClearInterrupt(uint32 interruptMask)
{
    PUMP_PWM_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: PUMP_PWM_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - PUMP_PWM_INTR_MASK_TC       - Terminal count mask
*     - PUMP_PWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SetInterrupt(uint32 interruptMask)
{
    PUMP_PWM_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
