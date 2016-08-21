/*******************************************************************************
* File Name: PUMP_PWM.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the PUMP_PWM
*  component.
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

#if !defined(CY_TCPWM_PUMP_PWM_H)
#define CY_TCPWM_PUMP_PWM_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} PUMP_PWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  PUMP_PWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define PUMP_PWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define PUMP_PWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define PUMP_PWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define PUMP_PWM_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define PUMP_PWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define PUMP_PWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define PUMP_PWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define PUMP_PWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define PUMP_PWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define PUMP_PWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define PUMP_PWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define PUMP_PWM_TC_RUN_MODE                    (0lu)
#define PUMP_PWM_TC_COUNTER_MODE                (0lu)
#define PUMP_PWM_TC_COMP_CAP_MODE               (2lu)
#define PUMP_PWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define PUMP_PWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define PUMP_PWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define PUMP_PWM_TC_START_SIGNAL_MODE           (0lu)
#define PUMP_PWM_TC_STOP_SIGNAL_MODE            (0lu)
#define PUMP_PWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define PUMP_PWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define PUMP_PWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define PUMP_PWM_TC_START_SIGNAL_PRESENT        (0lu)
#define PUMP_PWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define PUMP_PWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PUMP_PWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define PUMP_PWM_PWM_KILL_EVENT                 (0lu)
#define PUMP_PWM_PWM_STOP_EVENT                 (0lu)
#define PUMP_PWM_PWM_MODE                       (4lu)
#define PUMP_PWM_PWM_OUT_N_INVERT               (0lu)
#define PUMP_PWM_PWM_OUT_INVERT                 (0lu)
#define PUMP_PWM_PWM_ALIGN                      (0lu)
#define PUMP_PWM_PWM_RUN_MODE                   (0lu)
#define PUMP_PWM_PWM_DEAD_TIME_CYCLE            (0lu)
#define PUMP_PWM_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define PUMP_PWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define PUMP_PWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define PUMP_PWM_PWM_START_SIGNAL_MODE          (0lu)
#define PUMP_PWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define PUMP_PWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define PUMP_PWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define PUMP_PWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define PUMP_PWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define PUMP_PWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define PUMP_PWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PUMP_PWM_PWM_INTERRUPT_MASK             (0lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define PUMP_PWM_TC_PERIOD_VALUE                (65535lu)
#define PUMP_PWM_TC_COMPARE_VALUE               (65535lu)
#define PUMP_PWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define PUMP_PWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define PUMP_PWM_PWM_PERIOD_VALUE               (1023lu)
#define PUMP_PWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define PUMP_PWM_PWM_PERIOD_SWAP                (0lu)
#define PUMP_PWM_PWM_COMPARE_VALUE              (0lu)
#define PUMP_PWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define PUMP_PWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define PUMP_PWM__LEFT 0
#define PUMP_PWM__RIGHT 1
#define PUMP_PWM__CENTER 2
#define PUMP_PWM__ASYMMETRIC 3

#define PUMP_PWM__X1 0
#define PUMP_PWM__X2 1
#define PUMP_PWM__X4 2

#define PUMP_PWM__PWM 4
#define PUMP_PWM__PWM_DT 5
#define PUMP_PWM__PWM_PR 6

#define PUMP_PWM__INVERSE 1
#define PUMP_PWM__DIRECT 0

#define PUMP_PWM__CAPTURE 2
#define PUMP_PWM__COMPARE 0

#define PUMP_PWM__TRIG_LEVEL 3
#define PUMP_PWM__TRIG_RISING 0
#define PUMP_PWM__TRIG_FALLING 1
#define PUMP_PWM__TRIG_BOTH 2

#define PUMP_PWM__INTR_MASK_TC 1
#define PUMP_PWM__INTR_MASK_CC_MATCH 2
#define PUMP_PWM__INTR_MASK_NONE 0
#define PUMP_PWM__INTR_MASK_TC_CC 3

#define PUMP_PWM__UNCONFIG 8
#define PUMP_PWM__TIMER 1
#define PUMP_PWM__QUAD 3
#define PUMP_PWM__PWM_SEL 7

#define PUMP_PWM__COUNT_UP 0
#define PUMP_PWM__COUNT_DOWN 1
#define PUMP_PWM__COUNT_UPDOWN0 2
#define PUMP_PWM__COUNT_UPDOWN1 3


/* Prescaler */
#define PUMP_PWM_PRESCALE_DIVBY1                ((uint32)(0u << PUMP_PWM_PRESCALER_SHIFT))
#define PUMP_PWM_PRESCALE_DIVBY2                ((uint32)(1u << PUMP_PWM_PRESCALER_SHIFT))
#define PUMP_PWM_PRESCALE_DIVBY4                ((uint32)(2u << PUMP_PWM_PRESCALER_SHIFT))
#define PUMP_PWM_PRESCALE_DIVBY8                ((uint32)(3u << PUMP_PWM_PRESCALER_SHIFT))
#define PUMP_PWM_PRESCALE_DIVBY16               ((uint32)(4u << PUMP_PWM_PRESCALER_SHIFT))
#define PUMP_PWM_PRESCALE_DIVBY32               ((uint32)(5u << PUMP_PWM_PRESCALER_SHIFT))
#define PUMP_PWM_PRESCALE_DIVBY64               ((uint32)(6u << PUMP_PWM_PRESCALER_SHIFT))
#define PUMP_PWM_PRESCALE_DIVBY128              ((uint32)(7u << PUMP_PWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define PUMP_PWM_MODE_TIMER_COMPARE             ((uint32)(PUMP_PWM__COMPARE         <<  \
                                                                  PUMP_PWM_MODE_SHIFT))
