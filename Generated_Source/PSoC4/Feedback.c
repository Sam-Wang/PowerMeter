/*******************************************************************************
* File Name: Feedback.c  
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
#include "Feedback.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Feedback_PC =   (Feedback_PC & \
                                (uint32)(~(uint32)(Feedback_DRIVE_MODE_IND_MASK << (Feedback_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Feedback_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Feedback_Write
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
void Feedback_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Feedback_DR & (uint8)(~Feedback_MASK));
    drVal = (drVal | ((uint8)(value << Feedback_SHIFT) & Feedback_MASK));
    Feedback_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Feedback_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Feedback_DM_STRONG     Strong Drive 
*  Feedback_DM_OD_HI      Open Drain, Drives High 
*  Feedback_DM_OD_LO      Open Drain, Drives Low 
*  Feedback_DM_RES_UP     Resistive Pull Up 
*  Feedback_DM_RES_DWN    Resistive Pull Down 
*  Feedback_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Feedback_DM_DIG_HIZ    High Impedance Digital 
*  Feedback_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Feedback_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Feedback__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Feedback_Read
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
*  Macro Feedback_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Feedback_Read(void) 
{
    return (uint8)((Feedback_PS & Feedback_MASK) >> Feedback_SHIFT);
}


/*******************************************************************************
* Function Name: Feedback_ReadDataReg
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
uint8 Feedback_ReadDataReg(void) 
{
    return (uint8)((Feedback_DR & Feedback_MASK) >> Feedback_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Feedback_INTSTAT) 

    /*******************************************************************************
    * Function Name: Feedback_ClearInterrupt
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
    uint8 Feedback_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Feedback_INTSTAT & Feedback_MASK);
		Feedback_INTSTAT = maskedStatus;
        return maskedStatus >> Feedback_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
