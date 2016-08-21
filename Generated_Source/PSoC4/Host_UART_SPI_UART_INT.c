/*******************************************************************************
* File Name: Host_UART_SPI_UART_INT.c
* Version 2.0
*
* Description:
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Host_UART_PVT.h"
#include "Host_UART_SPI_UART_PVT.h"


/*******************************************************************************
* Function Name: Host_UART_SPI_UART_ISR
********************************************************************************
*
* Summary:
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(Host_UART_SPI_UART_ISR)
{
#if(Host_UART_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
    uint32 dataRx;
#endif /* (Host_UART_INTERNAL_RX_SW_BUFFER_CONST) */

#if(Host_UART_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (Host_UART_INTERNAL_TX_SW_BUFFER_CONST) */

    if(NULL != Host_UART_customIntrHandler)
    {
        Host_UART_customIntrHandler();
    }

    #if(Host_UART_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        Host_UART_ClearSpiExtClkInterruptSource(Host_UART_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if(Host_UART_CHECK_RX_SW_BUFFER)
    {
        if(Host_UART_CHECK_INTR_RX_MASKED(Host_UART_INTR_RX_NOT_EMPTY))
        {
            while(0u != Host_UART_GET_RX_FIFO_ENTRIES)
            {
                /* Get data from RX FIFO */
                dataRx = Host_UART_RX_FIFO_RD_REG;

                /* Move local head index */
                locHead = (Host_UART_rxBufferHead + 1u);

                /* Adjust local head index */
                if(Host_UART_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if(locHead == Host_UART_rxBufferTail)
                {
                    /* Overflow: through away new data */
                    Host_UART_rxBufferOverflow = (uint8) Host_UART_INTR_RX_OVERFLOW;
                }
                else
                {
                    /* Store received data */
                    Host_UART_PutWordInRxBuffer(locHead, dataRx);

                    /* Move head index */
                    Host_UART_rxBufferHead = locHead;
                }
            }

            Host_UART_ClearRxInterruptSource(Host_UART_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if(Host_UART_CHECK_TX_SW_BUFFER)
    {
        if(Host_UART_CHECK_INTR_TX_MASKED(Host_UART_INTR_TX_NOT_FULL))
        {
            /* Put data into TX FIFO */
            while(Host_UART_SPI_UART_FIFO_SIZE != Host_UART_GET_TX_FIFO_ENTRIES)
            {
                /* Check for room in TX software buffer */
                if(Host_UART_txBufferHead != Host_UART_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (Host_UART_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if(Host_UART_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    Host_UART_TX_FIFO_WR_REG = Host_UART_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    Host_UART_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    Host_UART_DISABLE_INTR_TX(Host_UART_INTR_TX_NOT_FULL);
                    break;
                }
            }

            Host_UART_ClearTxInterruptSource(Host_UART_INTR_TX_NOT_FULL);
        }
    }
    #endif
}


/* [] END OF FILE */