#define PUMP_PWM_MODE_TIMER_CAPTURE             ((uint32)(PUMP_PWM__CAPTURE         <<  \
                                                                  PUMP_PWM_MODE_SHIFT))
#define PUMP_PWM_MODE_QUAD                      ((uint32)(PUMP_PWM__QUAD            <<  \
                                                                  PUMP_PWM_MODE_SHIFT))
#define PUMP_PWM_MODE_PWM                       ((uint32)(PUMP_PWM__PWM             <<  \
                                                                  PUMP_PWM_MODE_SHIFT))
#define PUMP_PWM_MODE_PWM_DT                    ((uint32)(PUMP_PWM__PWM_DT          <<  \
                                                                  PUMP_PWM_MODE_SHIFT))
#define PUMP_PWM_MODE_PWM_PR                    ((uint32)(PUMP_PWM__PWM_PR          <<  \
                                                                  PUMP_PWM_MODE_SHIFT))

/* Quad Modes */
#define PUMP_PWM_MODE_X1                        ((uint32)(PUMP_PWM__X1              <<  \
                                                                  PUMP_PWM_QUAD_MODE_SHIFT))
#define PUMP_PWM_MODE_X2                        ((uint32)(PUMP_PWM__X2              <<  \
                                                                  PUMP_PWM_QUAD_MODE_SHIFT))
#define PUMP_PWM_MODE_X4                        ((uint32)(PUMP_PWM__X4              <<  \
                                                                  PUMP_PWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define PUMP_PWM_COUNT_UP                       ((uint32)(PUMP_PWM__COUNT_UP        <<  \
                                                                  PUMP_PWM_UPDOWN_SHIFT))
#define PUMP_PWM_COUNT_DOWN                     ((uint32)(PUMP_PWM__COUNT_DOWN      <<  \
                                                                  PUMP_PWM_UPDOWN_SHIFT))
#define PUMP_PWM_COUNT_UPDOWN0                  ((uint32)(PUMP_PWM__COUNT_UPDOWN0   <<  \
                                                                  PUMP_PWM_UPDOWN_SHIFT))
