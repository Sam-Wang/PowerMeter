/*******************************************************************************
* File Name: LED_volt.h  
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

#if !defined(CY_PINS_LED_volt_H) /* Pins LED_volt_H */
#define CY_PINS_LED_volt_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED_volt_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_volt_Write(uint8 value) ;
void    LED_volt_SetDriveMode(uint8 mode) ;
uint8   LED_volt_ReadDataReg(void) ;
uint8   LED_volt_Read(void) ;
uint8   LED_volt_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_volt_DRIVE_MODE_BITS        (3)
#define LED_volt_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED_volt_DRIVE_MODE_BITS))

#define LED_volt_DM_ALG_HIZ         (0x00u)
#define LED_volt_DM_DIG_HIZ         (0x01u)
#define LED_volt_DM_RES_UP          (0x02u)
#define LED_volt_DM_RES_DWN         (0x03u)
#define LED_volt_DM_OD_LO           (0x04u)
#define LED_volt_DM_OD_HI           (0x05u)
#define LED_volt_DM_STRONG          (0x06u)
#define LED_volt_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LED_volt_MASK               LED_volt__MASK
#define LED_volt_SHIFT              LED_volt__SHIFT
#define LED_volt_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_volt_PS                     (* (reg32 *) LED_volt__PS)
/* Port Configuration */
#define LED_volt_PC                     (* (reg32 *) LED_volt__PC)
/* Data Register */
#define LED_volt_DR                     (* (reg32 *) LED_volt__DR)
/* Input Buffer Disable Override */
#define LED_volt_INP_DIS                (* (reg32 *) LED_volt__PC2)


#if defined(LED_volt__INTSTAT)  /* Interrupt Registers */

    #define LED_volt_INTSTAT                (* (reg32 *) LED_volt__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LED_volt_DRIVE_MODE_SHIFT       (0x00u)
#define LED_volt_DRIVE_MODE_MASK        (0x07u << LED_volt_DRIVE_MODE_SHIFT)


#endif /* End Pins LED_volt_H */


/* [] END OF FILE */
