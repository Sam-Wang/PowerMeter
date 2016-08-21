/*******************************************************************************
* File Name: LED_driver.h
* Version 1.10
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Opamp (Analog Buffer) Component.
*
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_OPAMP_LED_driver_H)
#define CY_OPAMP_LED_driver_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*       Type Definitions
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} LED_driver_BACKUP_STRUCT;


/**************************************
*        Function Prototypes
**************************************/
void LED_driver_Init(void);
void LED_driver_Enable(void);
void LED_driver_Start(void);
void LED_driver_Stop(void);
void LED_driver_SetPower(uint32 power);
void LED_driver_PumpControl(uint32 onOff);
void LED_driver_Sleep(void);
void LED_driver_Wakeup(void);
void LED_driver_SaveConfig(void);
void LED_driver_RestoreConfig(void);


/**************************************
*           API Constants
**************************************/

/* Parameters for SetPower() function */
#define LED_driver_LOW_POWER      (1u)
#define LED_driver_MED_POWER      (2u)
#define LED_driver_HIGH_POWER     (3u)


/* Parameters for PumpControl() function */
#define LED_driver_PUMP_ON        (1u)
#define LED_driver_PUMP_OFF       (0u)


/***************************************
*   Initial Parameter Constants
****************************************/

#define LED_driver_OUTPUT_CURRENT         (1u)
#define LED_driver_POWER                  (3u)
#define LED_driver_MODE                   (0u)
#define LED_driver_OA_COMP_TRIM_VALUE     (3u)
#define LED_driver_DEEPSLEEP_SUPPORT      (0u)


/***************************************
*    Variables with External Linkage
***************************************/

extern uint8  LED_driver_initVar;


/**************************************
*             Registers
**************************************/
#define LED_driver_CTB_CTRL_REG       (*(reg32 *) LED_driver_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define LED_driver_CTB_CTRL_PTR       ( (reg32 *) LED_driver_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define LED_driver_OA_RES_CTRL_REG    (*(reg32 *) LED_driver_cy_psoc4_abuf__OA_RES_CTRL)
#define LED_driver_OA_RES_CTRL_PTR    ( (reg32 *) LED_driver_cy_psoc4_abuf__OA_RES_CTRL)
#define LED_driver_OA_COMP_TRIM_REG   (*(reg32 *) LED_driver_cy_psoc4_abuf__OA_COMP_TRIM)
#define LED_driver_OA_COMP_TRIM_PTR   ( (reg32 *) LED_driver_cy_psoc4_abuf__OA_COMP_TRIM)


/***************************************
*        Registers Constants
***************************************/

/* LED_driver_CTB_CTRL_REG */
#define LED_driver_CTB_CTRL_DEEPSLEEP_ON_SHIFT    (30u)   /* [30] Selects behavior CTB IP in the DeepSleep power mode */
#define LED_driver_CTB_CTRL_ENABLED_SHIFT         (31u)   /* [31] Enable of the CTB IP */


#define LED_driver_CTB_CTRL_DEEPSLEEP_ON          ((uint32) 0x01u << LED_driver_CTB_CTRL_DEEPSLEEP_ON_SHIFT)
#define LED_driver_CTB_CTRL_ENABLED               ((uint32) 0x01u << LED_driver_CTB_CTRL_ENABLED_SHIFT)


/* LED_driver_OA_RES_CTRL_REG */
#define LED_driver_OA_PWR_MODE_SHIFT          (0u)    /* [1:0]    Power level */
#define LED_driver_OA_DRIVE_STR_SEL_SHIFT     (2u)    /* [2]      Opamp output strenght select: 0 - 1x, 1 - 10x */
#define LED_driver_OA_COMP_EN_SHIFT           (4u)    /* [4]      CTB IP mode: 0 - Opamp, 1 - Comparator  */
#define LED_driver_OA_PUMP_EN_SHIFT           (11u)   /* [11]     Pump enable */


