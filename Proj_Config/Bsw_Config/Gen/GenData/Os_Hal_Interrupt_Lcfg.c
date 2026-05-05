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
 *              File: Os_Hal_Interrupt_Lcfg.c
 *   Generation Time: 2024-02-01 23:46:21
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Core.h"


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

/*! HAL ISR configuration data: CanIsr_1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_1 =
{
  /* .Level          = */ 10,
  /* .Source         = */ 0x904uL,
  /* .CoreAssignment = */ 0
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsr_1 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer_Core0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer_Core0 =
{
  /* .Level          = */ 23,
  /* .Source         = */ 0x490uL,
  /* .CoreAssignment = */ 0
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer_Core0 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: GTMTIM2SR7_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTIM2SR7_ISR =
{
  /* .Level          = */ 9,
  /* .Source         = */ 0x17e8uL,
  /* .CoreAssignment = */ 0
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_GTMTIM2SR7_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: XSignalIsr_OsCore0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore0 =
{
  /* .Level          = */ 22,
  /* .Source         = */ 0x1000uL,
  /* .CoreAssignment = */ 0
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_XSignalIsr_OsCore0 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore0 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore0 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore0,
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CounterIsr_SystemTimer_Core1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer_Core1 =
{
  /* .Level          = */ 24,
  /* .Source         = */ 0x498uL,
  /* .CoreAssignment = */ 1
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer_Core1 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: XSignalIsr_OsCore1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore1 =
{
  /* .Level          = */ 34,
  /* .Source         = */ 0x1020uL,
  /* .CoreAssignment = */ 1
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_XSignalIsr_OsCore1 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore1 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore1 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore1,
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CounterIsr_SystemTimer_Core2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer_Core2 =
{
  /* .Level          = */ 55,
  /* .Source         = */ 0x4a0uL,
  /* .CoreAssignment = */ 2
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer_Core2 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: XSignalIsr_OsCore2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore2 =
{
  /* .Level          = */ 44,
  /* .Source         = */ 0x1040uL,
  /* .CoreAssignment = */ 2
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_XSignalIsr_OsCore2 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore2 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore2 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore2,
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
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
