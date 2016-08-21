/*******************************************************************************
* File Name: Host_UART_SPI_UART.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_Host_UART_H)
#define CY_SCB_SPI_UART_Host_UART_H

#include "Host_UART.h"


/***************************************
*   SPI Initial Parameter Constants
****************************************/

#define Host_UART_SPI_MODE                   (0u)
#define Host_UART_SPI_SUB_MODE               (0u)
#define Host_UART_SPI_CLOCK_MODE             (0u)
#define Host_UART_SPI_OVS_FACTOR             (16u)
#define Host_UART_SPI_MEDIAN_FILTER_ENABLE   (0u)
#define Host_UART_SPI_LATE_MISO_SAMPLE_ENABLE (0u)
#define Host_UART_SPI_RX_DATA_BITS_NUM       (8u)
#define Host_UART_SPI_TX_DATA_BITS_NUM       (8u)
#define Host_UART_SPI_WAKE_ENABLE            (0u)
#define Host_UART_SPI_BITS_ORDER             (1u)
#define Host_UART_SPI_TRANSFER_SEPARATION    (1u)
#define Host_UART_SPI_NUMBER_OF_SS_LINES     (1u)
#define Host_UART_SPI_RX_BUFFER_SIZE         (8u)
#define Host_UART_SPI_TX_BUFFER_SIZE         (8u)

#define Host_UART_SPI_INTERRUPT_MODE         (0u)

#define Host_UART_SPI_INTR_RX_MASK           (0u)
#define Host_UART_SPI_INTR_TX_MASK           (0u)

#define Host_UART_SPI_RX_TRIGGER_LEVEL       (7u)
#define Host_UART_SPI_TX_TRIGGER_LEVEL       (0u)

#define Host_UART_SPI_BYTE_MODE_ENABLE       (0u)
#define Host_UART_SPI_FREE_RUN_SCLK_ENABLE   (0u)
#define Host_UART_SPI_SS0_POLARITY           (0u)
#define Host_UART_SPI_SS1_POLARITY           (0u)
#define Host_UART_SPI_SS2_POLARITY           (0u)
#define Host_UART_SPI_SS3_POLARITY           (0u)


/***************************************
*   UART Initial Parameter Constants
****************************************/

#define Host_UART_UART_SUB_MODE              (0u)
#define Host_UART_UART_DIRECTION             (3u)
#define Host_UART_UART_DATA_BITS_NUM         (8u)
#define Host_UART_UART_PARITY_TYPE           (2u)
#define Host_UART_UART_STOP_BITS_NUM         (2u)
#define Host_UART_UART_OVS_FACTOR            (16u)
#define Host_UART_UART_IRDA_LOW_POWER        (0u)
#define Host_UART_UART_MEDIAN_FILTER_ENABLE  (0u)
#define Host_UART_UART_RETRY_ON_NACK         (0u)
#define Host_UART_UART_IRDA_POLARITY         (0u)
#define Host_UART_UART_DROP_ON_FRAME_ERR     (0u)
#define Host_UART_UART_DROP_ON_PARITY_ERR    (0u)
#define Host_UART_UART_WAKE_ENABLE           (0u)
#define Host_UART_UART_RX_BUFFER_SIZE        (64u)
#define Host_UART_UART_TX_BUFFER_SIZE        (128u)
#define Host_UART_UART_MP_MODE_ENABLE        (0u)
#define Host_UART_UART_MP_ACCEPT_ADDRESS     (0u)
#define Host_UART_UART_MP_RX_ADDRESS         (2u)
#define Host_UART_UART_MP_RX_ADDRESS_MASK    (255u)

#define Host_UART_UART_INTERRUPT_MODE        (1u)

#define Host_UART_UART_INTR_RX_MASK          (4u)
#define Host_UART_UART_INTR_TX_MASK          (0u)

#define Host_UART_UART_RX_TRIGGER_LEVEL      (7u)
#define Host_UART_UART_TX_TRIGGER_LEVEL      (0u)

#define Host_UART_UART_BYTE_MODE_ENABLE      (0u)
#define Host_UART_UART_CTS_ENABLE            (0u)
#define Host_UART_UART_CTS_POLARITY          (0u)
#define Host_UART_UART_RTS_POLARITY          (0u)
#define Host_UART_UART_RTS_FIFO_LEVEL        (4u)

/* SPI mode enum */
#define Host_UART_SPI_SLAVE  (0u)
#define Host_UART_SPI_MASTER (1u)

/* UART direction enum */
#define Host_UART_UART_RX    (1u)
#define Host_UART_UART_TX    (2u)
#define Host_UART_UART_TX_RX (3u)


/***************************************
*   Conditional Compilation Parameters
****************************************/

