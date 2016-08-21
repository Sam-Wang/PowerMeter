/*******************************************************************************
* File Name: Ref.c  
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
#include "Ref.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Ref_PC =   (Ref_PC & \
                                (uint32)(~(uint32)(Ref_DRIVE_MODE_IND_MASK << (Ref_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Ref_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Ref_Write
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
void Ref_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Ref_DR & (uint8)(~Ref_MASK));
    drVal = (drVal | ((uint8)(value << Ref_SHIFT) & Ref_MASK));
    Ref_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Ref_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Ref_DM_STRONG     Strong Drive 
*  Ref_DM_OD_HI      Open Drain, Drives High 
*  Ref_DM_OD_LO      Open Drain, Drives Low 
*  Ref_DM_RES_UP     Resistive Pull Up 
*  Ref_DM_RES_DWN    Resistive Pull Down 
*  Ref_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Ref_DM_DIG_HIZ    High Impedance Digital 
*  Ref_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Ref_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Ref__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Ref_Read
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
*  Macro Ref_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Ref_Read(void) 
{
    return (uint8)((Ref_PS & Ref_MASK) >> Ref_SHIFT);
}


/*******************************************************************************
* Function Name: Ref_ReadDataReg
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
uint8 Ref_ReadDataReg(void) 
{
    return (uint8)((Ref_DR & Ref_MASK) >> Ref_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Ref_INTSTAT) 

    /*******************************************************************************
    * Function Name: Ref_ClearInterrupt
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
    uint8 Ref_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Ref_INTSTAT & Ref_MASK);
		Ref_INTSTAT = maskedStatus;
        return maskedStatus >> Ref_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
