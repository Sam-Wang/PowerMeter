/*******************************************************************************
* File Name: Ref.h  
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

#if !defined(CY_PINS_Ref_H) /* Pins Ref_H */
#define CY_PINS_Ref_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Ref_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Ref_Write(uint8 value) ;
void    Ref_SetDriveMode(uint8 mode) ;
uint8   Ref_ReadDataReg(void) ;
uint8   Ref_Read(void) ;
uint8   Ref_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Ref_DRIVE_MODE_BITS        (3)
#define Ref_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Ref_DRIVE_MODE_BITS))

#define Ref_DM_ALG_HIZ         (0x00u)
#define Ref_DM_DIG_HIZ         (0x01u)
#define Ref_DM_RES_UP          (0x02u)
#define Ref_DM_RES_DWN         (0x03u)
#define Ref_DM_OD_LO           (0x04u)
#define Ref_DM_OD_HI           (0x05u)
#define Ref_DM_STRONG          (0x06u)
#define Ref_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Ref_MASK               Ref__MASK
#define Ref_SHIFT              Ref__SHIFT
#define Ref_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Ref_PS                     (* (reg32 *) Ref__PS)
/* Port Configuration */
#define Ref_PC                     (* (reg32 *) Ref__PC)
/* Data Register */
#define Ref_DR                     (* (reg32 *) Ref__DR)
/* Input Buffer Disable Override */
#define Ref_INP_DIS                (* (reg32 *) Ref__PC2)


#if defined(Ref__INTSTAT)  /* Interrupt Registers */

    #define Ref_INTSTAT                (* (reg32 *) Ref__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Ref_DRIVE_MODE_SHIFT       (0x00u)
#define Ref_DRIVE_MODE_MASK        (0x07u << Ref_DRIVE_MODE_SHIFT)


#endif /* End Pins Ref_H */


/* [] END OF FILE */