#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    /* Mode */
    #define Host_UART_SPI_MASTER_CONST       (1u)

    /* Direction */
    #define Host_UART_RX_DIRECTION           (1u)
    #define Host_UART_TX_DIRECTION           (1u)
    #define Host_UART_UART_RX_DIRECTION      (1u)
    #define Host_UART_UART_TX_DIRECTION      (1u)

    /* Only external RX and TX buffer for Uncofigured mode */
    #define Host_UART_INTERNAL_RX_SW_BUFFER   (0u)
    #define Host_UART_INTERNAL_TX_SW_BUFFER   (0u)

    /* Get RX and TX buffer size */
    #define Host_UART_RX_BUFFER_SIZE (Host_UART_rxBufferSize)
    #define Host_UART_TX_BUFFER_SIZE (Host_UART_txBufferSize)

    /* Return true if buffer is provided */
    #define Host_UART_CHECK_RX_SW_BUFFER (NULL != Host_UART_rxBuffer)
    #define Host_UART_CHECK_TX_SW_BUFFER (NULL != Host_UART_txBuffer)

    /* Always provide global variables to support RX and TX buffers */
    #define Host_UART_INTERNAL_RX_SW_BUFFER_CONST    (1u)
    #define Host_UART_INTERNAL_TX_SW_BUFFER_CONST    (1u)

    /* Get wakeup enable option */
    #define Host_UART_SPI_WAKE_ENABLE_CONST  (1u)
    #define Host_UART_CHECK_SPI_WAKE_ENABLE  (0u != Host_UART_scbEnableWake)
    #define Host_UART_UART_WAKE_ENABLE_CONST (1u)

    /* SPI/UART: TX or RX FIFO size */
    #if (Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1)
        #define Host_UART_SPI_UART_FIFO_SIZE (Host_UART_FIFO_SIZE)
    #else
        #define Host_UART_SPI_UART_FIFO_SIZE (Host_UART_GET_FIFO_SIZE(Host_UART_CTRL_REG & \
                                                                                    Host_UART_CTRL_BYTE_MODE))
    #endif /* (Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1) */

#else

    /* Internal RX and TX buffer: for SPI or UART */
    #if (Host_UART_SCB_MODE_SPI_CONST_CFG)

        /* SPI Direction */
        #define Host_UART_SPI_RX_DIRECTION (1u)
        #define Host_UART_SPI_TX_DIRECTION (1u)

        /* Get FIFO size */
        #if (Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1)
            #define Host_UART_SPI_UART_FIFO_SIZE    (Host_UART_FIFO_SIZE)
        #else
            #define Host_UART_SPI_UART_FIFO_SIZE \
                                           Host_UART_GET_FIFO_SIZE(Host_UART_SPI_BYTE_MODE_ENABLE)

        #endif /* (Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1) */

        /* SPI internal RX and TX buffers */
        #define Host_UART_INTERNAL_SPI_RX_SW_BUFFER  (Host_UART_SPI_RX_BUFFER_SIZE > \
                                                                Host_UART_SPI_UART_FIFO_SIZE)
        #define Host_UART_INTERNAL_SPI_TX_SW_BUFFER  (Host_UART_SPI_TX_BUFFER_SIZE > \
                                                                Host_UART_SPI_UART_FIFO_SIZE)

        /* Internal SPI RX and TX buffer */
        #define Host_UART_INTERNAL_RX_SW_BUFFER  (Host_UART_INTERNAL_SPI_RX_SW_BUFFER)
        #define Host_UART_INTERNAL_TX_SW_BUFFER  (Host_UART_INTERNAL_SPI_TX_SW_BUFFER)

        /* Internal SPI RX and TX buffer size */
        #define Host_UART_RX_BUFFER_SIZE         (Host_UART_SPI_RX_BUFFER_SIZE + 1u)
        #define Host_UART_TX_BUFFER_SIZE         (Host_UART_SPI_TX_BUFFER_SIZE)

        /* Get wakeup enable option */
        #define Host_UART_SPI_WAKE_ENABLE_CONST  (0u != Host_UART_SPI_WAKE_ENABLE)
        #define Host_UART_UART_WAKE_ENABLE_CONST (0u)

    #else

        /* UART Direction */
        #define Host_UART_UART_RX_DIRECTION (0u != (Host_UART_UART_DIRECTION & Host_UART_UART_RX))
        #define Host_UART_UART_TX_DIRECTION (0u != (Host_UART_UART_DIRECTION & Host_UART_UART_TX))

        /* Get FIFO size */
        #if (Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1)
            #define Host_UART_SPI_UART_FIFO_SIZE    (Host_UART_FIFO_SIZE)
        #else
            #define Host_UART_SPI_UART_FIFO_SIZE \
                                           Host_UART_GET_FIFO_SIZE(Host_UART_UART_BYTE_MODE_ENABLE)
        #endif /* (Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1) */

        /* UART internal RX and TX buffers */
        #define Host_UART_INTERNAL_UART_RX_SW_BUFFER  (Host_UART_UART_RX_BUFFER_SIZE > \
                                                                Host_UART_SPI_UART_FIFO_SIZE)
        #define Host_UART_INTERNAL_UART_TX_SW_BUFFER  (Host_UART_UART_TX_BUFFER_SIZE > \
                                                                    Host_UART_SPI_UART_FIFO_SIZE)

        /* Internal UART RX and TX buffer */
        #define Host_UART_INTERNAL_RX_SW_BUFFER  (Host_UART_INTERNAL_UART_RX_SW_BUFFER)
        #define Host_UART_INTERNAL_TX_SW_BUFFER  (Host_UART_INTERNAL_UART_TX_SW_BUFFER)

        /* Internal UART RX and TX buffer size */
        #define Host_UART_RX_BUFFER_SIZE         (Host_UART_UART_RX_BUFFER_SIZE + 1u)
        #define Host_UART_TX_BUFFER_SIZE         (Host_UART_UART_TX_BUFFER_SIZE)

        /* Get wakeup enable option */
        #define Host_UART_SPI_WAKE_ENABLE_CONST  (0u)
        #define Host_UART_UART_WAKE_ENABLE_CONST (0u != Host_UART_UART_WAKE_ENABLE)

    #endif /* (Host_UART_SCB_MODE_SPI_CONST_CFG) */

    /* Mode */
    #define Host_UART_SPI_MASTER_CONST   (Host_UART_SPI_MODE == Host_UART_SPI_MASTER)

    /* Direction */
    #define Host_UART_RX_DIRECTION ((Host_UART_SCB_MODE_SPI_CONST_CFG) ? \
                                            (Host_UART_SPI_RX_DIRECTION) : (Host_UART_UART_RX_DIRECTION))

    #define Host_UART_TX_DIRECTION ((Host_UART_SCB_MODE_SPI_CONST_CFG) ? \
                                            (Host_UART_SPI_TX_DIRECTION) : (Host_UART_UART_TX_DIRECTION))

    /* Internal RX and TX buffer: for SPI or UART. Used in conditional compilation check */
    #define Host_UART_CHECK_RX_SW_BUFFER (Host_UART_INTERNAL_RX_SW_BUFFER)
    #define Host_UART_CHECK_TX_SW_BUFFER (Host_UART_INTERNAL_TX_SW_BUFFER)

    /* Provide global variables to support RX and TX buffers */
    #define Host_UART_INTERNAL_RX_SW_BUFFER_CONST    (Host_UART_INTERNAL_RX_SW_BUFFER)
    #define Host_UART_INTERNAL_TX_SW_BUFFER_CONST    (Host_UART_INTERNAL_TX_SW_BUFFER)

    /* Wakeup for SPI */
    #define Host_UART_CHECK_SPI_WAKE_ENABLE  (Host_UART_SPI_WAKE_ENABLE_CONST)

