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
* File Name    : r_cg_port.h
* Version      : Applilet3 for RL78/D1A V2.03.00.03 [07 Aug 2014]
* Device(s)    : R5F10DPJ
* Tool-Chain   : CA78K0R
* Description  : This file implements device driver for PORT module.
* Creation Date: 12/15/2015
***********************************************************************************************************************/

#ifndef PORT_H
#define PORT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Port Mode Register (PMm)
*/
/* Pmn pin I/O mode selection (PMm7 - PMm0) */
#define _01_PMn0_NOT_USE         (0x01U) /* not use Pn0 as digital I/O */
#define _01_PMn0_MODE_INPUT      (0x01U) /* use Pn0 as input mode */
#define _00_PMn0_MODE_OUTPUT     (0x00U) /* use Pn0 as output mode */
#define _02_PMn1_NOT_USE         (0x02U) /* not use Pn1 as digital I/O */
#define _02_PMn1_MODE_INPUT      (0x02U) /* use Pn1 as input mode */
#define _00_PMn1_MODE_OUTPUT     (0x00U) /* use Pn1 as output mode */
#define _04_PMn2_NOT_USE         (0x04U) /* not use Pn2 as digital I/O */
#define _04_PMn2_MODE_INPUT      (0x04U) /* use Pn2 as input mode */
#define _00_PMn2_MODE_OUTPUT     (0x00U) /* use Pn2 as output mode */
#define _08_PMn3_NOT_USE         (0x08U) /* not use Pn3 as digital I/O */
#define _08_PMn3_MODE_INPUT      (0x08U) /* use Pn3 as input mode */
#define _00_PMn3_MODE_OUTPUT     (0x00U) /* use Pn3 as output mode */
#define _10_PMn4_NOT_USE         (0x10U) /* not use Pn4 as digital I/O */
#define _10_PMn4_MODE_INPUT      (0x10U) /* use Pn4 as input mode */
#define _00_PMn4_MODE_OUTPUT     (0x00U) /* use Pn4 as output mode */
#define _20_PMn5_NOT_USE         (0x20U) /* not use Pn5 as digital I/O */
#define _20_PMn5_MODE_INPUT      (0x20U) /* use Pn5 as input mode */
#define _00_PMn5_MODE_OUTPUT     (0x00U) /* use Pn5 as output mode */
#define _40_PMn6_NOT_USE         (0x40U) /* not use Pn6 as digital I/O */
#define _40_PMn6_MODE_INPUT      (0x40U) /* use Pn6 as input mode */
#define _00_PMn6_MODE_OUTPUT     (0x00U) /* use Pn6 as output mode */
#define _80_PMn7_NOT_USE         (0x80U) /* not use Pn7 as digital I/O */
#define _80_PMn7_MODE_INPUT      (0x80U) /* use Pn7 as input mode */
#define _00_PMn7_MODE_OUTPUT     (0x00U) /* use Pn7 as output mode */

/*
    Port Register (Pm)
*/
/* Pmn pin data (Pm0 to Pm7) */
#define _00_Pn0_OUTPUT_0         (0x00U) /* Pn0 output 0 */
#define _01_Pn0_OUTPUT_1         (0x01U) /* Pn0 output 1 */
#define _00_Pn1_OUTPUT_0         (0x00U) /* Pn1 output 0 */
#define _02_Pn1_OUTPUT_1         (0x02U) /* Pn1 output 1 */
#define _00_Pn2_OUTPUT_0         (0x00U) /* Pn2 output 0 */
#define _04_Pn2_OUTPUT_1         (0x04U) /* Pn2 output 1 */
#define _00_Pn3_OUTPUT_0         (0x00U) /* Pn3 output 0 */
#define _08_Pn3_OUTPUT_1         (0x08U) /* Pn3 output 1 */
#define _00_Pn4_OUTPUT_0         (0x00U) /* Pn4 output 0 */
#define _10_Pn4_OUTPUT_1         (0x10U) /* Pn4 output 1 */
#define _00_Pn5_OUTPUT_0         (0x00U) /* Pn5 output 0 */
#define _20_Pn5_OUTPUT_1         (0x20U) /* Pn5 output 1 */
#define _00_Pn6_OUTPUT_0         (0x00U) /* Pn6 output 0 */
#define _40_Pn6_OUTPUT_1         (0x40U) /* Pn6 output 1 */
#define _00_Pn7_OUTPUT_0         (0x00U) /* Pn7 output 0 */
#define _80_Pn7_OUTPUT_1         (0x80U) /* Pn7 output 1 */

/*
    Pull-up Resistor Option Register (PUm)
*/
/* Pmn pin on-chip pull-up resistor selection (PUmn) */
#define _00_PUn0_PULLUP_OFF      (0x00U) /* Pn0 pull-up resistor not connected */
#define _01_PUn0_PULLUP_ON       (0x01U) /* Pn0 pull-up resistor connected */
#define _00_PUn1_PULLUP_OFF      (0x00U) /* Pn1 pull-up resistor not connected */
#define _02_PUn1_PULLUP_ON       (0x02U) /* Pn1 pull-up resistor connected */
#define _00_PUn2_PULLUP_OFF      (0x00U) /* Pn2 Pull-up resistor not connected */
#define _04_PUn2_PULLUP_ON       (0x04U) /* Pn2 pull-up resistor connected */
#define _00_PUn3_PULLUP_OFF      (0x00U) /* Pn3 pull-up resistor not connected */
#define _08_PUn3_PULLUP_ON       (0x08U) /* Pn3 pull-up resistor connected */
#define _00_PUn4_PULLUP_OFF      (0x00U) /* Pn4 pull-up resistor not connected */
#define _10_PUn4_PULLUP_ON       (0x10U) /* Pn4 pull-up resistor connected */
#define _00_PUn5_PULLUP_OFF      (0x00U) /* Pn5 pull-up resistor not connected */
#define _20_PUn5_PULLUP_ON       (0x20U) /* Pn5 pull-up resistor connected */
#define _00_PUn6_PULLUP_OFF      (0x00U) /* Pn6 pull-up resistor not connected */
#define _40_PUn6_PULLUP_ON       (0x40U) /* Pn6 pull-up resistor connected */
#define _00_PUn7_PULLUP_OFF      (0x00U) /* Pn7 pull-up resistor not connected */
#define _80_PUn7_PULLUP_ON       (0x80U) /* Pn7 pull-up resistor connected */

