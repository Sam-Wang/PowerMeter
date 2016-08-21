/*******************************************************************************
* File Name: Thermistor.c  
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
#include "Thermistor.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Thermistor_PC =   (Thermistor_PC & \
                                (uint32)(~(uint32)(Thermistor_DRIVE_MODE_IND_MASK << (Thermistor_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Thermistor_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Thermistor_Write
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
void Thermistor_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Thermistor_DR & (uint8)(~Thermistor_MASK));
    drVal = (drVal | ((uint8)(value << Thermistor_SHIFT) & Thermistor_MASK));
    Thermistor_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Thermistor_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Thermistor_DM_STRONG     Strong Drive 
*  Thermistor_DM_OD_HI      Open Drain, Drives High 
*  Thermistor_DM_OD_LO      Open Drain, Drives Low 
*  Thermistor_DM_RES_UP     Resistive Pull Up 
*  Thermistor_DM_RES_DWN    Resistive Pull Down 
*  Thermistor_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Thermistor_DM_DIG_HIZ    High Impedance Digital 
*  Thermistor_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Thermistor_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Thermistor__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Thermistor_Read
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
*  Macro Thermistor_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Thermistor_Read(void) 
{
    return (uint8)((Thermistor_PS & Thermistor_MASK) >> Thermistor_SHIFT);
}


/*******************************************************************************
* Function Name: Thermistor_ReadDataReg
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
uint8 Thermistor_ReadDataReg(void) 
{
    return (uint8)((Thermistor_DR & Thermistor_MASK) >> Thermistor_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Thermistor_INTSTAT) 

    /*******************************************************************************
    * Function Name: Thermistor_ClearInterrupt
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
    uint8 Thermistor_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Thermistor_INTSTAT & Thermistor_MASK);
		Thermistor_INTSTAT = maskedStatus;
        return maskedStatus >> Thermistor_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
