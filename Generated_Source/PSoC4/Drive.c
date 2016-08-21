/*******************************************************************************
* File Name: Drive.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Drive.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Drive_PC =   (Drive_PC & \
                                (uint32)(~(uint32)(Drive_DRIVE_MODE_IND_MASK << (Drive_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Drive_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Drive_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Drive_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Drive_DR & (uint8)(~Drive_MASK));
    drVal = (drVal | ((uint8)(value << Drive_SHIFT) & Drive_MASK));
    Drive_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Drive_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Drive_DM_STRONG     Strong Drive 
*  Drive_DM_OD_HI      Open Drain, Drives High 
*  Drive_DM_OD_LO      Open Drain, Drives Low 
*  Drive_DM_RES_UP     Resistive Pull Up 
*  Drive_DM_RES_DWN    Resistive Pull Down 
*  Drive_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Drive_DM_DIG_HIZ    High Impedance Digital 
*  Drive_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Drive_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Drive__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Drive_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Drive_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Drive_Read(void) 
{
    return (uint8)((Drive_PS & Drive_MASK) >> Drive_SHIFT);
}


/*******************************************************************************
* Function Name: Drive_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Drive_ReadDataReg(void) 
{
    return (uint8)((Drive_DR & Drive_MASK) >> Drive_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Drive_INTSTAT) 

    /*******************************************************************************
    * Function Name: Drive_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Drive_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Drive_INTSTAT & Drive_MASK);
		Drive_INTSTAT = maskedStatus;
        return maskedStatus >> Drive_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
