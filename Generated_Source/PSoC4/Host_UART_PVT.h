/*******************************************************************************
* File Name: .h
* Version 2.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_Host_UART_H)
#define CY_SCB_PVT_Host_UART_H

#include "Host_UART.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define Host_UART_SetI2CExtClkInterruptMode(interruptMask) Host_UART_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define Host_UART_ClearI2CExtClkInterruptSource(interruptMask) Host_UART_CLEAR_INTR_I2C_EC(interruptMask)
#define Host_UART_GetI2CExtClkInterruptSource()                (Host_UART_INTR_I2C_EC_REG)
#define Host_UART_GetI2CExtClkInterruptMode()                  (Host_UART_INTR_I2C_EC_MASK_REG)
#define Host_UART_GetI2CExtClkInterruptSourceMasked()          (Host_UART_INTR_I2C_EC_MASKED_REG)

#if (!Host_UART_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define Host_UART_SetSpiExtClkInterruptMode(interruptMask) \
                                                                Host_UART_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define Host_UART_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                Host_UART_CLEAR_INTR_SPI_EC(interruptMask)
    #define Host_UART_GetExtSpiClkInterruptSource()                 (Host_UART_INTR_SPI_EC_REG)
    #define Host_UART_GetExtSpiClkInterruptMode()                   (Host_UART_INTR_SPI_EC_MASK_REG)
    #define Host_UART_GetExtSpiClkInterruptSourceMasked()           (Host_UART_INTR_SPI_EC_MASKED_REG)
#endif /* (!Host_UART_CY_SCBIP_V1) */

#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void Host_UART_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if !defined (CY_REMOVE_Host_UART_CUSTOM_INTR_HANDLER)
    extern cyisraddress Host_UART_customIntrHandler;
#endif /* !defined (CY_REMOVE_Host_UART_CUSTOM_INTR_HANDLER) */

extern Host_UART_BACKUP_STRUCT Host_UART_backup;

#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 Host_UART_scbMode;
    extern uint8 Host_UART_scbEnableWake;
    extern uint8 Host_UART_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 Host_UART_mode;
    extern uint8 Host_UART_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * Host_UART_rxBuffer;
    extern uint8   Host_UART_rxDataBits;
    extern uint32  Host_UART_rxBufferSize;

    extern volatile uint8 * Host_UART_txBuffer;
    extern uint8   Host_UART_txDataBits;
    extern uint32  Host_UART_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 Host_UART_numberOfAddr;
    extern uint8 Host_UART_subAddrSize;
#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*        Conditional Macro
****************************************/

#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define Host_UART_SCB_MODE_I2C_RUNTM_CFG     (Host_UART_SCB_MODE_I2C      == Host_UART_scbMode)
    #define Host_UART_SCB_MODE_SPI_RUNTM_CFG     (Host_UART_SCB_MODE_SPI      == Host_UART_scbMode)
    #define Host_UART_SCB_MODE_UART_RUNTM_CFG    (Host_UART_SCB_MODE_UART     == Host_UART_scbMode)
    #define Host_UART_SCB_MODE_EZI2C_RUNTM_CFG   (Host_UART_SCB_MODE_EZI2C    == Host_UART_scbMode)
    #define Host_UART_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (Host_UART_SCB_MODE_UNCONFIG == Host_UART_scbMode)

    /* Defines wakeup enable */
    #define Host_UART_SCB_WAKE_ENABLE_CHECK       (0u != Host_UART_scbEnableWake)
#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!Host_UART_CY_SCBIP_V1)
    #define Host_UART_SCB_PINS_NUMBER    (7u)
#else
    #define Host_UART_SCB_PINS_NUMBER    (2u)
#endif /* (!Host_UART_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_Host_UART_H) */


/* [] END OF FILE */
