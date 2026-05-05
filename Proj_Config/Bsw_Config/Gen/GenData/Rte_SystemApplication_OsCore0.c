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
 *             File:  Rte_SystemApplication_OsCore0.c
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
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x111, RTE_VAR_INIT) Rte_AppButtonCtrl_SG_Sig_Grp_0x111_SR_S_SG_Sig_Grp_0x111 = {
  FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x400, RTE_VAR_INIT) Rte_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400 = {
  0U, 0U, 0U, TRUE, TRUE, TRUE, TRUE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x401, RTE_VAR_INIT) Rte_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401 = {
  FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x402, RTE_VAR_INIT) Rte_AppComRx_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x403, RTE_VAR_INIT) Rte_AppComRx_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x112, RTE_VAR_INIT) Rte_AppCtrl_SG_Sig_Grp_0x112_SR_R_SG_Sig_Grp_0x112 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x113, RTE_VAR_INIT) Rte_AppCtrl_SG_Sig_Grp_0x113_SR_R_SG_Sig_Grp_0x113 = {
  20U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x114, RTE_VAR_INIT) Rte_AppCtrl_SG_Sig_Grp_0x114_SR_R_SG_Sig_Grp_0x114 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x115, RTE_VAR_INIT) Rte_AppCtrl_SG_Sig_Grp_0x115_SR_R_SG_Sig_Grp_0x115 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SG_Sig_Grp_0x110, RTE_VAR_INIT) Rte_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110 = {
  FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ComM_ModeType, RTE_VAR_INIT) Rte_AppWakeUpCtrl_App_ComM_Mode_Request_Request_Mode = 0U;