#define PUMP_PWM_COUNT_UPDOWN1                  ((uint32)(PUMP_PWM__COUNT_UPDOWN1   <<  \
                                                                  PUMP_PWM_UPDOWN_SHIFT))

/* PWM output invert */
#define PUMP_PWM_INVERT_LINE                    ((uint32)(PUMP_PWM__INVERSE         <<  \
                                                                  PUMP_PWM_INV_OUT_SHIFT))
#define PUMP_PWM_INVERT_LINE_N                  ((uint32)(PUMP_PWM__INVERSE         <<  \
                                                                  PUMP_PWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define PUMP_PWM_TRIG_RISING                    ((uint32)PUMP_PWM__TRIG_RISING)
#define PUMP_PWM_TRIG_FALLING                   ((uint32)PUMP_PWM__TRIG_FALLING)
#define PUMP_PWM_TRIG_BOTH                      ((uint32)PUMP_PWM__TRIG_BOTH)
#define PUMP_PWM_TRIG_LEVEL                     ((uint32)PUMP_PWM__TRIG_LEVEL)

/* Interrupt mask */
#define PUMP_PWM_INTR_MASK_TC                   ((uint32)PUMP_PWM__INTR_MASK_TC)
#define PUMP_PWM_INTR_MASK_CC_MATCH             ((uint32)PUMP_PWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define PUMP_PWM_CC_MATCH_SET                   (0x00u)
#define PUMP_PWM_CC_MATCH_CLEAR                 (0x01u)
#define PUMP_PWM_CC_MATCH_INVERT                (0x02u)
#define PUMP_PWM_CC_MATCH_NO_CHANGE             (0x03u)
#define PUMP_PWM_OVERLOW_SET                    (0x00u)
#define PUMP_PWM_OVERLOW_CLEAR                  (0x04u)
#define PUMP_PWM_OVERLOW_INVERT                 (0x08u)
#define PUMP_PWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define PUMP_PWM_UNDERFLOW_SET                  (0x00u)
#define PUMP_PWM_UNDERFLOW_CLEAR                (0x10u)
#define PUMP_PWM_UNDERFLOW_INVERT               (0x20u)
#define PUMP_PWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define PUMP_PWM_PWM_MODE_LEFT                  (PUMP_PWM_CC_MATCH_CLEAR        |   \
                                                         PUMP_PWM_OVERLOW_SET           |   \
                                                         PUMP_PWM_UNDERFLOW_NO_CHANGE)
#define PUMP_PWM_PWM_MODE_RIGHT                 (PUMP_PWM_CC_MATCH_SET          |   \
                                                         PUMP_PWM_OVERLOW_NO_CHANGE     |   \
                                                         PUMP_PWM_UNDERFLOW_CLEAR)
#define PUMP_PWM_PWM_MODE_ASYM                  (PUMP_PWM_CC_MATCH_INVERT       |   \
                                                         PUMP_PWM_OVERLOW_SET           |   \
                                                         PUMP_PWM_UNDERFLOW_CLEAR)

#if (PUMP_PWM_CY_TCPWM_V2)
    #if(PUMP_PWM_CY_TCPWM_4000)
        #define PUMP_PWM_PWM_MODE_CENTER                (PUMP_PWM_CC_MATCH_INVERT       |   \
                                                                 PUMP_PWM_OVERLOW_NO_CHANGE     |   \
                                                                 PUMP_PWM_UNDERFLOW_CLEAR)
    #else
        #define PUMP_PWM_PWM_MODE_CENTER                (PUMP_PWM_CC_MATCH_INVERT       |   \
                                                                 PUMP_PWM_OVERLOW_SET           |   \
                                                                 PUMP_PWM_UNDERFLOW_CLEAR)
    #endif /* (PUMP_PWM_CY_TCPWM_4000) */