#endif /* End (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*       Type Definitions
***************************************/

/* Host_UART_SPI_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 submode;
    uint32 sclkMode;
    uint32 oversample;
    uint32 enableMedianFilter;
    uint32 enableLateSampling;
    uint32 enableWake;
    uint32 rxDataBits;
    uint32 txDataBits;
    uint32 bitOrder;
    uint32 transferSeperation;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
    uint8 enableByteMode;
    uint8 enableFreeRunSclk;
    uint8 polaritySs;
} Host_UART_SPI_INIT_STRUCT;

/* Host_UART_UART_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 direction;
    uint32 dataBits;
    uint32 parity;
    uint32 stopBits;
    uint32 oversample;
    uint32 enableIrdaLowPower;
    uint32 enableMedianFilter;
    uint32 enableRetryNack;
    uint32 enableInvertedRx;
    uint32 dropOnParityErr;
    uint32 dropOnFrameErr;
    uint32 enableWake;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableMultiproc;
    uint32 multiprocAcceptAddr;
    uint32 multiprocAddr;
    uint32 multiprocAddrMask;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
    uint8 enableByteMode;
    uint8 enableCts;
    uint8 ctsPolarity;
    uint8 rtsRxFifoLevel;
    uint8 rtsPolarity;
} Host_UART_UART_INIT_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/* SPI specific functions */
#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    void Host_UART_SpiInit(const Host_UART_SPI_INIT_STRUCT *config);
#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(Host_UART_SCB_MODE_SPI_INC)
    #define Host_UART_SpiIsBusBusy() ((uint32) (0u != (Host_UART_SPI_STATUS_REG & \
                                                              Host_UART_SPI_STATUS_BUS_BUSY)))

    #if (Host_UART_SPI_MASTER_CONST)
        void Host_UART_SpiSetActiveSlaveSelect(uint32 slaveSelect);
    #endif /*(Host_UART_SPI_MASTER_CONST) */

    #if !(Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1)
        void Host_UART_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity);
    #endif /* !(Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1) */
#endif /* (Host_UART_SCB_MODE_SPI_INC) */

