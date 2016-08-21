/*******************************************************************************
* File Name: Host_UART_PM.c
* Version 2.0
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Host_UART.h"
#include "Host_UART_PVT.h"

#if(Host_UART_SCB_MODE_I2C_INC)
    #include "Host_UART_I2C_PVT.h"
#endif /* (Host_UART_SCB_MODE_I2C_INC) */

#if(Host_UART_SCB_MODE_EZI2C_INC)
    #include "Host_UART_EZI2C_PVT.h"
#endif /* (Host_UART_SCB_MODE_EZI2C_INC) */

#if(Host_UART_SCB_MODE_SPI_INC || Host_UART_SCB_MODE_UART_INC)
    #include "Host_UART_SPI_UART_PVT.h"
#endif /* (Host_UART_SCB_MODE_SPI_INC || Host_UART_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
   (Host_UART_SCB_MODE_I2C_CONST_CFG   && (!Host_UART_I2C_WAKE_ENABLE_CONST))   || \
   (Host_UART_SCB_MODE_EZI2C_CONST_CFG && (!Host_UART_EZI2C_WAKE_ENABLE_CONST)) || \
   (Host_UART_SCB_MODE_SPI_CONST_CFG   && (!Host_UART_SPI_WAKE_ENABLE_CONST))   || \
   (Host_UART_SCB_MODE_UART_CONST_CFG  && (!Host_UART_UART_WAKE_ENABLE_CONST)))

    Host_UART_BACKUP_STRUCT Host_UART_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: Host_UART_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The "Enable wakeup from Sleep Mode" selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_Sleep(void)
{
#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    if(Host_UART_SCB_WAKE_ENABLE_CHECK)
    {
        if(Host_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            Host_UART_I2CSaveConfig();
        }
        else if(Host_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            Host_UART_EzI2CSaveConfig();
        }
    #if(!Host_UART_CY_SCBIP_V1)
        else if(Host_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            Host_UART_SpiSaveConfig();
        }
        else if(Host_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            Host_UART_UartSaveConfig();
        }
    #endif /* (!Host_UART_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        Host_UART_backup.enableState = (uint8) Host_UART_GET_CTRL_ENABLED;

        if(0u != Host_UART_backup.enableState)
        {
            Host_UART_Stop();
        }
    }

#else

    #if (Host_UART_SCB_MODE_I2C_CONST_CFG && Host_UART_I2C_WAKE_ENABLE_CONST)
        Host_UART_I2CSaveConfig();

    #elif (Host_UART_SCB_MODE_EZI2C_CONST_CFG && Host_UART_EZI2C_WAKE_ENABLE_CONST)
        Host_UART_EzI2CSaveConfig();

    #elif (Host_UART_SCB_MODE_SPI_CONST_CFG && Host_UART_SPI_WAKE_ENABLE_CONST)
        Host_UART_SpiSaveConfig();

    #elif (Host_UART_SCB_MODE_UART_CONST_CFG && Host_UART_UART_WAKE_ENABLE_CONST)
        Host_UART_UartSaveConfig();

    #else

        Host_UART_backup.enableState = (uint8) Host_UART_GET_CTRL_ENABLED;

        if(0u != Host_UART_backup.enableState)
        {
            Host_UART_Stop();
        }

    #endif /* defined (Host_UART_SCB_MODE_I2C_CONST_CFG) && (Host_UART_I2C_WAKE_ENABLE_CONST) */

#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Host_UART_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting
*  Deep Sleep. The "Enable wakeup from Sleep Mode" option has an influence
*  on this function implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_Wakeup(void)
{
#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    if(Host_UART_SCB_WAKE_ENABLE_CHECK)
    {
        if(Host_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            Host_UART_I2CRestoreConfig();
        }
        else if(Host_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            Host_UART_EzI2CRestoreConfig();
        }
    #if(!Host_UART_CY_SCBIP_V1)
        else if(Host_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            Host_UART_SpiRestoreConfig();
        }
        else if(Host_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            Host_UART_UartRestoreConfig();
        }
    #endif /* (!Host_UART_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != Host_UART_backup.enableState)
        {
            Host_UART_Enable();
        }
    }

#else

    #if (Host_UART_SCB_MODE_I2C_CONST_CFG  && Host_UART_I2C_WAKE_ENABLE_CONST)
        Host_UART_I2CRestoreConfig();

    #elif (Host_UART_SCB_MODE_EZI2C_CONST_CFG && Host_UART_EZI2C_WAKE_ENABLE_CONST)
        Host_UART_EzI2CRestoreConfig();

    #elif (Host_UART_SCB_MODE_SPI_CONST_CFG && Host_UART_SPI_WAKE_ENABLE_CONST)
        Host_UART_SpiRestoreConfig();

    #elif (Host_UART_SCB_MODE_UART_CONST_CFG && Host_UART_UART_WAKE_ENABLE_CONST)
        Host_UART_UartRestoreConfig();

    #else

        if(0u != Host_UART_backup.enableState)
        {
            Host_UART_Enable();
        }

    #endif /* (Host_UART_I2C_WAKE_ENABLE_CONST) */

#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
