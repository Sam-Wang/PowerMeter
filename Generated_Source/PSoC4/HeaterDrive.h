/*******************************************************************************
* File Name: HeaterDrive.h  
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

#if !defined(CY_PINS_HeaterDrive_H) /* Pins HeaterDrive_H */
#define CY_PINS_HeaterDrive_H

#include "cytypes.h"
#include "cyfitter.h"
#include "HeaterDrive_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    HeaterDrive_Write(uint8 value) ;
void    HeaterDrive_SetDriveMode(uint8 mode) ;
uint8   HeaterDrive_ReadDataReg(void) ;
uint8   HeaterDrive_Read(void) ;
uint8   HeaterDrive_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HeaterDrive_DRIVE_MODE_BITS        (3)
#define HeaterDrive_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - HeaterDrive_DRIVE_MODE_BITS))

#define HeaterDrive_DM_ALG_HIZ         (0x00u)
#define HeaterDrive_DM_DIG_HIZ         (0x01u)
#define HeaterDrive_DM_RES_UP          (0x02u)
#define HeaterDrive_DM_RES_DWN         (0x03u)
#define HeaterDrive_DM_OD_LO           (0x04u)
#define HeaterDrive_DM_OD_HI           (0x05u)
#define HeaterDrive_DM_STRONG          (0x06u)
#define HeaterDrive_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define HeaterDrive_MASK               HeaterDrive__MASK
#define HeaterDrive_SHIFT              HeaterDrive__SHIFT
#define HeaterDrive_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HeaterDrive_PS                     (* (reg32 *) HeaterDrive__PS)
/* Port Configuration */
#define HeaterDrive_PC                     (* (reg32 *) HeaterDrive__PC)
/* Data Register */
#define HeaterDrive_DR                     (* (reg32 *) HeaterDrive__DR)
/* Input Buffer Disable Override */
#define HeaterDrive_INP_DIS                (* (reg32 *) HeaterDrive__PC2)


#if defined(HeaterDrive__INTSTAT)  /* Interrupt Registers */

    #define HeaterDrive_INTSTAT                (* (reg32 *) HeaterDrive__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define HeaterDrive_DRIVE_MODE_SHIFT       (0x00u)
#define HeaterDrive_DRIVE_MODE_MASK        (0x07u << HeaterDrive_DRIVE_MODE_SHIFT)


#endif /* End Pins HeaterDrive_H */


/* [] END OF FILE */
