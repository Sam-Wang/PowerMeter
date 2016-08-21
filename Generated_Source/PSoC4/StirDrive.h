/*******************************************************************************
* File Name: StirDrive.h  
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

#if !defined(CY_PINS_StirDrive_H) /* Pins StirDrive_H */
#define CY_PINS_StirDrive_H

#include "cytypes.h"
#include "cyfitter.h"
#include "StirDrive_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    StirDrive_Write(uint8 value) ;
void    StirDrive_SetDriveMode(uint8 mode) ;
uint8   StirDrive_ReadDataReg(void) ;
uint8   StirDrive_Read(void) ;
uint8   StirDrive_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define StirDrive_DRIVE_MODE_BITS        (3)
#define StirDrive_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - StirDrive_DRIVE_MODE_BITS))

#define StirDrive_DM_ALG_HIZ         (0x00u)
#define StirDrive_DM_DIG_HIZ         (0x01u)
#define StirDrive_DM_RES_UP          (0x02u)
#define StirDrive_DM_RES_DWN         (0x03u)
#define StirDrive_DM_OD_LO           (0x04u)
#define StirDrive_DM_OD_HI           (0x05u)
#define StirDrive_DM_STRONG          (0x06u)
#define StirDrive_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define StirDrive_MASK               StirDrive__MASK
#define StirDrive_SHIFT              StirDrive__SHIFT
#define StirDrive_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define StirDrive_PS                     (* (reg32 *) StirDrive__PS)
/* Port Configuration */
#define StirDrive_PC                     (* (reg32 *) StirDrive__PC)
/* Data Register */
#define StirDrive_DR                     (* (reg32 *) StirDrive__DR)
/* Input Buffer Disable Override */
#define StirDrive_INP_DIS                (* (reg32 *) StirDrive__PC2)


#if defined(StirDrive__INTSTAT)  /* Interrupt Registers */

    #define StirDrive_INTSTAT                (* (reg32 *) StirDrive__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define StirDrive_DRIVE_MODE_SHIFT       (0x00u)
#define StirDrive_DRIVE_MODE_MASK        (0x07u << StirDrive_DRIVE_MODE_SHIFT)


#endif /* End Pins StirDrive_H */


/* [] END OF FILE */
