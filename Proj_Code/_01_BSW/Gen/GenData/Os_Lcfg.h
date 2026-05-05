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
 *              File: Os_Lcfg.h
 *   Generation Time: 2024-02-03 23:46:01
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CODE) Os_Task_Default_Init_Task(void);

# define OS_STOP_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Default_Init_Task_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task_Core1()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CORE1_CODE) Os_Task_Default_Init_Task_Core1(void);

# define OS_STOP_SEC_Default_Init_Task_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Default_Init_Task_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task_Core2()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CORE2_CODE) Os_Task_Default_Init_Task_Core2(void);

# define OS_STOP_SEC_Default_Init_Task_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_App10ms_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_App10ms_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APP10MS_CORE0_CODE) Os_Task_OsTask_App10ms_Core0(void);

# define OS_STOP_SEC_OsTask_App10ms_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_App10ms_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_App10ms_Core1()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APP10MS_CORE1_CODE) Os_Task_OsTask_App10ms_Core1(void);

# define OS_STOP_SEC_OsTask_App10ms_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_App10ms_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_App10ms_Core2()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APP10MS_CORE2_CODE) Os_Task_OsTask_App10ms_Core2(void);

# define OS_STOP_SEC_OsTask_App10ms_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_App_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_App_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APP_INIT_TASK_CODE) Os_Task_OsTask_App_Init_Task(void);

# define OS_STOP_SEC_OsTask_App_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_Bsw5ms_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_Bsw5ms_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_BSW5MS_CORE0_CODE) Os_Task_OsTask_Bsw5ms_Core0(void);

# define OS_STOP_SEC_OsTask_Bsw5ms_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_1()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_1_CODE) Os_Isr_CanIsr_1(void);

# define OS_STOP_SEC_CanIsr_1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMTIM2SR7_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMTIM2SR7_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMTIM2SR7_ISR_CODE) Os_Isr_GTMTIM2SR7_ISR(void);

# define OS_STOP_SEC_GTMTIM2SR7_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
