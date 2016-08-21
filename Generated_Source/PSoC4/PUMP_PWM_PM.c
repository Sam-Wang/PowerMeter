/*******************************************************************************
* File Name: PUMP_PWM_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
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

static PUMP_PWM_BACKUP_STRUCT PUMP_PWM_backup;


/*******************************************************************************
* Function Name: PUMP_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PUMP_PWM_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_Sleep(void)
{
    if(0u != (PUMP_PWM_BLOCK_CONTROL_REG & PUMP_PWM_MASK))
    {
        PUMP_PWM_backup.enableState = 1u;
    }
    else
    {
        PUMP_PWM_backup.enableState = 0u;
    }

    PUMP_PWM_Stop();
    PUMP_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: PUMP_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PUMP_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PUMP_PWM_Wakeup(void)
{
    PUMP_PWM_RestoreConfig();

    if(0u != PUMP_PWM_backup.enableState)
    {
        PUMP_PWM_Enable();
    }
}


/* [] END OF FILE */
