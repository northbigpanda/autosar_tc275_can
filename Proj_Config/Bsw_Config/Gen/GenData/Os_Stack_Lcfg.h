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
 *              File: Os_Stack_Lcfg.h
 *   Generation Time: 2024-02-03 23:56:52
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#ifndef OS_STACK_LCFG_H
# define OS_STACK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

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

# define OS_START_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore0_Error */
/* User: [ErrorHook_OsCore0, OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Error_Dyn, OS_CFG_SIZE_OSCORE0_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore0_Init */
/* User: [OsCore0, Os_CoreInitHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Init_Dyn, OS_CFG_SIZE_OSCORE0_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore0_Isr_Core */
/* User: [CanIsr_1, CounterIsr_SystemTimer_Core0, GTMTIM2SR7_ISR, XSignalIsr_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore0_Kernel */
/* User: [OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Kernel_Dyn, OS_CFG_SIZE_OSCORE0_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio30 */
/* User: [Default_Init_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio30_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO30_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio4294967295 */
/* User: [IdleTask_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio50 */
/* User: [OsTask_App_Init_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore1_Error */
/* User: [ErrorHook_OsCore1, OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Error_Dyn, OS_CFG_SIZE_OSCORE1_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore1_Init */
/* User: [OsCore1, Os_CoreInitHook_OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Init_Dyn, OS_CFG_SIZE_OSCORE1_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore1_Isr_Core */
/* User: [CounterIsr_SystemTimer_Core1, XSignalIsr_OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE1_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore1_Kernel */
/* User: [OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Kernel_Dyn, OS_CFG_SIZE_OSCORE1_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio4294967295 */
/* User: [IdleTask_OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio50 */
/* User: [Default_Init_Task_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore2_Error */
/* User: [ErrorHook_OsCore2, OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Error_Dyn, OS_CFG_SIZE_OSCORE2_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore2_Init */
/* User: [OsCore2, Os_CoreInitHook_OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Init_Dyn, OS_CFG_SIZE_OSCORE2_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore2_Isr_Core */
/* User: [CounterIsr_SystemTimer_Core2, XSignalIsr_OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE2_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore2_Kernel */
/* User: [OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Kernel_Dyn, OS_CFG_SIZE_OSCORE2_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore2_Task_Prio4294967295 */
/* User: [IdleTask_OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE2_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore2_Task_Prio50 */
/* User: [Default_Init_Task_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE2_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_App10ms_Core0 */
/* User: [OsTask_App10ms_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_App10ms_Core0_Dyn, OS_CFG_SIZE_OSTASK_APP10MS_CORE0_STACK);

# define OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_App10ms_Core1 */
/* User: [OsTask_App10ms_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_App10ms_Core1_Dyn, OS_CFG_SIZE_OSTASK_APP10MS_CORE1_STACK);

# define OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_App10ms_Core2 */
/* User: [OsTask_App10ms_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_App10ms_Core2_Dyn, OS_CFG_SIZE_OSTASK_APP10MS_CORE2_STACK);

# define OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_Bsw5ms_Core0 */
/* User: [OsTask_Bsw5ms_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_Bsw5ms_Core0_Dyn, OS_CFG_SIZE_OSTASK_BSW5MS_CORE0_STACK);

# define OS_STOP_SEC_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: OsCore0_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Error;

/*! Stack configuration data: OsCore0_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Init;

/*! Stack configuration data: OsCore0_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Core;

/*! Stack configuration data: OsCore0_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Kernel;

/*! Stack configuration data: OsCore0_Task_Prio30 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio30;

/*! Stack configuration data: OsCore0_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio4294967295;

/*! Stack configuration data: OsCore0_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio50;

/*! Stack configuration data: OsTask_App10ms_Core0 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_App10ms_Core0;

/*! Stack configuration data: OsTask_Bsw5ms_Core0 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_Bsw5ms_Core0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: OsCore1_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Error;

/*! Stack configuration data: OsCore1_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Init;

/*! Stack configuration data: OsCore1_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Isr_Core;

/*! Stack configuration data: OsCore1_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Kernel;

/*! Stack configuration data: OsCore1_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio4294967295;

/*! Stack configuration data: OsCore1_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio50;

/*! Stack configuration data: OsTask_App10ms_Core1 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_App10ms_Core1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: OsCore2_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Error;

/*! Stack configuration data: OsCore2_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Init;

/*! Stack configuration data: OsCore2_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Isr_Core;

/*! Stack configuration data: OsCore2_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Kernel;

/*! Stack configuration data: OsCore2_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Task_Prio4294967295;

/*! Stack configuration data: OsCore2_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Task_Prio50;

/*! Stack configuration data: OsTask_App10ms_Core2 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_App10ms_Core2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_STACK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.h
 *********************************************************************************************************************/
