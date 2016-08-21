/*******************************************************************************
* File Name: Transimpedance.c
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

#include "Transimpedance.h"

uint8 Transimpedance_initVar = 0u; /* Defines if component was initialized */
static uint32 Transimpedance_internalPower = 0u; /* Defines component Power value */


/*******************************************************************************
* Function Name: Transimpedance_Init
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
void Transimpedance_Init(void)
{
    Transimpedance_internalPower = Transimpedance_POWER;
    Transimpedance_CTB_CTRL_REG = Transimpedance_DEFAULT_CTB_CTRL;
    Transimpedance_OA_RES_CTRL_REG = Transimpedance_DEFAULT_OA_RES_CTRL;
    Transimpedance_OA_COMP_TRIM_REG = Transimpedance_DEFAULT_OA_COMP_TRIM_REG;
}


/*******************************************************************************
* Function Name: Transimpedance_Enable
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
void Transimpedance_Enable(void)
{
    Transimpedance_OA_RES_CTRL_REG |= Transimpedance_internalPower | \
                                        Transimpedance_OA_PUMP_EN;
}


/*******************************************************************************
* Function Name: Transimpedance_Start
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
*  Transimpedance_initVar: Used to check the initial configuration, modified
*  when this function is called for the first time.
*
*******************************************************************************/
void Transimpedance_Start(void)
{
    if( 0u == Transimpedance_initVar)
    {
        Transimpedance_Init();
        Transimpedance_initVar = 1u;
    }
    Transimpedance_Enable();
}


/*******************************************************************************
* Function Name: Transimpedance_Stop
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
void Transimpedance_Stop(void)
{
    Transimpedance_OA_RES_CTRL_REG &= ((uint32)~(Transimpedance_OA_PWR_MODE_MASK | \
                                                   Transimpedance_OA_PUMP_EN));
}


/*******************************************************************************
* Function Name: Transimpedance_SetPower
********************************************************************************
*
* Summary:
*  Sets the Opamp to one of the three power levels.
*
* Parameters:
*  power: power levels.
*   Transimpedance_LOW_POWER - Lowest active power
*   Transimpedance_MED_POWER - Medium power
*   Transimpedance_HIGH_POWER - Highest active power
*
* Return:
*  None
*
**********************************************************************************/
void Transimpedance_SetPower(uint32 power)
{
    uint32 tmp;
    
    Transimpedance_internalPower = Transimpedance_GET_OA_PWR_MODE(power);
    tmp = Transimpedance_OA_RES_CTRL_REG & \
           (uint32)~Transimpedance_OA_PWR_MODE_MASK;
    Transimpedance_OA_RES_CTRL_REG = tmp | Transimpedance_internalPower;
}


/*******************************************************************************
* Function Name: Transimpedance_PumpControl
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
*   Transimpedance_PUMP_OFF - Turn off the pump
*   Transimpedance_PUMP_ON - Turn on the pump
*
* Return:
*  None
*
**********************************************************************************/
void Transimpedance_PumpControl(uint32 onOff)
{
    
    if(0u != onOff)
    {
        Transimpedance_OA_RES_CTRL |= Transimpedance_OA_PUMP_EN;    
    }
    else
    {
        Transimpedance_OA_RES_CTRL &= (uint32)~Transimpedance_OA_PUMP_EN;
    }
}


/* [] END OF FILE */
