/*******************************************************************************
* File Name: Host_UART_SPI_UART_PVT.h
* Version 2.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_Host_UART_H)
#define CY_SCB_SPI_UART_PVT_Host_UART_H

#include "Host_UART_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if(Host_UART_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  Host_UART_rxBufferHead;
    extern volatile uint32  Host_UART_rxBufferTail;
    extern volatile uint8   Host_UART_rxBufferOverflow;
#endif /* (Host_UART_INTERNAL_RX_SW_BUFFER_CONST) */

#if(Host_UART_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  Host_UART_txBufferHead;
    extern volatile uint32  Host_UART_txBufferTail;
#endif /* (Host_UART_INTERNAL_TX_SW_BUFFER_CONST) */

#if(Host_UART_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 Host_UART_rxBufferInternal[Host_UART_RX_BUFFER_SIZE];
#endif /* (Host_UART_INTERNAL_RX_SW_BUFFER) */

#if(Host_UART_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 Host_UART_txBufferInternal[Host_UART_TX_BUFFER_SIZE];
#endif /* (Host_UART_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(Host_UART_SCB_MODE_SPI_CONST_CFG)
    void Host_UART_SpiInit(void);
#endif /* (Host_UART_SCB_MODE_SPI_CONST_CFG) */

#if(Host_UART_SPI_WAKE_ENABLE_CONST)
    void Host_UART_SpiSaveConfig(void);
    void Host_UART_SpiRestoreConfig(void);
#endif /* (Host_UART_SPI_WAKE_ENABLE_CONST) */

#if(Host_UART_SCB_MODE_UART_CONST_CFG)
    void Host_UART_UartInit(void);
#endif /* (Host_UART_SCB_MODE_UART_CONST_CFG) */

#if(Host_UART_UART_WAKE_ENABLE_CONST)
    void Host_UART_UartSaveConfig(void);
    void Host_UART_UartRestoreConfig(void);
    #define Host_UART_UartStop() \
        do{                             \
            Host_UART_UART_RX_CTRL_REG &= ~Host_UART_UART_RX_CTRL_SKIP_START; \
        }while(0)
#else
        #define Host_UART_UartStop() do{ /* Does nothing */ }while(0)

#endif /* (Host_UART_UART_WAKE_ENABLE_CONST) */

/* Interrupt processing */
#define Host_UART_SpiUartEnableIntRx(intSourceMask)  Host_UART_SetRxInterruptMode(intSourceMask)
#define Host_UART_SpiUartEnableIntTx(intSourceMask)  Host_UART_SetTxInterruptMode(intSourceMask)
uint32  Host_UART_SpiUartDisableIntRx(void);
uint32  Host_UART_SpiUartDisableIntTx(void);


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in Host_UART_SetPins() */
#define Host_UART_UART_RX_PIN_ENABLE    (Host_UART_UART_RX)
#define Host_UART_UART_TX_PIN_ENABLE    (Host_UART_UART_TX)

/* UART RTS and CTS position to be used in  Host_UART_SetPins() */
#define Host_UART_UART_RTS_PIN_ENABLE    (0x10u)
#define Host_UART_UART_CTS_PIN_ENABLE    (0x20u)

#endif /* (CY_SCB_SPI_UART_PVT_Host_UART_H) */


/* [] END OF FILE */
