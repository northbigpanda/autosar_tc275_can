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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Timer_Lcfg.c
 *   Generation Time: 2026-05-17 00:17:54
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] Cfg95301 - Os Interrupt Service Routine parameter invalid or different to configuration in BSW module 
 * - [Reduced Severity due to User-Defined Parameter] Either this parameter deviates from its definition in the /ActiveEcuC/Can Os Interrupt Service Routine or the definition of this parameter is invalid.
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/CanIsr_0 (DefRef: /MICROSAR/Os/OsIsr)
 * /ActiveEcuC/Os/CanIsr_0[0:OsIsrInterruptPriority](value=100) (DefRef: /MICROSAR/Os/OsIsr/OsIsrInterruptPriority)
 *********************************************************************************************************************/
/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_TIMER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Timer_Lcfg.h"
#include "Os_Hal_Timer.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer_Core0 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer_Core0 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM0_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM0_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM0_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM0_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM0_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer_Core1 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer_Core1 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM1_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM1_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM1_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM1_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM1_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: SystemTimer_Core2 */
CONST(Os_Hal_TimerFrtConfigType, OS_CONST) OsCfg_Hal_TimerFrt_SystemTimer_Core2 =
{
  /* CounterRegisterAddress            = */ OS_HAL_TIMER_STM2_BASE + OS_HAL_TIMER_STM_TIM0_OFFSET,
  /* CompareRegisterAddress            = */ OS_HAL_TIMER_STM2_BASE + OS_HAL_TIMER_STM_CMP0_OFFSET,
  /* CMCONRegisterAddress              = */ OS_HAL_TIMER_STM2_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET,
  /* CMCONMask                         = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK,
  /* CMCONValue                        = */ OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE,
  /* InterruptSRCRegisterAddress       = */ OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM2_CH0_OFFSET,
  /* ICRRegisterAddress                = */ OS_HAL_TIMER_STM2_BASE + OS_HAL_TIMER_STM_ICR_OFFSET,
  /* ICRMask                           = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK,
  /* ICRValue                          = */ OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE,
  /* ReloadValue                       = */ 0
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Lcfg.c
 *********************************************************************************************************************/