#else
    #define PUMP_PWM_PWM_MODE_CENTER                (PUMP_PWM_CC_MATCH_INVERT       |   \
                                                             PUMP_PWM_OVERLOW_NO_CHANGE     |   \
                                                             PUMP_PWM_UNDERFLOW_CLEAR)
#endif /* (PUMP_PWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define PUMP_PWM_CMD_CAPTURE                    (0u)
#define PUMP_PWM_CMD_RELOAD                     (8u)
#define PUMP_PWM_CMD_STOP                       (16u)
#define PUMP_PWM_CMD_START                      (24u)

/* Status */
#define PUMP_PWM_STATUS_DOWN                    (1u)
#define PUMP_PWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   PUMP_PWM_Init(void);
void   PUMP_PWM_Enable(void);
void   PUMP_PWM_Start(void);
void   PUMP_PWM_Stop(void);

void   PUMP_PWM_SetMode(uint32 mode);
void   PUMP_PWM_SetCounterMode(uint32 counterMode);
void   PUMP_PWM_SetPWMMode(uint32 modeMask);
void   PUMP_PWM_SetQDMode(uint32 qdMode);

void   PUMP_PWM_SetPrescaler(uint32 prescaler);
void   PUMP_PWM_TriggerCommand(uint32 mask, uint32 command);
void   PUMP_PWM_SetOneShot(uint32 oneShotEnable);
uint32 PUMP_PWM_ReadStatus(void);

void   PUMP_PWM_SetPWMSyncKill(uint32 syncKillEnable);
void   PUMP_PWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   PUMP_PWM_SetPWMDeadTime(uint32 deadTime);
void   PUMP_PWM_SetPWMInvert(uint32 mask);

void   PUMP_PWM_SetInterruptMode(uint32 interruptMask);
uint32 PUMP_PWM_GetInterruptSourceMasked(void);
uint32 PUMP_PWM_GetInterruptSource(void);
void   PUMP_PWM_ClearInterrupt(uint32 interruptMask);
void   PUMP_PWM_SetInterrupt(uint32 interruptMask);

void   PUMP_PWM_WriteCounter(uint32 count);
uint32 PUMP_PWM_ReadCounter(void);

uint32 PUMP_PWM_ReadCapture(void);
uint32 PUMP_PWM_ReadCaptureBuf(void);

void   PUMP_PWM_WritePeriod(uint32 period);
uint32 PUMP_PWM_ReadPeriod(void);
void   PUMP_PWM_WritePeriodBuf(uint32 periodBuf);
uint32 PUMP_PWM_ReadPeriodBuf(void);

void   PUMP_PWM_WriteCompare(uint32 compare);
uint32 PUMP_PWM_ReadCompare(void);
void   PUMP_PWM_WriteCompareBuf(uint32 compareBuf);
uint32 PUMP_PWM_ReadCompareBuf(void);

void   PUMP_PWM_SetPeriodSwap(uint32 swapEnable);
void   PUMP_PWM_SetCompareSwap(uint32 swapEnable);

void   PUMP_PWM_SetCaptureMode(uint32 triggerMode);
void   PUMP_PWM_SetReloadMode(uint32 triggerMode);
void   PUMP_PWM_SetStartMode(uint32 triggerMode);
void   PUMP_PWM_SetStopMode(uint32 triggerMode);
void   PUMP_PWM_SetCountMode(uint32 triggerMode);