/* UART specific functions */
#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    void Host_UART_UartInit(const Host_UART_UART_INIT_STRUCT *config);
#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(Host_UART_SCB_MODE_UART_INC)
    void Host_UART_UartSetRxAddress(uint32 address);
    void Host_UART_UartSetRxAddressMask(uint32 addressMask);

    /* UART RX direction APIs */
    #if(Host_UART_UART_RX_DIRECTION)
        uint32 Host_UART_UartGetChar(void);
        uint32 Host_UART_UartGetByte(void);

        #if !(Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1)
            /* UART APIs for Flow Control */
            void Host_UART_UartSetRtsPolarity(uint32 polarity);
            void Host_UART_UartSetRtsFifoLevel(uint32 level);
        #endif /* !(Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1) */
    #endif /* (Host_UART_UART_RX_DIRECTION) */

    /* UART TX direction APIs */
    #if(Host_UART_UART_TX_DIRECTION)
        #define Host_UART_UartPutChar(ch)    Host_UART_SpiUartWriteTxData((uint32)(ch))
        void Host_UART_UartPutString(const char8 string[]);
        void Host_UART_UartPutCRLF(uint32 txDataByte);

        #if !(Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1)
            /* UART APIs for Flow Control */
            void Host_UART_UartEnableCts(void);
            void Host_UART_UartDisableCts(void);
            void Host_UART_UartSetCtsPolarity(uint32 polarity);
        #endif /* !(Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1) */
    #endif /* (Host_UART_UART_TX_DIRECTION) */
#endif /* (Host_UART_SCB_MODE_UART_INC) */

/* Common APIs RX direction */
#if(Host_UART_RX_DIRECTION)
    uint32 Host_UART_SpiUartReadRxData(void);
    uint32 Host_UART_SpiUartGetRxBufferSize(void);
    void   Host_UART_SpiUartClearRxBuffer(void);
#endif /* (Host_UART_RX_DIRECTION) */

/* Common APIs TX direction */
#if(Host_UART_TX_DIRECTION)
    void   Host_UART_SpiUartWriteTxData(uint32 txData);
    void   Host_UART_SpiUartPutArray(const uint8 wrBuf[], uint32 count);
    void   Host_UART_SpiUartClearTxBuffer(void);
    uint32 Host_UART_SpiUartGetTxBufferSize(void);
#endif /* (Host_UART_TX_DIRECTION) */

CY_ISR_PROTO(Host_UART_SPI_UART_ISR);

#if(Host_UART_UART_RX_WAKEUP_IRQ)
    CY_ISR_PROTO(Host_UART_UART_WAKEUP_ISR);
#endif /* (Host_UART_UART_RX_WAKEUP_IRQ) */


/***************************************
*     Buffer Access Macro Definitions
***************************************/

#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* RX direction */
    void   Host_UART_PutWordInRxBuffer  (uint32 idx, uint32 rxDataByte);
    uint32 Host_UART_GetWordFromRxBuffer(uint32 idx);

    /* TX direction */
    void   Host_UART_PutWordInTxBuffer  (uint32 idx, uint32 txDataByte);
    uint32 Host_UART_GetWordFromTxBuffer(uint32 idx);

#else
    /* RX direction */
    #if(Host_UART_INTERNAL_RX_SW_BUFFER_CONST)
        #define Host_UART_PutWordInRxBuffer(idx, rxDataByte) \
                do{                                                 \
                    Host_UART_rxBufferInternal[(idx)] = ((uint8) (rxDataByte)); \
                }while(0)

        #define Host_UART_GetWordFromRxBuffer(idx) Host_UART_rxBufferInternal[(idx)]

    #endif /* (Host_UART_INTERNAL_RX_SW_BUFFER_CONST) */

    /* TX direction */
    #if(Host_UART_INTERNAL_TX_SW_BUFFER_CONST)
        #define Host_UART_PutWordInTxBuffer(idx, txDataByte) \
                    do{                                             \
                        Host_UART_txBufferInternal[(idx)] = ((uint8) (txDataByte)); \
                    }while(0)

        #define Host_UART_GetWordFromTxBuffer(idx) Host_UART_txBufferInternal[(idx)]

    #endif /* (Host_UART_INTERNAL_TX_SW_BUFFER_CONST) */

#endif /* (Host_UART_TX_SW_BUFFER_ENABLE) */


/***************************************
*         SPI API Constants
***************************************/

/* SPI sub mode enum */
#define Host_UART_SPI_MODE_MOTOROLA      (0x00u)
#define Host_UART_SPI_MODE_TI_COINCIDES  (0x01u)
#define Host_UART_SPI_MODE_TI_PRECEDES   (0x11u)
#define Host_UART_SPI_MODE_NATIONAL      (0x02u)
#define Host_UART_SPI_MODE_MASK          (0x03u)
#define Host_UART_SPI_MODE_TI_PRECEDES_MASK  (0x10u)
#define Host_UART_SPI_MODE_NS_MICROWIRE  (Host_UART_SPI_MODE_NATIONAL)

/* SPI phase and polarity mode enum */
#define Host_UART_SPI_SCLK_CPHA0_CPOL0   (0x00u)
#define Host_UART_SPI_SCLK_CPHA0_CPOL1   (0x02u)
#define Host_UART_SPI_SCLK_CPHA1_CPOL0   (0x01u)
#define Host_UART_SPI_SCLK_CPHA1_CPOL1   (0x03u)

