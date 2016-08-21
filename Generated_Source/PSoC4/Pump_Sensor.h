/*******************************************************************************
* File Name: Pump_Sensor.h  
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

#if !defined(CY_PINS_Pump_Sensor_H) /* Pins Pump_Sensor_H */
#define CY_PINS_Pump_Sensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pump_Sensor_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pump_Sensor_Write(uint8 value) ;
void    Pump_Sensor_SetDriveMode(uint8 mode) ;
uint8   Pump_Sensor_ReadDataReg(void) ;
uint8   Pump_Sensor_Read(void) ;
uint8   Pump_Sensor_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pump_Sensor_DRIVE_MODE_BITS        (3)
#define Pump_Sensor_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pump_Sensor_DRIVE_MODE_BITS))

#define Pump_Sensor_DM_ALG_HIZ         (0x00u)
#define Pump_Sensor_DM_DIG_HIZ         (0x01u)
#define Pump_Sensor_DM_RES_UP          (0x02u)
#define Pump_Sensor_DM_RES_DWN         (0x03u)
#define Pump_Sensor_DM_OD_LO           (0x04u)
#define Pump_Sensor_DM_OD_HI           (0x05u)
#define Pump_Sensor_DM_STRONG          (0x06u)
#define Pump_Sensor_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Pump_Sensor_MASK               Pump_Sensor__MASK
#define Pump_Sensor_SHIFT              Pump_Sensor__SHIFT
#define Pump_Sensor_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pump_Sensor_PS                     (* (reg32 *) Pump_Sensor__PS)
/* Port Configuration */
#define Pump_Sensor_PC                     (* (reg32 *) Pump_Sensor__PC)
/* Data Register */
#define Pump_Sensor_DR                     (* (reg32 *) Pump_Sensor__DR)
/* Input Buffer Disable Override */
#define Pump_Sensor_INP_DIS                (* (reg32 *) Pump_Sensor__PC2)


#if defined(Pump_Sensor__INTSTAT)  /* Interrupt Registers */

    #define Pump_Sensor_INTSTAT                (* (reg32 *) Pump_Sensor__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Pump_Sensor_DRIVE_MODE_SHIFT       (0x00u)
#define Pump_Sensor_DRIVE_MODE_MASK        (0x07u << Pump_Sensor_DRIVE_MODE_SHIFT)


#endif /* End Pins Pump_Sensor_H */


/* [] END OF FILE */
