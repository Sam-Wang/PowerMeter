/*******************************************************************************
* File Name: PumpDrive.h  
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

#if !defined(CY_PINS_PumpDrive_H) /* Pins PumpDrive_H */
#define CY_PINS_PumpDrive_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PumpDrive_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PumpDrive_Write(uint8 value) ;
void    PumpDrive_SetDriveMode(uint8 mode) ;
uint8   PumpDrive_ReadDataReg(void) ;
uint8   PumpDrive_Read(void) ;
uint8   PumpDrive_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PumpDrive_DRIVE_MODE_BITS        (3)
#define PumpDrive_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PumpDrive_DRIVE_MODE_BITS))

#define PumpDrive_DM_ALG_HIZ         (0x00u)
#define PumpDrive_DM_DIG_HIZ         (0x01u)
#define PumpDrive_DM_RES_UP          (0x02u)
#define PumpDrive_DM_RES_DWN         (0x03u)
#define PumpDrive_DM_OD_LO           (0x04u)
#define PumpDrive_DM_OD_HI           (0x05u)
#define PumpDrive_DM_STRONG          (0x06u)
#define PumpDrive_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define PumpDrive_MASK               PumpDrive__MASK
#define PumpDrive_SHIFT              PumpDrive__SHIFT
#define PumpDrive_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PumpDrive_PS                     (* (reg32 *) PumpDrive__PS)
/* Port Configuration */
#define PumpDrive_PC                     (* (reg32 *) PumpDrive__PC)
/* Data Register */
#define PumpDrive_DR                     (* (reg32 *) PumpDrive__DR)
/* Input Buffer Disable Override */
#define PumpDrive_INP_DIS                (* (reg32 *) PumpDrive__PC2)


#if defined(PumpDrive__INTSTAT)  /* Interrupt Registers */

    #define PumpDrive_INTSTAT                (* (reg32 *) PumpDrive__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define PumpDrive_DRIVE_MODE_SHIFT       (0x00u)
#define PumpDrive_DRIVE_MODE_MASK        (0x07u << PumpDrive_DRIVE_MODE_SHIFT)


#endif /* End Pins PumpDrive_H */


/* [] END OF FILE */