/* SPI bits order enum */
#define Host_UART_BITS_ORDER_LSB_FIRST   (0u)
#define Host_UART_BITS_ORDER_MSB_FIRST   (1u)

/* SPI transfer separation enum */
#define Host_UART_SPI_TRANSFER_SEPARATED     (0u)
#define Host_UART_SPI_TRANSFER_CONTINUOUS    (1u)

/* SPI slave select constants */
#define Host_UART_SPI_SLAVE_SELECT0    (Host_UART_SCB__SS0_POSISTION)
#define Host_UART_SPI_SLAVE_SELECT1    (Host_UART_SCB__SS1_POSISTION)
#define Host_UART_SPI_SLAVE_SELECT2    (Host_UART_SCB__SS2_POSISTION)
#define Host_UART_SPI_SLAVE_SELECT3    (Host_UART_SCB__SS3_POSISTION)

/* SPI slave select polarity settings */
#define Host_UART_SPI_SS_ACTIVE_LOW  (0u)
#define Host_UART_SPI_SS_ACTIVE_HIGH (1u)


/***************************************
*         UART API Constants
***************************************/

/* UART sub-modes enum */
#define Host_UART_UART_MODE_STD          (0u)
#define Host_UART_UART_MODE_SMARTCARD    (1u)
#define Host_UART_UART_MODE_IRDA         (2u)

/* UART direction enum */
#define Host_UART_UART_RX    (1u)
#define Host_UART_UART_TX    (2u)
#define Host_UART_UART_TX_RX (3u)

/* UART parity enum */
#define Host_UART_UART_PARITY_EVEN   (0u)
#define Host_UART_UART_PARITY_ODD    (1u)
#define Host_UART_UART_PARITY_NONE   (2u)

/* UART stop bits enum */
#define Host_UART_UART_STOP_BITS_1   (2u)
#define Host_UART_UART_STOP_BITS_1_5 (3u)
#define Host_UART_UART_STOP_BITS_2   (4u)

/* UART IrDA low power OVS enum */
#define Host_UART_UART_IRDA_LP_OVS16     (16u)
#define Host_UART_UART_IRDA_LP_OVS32     (32u)
#define Host_UART_UART_IRDA_LP_OVS48     (48u)
#define Host_UART_UART_IRDA_LP_OVS96     (96u)
#define Host_UART_UART_IRDA_LP_OVS192    (192u)
#define Host_UART_UART_IRDA_LP_OVS768    (768u)
#define Host_UART_UART_IRDA_LP_OVS1536   (1536u)

/* Uart MP: mark (address) and space (data) bit definitions */
#define Host_UART_UART_MP_MARK       (0x100u)
#define Host_UART_UART_MP_SPACE      (0x000u)

/* UART CTS/RTS polarity settings */
#define Host_UART_UART_CTS_ACTIVE_LOW    (0u)
#define Host_UART_UART_CTS_ACTIVE_HIGH   (1u)
#define Host_UART_UART_RTS_ACTIVE_LOW    (0u)
#define Host_UART_UART_RTS_ACTIVE_HIGH   (1u)

/* Sources of RX errors */
#define Host_UART_INTR_RX_ERR        (Host_UART_INTR_RX_OVERFLOW    | \
                                             Host_UART_INTR_RX_UNDERFLOW   | \
                                             Host_UART_INTR_RX_FRAME_ERROR | \
                                             Host_UART_INTR_RX_PARITY_ERROR)

/* Shifted INTR_RX_ERR defines ONLY for Host_UART_UartGetByte() */
#define Host_UART_UART_RX_OVERFLOW       (Host_UART_INTR_RX_OVERFLOW << 8u)
#define Host_UART_UART_RX_UNDERFLOW      (Host_UART_INTR_RX_UNDERFLOW << 8u)
#define Host_UART_UART_RX_FRAME_ERROR    (Host_UART_INTR_RX_FRAME_ERROR << 8u)
#define Host_UART_UART_RX_PARITY_ERROR   (Host_UART_INTR_RX_PARITY_ERROR << 8u)
#define Host_UART_UART_RX_ERROR_MASK     (Host_UART_UART_RX_OVERFLOW    | \
                                                 Host_UART_UART_RX_UNDERFLOW   | \
                                                 Host_UART_UART_RX_FRAME_ERROR | \
                                                 Host_UART_UART_RX_PARITY_ERROR)


/***************************************
*     Vars with External Linkage
***************************************/

#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const Host_UART_SPI_INIT_STRUCT  Host_UART_configSpi;
    extern const Host_UART_UART_INIT_STRUCT Host_UART_configUart;
#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*    Specific SPI Macro Definitions
***************************************/

#define Host_UART_GET_SPI_INTR_SLAVE_MASK(sourceMask)  ((sourceMask) & Host_UART_INTR_SLAVE_SPI_BUS_ERROR)
#define Host_UART_GET_SPI_INTR_MASTER_MASK(sourceMask) ((sourceMask) & Host_UART_INTR_MASTER_SPI_DONE)
#define Host_UART_GET_SPI_INTR_RX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~Host_UART_INTR_SLAVE_SPI_BUS_ERROR)