/*
    Port Input Mode Register (PIMm)
*/
/* Pmn pin input buffer selection (PIMmn) */
#define _00_PIMn0_SCHMITT1_INPUT (0x00U) /* set Pn0 Schmitt1 input buffer */
#define _01_PIMn0_SCHMITT3_INPUT (0x01U) /* set Pn0 Schmitt3 input buffer */
#define _00_PIMn1_SCHMITT1_INPUT (0x00U) /* set Pn1 Schmitt1 input buffer */
#define _02_PIMn1_SCHMITT3_INPUT (0x02U) /* set Pn1 Schmitt3 input buffer */
#define _00_PIMn2_SCHMITT1_INPUT (0x00U) /* set Pn2 Schmitt1 input buffer */
#define _04_PIMn2_SCHMITT3_INPUT (0x04U) /* set Pn2 Schmitt3 input buffer */
#define _00_PIMn3_SCHMITT1_INPUT (0x00U) /* set Pn3 Schmitt1 input buffer */
#define _08_PIMn3_SCHMITT3_INPUT (0x08U) /* set Pn3 Schmitt3 input buffer */
#define _00_PIMn4_SCHMITT1_INPUT (0x00U) /* set Pn4 Schmitt1 input buffer */
#define _10_PIMn4_SCHMITT3_INPUT (0x10U) /* set Pn4 Schmitt3 input buffer */
#define _00_PIMn5_SCHMITT1_INPUT (0x00U) /* set Pn5 Schmitt1 input buffer */
#define _20_PIMn5_SCHMITT3_INPUT (0x20U) /* set Pn5 Schmitt3 input buffer */
#define _00_PIMn6_SCHMITT1_INPUT (0x00U) /* set Pn6 Schmitt1 input buffer */
#define _40_PIMn6_SCHMITT3_INPUT (0x40U) /* set Pn6 Schmitt3 input buffer */
#define _00_PIMn7_SCHMITT1_INPUT (0x00U) /* set Pn7 Schmitt1 input buffer */
#define _80_PIMn7_SCHMITT3_INPUT (0x80U) /* set Pn7 Schmitt3 input buffer */

/*
    Port Output Mode Register (POMm)
*/
/* Pmn pin output mode selection (POMmn) */
#define _00_POM0_NCH_OFF         (0x00U) /* set P60 output normal mode */
#define _01_POM0_NCH_ON          (0x01U) /* set P60 output N-ch open-drain mode */
#define _00_POM1_NCH_OFF         (0x00U) /* set P61 output normal mode */
#define _02_POM1_NCH_ON          (0x02U) /* set P61 output N-ch open-drain mode */
#define _00_POM2_NCH_OFF         (0x00U) /* set P30 output normal mode */
#define _04_POM2_NCH_ON          (0x04U) /* set P30 output N-ch open-drain mode */
#define _00_POM3_NCH_OFF         (0x00U) /* set P31 output normal mode */
#define _08_POM3_NCH_ON          (0x08U) /* set P31 output N-ch open-drain mode */
#define _00_POM4_NCH_OFF         (0x00U) /* set P136 output normal mode */
#define _10_POM4_NCH_ON          (0x10U) /* set P136 output N-ch open-drain mode */
#define _00_POM5_NCH_OFF         (0x00U) /* set P50 output normal mode */
#define _20_POM5_NCH_ON          (0x20U) /* set P50 output N-ch open-drain mode */

/*
    AD port configuration register (ADPC)
*/
/* Analog input/digital input switching (ADPC3 - ADPC0) */
#define _00_ADPC_DI_OFF          (0x00U) /* use P20 - P27 and P150 as analog input*/
#define _09_ADPC_DI_ON           (0x09U) /* use P150 as digital input */
#define _08_ADPC_DI_ON           (0x08U) /* use P27 and P150 as digital input */
#define _07_ADPC_DI_ON           (0x07U) /* use P26 - P27 and P150 as digital input */
#define _06_ADPC_DI_ON           (0x06U) /* use P25 - P27 and P150 as digital input */
#define _05_ADPC_DI_ON           (0x05U) /* use P24 - P27 and P150 as digital input */
#define _04_ADPC_DI_ON           (0x04U) /* use P23 - P27 and P150 as digital input */
#define _03_ADPC_DI_ON           (0x03U) /* use P22 - P27 and P150 as digital input */
#define _02_ADPC_DI_ON           (0x02U) /* use P21 - P27 and P150 as digital input */
#define _01_ADPC_DI_ON           (0x01U) /* use P20 - P27 and P150 as digital input */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _FE_PM4_DEFAULT          (0xFEU) /* PM4 default value */
#define _80_PM6_DEFAULT          (0x80U) /* PM6 default value */
#define _C0_PM7_DEFAULT          (0xC0U) /* PM7 default value */
#define _80_PM13_DEFAULT         (0x80U) /* PM13 default value */
#define _FE_PM14_DEFAULT         (0xFEU) /* PM14 default value */
#define _FE_PM15_DEFAULT         (0xFEU) /* PM15 default value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_PORT_Create(void);


/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
