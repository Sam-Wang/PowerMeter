/*******************************************************************************
* File Name: Agnd.h  
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

#if !defined(CY_PINS_Agnd_H) /* Pins Agnd_H */
#define CY_PINS_Agnd_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Agnd_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Agnd_Write(uint8 value) ;
void    Agnd_SetDriveMode(uint8 mode) ;
uint8   Agnd_ReadDataReg(void) ;
uint8   Agnd_Read(void) ;
uint8   Agnd_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Agnd_DRIVE_MODE_BITS        (3)
#define Agnd_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Agnd_DRIVE_MODE_BITS))

#define Agnd_DM_ALG_HIZ         (0x00u)
#define Agnd_DM_DIG_HIZ         (0x01u)
#define Agnd_DM_RES_UP          (0x02u)
#define Agnd_DM_RES_DWN         (0x03u)
#define Agnd_DM_OD_LO           (0x04u)
#define Agnd_DM_OD_HI           (0x05u)
#define Agnd_DM_STRONG          (0x06u)
#define Agnd_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Agnd_MASK               Agnd__MASK
#define Agnd_SHIFT              Agnd__SHIFT
#define Agnd_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Agnd_PS                     (* (reg32 *) Agnd__PS)
/* Port Configuration */
#define Agnd_PC                     (* (reg32 *) Agnd__PC)
/* Data Register */
#define Agnd_DR                     (* (reg32 *) Agnd__DR)
/* Input Buffer Disable Override */
#define Agnd_INP_DIS                (* (reg32 *) Agnd__PC2)


#if defined(Agnd__INTSTAT)  /* Interrupt Registers */

    #define Agnd_INTSTAT                (* (reg32 *) Agnd__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Agnd_DRIVE_MODE_SHIFT       (0x00u)
#define Agnd_DRIVE_MODE_MASK        (0x07u << Agnd_DRIVE_MODE_SHIFT)


#endif /* End Pins Agnd_H */


/* [] END OF FILE */