#define Host_UART_GET_SPI_INTR_TX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~Host_UART_INTR_MASTER_SPI_DONE)


/***************************************
*    Specific UART Macro Definitions
***************************************/

#define Host_UART_UART_GET_CTRL_OVS_IRDA_LP(oversample) \
        ((Host_UART_UART_IRDA_LP_OVS16   == (oversample)) ? Host_UART_CTRL_OVS_IRDA_LP_OVS16 : \
         ((Host_UART_UART_IRDA_LP_OVS32   == (oversample)) ? Host_UART_CTRL_OVS_IRDA_LP_OVS32 : \
          ((Host_UART_UART_IRDA_LP_OVS48   == (oversample)) ? Host_UART_CTRL_OVS_IRDA_LP_OVS48 : \
           ((Host_UART_UART_IRDA_LP_OVS96   == (oversample)) ? Host_UART_CTRL_OVS_IRDA_LP_OVS96 : \
            ((Host_UART_UART_IRDA_LP_OVS192  == (oversample)) ? Host_UART_CTRL_OVS_IRDA_LP_OVS192 : \
             ((Host_UART_UART_IRDA_LP_OVS768  == (oversample)) ? Host_UART_CTRL_OVS_IRDA_LP_OVS768 : \
              ((Host_UART_UART_IRDA_LP_OVS1536 == (oversample)) ? Host_UART_CTRL_OVS_IRDA_LP_OVS1536 : \
                                                                          Host_UART_CTRL_OVS_IRDA_LP_OVS16)))))))

#define Host_UART_GET_UART_RX_CTRL_ENABLED(direction) ((0u != (Host_UART_UART_RX & (direction))) ? \
                                                                     (Host_UART_RX_CTRL_ENABLED) : (0u))

#define Host_UART_GET_UART_TX_CTRL_ENABLED(direction) ((0u != (Host_UART_UART_TX & (direction))) ? \
                                                                     (Host_UART_TX_CTRL_ENABLED) : (0u))


/***************************************
*        SPI Register Settings
***************************************/

#define Host_UART_CTRL_SPI      (Host_UART_CTRL_MODE_SPI)
#define Host_UART_SPI_RX_CTRL   (Host_UART_RX_CTRL_ENABLED)
#define Host_UART_SPI_TX_CTRL   (Host_UART_TX_CTRL_ENABLED)


/***************************************
*       SPI Init Register Settings
***************************************/

#define Host_UART_SPI_SS_POLARITY \
             (((uint32) Host_UART_SPI_SS0_POLARITY << Host_UART_SPI_SLAVE_SELECT0) | \
              ((uint32) Host_UART_SPI_SS1_POLARITY << Host_UART_SPI_SLAVE_SELECT1) | \
              ((uint32) Host_UART_SPI_SS2_POLARITY << Host_UART_SPI_SLAVE_SELECT2) | \
              ((uint32) Host_UART_SPI_SS3_POLARITY << Host_UART_SPI_SLAVE_SELECT3))

