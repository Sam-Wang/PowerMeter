/*******************************************************************************
* File Name: Host_UART_BOOT.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the bootloader
*  communication support in the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Host_UART_BOOT.h"


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_BTLDR_COMM_MODE_ENABLED)

/*******************************************************************************
* Function Name: Host_UART_CyBtldrCommStart
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStart function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_CyBtldrCommStart(void)
{
    #if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(Host_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            Host_UART_I2CCyBtldrCommStart();
        }
        else if(Host_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            Host_UART_SpiCyBtldrCommStart();
        }
        else if(Host_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            Host_UART_UartCyBtldrCommStart();
        }
        else if(Host_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
             Host_UART_EzI2CCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(Host_UART_SCB_MODE_I2C_CONST_CFG)
        Host_UART_I2CCyBtldrCommStart();

    #elif(Host_UART_SCB_MODE_SPI_CONST_CFG)
        Host_UART_SpiCyBtldrCommStart();

    #elif(Host_UART_SCB_MODE_UART_CONST_CFG)
        Host_UART_UartCyBtldrCommStart();

    #elif(Host_UART_SCB_MODE_EZI2C_CONST_CFG)
        Host_UART_EzI2CCyBtldrCommStart();

    #else
        /* Unknown mode */

    #endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Host_UART_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStop function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_CyBtldrCommStop(void)
{
    #if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(Host_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            Host_UART_I2CCyBtldrCommStop();
        }
        else if(Host_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            Host_UART_SpiCyBtldrCommStop();
        }
        else if(Host_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            Host_UART_UartCyBtldrCommStop();
        }
        else if(Host_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            Host_UART_EzI2CCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(Host_UART_SCB_MODE_I2C_CONST_CFG)
        Host_UART_I2CCyBtldrCommStop();

    #elif(Host_UART_SCB_MODE_SPI_CONST_CFG)
        Host_UART_SpiCyBtldrCommStop();

    #elif(Host_UART_SCB_MODE_UART_CONST_CFG)
        Host_UART_UartCyBtldrCommStop();

    #elif(Host_UART_SCB_MODE_EZI2C_CONST_CFG)
        Host_UART_EzI2CCyBtldrCommStop();

    #else
        /* Unknown mode */

    #endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Host_UART_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommReset function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_CyBtldrCommReset(void)
{
    #if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(Host_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            Host_UART_I2CCyBtldrCommReset();
        }
        else if(Host_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            Host_UART_SpiCyBtldrCommReset();
        }
        else if(Host_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            Host_UART_UartCyBtldrCommReset();
        }
        else if(Host_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            Host_UART_EzI2CCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(Host_UART_SCB_MODE_I2C_CONST_CFG)
        Host_UART_I2CCyBtldrCommReset();

    #elif(Host_UART_SCB_MODE_SPI_CONST_CFG)
        Host_UART_SpiCyBtldrCommReset();

    #elif(Host_UART_SCB_MODE_UART_CONST_CFG)
        Host_UART_UartCyBtldrCommReset();

    #elif(Host_UART_SCB_MODE_EZI2C_CONST_CFG)
        Host_UART_EzI2CCyBtldrCommReset();

    #else
        /* Unknown mode */

    #endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Host_UART_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommRead function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to storage for the block of data to be read from the
*            bootloader host
*  size:     Number of bytes to be read.
*  count:    Pointer to the variable to write the number of bytes actually
*            read.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus Host_UART_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(Host_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = Host_UART_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(Host_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = Host_UART_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(Host_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            status = Host_UART_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(Host_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = Host_UART_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }

    #elif(Host_UART_SCB_MODE_I2C_CONST_CFG)
        status = Host_UART_I2CCyBtldrCommRead(pData, size, count, timeOut);

    #elif(Host_UART_SCB_MODE_SPI_CONST_CFG)
        status = Host_UART_SpiCyBtldrCommRead(pData, size, count, timeOut);

    #elif(Host_UART_SCB_MODE_UART_CONST_CFG)
        status = Host_UART_UartCyBtldrCommRead(pData, size, count, timeOut);

    #elif(Host_UART_SCB_MODE_EZI2C_CONST_CFG)
        status = Host_UART_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: Host_UART_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommWrite  function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to the block of data to be written to the bootloader host.
*  size:     Number of bytes to be written.
*  count:    Pointer to the variable to write the number of bytes actually
*            written.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus Host_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if(Host_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = Host_UART_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(Host_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = Host_UART_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(Host_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            status = Host_UART_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(Host_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = Host_UART_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode */
        }
    #elif(Host_UART_SCB_MODE_I2C_CONST_CFG)
        status = Host_UART_I2CCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(Host_UART_SCB_MODE_SPI_CONST_CFG)
        status = Host_UART_SpiCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(Host_UART_SCB_MODE_UART_CONST_CFG)
        status = Host_UART_UartCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(Host_UART_SCB_MODE_EZI2C_CONST_CFG)
        status = Host_UART_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode */

    #endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_BTLDR_COMM_MODE_ENABLED) */


/* [] END OF FILE */
