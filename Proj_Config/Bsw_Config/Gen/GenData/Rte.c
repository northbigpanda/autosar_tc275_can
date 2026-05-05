/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte.c
 *           Config:  TC27x.dpa
 *      ECU-Project:  TC27x
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_AppButtonCtrl.h"
#include "Rte_AppComRx.h"
#include "Rte_AppComTx.h"
#include "Rte_AppCtrl.h"
#include "Rte_AppCtrl1.h"
#include "Rte_AppCtrl2.h"
#include "Rte_AppLedCtrl.h"
#include "Rte_AppWakeUpCtrl.h"
#include "Rte_BswM.h"
#include "Rte_ComM.h"
#include "Rte_Dcm.h"
#include "Rte_DemMaster_0.h"
#include "Rte_DemSatellite_0.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_IcuCdd.h"
#include "Rte_IoHwAb.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_Os_OsCore1_swc.h"
#include "Rte_Os_OsCore2_swc.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_CanTp.h"
#include "SchM_CanTrcv_30_Tja1043.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_EcuM.h"
#include "SchM_Icu_17_GtmCcu6.h"
#include "SchM_IoHwAb.h"
#include "SchM_Irq.h"
#include "SchM_Mcu.h"
#include "SchM_Nm.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */
volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_StartTiming_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408, 1514 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408, MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_1 = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_2 = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x110, RTE_CONST) Rte_C_SG_Sig_Grp_0x110_0 = {
  FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x111, RTE_CONST) Rte_C_SG_Sig_Grp_0x111_0 = {
  FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x112, RTE_CONST) Rte_C_SG_Sig_Grp_0x112_0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x113, RTE_CONST) Rte_C_SG_Sig_Grp_0x113_0 = {
  20U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x114, RTE_CONST) Rte_C_SG_Sig_Grp_0x114_0 = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x400, RTE_CONST) Rte_C_SG_Sig_Grp_0x400_0 = {
  0U, 0U, 0U, TRUE, TRUE, TRUE, TRUE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x401, RTE_CONST) Rte_C_SG_Sig_Grp_0x401_0 = {
  FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x402, RTE_CONST) Rte_C_SG_Sig_Grp_0x402_0 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SG_Sig_Grp_0x403, RTE_CONST) Rte_C_SG_Sig_Grp_0x403_0 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num);

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer_Core0
# define RTE_USEC_SystemTimer_Core0 OS_US2TICKS_SystemTimer_Core0
#else
# define RTE_USEC_SystemTimer_Core0(val) ((TickType)RTE_CONST_USEC_SystemTimer_Core0_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer_Core0
# define RTE_MSEC_SystemTimer_Core0 OS_MS2TICKS_SystemTimer_Core0
#else
# define RTE_MSEC_SystemTimer_Core0(val) ((TickType)RTE_CONST_MSEC_SystemTimer_Core0_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer_Core0
# define RTE_SEC_SystemTimer_Core0 OS_SEC2TICKS_SystemTimer_Core0
#else
# define RTE_SEC_SystemTimer_Core0(val)  ((TickType)RTE_CONST_SEC_SystemTimer_Core0_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer_Core1
# define RTE_USEC_SystemTimer_Core1 OS_US2TICKS_SystemTimer_Core1
#else
# define RTE_USEC_SystemTimer_Core1(val) ((TickType)RTE_CONST_USEC_SystemTimer_Core1_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer_Core1
# define RTE_MSEC_SystemTimer_Core1 OS_MS2TICKS_SystemTimer_Core1
#else
# define RTE_MSEC_SystemTimer_Core1(val) ((TickType)RTE_CONST_MSEC_SystemTimer_Core1_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer_Core1
# define RTE_SEC_SystemTimer_Core1 OS_SEC2TICKS_SystemTimer_Core1
#else
# define RTE_SEC_SystemTimer_Core1(val)  ((TickType)RTE_CONST_SEC_SystemTimer_Core1_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer_Core2
# define RTE_USEC_SystemTimer_Core2 OS_US2TICKS_SystemTimer_Core2
#else
# define RTE_USEC_SystemTimer_Core2(val) ((TickType)RTE_CONST_USEC_SystemTimer_Core2_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer_Core2
# define RTE_MSEC_SystemTimer_Core2 OS_MS2TICKS_SystemTimer_Core2
#else
# define RTE_MSEC_SystemTimer_Core2(val) ((TickType)RTE_CONST_MSEC_SystemTimer_Core2_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer_Core2
# define RTE_SEC_SystemTimer_Core2 OS_SEC2TICKS_SystemTimer_Core2
#else
# define RTE_SEC_SystemTimer_Core2(val)  ((TickType)RTE_CONST_SEC_SystemTimer_Core2_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_Core0_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_Core1_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_Core2_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_Core0_10 (10UL)
#define RTE_CONST_MSEC_SystemTimer_Core1_10 (10UL)
#define RTE_CONST_MSEC_SystemTimer_Core2_10 (10UL)
#define RTE_CONST_MSEC_SystemTimer_Core0_5 (5UL)
#define RTE_CONST_MSEC_SystemTimer_Core1_5 (5UL)
#define RTE_CONST_MSEC_SystemTimer_Core2_5 (5UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))ptr; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(void, RTE_CODE) SchM_Init(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* activate the tasks */
    (void)ActivateTask(OsTask_Bsw5ms_Core0); /* PRQA S 3417 */ /* MD_Rte_Os */

    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE2_OsTask_Bsw5ms_Core0_0_5ms, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(5)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_SCHM_INIT;
  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* activate the tasks */
    (void)ActivateTask(OsTask_App10ms_Core1); /* PRQA S 3417 */ /* MD_Rte_Os */

    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE2_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer_Core1(0) + (TickType)1, RTE_MSEC_SystemTimer_Core1(5)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_1 = RTE_STATE_SCHM_INIT;
  }
  if (id == OS_CORE_ID_2) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* activate the tasks */
    (void)ActivateTask(OsTask_App10ms_Core2); /* PRQA S 3417 */ /* MD_Rte_Os */

    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE2_OsTask_App10ms_Core2_0_5ms, RTE_MSEC_SystemTimer_Core2(0) + (TickType)1, RTE_MSEC_SystemTimer_Core2(5)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_2 = RTE_STATE_SCHM_INIT;
  }
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* activate the tasks */
    (void)ActivateTask(OsTask_App10ms_Core0); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ActivateTask(OsTask_App_Init_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE_AppCtrl2_AppCtrl2_MainFunction, RTE_MSEC_SystemTimer_Core2(0) + (TickType)1, RTE_MSEC_SystemTimer_Core2(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_AppCtrl1_AppCtrl1_MainFuntion, RTE_MSEC_SystemTimer_Core1(0) + (TickType)1, RTE_MSEC_SystemTimer_Core1(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_OsTask_App10ms_Core0_0_10ms, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_IoHwAb_IoHwAb_IoHwAbRunnable, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(5)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

    Rte_StartTiming_InitState = RTE_STATE_INIT;
    Rte_InitState = RTE_STATE_INIT;

  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState_1 = RTE_STATE_INIT;

  }
  if (id == OS_CORE_ID_2) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState_2 = RTE_STATE_INIT;

  }
  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_StartTiming_InitState = RTE_STATE_UNINIT;
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE_OsTask_App10ms_Core0_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_AppCtrl1_AppCtrl1_MainFuntion); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_AppCtrl2_AppCtrl2_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_IoHwAb_IoHwAb_IoHwAbRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_SCHM_INIT;

  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState_1 = RTE_STATE_SCHM_INIT;

  }
  if (id == OS_CORE_ID_2) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState_2 = RTE_STATE_SCHM_INIT;

  }
  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_OsTask_Bsw5ms_Core0_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_UNINIT;
  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_1 = RTE_STATE_UNINIT;
  }
  if (id == OS_CORE_ID_2) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_OsTask_App10ms_Core2_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_2 = RTE_STATE_UNINIT;
  }
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  uint32 id;
  id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState = RTE_STATE_UNINIT;
    Rte_StartTiming_InitState = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore0();
  }
  else if (id == OS_CORE_ID_1) /* PRQA S 2004, 1843 */ /* MD_MSR_EmptyClause, MD_Rte_Os */
  {
    Rte_InitState_1 = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore1();
  }
  else if (id == OS_CORE_ID_2) /* PRQA S 2004, 1843 */ /* MD_MSR_EmptyClause, MD_Rte_Os */
  {
    Rte_InitState_2 = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore2();
  }
}


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_Ccu6IenUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_Ccu6IenUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_CcuInterruptHandle(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_CcuInterruptHandle(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_CcuVariableupdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_CcuVariableupdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_EnableNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_EnableNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_EnableWakeup(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_EnableWakeup(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_ResetEdgeCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_ResetEdgeCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}



/**********************************************************************************************************************
 * COM-Callbacks for DataReceivedEvent triggered runnables, inter-ECU client/server communication, for queued com. and for Rx timeout / Rx inv. flag (reset)
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_Sender = !Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400; /* PRQA S 4404, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0316:  MISRA rule: Dir1.1
     Reason:     Pointer cast to uint8* because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_1533:  MISRA rule: Rule8.9
     Reason:     Object is referenced by more than one function in different configurations.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
