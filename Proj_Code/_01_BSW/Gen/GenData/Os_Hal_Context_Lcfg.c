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
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2024-02-03 23:56:52
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic task context data: Default_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: OsTask_App10ms_Core0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_App10ms_Core0_Dyn;

/*! HAL dynamic task context data: OsTask_App_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_App_Init_Task_Dyn;

/*! HAL dynamic task context data: OsTask_Bsw5ms_Core0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Bsw5ms_Core0_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore1_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore1_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_Isr_Level2_Dyn;

/*! HAL dynamic task context data: Default_Init_Task_Core1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Core1_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore1_Dyn;

/*! HAL dynamic task context data: OsTask_App10ms_Core1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_App10ms_Core1_Dyn;

/*! HAL exception context data: OsCore1 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore1_ExceptionContext;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore2_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore2_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_Isr_Level2_Dyn;

/*! HAL dynamic task context data: Default_Init_Task_Core2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Core2_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore2_Dyn;

/*! HAL dynamic task context data: OsTask_App10ms_Core2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_App10ms_Core2_Dyn;

/*! HAL exception context data: OsCore2 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore2_ExceptionContext;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CanIsr_1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_CanIsr_1,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPfrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: GTMTIM2SR7_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GTMTIM2SR7_ISR =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_GTMTIM2SR7_ISR,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio30_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio30_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_Init_Task,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: OsTask_App10ms_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_App10ms_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_App10ms_Core0_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_App10ms_Core0_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_App10ms_Core0,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: OsTask_App_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_App_Init_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio50_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio50_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_App_Init_Task,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: OsTask_Bsw5ms_Core0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Bsw5ms_Core0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_Bsw5ms_Core0_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_Bsw5ms_Core0_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_Bsw5ms_Core0,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL hook context configuration data: ErrorHook_OsCore1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Error_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Error_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer_Core1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer_Core1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPfrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_Init_Task_Core1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task_Core1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio50_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio50_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_Init_Task_Core1,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: OsTask_App10ms_Core1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_App10ms_Core1 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_App10ms_Core1_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_App10ms_Core1_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_App10ms_Core1,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore1_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore1_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL hook context configuration data: ErrorHook_OsCore2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Error_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Error_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer_Core2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer_Core2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPfrtIsr,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL ISR2 context configuration data: XSignalIsr_OsCore2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_XSignalIsr_OsCore2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Isr_Os_XSigRecvIsrHandler,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)55<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: Default_Init_Task_Core2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task_Core2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Task_Prio50_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Task_Prio50_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Default_Init_Task_Core2,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: IdleTask_OsCore2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Task_Prio4294967295_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL task context configuration data: OsTask_App10ms_Core2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_App10ms_Core2 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_App10ms_Core2_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackStartAddr   = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_App10ms_Core2_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .ProgramStatus    = */ (uint32)OS_HAL_PSW_IS_MASK | OS_HAL_PSW_CDE_MASK | OS_HAL_PSW_IO_SUPERVISOR | OS_HAL_PSW_S_MASK | OS_HAL_PSW_PRS_PS0,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_App10ms_Core2,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */
  /* .IntStatus        = */ ((uint32)0<<OS_HAL_PCXI_PCPN_BIT_POSITION) | OS_HAL_PCXI_PIE_ENABLED
};

/*! HAL kernel stack configuration data: OsCore2_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore2_Kernel =
{
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore2_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore2_Kernel_Dyn)+1)  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
  &OsCfg_Hal_Context_OsCore1_ExceptionContext,
  &OsCfg_Hal_Context_OsCore2_ExceptionContext,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
