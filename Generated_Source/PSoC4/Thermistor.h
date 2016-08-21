/*******************************************************************************
* File Name: Thermistor.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Thermistor_H) /* Pins Thermistor_H */
#define CY_PINS_Thermistor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Thermistor_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Thermistor_Write(uint8 value) ;
void    Thermistor_SetDriveMode(uint8 mode) ;
uint8   Thermistor_ReadDataReg(void) ;
uint8   Thermistor_Read(void) ;
uint8   Thermistor_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Thermistor_DRIVE_MODE_BITS        (3)
#define Thermistor_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Thermistor_DRIVE_MODE_BITS))

#define Thermistor_DM_ALG_HIZ         (0x00u)
#define Thermistor_DM_DIG_HIZ         (0x01u)
#define Thermistor_DM_RES_UP          (0x02u)
#define Thermistor_DM_RES_DWN         (0x03u)
#define Thermistor_DM_OD_LO           (0x04u)
#define Thermistor_DM_OD_HI           (0x05u)
#define Thermistor_DM_STRONG          (0x06u)
#define Thermistor_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Thermistor_MASK               Thermistor__MASK
#define Thermistor_SHIFT              Thermistor__SHIFT
#define Thermistor_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Thermistor_PS                     (* (reg32 *) Thermistor__PS)
/* Port Configuration */
#define Thermistor_PC                     (* (reg32 *) Thermistor__PC)
/* Data Register */
#define Thermistor_DR                     (* (reg32 *) Thermistor__DR)
/* Input Buffer Disable Override */
#define Thermistor_INP_DIS                (* (reg32 *) Thermistor__PC2)


#if defined(Thermistor__INTSTAT)  /* Interrupt Registers */

    #define Thermistor_INTSTAT                (* (reg32 *) Thermistor__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Thermistor_DRIVE_MODE_SHIFT       (0x00u)
#define Thermistor_DRIVE_MODE_MASK        (0x07u << Thermistor_DRIVE_MODE_SHIFT)


#endif /* End Pins Thermistor_H */


/* [] END OF FILE */