void   PUMP_PWM_SaveConfig(void);
void   PUMP_PWM_RestoreConfig(void);
void   PUMP_PWM_Sleep(void);
void   PUMP_PWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define PUMP_PWM_BLOCK_CONTROL_REG              (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PUMP_PWM_BLOCK_CONTROL_PTR              ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PUMP_PWM_COMMAND_REG                    (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PUMP_PWM_COMMAND_PTR                    ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PUMP_PWM_INTRRUPT_CAUSE_REG             (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PUMP_PWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PUMP_PWM_CONTROL_REG                    (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__CTRL )
#define PUMP_PWM_CONTROL_PTR                    ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__CTRL )
#define PUMP_PWM_STATUS_REG                     (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__STATUS )
#define PUMP_PWM_STATUS_PTR                     ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__STATUS )
#define PUMP_PWM_COUNTER_REG                    (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__COUNTER )
#define PUMP_PWM_COUNTER_PTR                    ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__COUNTER )
#define PUMP_PWM_COMP_CAP_REG                   (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__CC )
#define PUMP_PWM_COMP_CAP_PTR                   ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__CC )
#define PUMP_PWM_COMP_CAP_BUF_REG               (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define PUMP_PWM_COMP_CAP_BUF_PTR               ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define PUMP_PWM_PERIOD_REG                     (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__PERIOD )
#define PUMP_PWM_PERIOD_PTR                     ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__PERIOD )
#define PUMP_PWM_PERIOD_BUF_REG                 (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PUMP_PWM_PERIOD_BUF_PTR                 ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PUMP_PWM_TRIG_CONTROL0_REG              (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PUMP_PWM_TRIG_CONTROL0_PTR              ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PUMP_PWM_TRIG_CONTROL1_REG              (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PUMP_PWM_TRIG_CONTROL1_PTR              ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PUMP_PWM_TRIG_CONTROL2_REG              (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PUMP_PWM_TRIG_CONTROL2_PTR              ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PUMP_PWM_INTERRUPT_REQ_REG              (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__INTR )
#define PUMP_PWM_INTERRUPT_REQ_PTR              ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__INTR )
#define PUMP_PWM_INTERRUPT_SET_REG              (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define PUMP_PWM_INTERRUPT_SET_PTR              ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define PUMP_PWM_INTERRUPT_MASK_REG             (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define PUMP_PWM_INTERRUPT_MASK_PTR             ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define PUMP_PWM_INTERRUPT_MASKED_REG           (*(reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PUMP_PWM_INTERRUPT_MASKED_PTR           ( (reg32 *) PUMP_PWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define PUMP_PWM_MASK                           ((uint32)PUMP_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define PUMP_PWM_RELOAD_CC_SHIFT                (0u)
#define PUMP_PWM_RELOAD_PERIOD_SHIFT            (1u)
#define PUMP_PWM_PWM_SYNC_KILL_SHIFT            (2u)
#define PUMP_PWM_PWM_STOP_KILL_SHIFT            (3u)
#define PUMP_PWM_PRESCALER_SHIFT                (8u)
#define PUMP_PWM_UPDOWN_SHIFT                   (16u)
#define PUMP_PWM_ONESHOT_SHIFT                  (18u)
#define PUMP_PWM_QUAD_MODE_SHIFT                (20u)
#define PUMP_PWM_INV_OUT_SHIFT                  (20u)
#define PUMP_PWM_INV_COMPL_OUT_SHIFT            (21u)
#define PUMP_PWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define PUMP_PWM_RELOAD_CC_MASK                 ((uint32)(PUMP_PWM_1BIT_MASK        <<  \
                                                                            PUMP_PWM_RELOAD_CC_SHIFT))
#define PUMP_PWM_RELOAD_PERIOD_MASK             ((uint32)(PUMP_PWM_1BIT_MASK        <<  \
                                                                            PUMP_PWM_RELOAD_PERIOD_SHIFT))
#define PUMP_PWM_PWM_SYNC_KILL_MASK             ((uint32)(PUMP_PWM_1BIT_MASK        <<  \
                                                                            PUMP_PWM_PWM_SYNC_KILL_SHIFT))
#define PUMP_PWM_PWM_STOP_KILL_MASK             ((uint32)(PUMP_PWM_1BIT_MASK        <<  \
                                                                            PUMP_PWM_PWM_STOP_KILL_SHIFT))
