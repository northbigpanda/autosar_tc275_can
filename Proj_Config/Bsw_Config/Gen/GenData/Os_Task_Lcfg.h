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
 *              File: Os_Task_Lcfg.h
 *   Generation Time: 2024-02-03 23:46:01
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TASK_LCFG_H
# define OS_TASK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Task_Types.h"

/* Os kernel module dependencies */
# include "Os_Ioc_Types.h"
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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task configuration data: Default_Init_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task;

/*! Task configuration data: IdleTask_OsCore0 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore0;

/*! Task configuration data: OsTask_App10ms_Core0 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_App10ms_Core0;

/*! Task configuration data: OsTask_App_Init_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_App_Init_Task;

/*! Task configuration data: OsTask_Bsw5ms_Core0 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Bsw5ms_Core0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task configuration data: Default_Init_Task_Core1 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task_Core1;

/*! Task configuration data: IdleTask_OsCore1 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore1;

/*! Task configuration data: OsTask_App10ms_Core1 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_App10ms_Core1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task configuration data: Default_Init_Task_Core2 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task_Core2;

/*! Task configuration data: IdleTask_OsCore2 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore2;

/*! Task configuration data: OsTask_App10ms_Core2 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_App10ms_Core2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for tasks. */
extern CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TASK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Task_Lcfg.h
 *********************************************************************************************************************/