/* PRQA L:L1 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/


#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_SystemApplication_OsCore0_AckFlagsType, RTE_VAR_INIT) Rte_SystemApplication_OsCore0_AckFlags = {
  1,
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_SystemApplication_OsCore0_AckFlagsInit() (Rte_MemClr(&Rte_SystemApplication_OsCore0_AckFlags, sizeof(Rte_SystemApplication_OsCore0_AckFlagsType)))
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Update Flags for each Receiver with enableUpdate != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_SystemApplication_OsCore0_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_SystemApplication_OsCore0_RxUpdateFlags = {
  0U,
  0U
};

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_SystemApplication_OsCore0_RxUpdateFlagsInit() (Rte_MemClr(&Rte_SystemApplication_OsCore0_RxUpdateFlags, sizeof(Rte_SystemApplication_OsCore0_RxUpdateFlagsType)))

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num);

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(BswM_ESH_Mode, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_BswM_ESH_Mode_STARTUP; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
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


FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore0(void)
{
  /* initialize flags for update handling */
  Rte_SystemApplication_OsCore0_RxUpdateFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* set default values for internal data */
  Rte_AppButtonCtrl_SG_Sig_Grp_0x111_SR_S_SG_Sig_Grp_0x111 = Rte_C_SG_Sig_Grp_0x111_0;
  Rte_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400 = Rte_C_SG_Sig_Grp_0x400_0;
  Rte_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401 = Rte_C_SG_Sig_Grp_0x401_0;
  Rte_AppComRx_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402 = Rte_C_SG_Sig_Grp_0x402_0;
  Rte_AppComRx_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403 = Rte_C_SG_Sig_Grp_0x403_0;
  Rte_AppCtrl_SG_Sig_Grp_0x112_SR_R_SG_Sig_Grp_0x112 = Rte_C_SG_Sig_Grp_0x112_0;
  Rte_AppCtrl_SG_Sig_Grp_0x113_SR_R_SG_Sig_Grp_0x113 = Rte_C_SG_Sig_Grp_0x113_0;
  Rte_AppCtrl_SG_Sig_Grp_0x114_SR_R_SG_Sig_Grp_0x114 = Rte_C_SG_Sig_Grp_0x114_0;
  Rte_AppCtrl_SG_Sig_Grp_0x115_SR_R_SG_Sig_Grp_0x115 = Rte_C_SG_Sig_Grp_0x115_0;
  Rte_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110 = Rte_C_SG_Sig_Grp_0x110_0;
  Rte_AppWakeUpCtrl_App_ComM_Mode_Request_Request_Mode = 0U;

  /* reset Tx Ack Flags */
  Rte_SystemApplication_OsCore0_AckFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode_Ack = 1U;

  /* mode management initialization part 1 */

  Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_BswM_ESH_Mode_STARTUP;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppButtonCtrl_SG_Sig_Grp_0x111_SR_S_SG_Sig_Grp_0x111(P2CONST(SG_Sig_Grp_0x111, AUTOMATIC, RTE_APPBUTTONCTRL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppButtonCtrl_SG_Sig_Grp_0x111_SR_S_SG_Sig_Grp_0x111 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400(P2CONST(SG_Sig_Grp_0x400, AUTOMATIC, RTE_APPCOMRX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401(P2CONST(SG_Sig_Grp_0x401, AUTOMATIC, RTE_APPCOMRX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComRx_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402(P2CONST(SG_Sig_Grp_0x402, AUTOMATIC, RTE_APPCOMRX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppComRx_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComRx_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403(P2CONST(SG_Sig_Grp_0x403, AUTOMATIC, RTE_APPCOMRX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppComRx_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComTx_SG_Sig_Grp_0x110_SG_Sig_Grp_0x110(P2CONST(SG_Sig_Grp_0x110, AUTOMATIC, RTE_APPCOMTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Com_SendSignal(ComConf_ComGroupSignal_Led1_State_oSupA_Led_State_oDBCNetWork_987486a5_Tx, &(*(data)).Led1_State); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Led2_State_oSupA_Led_State_oDBCNetWork_13a7b8bc_Tx, &(*(data)).Led2_State); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Led3_State_oSupA_Led_State_oDBCNetWork_dc39af74_Tx, &(*(data)).Led3_State); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Led4_State_oSupA_Led_State_oDBCNetWork_df70c2cf_Tx, &(*(data)).Led4_State); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComTx_SG_Sig_Grp_0x111_SG_Sig_Grp_0x111(P2CONST(SG_Sig_Grp_0x111, AUTOMATIC, RTE_APPCOMTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Com_SendSignal(ComConf_ComGroupSignal_Button1_State_oSupA_Button_State_oDBCNetWork_f13c0622_Tx, &(*(data)).Button1_State); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Button2_State_oSupA_Button_State_oDBCNetWork_bcd40645_Tx, &(*(data)).Button2_State); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Button3_State_oSupA_Button_State_oDBCNetWork_315cfba7_Tx, &(*(data)).Button3_State); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Button4_State_oSupA_Button_State_oDBCNetWork_2704068b_Tx, &(*(data)).Button4_State); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComTx_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112(P2CONST(SG_Sig_Grp_0x112, AUTOMATIC, RTE_APPCOMTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Com_SendSignal(ComConf_ComGroupSignal_PowerMode_oSupA_PowerMode_oDBCNetWork_c3b722c7_Tx, &(*(data)).PowerMode); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_SupA_Checksum_0x112_oSupA_PowerMode_oDBCNetWork_3f776c50_Tx, &(*(data)).SupA_Checksum_0x112); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_SupA_Counter_0x112_oSupA_PowerMode_oDBCNetWork_5e5c6751_Tx, &(*(data)).SupA_Counter_0x112); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComTx_SG_Sig_Grp_0x113_SG_Sig_Grp_0x113(P2CONST(SG_Sig_Grp_0x113, AUTOMATIC, RTE_APPCOMTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Com_SendSignal(ComConf_ComGroupSignal_AAA_Angle_oSupA_Angle_oDBCNetWork_1adb3bf0_Tx, &(*(data)).AAA_Angle); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x113_oSupA_Angle_oDBCNetWork_c5c2558a_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComTx_SG_Sig_Grp_0x114_SG_Sig_Grp_0x114(P2CONST(SG_Sig_Grp_0x114, AUTOMATIC, RTE_APPCOMTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x114_Used_1_oSupA_Function_1_oDBCNetWork_6c3a7273_Tx, &(*(data)).Sig_0x114_Used_1); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x114_Used_2_oSupA_Function_1_oDBCNetWork_289b576b_Tx, &(*(data)).Sig_0x114_Used_2); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x114_Used_3_oSupA_Function_1_oDBCNetWork_14fbb463_Tx, &(*(data)).Sig_0x114_Used_3); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x114_Used_4_oSupA_Function_1_oDBCNetWork_a1d91d5b_Tx, &(*(data)).Sig_0x114_Used_4); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x114_Used_5_oSupA_Function_1_oDBCNetWork_9db9fe53_Tx, &(*(data)).Sig_0x114_Used_5); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComTx_SG_Sig_Grp_0x115_SG_Sig_Grp_0x115(P2CONST(SG_Sig_Grp_0x115, AUTOMATIC, RTE_APPCOMTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x115_Used_1_oSupA_Function_2_oDBCNetWork_510009a2_Tx, &(*(data)).Sig_0x115_Used_1); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x115_Used_2_oSupA_Function_2_oDBCNetWork_15a12cba_Tx, &(*(data)).Sig_0x115_Used_2); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x115_Used_3_oSupA_Function_2_oDBCNetWork_29c1cfb2_Tx, &(*(data)).Sig_0x115_Used_3); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x115_Used_4_oSupA_Function_2_oDBCNetWork_9ce3668a_Tx, &(*(data)).Sig_0x115_Used_4); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignal(ComConf_ComGroupSignal_Sig_0x115_Used_5_oSupA_Function_2_oDBCNetWork_a0838582_Tx, &(*(data)).Sig_0x115_Used_5); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_MSR_RetVal */
  ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x115_oSupA_Function_2_oDBCNetWork_7faaf093_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppCtrl_SG_Sig_Grp_0x112_SR_R_SG_Sig_Grp_0x112(P2CONST(SG_Sig_Grp_0x112, AUTOMATIC, RTE_APPCTRL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppCtrl_SG_Sig_Grp_0x112_SR_R_SG_Sig_Grp_0x112 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppCtrl_SG_Sig_Grp_0x113_SR_R_SG_Sig_Grp_0x113(P2CONST(SG_Sig_Grp_0x113, AUTOMATIC, RTE_APPCTRL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppCtrl_SG_Sig_Grp_0x113_SR_R_SG_Sig_Grp_0x113 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppCtrl_SG_Sig_Grp_0x114_SR_R_SG_Sig_Grp_0x114(P2CONST(SG_Sig_Grp_0x114, AUTOMATIC, RTE_APPCTRL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppCtrl_SG_Sig_Grp_0x114_SR_R_SG_Sig_Grp_0x114 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppCtrl_SG_Sig_Grp_0x115_SR_R_SG_Sig_Grp_0x115(P2CONST(SG_Sig_Grp_0x115, AUTOMATIC, RTE_APPCTRL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppCtrl_SG_Sig_Grp_0x115_SR_R_SG_Sig_Grp_0x115 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110(P2CONST(SG_Sig_Grp_0x110, AUTOMATIC, RTE_APPLEDCTRL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppButtonCtrl_SG_Sig_Grp_0x401_SR_R_SG_Sig_Grp_0x401(P2VAR(SG_Sig_Grp_0x401, AUTOMATIC, RTE_APPBUTTONCTRL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400(P2VAR(SG_Sig_Grp_0x400, AUTOMATIC, RTE_APPCOMRX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx); /* PRQA S 3453, 0315 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_CrcSig_Pack_0_oSupB_Led_Control_oDBCNetWork_ecfc9a83_Rx, &(*(data)).CrcSig_Pack_0); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_CrcSig_Pack_1_oSupB_Led_Control_oDBCNetWork_e21b7252_Rx, &(*(data)).CrcSig_Pack_1); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_CrcSig_Pack_2_oSupB_Led_Control_oDBCNetWork_f1334b21_Rx, &(*(data)).CrcSig_Pack_2); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Led1_Control_oSupB_Led_Control_oDBCNetWork_48297120_Rx, &(*(data)).Led1_Control); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Led2_Control_oSupB_Led_Control_oDBCNetWork_9bb26ddb_Rx, &(*(data)).Led2_Control); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Led3_Control_oSupB_Led_Control_oDBCNetWork_d53b6672_Rx, &(*(data)).Led3_Control); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Led4_Control_oSupB_Led_Control_oDBCNetWork_e7f5526c_Rx, &(*(data)).Led4_Control); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SupB_Checksum_0x400_oSupB_Led_Control_oDBCNetWork_1c8bf5dc_Rx, &(*(data)).SupB_Checksum_0x400); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SupB_Counter_0x400_oSupB_Led_Control_oDBCNetWork_2dd3ae1e_Rx, &(*(data)).SupB_Counter_0x400); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 = Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComRx_SG_Sig_Grp_0x401_SG_Sig_Grp_0x401(P2VAR(SG_Sig_Grp_0x401, AUTOMATIC, RTE_APPCOMRX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx); /* PRQA S 3453, 0315 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Button1_Control_oSupB_Button_Control_oDBCNetWork_cbcdfbc4_Rx, &(*(data)).Button1_Control); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Button2_Control_oSupB_Button_Control_oDBCNetWork_f3f670b7_Rx, &(*(data)).Button2_Control); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Button3_Control_oSupB_Button_Control_oDBCNetWork_52cff459_Rx, &(*(data)).Button3_Control); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Button4_Control_oSupB_Button_Control_oDBCNetWork_83816651_Rx, &(*(data)).Button4_Control); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComRx_SG_Sig_Grp_0x402_SG_Sig_Grp_0x402(P2VAR(SG_Sig_Grp_0x402, AUTOMATIC, RTE_APPCOMRX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx); /* PRQA S 3453, 0315 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x402_Used_1_oSupC_Function_1_oDBCNetWork_23971e12_Rx, &(*(data)).Sig_0x402_Used_1); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x402_Used_2_oSupC_Function_1_oDBCNetWork_67363b0a_Rx, &(*(data)).Sig_0x402_Used_2); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x402_Used_3_oSupC_Function_1_oDBCNetWork_5b56d802_Rx, &(*(data)).Sig_0x402_Used_3); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x402_Used_4_oSupC_Function_1_oDBCNetWork_ee74713a_Rx, &(*(data)).Sig_0x402_Used_4); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x402_Used_5_oSupC_Function_1_oDBCNetWork_d2149232_Rx, &(*(data)).Sig_0x402_Used_5); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComRx_SG_Sig_Grp_0x403_SG_Sig_Grp_0x403(P2VAR(SG_Sig_Grp_0x403, AUTOMATIC, RTE_APPCOMRX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx); /* PRQA S 3453, 0315 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x403_Used_1_oSupC_Function_2_oDBCNetWork_1ead65c3_Rx, &(*(data)).Sig_0x403_Used_1); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x403_Used_2_oSupC_Function_2_oDBCNetWork_5a0c40db_Rx, &(*(data)).Sig_0x403_Used_2); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x403_Used_3_oSupC_Function_2_oDBCNetWork_666ca3d3_Rx, &(*(data)).Sig_0x403_Used_3); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x403_Used_4_oSupC_Function_2_oDBCNetWork_d34e0aeb_Rx, &(*(data)).Sig_0x403_Used_4); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Sig_0x403_Used_5_oSupC_Function_2_oDBCNetWork_ef2ee9e3_Rx, &(*(data)).Sig_0x403_Used_5); /* PRQA S 3453, 0315, 2986 */ /* MD_MSR_FctLikeMacro, MD_Rte_0315, MD_MSR_RetVal */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComTx_SG_Sig_Grp_0x110_SR_R_SG_Sig_Grp_0x110(P2VAR(SG_Sig_Grp_0x110, AUTOMATIC, RTE_APPCOMTX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComTx_SG_Sig_Grp_0x111_SR_R_SG_Sig_Grp_0x111(P2VAR(SG_Sig_Grp_0x111, AUTOMATIC, RTE_APPCOMTX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppButtonCtrl_SG_Sig_Grp_0x111_SR_S_SG_Sig_Grp_0x111; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComTx_SG_Sig_Grp_0x112_SR_R_SG_Sig_Grp_0x112(P2VAR(SG_Sig_Grp_0x112, AUTOMATIC, RTE_APPCOMTX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppCtrl_SG_Sig_Grp_0x112_SR_R_SG_Sig_Grp_0x112; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComTx_SG_Sig_Grp_0x113_SR_R_SG_Sig_Grp_0x113(P2VAR(SG_Sig_Grp_0x113, AUTOMATIC, RTE_APPCOMTX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppCtrl_SG_Sig_Grp_0x113_SR_R_SG_Sig_Grp_0x113; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComTx_SG_Sig_Grp_0x114_SR_R_SG_Sig_Grp_0x114(P2VAR(SG_Sig_Grp_0x114, AUTOMATIC, RTE_APPCOMTX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppCtrl_SG_Sig_Grp_0x114_SR_R_SG_Sig_Grp_0x114; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComTx_SG_Sig_Grp_0x115_SR_R_SG_Sig_Grp_0x115(P2VAR(SG_Sig_Grp_0x115, AUTOMATIC, RTE_APPCOMTX_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppCtrl_SG_Sig_Grp_0x115_SR_R_SG_Sig_Grp_0x115; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppCtrl_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400(P2VAR(SG_Sig_Grp_0x400, AUTOMATIC, RTE_APPCTRL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppCtrl_SG_Sig_Grp_0x401_SR_R_SG_Sig_Grp_0x401(P2VAR(SG_Sig_Grp_0x401, AUTOMATIC, RTE_APPCTRL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppCtrl_SG_Sig_Grp_0x402_SR_R_SG_Sig_Grp_0x402(P2VAR(SG_Sig_Grp_0x402, AUTOMATIC, RTE_APPCTRL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppComRx_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppCtrl_SG_Sig_Grp_0x403_SR_R_SG_Sig_Grp_0x403(P2VAR(SG_Sig_Grp_0x403, AUTOMATIC, RTE_APPCTRL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppComRx_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppLedCtrl_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400(P2VAR(SG_Sig_Grp_0x400, AUTOMATIC, RTE_APPLEDCTRL_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ModeReq_App_ComM_Mode_Request_Request_Mode(P2VAR(ComM_ModeType, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 3673, 1505, 3206 */ /* MD_Rte_Qac, MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_AppWakeUpCtrl_App_ComM_Mode_Request_Request_Mode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Braking_Brake_Pedal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus;
  ErrorCode = ErrorCode;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_Braking_Brake_Pedal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus;
  Data = Data;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_ECU_Check_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ECU_Check_status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus;
  Out_ECU_Check_status = Out_ECU_Check_status;
  ErrorCode = ErrorCode;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_ECU_Check_Start(uint8 In_Start_ECU_Check, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ECU_Check_is_in_progress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  In_Start_ECU_Check = In_Start_ECU_Check;
  OpStatus = OpStatus;
  Out_ECU_Check_is_in_progress = Out_ECU_Check_is_in_progress;
  ErrorCode = ErrorCode;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_DTC_0x402011_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  FaultDetectionCounter = FaultDetectionCounter;

  return ret;
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  BswM_ESH_Mode currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  if (nextMode >= 5U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (currentMode >= 5U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(BswM_ESH_Mode, RTE_CODE) Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  BswM_ESH_Mode curMode;
  curMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  return curMode;
}


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void)
{

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_DBCNetWork_9ed72b09_DcmCommunicationControl_ComMConf_ComMChannel_CN_DBCNetWork_9ed72b09(Dcm_CommunicationModeType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode;

  return ret;
}


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     OsTask_App10ms_Core0
 * Priority: 34
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_App10ms_Core0) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_OsTask_App10ms_Core0_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_App10ms_Core0, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_OsTask_App10ms_Core0_0_10ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_OsTask_App10ms_Core0_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      AppCtrl_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      AppComTx_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      AppComRx_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      AppWakeUpCtrl_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      AppButtonCtrl_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      AppLedCtrl_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      IcuCdd_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_App_Init_Task
 * Priority: 50
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_App_Init_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  AppComRx_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  AppComTx_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  AppCtrl_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  AppWakeUpCtrl_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  AppButtonCtrl_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  AppLedCtrl_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  IcuCdd_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_Bsw5ms_Core0
 * Priority: 0
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(OsTask_Bsw5ms_Core0) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_OsTask_Bsw5ms_Core0_0_5ms | Rte_Ev_Run_IoHwAb_IoHwAb_IoHwAbRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_Bsw5ms_Core0, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_OsTask_Bsw5ms_Core0_0_5ms | Rte_Ev_Run_IoHwAb_IoHwAb_IoHwAbRunnable)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_OsTask_Bsw5ms_Core0_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      BswM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_OsTask_Bsw5ms_Core0_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      EcuM_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_OsTask_Bsw5ms_Core0_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanTrcv_30_Tja1043_MainFunction();

      /* call runnable */
      ComM_MainFunction_0(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call schedulable entity */
      Can_MainFunction_Wakeup();

      /* call schedulable entity */
      CanNm_MainFunction();

      /* call schedulable entity */
      CanSM_MainFunction();

      /* call schedulable entity */
      CanTp_MainFunction();

      /* call schedulable entity */
      Com_MainFunctionRx();

      /* call schedulable entity */
      Com_MainFunctionTx();

      /* call runnable */
      Dcm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Dem_MasterMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Dem_SatelliteMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_IoHwAb_IoHwAb_IoHwAbRunnable) != (EventMaskType)0)
    {
      /* call runnable */
      IoHwAb_IoHwAbRunnable(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1339:  MISRA rule: Rule17.8
     Reason:     Passing elements by pointer is a well known concept.
     Risk:       No functional risk. Data flow is handled with care.
     Prevention: Not required.

   MD_Rte_1340:  MISRA rule: Rule17.8
     Reason:     Passing elements by pointer is a well known concept.
     Risk:       No functional risk. Data flow is handled with care.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2982:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
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

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
