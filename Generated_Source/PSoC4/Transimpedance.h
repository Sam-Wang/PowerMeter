/*******************************************************************************
* File Name: Transimpedance.h
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


#if !defined(CY_OPAMP_Transimpedance_H)
#define CY_OPAMP_Transimpedance_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*       Type Definitions
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Transimpedance_BACKUP_STRUCT;


/**************************************
*        Function Prototypes
**************************************/
void Transimpedance_Init(void);
void Transimpedance_Enable(void);
void Transimpedance_Start(void);
void Transimpedance_Stop(void);
void Transimpedance_SetPower(uint32 power);
void Transimpedance_PumpControl(uint32 onOff);
void Transimpedance_Sleep(void);
void Transimpedance_Wakeup(void);
void Transimpedance_SaveConfig(void);
void Transimpedance_RestoreConfig(void);


/**************************************
*           API Constants
**************************************/

/* Parameters for SetPower() function */
#define Transimpedance_LOW_POWER      (1u)
#define Transimpedance_MED_POWER      (2u)
#define Transimpedance_HIGH_POWER     (3u)


/* Parameters for PumpControl() function */
#define Transimpedance_PUMP_ON        (1u)
#define Transimpedance_PUMP_OFF       (0u)


/***************************************
*   Initial Parameter Constants
****************************************/

#define Transimpedance_OUTPUT_CURRENT         (1u)
#define Transimpedance_POWER                  (3u)
#define Transimpedance_MODE                   (0u)
#define Transimpedance_OA_COMP_TRIM_VALUE     (3u)
#define Transimpedance_DEEPSLEEP_SUPPORT      (0u)


/***************************************
*    Variables with External Linkage
***************************************/

extern uint8  Transimpedance_initVar;


/**************************************
*             Registers
**************************************/
#define Transimpedance_CTB_CTRL_REG       (*(reg32 *) Transimpedance_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define Transimpedance_CTB_CTRL_PTR       ( (reg32 *) Transimpedance_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define Transimpedance_OA_RES_CTRL_REG    (*(reg32 *) Transimpedance_cy_psoc4_abuf__OA_RES_CTRL)
#define Transimpedance_OA_RES_CTRL_PTR    ( (reg32 *) Transimpedance_cy_psoc4_abuf__OA_RES_CTRL)
#define Transimpedance_OA_COMP_TRIM_REG   (*(reg32 *) Transimpedance_cy_psoc4_abuf__OA_COMP_TRIM)
#define Transimpedance_OA_COMP_TRIM_PTR   ( (reg32 *) Transimpedance_cy_psoc4_abuf__OA_COMP_TRIM)


/***************************************
*        Registers Constants
***************************************/

/* Transimpedance_CTB_CTRL_REG */
#define Transimpedance_CTB_CTRL_DEEPSLEEP_ON_SHIFT    (30u)   /* [30] Selects behavior CTB IP in the DeepSleep power mode */
#define Transimpedance_CTB_CTRL_ENABLED_SHIFT         (31u)   /* [31] Enable of the CTB IP */


#define Transimpedance_CTB_CTRL_DEEPSLEEP_ON          ((uint32) 0x01u << Transimpedance_CTB_CTRL_DEEPSLEEP_ON_SHIFT)
#define Transimpedance_CTB_CTRL_ENABLED               ((uint32) 0x01u << Transimpedance_CTB_CTRL_ENABLED_SHIFT)


/* Transimpedance_OA_RES_CTRL_REG */
#define Transimpedance_OA_PWR_MODE_SHIFT          (0u)    /* [1:0]    Power level */
#define Transimpedance_OA_DRIVE_STR_SEL_SHIFT     (2u)    /* [2]      Opamp output strenght select: 0 - 1x, 1 - 10x */
#define Transimpedance_OA_COMP_EN_SHIFT           (4u)    /* [4]      CTB IP mode: 0 - Opamp, 1 - Comparator  */
#define Transimpedance_OA_PUMP_EN_SHIFT           (11u)   /* [11]     Pump enable */


