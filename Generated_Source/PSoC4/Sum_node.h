/*******************************************************************************
* File Name: Sum_node.h  
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

#if !defined(CY_PINS_Sum_node_H) /* Pins Sum_node_H */
#define CY_PINS_Sum_node_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Sum_node_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Sum_node_Write(uint8 value) ;
void    Sum_node_SetDriveMode(uint8 mode) ;
uint8   Sum_node_ReadDataReg(void) ;
uint8   Sum_node_Read(void) ;
uint8   Sum_node_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Sum_node_DRIVE_MODE_BITS        (3)
#define Sum_node_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Sum_node_DRIVE_MODE_BITS))

#define Sum_node_DM_ALG_HIZ         (0x00u)
#define Sum_node_DM_DIG_HIZ         (0x01u)
#define Sum_node_DM_RES_UP          (0x02u)
#define Sum_node_DM_RES_DWN         (0x03u)
#define Sum_node_DM_OD_LO           (0x04u)
#define Sum_node_DM_OD_HI           (0x05u)
#define Sum_node_DM_STRONG          (0x06u)
#define Sum_node_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Sum_node_MASK               Sum_node__MASK
#define Sum_node_SHIFT              Sum_node__SHIFT
#define Sum_node_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sum_node_PS                     (* (reg32 *) Sum_node__PS)
/* Port Configuration */
#define Sum_node_PC                     (* (reg32 *) Sum_node__PC)
/* Data Register */
#define Sum_node_DR                     (* (reg32 *) Sum_node__DR)
/* Input Buffer Disable Override */
#define Sum_node_INP_DIS                (* (reg32 *) Sum_node__PC2)


#if defined(Sum_node__INTSTAT)  /* Interrupt Registers */

    #define Sum_node_INTSTAT                (* (reg32 *) Sum_node__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Sum_node_DRIVE_MODE_SHIFT       (0x00u)
#define Sum_node_DRIVE_MODE_MASK        (0x07u << Sum_node_DRIVE_MODE_SHIFT)


#endif /* End Pins Sum_node_H */


/* [] END OF FILE */
