/*******************************************************************************
* File Name: Host_UART.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

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
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 Host_UART_scbMode = Host_UART_SCB_MODE_UNCONFIG;
    uint8 Host_UART_scbEnableWake;
    uint8 Host_UART_scbEnableIntr;

    /* I2C configuration variables */
    uint8 Host_UART_mode;
    uint8 Host_UART_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * Host_UART_rxBuffer;
    uint8  Host_UART_rxDataBits;
    uint32 Host_UART_rxBufferSize;

    volatile uint8 * Host_UART_txBuffer;
    uint8  Host_UART_txDataBits;
    uint32 Host_UART_txBufferSize;

    /* EZI2C configuration variables */
    uint8 Host_UART_numberOfAddr;
    uint8 Host_UART_subAddrSize;
#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/

uint8 Host_UART_initVar = 0u;

#if !defined (CY_REMOVE_Host_UART_CUSTOM_INTR_HANDLER)
    cyisraddress Host_UART_customIntrHandler = NULL;
#endif /* !defined (CY_REMOVE_Host_UART_CUSTOM_INTR_HANDLER) */


/***************************************
*    Private Function Prototypes
***************************************/

static void Host_UART_ScbEnableIntr(void);
static void Host_UART_ScbModeStop(void);


/*******************************************************************************
* Function Name: Host_UART_Init
********************************************************************************
*
* Summary:
*  Initializes the SCB component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  SCB_I2CInit, SCB_SpiInit, SCB_UartInit or SCB_EzI2CInit.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_Init(void)
{
#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    if(Host_UART_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        Host_UART_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif(Host_UART_SCB_MODE_I2C_CONST_CFG)
    Host_UART_I2CInit();

#elif(Host_UART_SCB_MODE_SPI_CONST_CFG)
    Host_UART_SpiInit();

#elif(Host_UART_SCB_MODE_UART_CONST_CFG)
    Host_UART_UartInit();

#elif(Host_UART_SCB_MODE_EZI2C_CONST_CFG)
    Host_UART_EzI2CInit();

#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Host_UART_Enable
********************************************************************************
*
* Summary:
*  Enables the SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_Enable(void)
{
#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if(!Host_UART_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        Host_UART_CTRL_REG |= Host_UART_CTRL_ENABLED;

        Host_UART_ScbEnableIntr();
    }
#else
    Host_UART_CTRL_REG |= Host_UART_CTRL_ENABLED;

    Host_UART_ScbEnableIntr();
#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: Host_UART_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZ I2C. Otherwise this function does not enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Host_UART_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void Host_UART_Start(void)
{
    if(0u == Host_UART_initVar)
    {
        Host_UART_Init();
        Host_UART_initVar = 1u; /* Component was initialized */
    }

    Host_UART_Enable();
}


/*******************************************************************************
* Function Name: Host_UART_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component and its interrupt.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_Stop(void)
{
#if(Host_UART_SCB_IRQ_INTERNAL)
    Host_UART_DisableInt();
#endif /* (Host_UART_SCB_IRQ_INTERNAL) */

    Host_UART_CTRL_REG &= (uint32) ~Host_UART_CTRL_ENABLED;  /* Disable scb IP */

#if(Host_UART_SCB_IRQ_INTERNAL)
    Host_UART_ClearPendingInt();
#endif /* (Host_UART_SCB_IRQ_INTERNAL) */

    Host_UART_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: Host_UART_SetRxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the RX FIFO to generate RX level interrupt.
*         The range of valid level values is between 0 and RX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = Host_UART_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~Host_UART_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (Host_UART_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    Host_UART_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: Host_UART_SetTxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has more entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the TX FIFO to generate TX level interrupt.
*         The range of valid level values is between 0 and TX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = Host_UART_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~Host_UART_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (Host_UART_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    Host_UART_TX_FIFO_CTRL_REG = txFifoCtrl;
}


/*******************************************************************************
* Function Name: Host_UART_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operation such as software buffer management functions
*  before the interrupt returns.  It is the user's responsibility not to break
*  the software buffer operations. Only one custom handler is supported, which
*  is the function provided by the most recent call.
*  At the initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void Host_UART_SetCustomInterruptHandler(cyisraddress func)
{
#if !defined (CY_REMOVE_Host_UART_CUSTOM_INTR_HANDLER)
    Host_UART_customIntrHandler = func; /* Register interrupt handler */
#else
    if(NULL != func)
    {
        /* Suppress compiler warning */
    }
#endif /* !defined (CY_REMOVE_Host_UART_CUSTOM_INTR_HANDLER) */
}