#define PUMP_PWM_PRESCALER_MASK                 ((uint32)(PUMP_PWM_8BIT_MASK        <<  \
                                                                            PUMP_PWM_PRESCALER_SHIFT))
#define PUMP_PWM_UPDOWN_MASK                    ((uint32)(PUMP_PWM_2BIT_MASK        <<  \
                                                                            PUMP_PWM_UPDOWN_SHIFT))
#define PUMP_PWM_ONESHOT_MASK                   ((uint32)(PUMP_PWM_1BIT_MASK        <<  \
                                                                            PUMP_PWM_ONESHOT_SHIFT))
#define PUMP_PWM_QUAD_MODE_MASK                 ((uint32)(PUMP_PWM_3BIT_MASK        <<  \
                                                                            PUMP_PWM_QUAD_MODE_SHIFT))
#define PUMP_PWM_INV_OUT_MASK                   ((uint32)(PUMP_PWM_2BIT_MASK        <<  \
                                                                            PUMP_PWM_INV_OUT_SHIFT))
#define PUMP_PWM_MODE_MASK                      ((uint32)(PUMP_PWM_3BIT_MASK        <<  \
                                                                            PUMP_PWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define PUMP_PWM_CAPTURE_SHIFT                  (0u)
#define PUMP_PWM_COUNT_SHIFT                    (2u)
#define PUMP_PWM_RELOAD_SHIFT                   (4u)
#define PUMP_PWM_STOP_SHIFT                     (6u)
#define PUMP_PWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define PUMP_PWM_CAPTURE_MASK                   ((uint32)(PUMP_PWM_2BIT_MASK        <<  \
                                                                  PUMP_PWM_CAPTURE_SHIFT))
#define PUMP_PWM_COUNT_MASK                     ((uint32)(PUMP_PWM_2BIT_MASK        <<  \
                                                                  PUMP_PWM_COUNT_SHIFT))
#define PUMP_PWM_RELOAD_MASK                    ((uint32)(PUMP_PWM_2BIT_MASK        <<  \
                                                                  PUMP_PWM_RELOAD_SHIFT))
#define PUMP_PWM_STOP_MASK                      ((uint32)(PUMP_PWM_2BIT_MASK        <<  \
                                                                  PUMP_PWM_STOP_SHIFT))
#define PUMP_PWM_START_MASK                     ((uint32)(PUMP_PWM_2BIT_MASK        <<  \
                                                                  PUMP_PWM_START_SHIFT))

/* MASK */
#define PUMP_PWM_1BIT_MASK                      ((uint32)0x01u)
#define PUMP_PWM_2BIT_MASK                      ((uint32)0x03u)
#define PUMP_PWM_3BIT_MASK                      ((uint32)0x07u)
#define PUMP_PWM_6BIT_MASK                      ((uint32)0x3Fu)
#define PUMP_PWM_8BIT_MASK                      ((uint32)0xFFu)
#define PUMP_PWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define PUMP_PWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define PUMP_PWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(PUMP_PWM_QUAD_ENCODING_MODES     << PUMP_PWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(PUMP_PWM_CONFIG                  << PUMP_PWM_MODE_SHIFT)))

#define PUMP_PWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(PUMP_PWM_PWM_STOP_EVENT          << PUMP_PWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(PUMP_PWM_PWM_OUT_INVERT          << PUMP_PWM_INV_OUT_SHIFT))         |\
         ((uint32)(PUMP_PWM_PWM_OUT_N_INVERT        << PUMP_PWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(PUMP_PWM_PWM_MODE                << PUMP_PWM_MODE_SHIFT)))

#define PUMP_PWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(PUMP_PWM_PWM_RUN_MODE         << PUMP_PWM_ONESHOT_SHIFT))
            
#define PUMP_PWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(PUMP_PWM_PWM_ALIGN            << PUMP_PWM_UPDOWN_SHIFT))

