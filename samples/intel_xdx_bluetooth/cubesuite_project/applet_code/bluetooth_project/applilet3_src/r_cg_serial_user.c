/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012, 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_serial_user.c
* Version      : Applilet3 for RL78/D1A V2.03.00.03 [07 Aug 2014]
* Device(s)    : R5F10DPJ
* Tool-Chain   : CA78K0R
* Description  : This file implements device driver for Serial module.
* Creation Date: 12/15/2015
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt INTLR0 r_uartf0_interrupt_receive
#pragma interrupt INTLT0 r_uartf0_interrupt_send
#pragma interrupt INTLS0 r_uartf0_interrupt_error
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t  * gp_uartf0_tx_address;       /* uartf0 transmit buffer address */
extern volatile uint8_t  * gp_uartf0_tx_bf_address;    /* uartf0 transmit buffer address in buffer mode */
extern volatile uint16_t   g_uartf0_quotient;          /* uartf0 transmit buffer data count */
extern volatile uint16_t   g_uartf0_remainder;         /* uartf0 transmit buffer data remainer */
extern volatile uint16_t   g_uartf0_tx_cnt;            /* uartf0 transmit data number */
extern volatile uint8_t  * gp_uartf0_rx_address;       /* uartf0 receive data address */
extern volatile uint16_t   g_uartf0_rx_cnt;            /* uartf0 receive data number */
extern volatile uint16_t   g_uartf0_rx_len;            /* uartf0 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_uartf0_interrupt_receive
* Description  : This function is INTLR0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
__interrupt static void r_uartf0_interrupt_receive(void)
{
    uint8_t rx_data_8;
    
    rx_data_8 = UF0RXB;
    
    if (g_uartf0_rx_len > g_uartf0_rx_cnt)
    {
        *gp_uartf0_rx_address = rx_data_8;
        gp_uartf0_rx_address++;
        g_uartf0_rx_cnt++;

        if (g_uartf0_rx_len == g_uartf0_rx_cnt)
        {
            r_uartf0_callback_receiveend();
        }
    }
    else
    {
        r_uartf0_callback_softwareoverrun(rx_data_8);
    }
}

/***********************************************************************************************************************
* Function Name: r_uartf0_interrupt_send
* Description  : This function is INTLT0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
__interrupt static void r_uartf0_interrupt_send(void)
{
    if (g_uartf0_tx_cnt > 0U)
    {
        LTMK0 = 1U; 
        UF0TXB = *gp_uartf0_tx_address;
        gp_uartf0_tx_address++;
        g_uartf0_tx_cnt--;
        LTMK0 = 0U; 
    }
    else
    {
        r_uartf0_callback_sendend();
    }
}

/***********************************************************************************************************************
* Function Name: r_uartf0_interrupt_error
* Description  : This function is INTLS0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
__interrupt static void r_uartf0_interrupt_error(void)
{
    uint8_t  err_type;

    *gp_uartf0_rx_address = UF0RXB;
    err_type = (uint8_t)(UF0STR & 0x07U);
    UF0STC |= _0007_UARTF_COMMONERROE_CLEAR;
    r_uartf0_callback_error(err_type);
}

/***********************************************************************************************************************
* Function Name: r_uartf0_callback_receiveend
* Description  : This function is a callback function of UARTF0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uartf0_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uartf0_callback_sendend
* Description  : This function is a callback function of UARTF0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uartf0_callback_sendend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uartf0_callback_error
* Description  : This function is a callback function of UARTF0.
* Arguments    : err_type -
*                    error type
* Return Value : None
***********************************************************************************************************************/
static void r_uartf0_callback_error(uint8_t err_type)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_uartf0_callback_softwareoverrun
* Description  : This function is a callback function of UARTF0.
* Arguments    : rx_data -
*                    receive data
* Return Value : None
***********************************************************************************************************************/
static void r_uartf0_callback_softwareoverrun(uint16_t rx_data)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
