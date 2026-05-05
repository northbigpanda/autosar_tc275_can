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
 *              File: Os_Isr_Lcfg.h
 *   Generation Time: 2024-02-01 23:46:22
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#ifndef OS_ISR_LCFG_H
# define OS_ISR_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"
# include "Os_Timer_Types.h"
# include "Os_XSignal_Types.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsr_1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_1;

/*! ISR configuration data: CounterIsr_SystemTimer_Core0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_Core0_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_Core0;

/*! ISR configuration data: GTMTIM2SR7_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_GTMTIM2SR7_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTIM2SR7_ISR;

/*! ISR configuration data: XSignalIsr_OsCore0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore0_HwConfig;
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CounterIsr_SystemTimer_Core1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_Core1_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_Core1;

/*! ISR configuration data: XSignalIsr_OsCore1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore1_HwConfig;
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CounterIsr_SystemTimer_Core2 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_Core2_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_Core2;

/*! ISR configuration data: XSignalIsr_OsCore2 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore2_HwConfig;
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
extern CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ISR_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.h
 *********************************************************************************************************************/
