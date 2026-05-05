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
 *              File: Os_Barrier_Lcfg.c
 *   Generation Time: 2024-01-10 07:48:04
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_BARRIER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Barrier_Lcfg.h"
#include "Os_Barrier.h"

/* Os kernel module dependencies */
#include "Os_Common.h"

/* Os hal dependencies */
#include "Os_Hal_Kernel_Lcfg.h"


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

#define OS_START_SEC_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic barrier data: OsCore0 */
OS_LOCAL VAR(Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsCore0_Dyn;

#define OS_STOP_SEC_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_BARRIER_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic barrier data: OsCore1 */
OS_LOCAL VAR(Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsCore1_Dyn;

#define OS_STOP_SEC_BARRIER_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_BARRIER_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic barrier data: OsCore2 */
OS_LOCAL VAR(Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsCore2_Dyn;

#define OS_STOP_SEC_BARRIER_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Core barrier attendee references. */
OS_LOCAL CONST(Os_BarrierAttendeeRefType, OS_CONST) OsCfg_Barrier_AttendeeRefs[OS_COREASRCOREIDX_COUNT] =
{
  &OsCfg_Barrier_OsCore0,
  &OsCfg_Barrier_OsCore1,
  &OsCfg_Barrier_OsCore2
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Barrier configuration data: OsCore0 */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsCore0 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsCore0_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_AttendeeRefs,
  /* .AttendeeCount = */ (Os_BarrierAttendeeIdxType)OS_COREASRCOREIDX_COUNT,
  /* .TaskPtr       = */ NULL_PTR
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Barrier configuration data: OsCore1 */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsCore1 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsCore1_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_AttendeeRefs,
  /* .AttendeeCount = */ (Os_BarrierAttendeeIdxType)OS_COREASRCOREIDX_COUNT,
  /* .TaskPtr       = */ NULL_PTR
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Barrier configuration data: OsCore2 */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsCore2 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsCore2_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_AttendeeRefs,
  /* .AttendeeCount = */ (Os_BarrierAttendeeIdxType)OS_COREASRCOREIDX_COUNT,
  /* .TaskPtr       = */ NULL_PTR
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
 *  END OF FILE: Os_Barrier_Lcfg.c
 *********************************************************************************************************************/
