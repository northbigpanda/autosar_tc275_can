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
 *              File: Os_Application_Lcfg.c
 *   Generation Time: 2024-02-05 14:39:15
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_APPLICATION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore1 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore2 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_OsTask_Bsw5ms_Core0_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_IoHwAb_IoHwAb_IoHwAbRunnable),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_OsTask_App10ms_Core0_0_10ms),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_1),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer_Core0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_GTMTIM2SR7_ISR),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore0),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_App10ms_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_App_Init_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Bsw5ms_Core0),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore0 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore0),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_AppCtrl1_AppCtrl1_MainFuntion),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core1),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ISRS + 1u] =
{
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer_Core1),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore1),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Core1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_App10ms_Core1),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore1 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore1_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore1 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore1 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore1_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore1,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore1),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore1_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore1_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore1_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore1_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore1_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore1_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore1_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore1_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore1
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_OsTask_App10ms_Core2_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_AppCtrl2_AppCtrl2_MainFunction),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core2),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ISRS + 1u] =
{
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer_Core2),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore2),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Core2),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore2),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_App10ms_Core2),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore2 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore2_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore2 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore2 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore2_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore2,
  /* .AccessRightId        = */ OS_APPID2MASK((Os_AppAccessMaskType)SystemApplication_OsCore2),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore2_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore2_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore2_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore2_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore2_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore2_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore2_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore2_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore2
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for applications. */
CONSTP2CONST(Os_AppConfigType, OS_CONST, OS_CONST) OsCfg_AppRefs[OS_APPID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  &OsCfg_App_SystemApplication_OsCore0,
  &OsCfg_App_SystemApplication_OsCore1,
  &OsCfg_App_SystemApplication_OsCore2,
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
 *  END OF FILE: Os_Application_Lcfg.c
 *********************************************************************************************************************/