#define LED_driver_OA_PWR_MODE                ((uint32) 0x02u << LED_driver_OA_PWR_MODE_SHIFT)
#define LED_driver_OA_PWR_MODE_MASK           ((uint32) 0x03u << LED_driver_OA_PWR_MODE_SHIFT)
#define LED_driver_OA_DRIVE_STR_SEL_1X        ((uint32) 0x00u << LED_driver_OA_DRIVE_STR_SEL_SHIFT)
#define LED_driver_OA_DRIVE_STR_SEL_10X       ((uint32) 0x01u << LED_driver_OA_DRIVE_STR_SEL_SHIFT)
#define LED_driver_OA_DRIVE_STR_SEL_MASK      ((uint32) 0x01u << LED_driver_OA_DRIVE_STR_SEL_SHIFT)
#define LED_driver_OA_COMP_EN                 ((uint32) 0x00u << LED_driver_OA_COMP_EN_SHIFT)
#define LED_driver_OA_PUMP_EN                 ((uint32) 0x01u << LED_driver_OA_PUMP_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define LED_driver_GET_DEEPSLEEP_ON(deepSleep)    ((0u != (deepSleep)) ? (LED_driver_CTB_CTRL_DEEPSLEEP_ON) : (0u))
#define LED_driver_GET_OA_DRIVE_STR(current)      ((0u != (current)) ? (LED_driver_OA_DRIVE_STR_SEL_10X) : \
                                                                             (LED_driver_OA_DRIVE_STR_SEL_1X))
#define LED_driver_GET_OA_PWR_MODE(mode)          ((mode) & LED_driver_OA_PWR_MODE_MASK)
#define LED_driver_CHECK_PWR_MODE_OFF             (0u != (LED_driver_OA_RES_CTRL_REG & \
                                                                LED_driver_OA_PWR_MODE_MASK))

/* Returns true if component available in Deep Sleep power mode*/ 
#define LED_driver_CHECK_DEEPSLEEP_SUPPORT        (0u != LED_driver_DEEPSLEEP_SUPPORT) 

#define LED_driver_DEFAULT_CTB_CTRL (LED_driver_GET_DEEPSLEEP_ON(LED_driver_DEEPSLEEP_SUPPORT) | \
                                           LED_driver_CTB_CTRL_ENABLED)

#define LED_driver_DEFAULT_OA_RES_CTRL (LED_driver_OA_COMP_EN | \
                                              LED_driver_GET_OA_DRIVE_STR(LED_driver_OUTPUT_CURRENT))

#define LED_driver_DEFAULT_OA_COMP_TRIM_REG (LED_driver_OA_COMP_TRIM_VALUE)


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define LED_driver_LOWPOWER                   (LED_driver_LOW_POWER)
#define LED_driver_MEDPOWER                   (LED_driver_MED_POWER)
#define LED_driver_HIGHPOWER                  (LED_driver_HIGH_POWER)

/* PUMP ON/OFF defines */
#define LED_driver_PUMPON                     (LED_driver_PUMP_ON)
#define LED_driver_PUMPOFF                    (LED_driver_PUMP_OFF)

#define LED_driver_OA_CTRL                    (LED_driver_CTB_CTRL_REG)
#define LED_driver_OA_RES_CTRL                (LED_driver_OA_RES_CTRL_REG)

/* Bit Field  OA_CTRL */
#define LED_driver_OA_CTB_EN_SHIFT            (LED_driver_CTB_CTRL_ENABLED_SHIFT)
#define LED_driver_OA_PUMP_CTRL_SHIFT         (LED_driver_OA_PUMP_EN_SHIFT)
#define LED_driver_OA_PUMP_EN_MASK            (0x800u)
#define LED_driver_PUMP_PROTECT_MASK          (1u)


#endif    /* CY_OPAMP_LED_driver_H */


/* [] END OF FILE */
