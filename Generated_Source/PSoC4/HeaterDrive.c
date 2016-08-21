/*******************************************************************************
* File Name: HeaterDrive.c  
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
#include "HeaterDrive.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        HeaterDrive_PC =   (HeaterDrive_PC & \
                                (uint32)(~(uint32)(HeaterDrive_DRIVE_MODE_IND_MASK << (HeaterDrive_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (HeaterDrive_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: HeaterDrive_Write
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
void HeaterDrive_Write(uint8 value) 
{
    uint8 drVal = (uint8)(HeaterDrive_DR & (uint8)(~HeaterDrive_MASK));
    drVal = (drVal | ((uint8)(value << HeaterDrive_SHIFT) & HeaterDrive_MASK));
    HeaterDrive_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: HeaterDrive_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  HeaterDrive_DM_STRONG     Strong Drive 
*  HeaterDrive_DM_OD_HI      Open Drain, Drives High 
*  HeaterDrive_DM_OD_LO      Open Drain, Drives Low 
*  HeaterDrive_DM_RES_UP     Resistive Pull Up 
*  HeaterDrive_DM_RES_DWN    Resistive Pull Down 
*  HeaterDrive_DM_RES_UPDWN  Resistive Pull Up/Down 
*  HeaterDrive_DM_DIG_HIZ    High Impedance Digital 
*  HeaterDrive_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void HeaterDrive_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(HeaterDrive__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: HeaterDrive_Read
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
*  Macro HeaterDrive_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HeaterDrive_Read(void) 
{
    return (uint8)((HeaterDrive_PS & HeaterDrive_MASK) >> HeaterDrive_SHIFT);
}


/*******************************************************************************
* Function Name: HeaterDrive_ReadDataReg
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
uint8 HeaterDrive_ReadDataReg(void) 
{
    return (uint8)((HeaterDrive_DR & HeaterDrive_MASK) >> HeaterDrive_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HeaterDrive_INTSTAT) 

    /*******************************************************************************
    * Function Name: HeaterDrive_ClearInterrupt
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
    uint8 HeaterDrive_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(HeaterDrive_INTSTAT & HeaterDrive_MASK);
		HeaterDrive_INTSTAT = maskedStatus;
        return maskedStatus >> HeaterDrive_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
