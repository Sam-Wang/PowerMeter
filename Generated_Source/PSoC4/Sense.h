/*******************************************************************************
* File Name: Sense.h  
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

#if !defined(CY_PINS_Sense_H) /* Pins Sense_H */
#define CY_PINS_Sense_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Sense_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Sense_Write(uint8 value) ;
void    Sense_SetDriveMode(uint8 mode) ;
uint8   Sense_ReadDataReg(void) ;
uint8   Sense_Read(void) ;
uint8   Sense_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Sense_DRIVE_MODE_BITS        (3)
#define Sense_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Sense_DRIVE_MODE_BITS))

#define Sense_DM_ALG_HIZ         (0x00u)
#define Sense_DM_DIG_HIZ         (0x01u)
#define Sense_DM_RES_UP          (0x02u)
#define Sense_DM_RES_DWN         (0x03u)
#define Sense_DM_OD_LO           (0x04u)
#define Sense_DM_OD_HI           (0x05u)
#define Sense_DM_STRONG          (0x06u)
#define Sense_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Sense_MASK               Sense__MASK
#define Sense_SHIFT              Sense__SHIFT
#define Sense_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sense_PS                     (* (reg32 *) Sense__PS)
/* Port Configuration */
#define Sense_PC                     (* (reg32 *) Sense__PC)
/* Data Register */
#define Sense_DR                     (* (reg32 *) Sense__DR)
/* Input Buffer Disable Override */
#define Sense_INP_DIS                (* (reg32 *) Sense__PC2)


#if defined(Sense__INTSTAT)  /* Interrupt Registers */

    #define Sense_INTSTAT                (* (reg32 *) Sense__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Sense_DRIVE_MODE_SHIFT       (0x00u)
#define Sense_DRIVE_MODE_MASK        (0x07u << Sense_DRIVE_MODE_SHIFT)


#endif /* End Pins Sense_H */


/* [] END OF FILE */
