/*******************************************************************************
* File Name: LED_driver.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the Opamp (Analog Buffer)
*  Component.
*
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LED_driver.h"

uint8 LED_driver_initVar = 0u; /* Defines if component was initialized */
static uint32 LED_driver_internalPower = 0u; /* Defines component Power value */


/*******************************************************************************
* Function Name: LED_driver_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the customizer Configure 
*  dialog settings. It is not necessary to call Init() because the Start() API 
*  calls this function and is the preferred method to begin the component operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_driver_Init(void)
{
    LED_driver_internalPower = LED_driver_POWER;
    LED_driver_CTB_CTRL_REG = LED_driver_DEFAULT_CTB_CTRL;
    LED_driver_OA_RES_CTRL_REG = LED_driver_DEFAULT_OA_RES_CTRL;
    LED_driver_OA_COMP_TRIM_REG = LED_driver_DEFAULT_OA_COMP_TRIM_REG;
}


/*******************************************************************************
* Function Name: LED_driver_Enable
********************************************************************************
*
* Summary:
*  Activates the hardware and begins the component operation. It is not necessary to 
*  call Enable() because the Start() API calls this function, which is the 
*  preferred method to begin the component operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_driver_Enable(void)
{
    LED_driver_OA_RES_CTRL_REG |= LED_driver_internalPower | \
                                        LED_driver_OA_PUMP_EN;
}


/*******************************************************************************
* Function Name: LED_driver_Start
********************************************************************************
*
* Summary:
*  Performs all of the required initialization for the component and enables power 
*  to the block. The first time the routine is executed, the Power level, Mode, 
*  and Output mode are set. When called to restart the Opamp following a Stop() call, 
*  the current component parameter settings are retained.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  LED_driver_initVar: Used to check the initial configuration, modified
*  when this function is called for the first time.
*
*******************************************************************************/
void LED_driver_Start(void)
{
    if( 0u == LED_driver_initVar)
    {
        LED_driver_Init();
        LED_driver_initVar = 1u;
    }
    LED_driver_Enable();
}


/*******************************************************************************
* Function Name: LED_driver_Stop
********************************************************************************
*
* Summary:
*  Turn off the Opamp block.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_driver_Stop(void)
{
    LED_driver_OA_RES_CTRL_REG &= ((uint32)~(LED_driver_OA_PWR_MODE_MASK | \
                                                   LED_driver_OA_PUMP_EN));
}


/*******************************************************************************
* Function Name: LED_driver_SetPower
********************************************************************************
*
* Summary:
*  Sets the Opamp to one of the three power levels.
*
* Parameters:
*  power: power levels.
*   LED_driver_LOW_POWER - Lowest active power
*   LED_driver_MED_POWER - Medium power
*   LED_driver_HIGH_POWER - Highest active power
*
* Return:
*  None
*
**********************************************************************************/
void LED_driver_SetPower(uint32 power)
{
    uint32 tmp;
    
    LED_driver_internalPower = LED_driver_GET_OA_PWR_MODE(power);
    tmp = LED_driver_OA_RES_CTRL_REG & \
           (uint32)~LED_driver_OA_PWR_MODE_MASK;
    LED_driver_OA_RES_CTRL_REG = tmp | LED_driver_internalPower;
}


/*******************************************************************************
* Function Name: LED_driver_PumpControl
********************************************************************************
*
* Summary:
*  Allows the user to turn the Opamp's boost pump on or off. By Default the Start() 
*  function turns on the pump. Use this API to turn it off. The boost must be 
*  turned on when the supply is less than 2.7 volts and off if the supply is more 
*  than 4 volts.
*
* Parameters:
*  onOff: Control the pump.
*   LED_driver_PUMP_OFF - Turn off the pump
*   LED_driver_PUMP_ON - Turn on the pump
*
* Return:
*  None
*
**********************************************************************************/
void LED_driver_PumpControl(uint32 onOff)
{
    
    if(0u != onOff)
    {
        LED_driver_OA_RES_CTRL |= LED_driver_OA_PUMP_EN;    
    }
    else
    {
        LED_driver_OA_RES_CTRL &= (uint32)~LED_driver_OA_PUMP_EN;
    }
}


/* [] END OF FILE */
