/*******************************************************************************
* File Name: Feedback.h  
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

#if !defined(CY_PINS_Feedback_H) /* Pins Feedback_H */
#define CY_PINS_Feedback_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Feedback_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Feedback_Write(uint8 value) ;
void    Feedback_SetDriveMode(uint8 mode) ;
uint8   Feedback_ReadDataReg(void) ;
uint8   Feedback_Read(void) ;
uint8   Feedback_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Feedback_DRIVE_MODE_BITS        (3)
#define Feedback_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Feedback_DRIVE_MODE_BITS))

#define Feedback_DM_ALG_HIZ         (0x00u)
#define Feedback_DM_DIG_HIZ         (0x01u)
#define Feedback_DM_RES_UP          (0x02u)
#define Feedback_DM_RES_DWN         (0x03u)
#define Feedback_DM_OD_LO           (0x04u)
#define Feedback_DM_OD_HI           (0x05u)
#define Feedback_DM_STRONG          (0x06u)
#define Feedback_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Feedback_MASK               Feedback__MASK
#define Feedback_SHIFT              Feedback__SHIFT
#define Feedback_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Feedback_PS                     (* (reg32 *) Feedback__PS)
/* Port Configuration */
#define Feedback_PC                     (* (reg32 *) Feedback__PC)
/* Data Register */
#define Feedback_DR                     (* (reg32 *) Feedback__DR)
/* Input Buffer Disable Override */
#define Feedback_INP_DIS                (* (reg32 *) Feedback__PC2)


#if defined(Feedback__INTSTAT)  /* Interrupt Registers */

    #define Feedback_INTSTAT                (* (reg32 *) Feedback__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Feedback_DRIVE_MODE_SHIFT       (0x00u)
#define Feedback_DRIVE_MODE_MASK        (0x07u << Feedback_DRIVE_MODE_SHIFT)


#endif /* End Pins Feedback_H */


/* [] END OF FILE */
