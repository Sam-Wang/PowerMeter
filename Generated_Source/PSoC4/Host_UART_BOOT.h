/*******************************************************************************
* File Name: Host_UART_BOOT.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the bootloader
*  communication interface of SCB component.
*
* Note:
*
********************************************************************************
* Copyright 2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_Host_UART_H)
#define CY_SCB_BOOT_Host_UART_H

#include "Host_UART_PVT.h"

#if (Host_UART_SCB_MODE_I2C_INC)
    #include "Host_UART_I2C.h"
#endif /* (Host_UART_SCB_MODE_I2C_INC) */

#if (Host_UART_SCB_MODE_EZI2C_INC)
    #include "Host_UART_EZI2C.h"
#endif /* (Host_UART_SCB_MODE_EZI2C_INC) */

#if (Host_UART_SCB_MODE_SPI_INC || Host_UART_SCB_MODE_UART_INC)
    #include "Host_UART_SPI_UART.h"
#endif /* (Host_UART_SCB_MODE_SPI_INC || Host_UART_SCB_MODE_UART_INC) */


/***************************************
*        Function Prototypes
***************************************/

/* Bootloader communication interface enable */
#define Host_UART_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Host_UART) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

#if (Host_UART_SCB_MODE_I2C_INC)

    #define Host_UART_I2C_BTLDR_COMM_ENABLED     (Host_UART_BTLDR_COMM_ENABLED && \
                                                            (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             Host_UART_I2C_SLAVE_CONST))

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_I2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void Host_UART_I2CCyBtldrCommStart(void);
    void Host_UART_I2CCyBtldrCommStop (void);
    void Host_UART_I2CCyBtldrCommReset(void);
    cystatus Host_UART_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus Host_UART_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Size of Read/Write buffers for I2C bootloader  */
    #define Host_UART_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
    #define Host_UART_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)
    #define Host_UART_I2C_MIN_UINT16(a, b)           ( ((uint16)(a) < (uint16) (b)) ? \
                                                                    ((uint32) (a)) : ((uint32) (b)) )
    #define Host_UART_WAIT_1_MS                      (1u)
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_I2C_BTLDR_COMM_ENABLED) */

#endif /* (Host_UART_SCB_MODE_I2C_INC) */


#if (Host_UART_SCB_MODE_EZI2C_INC)

    /* Provide EMPTY bootloader communication functions. EZI2C is NOT supported yet */
    #define Host_UART_EZI2C_BTLDR_COMM_ENABLED   (Host_UART_BTLDR_COMM_ENABLED && \
                                                         Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void Host_UART_EzI2CCyBtldrCommStart(void);
    void Host_UART_EzI2CCyBtldrCommStop (void);
    void Host_UART_EzI2CCyBtldrCommReset(void);
    cystatus Host_UART_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus Host_UART_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_EZI2C_BTLDR_COMM_ENABLED) */

#endif /* (Host_UART_SCB_MODE_EZI2C_INC) */

#if (Host_UART_SCB_MODE_SPI_INC || Host_UART_SCB_MODE_UART_INC)
    /* Provide EMPTY bootloader communication functions. SPI and UART is NOT supported yet */
    #define Host_UART_SPI_BTLDR_COMM_ENABLED     (Host_UART_BTLDR_COMM_ENABLED && \
                                                        Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    #define Host_UART_UART_BTLDR_COMM_ENABLED    (Host_UART_BTLDR_COMM_ENABLED && \
                                                        Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void Host_UART_SpiCyBtldrCommStart(void);
    void Host_UART_SpiCyBtldrCommStop (void);
    void Host_UART_SpiCyBtldrCommReset(void);
    cystatus Host_UART_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus Host_UART_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void Host_UART_UartCyBtldrCommStart(void);
    void Host_UART_UartCyBtldrCommStop (void);
    void Host_UART_UartCyBtldrCommReset(void);
    cystatus Host_UART_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus Host_UART_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_UART_BTLDR_COMM_ENABLED) */

#endif /* (Host_UART_SCB_MODE_SPI_INC || Host_UART_SCB_MODE_UART_INC) */

#if !defined (Host_UART_I2C_BTLDR_COMM_ENABLED)
    #define Host_UART_I2C_BTLDR_COMM_ENABLED     (0u)
#endif /* (Host_UART_I2C_BTLDR_COMM_ENABLED) */

#if !defined (Host_UART_EZI2C_BTLDR_COMM_ENABLED)
    #define Host_UART_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (Host_UART_EZI2C_BTLDR_COMM_ENABLED) */

#if !defined (Host_UART_SPI_BTLDR_COMM_ENABLED)
    #define Host_UART_SPI_BTLDR_COMM_ENABLED     (0u)
#endif /* (Host_UART_SPI_BTLDR_COMM_ENABLED) */

#if !defined (Host_UART_UART_BTLDR_COMM_ENABLED)
    #define Host_UART_UART_BTLDR_COMM_ENABLED    (0u)
#endif /* (Host_UART_UART_BTLDR_COMM_ENABLED) */

/* Bootloader enabled condition for each mode */
#define Host_UART_BTLDR_COMM_MODE_ENABLED    (Host_UART_I2C_BTLDR_COMM_ENABLED   || \
                                                     Host_UART_EZI2C_BTLDR_COMM_ENABLED || \
                                                     Host_UART_SPI_BTLDR_COMM_ENABLED   || \
                                                     Host_UART_UART_BTLDR_COMM_ENABLED)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_BTLDR_COMM_ENABLED)
    #if (Host_UART_BTLDR_COMM_MODE_ENABLED)
        /* Bootloader physical layer functions */
        void Host_UART_CyBtldrCommStart(void);
        void Host_UART_CyBtldrCommStop (void);
        void Host_UART_CyBtldrCommReset(void);
        cystatus Host_UART_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus Host_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (Host_UART_BTLDR_COMM_MODE_ENABLED) */

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Host_UART)
        #define CyBtldrCommStart    Host_UART_CyBtldrCommStart
        #define CyBtldrCommStop     Host_UART_CyBtldrCommStop
        #define CyBtldrCommReset    Host_UART_CyBtldrCommReset
        #define CyBtldrCommWrite    Host_UART_CyBtldrCommWrite
        #define CyBtldrCommRead     Host_UART_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Host_UART) */
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (Host_UART_BTLDR_COMM_ENABLED) */

#endif /* (CY_SCB_BOOT_Host_UART_H) */

/* [] END OF FILE */