/*******************************************************************************
* Function Name: Host_UART_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables an interrupt for a specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void Host_UART_ScbEnableIntr(void)
{
#if(Host_UART_SCB_IRQ_INTERNAL)
    #if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Enable interrupt in NVIC */
        if(0u != Host_UART_scbEnableIntr)
        {
            Host_UART_EnableInt();
        }
    #else
        Host_UART_EnableInt();

    #endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (Host_UART_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: Host_UART_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls the Stop function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void Host_UART_ScbModeStop(void)
{
#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    if(Host_UART_SCB_MODE_I2C_RUNTM_CFG)
    {
        Host_UART_I2CStop();
    }
    else if (Host_UART_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        Host_UART_EzI2CStop();
    }
#if (!Host_UART_CY_SCBIP_V1)
    else if (Host_UART_SCB_MODE_UART_RUNTM_CFG)
    {
        Host_UART_UartStop();
    }
#endif /* (!Host_UART_CY_SCBIP_V1) */
    else
    {
        /* Do nothing for other modes */
    }
#elif(Host_UART_SCB_MODE_I2C_CONST_CFG)
    Host_UART_I2CStop();

#elif(Host_UART_SCB_MODE_EZI2C_CONST_CFG)
    Host_UART_EzI2CStop();

#elif(Host_UART_SCB_MODE_UART_CONST_CFG)
    Host_UART_UartStop();

#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if(Host_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: Host_UART_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Host_UART_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 hsiomSel [Host_UART_SCB_PINS_NUMBER];
        uint32 pinsDm   [Host_UART_SCB_PINS_NUMBER];

    #if (!Host_UART_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!Host_UART_CY_SCBIP_V1) */

        uint32 i;

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for(i = 0u; i < Host_UART_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i]  = Host_UART_HSIOM_DEF_SEL;
            pinsDm[i]    = Host_UART_PIN_DM_ALG_HIZ;
        }

        if((Host_UART_SCB_MODE_I2C   == mode) ||
           (Host_UART_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[Host_UART_MOSI_SCL_RX_PIN_INDEX] = Host_UART_HSIOM_I2C_SEL;
            hsiomSel[Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_HSIOM_I2C_SEL;

            pinsDm[Host_UART_MOSI_SCL_RX_PIN_INDEX] = Host_UART_PIN_DM_OD_LO;
            pinsDm[Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_PIN_DM_OD_LO;
        }
    #if (!Host_UART_CY_SCBIP_V1)
        else if(Host_UART_SCB_MODE_SPI == mode)
        {
            hsiomSel[Host_UART_MOSI_SCL_RX_PIN_INDEX] = Host_UART_HSIOM_SPI_SEL;
            hsiomSel[Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_HSIOM_SPI_SEL;
            hsiomSel[Host_UART_SCLK_PIN_INDEX]        = Host_UART_HSIOM_SPI_SEL;

            if(Host_UART_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[Host_UART_MOSI_SCL_RX_PIN_INDEX] = Host_UART_PIN_DM_DIG_HIZ;
                pinsDm[Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_PIN_DM_STRONG;
                pinsDm[Host_UART_SCLK_PIN_INDEX]        = Host_UART_PIN_DM_DIG_HIZ;

            #if(Host_UART_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[Host_UART_SS0_PIN_INDEX] = Host_UART_HSIOM_SPI_SEL;
                pinsDm  [Host_UART_SS0_PIN_INDEX] = Host_UART_PIN_DM_DIG_HIZ;
            #endif /* (Host_UART_SS1_PIN) */

            #if(Host_UART_MISO_SDA_TX_PIN)
                /* Disable input buffer */
                 pinsInBuf |= Host_UART_MISO_SDA_TX_PIN_MASK;
            #endif /* (Host_UART_MISO_SDA_TX_PIN_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[Host_UART_MOSI_SCL_RX_PIN_INDEX] = Host_UART_PIN_DM_STRONG;
                pinsDm[Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_PIN_DM_DIG_HIZ;
                pinsDm[Host_UART_SCLK_PIN_INDEX]        = Host_UART_PIN_DM_STRONG;

            #if(Host_UART_SS0_PIN)
                hsiomSel [Host_UART_SS0_PIN_INDEX] = Host_UART_HSIOM_SPI_SEL;
                pinsDm   [Host_UART_SS0_PIN_INDEX] = Host_UART_PIN_DM_STRONG;
                pinsInBuf                                |= Host_UART_SS0_PIN_MASK;
            #endif /* (Host_UART_SS0_PIN) */

            #if(Host_UART_SS1_PIN)
                hsiomSel [Host_UART_SS1_PIN_INDEX] = Host_UART_HSIOM_SPI_SEL;
                pinsDm   [Host_UART_SS1_PIN_INDEX] = Host_UART_PIN_DM_STRONG;
                pinsInBuf                                |= Host_UART_SS1_PIN_MASK;
            #endif /* (Host_UART_SS1_PIN) */

            #if(Host_UART_SS2_PIN)
                hsiomSel [Host_UART_SS2_PIN_INDEX] = Host_UART_HSIOM_SPI_SEL;
                pinsDm   [Host_UART_SS2_PIN_INDEX] = Host_UART_PIN_DM_STRONG;
                pinsInBuf                                |= Host_UART_SS2_PIN_MASK;
            #endif /* (Host_UART_SS2_PIN) */

            #if(Host_UART_SS3_PIN)
                hsiomSel [Host_UART_SS3_PIN_INDEX] = Host_UART_HSIOM_SPI_SEL;
                pinsDm   [Host_UART_SS3_PIN_INDEX] = Host_UART_PIN_DM_STRONG;
                pinsInBuf                                |= Host_UART_SS3_PIN_MASK;
            #endif /* (Host_UART_SS2_PIN) */

                /* Disable input buffers */
            #if(Host_UART_MOSI_SCL_RX_PIN)
                pinsInBuf |= Host_UART_MOSI_SCL_RX_PIN_MASK;
            #endif /* (Host_UART_MOSI_SCL_RX_PIN) */

             #if(Host_UART_MOSI_SCL_RX_WAKE_PIN)
                pinsInBuf |= Host_UART_MOSI_SCL_RX_WAKE_PIN_MASK;
            #endif /* (Host_UART_MOSI_SCL_RX_WAKE_PIN) */

            #if(Host_UART_SCLK_PIN)
                pinsInBuf |= Host_UART_SCLK_PIN_MASK;
            #endif /* (Host_UART_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if(Host_UART_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_HSIOM_UART_SEL;
                pinsDm  [Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (Host_UART_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[Host_UART_MOSI_SCL_RX_PIN_INDEX] = Host_UART_HSIOM_UART_SEL;
                    pinsDm  [Host_UART_MOSI_SCL_RX_PIN_INDEX] = Host_UART_PIN_DM_DIG_HIZ;
                }

                if(0u != (Host_UART_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_HSIOM_UART_SEL;
                    pinsDm  [Host_UART_MISO_SDA_TX_PIN_INDEX] = Host_UART_PIN_DM_STRONG;

                #if(Host_UART_MISO_SDA_TX_PIN)
                     pinsInBuf |= Host_UART_MISO_SDA_TX_PIN_MASK;
                #endif /* (Host_UART_MISO_SDA_TX_PIN_PIN) */
                }

            #if !(Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1)
                if(Host_UART_UART_MODE_STD == subMode)
                {
                    if(0u != (Host_UART_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                        hsiomSel[Host_UART_SCLK_PIN_INDEX] = Host_UART_HSIOM_UART_SEL;
                        pinsDm  [Host_UART_SCLK_PIN_INDEX] = Host_UART_PIN_DM_DIG_HIZ;
                    }

                    if(0u != (Host_UART_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                        hsiomSel[Host_UART_SS0_PIN_INDEX] = Host_UART_HSIOM_UART_SEL;
                        pinsDm  [Host_UART_SS0_PIN_INDEX] = Host_UART_PIN_DM_STRONG;

                    #if(Host_UART_SS0_PIN)
                        /* Disable input buffer */
                        pinsInBuf |= Host_UART_SS0_PIN_MASK;
                    #endif /* (Host_UART_SS0_PIN) */
                    }
                }
            #endif /* !(Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1) */
            }
        }
    #endif /* (!Host_UART_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if(Host_UART_MOSI_SCL_RX_PIN)
        Host_UART_SET_HSIOM_SEL(Host_UART_MOSI_SCL_RX_HSIOM_REG,
                                       Host_UART_MOSI_SCL_RX_HSIOM_MASK,
                                       Host_UART_MOSI_SCL_RX_HSIOM_POS,
                                       hsiomSel[Host_UART_MOSI_SCL_RX_PIN_INDEX]);

        Host_UART_spi_mosi_i2c_scl_uart_rx_SetDriveMode((uint8) pinsDm[Host_UART_MOSI_SCL_RX_PIN_INDEX]);

    #if (!Host_UART_CY_SCBIP_V1)
        Host_UART_SET_INP_DIS(Host_UART_spi_mosi_i2c_scl_uart_rx_INP_DIS,
                                     Host_UART_spi_mosi_i2c_scl_uart_rx_MASK,
                                     (0u != (pinsInBuf & Host_UART_MOSI_SCL_RX_PIN_MASK)));
    #endif /* (!Host_UART_CY_SCBIP_V1) */
    #endif /* (Host_UART_MOSI_SCL_RX_PIN) */

    #if(Host_UART_MOSI_SCL_RX_WAKE_PIN)
        Host_UART_SET_HSIOM_SEL(Host_UART_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                       Host_UART_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                       Host_UART_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                       hsiomSel[Host_UART_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        Host_UART_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode((uint8)
                                                               pinsDm[Host_UART_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        Host_UART_SET_INP_DIS(Host_UART_spi_mosi_i2c_scl_uart_rx_wake_INP_DIS,
                                     Host_UART_spi_mosi_i2c_scl_uart_rx_wake_MASK,
                                     (0u != (pinsInBuf & Host_UART_MOSI_SCL_RX_WAKE_PIN_MASK)));

         /* Set interrupt on falling edge */
        Host_UART_SET_INCFG_TYPE(Host_UART_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                        Host_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                        Host_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                        Host_UART_INTCFG_TYPE_FALLING_EDGE);
    #endif /* (Host_UART_MOSI_SCL_RX_WAKE_PIN) */

    #if(Host_UART_MISO_SDA_TX_PIN)
        Host_UART_SET_HSIOM_SEL(Host_UART_MISO_SDA_TX_HSIOM_REG,
                                       Host_UART_MISO_SDA_TX_HSIOM_MASK,
                                       Host_UART_MISO_SDA_TX_HSIOM_POS,
                                       hsiomSel[Host_UART_MISO_SDA_TX_PIN_INDEX]);

        Host_UART_spi_miso_i2c_sda_uart_tx_SetDriveMode((uint8) pinsDm[Host_UART_MISO_SDA_TX_PIN_INDEX]);

    #if (!Host_UART_CY_SCBIP_V1)
        Host_UART_SET_INP_DIS(Host_UART_spi_miso_i2c_sda_uart_tx_INP_DIS,
                                     Host_UART_spi_miso_i2c_sda_uart_tx_MASK,
                                    (0u != (pinsInBuf & Host_UART_MISO_SDA_TX_PIN_MASK)));
    #endif /* (!Host_UART_CY_SCBIP_V1) */
    #endif /* (Host_UART_MOSI_SCL_RX_PIN) */

    #if(Host_UART_SCLK_PIN)
        Host_UART_SET_HSIOM_SEL(Host_UART_SCLK_HSIOM_REG, Host_UART_SCLK_HSIOM_MASK,
                                       Host_UART_SCLK_HSIOM_POS, hsiomSel[Host_UART_SCLK_PIN_INDEX]);

        Host_UART_spi_sclk_SetDriveMode((uint8) pinsDm[Host_UART_SCLK_PIN_INDEX]);

        Host_UART_SET_INP_DIS(Host_UART_spi_sclk_INP_DIS,
                                     Host_UART_spi_sclk_MASK,
                                     (0u != (pinsInBuf & Host_UART_SCLK_PIN_MASK)));
    #endif /* (Host_UART_SCLK_PIN) */

    #if(Host_UART_SS0_PIN)
        Host_UART_SET_HSIOM_SEL(Host_UART_SS0_HSIOM_REG, Host_UART_SS0_HSIOM_MASK,
                                       Host_UART_SS0_HSIOM_POS, hsiomSel[Host_UART_SS0_PIN_INDEX]);

        Host_UART_spi_ss0_SetDriveMode((uint8) pinsDm[Host_UART_SS0_PIN_INDEX]);

        Host_UART_SET_INP_DIS(Host_UART_spi_ss0_INP_DIS,
                                     Host_UART_spi_ss0_MASK,
                                     (0u != (pinsInBuf & Host_UART_SS0_PIN_MASK)));
    #endif /* (Host_UART_SS1_PIN) */

    #if(Host_UART_SS1_PIN)
        Host_UART_SET_HSIOM_SEL(Host_UART_SS1_HSIOM_REG, Host_UART_SS1_HSIOM_MASK,
                                       Host_UART_SS1_HSIOM_POS, hsiomSel[Host_UART_SS1_PIN_INDEX]);

        Host_UART_spi_ss1_SetDriveMode((uint8) pinsDm[Host_UART_SS1_PIN_INDEX]);

        Host_UART_SET_INP_DIS(Host_UART_spi_ss1_INP_DIS,
                                     Host_UART_spi_ss1_MASK,
                                     (0u != (pinsInBuf & Host_UART_SS1_PIN_MASK)));
    #endif /* (Host_UART_SS1_PIN) */

    #if(Host_UART_SS2_PIN)
        Host_UART_SET_HSIOM_SEL(Host_UART_SS2_HSIOM_REG, Host_UART_SS2_HSIOM_MASK,
                                       Host_UART_SS2_HSIOM_POS, hsiomSel[Host_UART_SS2_PIN_INDEX]);

        Host_UART_spi_ss2_SetDriveMode((uint8) pinsDm[Host_UART_SS2_PIN_INDEX]);

        Host_UART_SET_INP_DIS(Host_UART_spi_ss2_INP_DIS,
                                     Host_UART_spi_ss2_MASK,
                                     (0u != (pinsInBuf & Host_UART_SS2_PIN_MASK)));
    #endif /* (Host_UART_SS2_PIN) */

    #if(Host_UART_SS3_PIN)
        Host_UART_SET_HSIOM_SEL(Host_UART_SS3_HSIOM_REG,  Host_UART_SS3_HSIOM_MASK,
                                       Host_UART_SS3_HSIOM_POS, hsiomSel[Host_UART_SS3_PIN_INDEX]);

        Host_UART_spi_ss3_SetDriveMode((uint8) pinsDm[Host_UART_SS3_PIN_INDEX]);

        Host_UART_SET_INP_DIS(Host_UART_spi_ss3_INP_DIS,
                                     Host_UART_spi_ss3_MASK,
                                     (0u != (pinsInBuf & Host_UART_SS3_PIN_MASK)));
    #endif /* (Host_UART_SS3_PIN) */
    }

#endif /* (Host_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: Host_UART_I2CSlaveNackGeneration
    ********************************************************************************
    *
    * Summary:
    *  Sets command to generate NACK to the address or data.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Host_UART_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (Host_UART_CTRL_REG & Host_UART_CTRL_EC_AM_MODE)) &&
            (0u == (Host_UART_I2C_CTRL_REG & Host_UART_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            Host_UART_CTRL_REG &= ~Host_UART_CTRL_EC_AM_MODE;
            Host_UART_CTRL_REG |=  Host_UART_CTRL_EC_AM_MODE;
        }

        Host_UART_I2C_SLAVE_CMD_REG = Host_UART_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (Host_UART_CY_SCBIP_V0 || Host_UART_CY_SCBIP_V1) */


/* [] END OF FILE */