#define PUMP_PWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(PUMP_PWM_PWM_KILL_EVENT      << PUMP_PWM_PWM_SYNC_KILL_SHIFT))

#define PUMP_PWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(PUMP_PWM_PWM_DEAD_TIME_CYCLE  << PUMP_PWM_PRESCALER_SHIFT))

#define PUMP_PWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(PUMP_PWM_PWM_PRESCALER        << PUMP_PWM_PRESCALER_SHIFT))

#define PUMP_PWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(PUMP_PWM_TC_PRESCALER            << PUMP_PWM_PRESCALER_SHIFT))       |\
         ((uint32)(PUMP_PWM_TC_COUNTER_MODE         << PUMP_PWM_UPDOWN_SHIFT))          |\
         ((uint32)(PUMP_PWM_TC_RUN_MODE             << PUMP_PWM_ONESHOT_SHIFT))         |\
         ((uint32)(PUMP_PWM_TC_COMP_CAP_MODE        << PUMP_PWM_MODE_SHIFT)))
        
#define PUMP_PWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(PUMP_PWM_QUAD_PHIA_SIGNAL_MODE   << PUMP_PWM_COUNT_SHIFT))           |\
         ((uint32)(PUMP_PWM_QUAD_INDEX_SIGNAL_MODE  << PUMP_PWM_RELOAD_SHIFT))          |\
         ((uint32)(PUMP_PWM_QUAD_STOP_SIGNAL_MODE   << PUMP_PWM_STOP_SHIFT))            |\
         ((uint32)(PUMP_PWM_QUAD_PHIB_SIGNAL_MODE   << PUMP_PWM_START_SHIFT)))

#define PUMP_PWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(PUMP_PWM_PWM_SWITCH_SIGNAL_MODE  << PUMP_PWM_CAPTURE_SHIFT))         |\
         ((uint32)(PUMP_PWM_PWM_COUNT_SIGNAL_MODE   << PUMP_PWM_COUNT_SHIFT))           |\
         ((uint32)(PUMP_PWM_PWM_RELOAD_SIGNAL_MODE  << PUMP_PWM_RELOAD_SHIFT))          |\
         ((uint32)(PUMP_PWM_PWM_STOP_SIGNAL_MODE    << PUMP_PWM_STOP_SHIFT))            |\
         ((uint32)(PUMP_PWM_PWM_START_SIGNAL_MODE   << PUMP_PWM_START_SHIFT)))

#define PUMP_PWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(PUMP_PWM_TC_CAPTURE_SIGNAL_MODE  << PUMP_PWM_CAPTURE_SHIFT))         |\
         ((uint32)(PUMP_PWM_TC_COUNT_SIGNAL_MODE    << PUMP_PWM_COUNT_SHIFT))           |\
         ((uint32)(PUMP_PWM_TC_RELOAD_SIGNAL_MODE   << PUMP_PWM_RELOAD_SHIFT))          |\
         ((uint32)(PUMP_PWM_TC_STOP_SIGNAL_MODE     << PUMP_PWM_STOP_SHIFT))            |\
         ((uint32)(PUMP_PWM_TC_START_SIGNAL_MODE    << PUMP_PWM_START_SHIFT)))
        
#define PUMP_PWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((PUMP_PWM__COUNT_UPDOWN0 == PUMP_PWM_TC_COUNTER_MODE)                  ||\
                 (PUMP_PWM__COUNT_UPDOWN1 == PUMP_PWM_TC_COUNTER_MODE))

#define PUMP_PWM_PWM_UPDOWN_CNT_USED                                                            \
                ((PUMP_PWM__CENTER == PUMP_PWM_PWM_ALIGN)                               ||\
                 (PUMP_PWM__ASYMMETRIC == PUMP_PWM_PWM_ALIGN))               
        
#define PUMP_PWM_PWM_PR_INIT_VALUE              (1u)
#define PUMP_PWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_PUMP_PWM_H */

/* [] END OF FILE */