#define Transimpedance_OA_PWR_MODE                ((uint32) 0x02u << Transimpedance_OA_PWR_MODE_SHIFT)
#define Transimpedance_OA_PWR_MODE_MASK           ((uint32) 0x03u << Transimpedance_OA_PWR_MODE_SHIFT)
#define Transimpedance_OA_DRIVE_STR_SEL_1X        ((uint32) 0x00u << Transimpedance_OA_DRIVE_STR_SEL_SHIFT)
#define Transimpedance_OA_DRIVE_STR_SEL_10X       ((uint32) 0x01u << Transimpedance_OA_DRIVE_STR_SEL_SHIFT)
#define Transimpedance_OA_DRIVE_STR_SEL_MASK      ((uint32) 0x01u << Transimpedance_OA_DRIVE_STR_SEL_SHIFT)
#define Transimpedance_OA_COMP_EN                 ((uint32) 0x00u << Transimpedance_OA_COMP_EN_SHIFT)
#define Transimpedance_OA_PUMP_EN                 ((uint32) 0x01u << Transimpedance_OA_PUMP_EN_SHIFT)


/***************************************
*       Init Macros Definitions
***************************************/

#define Transimpedance_GET_DEEPSLEEP_ON(deepSleep)    ((0u != (deepSleep)) ? (Transimpedance_CTB_CTRL_DEEPSLEEP_ON) : (0u))
#define Transimpedance_GET_OA_DRIVE_STR(current)      ((0u != (current)) ? (Transimpedance_OA_DRIVE_STR_SEL_10X) : \
                                                                             (Transimpedance_OA_DRIVE_STR_SEL_1X))
#define Transimpedance_GET_OA_PWR_MODE(mode)          ((mode) & Transimpedance_OA_PWR_MODE_MASK)
#define Transimpedance_CHECK_PWR_MODE_OFF             (0u != (Transimpedance_OA_RES_CTRL_REG & \
                                                                Transimpedance_OA_PWR_MODE_MASK))

/* Returns true if component available in Deep Sleep power mode*/ 
#define Transimpedance_CHECK_DEEPSLEEP_SUPPORT        (0u != Transimpedance_DEEPSLEEP_SUPPORT) 

#define Transimpedance_DEFAULT_CTB_CTRL (Transimpedance_GET_DEEPSLEEP_ON(Transimpedance_DEEPSLEEP_SUPPORT) | \
                                           Transimpedance_CTB_CTRL_ENABLED)

#define Transimpedance_DEFAULT_OA_RES_CTRL (Transimpedance_OA_COMP_EN | \
                                              Transimpedance_GET_OA_DRIVE_STR(Transimpedance_OUTPUT_CURRENT))

#define Transimpedance_DEFAULT_OA_COMP_TRIM_REG (Transimpedance_OA_COMP_TRIM_VALUE)


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define Transimpedance_LOWPOWER                   (Transimpedance_LOW_POWER)
#define Transimpedance_MEDPOWER                   (Transimpedance_MED_POWER)
#define Transimpedance_HIGHPOWER                  (Transimpedance_HIGH_POWER)

/* PUMP ON/OFF defines */
#define Transimpedance_PUMPON                     (Transimpedance_PUMP_ON)
#define Transimpedance_PUMPOFF                    (Transimpedance_PUMP_OFF)

#define Transimpedance_OA_CTRL                    (Transimpedance_CTB_CTRL_REG)
#define Transimpedance_OA_RES_CTRL                (Transimpedance_OA_RES_CTRL_REG)

/* Bit Field  OA_CTRL */
#define Transimpedance_OA_CTB_EN_SHIFT            (Transimpedance_CTB_CTRL_ENABLED_SHIFT)
#define Transimpedance_OA_PUMP_CTRL_SHIFT         (Transimpedance_OA_PUMP_EN_SHIFT)
#define Transimpedance_OA_PUMP_EN_MASK            (0x800u)
#define Transimpedance_PUMP_PROTECT_MASK          (1u)


#endif    /* CY_OPAMP_Transimpedance_H */


/* [] END OF FILE */
