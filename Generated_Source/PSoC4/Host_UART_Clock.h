/*******************************************************************************
* File Name: Host_UART_Clock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Host_UART_Clock_H)
#define CY_CLOCK_Host_UART_Clock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Host_UART_Clock_StartEx(uint32 alignClkDiv);
#define Host_UART_Clock_Start() \
    Host_UART_Clock_StartEx(Host_UART_Clock__PA_DIV_ID)

#else

void Host_UART_Clock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Host_UART_Clock_Stop(void);

void Host_UART_Clock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Host_UART_Clock_GetDividerRegister(void);
uint8  Host_UART_Clock_GetFractionalDividerRegister(void);

#define Host_UART_Clock_Enable()                         Host_UART_Clock_Start()
#define Host_UART_Clock_Disable()                        Host_UART_Clock_Stop()
#define Host_UART_Clock_SetDividerRegister(clkDivider, reset)  \
    Host_UART_Clock_SetFractionalDividerRegister((clkDivider), 0u)
#define Host_UART_Clock_SetDivider(clkDivider)           Host_UART_Clock_SetDividerRegister((clkDivider), 1u)
#define Host_UART_Clock_SetDividerValue(clkDivider)      Host_UART_Clock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Host_UART_Clock_DIV_ID     Host_UART_Clock__DIV_ID

#define Host_UART_Clock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Host_UART_Clock_CTRL_REG   (*(reg32 *)Host_UART_Clock__CTRL_REGISTER)
#define Host_UART_Clock_DIV_REG    (*(reg32 *)Host_UART_Clock__DIV_REGISTER)

#define Host_UART_Clock_CMD_DIV_SHIFT          (0u)
#define Host_UART_Clock_CMD_PA_DIV_SHIFT       (8u)
#define Host_UART_Clock_CMD_DISABLE_SHIFT      (30u)
#define Host_UART_Clock_CMD_ENABLE_SHIFT       (31u)

#define Host_UART_Clock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Host_UART_Clock_CMD_DISABLE_SHIFT))
#define Host_UART_Clock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Host_UART_Clock_CMD_ENABLE_SHIFT))

#define Host_UART_Clock_DIV_FRAC_MASK  (0x000000F8u)
#define Host_UART_Clock_DIV_FRAC_SHIFT (3u)
#define Host_UART_Clock_DIV_INT_MASK   (0xFFFFFF00u)
#define Host_UART_Clock_DIV_INT_SHIFT  (8u)

#else 

#define Host_UART_Clock_DIV_REG        (*(reg32 *)Host_UART_Clock__REGISTER)
#define Host_UART_Clock_ENABLE_REG     Host_UART_Clock_DIV_REG
#define Host_UART_Clock_DIV_FRAC_MASK  Host_UART_Clock__FRAC_MASK
#define Host_UART_Clock_DIV_FRAC_SHIFT (16u)
#define Host_UART_Clock_DIV_INT_MASK   Host_UART_Clock__DIVIDER_MASK
#define Host_UART_Clock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Host_UART_Clock_H) */

/* [] END OF FILE */
