/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vBRS
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\GenData\vBrsCfg.h
 *   Generation Time: 2024-01-23 23:53:07
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#ifndef _VBRSCFG_H_
#define _VBRSCFG_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#if !defined (BRS_INCLUDED_BY_ASM_FILE)
# include "Std_Types.h"
#endif

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define BASIC_RUNTIME_SYSTEM_TYPE_MSR4

#define BRS_GENERATED_HW_CONFIG_VERSION 332U

/*******************************************************************************
 Standard BRS configuration
*******************************************************************************/
/* Testsuite support is disabled (#define BRS_ENABLE_TESTSUITE_SUPPORT) */

/* TCC support is disabled (#define BRS_ENABLE_TCC_COMIF_SUPPORT / #define BRS_ENABLE_TCC_TCM_SUPPORT) */

/* LED support is disabled (#define BRS_ENABLE_SUPPORT_LEDS) */

/* Toggle custom pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN) */

/* Toggle watchdog pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) */


/*******************************************************************************
 Additional BRS support features
*******************************************************************************/
/* Switch to enable support of SafeContext OS */
/* SafeContext support is disabled (#define BRS_ENABLE_SAFECTXSUPPORT) */

/* Switch to enable support of MultiCore OS */
#define BRS_ENABLE_OS_MULTICORESUPPORT

/* Switches to enable support of FlashBootLoader and to define the FBL Type */
/* FlashBootLoader support is disabled (#define BRS_ENABLE_FBL_SUPPORT) */

/*******************************************************************************
 BRS hardware configuration constants
*******************************************************************************/
/* Main Oscillator Clock (MHz) */
#define BRS_OSC_CLK 20

/* Timebase Clock (Hz) */
#define BRS_TIMEBASE_CLOCK 200

/* Peripheral Clock (MHz) */
#define BRS_PERIPH_CLOCK 80


/*******************************************************************************
 Tested Derivative: Infineon Aurix TC27x Family
*******************************************************************************/
#define BRS_DERIVATIVE_TC27x

/*******************************************************************************
 CPU Core
*******************************************************************************/
#define BRS_CPU_CORE_TC161

/*******************************************************************************
 CPU Max Frequency (Hz)
*******************************************************************************/
#define BRS_CPU_MAX_FREQUENCY 200

/*******************************************************************************
 CPU Core Amount (number of cores)
*******************************************************************************/
#define BRS_CPU_CORE_AMOUNT 3

/*******************************************************************************
 Derivative Group
*******************************************************************************/
#define BRS_DERIVATIVE_GROUP_TC2xx

/*******************************************************************************
 Pll Group
*******************************************************************************/
#define BRS_PLL_GROUP_A

/*******************************************************************************
 Port Group
*******************************************************************************/
#define BRS_PORT_GROUP_A

/*******************************************************************************
 Reset Group
*******************************************************************************/
#define BRS_RESET_GROUP_A

/*******************************************************************************
 Watchdog Group
*******************************************************************************/
#define BRS_WATCHDOG_GROUP_A

/*******************************************************************************
 Init Patterns
*******************************************************************************/
#define BRS_INIT_PATTERN_BLOCKS (0x0UL)
#define BRS_INIT_PATTERN_HARDRESET_BLOCKS (0x0UL)
#define BRS_INIT_PATTERN_AREAS (0x0UL)
#define BRS_INIT_PATTERN_HARDRESET_AREAS (0x0UL)

#endif /*_VBRSCFG_H_*/

