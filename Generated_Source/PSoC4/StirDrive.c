/*******************************************************************************
* File Name: StirDrive.c  
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
#include "StirDrive.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        StirDrive_PC =   (StirDrive_PC & \
                                (uint32)(~(uint32)(StirDrive_DRIVE_MODE_IND_MASK << (StirDrive_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (StirDrive_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: StirDrive_Write
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
void StirDrive_Write(uint8 value) 
{
    uint8 drVal = (uint8)(StirDrive_DR & (uint8)(~StirDrive_MASK));
    drVal = (drVal | ((uint8)(value << StirDrive_SHIFT) & StirDrive_MASK));
    StirDrive_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: StirDrive_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  StirDrive_DM_STRONG     Strong Drive 
*  StirDrive_DM_OD_HI      Open Drain, Drives High 
*  StirDrive_DM_OD_LO      Open Drain, Drives Low 
*  StirDrive_DM_RES_UP     Resistive Pull Up 
*  StirDrive_DM_RES_DWN    Resistive Pull Down 
*  StirDrive_DM_RES_UPDWN  Resistive Pull Up/Down 
*  StirDrive_DM_DIG_HIZ    High Impedance Digital 
*  StirDrive_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void StirDrive_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(StirDrive__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: StirDrive_Read
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
*  Macro StirDrive_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 StirDrive_Read(void) 
{
    return (uint8)((StirDrive_PS & StirDrive_MASK) >> StirDrive_SHIFT);
}


/*******************************************************************************
* Function Name: StirDrive_ReadDataReg
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
uint8 StirDrive_ReadDataReg(void) 
{
    return (uint8)((StirDrive_DR & StirDrive_MASK) >> StirDrive_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(StirDrive_INTSTAT) 

    /*******************************************************************************
    * Function Name: StirDrive_ClearInterrupt
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
    uint8 StirDrive_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(StirDrive_INTSTAT & StirDrive_MASK);
		StirDrive_INTSTAT = maskedStatus;
        return maskedStatus >> StirDrive_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
