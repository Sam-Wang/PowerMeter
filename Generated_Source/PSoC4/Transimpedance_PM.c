/*******************************************************************************
* File Name: Transimpedance_PM.c
* Version 1.10
*
* Description:
*  This file provides the power management source code to the API for the
*  Opamp (Analog Buffer) component.
*
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Transimpedance.h"

#if(!Transimpedance_CHECK_DEEPSLEEP_SUPPORT)
    static Transimpedance_BACKUP_STRUCT Transimpedance_backup =
    {
        0u, /* enableState */
    };
#endif /* (Transimpedance_CHECK_DEEPSLEEP_SUPPORT) */


/*******************************************************************************
* Function Name: Transimpedance_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Transimpedance_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Transimpedance_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Transimpedance_RestoreConfig(void)
{
    
}


/*******************************************************************************
* Function Name: Transimpedance_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. The Sleep() API 
*  saves the current component state. Call the Sleep() function before calling the 
*  CySysPmDeepSleep() or the CySysPmHibernate() functions. The "Deep sleep operation" 
*  option has an influence on this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Transimpedance_backup: The structure field 'enableState' is modified
*  depending on the enable state of the block before entering the sleep mode.
*
*******************************************************************************/
void Transimpedance_Sleep(void)
{
#if(!Transimpedance_CHECK_DEEPSLEEP_SUPPORT)
    if(Transimpedance_CHECK_PWR_MODE_OFF)
    {
        Transimpedance_backup.enableState = 1u;
        Transimpedance_Stop();
    }
    else /* The component is disabled */
    {
        Transimpedance_backup.enableState = 0u;
    }
#endif /* (Transimpedance_CHECK_DEEPSLEEP_SUPPORT) */
}


/*******************************************************************************
* Function Name: Transimpedance_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when Sleep() 
*  is called. If the component has been enabled before the Sleep() function is 
*  called, the Wakeup() function will also re-enable the component.
*  The "Deep sleep operation" option has an influence on this function
*  implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Transimpedance_backup: The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Transimpedance_Wakeup(void)
{
#if(!Transimpedance_CHECK_DEEPSLEEP_SUPPORT)
    if(0u != Transimpedance_backup.enableState)
    {
        /* Enable Opamp's operation */
        Transimpedance_Enable();
    } /* Do nothing if Opamp was disabled before */
#endif /* (Transimpedance_CHECK_DEEPSLEEP_SUPPORT) */
}


/* [] END OF FILE */