#if(Host_UART_SCB_MODE_SPI_CONST_CFG)

    /* SPI Configuration */
    #define Host_UART_SPI_DEFAULT_CTRL \
                    (Host_UART_GET_CTRL_OVS(Host_UART_SPI_OVS_FACTOR) | \
                     Host_UART_GET_CTRL_BYTE_MODE (Host_UART_SPI_BYTE_MODE_ENABLE) | \
                     Host_UART_GET_CTRL_EC_AM_MODE(Host_UART_SPI_WAKE_ENABLE)      | \
                     Host_UART_CTRL_SPI)

    #define Host_UART_SPI_DEFAULT_SPI_CTRL \
                    (Host_UART_GET_SPI_CTRL_CONTINUOUS    (Host_UART_SPI_TRANSFER_SEPARATION)       | \
                     Host_UART_GET_SPI_CTRL_SELECT_PRECEDE(Host_UART_SPI_SUB_MODE &                   \
                                                                  Host_UART_SPI_MODE_TI_PRECEDES_MASK)     | \
                     Host_UART_GET_SPI_CTRL_SCLK_MODE     (Host_UART_SPI_CLOCK_MODE)                | \
                     Host_UART_GET_SPI_CTRL_LATE_MISO_SAMPLE(Host_UART_SPI_LATE_MISO_SAMPLE_ENABLE) | \
                     Host_UART_GET_SPI_CTRL_SCLK_CONTINUOUS(Host_UART_SPI_FREE_RUN_SCLK_ENABLE)     | \
                     Host_UART_GET_SPI_CTRL_SSEL_POLARITY (Host_UART_SPI_SS_POLARITY)               | \
                     Host_UART_GET_SPI_CTRL_SUB_MODE      (Host_UART_SPI_SUB_MODE)                  | \
                     Host_UART_GET_SPI_CTRL_MASTER_MODE   (Host_UART_SPI_MODE))

    /* RX direction */
    #define Host_UART_SPI_DEFAULT_RX_CTRL \
                    (Host_UART_GET_RX_CTRL_DATA_WIDTH(Host_UART_SPI_RX_DATA_BITS_NUM)     | \
                     Host_UART_GET_RX_CTRL_BIT_ORDER (Host_UART_SPI_BITS_ORDER)           | \
                     Host_UART_GET_RX_CTRL_MEDIAN    (Host_UART_SPI_MEDIAN_FILTER_ENABLE) | \
                     Host_UART_SPI_RX_CTRL)

    #define Host_UART_SPI_DEFAULT_RX_FIFO_CTRL \
                    Host_UART_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(Host_UART_SPI_RX_TRIGGER_LEVEL)

    /* TX direction */
    #define Host_UART_SPI_DEFAULT_TX_CTRL \
                    (Host_UART_GET_TX_CTRL_DATA_WIDTH(Host_UART_SPI_TX_DATA_BITS_NUM) | \
                     Host_UART_GET_TX_CTRL_BIT_ORDER (Host_UART_SPI_BITS_ORDER)       | \
                     Host_UART_SPI_TX_CTRL)

    #define Host_UART_SPI_DEFAULT_TX_FIFO_CTRL \
                    Host_UART_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(Host_UART_SPI_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define Host_UART_SPI_DEFAULT_INTR_SPI_EC_MASK   (Host_UART_NO_INTR_SOURCES)

    #define Host_UART_SPI_DEFAULT_INTR_I2C_EC_MASK   (Host_UART_NO_INTR_SOURCES)
    #define Host_UART_SPI_DEFAULT_INTR_SLAVE_MASK \
                    (Host_UART_SPI_INTR_RX_MASK & Host_UART_INTR_SLAVE_SPI_BUS_ERROR)

    #define Host_UART_SPI_DEFAULT_INTR_MASTER_MASK \
                    (Host_UART_SPI_INTR_TX_MASK & Host_UART_INTR_MASTER_SPI_DONE)

    #define Host_UART_SPI_DEFAULT_INTR_RX_MASK \
                    (Host_UART_SPI_INTR_RX_MASK & (uint32) ~Host_UART_INTR_SLAVE_SPI_BUS_ERROR)

    #define Host_UART_SPI_DEFAULT_INTR_TX_MASK \
                    (Host_UART_SPI_INTR_TX_MASK & (uint32) ~Host_UART_INTR_MASTER_SPI_DONE)

#endif /* (Host_UART_SCB_MODE_SPI_CONST_CFG) */


/***************************************
*        UART Register Settings
***************************************/

#define Host_UART_CTRL_UART      (Host_UART_CTRL_MODE_UART)
#define Host_UART_UART_RX_CTRL   (Host_UART_RX_CTRL_LSB_FIRST) /* LSB for UART goes first */
#define Host_UART_UART_TX_CTRL   (Host_UART_TX_CTRL_LSB_FIRST) /* LSB for UART goes first */


/***************************************
*      UART Init Register Settings
***************************************/

#if(Host_UART_SCB_MODE_UART_CONST_CFG)

    /* UART configuration */
    #if(Host_UART_UART_MODE_IRDA == Host_UART_UART_SUB_MODE)

        #define Host_UART_DEFAULT_CTRL_OVS   ((0u != Host_UART_UART_IRDA_LOW_POWER) ?              \
                                (Host_UART_UART_GET_CTRL_OVS_IRDA_LP(Host_UART_UART_OVS_FACTOR)) : \
                                (Host_UART_CTRL_OVS_IRDA_OVS16))

    #else

        #define Host_UART_DEFAULT_CTRL_OVS   Host_UART_GET_CTRL_OVS(Host_UART_UART_OVS_FACTOR)

    #endif /* (Host_UART_UART_MODE_IRDA == Host_UART_UART_SUB_MODE) */

    #define Host_UART_UART_DEFAULT_CTRL \
                                (Host_UART_GET_CTRL_BYTE_MODE  (Host_UART_UART_BYTE_MODE_ENABLE)  | \
                                 Host_UART_GET_CTRL_ADDR_ACCEPT(Host_UART_UART_MP_ACCEPT_ADDRESS) | \
                                 Host_UART_DEFAULT_CTRL_OVS                                              | \
                                 Host_UART_CTRL_UART)

    #define Host_UART_UART_DEFAULT_UART_CTRL \
                                    (Host_UART_GET_UART_CTRL_MODE(Host_UART_UART_SUB_MODE))

    /* RX direction */
    #define Host_UART_UART_DEFAULT_RX_CTRL_PARITY \
                                ((Host_UART_UART_PARITY_NONE != Host_UART_UART_PARITY_TYPE) ?      \
                                  (Host_UART_GET_UART_RX_CTRL_PARITY(Host_UART_UART_PARITY_TYPE) | \
                                   Host_UART_UART_RX_CTRL_PARITY_ENABLED) : (0u))

    #define Host_UART_UART_DEFAULT_UART_RX_CTRL \
                    (Host_UART_GET_UART_RX_CTRL_MODE(Host_UART_UART_STOP_BITS_NUM)                    | \
                     Host_UART_GET_UART_RX_CTRL_POLARITY(Host_UART_UART_IRDA_POLARITY)                | \
                     Host_UART_GET_UART_RX_CTRL_MP_MODE(Host_UART_UART_MP_MODE_ENABLE)                | \
                     Host_UART_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(Host_UART_UART_DROP_ON_PARITY_ERR) | \
                     Host_UART_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(Host_UART_UART_DROP_ON_FRAME_ERR)   | \
                     Host_UART_UART_DEFAULT_RX_CTRL_PARITY)

    #define Host_UART_UART_DEFAULT_RX_CTRL \
                                (Host_UART_GET_RX_CTRL_DATA_WIDTH(Host_UART_UART_DATA_BITS_NUM)        | \
                                 Host_UART_GET_RX_CTRL_MEDIAN    (Host_UART_UART_MEDIAN_FILTER_ENABLE) | \
                                 Host_UART_GET_UART_RX_CTRL_ENABLED(Host_UART_UART_DIRECTION))

    #define Host_UART_UART_DEFAULT_RX_FIFO_CTRL \
                                Host_UART_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(Host_UART_UART_RX_TRIGGER_LEVEL)

    #define Host_UART_UART_DEFAULT_RX_MATCH_REG  ((0u != Host_UART_UART_MP_MODE_ENABLE) ?          \
                                (Host_UART_GET_RX_MATCH_ADDR(Host_UART_UART_MP_RX_ADDRESS) | \
                                 Host_UART_GET_RX_MATCH_MASK(Host_UART_UART_MP_RX_ADDRESS_MASK)) : (0u))

    /* TX direction */
    #define Host_UART_UART_DEFAULT_TX_CTRL_PARITY (Host_UART_UART_DEFAULT_RX_CTRL_PARITY)

    #define Host_UART_UART_DEFAULT_UART_TX_CTRL \
                                (Host_UART_GET_UART_TX_CTRL_MODE(Host_UART_UART_STOP_BITS_NUM)       | \
                                 Host_UART_GET_UART_TX_CTRL_RETRY_NACK(Host_UART_UART_RETRY_ON_NACK) | \
                                 Host_UART_UART_DEFAULT_TX_CTRL_PARITY)

    #define Host_UART_UART_DEFAULT_TX_CTRL \
                                (Host_UART_GET_TX_CTRL_DATA_WIDTH(Host_UART_UART_DATA_BITS_NUM) | \
                                 Host_UART_GET_UART_TX_CTRL_ENABLED(Host_UART_UART_DIRECTION))

    #define Host_UART_UART_DEFAULT_TX_FIFO_CTRL \
                                Host_UART_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(Host_UART_UART_TX_TRIGGER_LEVEL)

    #define Host_UART_UART_DEFAULT_FLOW_CTRL \
                        (Host_UART_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(Host_UART_UART_RTS_FIFO_LEVEL) | \
                         Host_UART_GET_UART_FLOW_CTRL_RTS_POLARITY (Host_UART_UART_RTS_POLARITY)   | \
                         Host_UART_GET_UART_FLOW_CTRL_CTS_POLARITY (Host_UART_UART_CTS_POLARITY)   | \
                         Host_UART_GET_UART_FLOW_CTRL_CTS_ENABLE   (Host_UART_UART_CTS_ENABLE))

    /* Interrupt sources */
    #define Host_UART_UART_DEFAULT_INTR_I2C_EC_MASK  (Host_UART_NO_INTR_SOURCES)
    #define Host_UART_UART_DEFAULT_INTR_SPI_EC_MASK  (Host_UART_NO_INTR_SOURCES)
    #define Host_UART_UART_DEFAULT_INTR_SLAVE_MASK   (Host_UART_NO_INTR_SOURCES)
    #define Host_UART_UART_DEFAULT_INTR_MASTER_MASK  (Host_UART_NO_INTR_SOURCES)
    #define Host_UART_UART_DEFAULT_INTR_RX_MASK      (Host_UART_UART_INTR_RX_MASK)
    #define Host_UART_UART_DEFAULT_INTR_TX_MASK      (Host_UART_UART_INTR_TX_MASK)

#endif /* (Host_UART_SCB_MODE_UART_CONST_CFG) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

#define Host_UART_SPIM_ACTIVE_SS0    (Host_UART_SPI_SLAVE_SELECT0)
#define Host_UART_SPIM_ACTIVE_SS1    (Host_UART_SPI_SLAVE_SELECT1)
#define Host_UART_SPIM_ACTIVE_SS2    (Host_UART_SPI_SLAVE_SELECT2)
#define Host_UART_SPIM_ACTIVE_SS3    (Host_UART_SPI_SLAVE_SELECT3)

#endif /* CY_SCB_SPI_UART_Host_UART_H */


/* [] END OF FILE */
