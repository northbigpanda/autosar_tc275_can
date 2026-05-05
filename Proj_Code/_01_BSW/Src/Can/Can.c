/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* STARTSINGLE_OF_MULTIPLE */

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*  \file     Can.c / Can_Irq.c / Can_Local.h
 *  \brief    Implementation of the CAN driver
 *  \details  see functional description below
 *
 *********************************************************************************************************************/
/* ***************************************************************************
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Ht           Heike Honert              Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Bir          Holger Birke              Vector Informatik GmbH
| Rna          Ruediger Naas             Vector Informatik GmbH
| Hzo          Han Zhao                  Vector Informatik GmbH
| Bns          Benjamin Schuetterle      Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver   Author  Description
| ---------  ---  ------  ----------------------------------------------------
| Refer to the module's header file.
|************************************************************************** */

/* \trace SPEC-1570 */
/***************************************************************************/
/* Include files                                                           */
/***************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
#define C_DRV_INTERNAL /* compatibility */
#define CAN_SOURCE     /* testability */
#define __CAN_SRC__       /* compatibility RTM not aware of multi driver instance */ /* PRQA S 0602,0603 */ /* MD_Can_ModuleDefine */
#if !defined(__CAN_SRC__) /* driver use ORGANI without infix */ /* COV_CAN_INTERNAL */
# define __CAN_SRC__      /* for all MSR module (used by RTM) */ /* PRQA S 0602,0603 */ /* MD_Can_ModuleDefine */
#endif

/* \trace SPEC-1408, SPEC-1590, SPEC-1588 */
/* \trace SPEC-1392 */
#include "CanIf_Cbk.h"   /* for callback declaration */
/* \trace SPEC-1707 */
#include "CanIf.h"       /* for version check */
#include "Can_Local.h"    /* have to be last include due to channel define will lead to problems */

#if (CAN_DEV_ERROR_REPORT == STD_ON)
/* \trace SPEC-1596 */
# include "Det.h"
#endif

#if !defined(CAN_AMD_RUNTIME_MEASUREMENT) /* COV_CAN_COMPATIBILITY */
# define CAN_AMD_RUNTIME_MEASUREMENT STD_OFF
#endif
#if (CAN_AMD_RUNTIME_MEASUREMENT == STD_ON) /* COV_CAN_AMD_RUNTIME_MEASUREMENT */
# include "AmdRtm.h"
#endif

#if !defined(CAN_RUNTIME_MEASUREMENT_SUPPORT) /* COV_CAN_COMPATIBILITY */
# define CAN_RUNTIME_MEASUREMENT_SUPPORT STD_OFF
#endif
#if (CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)
/* AR4-328 */
# define C_ENABLE_RUNTIME_MEASUREMENT_SUPPORT
# include "Rtm.h"
#endif

#include "vstdlib.h"

/* ECO_IGNORE_BLOCK_END */

/***************************************************************************/
/* Version Check                                                           */
/***************************************************************************/
/* \trace SPEC-20329 */
/* not the SW version but all file versions that represent the SW version are checked */
#if (CAN_COREVERSION           != 0x0800u) /* \trace SPEC-1699 */
# error "Source and Header file are inconsistent!"
#endif
#if (CAN_RELEASE_COREVERSION   != 0x01u)
# error "Source and Header file are inconsistent!"
#endif
#if defined(CAN_GEN_BASE_CFG5_VERSION) /* COV_CAN_COMPATIBILITY */
# if (CAN_GEN_BASE_CFG5_VERSION         != 0x0103u)
#  error "Source and Generated Header file are inconsistent!"
# endif
#else
# error "No CAN_GEN_BASE_CFG5_VERSION is defined"
#endif
#if( DRVCAN_TRICOREMULTICANASR_VERSION != 0x0502u)
# error "Source and Header file are inconsistent!"
#endif
#if( DRVCAN_TRICOREMULTICANASR_RELEASE_VERSION != 0x00u)
# error "Source and Header file are inconsistent!"
#endif

# if( CAN_GEN_TricoreMulticanAsr_VERSION != 0x0101u)
#  error "Generated Data are inconsistent!"
# endif

/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
#if defined(CAN_USE_NO_VECTOR_IF) /* for testability */
# define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#else
# if defined(CANIF_VENDOR_ID) /* COV_CAN_COMPATIBILITY */
#  if (CANIF_VENDOR_ID == 0x001E) /* COV_CAN_COMPATIBILITY */
#   define CAN_USE_VECTOR_IF
#   if defined(IF_ASRIFCAN_VERSION) /* COV_CAN_COMPATIBILITY */
#    if (IF_ASRIFCAN_VERSION < 0x0410) /* COV_CAN_COMPATIBILITY */
#     define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#    endif
#   endif
#  else
#   define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#  endif
# else
#  define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
# endif
#endif
/* Compatibility to CBD */
/* instead of direct canCanInterruptCounter[] use Can_GetCanInterruptCounter(Index) abstraction for ComStackLib */

#if (CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)
# define CanHookBegin_Can_Init()                              Rtm_Start(RtmConf_RtmMeasurementPoint_Can_Init)
# define CanHookEnd_Can_Init()                                Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_Init)
# define CanHookBegin_Can_SetControllerMode()                 Rtm_Start(RtmConf_RtmMeasurementPoint_Can_SetControllerMode)
# define CanHookEnd_Can_SetControllerMode()                   Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_SetControllerMode)
# define CanHookBegin_Can_Write()                             Rtm_Start(RtmConf_RtmMeasurementPoint_Can_Write)
# define CanHookEnd_Can_Write()                               Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_Write)

#else /* BRS runtime measurement */
# define CanHookBegin_Can_Init()
# define CanHookEnd_Can_Init()
# define CanHookBegin_Can_SetControllerMode() \

# define CanHookEnd_Can_SetControllerMode() \

# define CanHookBegin_Can_Write() \

# define CanHookEnd_Can_Write() \

#endif

# define CanHookBegin_CanHL_ReInit() \

# define CanHookEnd_CanHL_ReInit() \

#define CanHookBegin_CanHL_TxConfirmation() \

#define CanHookEnd_CanHL_TxConfirmation() \

#define CanHookBegin_CanHL_BasicCanMsgReceived() \

#define CanHookEnd_CanHL_BasicCanMsgReceived() \

#define CanHookBegin_CanHL_FullCanMsgReceived() \

#define CanHookEnd_CanHL_FullCanMsgReceived() \

#define CanHookBegin_Can_MainFunction_Write() \

#define CanHookEnd_Can_MainFunction_Write() \

#define CanHookBegin_Can_MainFunction_Read() \

#define CanHookEnd_Can_MainFunction_Read() \

/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#define C_MSID_RESET         ((vuint8 )0x0020)   /*!< Message Index Register reset value */
#define C_MSID_INDEX         ((vuint8 )0x003F)   /*!< Message Index Register access mask */

#define C_NCR_RESET          ((vuint16)0x0000)   /*!< Node Control Register reset value */
#define C_NCR_INIT           ((vuint16)0x0001)   /*!< Node Control Register INIT bit */
#define C_NCR_ALIE           ((vuint16)0x0008)   /*!< Node Control Register Alert Interrupt enable bit */
#define C_NCR_CCE            ((vuint16)0x0040)   /*!< Node Control Register Configuration Change enable bit */
#define C_NCR_CALM           ((vuint16)0x0080)   /*!< Node Control Register Can Analyzer Mode enable bit, to set INIT bit required */
#define C_NCR_FDEN           ((vuint16)0x0200)   /*!< Node Control Register FD enable bit, protected by INIT and CCE bit */

#define C_NSR_ALERT          ((vuint16)0x0020)   /*!< Node Status Register Alert Warning flag */
#define C_NSR_EWRN           ((vuint16)0x0040)   /*!< Node Status Register Error Warning Status flag*/
#define C_NSR_BOFF           ((vuint16)0x0080)   /*!< Node Status Register Busoff Status flag*/

#define C_MOCTR_ALL          ((vuint16)0x0FFF)   /*!< Message Object Control/Status Register access mask */
#define C_MOCTR_RXPND        ((vuint16)0x0001)   /*!< Message Object Control/Status Register Rx pending bit */
#define C_MOCTR_TXPND        ((vuint16)0x0002)   /*!< Message Object Control/Status Register Tx pending bit */
#define C_MOCTR_RXUPD        ((vuint16)0x0004)   /*!< Message Object Control/Status Register Rx updating bit */
#define C_MOCTR_NEWDAT       ((vuint16)0x0008)   /*!< Message Object Control/Status Register New Data bit */
#define C_MOCTR_MSGLOST      ((vuint16)0x0010)   /*!< Message Object Control/Status Register Message Lost bit */
#define C_MOCTR_MSGVAL       ((vuint16)0x0020)   /*!< Message Object Control/Status Register Message Valid bit */
#define C_MOCTR_RTSEL        ((vuint16)0x0040)   /*!< Message Object Control/Status Register Rx/Tx Selected bit */
#define C_MOCTR_RXEN         ((vuint16)0x0080)   /*!< Message Object Control/Status Register Rx Enable bit */
#define C_MOCTR_TXREQ        ((vuint16)0x0100)   /*!< Message Object Control/Status Register Tx Request bit */
#define C_MOCTR_TXEN0        ((vuint16)0x0200)   /*!< Message Object Control/Status Register Tx Enable 0 bit */
#define C_MOCTR_TXEN1        ((vuint16)0x0400)   /*!< Message Object Control/Status Register Tx Enable 1 bit */
#define C_MOCTR_DIR          ((vuint16)0x0800)   /*!< Message Object Control/Status Register Message Direction bit */

#define C_MOFCR_MODE_NORMAL  (0x00u)  /*!< Message Object Function Control Register Standard Message Object mask */
#define C_MOFCR_MODE_RXBASE  (0x01u)  /*!< Message Object Function Control Register Rx FIFO Base Object mask */
#define C_MOFCR_MODE_FDBASE  (0x05u)  /*!< Message Object Function Control Register CANFD 64 bytes Message Mode mask */
#define C_MOFCR_IE_RX        (0x01u)  /*!< Message Object Function Control Register Rx Interrupt Enable bit */
#define C_MOFCR_IE_TX        (0x02u)  /*!< Message Object Function Control Register Tx Interrupt Enable bit */
#define C_MOFCR_IE_SDT       (0x40u)  /*!< Message Object Function Control Register Single Data Transfer enable bit */
#define C_MOFCR_DLC          C_DLC_M  /*!< Message Object Function Control Register Data Length Code */

#define C_MOAMR_CLOSE      ((vuint32)0x1FFFFFFFUL) /*!< Message Object Acceptance Mask Register close mask */
#define C_MOAMR_OPEN       ((vuint32)0x00000000UL) /*!< Message Object Acceptance Mask Register open mask */

/* define unused node-priorities (fill table) */
#if !defined( kCanISRPrio_0 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_0 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_1 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_1 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_2 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_2 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_3 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_3 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_4 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_4 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_5 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_5 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_6 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_6 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_7 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_7 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_8 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_8 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_9 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_9 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_10 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_10 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_11 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_11 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_12 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_12 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_13 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_13 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_14 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_14 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRPrio_15 ) /* COV_CAN_kCanISRPrio */
# define kCanISRPrio_15 0x00u  /* unused node - no prio available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_0 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_0 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_1 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_1 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_2 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_2 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_3 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_3 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_4 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_4 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_5 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_5 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_6 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_6 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_7 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_7 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_8 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_8 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_9 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_9 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_10 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_10 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_11 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_11 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_12 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_12 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_13 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_13 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_14 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_14 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
#if !defined( kCanISRGroup_15 ) /* COV_CAN_kCanISRPrio */
# define kCanISRGroup_15 0x00u  /* unused node - no group available (first is always available - see above) */
#endif
/* no compiler abstraction here pointers are always 32 bit and cast does not work for Tasking compiler */
#define CANLL_SRC_OFFSET     (15u)
#if defined ( kCanSRCAdr ) /* Aurix: extern SRC (other layout used) */ /* COV_CAN_AURIX_DERIVATIVE */
# define CAN_SRC_ADR(ch)      &( (V_DEF_P2VAR_PARA(volatile, vuint32, VAR_NOINIT, INT_CTRL)) (kCanSRCAdr) )[Can_GetSrcNum(ch)]   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define CAN_SRC_ADR_RAM(ch)  &( (V_DEF_P2VAR_PARA(volatile, vuint32, VAR_NOINIT, INT_CTRL)) (kCanSRCAdr) )[CanSrcNum_Ram[(ch)]] /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define C_SRC_SRE            (0x00000400UL) /*!< Service Request Control Register Service Request Enable bit */
# define C_SRC_CLRR           (0x02000000UL) /*!< Service Request Control Register Request Clear bit, SRR bit will be cleared */
#else
# define CAN_SRC_ADR(ch)      &( (V_DEF_P2VAR_PARA(volatile, vuint32, VAR_NOINIT, INT_CTRL)) (kCanBaseAdr+ 0xC0u) )[CANLL_SRC_OFFSET-Can_GetSrcNum(ch)]   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define CAN_SRC_ADR_RAM(ch)  &( (V_DEF_P2VAR_PARA(volatile, vuint32, VAR_NOINIT, INT_CTRL)) (kCanBaseAdr+ 0xC0u) )[CANLL_SRC_OFFSET-CanSrcNum_Ram[(ch)]] /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define C_SRC_SRE            (0x00001000UL) /*!< Service Request Control Register Service Request Enable bit */
# define C_SRC_CLRR           (0x00004000UL) /*!< Service Request Control Register Request Clear bit, SRR bit will be cleared */
#endif

#define C_PAN_BUSY           ((vuint16)0x0100) /*!< Panel Control Register Panel Busy Flag */
#define C_PAN_ALLOC_TO_LIST  ((vuint16)0x0002) /*!< Panel Control Register Static Allocate PANCMD */
#define C_PAN_RESET_LIST     ((vuint16)0x0001) /*!< Panel Control Register Initialize Lists PANCMD */

#define C_CLC_DISABLE        ((vuint16)0x0001) /*!< Clock Control Register Module Disable Request Bit */
#define C_CLC_IS_DISABLE     ((vuint16)0x0002) /*!< Clock Control Register Module Disable Status Bit */
#define C_CLC_ENABLE         ((vuint16)0x0008) /*!< Clock Control Register Sleep Mode Enable Control bit */

#define C_MCR_INIT_CLOCK     ((vuint16)0x0000) /*!< Module Control Register init mask (TC1xxx:use fclc  TC2xx:start Init) */

/***************************************************************************/
/* macros                                                                  */
/***************************************************************************/
/* PRQA S 3453 FctLikeMacroLabel */ /* MD_MSR_FctLikeMacro */

/* for LL compatibility */
/* hw handles */
#define CAN_HL_HW_TX_NORMAL_INDEX(hwch)     (Can_GetTxBasicHwStart(hwch)) 
# define CAN_HL_HW_TX_STARTINDEX(hwch)      (Can_GetTxFullHwStart(hwch))
#define CAN_HL_HW_TX_FULL_STARTINDEX(hwch)  (Can_GetTxFullHwStart(hwch))
#define CAN_HL_HW_UNUSED_STARTINDEX(hwch)   (Can_GetUnusedHwStart(hwch))
#define CAN_HL_HW_RX_FULL_STARTINDEX(hwch)  (Can_GetRxFullHwStart(hwch))
#define CAN_HL_HW_RX_BASIC_STARTINDEX(hwch) (Can_GetRxBasicHwStart(hwch))
# define CAN_HL_HW_TX_STOPINDEX(hwch)       (Can_GetTxBasicHwStop(hwch))
#define CAN_HL_HW_TX_FULL_STOPINDEX(hwch)   (Can_GetTxFullHwStop(hwch))
#define CAN_HL_HW_UNUSED_STOPINDEX(hwch)    (Can_GetUnusedHwStop(hwch))
#define CAN_HL_HW_RX_FULL_STOPINDEX(hwch)   (Can_GetRxFullHwStop(hwch))
#define CAN_HL_HW_RX_BASIC_STOPINDEX(hwch)  (Can_GetRxBasicHwStop(hwch))
/* mailbox handles */
#define CAN_HL_MB_RX_FULL_STARTINDEX(hwch)  (Can_GetRxFullHandleStart(hwch))
#define CAN_HL_MB_RX_BASIC_STARTINDEX(hwch) (Can_GetRxBasicHandleStart(hwch))
#define CAN_HL_MB_TX_FULL_STARTINDEX(hwch)  (Can_GetTxFullHandleStart(hwch))
#define CAN_HL_MB_TX_BASIC_STARTINDEX(hwch) (Can_GetTxBasicHandleStart(hwch))
#define CAN_HL_MB_RX_FULL_STOPINDEX(hwch)   (Can_GetRxFullHandleStop(hwch))
#define CAN_HL_MB_RX_BASIC_STOPINDEX(hwch)  (Can_GetRxBasicHandleStop(hwch))
#define CAN_HL_MB_TX_FULL_STOPINDEX(hwch)   (Can_GetTxFullHandleStop(hwch))
#define CAN_HL_MB_TX_BASIC_STOPINDEX(hwch)  (Can_GetTxBasicHandleStop(hwch))

#if defined(C_ENABLE_CAN_RAM_CHECK)
# if !defined(CAN_RAM_CHECK_MAILBOX_RESULT) /* May be defined by test suite to stimulate RAM_CHECK failure */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
#   define CAN_RAM_CHECK_MAILBOX_RESULT(ch, initParaPtr) CanLL_InitIsMailboxCorrupt((initParaPtr))
#  else
#   define CAN_RAM_CHECK_MAILBOX_RESULT(ch, initParaPtr) CanLL_InitIsMailboxCorrupt((ch), (initParaPtr))
#  endif
# endif
# if !defined(CAN_RAM_CHECK_FINISHED_CTP) /* May be defined by test suite to check RAM_CHECK finished / executed */
#  define CAN_RAM_CHECK_FINISHED_CTP(ch)
# endif
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
# if !defined(CAN_RAM_CHECK_BEGIN_REG_RESULT) /* May be defined by test suite to stimulate RAM_CHECK_EXTENDED failure */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
#   define CAN_RAM_CHECK_BEGIN_REG_RESULT(ch, initParaPtr) CanLL_InitBeginIsRegisterCorrupt((initParaPtr))
#  else
#   define CAN_RAM_CHECK_BEGIN_REG_RESULT(ch, initParaPtr) CanLL_InitBeginIsRegisterCorrupt((ch), (initParaPtr))
#  endif
# endif
# if !defined(CAN_RAM_CHECK_END_REG_RESULT) /* May be defined by test suite to stimulate RAM_CHECK_EXTENDED failure */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
#   define CAN_RAM_CHECK_END_REG_RESULT(ch, initParaPtr) CanLL_InitEndIsRegisterCorrupt((initParaPtr))
#  else
#   define CAN_RAM_CHECK_END_REG_RESULT(ch, initParaPtr) CanLL_InitEndIsRegisterCorrupt((ch), (initParaPtr))
#  endif
# endif
# if !defined(CAN_RAM_CHECK_READ_BACK_RESULT) /* May be defined by test suite to stimulate RAM_CHECK_EXTENDED failure */
#  define CAN_RAM_CHECK_READ_BACK_RESULT(ch)
# endif
#endif

#define CanHL_IsStart(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_START) == CAN_STATUS_START)
#define CanHL_IsSleep(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_SLEEP) == CAN_STATUS_SLEEP)
#define CanHL_IsStop(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_STOP) == CAN_STATUS_STOP)
#define CanHL_IsBusOff(ch) (Can_IsIsBusOff(ch))
#define CanHL_IsControllerInit(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_INIT) == CAN_STATUS_INIT)

#if defined(C_ENABLE_CAN_FD_USED) /* also for BRS because DLC may be bigger than 8 and will be checked by CanIf */
# define CAN_DLC2LEN(dlc) (Can_DlcToFrameLenght[((uint8)(dlc)) & ((uint8)0xFu)])
# define CAN_LEN2DLC(length) ((uint8)Can_MessageLengthToDlc[(length)])
#else
# define CAN_DLC2LEN(dlc) (dlc)
# define CAN_LEN2DLC(length) (length)
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
# define CAN_MAX_DATALEN_OBJ(Index) Can_GetMailboxDataLen(Index)
#else
# define CAN_MAX_DATALEN_OBJ(Index) 8u
#endif
#define CanHL_IsFdMessage(id) (((id) & (Can_IdType)CAN_ID_FD_MASK) == (Can_IdType)CAN_ID_FD_MASK) /* \trace SPEC-60432, SPEC-50586 */
#define CanHL_IsFdTxBrs(ch)   (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(ch)) == CAN_FD_RXTX) /* \trace SPEC-60432, SPEC-50586 */

/* PRQA L:FctLikeMacroLabel */

/* PRQA S 3453 QAC_CanLL_FctLikeMacro */ /* MD_MSR_FctLikeMacro */
#if defined( C_ENABLE_USE_VSTDLIB )           /* COV_CAN_VSTDLIB_USE */
# define CAN_SFR_PROTECT_OFF()    VStdUnlockInit()
# define CAN_SFR_PROTECT_ON()     VStdLockInit()
# if defined( C_ENABLE_NESTED_INTERRUPTS )   /* COV_CAN_VSTDLIB_USE */
#  define CAN_ENABLE_GLOBAL_ISR() VStdEnableInt()
# endif
#else /* part of Appl code (default) */
# define CAN_SFR_PROTECT_OFF()    Appl_UnlockEndinit()
# define CAN_SFR_PROTECT_ON()     Appl_LockEndinit()
# if defined( C_ENABLE_NESTED_INTERRUPTS )
#  define CAN_ENABLE_GLOBAL_ISR() Appl_EnableInt()
# endif
#endif


/*
|<DataModelStart>| CanLL_TxIsObjFree
Relation_Context:
Relation:
ChannelAmount, TxBasicAmount
ChannelAmount, TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
#define CanLL_TxIsObjFree( hwCh, txObjHandle ) \
         ((canCellPtr->Obj[(vuint8)CAN_HWOBJ_SAFE_MASK(txObjHandle)].MoCtrL & C_MOCTR_TXREQ) == (vuint16)0x0000u)
/*
|<DataModelStart>| CanLL_HwIsSleep
Relation_Context:
Relation:
Wakeup, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
# define CanLL_HwIsSleep( hwCh )  (kCanFalse != kCanFalse)  /* avoid misra warning */

/*
|<DataModelStart>| CanLL_HwIsStop
Relation_Context:
Relation:
OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
#define CanLL_HwIsStop( hwCh )  (Can_GetHaltOfControllerData(hwCh)==kCanOk)

/*
|<DataModelStart>| CanLL_HwIsBusOff
Relation_Context:
Relation:
OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
#if defined(MISRA_CHECK) /* COV_CAN_MISRA */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsBusOff",0303 /* MD_Can_HwAccess */
#endif
#define CanLL_HwIsBusOff( hwCh )  \
        (((canCellPtr->Node[Can_GetNodeNum(hwCh)].NSR & C_NSR_BOFF)==C_NSR_BOFF) || \
         ((!CanLL_HwIsStop(hwCh)) && ((canCellPtr->Node[Can_GetNodeNum(hwCh)].NCR & C_NCR_INIT)==C_NCR_INIT)))

#if defined( C_ENABLE_EXTENDED_STATUS )
/*
|<DataModelStart>| CanLL_HwIsPassive
Relation_Context:
Relation:
CanGetStatus, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
# if defined(MISRA_CHECK) /* COV_CAN_MISRA */
#  pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsPassive",0303 /* MD_Can_HwAccess */
# endif
# define CanLL_HwIsPassive( hwCh )  \
         ((canCellPtr->Node[Can_GetNodeNum(hwCh)].NECnt_Tec > 127u) || (canCellPtr->Node[Can_GetNodeNum(hwCh)].NECnt_Rec > 127u))

/*
|<DataModelStart>| CanLL_HwIsWarning
Relation_Context:
Relation:
CanGetStatus, OneChOpt, ChannelAmount
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
# if defined(MISRA_CHECK) /* COV_CAN_MISRA */
#  pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsWarning",0303 /* MD_Can_HwAccess */
# endif
# define CanLL_HwIsWarning( hwCh ) \
         ((canCellPtr->Node[Can_GetNodeNum(hwCh)].NSR & C_NSR_EWRN)==C_NSR_EWRN)
#endif /* C_ENABLE_EXTENDED_STATUS */

/* temporary buffer for Rx data in RAM */
# define TmpRxMailbox      Can_GetTmpRxMsgMailbox(canHwChannel)
# define pTmpRxMailboxMsg  ((CanChipMsgPtr)    &Can_GetTmpRxMsgMailbox(canHwChannel))
# define pTmpRxMailboxData ((CanChipDataPtr)   &Can_GetTmpRxMsgMailbox(canHwChannel).MoDR[0])

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
# define CanLL_ApplCanTimerStart(loop)  ApplCanTimerStart(channel, loop)
# define CanLL_ApplCanTimerEnd(loop)    ApplCanTimerEnd(channel, loop)
# define CanLL_ApplCanTimerLoop(loop)   ApplCanTimerLoop(channel, loop)
#else
# define CanLL_ApplCanTimerStart(loop)  ApplCanTimerStart(loop)
# define CanLL_ApplCanTimerEnd(loop)    ApplCanTimerEnd(loop)
# define CanLL_ApplCanTimerLoop(loop)   ApplCanTimerLoop(loop)
#endif

/* PRQA L:QAC_CanLL_FctLikeMacro */

/***************************************************************************/
/* Constants                                                               */
/***************************************************************************/
#define CAN_START_SEC_CONST_UNSPECIFIED  /*--------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* BR:012 */
V_DEF_CONST(V_NONE, uint8, CONST) Can_MainVersion         = (uint8)CAN_SW_MAJOR_VERSION; /* PRQA S 3408 */ /* MD_Can_ExternalScope */
V_DEF_CONST(V_NONE, uint8, CONST) Can_SubVersion          = (uint8)CAN_SW_MINOR_VERSION; /* PRQA S 3408 */ /* MD_Can_ExternalScope */
V_DEF_CONST(V_NONE, uint8, CONST) Can_ReleaseVersion      = (uint8)CAN_SW_PATCH_VERSION; /* PRQA S 3408 */ /* MD_Can_ExternalScope */

#if defined(C_ENABLE_CAN_FD_USED)
V_DEF_CONST(CAN_STATIC, uint8, CONST) Can_DlcToFrameLenght[16] = /* PRQA S 3218,3408 */ /* MD_Can_GlobalScope */
{
  0u,  1u,  2u,  3u,
  4u,  5u,  6u,  7u,
  8u, 12u, 16u, 20u,
 24u, 32u, 48u, 64u
};
V_DEF_CONST(CAN_STATIC, uint8, CONST) Can_MessageLengthToDlc[65] = /* PRQA S 3218,3408 */ /* MD_Can_GlobalScope */
{
/* 00..07 */  0u,  1u,  2u,  3u,  4u,  5u,  6u,  7u,
/* 08..15 */  8u,  9u,  9u,  9u,  9u, 10u, 10u, 10u,
/* 16..23 */ 10u, 11u, 11u, 11u, 11u, 12u, 12u, 12u,
/* 24..31 */ 12u, 13u, 13u, 13u, 13u, 13u, 13u, 13u,
/* 32..39 */ 13u, 14u, 14u, 14u, 14u, 14u, 14u, 14u,
/* 40..47 */ 14u, 14u, 14u, 14u, 14u, 14u, 14u, 14u,
/* 48..55 */ 14u, 15u, 15u, 15u, 15u, 15u, 15u, 15u,
/* 56..63 */ 15u, 15u, 15u, 15u, 15u, 15u, 15u, 15u,
/* 64     */ 15u
};
#endif

/* Global constants with CAN driver main and subversion */

#if defined( C_ENABLE_CAN_RAM_CHECK )
/* ROM CATEGORY 4 START */
V_DEF_CONST(CAN_STATIC, vuint8, CONST) CanMemCheckValues8bit[3] = /* PRQA S 3218 */ /* MD_Can_GlobalScope */
{
  0xAAu, 0x55u, 0x00u
};
V_DEF_CONST(CAN_STATIC, vuint16, CONST) CanMemCheckValues16bit[3] = /* PRQA S 3218 */ /* MD_Can_GlobalScope */
{
  0xAAAAu, 0x5555u, 0x0000u
};
V_DEF_CONST(CAN_STATIC, vuint32, CONST) CanMemCheckValues32bit[3] = /* PRQA S 3218 */ /* MD_Can_GlobalScope */
{
  0xAAAAAAAAUL, 0x55555555UL, 0x00000000UL
};
/* ROM CATEGORY 4 END */
#endif

#define CAN_STOP_SEC_CONST_UNSPECIFIED  /*---------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***************************************************************************/
/* global data definitions                                                 */
/***************************************************************************/
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED  /*---------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if !defined(C_ENABLE_MULTIPLE_DRIVERS) /* COV_CAN_MULTIPLE_DRIVERS */
V_DEF_VAR(V_NONE, vuint16, VAR_NOINIT) canLLTempRead; /* avoid compiler optimization by global declaration */ /* PRQA S 3408,1514 */ /* MD_Can_ExternalScope */
#endif

/***************************************************************************************/
/* local data definitions   (need also INFIX because STATIC may be defined to nothing) */
/***************************************************************************************/
/* \trace SPEC-1585 */
/*! Semaphore to block reentrancy for Can_MainFunction_Read() */
V_DEF_VAR(CAN_STATIC, uint8, VAR_NOINIT) canIsRxTaskLocked; /* PRQA S 3408 */ /* MD_Can_GlobalScope */
#if defined(C_ENABLE_RX_QUEUE)
V_DEF_VAR(CAN_STATIC, uint16, VAR_NOINIT) canRxQueueMaxDataSize;  /* PRQA S 3218,3408 */ /* MD_Can_GlobalScope */
#endif


#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
V_DEF_VAR(CAN_STATIC, Can_HwHandleType, VAR_NOINIT) CanNumberOfMaxBasicCAN;
#endif

/* Just for Debugging */
#if defined (C_ENABLE_MULTIPLE_CELLS)
V_DEF_VAR(CAN_STATIC volatile, CanCellStructPtr, VAR_NOINIT) canCellDbgPtr0;  /* PRQA S 3218 */ /* MD_Can_GlobalScope */
V_DEF_VAR(CAN_STATIC volatile, CanCellStructPtr, VAR_NOINIT) canCellDbgPtr1;  /* PRQA S 3218 */ /* MD_Can_GlobalScope */
#else
V_DEF_VAR(CAN_STATIC volatile, CanCellStructPtr, VAR_NOINIT) canCellDbgPtr;  /* PRQA S 3218 */ /* MD_Can_GlobalScope */
#endif

/***************************************************************************/
/*  Safe Check LL                                                          */
/***************************************************************************/
# if !defined(CAN_SAFE_BSW) /* COV_CAN_COMPATIBILITY */
#  define CAN_SAFE_BSW   STD_OFF
# else
#  if (CAN_SAFE_BSW == STD_ON)
#   if defined(C_ENABLE_MULTIPLE_DRIVERS)               || \
     !defined(CanClockDividor)                          || \
     !defined(kCanMCRValue)                             || \
     !defined(C_ENABLE_TX_PRIO_BYID)                    || \
     defined(C_DISABLE_ISR_PROTOTYPE)                   || \
     !defined(kCanSRCAdr)
#    error "Unsupported Feature activated for SafeBSW"
#   endif
#  endif
# endif


#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /*----------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define CAN_START_SEC_VAR_INIT_UNSPECIFIED  /*-----------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ! Mark module to be initialized (used to check double/none initialization) */
V_DEF_VAR(CAN_STATIC, uint8, VAR_INIT) canConfigInitFlag = CAN_STATUS_UNINIT;
# define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED  /*------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* not static because of debug/test usage */
#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)
# define CAN_START_SEC_VAR_INIT_UNSPECIFIED  /*-----------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! Pointer to the current configuration */
V_DEF_P2CONST (V_NONE, Can_ConfigType, VAR_INIT, CONST_PBCFG) Can_ConfigDataPtr = NULL_PTR; /* UREQ00035484 */ /* PRQA S 3408 */ /* MD_Can_ExternalScope */
# define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED  /*------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#else
# define CAN_START_SEC_CONST_UNSPECIFIED  /*--------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! Pointer to the current configuration */
V_DEF_CONSTP2CONST(V_NONE, Can_ConfigType, CONST, CONST_PBCFG) Can_ConfigDataPtr = NULL_PTR; /* PRQA S 3408,1514 */ /* MD_Can_ExternalScope */
# define CAN_STOP_SEC_CONST_UNSPECIFIED  /*---------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/***************************************************************************/
/*  Safe Check                                                             */
/***************************************************************************/
#if !defined(CAN_SAFE_BSW) /* COV_CAN_COMPATIBILITY */
# define CAN_SAFE_BSW   STD_OFF
#else
# if (CAN_SAFE_BSW == STD_ON) /* COV_CAN_SAFE_BSW */
#  if (CAN_DEV_ERROR_DETECT == STD_OFF) || (CAN_AMD_RUNTIME_MEASUREMENT == STD_ON) /* COV_CAN_SAFE_BSW_EXCLUSION */
#   error "Unsupported Feature activated for SafeBSW"
#  endif
# endif
#endif

/***************************************************************************/
/*  Error Check                                                            */
/***************************************************************************/
# if (CAN_SLEEP_SUPPORT == STD_ON) && (CAN_WAKEUP_SUPPORT == STD_ON)
#  error "C_ENABLE_SLEEP_WAKEUP organified but generated like supported"
# endif
#if (CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_SLEEP_SUPPORT == STD_OFF)
# error "activated CAN_WAKEUP_SUPPORT need activated CAN_SLEEP_SUPPORT"
#endif
#if defined(C_ENABLE_HW_LOOP_TIMER)
# if (CAN_LOOP_MAX == 0)
#  error "CAN_LOOP_MAX should not be generated as 0"
# endif
#else
# if (CAN_HARDWARE_CANCELLATION == STD_ON)
#  error "C_ENABLE_HW_LOOP_TIMER organified but generated like supported"
# endif
#endif
# if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
#  error "C_ENABLE_CANCEL_IN_HW organified but generated like supported"
# endif
#if (CAN_MIRROR_MODE == STD_ON) && (!defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2) || (CAN_GENERIC_PRECOPY == STD_OFF))
# error "CAN_MIRROR_MODE need CAN_GENERIC_CONFIRMATION with CAN_API2 and CAN_GENERIC_PRECOPY as STD_ON"
#endif
#if (CAN_MULTIPLE_BASICCAN_TX == STD_ON)
# if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
/* cancellation does not work in CanHL_WritePrepareCancelTx for multiple BasicCAN messages, and is not useful for FIFO queue in CanIf (normally combined with multiple BCAN)*/
# error "CAN_MULTIPLE_BASICCAN_TX and CAN_HW_TRANSMIT_CANCELLATION are STD_ON but this combination is not supported"
# endif
#endif

#if (kCanNumberOfPhysChannels > CAN_MAX_NUM_NODE) && !defined(C_ENABLE_MULTIPLE_CELLS)
# error "Too much hardware channels used (derivative does not support this amount) !"
#endif
#if (kCanNumberOfChannels > CAN_MAX_NUM_NODE) 
# error "Too much nodes selected (see maximum amount of nodes available for this derivative) !"
#endif

#if defined( C_COMP_TASKING_TRICORE_MULTICAN )
#else
#error "Unknown Compiler switch selected"
#endif



#if !defined(kCanBaseAdr) && !defined(C_ENABLE_MULTIPLE_CELLS)
# error "kCanBaseAdr is not defined!"
#endif

#if defined(C_ENABLE_MULTIPLE_CELLS)
# if defined(C_ENABLE_MULTIPLE_DRIVERS) /* COV_CAN_MULTIPLE_DRIVERS */
#  error "The usage of multiple CAN cells in conjunction with Multiple Driver feature is not allowed"
# endif
#endif

/***************************************************************************/
/*  Functions                                                              */
/***************************************************************************/
#define CAN_START_SEC_STATIC_CODE  /*--------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined(C_ENABLE_HW_LOOP_TIMER) /* always used for sync mode */

# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define CanHL_ApplCanTimerStart( timerIdx )  ApplCanTimerStart( timerIdx );
#  define CanHL_ApplCanTimerEnd( timerIdx )    ApplCanTimerEnd( timerIdx );
# else
#  define CanHL_ApplCanTimerStart( timerIdx )  ApplCanTimerStart( channel, (timerIdx) );
#  define CanHL_ApplCanTimerEnd( timerIdx )    ApplCanTimerEnd( channel, (timerIdx) );
# endif
# define CanHL_ApplCanTimerLoop( timerIdx )   if (ApplCanTimerLoop(CAN_CHANNEL_CANPARA_FIRST (timerIdx)) != CAN_OK) \
                                              { \
                                                break; \
                                              }

# if (CAN_HW_LOOP_SUPPORT_API == STD_OFF)
/* Internal handling of HW loops (like AutoSar) - otherwise ApplCanTimer... is defined an implemented by Application */
/****************************************************************************
| NAME:             ApplCanTimerStart
****************************************************************************/
/* Used as macro to save runtime and code */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
/* \trace SPEC-1640 */
#    define ApplCanTimerStart(source)     ((void)GetCounterValue( CAN_OS_COUNTER_ID, &Can_GetCanLoopTimeout(0, (source)))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#    define ApplCanTimerStart(ch, source) ((void)GetCounterValue( CAN_OS_COUNTER_ID, &Can_GetCanLoopTimeout((ch), (source)))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif
/****************************************************************************
| NAME:             ApplCanTimerLoop
****************************************************************************/
/*
|<DataModelStart>| ApplCanTimerLoop
Relation_Context:
# from mode transition + any LL #
HardwareLoopCheck, HardwareCancelByAppl
Relation:
DevErrorDetect, OneChOpt
HardwareLoopCheck
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) ApplCanTimerLoop( CAN_CHANNEL_CANTYPE_FIRST uint8 source )
{
  /* ----- Local Variables ---------------------------------------------- */
  Can_ReturnType retval;
  uint8 errorId;
  uint8 apiId;
  errorId = CAN_E_NO_ERROR;
  apiId = CAN_HW_ACCESS_ID;
  retval = CAN_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#  if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller and source is valid (no INIT check because may be used inside power on INIT) */
  if (source > CAN_LOOP_MAX) /* CM_CAN_HL22 */
  {
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#   if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#   endif
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    TickType elapsedTime;
    TickType startTime;
    /* #110 Calculate the elapsed since time the start of this hardware loop (identified by parameter source). */
    /* Get start time (set by ApplCanTimerStart - temporary variable because GetElapsedValue modify original data */
    startTime = Can_GetCanLoopTimeout(channel, source);
    /* Get elapsed time - from start time to now */
    /* #120 Throw DET error when GetElapsedValue() failed */
    if ( GetElapsedValue( CAN_OS_COUNTER_ID, &startTime, &elapsedTime ) != (StatusType)E_OK ) /* SBSW_CAN_HL37 */ /* COV_CAN_GENDATA_FAILURE */
    {
      errorId = CAN_E_TIMEOUT_DET;
    }
    else
    {
      /* #130 Check if time out occurs for HW loop checks (none mode transition) \trace SPEC-1594 */
      if ( (TickType)CAN_OS_TICK2MS( elapsedTime ) < (TickType)CAN_TIMEOUT_DURATION ) /* COV_CAN_HARDWARE_FAILURE */
      { /* no time out occur return OK */
        retval = CAN_OK;
      }
#  if defined(C_ENABLE_HW_LOOP_TIMER)
      else
      { /* Mode Change synchronous & HW loop check */
        /* #140 Throw DET error and set hardware cancellation flag */
        if (source < CAN_LOOP_MAX) /* COV_CAN_HARDWARE_FAILURE */
        { 
          errorId = CAN_E_TIMEOUT_DET;
        }
      }
#  endif
    }
    CAN_DUMMY_STATEMENT(startTime); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (CAN_DEV_ERROR_REPORT == STD_ON)  
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(apiId, errorId);
  }
#  else
  CAN_DUMMY_STATEMENT(apiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
/****************************************************************************
| NAME:             ApplCanTimerEnd
****************************************************************************/
/* Used as macro to save runtime and code */
/* because of possible nested timers .. timer has to be reset */
#  define ApplCanTimerEnd ApplCanTimerStart
# endif /* (CAN_HW_LOOP_SUPPORT_API == STD_OFF) */

#else /* C_ENABLE_HW_LOOP_TIMER */
/* no HW loop is used at all */
# define CanHL_ApplCanTimerStart( timerIdx )
# define CanHL_ApplCanTimerLoop( timerIdx )
# define CanHL_ApplCanTimerEnd( timerIdx )
#endif


/****************************************************************************
| NAME:             CanHL_ReInit
****************************************************************************/
/*
|<DataModelStart>| CanHL_ReInit
Relation_Context:
# from CanHL_ModeTransition() #
Wakeup, OneChOpt, ChannelAmount
Relation:
DevErrorDetect, OneChOpt, ChannelAmount
DevErrorDetect, Variant, ChannelAmount
RamCheck
TxFullCANSupport
RxFullCANSupport
RxBasicCANSupport
Wakeup, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_STATIC, uint8, STATIC_CODE) CanHL_ReInit( CAN_HW_CHANNEL_CANTYPE_FIRST uint8 doRamCheck )
{ /* \trace SPEC-1719, SPEC-1589, SPEC-1346, SPEC-1565 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  tCanInitParaStruct initPara;
  CanHookBegin_CanHL_ReInit();
  errorId = CAN_E_NO_ERROR;
  initPara.isInitOk = kCanOk;
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller and Config pointer is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1718 */
    errorId = CAN_E_UNINIT;
  }
  else
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* \trace SPEC-1713 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* \trace SPEC-1713 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #100 initialization controller states and initialization objects --- */
    initPara.initObject = Can_GetLastInitObject(channel);
#if defined(C_ENABLE_CAN_RAM_CHECK)
    initPara.doRamCheck = doRamCheck;
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    initPara.isChRamCheckFail = kCanFalse;
#endif
    /* #110 clean up status (do not activate communication and let SLEEP and initialization to detect ram-check request) */
#if defined(C_ENABLE_CAN_RAM_CHECK) && !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    if (doRamCheck == kCanExecuteRamCheck)
    { /* #112 standard RAM check will be performed so delete old status CAN_DEACTIVATE_CONTROLLER but leave CAN_STATUS_INIT (info about PowerOn) */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)CAN_STATUS_INIT);  /* SBSW_CAN_HL02 */
    }
    else
#endif
    { /* #114 extended RAM check may be performed so delete old status except CAN_DEACTIVATE_CONTROLLER and CAN_STATUS_INIT */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & ((uint8)(CAN_DEACTIVATE_CONTROLLER) | (uint8)((uint8)CAN_STATUS_INIT)));  /* SBSW_CAN_HL02 */
    }
    /* #125 begin initialization CanHL_InitBegin() */
    initPara.isInitOk &= CanHL_InitBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
    /* #130 block invalid hardware access (silent check) */
    if (initPara.isInitOk == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
    {
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
      /* #140 do TX FullCAN initialization CanHL_InitTxFullCAN()*/
      initPara.isInitOk &= CanHL_InitTxFullCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */
#endif
      /* #150 do TX BasicCAN initialization CanHL_InitTxBasicCAN() */
      initPara.isInitOk &= CanHL_InitTxBasicCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */
#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
      /* #170 do RX FullCAN initialization CanHL_InitRxFullCAN() */
      initPara.isInitOk &= CanHL_InitRxFullCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */
#endif
#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
      /* #180 do RX BasicCAN initialization CanHL_InitRxBasicCAN() */
      initPara.isInitOk &= CanHL_InitRxBasicCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */
#endif
      /* #190 end initialization CanHL_InitEnd_InitMode() */
      initPara.isInitOk &= CanHL_InitEnd_InitMode(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
#if defined(C_ENABLE_CAN_RAM_CHECK)
      if (doRamCheck == kCanExecuteRamCheck)
      { 
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
        /* #200 extended RamChecks new issue occur - notify corrupt register / deactivate controller */
        if (initPara.isChRamCheckFail == kCanTrue) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
        {
          CanIf_RamCheckCorruptController((uint8)Can_GetCanToCanIfChannelMapping(channel));
          Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_DEACTIVATE_CONTROLLER); /* SBSW_CAN_HL02 */
        }
# else
        if( (Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) == CAN_DEACTIVATE_CONTROLLER ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
        { /* #210 standard RAM check issue occur - call Appl_CanRamCheckFailed() (any mailbox fail) */
          if (Appl_CanRamCheckFailed((uint8)channel) != CAN_DEACTIVATE_CONTROLLER)
          { /* #220 let the application decide if communication stay disabled as set by RAM check or not */
            Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)(~(CAN_DEACTIVATE_CONTROLLER))); /* Application decide to activate communication in case RAM_CHECK failed */  /* SBSW_CAN_HL02 */
          }
        }
# endif
        CAN_RAM_CHECK_FINISHED_CTP(channel)
      }
#endif
    }
    if (initPara.isInitOk == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
    { /* #280 set controller init flag when no issue occure before */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | (CAN_STATUS_INIT)); /* SBSW_CAN_HL02 */
    }
    else
    { /* #275 set error when issue occure before */
      Can_SetLogStatus(channel, /* CAN_STATUS_UNINIT | */ (Can_GetLogStatus(channel) & (uint8)(CAN_DEACTIVATE_CONTROLLER))); /* SBSW_CAN_HL02 */
      errorId = CAN_E_UNINIT;
    }
  } /* controller active in multiple ECU configuration */

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_INITCTR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
#if !defined(C_ENABLE_CAN_RAM_CHECK)
  CAN_DUMMY_STATEMENT(doRamCheck); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_CanHL_ReInit();
  return initPara.isInitOk;
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */

/****************************************************************************
| NAME:             CanHL_ModeTransition
****************************************************************************/
/*
|<DataModelStart>| CanHL_ModeTransition
Relation_Context:
# from Can_Init #
ChannelAmount
# from Can_Mainfunction_BusOff, CanHL_ErrorHandling #
StatusPolling, ChannelAmount
# from Can_ChangeBaudrate #
ChannelAmount
# from Can_SetBaudrate #
ChannelAmount
# from Can_SetControllerMode #
Wakeup
RamCheck
# from Can_RamCheckExecute #
RamCheck
# from Can_RamCheckEnableController #
RamCheck
Relation:
OneChOpt, HardwareLoopCheck, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_ModeTransition( CAN_CHANNEL_CANTYPE_FIRST uint8 transitionRequest, uint8 busOffRecovery, uint8 doRamCheck )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 transitionState;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 request transition in LL */
  transitionState = CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
  return transitionState;
}

/****************************************************************************
| NAME:             CanHL_NotifyTransition
****************************************************************************/
/*
|<DataModelStart>| CanHL_NotifyTransition
Relation_Context:
# from Can_SetControllerMode() #
Wakeup
RamCheck
Relation:
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_NotifyTransition( CAN_CHANNEL_CANTYPE_FIRST uint8 canState, CanIf_ControllerModeType canIfState, uint8 transitionState )
{
  {
    /* #20 transition finished change internal state */
    Can_SetLogStatus(channel, (uint8)((Can_GetLogStatus(channel) & CAN_STATUS_MASK_NOMODE) | canState)); /* SBSW_CAN_HL02 */
    /* #30 remove transition request */
    Can_SetModeTransitionRequest(channel, kCanModeNone); /* SBSW_CAN_HL01 */
    /* #40 call notification CanIf_ControllerModeIndication() \trace SPEC-1726, SPEC-1644, SPEC-60446 */
    CanIf_ControllerModeIndication( (uint8)Can_GetCanToCanIfChannelMapping(channel), canIfState );
  }
  CAN_DUMMY_STATEMENT(transitionState); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}


/****************************************************************************
| NAME:             CanHL_WritePrepare
****************************************************************************/
/*
|<DataModelStart>| CanHL_WritePrepare
Relation_Context:
# from Can_Write() #
Relation:
TxFullCANSupport
MultiplexedTx, TxHwFifo
MultiplexedTx, HwCancelTx, IdenticalIdCancel
ChannelAmount
OneChOpt
TxBasicAmount
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WritePrepare( CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 calculate logical TX mailbox handle for FullCAN or for BasicCAN (Multiplexed TX) as start value */
  txPara->mailboxElement = 0u; /* PRQA S 2982 */ /* MD_MSR_RetVal */ /* SBSW_CAN_HL42 */
  txPara->activeSendObject = CanHL_GetActiveSendObject(txPara->mailboxHandle, 0u); /* SBSW_CAN_HL42 */
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
  if ( Can_GetMailboxType(txPara->mailboxHandle) != CAN_TX_FULLCAN_TYPE ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
#endif
  { /* #20 BasicCAN preparation - search for hardware and logical transmit handle and do cancellation */
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
    CanObjectHandle mailboxElement_max;
    mailboxElement_max = Can_GetMailboxSize(txPara->mailboxHandle); /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    /* \trace SPEC-1677, SPEC-1672, SPEC-1679, SPEC-1673, SPEC-1671 */
    { /* #27 if normal or Mux Tx search from first to last element 0..1 or 0..3 for free object or one to be cancelled */
      CanObjectHandle mailboxElementFound;
      CanObjectHandle activeSendObjectFound;
      mailboxElementFound = mailboxElement_max;
      activeSendObjectFound = mailboxElement_max;
      for (txPara->mailboxElement = 0u; txPara->mailboxElement < mailboxElement_max; txPara->mailboxElement++) /* SBSW_CAN_HL42 */ /* SBSW_CAN_HL42 */
      { /* #30 over all multiplexed TX objects: find free mailbox or mailbox with identical ID */
        if (Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferFree)
        { /* #60 None Identical ID: else priority 1 - find free mailbox (no cancellation) */
          mailboxElementFound = txPara->mailboxElement;
          activeSendObjectFound = txPara->activeSendObject;
          break;
        }
        txPara->activeSendObject++; /* SBSW_CAN_HL42 */
      }
      if (mailboxElementFound == mailboxElement_max)
      { /* #90 no free or cancel mailbox found: return values set to valid element or to found element and cancel */
        txPara->mailboxElement = 0u; /* SBSW_CAN_HL42 */
        txPara->activeSendObject = CanHL_GetActiveSendObject(txPara->mailboxHandle, 0u); /* SBSW_CAN_HL42 */
      }
      else
      {
        txPara->mailboxElement = mailboxElementFound; /* SBSW_CAN_HL42 */
        txPara->activeSendObject = activeSendObjectFound; /* SBSW_CAN_HL42 */
      }
    } /* normal or mux tx */
#endif
  } /* end BasicCAN handling */
  CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* #200 no special FullCAN handling needed */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */



/****************************************************************************
| NAME:             CanHL_WriteStart
****************************************************************************/
/*
|<DataModelStart>| Can_WriteStart
Relation_Context:
# from Can_Write #
Relation:
GenericPreTransmit
TxHwFifo, GenericConfirmation
IDType
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_WriteStart( CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  Can_ReturnType retval = CAN_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 free TX mailbox found so start transmission \trace SPEC-1744 */
  if (Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferFree)
  {
    uint8 llretval;
    /* #20 remember PDU and send state to use it in Confirmation function \trace SPEC-1675 */
    Can_SetActiveSendPdu(txPara->activeSendObject, txPara->pdu.swPduHandle); /* SBSW_CAN_HL05 */
    Can_SetActiveSendState(txPara->activeSendObject, kCanBufferSend); /* SBSW_CAN_HL04 */
#if defined(C_ENABLE_PRETRANSMIT_FCT)
    /* call pretransmit function ----------------------------------------------- */
    Appl_GenericPreTransmit( (uint8)channel, &(txPara->pdu) );  /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL24 */
#endif
    /* #50 HW prepare transmission */
    CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    /* #60 Set ID, ID type and DLC in HW register depend on ID type */
    txPara->dlcRaw = MK_TX_DLC(CAN_LEN2DLC(txPara->pdu.length)); /* SBSW_CAN_HL42 */
#if defined(C_ENABLE_EXTENDED_ID)
# if defined(C_ENABLE_MIXED_ID)
    if ( ((txPara->pdu.id) & CAN_ID_IDE_MASK) != CAN_ID_IDE_MASK) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    {
      SET_PARASTRUCT_IDRAW_TX_STD(txPara, txPara->pdu.id); /* SBSW_CAN_HL42 */
    }
    else
# endif
    {
      SET_PARASTRUCT_IDRAW_TX_EXT(txPara, txPara->pdu.id); /* SBSW_CAN_HL42 */
    }
#else
    {
      SET_PARASTRUCT_IDRAW_TX_STD(txPara, txPara->pdu.id); /* SBSW_CAN_HL42 */ /* PRQA S 4491 */ /* MD_Can_IntegerCast */
    }
#endif
    /* set id, dlc in hardware */
    CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    if(txPara->pdu.sdu != NULL_PTR)
    { /* #70 Set CAN data in HW register (LL) - only when data pointer is not null \trace SPEC-1680, SPEC-1572, SPEC-1678, SPEC-60421 */
      txPara->CanMemCopySrcPtr = txPara->pdu.sdu; /* SBSW_CAN_HL42 */
      CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    }
    /* #80 HW start transmission (LL) */
    llretval = CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    /* HW finish transmission (LL) */
    CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    CAN_DUMMY_STATEMENT(llretval); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }
  else
  { /* #200 no free TX mailbox found so return busy - also in case cancellation (BasicCAN) was possible \trace SPEC-1754, SPEC-1764, SPEC-1747 */
    retval = CAN_BUSY;
  }
  return retval;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/****************************************************************************
| NAME:             CanHL_GetActiveSendObject
****************************************************************************/
/*
|<DataModelStart>| CanHL_GetActiveSendObject
Relation_Context:
# from CanHL_InitXXX() #
Wakeup, OneChOpt, ChannelAmount
# from CanHL_WritePrepare #
# from CanHL_TxTaskCancelationHandling #
HwCancelTx
# from CanHL_CleanUpSendState #
# from Can_CancelTx #
TransmitCancellationAPI
# from CanHL_TxConfirmation #
Relation:
DevErrorDetect
TxFullAmount
TxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, CanObjectHandle, STATIC_CODE) CanHL_GetActiveSendObject( Can_HwHandleType mailboxHandle, Can_HwHandleType mailboxElement )
{
  /* ----- Local Variables ---------------------------------------------- */
  CanObjectHandle activeSendObject;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 get logical handle from generated indirection table */
  activeSendObject = (CanObjectHandle) Can_GetMailboxActiveSendObject(mailboxHandle) + mailboxElement;
#if (CAN_SAFE_BSW == STD_ON)
  if (activeSendObject >= (Can_HwHandleType)Can_GetSizeOfActiveSendObject()) /* CM_CAN_HL03 */ /* COV_CAN_GENDATA_FAILURE */
  { /* #20 secure SilentBSW */
    activeSendObject = ((Can_HwHandleType)Can_GetSizeOfActiveSendObject() - (Can_HwHandleType)1u);
# if (CAN_DEV_ERROR_REPORT == STD_ON)  
    Can_CallDetReportError(CAN_WRITE_ID, CAN_E_PARAM_HANDLE);
# endif
  }
#endif
  return activeSendObject;
}


#if defined(C_ENABLE_CAN_RAM_CHECK)
/****************************************************************************
| NAME:             CanHL_RamCheckMailboxNotification
****************************************************************************/
/*
|<DataModelStart>| CanHL_RamCheckMailboxNotification
Relation_Context:
# CanHL_InitXXX() #
Wakeup, OneChOpt, ChannelAmount, RamCheck
Relation:
TxFullCANSupport
RxFullCANSupport
RxBasicCANSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RamCheckMailboxNotification( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */ /* COV_CAN_RAM_CHECK_NO_STIMULATION */
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 deactivate mailbox */
  Can_SetMailboxState(initPara->mailboxHandle, kCanFailed); /* SBSW_CAN_HL34 */
  /* #20 deactivate controller */
  Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_DEACTIVATE_CONTROLLER); /* SBSW_CAN_HL02 */
  /* #30 notify application about corrupt mailbox */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  CanIf_RamCheckCorruptMailbox((uint8)Can_GetCanToCanIfChannelMapping(channel), initPara->mailboxHandle);
# else
#  if defined(C_ENABLE_NOTIFY_CORRUPT_MAILBOX) /* with Mailbox Notification */
  Appl_CanCorruptMailbox((uint8)channel, (initPara->hwObjHandle));
#  endif
# endif
}
#endif

/****************************************************************************
| NAME:             CanHL_InitBegin
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitBegin
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount
Relation:
RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitBegin( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanFailed; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  if (CanLL_InitBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara) == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* SBSW_CAN_HL31 */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
  {
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    /* #20 Execute pattern RamCheck */
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      initPara->isChRamCheckFail |= CAN_RAM_CHECK_BEGIN_REG_RESULT(channel, initPara); /* SBSW_CAN_HL36 */ /* SBSW_CAN_HL31 */ /* COV_CAN_HARDWARE_FAILURE */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
    } 
#endif
    /* #30 Initialize controller registers (Begin section) */
    initOk = CanLL_InitBeginSetRegisters(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
  }
  return initOk;
}

#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
/****************************************************************************
| NAME:             CanHL_InitTxFullCAN
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitTxFullCAN
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount, TxFullCANSupport
Relation:
RamCheck
TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxFullCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  uint8 mailboxState;
  CanObjectHandle activeSendObject;
# if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
# endif
  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;
  /* #10 iterate over all FullCAN TX */
  for (initPara->mailboxHandle = Can_GetTxFullHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetTxFullHandleStop(canHwChannel); initPara->mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */ /* SBSW_CAN_HL36 */ /* SBSW_CAN_HL36 */
  { /* #20 initialize FullCAN TX mailboxes */
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle); /* SBSW_CAN_HL36 */
    activeSendObject = CanHL_GetActiveSendObject(initPara->mailboxHandle, 0u);
    Can_SetActiveSendState(activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #30 RAM check for FullCAN TX mailboxes */
    isMbRamCheckFail = kCanFalse;
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara); /* SBSW_CAN_HL31 */ /* COV_CAN_HARDWARE_FAILURE */
    } 
# endif
    /* TX initialization */
    mailboxState = CanLL_InitMailboxTx(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
    initOk &= mailboxState; /* all mailboxes OK - otherwise return fail */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT )
    { /* PowerOn */
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState); /* SBSW_CAN_HL34 */
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    { /* #45 deactivate corrupt mailbox */
      CanLL_InitMailboxTxDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      if (isMbRamCheckFail == kCanTrue)
      {  /* #50 notify application about corrupt mailbox and deactivate controller */
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      }
    }
# endif
  }
  return initOk;
}
#endif

/****************************************************************************
| NAME:             CanHL_InitTxBasicCAN
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitTxBasicCAN
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount
Relation:
MultiplexedTx, TxHwFifo
TxHwFifo, GenericConfirmation, IfTxBuffer
TxBasicAmount
RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxBasicCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  uint8 mailboxState;
  CanObjectHandle activeSendObject;
#if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
#endif

  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;
  initPara->mailboxHandle = Can_GetTxBasicHandleStart(canHwChannel); /* SBSW_CAN_HL36 */
#if defined(C_ENABLE_MULTIPLE_BASICCAN_TX)
  for (; initPara->mailboxHandle < Can_GetTxBasicHandleStop(canHwChannel); initPara->mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */ /* SBSW_CAN_HL36 */
#endif
  { /* #10 iterate over all logical BasicCAN TX */
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
    CanObjectHandle activeSendObjectStop;
#endif
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */ /* SBSW_CAN_HL36 */
    activeSendObject = CanHL_GetActiveSendObject(initPara->mailboxHandle, 0u);
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
    activeSendObjectStop = activeSendObject + Can_GetMailboxSize(initPara->mailboxHandle);
    for (; activeSendObject < activeSendObjectStop; activeSendObject++)
#endif
    { /* #20 initialize BasicCAN TX mailboxes */
      Can_SetActiveSendState(activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
    }
#if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #30 RAM check for BasicCAN TX mailboxes */
    isMbRamCheckFail = kCanFalse;
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara); /* COV_CAN_HARDWARE_FAILURE */ /* SBSW_CAN_HL31 */
    } 
#endif
    /* TX initialization */
    mailboxState = CanLL_InitMailboxTx(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
    initOk &= mailboxState; /* all mailboxes OK - otherwise return fail */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
#if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT )
    { /* PowerOn */
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState); /* SBSW_CAN_HL34 */
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    { /* #45 deactivate corrupt mailbox */
      CanLL_InitMailboxTxDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      if (isMbRamCheckFail == kCanTrue)
      {  /* #50 notify application about corrupt mailbox and deactivate controller */
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      }
    }
#endif
  }
  return initOk;
}


#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
/****************************************************************************
| NAME:             CanHL_InitRxFullCAN
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitRxFullCAN
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount, RxFullCANSupport
Relation:
RamCheck
IDType
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxFullCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  uint8 mailboxState;
# if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
# endif

  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;
  for (initPara->mailboxHandle = Can_GetRxFullHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetRxFullHandleStop(canHwChannel); initPara->mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* SBSW_CAN_HL36 */ /* SBSW_CAN_HL36 */
  { /* #10 iterate over all FullCAN RX mailboxes */
    initPara->hwObjHandle=Can_GetMailboxHwHandle(initPara->mailboxHandle); /* SBSW_CAN_HL36 */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #20 RAM check for FullCAN RX mailboxes */
    isMbRamCheckFail = kCanFalse;
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara); /* COV_CAN_HARDWARE_FAILURE */ /* SBSW_CAN_HL31 */
    } 
# endif
    /* #30 set ID for FullCAN RX mailboxes (LL) */
# if defined(C_ENABLE_EXTENDED_ID)
#  if defined(C_ENABLE_MIXED_ID)
    if ( (Can_GetMailboxIDValue(initPara->mailboxHandle) & CAN_ID_IDE_MASK) != CAN_ID_IDE_MASK) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */
    {
      initPara->idType = kCanIdTypeStd; /* SBSW_CAN_HL36 */
      SET_PARASTRUCT_IDRAW_RX_STD(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle)); /* SBSW_CAN_HL36 */ /* PRQA S 4491 */ /* MD_Can_IntegerCast */
    }
    else
#  endif
    {
      initPara->idType = kCanIdTypeExt; /* SBSW_CAN_HL36 */ /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      SET_PARASTRUCT_IDRAW_RX_EXT(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle)); /* SBSW_CAN_HL36 */
    }
# else
    initPara->idType = kCanIdTypeStd; /* SBSW_CAN_HL36 */
    SET_PARASTRUCT_IDRAW_RX_STD(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle)); /* SBSW_CAN_HL36 */ /* PRQA S 4491 */ /* MD_Can_IntegerCast */
# endif
    /* #40 initialize FullCAN RX mailboxes */
    mailboxState = CanLL_InitMailboxRxFullCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
    initOk &= mailboxState; /* all mailboxes OK - otherwise return fail */ /* PRQA S 2985 */ /* MD_Can_ConstValue */

# if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT )
    { /* PowerOn */
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState); /* SBSW_CAN_HL34 */
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    { /* #45 deactivate corrupt mailbox */
      CanLL_InitMailboxRxFullCanDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      if (isMbRamCheckFail == kCanTrue)
      {  /* #50 notify application about corrupt mailbox and deactivate controller */
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      }
    }
# endif
  }
  return initOk;
}
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
/****************************************************************************
| NAME:             CanHL_InitRxBasicCAN
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitRxBasicCAN
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount, RxBasicCANSupport
Relation:
RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxBasicCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  uint8 mailboxState;
# if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
# endif

  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;
  for (initPara->mailboxHandle = Can_GetRxBasicHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetRxBasicHandleStop(canHwChannel); initPara->mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */ /* SBSW_CAN_HL36 */ /* SBSW_CAN_HL36 */
  { /* #10 iterate over all BasicCAN RX mailboxes */
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle); /* SBSW_CAN_HL36 */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #20 RAM check for BasicCAN RX mailboxes */
    isMbRamCheckFail = kCanFalse;
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara); /* COV_CAN_HARDWARE_FAILURE */ /* SBSW_CAN_HL31 */
    } 
# endif
    /* #30 initialize BasicCAN RX mailboxes */
    mailboxState = CanLL_InitMailboxRxBasicCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
    initOk &= mailboxState; /* all mailboxes OK - otherwise return fail */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT )
    { /* PowerOn */
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState); /* SBSW_CAN_HL34 */
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    { /* #45 deactivate corrupt mailbox */
      CanLL_InitMailboxRxBasicCanDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      if (isMbRamCheckFail == kCanTrue)
      {  /* #50 notify application about corrupt mailbox and deactivate controller */
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      }
    }
# endif
  }
  return initOk;
}
#endif

/****************************************************************************
| NAME:             CanHL_InitEnd_InitMode
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitEnd_InitMode
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount
Relation:
RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitEnd_InitMode( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;

  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;

  /* #20 HW specific initialization end */
  initOk &= CanLL_InitEndSetRegisters(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  initOk &= CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara ); /* SBSW_CAN_HL31 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  return initOk;
}

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/****************************************************************************
| NAME:             CanHL_RxBasicCanPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_RxBasicCanPolling
Relation_Context:
# from Can_MainFunction_Read #
RxBasicCANSupport, RxPolling
Relation:
IndividualPolling
OneChOpt
ChannelAmount
RxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxBasicCanPolling( CAN_HW_CHANNEL_CANTYPE_ONLY )
{
  /* ----- Local Variables ---------------------------------------------- */
  tCanTaskParaStruct taskPara;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 check global pending flag (over all mailboxes - if available) */
  {
    /* #20 loop over all BasicCAN mailboxes */
    for (taskPara.mailboxHandle = Can_GetRxBasicHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetRxBasicHandleStop(canHwChannel); taskPara.mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
    { /* loop over all BasicCAN mailboxes with gap */
      taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#  if defined(C_ENABLE_INDIVIDUAL_POLLING) /* COV_CAN_HWOBJINDIVPOLLING */
      /* #30 check individual polling flag */
      if ( Can_IsMailboxIndivPolling(taskPara.mailboxHandle)) /* COV_CAN_HWOBJINDIVPOLLING */
#  endif
      {
        /* #40 call LL handling */
        CanLL_RxBasicProcessPendings(CAN_HW_CHANNEL_CANPARA_FIRST &taskPara); /* SBSW_CAN_HL44 */
      }
    }
  }
}
# endif /* C_ENABLE_RX_BASICCAN_POLLING */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/****************************************************************************
| NAME:             CanHL_RxFullCanPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_RxFullCanPolling
Relation_Context:
# from Can_MainFunction_Read #
RxFullCANSupport, RxPolling
Relation:
IndividualPolling
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxFullCanPolling( CAN_HW_CHANNEL_CANTYPE_ONLY )
{
  /* ----- Local Variables ---------------------------------------------- */
  tCanTaskParaStruct taskPara;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 check global pending flag (over all mailboxes - if available) */
  {
    /* #20 loop over all FullCAN mailboxes */
    for (taskPara.mailboxHandle = Can_GetRxFullHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetRxFullHandleStop(canHwChannel); taskPara.mailboxHandle++ ) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
    {
      taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#  if defined(C_ENABLE_INDIVIDUAL_POLLING) /* COV_CAN_HWOBJINDIVPOLLING */
      /* #30 check individual polling flag */
      if ( Can_IsMailboxIndivPolling(taskPara.mailboxHandle)) /* COV_CAN_HWOBJINDIVPOLLING */
#  endif
      {
        /* #40 call LL handling */
        CanLL_RxFullProcessPendings(CAN_HW_CHANNEL_CANPARA_FIRST &taskPara); /* SBSW_CAN_HL44 */
      }
    }
  }
}
# endif /* C_ENABLE_RX_FULLCAN_POLLING */
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
/****************************************************************************
| NAME:             CanHL_RxMsgReceivedNotification
****************************************************************************/
/*
|<DataModelStart>| CanHL_RxMsgReceivedNotification
Relation_Context:
# from CanHL_FullCanMsgReceived #
RxFullCANSupport
# from CanHL_BasicCanMsgReceived #
RxBasicCANSupport
Relation:
RxQueue, GenericPreCopy, MirrorMode
RxQueue, DevErrorDetect
RxQueue, CanFdSupport
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_RxMsgReceivedNotification( CAN_CHANNEL_CANTYPE_FIRST CanRxInfoStructPtr rxStructPtr ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  /* ----- Local Variables ---------------------------------------------- */
# if !defined(C_ENABLE_RX_QUEUE) && (CAN_GENERIC_PRECOPY == STD_ON)
  Can_ReturnType generic_retval;
# endif
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 RX queue */
# if defined(C_ENABLE_RX_QUEUE)
  /**************************** RxQueue handling **********************************/
    /* #20 EXCLUSIVE_AREA_4 secure RxQueue data handling */
  SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();
  if (Can_GetRxQueueInfo().Count < Can_GetSizeOfRxQueueBuffer()) /* COV_CAN_GENDATA_FAILURE */
  { /* #30 Queue not full: */
    /* #45 copy HRH, ID, DLC and data to RX queue */
    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).Hrh = rxStructPtr->localMailboxHandle; /* SBSW_CAN_HL18 */
    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).id  = rxStructPtr->localId; /* SBSW_CAN_HL18 */
    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).dlc = rxStructPtr->localDlc; /* SBSW_CAN_HL18 */

#  if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (canRxQueueMaxDataSize < rxStructPtr->localDlc) /* CM_CAN_HL17 */ /* COV_CAN_GENDATA_FAILURE */
    {
      errorId = CAN_E_PARAM_DLC;
    }
    else
#  endif
    {
      /* #46 copy data with VStdLib optimized copy routine */
      VStdMemCpy((void*)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).data, (void*)rxStructPtr->pChipData, rxStructPtr->localDlc); /* SBSW_CAN_HL19 */ /* PRQA S 0312,0314,0316 */ /* MD_Can_NoneVolatilePointerCast,MD_Can_PointerVoidCast,MD_Can_PointerVoidCast */
    }
      /* #47 increase pointer to next queue element */
    Can_GetRxQueueInfo().Count++; /* SBSW_CAN_HL55 */
    if (Can_GetRxQueueInfo().WriteIndex < ((uint16)Can_GetSizeOfRxQueueBuffer() - (uint16)1u) )
    {
      Can_GetRxQueueInfo().WriteIndex++; /* SBSW_CAN_HL55 */
    }
    else
    {
      Can_GetRxQueueInfo().WriteIndex = 0u; /* CM_CAN_HL24 */ /* SBSW_CAN_HL55 */
    }
  }
#  if (CAN_DEV_ERROR_REPORT == STD_ON)
  else 
  { /* #50 Queue full: last message will be lost -> overrun in queue do not change ReadIndex to override latest message because inconsistency problem (currently reading queue) */
    errorId = CAN_E_RXQUEUE;
  }
#  endif
  SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
# else /* C_ENABLE_RX_QUEUE */
  /* #100 no RX queue */
  /* -------------------------- Interface + APPL Notifications --- */
    /* #110 call Appl_GenericPrecopy() depend on configuration and if mirror mode is active */
#  if (CAN_GENERIC_PRECOPY == STD_ON)
#   if defined(C_ENABLE_MIRROR_MODE)
  if (Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE)
  { /* do not call Appl_GenericPrecopy() in case mirror mode was disabled */
    generic_retval = CAN_OK;
  }
  else
#   endif
  {
    generic_retval = Appl_GenericPrecopy((uint8)channel, (rxStructPtr->localId & CAN_ID_MASK_IN_GENERIC_CALLOUT), rxStructPtr->localDlc, (Can_DataPtrType)rxStructPtr->pChipData);  /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL07 */
  }
  if (generic_retval == CAN_OK) /* \trace SPEC-15119 */
#  endif
  { /* #120 call CanIf_RxIndication() if mirror mode is no active or Appl_GenericPrecopy() return OK \trace SPEC-1726, SPEC-1688, SPEC-1687, SPEC-1687 */
    CanIf_RxIndication(rxStructPtr->localMailboxHandle, rxStructPtr->localId, rxStructPtr->localDlc, (Can_DataPtrType)rxStructPtr->pChipData); /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL07 */
  }
# endif
  CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return errorId;
}
#endif

#if defined(C_ENABLE_RX_QUEUE)
/****************************************************************************
| NAME:             CanHL_RxQueueExecution
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/*
|<DataModelStart>| CanHL_RxQueueExecution
Relation_Context:
# from Can_Mainfunction_Read #
RxQueue
Relation:
GenericPreCopy, OneChOpt, DevErrorDetect
GenericPreCopy, MirrorMode
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxQueueExecution( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Execute RxQueue (over all channels) */
  while ( Can_GetRxQueueInfo().Count != (uint16)0 )
  { /* #20 over all filled RxQueue elements */
# if (CAN_GENERIC_PRECOPY == STD_ON)
    Can_ReturnType generic_retval;
    CAN_CHANNEL_CANTYPE_LOCAL
    generic_retval = CAN_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
#  if !defined( C_SINGLE_RECEIVE_CHANNEL ) /* otherwise 'channel' is a define */
    channel = Can_GetMailboxController(Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).Hrh);
#   if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
    { /* #30 Check controller is valid */
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#   endif
#  endif
#  if defined(C_ENABLE_MIRROR_MODE)
    if (Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE)
    { /* #40 MirrorMode: only when mirror is activated for this controller */
      generic_retval = CAN_OK;
    }
    else
#  endif
    { /* #50 call Appl_GenericPrecopy() */
      generic_retval = Appl_GenericPrecopy( (uint8)channel,
                (Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).id & CAN_ID_MASK_IN_GENERIC_CALLOUT),
                Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).dlc,
                (Can_DataPtrType)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).data ); /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL06 */
    }
    if (generic_retval == CAN_OK)
# endif
    { /* #60 call CanIf_RxIndication() if Appl_GenericPrecopy() return OK or no generic precopy is used \trace SPEC-1726, SPEC-1688, SPEC-1687, SPEC-1687 */
      CanIf_RxIndication( Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).Hrh, /* SBSW_CAN_HL06 */
              Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).id,
              Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).dlc,
              (Can_DataPtrType)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).data ); /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */
    }
    /* #70 EXCLUSIVE_AREA_4 secure RxQueue handling */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();
    /* #80 get next RxQueue element pointer */
    if (Can_GetRxQueueInfo().ReadIndex >= ((uint16)Can_GetSizeOfRxQueueBuffer() - (uint16)1u) ) /* CM_CAN_HL25 */
    {
      Can_GetRxQueueInfo().ReadIndex = 0u; /* CM_CAN_HL25 */ /* SBSW_CAN_HL55 */
    }
    else
    {
      Can_GetRxQueueInfo().ReadIndex++; /* SBSW_CAN_HL55 */
    }
    Can_GetRxQueueInfo().Count--; /* SBSW_CAN_HL55 */
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
  }
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_READ_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}
#endif


/****************************************************************************
| NAME:             CanLL_WriteReg8
****************************************************************************/
/*
|<DataModelStart>| CanLL_WriteReg8
Relation_Context:
# CanHL_InitXXX() #
RamCheck
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteReg8( CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr8 regPtr, vuint8 value, vuint8 readMask, CanInitParaStructPtr initPara )
{
  /* #10 write register value */
  *regPtr = value; /* SBSW_CAN_HL35 */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) 
  if (initPara->doRamCheck == kCanExecuteRamCheck)
  {
    vuint8 result = kCanFalse; /* PRQA S 2981 */ /* MD_MSR_RetVal */
    /* #20 read back value for RamCheck */
    volatile vuint8 readBack;
    readBack = *regPtr;
    if ((readBack & readMask) != (value & readMask)) /* COV_CAN_HARDWARE_FAILURE */
    {
      /* #30 return issue when read back value differs */
      result = kCanTrue; /* PRQA S 2982 */ /* MD_MSR_RetVal */
    }
    CAN_RAM_CHECK_READ_BACK_RESULT(channel)
    initPara->isChRamCheckFail |= result; /* SBSW_CAN_HL36 */
  }
# else
  CAN_DUMMY_STATEMENT(readMask); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/****************************************************************************
| NAME:             CanLL_WriteReg16
****************************************************************************/
/*
|<DataModelStart>| CanLL_WriteReg16
Relation_Context:
# CanHL_InitXXX() #
RamCheck
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteReg16( CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr16 regPtr, vuint16 value, vuint16 readMask, CanInitParaStructPtr initPara )
{
  /* #10 write register value */
  *regPtr = value; /* SBSW_CAN_HL35 */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) 
  if (initPara->doRamCheck == kCanExecuteRamCheck)
  {
    vuint8 result = kCanFalse; /* PRQA S 2981 */ /* MD_MSR_RetVal */
    /* #20 read back value for RamCheck */
    volatile vuint16 readBack;
    readBack = *regPtr;
    if ((readBack & readMask) != (value & readMask)) /* COV_CAN_HARDWARE_FAILURE */
    {
      /* #30 return issue when read back value differs */
      result = kCanTrue; /* PRQA S 2982 */ /* MD_MSR_RetVal */
    }
    CAN_RAM_CHECK_READ_BACK_RESULT(channel)
    initPara->isChRamCheckFail |= result; /* SBSW_CAN_HL36 */
  }
# else
  CAN_DUMMY_STATEMENT(readMask); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/****************************************************************************
| NAME:             CanLL_WriteReg32
****************************************************************************/
/*
|<DataModelStart>| CanLL_WriteReg32
Relation_Context:
# CanHL_InitXXX() #
RamCheck
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteReg32( CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr32 regPtr, vuint32 value, vuint32 readMask, CanInitParaStructPtr initPara )
{
  /* #10 write register value */
  *regPtr = value; /* SBSW_CAN_HL35 */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) 
  if (initPara->doRamCheck == kCanExecuteRamCheck)
  {
    vuint8 result = kCanFalse; /* PRQA S 2981 */ /* MD_MSR_RetVal */
    /* #20 read back value for RamCheck */
    volatile vuint32 readBack;
    readBack = *regPtr;
    if ((readBack & readMask) != (value & readMask)) /* COV_CAN_HARDWARE_FAILURE */
    {
      /* #30 return issue when read back value differs */
      result = kCanTrue; /* PRQA S 2982 */ /* MD_MSR_RetVal */
    }
    CAN_RAM_CHECK_READ_BACK_RESULT(channel)
    initPara->isChRamCheckFail |= result; /* SBSW_CAN_HL36 */
  }
# else
  CAN_DUMMY_STATEMENT(readMask); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/**********************************************************************************************************************
 *  CanLL_InitBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitBegin
Relation_Context:
# CanHL_InitBegin() #
OneChOpt, ChannelAmount
Relation:
ProtectedMode
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBegin( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint8 retVal;
#if (CAN_SAFE_BSW == STD_ON)
  /* #05 execute runtime check for generated data */
  retVal = CanLL_CheckGeneratedDataAccess(CAN_CHANNEL_CANPARA_ONLY);
  if (retVal == kCanOk) /* COV_CAN_GENDATA_ERROR */
#else
  retVal = kCanOk;
#endif
  { /* #10 suppress busoff detection while Init-flag is set */
    Can_SetBusOffNotifiedOfControllerData(channel, kCanOk); /* SBSW_CAN_LL02 */
  }
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(retVal);
}
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
/**********************************************************************************************************************
 *  CanLL_InitBeginIsRegisterCorrupt
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitBeginIsRegisterCorrupt
Relation_Context:
# CanHL_InitBegin() #
OneChOpt, ChannelAmount, RamCheck
Relation:
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginIsRegisterCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  vuint8 canRegistersRamCheckFailed;
  CanModuleStructPtr pCanCellModule;
  CanNodeStructPtr  pCanCellNode;
  vuint8 index;
  canRegistersRamCheckFailed = kCanFalse;

  pCanCellModule = CAN_MODULE_PTR;
  pCanCellNode  = CAN_NODE_PTR(Can_GetNodeNum(canHwChannel));
  
  pCanCellNode->NCR = C_NCR_CCE | C_NCR_INIT; /* SBSW_CAN_LL01 */
  /* CANFD does not need to be considered here (RAM check), NCR and NBTR will be written later */
  /* #10 Iterate test patterns */
  for(index = 0; index < 3u; index++)
  {
    vuint8  var_rec, var_tec, var_warn;
    vuint16 var_ncr, var_npcr, var_nipr, var_para;
    vuint32 var_msi, var_nbtr;
    /* #20 Write pattern to controller register */
    /* write control registers with CanMemCheckValues..bit[index] and verify the content */ 
    /* NCR: bit0: do not change mode here, bit4: already init-mode do not set to avoid error-interrupt set, 
            bit5: read only, bit6-8 no mode change here, bit9-31 read only */
    pCanCellNode->NCR = (CanMemCheckValues16bit[index] & 0x000EU) | C_NCR_CCE | C_NCR_INIT; /* SBSW_CAN_LL01 */
    /* NPCR: bit3-7,9-31: read only */
    pCanCellNode->NPCR = CanMemCheckValues16bit[index] & 0x0107U; /* SBSW_CAN_LL01 */
    pCanCellNode->NBTR = CanMemCheckValues32bit[index] & 0x0000FFFFUL; /* SBSW_CAN_LL01 */
    pCanCellNode->NECnt_Rec = CanMemCheckValues8bit[index]; /* SBSW_CAN_LL01 */
    pCanCellNode->NECnt_Tec = CanMemCheckValues8bit[index]; /* SBSW_CAN_LL01 */
    pCanCellNode->NECnt_EWRNLVL = CanMemCheckValues8bit[index]; /* SBSW_CAN_LL01 */
    pCanCellNode->NIPR = CanMemCheckValues16bit[index]; /* SBSW_CAN_LL01 */
    pCanCellModule->PANAR = CanMemCheckValues16bit[index]; /* SBSW_CAN_LL03 */
    pCanCellModule->MSIMask = CanMemCheckValues32bit[index]; /* SBSW_CAN_LL03 */
    /* read back */
    var_ncr = pCanCellNode->NCR;
    /* NPCR: bit3-7,9-31: read only */
    var_npcr = pCanCellNode->NPCR;
    var_nbtr = pCanCellNode->NBTR;
    var_rec  = pCanCellNode->NECnt_Rec;
    var_tec  = pCanCellNode->NECnt_Tec;
    var_warn = pCanCellNode->NECnt_EWRNLVL;
    var_nipr = pCanCellNode->NIPR;
    var_para = pCanCellModule->PANAR;
    var_msi  = pCanCellModule->MSIMask;
    /* #30 Check if register values are valid */
    if( (var_ncr  !=((CanMemCheckValues16bit[index] & 0x000EU) | C_NCR_CCE | C_NCR_INIT)) ||
        (var_npcr != (CanMemCheckValues16bit[index] & 0x0107U))                           ||
        (var_nbtr != (CanMemCheckValues32bit[index] & 0x0000FFFFUL))                      ||
        (var_rec  !=  CanMemCheckValues8bit[index]    )                                   ||
        (var_tec  != CanMemCheckValues8bit[index]     )                                   ||
        (var_warn != CanMemCheckValues8bit[index]     )                                   ||
        (var_nipr != CanMemCheckValues16bit[index]    )                                   ||
        (var_para != CanMemCheckValues16bit[index]    )                                   ||
        (var_msi  != CanMemCheckValues32bit[index]    )  )  /* COV_CAN_HARDWARE_FAILURE */
    {
      canRegistersRamCheckFailed |= kCanTrue; /* the channel is corrupt */
    }
  
    /* excluded registers 
      "Node[].NSR"    (only write 0) 
      "Node[].NFCR"   (unused) 
      "Module.MSPND"   (only write 0) 
      "Module.List"    (read only) 
      "Module.MITR"    (unused) 
      "Module.ID"      (unused) 
      "Module.PANCMD"  (read only or combined with unwanted action)
      "Module.MSID"    (read only)
      "Module.MSIMask" (not channel specific)
    */
  } 
  /* #40 If FD is enabled, the Bittiming register differs regarding layout */
#  if defined( C_ENABLE_CAN_FD_USED )
  {
    vuint32 var_nbtr;
    pCanCellNode->NCR = C_NCR_CCE | C_NCR_INIT | C_NCR_FDEN; /* SBSW_CAN_LL01 */
    for(index = 0; index < 3u; index++)
    {
      pCanCellNode->NBTR = CanMemCheckValues32bit[index] & 0x0FDF8F3FUL; /* SBSW_CAN_LL01 */
      var_nbtr = pCanCellNode->NBTR;
      if(var_nbtr != (CanMemCheckValues32bit[index] & 0x0FDF8F3FUL))  /* COV_CAN_HARDWARE_FAILURE */
      {
        canRegistersRamCheckFailed |= kCanTrue; /* the channel is corrupt */
      }
    }
  }
#  endif
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(canRegistersRamCheckFailed);
}
/* CODE CATEGORY 4 END */
#endif /* C_ENABLE_CAN_RAM_CHECK_EXTENDED */

/**********************************************************************************************************************
 *  CanLL_InitBeginSetRegisters
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitBeginSetRegisters
Relation_Context:
# CanHL_InitBegin() #
OneChOpt, ChannelAmount
Relation:
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  CanNodeStructPtr     pCanCellNode;
  pCanCellNode = CAN_NODE_PTR(Can_GetNodeNum(canHwChannel));
  /* #10 Prepare node register for initialization */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NSR, (vuint16)0x0000u, 0x7338U, initPara);                                  /* SBSW_CAN_LL07 */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NCR, ( C_NCR_CCE | C_NCR_INIT ), 0x03FFU, initPara);                        /* SBSW_CAN_LL07 */
#if defined( C_ENABLE_CAN_FD_USED )
  if (Can_GetIsChannelFd(channel))
  { /* #20 Setup node for FD communication */
    CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NCR, ( C_NCR_CCE | C_NCR_INIT | C_NCR_FDEN ), 0x03FFU, initPara);           /* SBSW_CAN_LL07 */
    CanLL_WriteReg32( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->FNBTR, Can_GetInitBTFast(initPara->initObject), 0x00007FFFUL, initPara);    /* SBSW_CAN_LL07 */
    CanLL_WriteReg32( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NTDCR, Can_GetInitTDCO(initPara->initObject), 0x00008F00UL, initPara);      /* SBSW_CAN_LL07 */
    CanLL_WriteReg32( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NBTR, Can_GetInitBT(initPara->initObject), 0xFDF8F3FUL, initPara);          /* SBSW_CAN_LL07 */
# if defined( C_ENABLE_FD_NISO )  /* COV_NISO_PED */
    CAN_NODE_PTR(0)->NBTR |= 0x00008000UL; /* first node enables NISO for all nodes */
# endif
# if defined( C_ENABLE_FD_PED )   /* COV_NISO_PED */
    CAN_NODE_PTR(1)->NBTR |= 0x00008000UL; /* second node enables PED for all nodes */
# endif
  }
  else
#endif
  { /* #30 Setup node for classic communication */
    CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NCR, ( C_NCR_CCE | C_NCR_INIT ), 0x03FFU, initPara);                        /* SBSW_CAN_LL07 */
    CanLL_WriteReg32( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NBTR, Can_GetInitBT(initPara->initObject), 0x0000FFFFUL, initPara);         /* SBSW_CAN_LL07 */
  }
  
  /* #40 configure interrupt handling in one ISR */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NIPR, (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu) | (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu)<<4) | (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu)<<8) | (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu)<<12)), 0xFFFFU, initPara); /* SBSW_CAN_LL07 */
  /* #50 enable ports and reset error counter */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NPCR, (vuint16)Can_GetInitPortSel(canHwChannel), 0x0107u, initPara); /* SBSW_CAN_LL07 */
  CanLL_WriteReg8(  CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NECnt_Rec, 0x00u, 0xFFu, initPara);                                  /* SBSW_CAN_LL07 */
  CanLL_WriteReg8(  CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NECnt_Tec, 0x00u, 0xFFu, initPara);                                  /* SBSW_CAN_LL07 */
  CanLL_WriteReg8(  CAN_CHANNEL_CANPARA_FIRST &pCanCellNode->NECnt_EWRNLVL, 0x60u, 0xFFu, initPara);                              /* SBSW_CAN_LL07 */
  return(kCanOk);
}
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitMailboxTx
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxTx
Relation_Context:
# CanHL_InitTxFullCAN() #
OneChOpt, ChannelAmount
# CanHL_InitTxBasicCAN() #
OneChOpt, ChannelAmount
Relation:
TxFullCANSupport
MultiplexedTx
CanFdSupport
IndividualPolling, TxPolling
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxTx( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  vuint8 retVal;
  CanModuleStructPtr pCanCellModule;
  CanMsgObjStructPtr pCanCellMailbox;
  CanObjectHandle hwObjHandle, hwObjStep;
  pCanCellModule = CAN_MODULE_PTR;
  retVal = kCanOk;

#if defined(C_ENABLE_CAN_FD_FULL)
  hwObjStep = (vuint8)((Can_GetMailboxDataLen(initPara->mailboxHandle) > 8u) ? 3 : 1); /* COV_CAN_BASICCAN_FULLCAN_FD_DATA_LEN_DIFFER */
#else
  hwObjStep = 1;
#endif
  for (hwObjHandle = initPara->hwObjHandle; hwObjHandle < Can_GetHwHandleStopOfMailbox(initPara->mailboxHandle); hwObjHandle+=hwObjStep)
  {
    pCanCellMailbox = CAN_MAILBOX_PTR(hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
    /* #10 reset mailbox (clear MSGVAL before alloc to list) */
    CanLL_Reset_MoCtr( &pCanCellMailbox->MoCtrL, C_MOCTR_ALL, 0x0FFFu, initPara ); /* SBSW_CAN_LL07 */
  
    if ( (Can_GetLogStatus(channel) & kCanHwIsInit) == 0u ) /* only in power on init */
    { /* #20 add mailbox to list for current node */
      retVal &= CanLL_SetListCmd(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule, (Can_GetNodeNum(canHwChannel)+1u), hwObjHandle, C_PAN_ALLOC_TO_LIST); /* SBSW_CAN_LL03 */
    }
    CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoIPR, (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu) | (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu)<<4) | (((vuint16)hwObjHandle & 0xFFu)<<8)), 0xFFFFu, initPara); /* SBSW_CAN_LL07 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
    CanLL_Set_MoCtr( &pCanCellMailbox->MoCtrH, (C_MOCTR_MSGVAL | C_MOCTR_TXEN1 | C_MOCTR_DIR), 0x0C20u, initPara ); /* SBSW_CAN_LL07 */
#if defined(C_ENABLE_CAN_FD_FULL)
    if(Can_GetMailboxDataLen(initPara->mailboxHandle) <= 8u)   /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
#endif
    { /* #30 configure mailbox as classic */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_BOT, (vuint8)hwObjHandle, 0xFFu, initPara);   /* SBSW_CAN_LL07 */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_TOP, (vuint8)hwObjHandle, 0xFFu, initPara);   /* SBSW_CAN_LL07 */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_CUR, (vuint8)hwObjHandle, 0xFFu, initPara);   /* SBSW_CAN_LL07 */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_SEL, (vuint8)hwObjHandle, 0xFFu, initPara);   /* SBSW_CAN_LL07 */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_Mode, C_MOFCR_MODE_NORMAL, 0x0Fu, initPara);  /* SBSW_CAN_LL07 */
    }
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_IE, 0x00u, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
#if defined (C_ENABLE_INDIVIDUAL_POLLING)
    if ( !Can_IsMailboxIndivPolling(initPara->mailboxHandle) ) /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
#endif
#if defined (C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_TX_POLLING)
    {
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_IE, C_MOFCR_IE_TX, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    }
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
    if(Can_GetMailboxDataLen(initPara->mailboxHandle) > 8u) /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
    { /* #40 configure mailbox as FD */
      vuint8 index;
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_BOT, (vuint8)(hwObjHandle+1u), 0xFFu, initPara);   /* SBSW_CAN_LL07 */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_TOP, (vuint8)(hwObjHandle+2u), 0xFFu, initPara);   /* SBSW_CAN_LL07 */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_CUR, (vuint8)hwObjHandle, 0xFFu, initPara);       /* SBSW_CAN_LL07 */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_SEL, (vuint8)hwObjHandle, 0xFFu, initPara);       /* SBSW_CAN_LL07 */
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_Mode, C_MOFCR_MODE_FDBASE, 0x0Fu, initPara);  /* SBSW_CAN_LL07 */
    
      for (index=0; index < 2u; index++)
      {
        pCanCellMailbox = CAN_MAILBOX_PTR(hwObjHandle+index+1u); /* PRQA S 2985 */ /* MD_Can_ConstValue */
        /* #50 reset mailbox (clear MSGVAL before alloc to list) */
        CanLL_Reset_MoCtr( &pCanCellMailbox->MoCtrL, C_MOCTR_ALL, 0x0FFFu, initPara ); /* SBSW_CAN_LL07 */
        if ( (Can_GetLogStatus(channel) & kCanHwIsInit) == 0u ) /* only in power on init */
        { /* #60 add data objects of mailbox to list for current node */
          retVal &= CanLL_SetListCmd(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule, 0u, (hwObjHandle+index+1u), C_PAN_ALLOC_TO_LIST); /* move to unused channel */ /* SBSW_CAN_LL03 */
        }
        CanLL_Set_MoCtr( &pCanCellMailbox->MoCtrH, C_MOCTR_MSGVAL, 0x0020u, initPara ); /* SBSW_CAN_LL07 */
      }
    }
#endif
  }
  return(retVal);
}
/* CODE CATEGORY 4 END */

# if (defined( C_ENABLE_CAN_RAM_CHECK ))
/**********************************************************************************************************************
 *  CanLL_InitMailboxTxDeactivate
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxTxDeactivate
Relation_Context:
# CanHL_InitTxFullCAN() #
OneChOpt, ChannelAmount
# CanHL_InitTxBasicCAN() #
OneChOpt, ChannelAmount
Relation:
TxFullCANSupport, RamCheck
MultiplexedTx, RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxTxDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */ /* COV_CAN_RAM_CHECK_NO_STIMULATION */
{
  CanObjectHandle hwObjHandle, hwObjStep;
#if defined(C_ENABLE_CAN_FD_FULL)
  hwObjStep = (vuint8)((Can_GetMailboxDataLen(initPara->mailboxHandle) > 8u) ? 3 : 1); /* COV_CAN_BASICCAN_FULLCAN_FD_DATA_LEN_DIFFER */
#else
  hwObjStep = 1;
#endif
  for (hwObjHandle = initPara->hwObjHandle; hwObjHandle < Can_GetHwHandleStopOfMailbox(initPara->mailboxHandle); hwObjHandle+=hwObjStep)
  { /* #10 disable mailbox object */
    CAN_MAILBOX_PTR(hwObjHandle)->MoCtrL = C_MOCTR_MSGVAL; /* SBSW_CAN_LL06 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  }
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 4 END */
# endif


#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxFullCan
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxRxFullCan
Relation_Context:
# CanHL_InitRxFullCAN() #
OneChOpt, ChannelAmount, RxFullCANSupport
Relation:
CanFdSupport
IDType, RxPolling
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxFullCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  vuint8 retVal;
  CanModuleStructPtr pCanCellModule;
  CanMsgObjStructPtr pCanCellMailbox;
  pCanCellModule = CAN_MODULE_PTR;
  pCanCellMailbox = CAN_MAILBOX_PTR(initPara->hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  retVal = kCanOk;
  /* #10 reset mailbox (clear MSGVAL before alloc to list) */
  CanLL_Reset_MoCtr( &pCanCellMailbox->MoCtrL, C_MOCTR_ALL, 0x0FFFu, initPara ); /* SBSW_CAN_LL07 */
  if ( (Can_GetLogStatus(channel) & kCanHwIsInit) == 0u ) /* only in power on init */
  { /* #20 add mailbox to list for current node */
    retVal = CanLL_SetListCmd(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule, (Can_GetNodeNum(canHwChannel)+1u), initPara->hwObjHandle, C_PAN_ALLOC_TO_LIST); /* SBSW_CAN_LL03 */
  }
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoIPR, (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu) | (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu)<<4) | (((vuint16)initPara->hwObjHandle & 0xFFu)<<8)), 0xFFFFu, initPara); /* SBSW_CAN_LL07 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  CanLL_Set_MoCtr( &pCanCellMailbox->MoCtrH, (C_MOCTR_MSGVAL | C_MOCTR_RXEN), 0x00A0u, initPara ); /* SBSW_CAN_LL07 */
  {
    CanLL_WriteReg32( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAMR.reg32, (C_EID_MASK_32 | C_MOAMR_CLOSE), 0x3FFFFFFFUL, initPara ); /* SBSW_CAN_LL07 */
  }
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAR.reg16[1], initPara->idRaw0, 0x3FFFu, initPara ); /* SBSW_CAN_LL07 */
# if defined( C_ENABLE_EXTENDED_ID )  /* COV_CAN_EXTENDED_ID */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAR.reg16[0], initPara->idRaw1, 0xFFFFu, initPara ); /* SBSW_CAN_LL07 */
# endif
# if defined(C_ENABLE_CAN_FD_FULL)
  if(Can_GetMailboxDataLen(initPara->mailboxHandle) <= 8u)
# endif
  { /* #30 configure mailbox as classic */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_BOT, (vuint8)initPara->hwObjHandle, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_TOP, (vuint8)initPara->hwObjHandle, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_CUR, (vuint8)initPara->hwObjHandle, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_SEL, (vuint8)initPara->hwObjHandle, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_Mode, C_MOFCR_MODE_NORMAL, 0x0Fu, initPara);  /* SBSW_CAN_LL07 */
  }
  CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_IE, 0x00u, 0xFFu, initPara); /* SBSW_CAN_LL07 */
# if defined (C_ENABLE_INDIVIDUAL_POLLING)
  if ( !Can_IsMailboxIndivPolling(initPara->mailboxHandle) ) /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
# endif
# if defined (C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_RX_FULLCAN_POLLING)
  {
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_IE, C_MOFCR_IE_RX, 0xFFu, initPara); /* SBSW_CAN_LL07 */
  }
# endif
# if defined(C_ENABLE_CAN_FD_FULL)
  if(Can_GetMailboxDataLen(initPara->mailboxHandle) > 8u)
  { /* #40 configure mailbox as FD */
    vuint8 index;
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_BOT, (vuint8)(initPara->hwObjHandle+1u), 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_TOP, (vuint8)(initPara->hwObjHandle+2u), 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_CUR, (vuint8)initPara->hwObjHandle, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_SEL, (vuint8)initPara->hwObjHandle, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_Mode, C_MOFCR_MODE_FDBASE, 0x0Fu, initPara);  /* SBSW_CAN_LL07 */

    for (index=0; index < 2u; index++)
    {
      pCanCellMailbox = CAN_MAILBOX_PTR(initPara->hwObjHandle+index+1u); /* PRQA S 2985 */ /* MD_Can_ConstValue */
      CanLL_Reset_MoCtr( &pCanCellMailbox->MoCtrL, C_MOCTR_ALL, 0x0FFFu, initPara ); /* SBSW_CAN_LL07 */
      if ( (Can_GetLogStatus(channel) & kCanHwIsInit) == 0u ) /* only in power on init */
      { /* #50 add data objects of mailbox to list for current node */
        retVal &= CanLL_SetListCmd(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule, 0, (initPara->hwObjHandle+index+1u), C_PAN_ALLOC_TO_LIST); /* move to unused channel */ /* SBSW_CAN_LL03 */
      }
      CanLL_Set_MoCtr( &pCanCellMailbox->MoCtrH, (C_MOCTR_MSGVAL | C_MOCTR_RXEN), 0x00A0u, initPara ); /* configure as Rx */ /* SBSW_CAN_LL07 */
    }
  }
# endif
  return(retVal);
}
/* CODE CATEGORY 4 END */

# if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxFullCanDeactivate
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxRxFullCanDeactivate
Relation_Context:
# CanHL_InitRxFullCAN() #
OneChOpt, ChannelAmount, RxFullCANSupport, RamCheck
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxRxFullCanDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */ /* COV_CAN_RAM_CHECK_NO_STIMULATION */
{ /* #10 disable mailbox object */
  CAN_MAILBOX_PTR(initPara->hwObjHandle)->MoCtrL = C_MOCTR_MSGVAL; /* disable object */ /* SBSW_CAN_LL06 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 4 END */
# endif

#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxBasicCan
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxRxBasicCan
Relation_Context:
# CanHL_InitRxBasicCAN() #
Wakeup, OneChOpt, ChannelAmount, RxBasicCANSupport
Relation:
CanFdSupport
IDType, RxPolling
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxBasicCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  vuint8 retVal;
  CanModuleStructPtr pCanCellModule;
  CanMsgObjStructPtr pCanCellMailbox;
  CanObjectHandle hwObjHandle, hwObjStep;
  pCanCellModule = CAN_MODULE_PTR;
  retVal = kCanOk;

#if defined(C_ENABLE_CAN_FD_FULL)
  hwObjStep = (vuint8)((Can_GetMailboxDataLen(initPara->mailboxHandle) > 8u) ? 3 : 1); /* COV_CAN_BASICCAN_FULLCAN_FD_DATA_LEN_DIFFER */
#else
  hwObjStep = 1;
#endif
  /* #10 loop through all mailboxes including shadow or FIFO buffer */
  for (hwObjHandle = initPara->hwObjHandle; hwObjHandle < Can_GetHwHandleStopOfMailbox(initPara->mailboxHandle); hwObjHandle+=hwObjStep)
  {
    pCanCellMailbox = CAN_MAILBOX_PTR(hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
    /* #20 reset mailbox (clear MSGVAL before alloc to list) */
    CanLL_Reset_MoCtr( &pCanCellMailbox->MoCtrL, C_MOCTR_ALL, 0x0FFFu, initPara ); /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_IE, 0x00u, 0xFFu, initPara); /* SBSW_CAN_LL07 */

    switch(hwObjHandle-initPara->hwObjHandle)
    {
    case 0:
# if defined(C_ENABLE_CAN_FD_FULL)
      if(Can_GetMailboxDataLen(initPara->mailboxHandle) > 8u) /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
      { /* #30 configure mailbox as FD (first shadow buffer) */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_Mode, C_MOFCR_MODE_FDBASE, 0x0Fu, initPara);  /* SBSW_CAN_LL07 */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_BOT,  ((vuint8)hwObjHandle+1u), 0xFFu, initPara);   /* SBSW_CAN_LL07 */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_TOP,  ((vuint8)hwObjHandle+2u), 0xFFu, initPara);   /* SBSW_CAN_LL07 */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_IE, C_MOFCR_IE_SDT, 0xFFu, initPara); /* SBSW_CAN_LL07 */
      }
      else
# endif
      { /* #40 configure mailbox as classic (FIFO) */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_Mode, C_MOFCR_MODE_RXBASE, 0x0Fu, initPara);  /* SBSW_CAN_LL07 */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_BOT, (vuint8)hwObjHandle, 0xFFu, initPara);  /* SBSW_CAN_LL07 */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_TOP, (vuint8)((hwObjHandle + Can_GetMailboxSize(initPara->mailboxHandle)) - 1u), 0xFFu, initPara);  /* SBSW_CAN_LL07 */
      }
      CanLL_InitRxBasicCANSubSetMask(CAN_CHANNEL_CANPARA_FIRST initPara, hwObjHandle); /* SBSW_CAN_HL31 */
      CanLL_Set_MoCtr( &pCanCellMailbox->MoCtrH, C_MOCTR_RXEN, 0x00A0u, initPara ); /* SBSW_CAN_LL07 */
      break;
    case 3: /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
# if defined(C_ENABLE_CAN_FD_FULL)
      if(Can_GetMailboxDataLen(initPara->mailboxHandle) > 8u)  /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
      { /* #50 configure mailbox as FD (second shadow buffer) */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_Mode, C_MOFCR_MODE_FDBASE, 0x0Fu, initPara);  /* SBSW_CAN_LL07 */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_BOT, ((vuint8)hwObjHandle+1u), 0xFFu, initPara);   /* SBSW_CAN_LL07 */
        CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_TOP, ((vuint8)hwObjHandle+2u), 0xFFu, initPara);   /* SBSW_CAN_LL07 */
        CanLL_InitRxBasicCANSubSetMask(CAN_CHANNEL_CANPARA_FIRST initPara, hwObjHandle); /* SBSW_CAN_HL31 */
        CanLL_Set_MoCtr( &pCanCellMailbox->MoCtrH, C_MOCTR_RXEN, 0x00A0u, initPara ); /* SBSW_CAN_LL07 */
      }
      else
# endif /* C_ENABLE_CAN_FD_FULL */
      {
        CanLL_Set_MoCtr( &pCanCellMailbox->MoCtrH, C_MOCTR_MSGVAL, 0x0020u, initPara ); /* SBSW_CAN_LL07 */
      }
      break;
    default: /* COV_CAN_NO_BASICCAN_FIFO_HANDLING */
      CanLL_InitRxBasicCANSubCloseMask(CAN_CHANNEL_CANPARA_FIRST initPara, hwObjHandle); /* SBSW_CAN_HL31 */
      break;
    } /* switch */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_CUR,  (vuint8)hwObjHandle, 0xFFu, initPara);       /* SBSW_CAN_LL07 */
    CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFGPR_SEL,  (vuint8)hwObjHandle, 0xFFu, initPara);       /* SBSW_CAN_LL07 */

    if ( (Can_GetLogStatus(channel) & kCanHwIsInit) == 0u ) /* only in power on init */
    {
      /* #60 add mailbox to list for current node */
      retVal &= CanLL_SetListCmd(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule, (Can_GetNodeNum(canHwChannel)+1u), hwObjHandle, C_PAN_ALLOC_TO_LIST); /* SBSW_CAN_LL03 */
    }
    CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoIPR, (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu) | (((vuint16)Can_GetSrcNum(canHwChannel) & 0x0Fu)<<4) | (((vuint16)hwObjHandle & 0xFFu)<<8)), 0xFFFFu, initPara); /* SBSW_CAN_LL07 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
# if defined (C_ENABLE_INDIVIDUAL_POLLING)
    if ( !Can_IsMailboxIndivPolling(initPara->mailboxHandle) )  /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
# endif
# if defined (C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_RX_BASICCAN_POLLING)
    { /* #70 enable Rx interrupt */
      vuint8 mofcr_ie = pCanCellMailbox->MoFCR_IE | C_MOFCR_IE_RX;
      CanLL_WriteReg8( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoFCR_IE, mofcr_ie, 0xFFu, initPara); /* SBSW_CAN_LL07 */
    }
# endif
    /* #80 activate mailbox */
    CanLL_Set_MoCtr( &pCanCellMailbox->MoCtrH, C_MOCTR_MSGVAL, 0x0020u, initPara ); /* SBSW_CAN_LL07 */
  }
  return(retVal);
}
/* CODE CATEGORY 4 END */

# if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxBasicCanDeactivate
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxRxBasicCanDeactivate
Relation_Context:
# CanHL_InitRxBasicCAN() #
Wakeup, OneChOpt, ChannelAmount, RxBasicCANSupport, RamCheck
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxRxBasicCanDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */ /* COV_CAN_RAM_CHECK_NO_STIMULATION */
{
  CanObjectHandle hwObjHandle, hwObjStep;
#if defined(C_ENABLE_CAN_FD_FULL)
  hwObjStep = (vuint8)((Can_GetMailboxDataLen(initPara->mailboxHandle) > 8u) ? 3 : 1); /* COV_CAN_BASICCAN_FULLCAN_FD_DATA_LEN_DIFFER */
#else
  hwObjStep = 1;
#endif
  for (hwObjHandle = initPara->hwObjHandle; hwObjHandle < Can_GetHwHandleStopOfMailbox(initPara->mailboxHandle); hwObjHandle+=hwObjStep)
  { /* #10 disable mailbox object */
    CAN_MAILBOX_PTR(hwObjHandle)->MoCtrL = C_MOCTR_MSGVAL; /* SBSW_CAN_LL06 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  }
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 4 END */
# endif
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */


/**********************************************************************************************************************
 *  CanLL_InitEndSetRegisters
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitEndSetRegisters
Relation_Context:
# CanHL_InitEnd_InitMode() #
Wakeup, OneChOpt, ChannelAmount
Relation:
IndividualPolling, TxPolling, RxPolling
StatusPolling
WakeupPolling
CanInterruptControl, MultipleCanCells
ProtectedMode
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEndSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint8 index;

  /* #10 delete all pending messages for this channel */
  for (index=0; index < CAN_MSPND_AMOUNT; index++)
  {
    CAN_MODULE_PTR->MSPND[index] = ~((vuint32)Can_GetGlobalInterruptPendingMask((canHwChannel*CAN_MSPND_AMOUNT_MAX) + index)); /* SBSW_CAN_LL03 */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
    /* only set by HW */
  }

  /* #20 set interrupt prio and enable interrupt */
#if defined(C_ENABLE_CAN_INTERRUPT_CONTROL) /* COV_CAN_INTERRUPT_CONTROL */
  if ( (Can_GetLogStatus(channel) & kCanHwIsInit) == 0u ) /* only in power on init */
  {
# if defined(C_ENABLE_MULTIPLE_CELLS) && !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
    vuint8 canll_channel_offset;
    if (Can_GetCellInfoIdxOfCell(canHwChannel) == CAN_MULTICAN)
    { /* CAN_MULTICAN  physical node 0..7 */
      canll_channel_offset = 0u;
    }
    else
    { /* CAN_MULTICANR physical node 8..15 */
      canll_channel_offset = CAN_MULTICANR_CH_OFFSET;
    }
# endif
    /* else canll_channel_offset is a global define with a constant value */
# if defined( C_LL_INTERRUPT_ISR_ACTIVE ) /* ! pure polling configuration */
#  if defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
    /* #30 enable Service and clear pending IR, IR prio will not be written in case of OS IR Control */
    (void)osEnableInterruptSource(Can_GetIsrOsId(canHwChannel), TRUE);
#  else    
    assertInternal((vuint32)Can_GetPhysPrio(Can_GetNodeNum(canHwChannel) + canll_channel_offset) != 0u, channel, kErrorUnknownISRPriority); /* PRQA S 2985 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_FAILURE */
    CAN_WRITE_PROTECTED_REG32(CAN_PROTECTED_AREA_SRC, CAN_SRC_ADR(canHwChannel), (C_SRC_SRE | C_SRC_CLRR | (vuint32)Can_GetPhysPrio(Can_GetNodeNum(canHwChannel) + canll_channel_offset))); /* SBSW_CAN_LL09 */ /* PRQA S 0303, 2985 */ /* MD_Can_HwAccess, MD_Can_ConstValue */
#  endif  
# endif
  }
#endif /* C_ENABLE_CAN_INTERRUPT_CONTROL */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(kCanOk);
}
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitEnd
Relation_Context:
# CanHL_InitEnd_InitMode() #
Wakeup, OneChOpt, ChannelAmount
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(kCanOk);
}
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_RAM_CHECK )
/**********************************************************************************************************************
 *  CanLL_InitIsMailboxCorrupt
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitIsMailboxCorrupt
Relation_Context:
# CanHL_InitXXX() #
Wakeup, OneChOpt, ChannelAmount
TxFullCANSupport, RamCheck
RxFullCANSupport, RamCheck
RxBasicCANSupport, RamCheck
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_InitIsMailboxCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint8 index, result;
  CanMsgObjStructPtr pCanCellMailbox;
  pCanCellMailbox = CAN_MAILBOX_PTR(initPara->hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  result = kCanFalse; /* PRQA S 2982 */ /* MD_MSR_RetVal */

  /* at this point the mailbox is not initialized therefore the contents are not saved! */
  {
    /* #10 Iterate test patterns */
    for(index = 0; index < 3u; index++)
    {
      vuint8  var_MoFCR_DLC;
      vuint32 var_MoAR;
      vuint32 var_MoDR[2];

      /* write Id, DLC, data registers with CanMemCheckValues..bit[index] and verify the content */ 
      /* #20 DLC and IDE register check */
      pCanCellMailbox->MoFCR_DLC = CanMemCheckValues8bit[index] & C_MOFCR_DLC; /* SBSW_CAN_LL06 */
      /* #30 ID register check */
      pCanCellMailbox->MoAR.reg32 = CanMemCheckValues32bit[index];             /* SBSW_CAN_LL06 */
      var_MoFCR_DLC  = pCanCellMailbox->MoFCR_DLC;
      var_MoAR       = pCanCellMailbox->MoAR.reg32;
      /* #40 Data register check */
      pCanCellMailbox->MoDR[0] = CanMemCheckValues32bit[index];                /* SBSW_CAN_LL06 */
      pCanCellMailbox->MoDR[1] = CanMemCheckValues32bit[index];                /* SBSW_CAN_LL06 */
      var_MoDR[0] = pCanCellMailbox->MoDR[0];                                  /* SBSW_CAN_LL13 */
      var_MoDR[1] = pCanCellMailbox->MoDR[1];                                  /* SBSW_CAN_LL13 */
      /* #50 Check if register values are valid */
      if( (var_MoFCR_DLC != (CanMemCheckValues8bit[index]  & C_MOFCR_DLC) ) ||
          (var_MoAR      != CanMemCheckValues32bit[index] )                 ||
          (var_MoDR[0]   != CanMemCheckValues32bit[index])                  ||
          (var_MoDR[1]   != CanMemCheckValues32bit[index]) )                  /* COV_CAN_HARDWARE_FAILURE */
      {
        result = kCanTrue; /* PRQA S 2982 */ /* MD_MSR_RetVal */
      }
    }
  }
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  CAN_RAM_CHECK_READ_BACK_RESULT(channel)
# endif
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(result);
}
/* CODE CATEGORY 4 END */
#endif /* C_ENABLE_CAN_RAM_CHECK */


/**********************************************************************************************************************
 *  CanLL_InitPowerOn
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitPowerOn
Relation_Context:
# from Can_Init #
Relation:
OneChOpt
ProtectedMode
MultipleCanCells
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOn(void)
{
  CAN_HW_CHANNEL_CANTYPE_LOCAL
  CanCellStructPtr pCanCell;
  CanModuleStructPtr pCanCellModule;
  CanNodeStructPtr  pCanCellNode;
  vuint8 retVal, channelIdx, maxUsedNodes;
  vuint16 area;

#if defined (C_ENABLE_MULTIPLE_CELLS)
  vuint8 cell;
  canCellDbgPtr0 = (CanCellStructPtr)Can_GetBaseAdrOfCellInfo(CAN_MULTICAN); /* PRQA S 0303 */ /* MD_Can_HwAccess */
  canCellDbgPtr1 = (CanCellStructPtr)Can_GetBaseAdrOfCellInfo(CAN_MULTICANR); /* PRQA S 0303 */ /* MD_Can_HwAccess */
#else
  canCellDbgPtr =  (CanCellStructPtr)kCanBaseAdr; /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif
  retVal = kCanOk;
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = 0;
#endif

#if defined(C_ENABLE_MULTIPLE_CELLS)
  for (cell=0; cell<2u; cell++)
  {   /* #10 iterate over cells */
    pCanCell = ((CanCellStructPtr)Can_GetBaseAdrOfCellInfo(cell)); /* PRQA S 0303 */ /* MD_Can_HwAccess */
    maxUsedNodes = Can_GetMaxHwNodeAmountOfCellInfo(cell);
    area = ((cell == CAN_MULTICAN)?CAN_PROTECTED_AREA_ENDINIT:CAN_PROTECTED_AREA_ENDINIT_MULTICANR);
#else /* #20 single cell */
  {
    pCanCell = ((CanCellStructPtr)kCanBaseAdr); /* PRQA S 0303 */ /* MD_Can_HwAccess */
    maxUsedNodes = CAN_MAX_NUM_NODE;
//    area = CAN_PROTECTED_AREA_ENDINIT;
#endif
    pCanCellModule = (CanModuleStructPtr) &pCanCell->Module;

#if defined(C_ENABLE_MULTIPLE_DRIVERS) /* COV_CAN_MULTIPLE_DRIVERS */
    maxUsedNodes = kCanNumberOfChannels;
    for (channelIdx=0; channelIdx < maxUsedNodes; channelIdx++)
    {
      /* #30 deactivate only used channels and activate in CanInit() */
      pCanCellNode = ((CanNodeStructPtr) &pCanCell->Node[Can_GetNodeNum(channelIdx)])
      pCanCellNode->NCR = C_NCR_CCE | C_NCR_INIT; /* SBSW_CAN_LL01 */
    }
#else /* #40 Single driver handling */
    CAN_SFR_PROTECT_OFF();
    CAN_WRITE_PROTECTED_REG16(area, &pCanCell->Ctrl.CLC, C_CLC_ENABLE); /* start CAN-clock / disable sleep */ /* SBSW_CAN_LL04 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    canLLTempRead = canCellPtr->Ctrl.CLC; /* needed before write to FDR -> workaround */
# if defined(CanClockDividor) /* COV_CAN_CANCLOCKDIVIDOR */
    CAN_WRITE_PROTECTED_REG32(area, &pCanCell->Ctrl.FDR, CanClockDividor); /* set divider for baudrate-clock */ /* SBSW_CAN_LL04 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# else
    CAN_WRITE_PROTECTED_REG32(area, &pCanCell->Ctrl.FDR, CanClockDividor[0]); /* preset divider */ /* SBSW_CAN_LL04 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
    CAN_SFR_PROTECT_ON();
    /* Workaround for high frequency clock to ensure FDR write */
    retVal &= CanLL_WaitForListReady(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule); /* reset list finished (< 50 Fsys-clk) */ /* SBSW_CAN_LL03 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */

    for (channelIdx=0; channelIdx < maxUsedNodes; channelIdx++)
    { /* #50 reset list needs Init-mode for all nodes. Deactivate all channel and activate in CanInit() */
      pCanCellNode = ((CanNodeStructPtr) &pCanCell->Node[channelIdx]);
      pCanCellNode->NCR = C_NCR_CCE | C_NCR_INIT; /* SBSW_CAN_LL01 */
    }
    
    retVal &= CanLL_SetListCmd(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule, 0, 0, C_PAN_RESET_LIST); /* default list init */ /* SBSW_CAN_LL03 */
    retVal &= CanLL_WaitForListReady(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule); /* reset list finished (< 50 Fsys-clk) */ /* SBSW_CAN_LL03 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
    pCanCellModule->MCR = C_MCR_INIT_CLOCK; /* SBSW_CAN_LL03 */
# if defined( kCanMCRValue ) /* since MultiCAN+, 2 steps are necessary (first clear selection, second set new clock) */ /* COV_CAN_MCR */
    ApplCanWaitSetMCR();
    pCanCellModule->MCR = (vuint16)kCanMCRValue; /* after all CCE are set */ /* SBSW_CAN_LL03 */
# endif
#endif
  }

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
  CanNumberOfMaxBasicCAN = 0;
#endif
# if !defined( C_ENABLE_USER_MODE_OS )
  CAN_DUMMY_STATEMENT(area); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return (retVal);
}
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitPowerOnChannelSpecific
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitPowerOnChannelSpecific
Relation_Context:
# from Can_Init #
Relation:
ChannelAmount, OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOnChannelSpecific(CAN_CHANNEL_CANTYPE_ONLY)
{
#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
  if ( Can_GetRxBasicHandleMax(channel) > CanNumberOfMaxBasicCAN ) /* COV_CAN_GENDATA_FAILURE */
  { /* #10 calculate total max number of basic can */
    CanNumberOfMaxBasicCAN = (Can_HwHandleType)Can_GetRxBasicHandleMax(channel);
  }
#endif

  CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (kCanOk);
}
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitMemoryPowerOn
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMemoryPowerOn
Relation_Context:
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMemoryPowerOn(void)
{ /* #10 nothing to do */
}
/* CODE CATEGORY 4 END */




/**********************************************************************************************************************
 *  CanLL_TxBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxBegin
Relation_Context:
# from Can_Write #
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara)
{ /* #10 calculate hwObjHandle */
# if defined(C_ENABLE_CAN_FD_FULL)
  if(Can_GetMailboxDataLen(txPara->mailboxHandle) > 8u) /* COV_CAN_BASICCAN_FULLCAN_FD_DATA_LEN_DIFFER */
  {
    txPara->hwObjHandle += txPara->mailboxElement * 3u; /* SBSW_CAN_LL11 */
  }
  else
# endif
  {
    txPara->hwObjHandle += txPara->mailboxElement; /* SBSW_CAN_LL11 */
  }
  /* #20 delete enable flag */
  CAN_MAILBOX_PTR(txPara->hwObjHandle)->MoCtrL = C_MOCTR_TXEN0; /* SBSW_CAN_LL06 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_TxSetMailbox
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxSetMailbox
Relation_Context:
# from Can_Write #
Relation:
IDType
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 fill mailbox with txPara data */
  CanMsgObjStructPtr pCanCellMailbox;
  pCanCellMailbox = CAN_MAILBOX_PTR(txPara->hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  pCanCellMailbox->MoAR.reg16[1] = txPara->idRaw0; /* SBSW_CAN_LL06 */
# if defined( C_ENABLE_EXTENDED_ID )   /* COV_CAN_EXTENDED_ID */
  pCanCellMailbox->MoAR.reg16[0] = txPara->idRaw1; /* SBSW_CAN_LL06 */
# endif
  pCanCellMailbox->MoFCR_DLC = txPara->dlcRaw & C_MOFCR_DLC; /* SBSW_CAN_LL06 */
# if defined( C_ENABLE_CAN_FD_USED )
  {
    vuint8 mode = txPara->fdType | txPara->fdBrsType;
#  if defined(C_ENABLE_CAN_FD_FULL)
    if((txPara->dlcRaw & C_MOFCR_DLC)>8u)
    {
      mode |= C_MOFCR_MODE_FDBASE;
    }
#  endif
    pCanCellMailbox->MoFCR_Mode = mode; /* configure mode */ /* SBSW_CAN_LL06 */
  }
# endif
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */


/**********************************************************************************************************************
 *  CanLL_TxCopyToCan
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxCopyToCan
Relation_Context:
Relation_Context:
# from Can_Write #
Relation:
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{  /* - do not copy data with 32bit access because of failure with GNU compiler
  - do not use 32bit copy because of possible 8bit alignment for application data */
  vuint8 index;
  CanMsgObjStructPtr pCanCellMailbox;
  /* #10 copy data to mailbox */
  pCanCellMailbox = CAN_MAILBOX_PTR(txPara->hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  for (index = 0; index < 8u; index++)
  {
    ((CanChipDataSfrPtr) &pCanCellMailbox->MoDR[0])[index] = txPara->CanMemCopySrcPtr[index]; /* SBSW_CAN_LL05 */
  }
#  if defined( C_ENABLE_CAN_FD_FULL )
  if (txPara->messageLen > 36u)
  {
    CanLL_WriteFdData(CAN_FD_MAILBOX_PTR(txPara->hwObjHandle+1u), &txPara->CanMemCopySrcPtr[8], txPara->paddingVal, 28u); /* SBSW_CAN_LL14 */ /* PRQA S 0310, 2985 */ /* MD_Can_PointerCast, MD_Can_ConstValue */
    CanLL_WriteFdData(CAN_FD_MAILBOX_PTR(txPara->hwObjHandle+2u), &txPara->CanMemCopySrcPtr[36], txPara->paddingVal, txPara->messageLen-36u); /* SBSW_CAN_LL14 */ /* PRQA S 0310, 2985 */ /* MD_Can_PointerCast, MD_Can_ConstValue */
  }
  else if(txPara->messageLen > 8u) /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */
  {
    CanLL_WriteFdData(CAN_FD_MAILBOX_PTR(txPara->hwObjHandle+1u), &txPara->CanMemCopySrcPtr[8], txPara->paddingVal, txPara->messageLen-8u); /* SBSW_CAN_LL14 */ /* PRQA S 0310, 2985 */ /* MD_Can_PointerCast, MD_Can_ConstValue */
    CanLL_WriteFdData(CAN_FD_MAILBOX_PTR(txPara->hwObjHandle+2u), &txPara->CanMemCopySrcPtr[36], txPara->paddingVal, 0u); /* SBSW_CAN_LL14 */ /* PRQA S 0310, 2985 */ /* MD_Can_PointerCast, MD_Can_ConstValue */
  }
#  endif
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_TxStart
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxStart
Relation_Context:
# from Can_Write #
Relation:
CanFdSupport, IDType
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 start transmission */
  CanMsgObjStructPtr pCanCellMailbox;
  pCanCellMailbox = CAN_MAILBOX_PTR(txPara->hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  pCanCellMailbox->MoCtrL = C_MOCTR_RTSEL; /* delete sel bit */  /* SBSW_CAN_LL06 */
  pCanCellMailbox->MoCtrH = C_MOCTR_TXEN0 | C_MOCTR_TXEN1 | C_MOCTR_TXREQ | C_MOCTR_NEWDAT; /* SBSW_CAN_LL06 */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(kCanOk);
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_TxEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxEnd
Relation_Context:
# from Can_Write #
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(txPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

#if defined( C_ENABLE_TX_POLLING )
/**********************************************************************************************************************
 *  CanLL_TxProcessPendings
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxProcessPendings
Relation_Context:
# from Can_MainFunction_Write #
TxPolling, TxFullCANSupport
Relation:
MultiplexedTx
TxBasicAmount
TxFullAmount
ChannelAmount
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  CanObjectHandle hwObjHandle, hwObjStep;
# if defined(C_ENABLE_CAN_FD_FULL)
  hwObjStep = (vuint8)((Can_GetMailboxDataLen(taskPara->mailboxHandle) > 8u) ? 3 : 1); /* COV_CAN_BASICCAN_FULLCAN_FD_DATA_LEN_DIFFER */
# else
  hwObjStep = 1;
# endif
  for (hwObjHandle = taskPara->hwObjHandle; hwObjHandle < Can_GetHwHandleStopOfMailbox(taskPara->mailboxHandle); hwObjHandle+=hwObjStep)
  { /* #10 for pending tx call TxConfirmation */
    if( (CAN_MAILBOX_PTR(hwObjHandle)->MoCtrL & C_MOCTR_TXPND) == C_MOCTR_TXPND ) /* PRQA S 2985 */ /* MD_Can_ConstValue */
    {
      CanHL_TxConfirmationPolling(CAN_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, Can_GetMailboxElement(hwObjHandle, canHwChannel), hwObjHandle);
    }
  }
}
/* CODE CATEGORY 2 END */
#endif /* C_ENABLE_TX_POLLING */

/**********************************************************************************************************************
 *  CanLL_TxConfBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxConfBegin
Relation_Context:
# from CanHL_TxConfirmation #
Relation:
TxBasicAmount
TxFullAmount
ChannelAmount
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 delete pending */
  CAN_MAILBOX_PTR(txConfPara->hwObjHandle)->MoCtrL = C_MOCTR_TXPND | C_MOCTR_TXEN0; /* SBSW_CAN_LL06 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112, 3206 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */


#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/**********************************************************************************************************************
 *  CanLL_TxConfSetTxConfStruct
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxConfSetTxConfStruct
Relation_Context:
# from CanHL_TxConfirmation #
GenericConfirmation
Relation:
TxBasicAmount
TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara)
{
  CanMsgObjStructPtr pCanCellMailbox;
# if defined(C_ENABLE_CAN_FD_FULL)
  vuint8 messageLen;
# endif
  /* #10 Fill txStructConf with data from HW */
  pCanCellMailbox = CAN_MAILBOX_PTR(txConfPara->hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  txConfPara->txStructConf->pChipMsgObj = (CanChipMsgPtr) &txConfPara->txStructConf->tmpMailbox; /* SBSW_CAN_LL11 */
  txConfPara->txStructConf->tmpMailbox.MoFCR_Mode = pCanCellMailbox->MoFCR_Mode; /* SBSW_CAN_LL11 */
  txConfPara->txStructConf->tmpMailbox.MoFCR_Gate = pCanCellMailbox->MoFCR_Gate; /* SBSW_CAN_LL11 */
  txConfPara->txStructConf->tmpMailbox.MoFCR_IE   = pCanCellMailbox->MoFCR_IE; /* SBSW_CAN_LL11 */
  txConfPara->txStructConf->tmpMailbox.MoFCR_DLC  = pCanCellMailbox->MoFCR_DLC; /* SBSW_CAN_LL11 */
  txConfPara->txStructConf->tmpMailbox.MoAR.reg32 = pCanCellMailbox->MoAR.reg32; /* SBSW_CAN_LL11 */
  txConfPara->txStructConf->pChipData             = (CanChipDataPtr) &txConfPara->txStructConf->tmpMailbox.MoDR[0]; /* SBSW_CAN_LL11 */
  txConfPara->txStructConf->pChipMsgObj->MoDR[0]  = pCanCellMailbox->MoDR[0]; /* SBSW_CAN_LL12 */
  txConfPara->txStructConf->pChipMsgObj->MoDR[1]  = pCanCellMailbox->MoDR[1]; /* SBSW_CAN_LL12 */
# if defined(C_ENABLE_CAN_FD_FULL)
  messageLen = CAN_DLC2LEN(pCanCellMailbox->MoFCR_DLC);
  if(messageLen > 8u)
  {
    CanLL_ReadFdData(CAN_FD_MAILBOX_PTR(txConfPara->hwObjHandle+1u), &txConfPara->txStructConf->pChipMsgObj->MoDR[2]); /* SBSW_CAN_LL14 */ /* PRQA S 0310, 2985 */ /* MD_Can_PointerCast, MD_Can_ConstValue */
  }
  if(messageLen > 36u)
  {
    CanLL_ReadFdData(CAN_FD_MAILBOX_PTR(txConfPara->hwObjHandle+2u), &txConfPara->txStructConf->pChipMsgObj->MoDR[9]); /* SBSW_CAN_LL14 */ /* PRQA S 0310, 2985 */ /* MD_Can_PointerCast, MD_Can_ConstValue */
  }
# endif
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */
#endif

/**********************************************************************************************************************
 *  CanLL_TxConfEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxConfEnd
Relation_Context:
# from CanHL_TxConfirmation #
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(txConfPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */


#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_RxBasicMsgReceivedBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicMsgReceivedBegin
Relation_Context:
# from CanHL_BasicCanMsgReceived #
RxBasicCANSupport
Relation:
HardwareLoopCheck
CanFdSupport
Overrun
OneChOpt
ChannelAmount
RxFullAmount
IDType
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara) /* PRQA S 2889 */ /* MD_Can_MultipleReturn */
{
  CanMsgObjStructPtr pCanCellMailbox;
  vuint8 canPndIdx;
  vuint32 canPndBit;
# if defined(C_ENABLE_CAN_FD_FULL)
#  if defined( C_ENABLE_HW_LOOP_TIMER )
  canHwLoopRetValType canHwLoopRetVal;
#  endif
#  if defined( C_ENABLE_OVERRUN ) 
  vuint8 copy_cnt = 0;
#  endif
# endif
# if defined( C_ENABLE_OVERRUN ) 
  rxBasicPara->isOverrun = kCanFalse; /* SBSW_CAN_LL11 */
# endif
# if defined(C_ENABLE_CAN_FD_FULL)
  if(Can_GetMailboxDataLen(rxBasicPara->mailboxHandle) > 8u) /* COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN */
  { /* #10 FD handling with shadow buffer */
    pCanCellMailbox = CAN_MAILBOX_PTR(rxBasicPara->hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
    canPndIdx = (((vuint8)rxBasicPara->hwObjHandle) >> 5);
    canPndBit = 1UL << (rxBasicPara->hwObjHandle & 0x1Fu);
    if( (pCanCellMailbox->MoCtrL & C_MOCTR_MSGVAL) == 0u )
    { /* #20 First shadow buffer uses SDT, SDT disables mailbox after successful reception */
      pCanCellMailbox->MoCtrL = C_MOCTR_RXPND | C_MOCTR_NEWDAT; /* delete pending flag */ /* SBSW_CAN_LL06 */
      CAN_MODULE_PTR->MSPND[canPndIdx] = ~canPndBit;             /* delete pending interrupt */ /* SBSW_CAN_LL03 */
      CanLL_CopyToTmpRxMailbox(CAN_HW_CHANNEL_CANPARA_FIRST rxBasicPara->hwObjHandle, kCanTrue);
      pCanCellMailbox->MoCtrH = C_MOCTR_MSGVAL; /* enable mailbox */ /* SBSW_CAN_LL06 */
    }
    else
    { /* #30 Second shadow buffer overruns can only happen in this mailbox */
#  if defined( C_ENABLE_HW_LOOP_TIMER )
      CanLL_ApplCanTimerStart(kCanLoopRx); /* SBSW_CAN_HL38 */
#  endif
      do
      { /* repeat reception until consistent data is read, msgval should not be used here */
#  if defined( C_ENABLE_OVERRUN ) 
        copy_cnt++;
#  endif
        pCanCellMailbox->MoCtrL = C_MOCTR_RXPND | C_MOCTR_NEWDAT; /* delete pending flag */ /* SBSW_CAN_LL06 */
        CAN_MODULE_PTR->MSPND[canPndIdx] = ~canPndBit;             /* delete pending interrupt */ /* SBSW_CAN_LL03 */
        CanLL_CopyToTmpRxMailbox(CAN_HW_CHANNEL_CANPARA_FIRST rxBasicPara->hwObjHandle, kCanTrue);
#  if defined( C_ENABLE_HW_LOOP_TIMER )
        canHwLoopRetVal = CanLL_ApplCanTimerLoop(kCanLoopRx);
      } while( ((pCanCellMailbox->MoCtrL & (C_MOCTR_NEWDAT | C_MOCTR_RXUPD)) != 0x0000u) && ((vuint8)canHwLoopRetVal != kCanFailed) ); /* COV_CAN_NOT_STIMULATEABLE */
#  else
      } while( (pCanCellMailbox->MoCtrL & (C_MOCTR_NEWDAT | C_MOCTR_RXUPD)) != 0x0000u ); /* COV_CAN_NOT_STIMULATEABLE */
#  endif
#  if defined( C_ENABLE_HW_LOOP_TIMER )
      CanLL_ApplCanTimerEnd(kCanLoopRx); /* SBSW_CAN_HL38 */
#  endif
#  if defined( C_ENABLE_OVERRUN ) 
      if (copy_cnt > 1u)  /* COV_CAN_DOUBLE_RECEPTION */
      {
        rxBasicPara->isOverrun = kCanTrue; /* SBSW_CAN_LL11 */
      }
#  endif
#  if defined( C_ENABLE_HW_LOOP_TIMER )
      if((vuint8)canHwLoopRetVal == kCanFailed) /* COV_CAN_HARDWARE_FAILURE */
      { /* do not proceed when data is inconsistent (no notification) */
        return kCanFailed;
      }
#  endif
    }
  }
  else
# endif  /* C_ENABLE_CAN_FD_FULL */
  { /* #100 FIFO handling */
    CanMsgObjStructPtr pCanCellFifoBaseMailbox;
    /* rxObjHandle of base object issues the reception */
    pCanCellFifoBaseMailbox = CAN_MAILBOX_PTR(Can_GetMailboxHwHandle(rxBasicPara->mailboxHandle)); /* FIFO base */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
    pCanCellMailbox = CAN_MAILBOX_PTR(pCanCellFifoBaseMailbox->MoFGPR_SEL);      /* FIFO element */ /* PRQA S 2985 */ /* MD_Can_ConstValue */

    while((pCanCellMailbox->MoCtrL & C_MOCTR_RXPND) != C_MOCTR_RXPND)
    { /* #110 get the pending FIFO mailbox */
      CanLL_IncSELPtr(pCanCellFifoBaseMailbox); /* increment the selection pointer */ /* SBSW_CAN_LL06 */
      pCanCellMailbox = CAN_MAILBOX_PTR(pCanCellFifoBaseMailbox->MoFGPR_SEL); /* PRQA S 2985 */ /* MD_Can_ConstValue */
    }
# if (CAN_RX_HW_FIFO_FULL_NOTIFICATION == STD_ON) /* COV_CAN_FIFO_FULL_NOTIFICATION */
    {
      vuint8 mofgpr_cur = pCanCellFifoBaseMailbox->MoFGPR_CUR;
      if (pCanCellFifoBaseMailbox->MoFGPR_SEL == mofgpr_cur)
      {
        ApplCanRxFiFoFull(canHwChannel);
      }
    }
# endif
    canPndIdx = (vuint8)(pCanCellFifoBaseMailbox->MoFGPR_SEL >> 5);
    canPndBit = 1UL << (pCanCellFifoBaseMailbox->MoFGPR_SEL & 0x1Fu);

    pCanCellMailbox->MoCtrL = C_MOCTR_RXPND | C_MOCTR_NEWDAT; /* delete pending flag */ /* SBSW_CAN_LL06 */
    CAN_MODULE_PTR->MSPND[canPndIdx] = ~canPndBit;             /* delete pending interrupt */ /* SBSW_CAN_LL03 */
    CanLL_CopyToTmpRxMailbox(CAN_HW_CHANNEL_CANPARA_FIRST rxBasicPara->hwObjHandle, kCanFalse); /* FIFO has not to consider FD data */
    CanLL_IncSELPtr(pCanCellFifoBaseMailbox); /* SBSW_CAN_LL06 */
  }
# if defined( C_ENABLE_OVERRUN ) 
  if( (pCanCellMailbox->MoCtrL & C_MOCTR_MSGLOST) == C_MOCTR_MSGLOST )
  {
    {
      rxBasicPara->isOverrun = kCanTrue; /* notify overrun */ /* SBSW_CAN_LL11 */
      pCanCellMailbox->MoCtrL = C_MOCTR_MSGLOST; /* delete overrun */  /* SBSW_CAN_LL06 */
    }
  }
# endif
  rxBasicPara->rxStruct.pChipMsgObj = pTmpRxMailboxMsg; /* SBSW_CAN_LL11 */
  rxBasicPara->rxStruct.pChipData = pTmpRxMailboxData;  /* SBSW_CAN_LL11 */
  return kCanOk;
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_RxBasicReleaseObj
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicReleaseObj
Relation_Context:
# from CanHL_BasicCanMsgReceived #
RxBasicCANSupport
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(rxBasicPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_RxBasicMsgReceivedEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicMsgReceivedEnd
Relation_Context:
# from CanHL_BasicCanMsgReceived #
RxBasicCANSupport
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(rxBasicPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

# if defined( C_ENABLE_RX_BASICCAN_POLLING )
/**********************************************************************************************************************
 *  CanLL_RxBasicProcessPendings
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicProcessPendings
Relation_Context:
# from CanHL_RxBasicCanPolling #
RxBasicCANSupport, RxPolling
Relation:
IndividualPolling
OneChOpt
ChannelAmount
RxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  CanObjectHandle hwObjHandle, hwObjStep;
# if defined(C_ENABLE_CAN_FD_FULL)
  hwObjStep = (vuint8)((Can_GetMailboxDataLen(taskPara->mailboxHandle) > 8u) ? 3 : 1); /* COV_CAN_BASICCAN_FULLCAN_FD_DATA_LEN_DIFFER */
# else
  hwObjStep = 1;
# endif
  for (hwObjHandle = taskPara->hwObjHandle; hwObjHandle < Can_GetHwHandleStopOfMailbox(taskPara->mailboxHandle); hwObjHandle+=hwObjStep)
  { /* #10 over all pending BasicCAN mailbox HW (FIFO/Shadow) call BasicCanMsgReceived */
    if( (CAN_MAILBOX_PTR(hwObjHandle)->MoCtrL & C_MOCTR_RXPND) == C_MOCTR_RXPND ) /* PRQA S 2985 */ /* MD_Can_ConstValue */
    {
      CanHL_BasicCanMsgReceivedPolling(CAN_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, hwObjHandle );
    }
  }
}
/* CODE CATEGORY 2 END */
# endif /* C_ENABLE_RX_BASICCAN_POLLING */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_RxFullMsgReceivedBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullMsgReceivedBegin
Relation_Context:
# from CanHL_FullCanMsgReceived #
RxFullCANSupport
Relation:
HardwareLoopCheck
CanFdSupport
Overrun
OneChOpt
ChannelAmount
RxFullAmount
IDType
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara)
{
  CanMsgObjStructPtr pCanCellMailbox;
  vuint8 canPndIdx, result;
  vuint32 canPndBit;
#if defined( C_ENABLE_HW_LOOP_TIMER )
  canHwLoopRetValType canHwLoopRetVal;
#endif
#if defined( C_ENABLE_FULLCAN_OVERRUN ) 
  vuint8 copy_cnt = 0;
  rxFullPara->isOverrun = kCanFalse; /* SBSW_CAN_LL11 */
#endif
  result = kCanOk;
  pCanCellMailbox = CAN_MAILBOX_PTR(rxFullPara->hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  canPndIdx = (((vuint8)rxFullPara->hwObjHandle) >> 5);
  canPndBit = 1UL << (rxFullPara->hwObjHandle & 0x1Fu);
#if defined( C_ENABLE_HW_LOOP_TIMER )
  CanLL_ApplCanTimerStart(kCanLoopRx); /* SBSW_CAN_HL38 */
#endif
  /* #10 Full can reception of classic and FD frames */
  do
  { /* #20 repeat until consistent data, msgval should not be used here */
#if defined( C_ENABLE_FULLCAN_OVERRUN ) 
    copy_cnt++;
#endif
    pCanCellMailbox->MoCtrL = C_MOCTR_RXPND | C_MOCTR_NEWDAT; /* delete pending flag */ /* SBSW_CAN_LL06 */
    CAN_MODULE_PTR->MSPND[canPndIdx] = ~canPndBit;             /* delete pending interrupt */ /* SBSW_CAN_LL03 */
    CanLL_CopyToTmpRxMailbox(CAN_HW_CHANNEL_CANPARA_FIRST rxFullPara->hwObjHandle, kCanTrue);
#if defined( C_ENABLE_HW_LOOP_TIMER )
    canHwLoopRetVal = CanLL_ApplCanTimerLoop(kCanLoopRx);
  } while( ((pCanCellMailbox->MoCtrL & (C_MOCTR_NEWDAT | C_MOCTR_RXUPD)) != 0x0000u) && ((vuint8)canHwLoopRetVal != kCanFailed) ); /* COV_CAN_NOT_STIMULATEABLE */
#else
  } while( (pCanCellMailbox->MoCtrL & (C_MOCTR_NEWDAT | C_MOCTR_RXUPD)) != 0x0000u ); /* COV_CAN_NOT_STIMULATEABLE */

#endif
#if defined( C_ENABLE_HW_LOOP_TIMER )
  CanLL_ApplCanTimerEnd(kCanLoopRx); /* SBSW_CAN_HL38 */
#endif
#if defined( C_ENABLE_FULLCAN_OVERRUN ) 
  if ((copy_cnt > 1u) || ((pCanCellMailbox->MoCtrL & C_MOCTR_MSGLOST) == C_MOCTR_MSGLOST)) /* COV_CAN_HARDWARE_FAILURE */
  {
    rxFullPara->isOverrun = kCanTrue; /* SBSW_CAN_LL11 */
    pCanCellMailbox->MoCtrL = C_MOCTR_MSGLOST; /* delete overrun */  /* SBSW_CAN_LL06 */
  }
#endif

#if defined( C_ENABLE_HW_LOOP_TIMER )
  if((vuint8)canHwLoopRetVal == kCanFailed) /* COV_CAN_HARDWARE_FAILURE */
  { /* #30 do not proceed when data is inconsistent (no notification) */
    result = kCanFailed;
  }
  else
#endif
  {
    /* #40 pass consistent data to caller */
    rxFullPara->rxStruct.pChipMsgObj = pTmpRxMailboxMsg; /* SBSW_CAN_LL11 */
    rxFullPara->rxStruct.pChipData = pTmpRxMailboxData; /* SBSW_CAN_LL11 */
  }
  return result;
}
/* CODE CATEGORY 1 END */


/**********************************************************************************************************************
 *  CanLL_RxFullReleaseObj
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullReleaseObj
Relation_Context:
# from CanHL_FullCanMsgReceived #
RxFullCANSupport
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
 V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(rxFullPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_RxFullMsgReceivedEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullMsgReceivedEnd
Relation_Context:
# from CanHL_FullCanMsgReceived #
RxFullCANSupport
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(rxFullPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

# if defined( C_ENABLE_RX_FULLCAN_POLLING )
/**********************************************************************************************************************
 *  CanLL_RxFullProcessPendings
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullProcessPendings
Relation_Context:
# from CanHL_RxFullCanPolling #
RxFullCANSupport, RxPolling
Relation:
OneChOpt
ChannelAmount
RxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  if( (CAN_MAILBOX_PTR(taskPara->hwObjHandle)->MoCtrL & C_MOCTR_RXPND) == C_MOCTR_RXPND ) /* PRQA S 2985 */ /* MD_Can_ConstValue */
  { /* #10 call BasicCanMsgReceived for pending FullCan */
    CanHL_FullCanMsgReceivedPolling(CAN_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, taskPara->hwObjHandle);
  }
}
/* CODE CATEGORY 2 END */
# endif /* C_ENABLE_RX_FULLCAN_POLLING */
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */


/**********************************************************************************************************************
 *  CanLL_ErrorHandlingBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_ErrorHandlingBegin
Relation_Context:
# from CanHL_ErrorHandling() #
StatusPolling
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 2 END */

/**********************************************************************************************************************
 *  CanLL_BusOffOccured
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_BusOffOccured
Relation_Context:
# from CanHL_ErrorHandling() #
StatusPolling
Relation:
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 result = kCanFalse;
  if( (Can_GetBusOffNotifiedOfControllerData(canHwChannel)==kCanFalse) &&
    ((CAN_NODE_PTR(Can_GetNodeNum(canHwChannel))->NCR & C_NCR_INIT) == C_NCR_INIT) &&
      (Can_GetHaltOfControllerData(canHwChannel)==kCanFalse)  ) /* COV_CAN_BUSOFF_NOTIFICATION */
  { /* #10 don't use busoff-flag here -> after resync deleted */
    Can_SetBusOffNotifiedOfControllerData(canHwChannel, kCanOk); /* SBSW_CAN_LL02 */
    result = kCanTrue;
  }
  return(result);
}
/* CODE CATEGORY 2 END */


/**********************************************************************************************************************
 *  CanLL_ErrorHandlingEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_ErrorHandlingEnd
Relation_Context:
# from CanHL_ErrorHandling() #
StatusPolling
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 2 END */

#if defined( C_ENABLE_EXTENDED_STATUS )
/**********************************************************************************************************************
 *  CanLL_GetStatusBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_GetStatusBegin
Relation_Context:
# from Can_GetStatus
CanGetStatus
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 3 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_GetStatusBegin(CAN_CHANNEL_CANTYPE_ONLY)
{ /* #10 nothing to do */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 3 END */
#endif


#if defined(C_ENABLE_CAN_FD_FULL)
/************************************************************************************************************
 *  CanLL_ReadFdData()
 ***********************************************************************************************************/
/*
|<DataModelStart>| CanLL_ReadFdData
Relation_Context:
# from MsgReceivedBegin #
RxFullCANSupport, RxBasicCANSupport, CanFdSupport
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ReadFdData(CanFdMsgObjStructPtr pCanFdCellMailbox, volatile vuint32* bufferPtr) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint8 index;
  for (index = 0; index < 7u; index++)
  { /* #10 copy extended data from FD frame into local buffer */
    bufferPtr[index] = pCanFdCellMailbox->MoDR[index]; /* SBSW_CAN_LL18 */
  }
}

/************************************************************************************************************
 *  CanLL_WriteFdData()
 ***********************************************************************************************************/
/*
|<DataModelStart>| CanLL_WriteFdData
Relation_Context:
# from CanLL_TxPretransmitCopyToCan, CanLL_TxCopyToCan, CanLL_TxCopyMsgTransmit#
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteFdData(CanFdMsgObjStructPtr pCanFdCellMailbox, volatile const vuint8* bufferPtr, vuint8 paddingValue, vuint8 paddingIndex)
{
  vuint8 index;
  union
  { /* PRQA S 0750 */ /* MD_Can_Union */
    tCanFdMsgObjStruct  dataStruct;
    vuint8              data8[28];
  } tmpBuffer; /* PRQA S 0759 */ /* MD_Can_Union */
  for (index = 0; (index < paddingIndex) && (index < 28u); index++) /* COV_CAN_FDMSG_WRITE_INDEX_CHECK */
  { /* #10 copy extended data FD frame */
    tmpBuffer.data8[index] = bufferPtr[index]; /* SBSW_CAN_LL18 */
  }
  for (index = paddingIndex; index < 28u; index++)
  { /* #20 pad the remaining data bytes with the specified padding value */
    tmpBuffer.data8[index] = paddingValue; /* SBSW_CAN_LL18 */
  }
  for (index = 0; index < 7u; index++)
  { /* #30 copy to HW */
    pCanFdCellMailbox->MoDR[index] = tmpBuffer.dataStruct.MoDR[index]; /* SBSW_CAN_LL18 */
  }
}
#endif

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS ) || defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/************************************************************************************************************
 *  CanLL_CopyToTmpRxMailbox()
 ***********************************************************************************************************/
/*
|<DataModelStart>| CanLL_CopyToTmpRxMailbox
Relation_Context:
# from CanLL_RxBasicMsgReceivedBegin, CanLL_RxFullMsgReceivedBegin#
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CopyToTmpRxMailbox(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle msgObjHandle, vuint8 copyFdData)
{
  CanMsgObjStructPtr pCanCellMailbox = CAN_MAILBOX_PTR(msgObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  /* #10 copy ID, mode, DLC and the first tw0 data byte to temp Rx mailbox */
  TmpRxMailbox.MoAR.reg32 = pCanCellMailbox->MoAR.reg32;  /* SBSW_CAN_LL10 */
  TmpRxMailbox.MoFCR_Mode = pCanCellMailbox->MoFCR_Mode;  /* SBSW_CAN_LL10 */
  TmpRxMailbox.MoFCR_DLC  = pCanCellMailbox->MoFCR_DLC;   /* SBSW_CAN_LL10 */
  TmpRxMailbox.MoDR[0]    = pCanCellMailbox->MoDR[0];     /* SBSW_CAN_LL10 */
  TmpRxMailbox.MoDR[1]    = pCanCellMailbox->MoDR[1];     /* SBSW_CAN_LL10 */
# if defined(C_ENABLE_CAN_FD_FULL)
  /* #20 copy FD data from second and third adjacent mailbox to temp */
  if(copyFdData == kCanTrue) /* COV_CAN_NO_BASICCAN_FIFO_HANDLING */
  {
    if(CAN_DLC2LEN(TmpRxMailbox.MoFCR_DLC) > 8u)
    {
      CanLL_ReadFdData(CAN_FD_MAILBOX_PTR(msgObjHandle+1u), &TmpRxMailbox.MoDR[2]); /* SBSW_CAN_LL14 */ /* PRQA S 0310, 2985 */ /* MD_Can_PointerCast, MD_Can_ConstValue */
    }
    if(CAN_DLC2LEN(TmpRxMailbox.MoFCR_DLC) > 36u)
    {
      CanLL_ReadFdData(CAN_FD_MAILBOX_PTR(msgObjHandle+2u), &TmpRxMailbox.MoDR[9]); /* SBSW_CAN_LL14 */ /* PRQA S 0310, 2985 */ /* MD_Can_PointerCast, MD_Can_ConstValue */
    }
  }
# else
  CAN_DUMMY_STATEMENT(copyFdData);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif


/**********************************************************************************************************************
 *  CanLL_ModeTransition
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_ModeTransition
Relation_Context:
# from CanHL_ModeTransition() #
Wakeup, OneChOpt, HardwareLoopCheck, ChannelAmount
RamCheck, OneChOpt, HardwareLoopCheck, ChannelAmount
# from Can_Mainfunction_Mode() #
ChannelAmount
Relation:
Wakeup
SilentMode
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 */
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST vuint8 mode, vuint8 busOffRecovery, vuint8 ramCheck)
{
  vuint8 retVal = kCanFailed;
  /* #10 Map mode to function, that will configure HW to mode */
  switch(mode)
  {
#if (CAN_REINIT_START == STD_OFF)
    case kCanModeStart:
      retVal = CanLL_ModeTransitionStart(CAN_CHANNEL_CANPARA_FIRST kCanFalse);
      break;
#else
    case kCanModeStartReinit:
#endif
    case kCanModeResetBusOffEnd:
      retVal = CanHL_ReInit(CAN_CHANNEL_CANPARA_FIRST ramCheck);
      if(retVal == kCanOk) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
      {
        retVal = CanLL_ModeTransitionStart(CAN_CHANNEL_CANPARA_FIRST kCanFalse);
      }
      break;
    case kCanModeStopReinitFast:
    case kCanModeStopReinit:
      retVal = CanHL_ReInit(CAN_CHANNEL_CANPARA_FIRST ramCheck);
      if(retVal == kCanOk) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
      {
        retVal = CanLL_ModeTransitionStop(CAN_CHANNEL_CANPARA_ONLY);
      }
      break;
#if defined(C_ENABLE_SILENT_MODE)
    case kCanModeSilent:
      retVal = CanLL_ModeTransitionStart(CAN_CHANNEL_CANPARA_FIRST kCanTrue);
      break;
#endif
    case kCanModeResetBusOffStart:
      retVal = kCanOk; /* nothing to do */
      break;
  } /* PRQA S 2002 */ /* MD_Can_NoDefaultInSwitch */
  CAN_DUMMY_STATEMENT(busOffRecovery); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
/* CODE CATEGORY 4 END */



#if defined( C_ENABLE_CAN_CAN_INTERRUPT_CONTROL ) /* COV_CAN_LOCK_ISR_BY_APPL */
/**********************************************************************************************************************
 *  CanLL_CanInterruptDisable
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_CanInterruptDisable
Relation_Context:
# from Can_DisableControllerInterrupts #
IndividualPolling
TxPolling
RxPolling
StatusPolling
Relation:
OneChOpt
ChannelAmount
CanInterruptControl
ProtectedMode
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptDisable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr)
{
# if defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined( C_LL_INTERRUPT_ISR_ACTIVE ) /* ! pure polling configuration ESCAN00095958 */
  boolean  retval;
  (void)osIsInterruptSourceEnabled(Can_GetIsrOsId(canHwChannel), &retval); /* SBSW_CAN_LL19 */
  (void)osDisableInterruptSource(Can_GetIsrOsId(canHwChannel));
  *(localInterruptOldFlagPtr) = (vuint32) retval; /* SBSW_CAN_LL17 */
#  else
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(localInterruptOldFlagPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
# else
   /* #10 save actual global IR status */
  (*localInterruptOldFlagPtr) = (vuint32)CAN_READ_PROTECTED_REG32(CAN_PROTECTED_AREA_SRC, CAN_SRC_ADR(canHwChannel)); /* SBSW_CAN_LL17 */ /* SBSW_CAN_LL09 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
  /* #20 disable global interrupts */
  CAN_WRITE_PROTECTED_REG32_RESET(CAN_PROTECTED_AREA_SRC, CAN_SRC_ADR(canHwChannel), C_SRC_SRE); /* SBSW_CAN_LL09 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_CanInterruptRestore
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_CanInterruptRestore
Relation_Context:
# from Can_EnableControllerInterrupts #
IndividualPolling
TxPolling
RxPolling
StatusPolling
Relation:
OneChOpt
ChannelAmount
CanInterruptControl
ProtectedMode
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptRestore(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOld localInterruptOldFlag)
{
# if defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined( C_LL_INTERRUPT_ISR_ACTIVE ) /* ! pure polling configuration ESCAN00095958 */
  if((vuint32)localInterruptOldFlag == TRUE) /* COV_CAN_TESTSUITE_NOT_APPLICABLE_WITH_LOCKED_IR */
  {
    (void)osEnableInterruptSource(Can_GetIsrOsId(canHwChannel), FALSE);
  }
#  else
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(localInterruptOldFlag); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
# else
  /* #10 enable global interrupt */
  CAN_WRITE_PROTECTED_REG32_SET(CAN_PROTECTED_AREA_SRC, CAN_SRC_ADR(canHwChannel), ((localInterruptOldFlag) & C_SRC_SRE)); /* SBSW_CAN_LL09 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
}
/* CODE CATEGORY 1 END */
#endif




#if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */
/****************************************************************************
| NAME:             CanHL_TxConfirmationPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_TxConfirmationPolling
Relation_Context:
# from CanLL_TxProcessPendings #
TxPolling
Relation:
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_TxConfirmationPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle )
{
  /* #10 Lock CAN controller interrupts. (avoid nested call of confirmation (individual polling) and CancelTx interrupt confirmation out of Can interrupt like TP) */
  Can_DisableControllerInterrupts((uint8)channel);
  /* #20 call CanHL_TxConfirmation() for handling */
  CanHL_TxConfirmation(CAN_HW_CHANNEL_CANPARA_FIRST mailboxHandle, mailboxElement, hwObjHandle);
  Can_EnableControllerInterrupts((uint8)channel);
}
#endif

/****************************************************************************
| NAME:             CanHL_TxConfirmation
****************************************************************************/
/*
|<DataModelStart>| CanHL_TxConfirmation
Relation_Context:
# from CanHL_TxConfirmationPolling #
# from Tx Interrupt #
TxPolling, IndividualPolling
Relation:
TxHwFifo, GenericConfirmation
DevErrorDetect, TxPolling, OneChOpt
TransmitCancellationAPI
GenericConfirmation, IfTxBuffer
HwCancelTx
GenericConfirmation, MirrorMode
HwCancelTx, TransmitCancellationAPI, GenericConfirmation
ChannelAmount
TxBasicAmount
TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* explicite not inline (big code + multiple calls) */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_TxConfirmation( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle )
{
  /* \trace SPEC-1574 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  tCanTxConfirmationParaStruct txConfPara;
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  tCanTxConfInfoStruct txConfInfoStruct;
#endif
  CanHookBegin_CanHL_TxConfirmation();
  errorId = CAN_E_NO_ERROR; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  txConfPara.mailboxHandle = mailboxHandle;
  txConfPara.mailboxElement = mailboxElement; /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
  txConfPara.hwObjHandle = hwObjHandle; /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  txConfPara.txStructConf = &txConfInfoStruct;
#endif
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
# if !defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING */
  /* #10 Check if parameter controller and hwObjHandle is valid (only for Interrupt system, polling do this by caller) */
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if ( 
#  if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
       ((txConfPara.mailboxHandle < Can_GetTxFullHandleStart(canHwChannel)) || (txConfPara.mailboxHandle >= Can_GetTxFullHandleStop(canHwChannel))) &&
#  endif
       ((txConfPara.mailboxHandle < Can_GetTxBasicHandleStart(canHwChannel)) || (txConfPara.mailboxHandle >= Can_GetTxBasicHandleStop(canHwChannel))) ) /* PRQA S 2991,2992,2995,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_FAILURE */
  {
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
# endif
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    PduIdType tmp_pdu;
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
    uint8_least tmp_state;
#endif
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
    Can_ReturnType generic_retval;
#endif
#if (defined(CAN_USE_CRITICALSECTION_OVER_CONFIRMATION) && (CAN_TRANSMIT_BUFFER == STD_ON)) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
    /* #100 EXCLUSIVE_AREA_3 needed to avoid another can_write while interface send out of queue (first send out of queue avoid inversion) or call GenericConfirmation2 (data consistency) */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3();
#endif
    txConfPara.activeSendObject = CanHL_GetActiveSendObject(txConfPara.mailboxHandle, txConfPara.mailboxElement); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
    {
      /* #120 Pre Release HW transmit object (LL) */
      CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara); /* SBSW_CAN_HL45 */
      /* #130 Remember PDU for confirmation parameter */
      tmp_pdu   = Can_GetActiveSendPdu(txConfPara.activeSendObject);
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
      /* #140 Remember SEND STATE which may be modified due to new transmit call in indication */
      tmp_state = (uint8_least)Can_GetActiveSendState(txConfPara.activeSendObject);
#endif
      { /* #200 Set send state to free to allow next TX out of confirmation or direct (reload queue) */
        /* #210 Notify the application by call Appl_GenericConfirmation() and CanIf_TxConfirmation() */
        /*      - Appl_GenericConfirmation() if configured and mirror mode is active
                and afterwards depend of return value
                - CanIf_TxConfirmation() if generic confirmation return OK, or no generic is used, and TX is not cancelled */
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1)
        Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
        if (Appl_GenericConfirmation( tmp_pdu ) == CAN_OK)
#elif defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
# if defined(C_ENABLE_MIRROR_MODE)
        if (Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE)
        { /* MirrorMode is inactive so call the following CanIf_TxConfirmation() */
          Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
          generic_retval = CAN_OK;
        }
        else
# endif
        { /* #230 For generic confirmation with API2 copy PDU data as parameter for Appl_GenericConfirmation() */
          { /* #250 in case of none FIFO get data out of CAN cell buffer (LL txStructConf) */
            Can_PduType canPdu;
            /* #260 get confirmation data out of hardware */
            CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara); /* SBSW_CAN_HL45 */
            CanHL_SetCanPduInfo(&canPdu, &txConfPara); /* SBSW_CAN_HL32 */ /* SBSW_CAN_HL45 */
            canPdu.swPduHandle = tmp_pdu;
            Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */ /* release after copy data to avoid data inconsistency */
            /* call Appl_GenericConfirmation() and in case of CAN_OK also the following CanIf_TxConfirmation() */
            generic_retval = Appl_GenericConfirmation( (uint8)channel, &canPdu ); /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL32 */
          }
        }
        /* #300 Appl_GenericConfirmation() decide to call Indication */
        if (generic_retval == CAN_OK)
#else /* no generic confirmation */
        Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
#endif
        {
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
          /* #310 If TX is SW cancelled call CanIf_CancelTxNotification() */
          if (tmp_state == kCanBufferCancelSw) /* COV_CAN_CANCEL_SW_STIMULATION */
          {
            CanIf_CancelTxNotification(tmp_pdu, FALSE);
          }
          else
#endif  /* #320 otherwise call CanIf_TxConfirmation() */
          {
            CanIf_TxConfirmation(tmp_pdu); /* \trace SPEC-1726, SPEC-1571 */
          }
        }
#if (defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)) && (CAN_TRANSMIT_BUFFER == STD_ON)
        /* #350 otherwise no CanIf_TxConfirmation() will be called so call CanIf_CancelTxNotification() just to notify IF to restart sending out of Queue */
        else
        {
# if defined(C_ENABLE_CANCEL_SUPPORT_API)
          CanIf_CancelTxNotification( tmp_pdu, FALSE );
# else
#  error "When using Generic Confirmation and Transmit buffer (If) the Cancel-support-api (if) has to be activated"
# endif
        }
#endif
      }
      /* #500 Post release HW transmit object (LL) */
      CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara); /* SBSW_CAN_HL45 */
    }

#if (defined(CAN_USE_CRITICALSECTION_OVER_CONFIRMATION) && (CAN_TRANSMIT_BUFFER == STD_ON)) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3();
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
# if !defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING */
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2991,2992,2995,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_HARDWARE_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_TXCNF_ID, errorId);
  }
# endif
#endif
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CanHookEnd_CanHL_TxConfirmation();
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */


#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/****************************************************************************
| NAME:             CanHL_SetCanPduInfo
****************************************************************************/
/*
|<DataModelStart>| CanHL_SetCanPduInfo
Relation_Context:
# from CanHL_TxConfirmation #
GenericConfirmation
Relation:
IDType
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_SetCanPduInfo(Can_PduInfoPtrType_var PduInfo, CanTxConfirmationParaStructPtr txConfPara)
{
  /* #10 set data pointer */
  PduInfo->sdu = (Can_SduPtrType) txConfPara->txStructConf->pChipData; /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL46 */
  /* #20 set data length */
  PduInfo->length = CanTxActualDLC(txConfPara->txStructConf); /* SBSW_CAN_HL46 */
  /* #30 set ID */
# if defined(C_ENABLE_EXTENDED_ID)
#  if defined(C_ENABLE_MIXED_ID)
  if ( CanTxActualIdType(txConfPara->txStructConf) == kCanIdTypeStd) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* Mixed ID */
    PduInfo->id = (Can_IdType)CanTxActualStdId(txConfPara->txStructConf); /* PRQA S 4391 */ /* MD_Can_IntegerCast */ /* SBSW_CAN_HL46 */
  }
  else
#  endif  /* pure Extended ID */
  { /* Extended ID */
    PduInfo->id = (Can_IdType)(CanTxActualExtId(txConfPara->txStructConf) | CAN_ID_IDE_MASK); /* SBSW_CAN_HL46 */
  }
# else    /* Standard ID */
  PduInfo->id = CanTxActualStdId(txConfPara->txStructConf); /* SBSW_CAN_HL46 */
# endif
# if defined(C_ENABLE_CAN_FD_USED)
  if ( CanTxActualFdType(txConfPara->txStructConf) == kCanFdTypeFd )
  {
    PduInfo->id |= (Can_IdType)CAN_ID_FD_MASK; /* SBSW_CAN_HL46 */
  }
# endif
  PduInfo->id &= CAN_ID_MASK_IN_GENERIC_CALLOUT; /* SBSW_CAN_HL46 */
}
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/****************************************************************************
| NAME:             CanHL_BasicCanMsgReceivedPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_BasicCanMsgReceivedPolling
Relation_Context:
# from CanLL_RxBasicProcessPendings #
RxBasicCANSupport
Relation:
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_BasicCanMsgReceivedPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle )
{
  /* #10 Lock CAN controller interrupts. */
  Can_DisableControllerInterrupts((uint8)channel);
  /* #20 call CanHL_BasicCanMsgReceived() for handling */
  CanHL_BasicCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxMailboxHandle, hwObjHandle );
  Can_EnableControllerInterrupts((uint8)channel);
}
#endif

/****************************************************************************
| NAME:             CanHL_BasicCanMsgReceived
****************************************************************************/
/*
|<DataModelStart>| CanHL_BasicCanMsgReceived
Relation_Context:
# from CanHL_BasicCanMsgReceivedPolling #
RxBasicCANSupport
# from Rx Interrupt #
Relation:
DevErrorDetect, RxPolling, OneChOpt
RamCheck
Overrun
IDType
CanFdSupport
DevErrorDetect, RxPolling, IndividualPolling
ChannelAmount
RxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* explicite not inline (big code + multiple calls) */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_BasicCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  tCanRxBasicParaStruct rxBasicPara;
  CanHookBegin_CanHL_BasicCanMsgReceived();
  errorId = CAN_E_NO_ERROR;
  rxBasicPara.mailboxHandle = rxMailboxHandle;
  rxBasicPara.hwObjHandle = hwObjHandle;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON) && !defined(C_ENABLE_RX_BASICCAN_POLLING)
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  /* #10 Check if parameter controller is in expected limit (already checked in polling task - do it only for interrupt) */
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif 
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #25 receive handling begin CanLL_RxBasicMsgReceivedBegin() \trace SPEC-1682, SPEC-1694 */
    if (CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara) == kCanOk) /* SBSW_CAN_HL26 */ /* COV_CAN_RxBasicMsgReceivedBegin */
    {
# if defined(C_ENABLE_CAN_RAM_CHECK)
      /* -------------------------- RAM check failed --- */
      if ((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER) /* COV_CAN_HARDWARE_FAILURE */
# endif
      { /* #30 RAM CHECK pass so continue reception */
# if defined(C_ENABLE_OVERRUN)
        /* -------------------------- Overrun --- */
        if (rxBasicPara.isOverrun == kCanTrue)
        { /* #40 Overrun occur so notify upper layer \trace SPEC-1686 */
#   if (CAN_OVERRUN_NOTIFICATION == CAN_DET)
          Can_CallDetReportError(CAN_RXINDI_ID, CAN_E_DATALOST); /* Call DET direct because Overrun will be notified additional to following DETs */
#   else /* CAN_OVERRUN_NOTIFICATION == CAN_APPL */
          Appl_CanOverrun( (uint8)channel );
#   endif
        }
# endif
        /* \trace SPEC-1346 */
        {
          /* -------------------------- Get DLC and Data Pointer --- */
          /* #60 get ID, DLC and data from HW \trace SPEC-1691, SPEC-1693 */
          rxBasicPara.rxStruct.localDlc = CanRxActualDLC((&(rxBasicPara.rxStruct)));
          /* -------------------------- Get ID  &  reject unwanted ID type --- */
# if defined(C_ENABLE_EXTENDED_ID)
#  if defined(C_ENABLE_MIXED_ID)
          if ( CanRxActualIdType((&(rxBasicPara.rxStruct))) == kCanIdTypeStd) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
          { /* mixed - standard ID */
            rxBasicPara.rxStruct.localId = (Can_IdType)CanRxActualStdId((&(rxBasicPara.rxStruct)));
          }
          else
#  endif 
          { /* mixed or pure - extended ID */
            rxBasicPara.rxStruct.localId = (Can_IdType)(CanRxActualExtId((&(rxBasicPara.rxStruct))) | CAN_ID_IDE_MASK);
          }
          {
# else 
          { /* pure - standard ID */
            rxBasicPara.rxStruct.localId = CanRxActualStdId((&(rxBasicPara.rxStruct)));
# endif
# if defined(C_ENABLE_CAN_FD_USED)
            if ( CanRxActualFdType((&(rxBasicPara.rxStruct))) == kCanFdTypeFd )
            { /* \trace SPEC-60428 */
              rxBasicPara.rxStruct.localId |= (Can_IdType)CAN_ID_FD_MASK;
            }
            /* DLC is not bigger than expected length (8) for CLASSIC CAN msg (additional to HashTag 145) */
            if ((CanRxActualFdType((&(rxBasicPara.rxStruct))) != kCanFdTypeFd) && (rxBasicPara.rxStruct.localDlc > 8u)) /* ESCAN00084263 */ /* COV_CAN_HARDWARE_FAILURE */
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
#  if (!defined(C_ENABLE_RX_BASICCAN_POLLING) || defined(C_ENABLE_INDIVIDUAL_POLLING))
            /* #140 Check HRH is BasicCAN (already checked in polling task - do it only for interrupt) */
            if ( (rxBasicPara.mailboxHandle < Can_GetRxBasicHandleStart(canHwChannel)) ||
                 (rxBasicPara.mailboxHandle >= Can_GetRxBasicHandleStop(canHwChannel)) ) /* PRQA S 2991,2992,2995,2996 */ /* MD_Can_ConstValue */ /* CM_CAN_HL18 */ /* COV_CAN_GENDATA_FAILURE */
            {
              errorId = CAN_E_PARAM_HANDLE;
            } 
            else
#  endif
# endif
            /* #145 DLC is not bigger than expected length from mailbox (MAX over all PDU for this mailbox) */
            if (rxBasicPara.rxStruct.localDlc > CAN_MAX_DATALEN_OBJ(rxBasicPara.mailboxHandle)) /* ESCAN00084263 */ /* COV_CAN_HARDWARE_FAILURE */
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
            {
              /* -------------------------- Notification --- */
              /* #150 RX queue and notification handling CanHL_RxMsgReceivedNotification() */
              rxBasicPara.rxStruct.localMailboxHandle = rxBasicPara.mailboxHandle;
              errorId = CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANPARA_FIRST &(rxBasicPara.rxStruct)); /* SBSW_CAN_HL26 */
            }
          }
        }
      }
    }
    /* #160 receive handling end CanHL_RxBasicMsgReceivedEnd() */
    CanLL_RxBasicReleaseObj(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara); /* SBSW_CAN_HL26 */
    CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara); /* SBSW_CAN_HL26 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_HARDWARE_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_RXINDI_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  CanHookEnd_CanHL_BasicCanMsgReceived();
} /* PRQA S 6010,6030,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/****************************************************************************
| NAME:             CanHL_FullCanMsgReceivedPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_FullCanMsgReceivedPolling
Relation_Context:
# from CanLL_RxFullProcessPendings #
RxFullCANSupport, RxPolling
Relation:
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_FullCanMsgReceivedPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle )
{
  /* #10 Lock CAN controller interrupts. */
  Can_DisableControllerInterrupts((uint8)channel);
  /* #20 call CanHL_FullCanMsgReceived() for handling */
  CanHL_FullCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxMailboxHandle, hwObjHandle );
  Can_EnableControllerInterrupts((uint8)channel);
}
# endif

/****************************************************************************
| NAME:             CanHL_FullCanMsgReceived
****************************************************************************/
/*
|<DataModelStart>| CanHL_FullCanMsgReceived
Relation_Context:
# from CanLL_FullCanMsgReceivedPolling #
RxFullCANSupport
# from Rx Interrupt #
Relation:
OneChOpt
DevErrorDetect, RxPolling, OneChOpt
RamCheck
Overrun
IDType
CanFdSupport
DevErrorDetect, RxPolling, IndividualPolling
ChannelAmount
RxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* explicite not inline (big code + multiple calls) */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_FullCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  tCanRxFullParaStruct rxFullPara;
  CanHookBegin_CanHL_FullCanMsgReceived();
  errorId = CAN_E_NO_ERROR;
  rxFullPara.mailboxHandle = rxMailboxHandle;
  rxFullPara.hwObjHandle = hwObjHandle;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
#  if !defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
#   if !defined( C_SINGLE_RECEIVE_CHANNEL )
  /* #10 Check if parameter controller is in expected limit (already checked in polling task - do it only for interrupt) */
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#   endif
#  endif
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #25 receive handling begin CanLL_RxFullMsgReceivedBegin() \trace SPEC-1682, SPEC-1694 */
    if (CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara) == kCanOk) /* SBSW_CAN_HL27 */ /* COV_CAN_RxFullMsgReceivedBegin */
    {
  /* -------------------------- RAM check failed --- */
# if defined(C_ENABLE_CAN_RAM_CHECK)
      if ((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER) /* COV_CAN_HARDWARE_FAILURE */
# endif
      { /* #30 RAM CHECK pass so continue reception */
        /* -------------------------- Overrun --- */
# if defined(C_ENABLE_FULLCAN_OVERRUN)
        if (rxFullPara.isOverrun == kCanTrue)
        {
          /* #40 Overrun occur so notify upper layer */
#   if (CAN_OVERRUN_NOTIFICATION == CAN_DET)
          Can_CallDetReportError(CAN_RXINDI_ID, CAN_E_DATALOST); /* \trace SPEC-1686 */ /* Call DET direct because Overrun will be notified additional to following DETs */
#   else /* CAN_OVERRUN_NOTIFICATION == CAN_APPL */
          Appl_CanFullCanOverrun( (uint8)channel );
#   endif
        }
# endif
        {
          /* -------------------------- Get DLC and Data Pointer --- */
          /* #60 get ID, DLC and data from HW \trace SPEC-1691, SPEC-1693 */
          rxFullPara.rxStruct.localDlc = CanRxActualDLC((&(rxFullPara.rxStruct)));
          /* -------------------------- Get ID  &  reject unwanted ID type --- */
# if defined(C_ENABLE_EXTENDED_ID)
#  if defined(C_ENABLE_MIXED_ID)
          if ( CanRxActualIdType((&(rxFullPara.rxStruct))) == kCanIdTypeStd) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
          { /* mixed - standard ID */
            rxFullPara.rxStruct.localId = (Can_IdType)CanRxActualStdId((&(rxFullPara.rxStruct)));
          }
          else
#  endif 
          { /* mixed or pure - extended ID */
            rxFullPara.rxStruct.localId = (Can_IdType)(CanRxActualExtId((&(rxFullPara.rxStruct))) | CAN_ID_IDE_MASK);
          }
# else 
          rxFullPara.rxStruct.localId = CanRxActualStdId((&(rxFullPara.rxStruct)));
# endif
          { /* ID has valid IdType */
# if defined(C_ENABLE_CAN_FD_USED)
            if ( CanRxActualFdType((&(rxFullPara.rxStruct))) == kCanFdTypeFd )
            { /* \trace SPEC-60428 */
              rxFullPara.rxStruct.localId |= (Can_IdType)CAN_ID_FD_MASK;
            }
            /* DLC is not bigger than expected length (8) for CLASSIC CAN msg (additional to HashTag 145) */
            if ((CanRxActualFdType((&(rxFullPara.rxStruct))) != kCanFdTypeFd) && (rxFullPara.rxStruct.localDlc > 8u)) /* ESCAN00084263 */ /* COV_CAN_HARDWARE_FAILURE */
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
#  if (!defined(C_ENABLE_RX_FULLCAN_POLLING) || defined(C_ENABLE_INDIVIDUAL_POLLING)) /* COV_CAN_RX_FULLCAN_POLLING */
            /* #140 Check HRH is FullCAN (already checked in polling task - do it only for interrupt) */
            if ( (rxFullPara.mailboxHandle < Can_GetRxFullHandleStart(canHwChannel)) ||
                 (rxFullPara.mailboxHandle >= Can_GetRxFullHandleStop(canHwChannel)) )  /* PRQA S 2991,2992,2995,2996 */ /* MD_Can_ConstValue */ /* CM_CAN_HL18 */ /* COV_CAN_GENDATA_FAILURE */
            {
              errorId = CAN_E_PARAM_HANDLE;
            }
            else
#  endif
# endif
            /* #145 DLC is not bigger than expected length from mailbox */
            if (rxFullPara.rxStruct.localDlc > CAN_MAX_DATALEN_OBJ(rxFullPara.mailboxHandle)) /* ESCAN00084263 */ /* COV_CAN_HARDWARE_FAILURE */
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
            {
              /* -------------------------- Notification --- */
              /* #150 RX queue and notification handling CanHL_RxMsgReceivedNotification() */
              rxFullPara.rxStruct.localMailboxHandle = rxFullPara.mailboxHandle;
              errorId = CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANPARA_FIRST &(rxFullPara.rxStruct)); /* SBSW_CAN_HL27 */
            }
          }
        }
      }
    }
    /* #160 receive handling end CanHL_RxFullMsgReceivedEnd() */
    CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara); /* SBSW_CAN_HL27 */
    CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara); /* SBSW_CAN_HL27 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_HARDWARE_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_RXINDI_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  CanHookEnd_CanHL_FullCanMsgReceived();
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

/****************************************************************************
| NAME:             CanHL_ErrorHandling
****************************************************************************/
/*
|<DataModelStart>| CanHL_ErrorHandling
Relation_Context:
# from Can_Mainfunction_BusOff() #
StatusPolling
# from BusOff Interrupt #
StatusPolling
Relation:
DevErrorDetect, StatusPolling, OneChOpt
Overrun
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* explicite not inline (big code + multiple calls) */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_ErrorHandling( CAN_HW_CHANNEL_CANTYPE_ONLY )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
# if !defined(C_ENABLE_ERROR_POLLING) /* COV_CAN_ERROR_POLLING */
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  /* #10 Check if parameter controller is in expected limit */
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Pre Error handling (LL) */
    CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
    if ( (CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue) && (!Can_IsIsBusOff(channel) /* avoid repeated call */)) /* COV_CAN_BUSOFF_NOT_IN_ALL_CONFIG */
    {
      /* #90 EXCLUSIVE_AREA_6 secure mode changes */
      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
      /* #100 BUSOFF occur -> ECU Manager restart Controller (no ResetBusOffStart/End needed) */
      Can_SetIsBusOff(channel, TRUE); /* SBSW_CAN_HL08 */
      /* #110 CanResetBusOffStart need when BUSOFF handled by Application */
      (void)CanHL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST kCanModeResetBusOffStart, kCanContinueBusOffRecovery, kCanSuppressRamCheck);
      /* #115 Controller is in STOP mode after CanResetBusOffStart \trace SPEC-1578, SPEC-1664, SPEC-1663 */
      /* #120 Status changed to STOP - no more call of STOP from CAN Interface */
      Can_SetLogStatus(channel, (uint8)((Can_GetLogStatus(channel) & CAN_STATUS_MASK_NOMODE) | CAN_STATUS_STOP)); /* SBSW_CAN_HL02 */
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
      /* #130 notify higher layer by call CanIf_ControllerBusOff() \trace SPEC-1726, SPEC-1578 */
      CanIf_ControllerBusOff((uint8)Can_GetCanToCanIfChannelMapping(channel));
    }
    /* #200 Post Error handling (LL) */
    CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_CTRBUSOFF_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


#define CAN_STOP_SEC_STATIC_CODE  /*---------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*-------------------------------------------------------------------------*/

#define CAN_START_SEC_CODE  /*---------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CAN_VERSION_INFO_API == STD_ON) /* \trace SPEC-1716 */
/****************************************************************************
| NAME:             Can_GetVersionInfo
****************************************************************************/
/*
|<DataModelStart>| Can_GetVersionInfo
Relation_Context:
VersionInfoApi
Relation:
DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_GetVersionInfo( Can_VersionInfoPtrType VersionInfo )
{ /* \trace SPEC-1723 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter versionInfo is an illegal null pointer \trace SPEC-1721 */
  if (VersionInfo == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  { /* #100 copy version info to given pointer parameter \trace SPEC-1717 */
    /* ----- Implementation ----------------------------------------------- */
    VersionInfo->vendorID   = CAN_VENDOR_ID; /* SBSW_CAN_HL10 */
    VersionInfo->moduleID   = CAN_MODULE_ID; /* SBSW_CAN_HL10 */
    VersionInfo->sw_major_version = (uint8)CAN_SW_MAJOR_VERSION; /* SBSW_CAN_HL10 */
    VersionInfo->sw_minor_version = (uint8)CAN_SW_MINOR_VERSION; /* SBSW_CAN_HL10 */
    VersionInfo->sw_patch_version = (uint8)CAN_SW_PATCH_VERSION; /* SBSW_CAN_HL10 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_VERSION_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif

/****************************************************************************
| NAME:             Can_InitMemory
****************************************************************************/
/*
|<DataModelStart>| Can_InitMemory
Relation_Context:
Relation:
Variant
DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_InitMemory( void )
{ /* BR:011 */
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 mark driver as uninitialized \trace SPEC-1650 */
  canConfigInitFlag = CAN_STATUS_UNINIT;
#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)
  /* #20 reset global configuration pointer */
  Can_ConfigDataPtr = NULL_PTR;
#endif /* otherwise constant pointer is used */
  /* #30 HW reset memory */
  CanLL_InitMemoryPowerOn(); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
#if(CAN_DEV_ERROR_DETECT == STD_OFF)
  CAN_DUMMY_STATEMENT(canConfigInitFlag); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

#if ((CAN_CHANGE_BAUDRATE_API == STD_ON) || (CAN_SET_BAUDRATE_API == STD_OFF))
/****************************************************************************
| NAME:             Can_ChangeBaudrate
****************************************************************************/
/*
|<DataModelStart>| Can_ChangeBaudrate
Relation_Context:
Relation:
ChangeBaudrate, DevErrorDetect, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_ChangeBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate )
{ /* \trace SPEC-20314 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval;
  uint8 errorId;
  retval = E_NOT_OK;
  errorId = CAN_E_PARAM_BAUDRATE; /* explicit default as Issue - remove when baud rate fit */ /* \trace SPEC-20321 */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT and STOP \trace SPEC-20338 */
  if ( canConfigInitFlag == CAN_STATUS_UNINIT )
  {
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if ( channel >= kCanNumberOfChannels ) /* CM_CAN_HL01 */
  { /* \trace SPEC-20331 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if ( (Can_GetLogStatus(channel) & CAN_STATUS_STOP) != CAN_STATUS_STOP )
  { /* \trace SPEC-1655, SPEC-20312 */
    errorId = CAN_E_TRANSITION;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    uint8_least baudrateIndex;
    for (baudrateIndex = Can_GetInitObjectStartIndex(channel); baudrateIndex < Can_GetInitObjectStartIndex(channel + 1u); baudrateIndex++)
    { /* #30 search for baud rate configuration */
      if (Can_GetInitObjectBaudrate(baudrateIndex) == Baudrate)
      { /* #40 set baud rate and reinitialize controller to activate baud rate \trace SPEC-1669 */
        uint8 transitionState;
        Can_SetLastInitObject(channel, (uint8)baudrateIndex); /* SBSW_CAN_HL11 */
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);
        CAN_DUMMY_STATEMENT(transitionState); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
        { /* #50 check transition STOP (Reinit) is successful */
          Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached */ /* SBSW_CAN_HL02 */
        }
        retval = E_OK;
        errorId = CAN_E_NO_ERROR;
        break;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_CHANGE_BR_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/****************************************************************************
| NAME:             Can_CheckBaudrate
****************************************************************************/
/*
|<DataModelStart>| Can_CheckBaudrate
Relation_Context:
ChangeBaudrate
Relation:
DevErrorDetect, OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate )
{ /* \trace SPEC-20311 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval;
  uint8 errorId;
  retval = E_NOT_OK;
  errorId = CAN_E_PARAM_BAUDRATE; /* \trace SPEC-20317 */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT \trace SPEC-20328, SPEC-20318 */
  if ( canConfigInitFlag == CAN_STATUS_UNINIT )
  {
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if ( channel >= kCanNumberOfChannels )
  { /* \trace SPEC-20335 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    uint8_least baudrateIndex;
    for (baudrateIndex = Can_GetInitObjectStartIndex(channel); baudrateIndex < Can_GetInitObjectStartIndex(channel + 1u); baudrateIndex++)
    { /* #30 search for baud rate configuration */
      if (Can_GetInitObjectBaudrate(baudrateIndex) == Baudrate)
      { /* #40 requested baud rate is set - return OK */
        retval = E_OK;
        errorId = CAN_E_NO_ERROR;
        break;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_CHECK_BR_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retval;
}
#endif /* CAN_CHANGE_BAUDRATE_API == STD_ON */

#if (CAN_SET_BAUDRATE_API == STD_ON)
/****************************************************************************
| NAME:             Can_SetBaudrate
****************************************************************************/
/*
|<DataModelStart>| Can_SetBaudrate
Relation_Context:
Relation:
ChangeBaudrate, DevErrorDetect, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetBaudrate( uint8 Controller, uint16 BaudRateConfigID )
{ /* \trace SPEC-50605 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval;
  uint8 errorId;
  /* #5 return E_NOT_OK in case no fitting baudrate is found \trace-2622524 */
  retval = E_NOT_OK;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT and STOP \trace SPEC-50595 */
  if ( canConfigInitFlag == CAN_STATUS_UNINIT )
  {
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if ( channel >= kCanNumberOfChannels ) /* CM_CAN_HL01 */
  { /* \trace SPEC-50587 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if ( (Can_GetLogStatus(channel) & CAN_STATUS_STOP) != CAN_STATUS_STOP )
  { /* \trace SPEC-50584 */
    errorId = CAN_E_TRANSITION;
  }
  else
  if ( BaudRateConfigID >= (uint16)(Can_GetInitObjectStartIndex(channel + 1u) - Can_GetInitObjectStartIndex(channel)) ) /* PRQA S 4391 */ /* MD_Can_IntegerCast */
  { /* \trace SPEC-50625, SPEC-50563 */
    errorId = CAN_E_PARAM_BAUDRATE;
  }
  else
# endif
  { /* #50 set baud rate and reinitialize controller to activate baud rate */
    uint8 transitionState;
    /* ----- Implementation ----------------------------------------------- */
    Can_SetLastInitObject(channel, (uint8)(Can_GetInitObjectStartIndex(channel) + BaudRateConfigID)); /* SBSW_CAN_HL11 */
    transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);
    /* #60 check if hardware cancellation appear while mode change, so for the baud rate set is not successful \trace SPEC-60434 */
    CAN_DUMMY_STATEMENT(transitionState); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    {
      retval = E_OK;
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached */ /* SBSW_CAN_HL02 */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_SET_BR_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* CAN_SET_BAUDRATE_API == STD_ON */

/****************************************************************************
| NAME:             Can_Init
****************************************************************************/
/*
|<DataModelStart>| Can_Init
Relation_Context:
Relation:
Variant, DevErrorDetect
RxQueue
OneChOpt
Variant
Wakeup
MirrorMode
SilentMode
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_Init( Can_ConfigPtrType ConfigPtr ) /* PRQA S 3206 */ /* MD_MSR_DummyStmt */
{ /* \trace SPEC-1587, SPEC-1708 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  CAN_CHANNEL_CANTYPE_LOCAL
  CanHookBegin_Can_Init();
  errorId = CAN_E_NO_ERROR;
#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER) /* PostBuild (load+sel) */
  Can_ConfigDataPtr = ConfigPtr; /* \trace SPEC-1394, SPEC-1575 */
# if defined(CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK) /* PostBuildLoadable */
  if (ConfigPtr == NULL_PTR)
  { /* #10 EcuM null pointer configuration check and notification */
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_NULLPTR);
  }
  else
#  if (CAN_FINALMAGICNUMBER == STD_ON) /* COV_CAN_FINALMAGICNUMBER */
  if (Can_GetFinalMagicNumber() != 20510u) /* COV_CAN_GENDATA_FAILURE */
  { /* #20 EcuM wrong magic number check and notification */
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_MAGICNUMBER);
  }
  else
#  endif
# else
  
  /* ----- Development Error Checks ------------------------------------- */
#  if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #30 Check if all parameters are valid \trace SPEC-1724 */
  if (ConfigPtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
#  endif
# endif
#else
  CAN_DUMMY_STATEMENT(ConfigPtr);  /* PRQA S 1338, 2982, 2983, 3112 */ /* MD_MSR_DummyStmt */
# if defined(V_ENABLE_USE_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
  ConfigPtr = Can_ConfigDataPtr;  /* PRQA S 2983,1338 */ /* MD_MSR_DummyStmt */
# endif
#endif /* CAN_ENABLE_USE_INIT_ROOT_POINTER */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag != CAN_STATUS_UNINIT)
  {
    /* #60 Check already initialized -> 2nd call is not allowed \trace SPEC-1712, SPEC-1722 */
    errorId = CAN_E_TRANSITION;
  }
  else
#endif
  if (  ( Can_GetBaseDll_GeneratorVersion()     != (uint16)CAN_GEN_BASE_CFG5_VERSION ) ||  /* PRQA S 2742 */ /* MD_Can_ConstValue */
        ( Can_GetPlatformDll_GeneratorVersion() != (uint16)CAN_GEN_TricoreMulticanAsr_VERSION ) ) /* COV_CAN_GENDATA_FAILURE */
  {
    /* #70 EcuM generator and compatibility version check and notification */
#if defined(CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK) /* not for PostBuildSelectable */
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_COMPATIBILITYVERSION); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
#else
    errorId = CAN_E_UNINIT; /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
#endif
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    {
      canIsRxTaskLocked = kCanFalse;
#if defined(C_ENABLE_RX_QUEUE)
      /* #110 delete RxQueue (all channels) */
      Can_GetRxQueueInfo().WriteIndex = 0u;  /* CM_CAN_HL24 */ /* SBSW_CAN_HL55 */
      Can_GetRxQueueInfo().ReadIndex = 0u; /* SBSW_CAN_HL55 */
      Can_GetRxQueueInfo().Count = 0u; /* SBSW_CAN_HL55 */
      canRxQueueMaxDataSize = (uint16) (sizeof(Can_GetRxQueueBuffer(0).data) / sizeof(Can_GetRxQueueBuffer(0).data[0]));
#endif
      /* #120 Set active Identity */
      /* #130 HW specific power on (LL) */
      if (CanLL_InitPowerOn() == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
      {
        canConfigInitFlag = CAN_STATUS_INIT; /* \trace SPEC-1648 */ /* before Controller initialization begin */
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
        for (channel = 0u; channel < kCanNumberOfChannels; channel++) /* CM_CAN_HL01 */
#endif
        { /* #132 for each controller */
#if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
          if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_FAILURE */
          { /* #134 not for inactive controller */
            continue;
          }
#endif
          /* #140 initialize start up values for each controllers */
          Can_SetLogStatus(channel, CAN_STATUS_UNINIT); /* PowerOn mark */ /* SBSW_CAN_HL02 */
          Can_SetModeTransitionRequest(channel, kCanModeNone); /* SBSW_CAN_HL01 */
          Can_SetBusOffTransitionRequest(channel, kCanFinishBusOffRecovery); /* SBSW_CAN_HL01 */
          Can_SetRamCheckTransitionRequest(channel, kCanSuppressRamCheck); /* SBSW_CAN_HL01 */
          Can_SetIsBusOff(channel, FALSE);  /* start up: no BUSOFF */ /* SBSW_CAN_HL08 */
          Can_SetCanInterruptCounter(channel, 0u); /* SBSW_CAN_HL12 */
#if defined(C_ENABLE_MIRROR_MODE)
          Can_SetMirrorModeState(channel, CDDMIRROR_INACTIVE); /* SBSW_CAN_HL20 */
#endif
#if defined(C_ENABLE_SILENT_MODE)
          Can_SetSilentModeState(channel, CAN_SILENT_INACTIVE); /* SBSW_CAN_HL20 */
#endif
          /* #155 HW channel specific power on */
          if (CanLL_InitPowerOnChannelSpecific(CAN_CHANNEL_CANPARA_ONLY) == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_HARDWARE_FAILURE */
          {
            uint8 transitionState;
            /* #160 set baud rate and initialize all CAN controllers \trace SPEC-1587, SPEC-1656 */
            Can_SetLastInitObject(channel, (uint8)(Can_GetInitObjectStartIndex(channel) + Can_GetCanControllerDefaultBaudrateIdx(CAN_HL_HW_CHANNEL_STARTINDEX(channel)))); /* SBSW_CAN_HL11 */
            transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanExecuteRamCheck);
            CAN_DUMMY_STATEMENT(transitionState); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
            { /* #170 check transition STOP (Reinit) is successful */
              Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached or issue */ /* SBSW_CAN_HL02 */
            }
          }
        }
      } /* CanLL_InitPowerOn */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_INIT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_Can_Init();
} /* PRQA S 6030,6050,6080 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_SetControllerMode
****************************************************************************/
/*
|<DataModelStart>| Can_SetControllerMode
Relation_Context:
Relation:
DevErrorDetect, OneChOpt, ChannelAmount
DevErrorDetect, Variant, ChannelAmount
DevErrorDetect, TransitionCheck
RamCheck, ChannelAmount
SilentMode, ChannelAmount
ReInitStart
Wakeup
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_SetControllerMode( uint8 Controller, Can_StateTransitionType Transition )
{ /* \trace SPEC-1715 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  Can_ReturnType retval;
  uint8 transitionRequest;
  uint8 busOffRecovery;
  uint8 doRamCheck;
  uint8 transitionState;
  CanHookBegin_Can_SetControllerMode();
  retval = CAN_NOT_OK;  /* \trace SPEC-1407 */ /* For successful transition it is set explicit to CAN_OK */
  transitionState = kCanFailed;
  errorId = CAN_E_NO_ERROR;
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller and Transition is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1731 */
    errorId = CAN_E_UNINIT;
  }
  else
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* \trace SPEC-1732 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { 
    errorId = CAN_E_PARAM_CONTROLLER; /* \trace SPEC3874 */
  }
  else
# endif
#endif
  { /* #50 second level check (modes and transitions) only valid when controller is in active ECU and valid */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (!CanHL_IsControllerInit(channel))
    { /* #60 Check controller is initialized */
      errorId = CAN_E_UNINIT;
    }
    else
    if ((!CanHL_IsStop(channel)) && (Transition == CAN_T_START))
    { /* #70 Check No-STOP -> START-Req is invalid \trace SPEC-1637 */ /* ESCAN00073272 */
      errorId = CAN_E_TRANSITION;
    }
    else
# if (CAN_TRANSITION_CHECK == STD_ON)  /* SREQ00000291 */
    if ( ((!CanHL_IsStop(channel)) && (!CanHL_IsSleep(channel)) && ((Transition == CAN_T_WAKEUP) || (Transition == CAN_T_SLEEP))) ||
         ((CanHL_IsSleep(channel)) && (Transition == CAN_T_STOP)) )
    { /* #80 Check  No STOP Nor SLEEP -> SLEEP-Req   or   No SLEEP Nor STOP --> WAKEUP-Req   is invalid \trace SPEC-1654, SPEC-1649 */
      /* #90 Check  No START Nor STOP -> STOP-Req is invalid \trace SPEC-1652 */
      errorId = CAN_E_TRANSITION;
    }
    else
# endif
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    /* #95 controller is active (no RAM check issue): */
    if ((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER) /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */ /* COV_CAN_RAM_CHECK_NO_STIMULATION */
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #100 EXCLUSIVE_AREA_6 avoid nesting mode changes (e.g. same API, initialization or BUSOFF) */
      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
      /* #125 HW begin mode transition */
      switch(Transition)
      {
      case CAN_T_START:
        /* #200 Handle --- START --- transition */
        if (Can_IsIsBusOff(channel)) /* COV_CAN_BUSOFF_NOT_IN_ALL_CONFIG */
        { /* #210 BUSOFF occur so finish BUSOFF handling and do START transition inside */
          transitionRequest = kCanModeResetBusOffEnd;
        } 
        else
        {
#if defined(C_ENABLE_SILENT_MODE)
          if (Can_GetSilentModeState(channel) == CAN_SILENT_ACTIVE)
          {
            transitionRequest = kCanModeSilent;
          }
          else
#endif
          {
#if (CAN_REINIT_START == STD_ON)
            transitionRequest = kCanModeStartReinit;
#else
            transitionRequest = kCanModeStart;
#endif
          }
        }
        busOffRecovery = kCanContinueBusOffRecovery;
        doRamCheck = kCanSuppressRamCheck;
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        {
          Can_SetIsBusOff(channel, FALSE); /* SBSW_CAN_HL08 */
        }
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_START, CANIF_CS_STARTED, transitionState);
        break;

      case CAN_T_STOP:
        /* #300 Handle --- STOP --- transition */
        transitionRequest = kCanModeStopReinitFast;
        busOffRecovery = kCanContinueBusOffRecovery;
        doRamCheck = kCanSuppressRamCheck;
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_STOP, CANIF_CS_STOPPED, transitionState);
        break;

      case CAN_T_WAKEUP:
        /* #400 Handle --- WAKEUP --- transition */
#if defined(C_ENABLE_CAN_RAM_CHECK) && !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
        if (!CanHL_IsStop(channel)) { /* do not call RAM_CHECK again in case CanIf call wakeup a second time (buswakeup + stop transition afterwards) */
          /* #415 do standard RAM check CanHL_DoRamCheck() if controller is not in STOP mode */
          transitionRequest = kCanModeStopReinit;
          doRamCheck = kCanExecuteRamCheck;
        }
        else
#endif
        {
          transitionRequest = kCanModeStopReinitFast;
          doRamCheck = kCanSuppressRamCheck;
        }
        {
          busOffRecovery = kCanFinishBusOffRecovery;
        }
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_STOP, CANIF_CS_STOPPED, transitionState);
        break;

      case CAN_T_SLEEP: /* \trace SPEC-1639 */
        /* #500 Handle --- SLEEP --- transition */
        { /* #520 no WAKEUP-source-ref: do emulated SLEEP mode \trace SPEC-1629, SPEC-1641, SPEC-1645 */
          transitionState = kCanOk;
        }
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_SLEEP, CANIF_CS_SLEEP, transitionState);
        break;

      default:
        /* #600 check unknown transition, return NOT_OK \trace SPEC-1573, SPEC-1402, SPEC-1403 */
        errorId = CAN_E_TRANSITION; /* \trace SPEC-1733, SPEC-1407 */
        break;
      } /* switch */
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
    }
  }
  if ( transitionState != kCanFailed ) /* COV_CAN_TRANSITION_REQUEST */
  {
    retval = CAN_OK;
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_SETCTR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_Can_SetControllerMode();
  return retval;
} /* PRQA S 6010,6030,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_DisableControllerInterrupts
****************************************************************************/
/*
|<DataModelStart>| Can_DisableControllerInterrupts
Relation_Context:
# from Can_Mainfunction_BusOff #
StatusPolling, ChannelAmount
# from CanHL_TxTaskCancelationHandling #
HwCancelTx, IndividualPolling
# from CanHL_TxConfirmationPolling #
TxPolling
# from Rx BasicCan FullCan #
RxPolling
RxBasicCANSupport
RxFullCANSupport
# from Error handling #
StatusPolling
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
IntLock
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_DisableControllerInterrupts( uint8 Controller )
{ /* \trace SPEC-1746 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1750 */
    errorId = CAN_E_UNINIT;
  }
  else
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* \trace SPEC-1742 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
  if (!CanHL_IsControllerInit(channel))
  { /* #40 Check controller is initialized \trace SPEC-1750 */
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  { /* ----- Implementation ----------------------------------------------- */
    /* #100 EXCLUSIVE_AREA_1 secure interrupt lock handling */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
    if (Can_GetCanInterruptCounter(channel) == 0u)
    { /* #110 Disable only when not disabled before (count nesting) \trace SPEC-1735, SPEC-1745 */
#if (CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH) /* COV_CAN_LOCK_ISR_BY_APPL */
      { /* #120 Disable CAN interrupt for each HW channel */
        CanLL_CanInterruptDisable(CAN_CHANNEL_CANPARA_FIRST  &Can_GetCanInterruptOldStatus(canHwChannel)); /* SBSW_CAN_HL16 */
      }
#endif
#if (CAN_INTLOCK == CAN_APPL) || (CAN_INTLOCK == CAN_BOTH) /* COV_CAN_LOCK_ISR_BY_APPL */
      /* #130 Let application Disable CAN interrupt ApplCanInterruptDisable() */
      ApplCanInterruptDisable((uint8)channel);
#endif
    }
    Can_SetCanInterruptCounter(channel, Can_GetCanInterruptCounter(channel) + 1u); /* \trace SPEC-1748 */ /* SBSW_CAN_HL12 */
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_DIINT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_EnableControllerInterrupts
****************************************************************************/
/*
|<DataModelStart>| Can_EnableControllerInterrupts
Relation_Context:
# from Can_Mainfunction_BusOff #
StatusPolling, ChannelAmount
# from CanHL_TxTaskCancelationHandling #
HwCancelTx, IndividualPolling
# from CanHL_TxConfirmationPolling #
TxPolling
# from Rx BasicCan FullCan #
RxPolling
RxBasicCANSupport
RxFullCANSupport
# from Error handling #
StatusPolling
Relation:
DevErrorDetect, OneChOpt 
DevErrorDetect, Variant
IntLock
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_EnableControllerInterrupts( uint8 Controller )
{ /* \trace SPEC-1741 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1739 */
    errorId = CAN_E_UNINIT;
  }
  else
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* \trace SPEC-1752 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
  if (!CanHL_IsControllerInit(channel))
  { /* #40 Check controller is initialized \trace SPEC-1739 */
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  { /* ----- Implementation ----------------------------------------------- */
    /* #100 EXCLUSIVE_AREA_1 secure interrupt lock handling */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
    if (Can_GetCanInterruptCounter(channel) != 0u)
    { /* #110 Enable only when disabled before (count nesting) \trace SPEC-1749, SPEC-1748 */
      Can_SetCanInterruptCounter(channel, Can_GetCanInterruptCounter(channel)-1u); /* SBSW_CAN_HL12 */
      if (Can_GetCanInterruptCounter(channel) == 0u) /* \trace SPEC-1736, SPEC-1756 */
      {
#if (CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH) /* COV_CAN_LOCK_ISR_BY_APPL */
        { /* #120 Disable CAN interrupt for each HW channel */
          CanLL_CanInterruptRestore(CAN_CHANNEL_CANPARA_FIRST Can_GetCanInterruptOldStatus(canHwChannel));
        }
#endif
#if (CAN_INTLOCK == CAN_APPL) || (CAN_INTLOCK == CAN_BOTH) /* COV_CAN_LOCK_ISR_BY_APPL */
        /* #130 Let application Enable CAN interrupt ApplCanInterruptRestore() */
        ApplCanInterruptRestore((uint8)channel);
#endif
      }
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_ENINT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_Write
****************************************************************************/
/*
|<DataModelStart>| Can_Write
Relation_Context:
Relation:
DevErrorDetect
OneChOpt
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
DevErrorDetect, TxFullCANSupport
DevErrorDetect, CanFdSupport
DevErrorDetect, MixedId
RamCheck
UseVectorCanIf
CanFdSupport
ChannelAmount
TxBasicAmount
TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_Write( Can_HwHandleType Hth, Can_PduInfoPtrType PduInfo )
{ /* \trace SPEC-1751, SPEC-1760, SPEC-1406 */
  /* ----- Local Variables ---------------------------------------------- */
  Can_ReturnType retval;
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  CanHookBegin_Can_Write();
  errorId = CAN_E_NO_ERROR;
  retval = CAN_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1759 */
    errorId = CAN_E_UNINIT;
  }
  else
  if (Hth >= Can_GetSizeOfMailbox()) {
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#endif
  {
#if !defined( C_SINGLE_RECEIVE_CHANNEL ) /* otherwise 'channel' is a define */
    channel = Can_GetMailboxController(Hth);
#endif
#if (CAN_DEV_ERROR_DETECT == STD_ON)
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
    {
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
    if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_FAILURE */
    {
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
# endif
    if (!CanHL_IsControllerInit(channel))
    { /* #40 Check controller is initialized \trace SPEC-1407 */
      errorId = CAN_E_UNINIT;
    }
    else
# if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
    if ((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE)) /* COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG */
# else
    if ((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE)) /* COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG */
# endif
    { /* \trace SPEC-1763 */
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
    if ((PduInfo == NULL_PTR) || ((PduInfo->sdu == NULL_PTR) && (PduInfo->length != 0u)))
    { /* \trace SPEC-1761 */
      errorId = CAN_E_PARAM_POINTER;
    }
    else
# if !defined(C_ENABLE_CAN_FD_USED)
    if ( CanHL_IsFdMessage(PduInfo->id) )
    { /* no CAN_FD: Check parameter PduInfo->id should not have FD bit in ID */
      errorId = CAN_E_PARAM_POINTER;
    }
    else
# endif
# if defined(C_ENABLE_CAN_FD_FULL)
    if ( ((PduInfo->length > 8u) && (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_NONE)) ||
         (PduInfo->length > CAN_MAX_DATALEN_OBJ(Hth)) ) /* COV_CAN_GENDATA_FAILURE */
         { /* \trace SPEC-1758 */
      /* \trace SPEC-60433 */ /* CAN_FD: Check parameter PduInfo->length is smaller than 9 for none FD configuration
         If development error detection for the CAN module is enabled and the CAN Controller is not in CAN FD mode (no CanControllerFdBaudrateConfig):
         The function Can_Write shall raise the error CAN_E_PARAM_DLC and shall return CAN_NOT_OK if the length is more than 8 byte.() */
      /* CAN_FD: Check parameter PduInfo->length against PDU maximum size */
      errorId = CAN_E_PARAM_DLC;
    }
    else
# else
    if ( PduInfo->length > CAN_MAX_DATALEN_OBJ(Hth) ) /* CM_CAN_HL20 */
    { /* \trace SPEC-1758 */ /* Check parameter PduInfo->length against maximum buffer size */
      errorId = CAN_E_PARAM_DLC;
    }
    else
# endif
# if defined(C_ENABLE_MIXED_ID)
    if ( ((PduInfo->id & (Can_IdType)CAN_ID_IDE_MASK) != (Can_IdType)CAN_ID_IDE_MASK ) && ( (PduInfo->id & (Can_IdType)CAN_ID_MASK) > (Can_IdType)CAN_ID_MASK_STD ) ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    { /* Check parameter PduInfo->id for STD ID is in STD range (EXT is always in range) */
      errorId = CAN_E_PARAM_POINTER;
    }
    else
# endif
    if ( (PduInfo->id & (Can_IdType)CAN_ID_UNUSED_MASK) != (Can_IdType)0UL )
    { /* Check parameter PduInfo->id contains illegal bits (e.g. bigger ID value than MAX for given type) */
      errorId = CAN_E_PARAM_POINTER;
    }
    else
#endif
    /* ----- Implementation ----------------------------------------------- */
#if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #150 reject deactivated mailbox (by RamCheck) */
    if (Can_GetMailboxState(Hth) == kCanFailed) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    {
      retval = CAN_NOT_OK;
    }
    else
#endif
    /* #180 check Hardware is in BUSOFF recovery state and is not able to handle a request: return BUSY \trace SPEC-1764 */
    if (Can_IsIsBusOff(channel)) /* COV_CAN_BUSOFF_NOT_IN_ALL_CONFIG */
    {
      retval = CAN_NOT_OK; /* ESCAN00096369 */
    }
    else
#if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #200 controller is active (no RAM check issue): */
    if ((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER) /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */ /* COV_CAN_HARDWARE_FAILURE */
#endif
    {
      /* #205 temporary pdu buffer to avoid data modification on constant data (modification in generic pretransmit) */
      tCanTxTransmissionParaStruct txPara;
      /* #210 EXCLUSIVE_AREA_2: Interrupts may not be locked and re-entrant call may occur. */
      /*                        Time in between ID search and lock of mailbox is critical 
                                (only when no Vector Interface used otherwise CanIf EXCLUSIVE_AREA is used instead) 
                                Can_Write() could be called re-entrant, there for also for polling systems the interrupts have to be locked  
                                this is essential while check for mailbox is free (in between if (free) and set to not free) and save PDU handle */
#if !defined(CAN_USE_VECTOR_IF)
      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_2();
#endif
      txPara.mailboxHandle = Hth;
      txPara.hwObjHandle = Can_GetMailboxHwHandle(Hth); 
      txPara.pdu.id = PduInfo->id;
      txPara.pdu.length = PduInfo->length;
      txPara.pdu.sdu = PduInfo->sdu;
      txPara.pdu.swPduHandle = PduInfo->swPduHandle;
#if defined(C_ENABLE_CAN_FD_USED)
      if (txPara.pdu.length <= 8u) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      {
        if (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_NONE)
        { /* #220 remove FD flag when no FD support is activated in this initialization structure and DLC not greater than 8 */
          /* CAN FD also support an extended payload which allows the transmission of up to 64 bytes.
          This feature also depends on the CAN FD configuration (see CanControllerFdBaudrateConfig).
          Therefore, if the CAN FD feature is enabled and the CAN FD flag is set in CanId passed to
           Can_Write(), CanDrv supports the transmission of PDUs with a length up to 64 bytes.
          If there is a request to transmit a CAN FD frame without the CAN FD feature enabled the
          frame is sent as conventional CAN frame as long as the PDU length <= 8 bytes. */
          txPara.pdu.id = txPara.pdu.id & ((Can_IdType)(CAN_ID_IDE_MASK | CAN_ID_MASK)); /* CAN_FD_   mask out the FD bit */
        }
      }
      txPara.fdBrsType = kCanFdBrsTypeFalse;
      if (CanHL_IsFdMessage(txPara.pdu.id))
      {
        txPara.fdType = kCanFdTypeFd;
        if (CanHL_IsFdTxBrs(channel))
        {
          txPara.fdBrsType = kCanFdBrsTypeTrue;
        }
      } else {
        txPara.fdType = kCanFdTypeClassic;
      }
      txPara.messageLen = txPara.pdu.length;
      txPara.frameLen = CAN_DLC2LEN(CAN_LEN2DLC(txPara.messageLen));
# if defined(C_ENABLE_CAN_FD_FULL)
      txPara.paddingVal = Can_GetMailboxFdPadding(txPara.mailboxHandle);
# endif
#endif
      /* #230 search for BasicCAN object handle to transmit (Multiplexed TX) and backup data for cancel TX object if necessary */
      CanHL_WritePrepare(CAN_CHANNEL_CANPARA_FIRST &txPara); /* SBSW_CAN_HL49 */
      /* #240 start transmission for given handle (if free) and return state */
      retval = CanHL_WriteStart(CAN_CHANNEL_CANPARA_FIRST &txPara); /* SBSW_CAN_HL49 */

#if !defined(CAN_USE_VECTOR_IF) /* No Vector Interface used, Interrupts may not be locked */
      /* avoid change of PDU information due to TX interrupt while changing */
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_2();
#endif
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_WRITE_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_Can_Write();
  return retval;
} /* PRQA S 6010,6030,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */

/****************************************************************************
| NAME:             ASR4.x - Can_CheckWakeup
****************************************************************************/
/*
|<DataModelStart>| Can_CheckWakeup
Relation_Context:
Relation:
Wakeup, DevErrorDetect, OneChOpt
Wakeup, DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
#if defined(C_ENABLE_CHECK_WAKEUP_CAN_RET_TYPE) /* COV_CAN_COMPATIBILITY */
# define CAN_CHECKWAKEUP_RETTYPE Can_ReturnType
# define CAN_CHECKWAKEUP_RETVAL_OK     CAN_OK
# define CAN_CHECKWAKEUP_RETVAL_NOT_OK CAN_NOT_OK
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_CheckWakeup( uint8 Controller )
#else
# define CAN_CHECKWAKEUP_RETTYPE Std_ReturnType
# define CAN_CHECKWAKEUP_RETVAL_OK     E_OK
# define CAN_CHECKWAKEUP_RETVAL_NOT_OK E_NOT_OK
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckWakeup( uint8 Controller )
#endif
{ /* \trace SPEC-1740 */
  /* ----- Local Variables ---------------------------------------------- */
  CAN_CHECKWAKEUP_RETTYPE retval;
  retval = CAN_CHECKWAKEUP_RETVAL_NOT_OK; /* \trace SPEC-1407 */
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_MainFunction_Write
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_Write
Relation_Context:
Relation:
TxPolling, HwCancelTx, DevErrorDetect
TxPolling, HwCancelTx, OneChOpt
TxPolling, HwCancelTx, Variant
TxPolling, HwCancelTx, Wakeup
TxPolling, IndividualPolling
TxPolling, TxFullCANSupport, IndividualPolling
TxFullCANSupport, HwCancelTx
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Write( void )
{ /* \trace SPEC-1766 */
  /* ----- Local Variables ---------------------------------------------- */
#if defined(C_ENABLE_TX_POLLING) 
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  CanHookBegin_Can_MainFunction_Write();
  /* canSendSemaphor no more needed because of ControllerInterrupts disabled while Can_Write() */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized \trace SPEC-1767 */
    errorId = CAN_E_UNINIT;
  }
  else
# endif
  {  
    /* ----- Implementation ----------------------------------------------- */
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for (channel = 0u; channel < kCanNumberOfChannels; channel++)
# endif
    { /* #20 over all active controller */
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
      if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* not for inactive controller */
        continue;
      }
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON) /* \trace SPEC-1573, SPEC-1402, SPEC-1403 */
      if (!CanHL_IsControllerInit(channel))
      { /* #50 Check controller is initialized */
        errorId = CAN_E_UNINIT;
      }
      else
# endif
      {
        if ( !CanHL_IsSleep(channel) )
        { /* #60 do not access CAN hardware in SLEEP */
          tCanTaskParaStruct taskPara;
# if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */ /* always true when no hw-cancel is supported */
          /* #100 do confirmation handling for pending mailboxes */
          { /* #110 is at least one mailbox pending */
            for ( taskPara.mailboxHandle = Can_GetTxBasicHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetTxBasicHandleStop(canHwChannel); taskPara.mailboxHandle++ ) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
            { /* #120 iterate over all TxBasicCAN */
              taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#  if defined(C_ENABLE_INDIVIDUAL_POLLING) /* COV_CAN_HWOBJINDIVPOLLING */
              if ( Can_IsMailboxIndivPolling(taskPara.mailboxHandle)) /* COV_CAN_HWOBJINDIVPOLLING */
#  endif
              { /* #130 is mailbox handled by polling (individual) */
                /* #140 call LL confirmation handling */
                CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &taskPara); /* SBSW_CAN_HL44 */
              }
            }
          }
# endif
# if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
#  if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */ /* always true when no hw-cancel is supported */
          /* #200 do confirmation handling for pending mailboxes */
          { /* #210 is at least one mailbox pending */
            for ( taskPara.mailboxHandle = Can_GetTxFullHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetTxFullHandleStop(canHwChannel); taskPara.mailboxHandle++ ) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
            { /* #220 iterate over all TxFullCAN */
              taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#   if defined(C_ENABLE_INDIVIDUAL_POLLING) /* COV_CAN_HWOBJINDIVPOLLING */
              if ( Can_IsMailboxIndivPolling(taskPara.mailboxHandle)) /* COV_CAN_HWOBJINDIVPOLLING */
#   endif
              { /* #230 is mailbox handled by polling (individual) */
                /* #240 call LL confirmation handling */
                CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &taskPara); /* SBSW_CAN_HL44 */
              }
            }
          }
#  endif
# endif
        } /* !IsSleep */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_WRITE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

#else
  CanHookBegin_Can_MainFunction_Write();
#endif /* C_ENABLE_TX_POLLING */
  CanHookEnd_Can_MainFunction_Write();
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_MainFunction_Read
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_Read
Relation_Context:
Relation:
DevErrorDetect
RxPolling, OneChOpt
RxPolling, Variant
RxPolling, DevErrorDetect
RxPolling, Wakeup
RxPolling, RxFullCANSupport
RxPolling, RxBasicCANSupport
RxQueue
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Read( void )
{ /* \trace SPEC-1776 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  CanHookBegin_Can_MainFunction_Read();
  errorId = CAN_E_NO_ERROR; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check Driver is initialized \trace SPEC-1784 */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  {
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #20 semaphore to secure parallel access to RX buffers interrupt or polling \trace SPEC-1569 */
  if ( canIsRxTaskLocked == kCanFalse )  /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */
  {
#if defined(C_ENABLE_RX_POLLING) /* COV_CAN_RX_POLLING */
    CAN_CHANNEL_CANTYPE_LOCAL
#endif
    canIsRxTaskLocked = kCanTrue; /* PRQA S 2982 */ /* MD_MSR_RetVal */
#if defined(C_ENABLE_RX_POLLING) /* \trace SPEC-1782 */ /* COV_CAN_RX_POLLING */
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for (channel = 0u; channel < kCanNumberOfChannels; channel++)
# endif
    { /* #30 iterate over all active controller */
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
      if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* not for inactive controller */
        continue;
      }
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
      if (!CanHL_IsControllerInit(channel))
      { /* #60 Check controller is initialized */
        errorId = CAN_E_UNINIT;
      }
      else
# endif
      {
        if ( !CanHL_IsSleep(channel) )
        { /* #70 do not access CAN hardware in SLEEP */
          /* #80 over all HW channel \trace SPEC-1774 */
# if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
          /* #90 search for all pending FullCAN mailbox objects and call notification */
          CanHL_RxFullCanPolling(CAN_HW_CHANNEL_CANPARA_ONLY);
# endif
# if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
          /* #100 search for all pending BasicCAN mailbox objects and call notification */
          CanHL_RxBasicCanPolling(CAN_HW_CHANNEL_CANPARA_ONLY);
# endif
        }
      }
    }
#endif /* C_ENABLE_RX_POLLING */
#if defined(C_ENABLE_RX_QUEUE)
    /* #200 execute RxQueue CanHL_RxQueueExecution() */
    CanHL_RxQueueExecution(); 
#endif
    canIsRxTaskLocked = kCanFalse;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_READ_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_Can_MainFunction_Read();
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_MainFunction_BusOff
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_BusOff
Relation_Context:
Relation:
StatusPolling, DevErrorDetect, ChannelAmount
StatusPolling, OneChOpt
StatusPolling, Variant, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_BusOff( void )
{ /* \trace SPEC-1783 */
  /* ----- Local Variables ---------------------------------------------- */
#if defined(C_ENABLE_ERROR_POLLING) /* \trace SPEC-1778 */ /* COV_CAN_ERROR_POLLING */
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized \trace SPEC-1780 */
    errorId = CAN_E_UNINIT;
  }
  else
# endif
  {  
    /* ----- Implementation ----------------------------------------------- */
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for (channel = 0u; channel < kCanNumberOfChannels; channel++)
# endif
    { /* #20 over all active controller */
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
      if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* not for inactive controller */
        continue;
      }
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
      if (!CanHL_IsControllerInit(channel))
      { /* #50 Check controller is initialized */
        errorId = CAN_E_UNINIT;
      }
      else
# endif
      {
        if ( !CanHL_IsSleep(channel) )
        { /* #60 do not access CAN hardware in SLEEP */
          /* #80 disable CAN interrupts */
          Can_DisableControllerInterrupts((uint8)channel);
          /* #90 call CanHL_ErrorHandling */
          CanHL_ErrorHandling( CAN_HW_CHANNEL_CANPARA_ONLY );
          Can_EnableControllerInterrupts((uint8)channel);
        }
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_BO_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
#endif /* C_ENABLE_ERROR_POLLING */
}

/****************************************************************************
| NAME:             Can_MainFunction_Wakeup
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_Wakeup
Relation_Context:
Relation:
WakeupPolling, Wakeup, DevErrorDetect
WakeupPolling, Wakeup, OneChOpt
WakeupPolling, Wakeup, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Wakeup( void )
{ /* \trace SPEC-1770 */
  /* ----- Local Variables ---------------------------------------------- */
}

/****************************************************************************
| NAME:             Can_MainFunction_Mode
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_Mode
Relation_Context:
Relation:
DevErrorDetect
OneChOpt, ChannelAmount
Variant, ChannelAmount
DevErrorDetect, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Mode( void )
{ /* \trace SPEC-1775 */
  /* ----- Local Variables ---------------------------------------------- */
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_CancelTx
****************************************************************************/
/*
|<DataModelStart>| Can_CancelTx
Relation_Context:
TransmitCancellationAPI
Relation:
DevErrorDetect, TxFullCANSupport
OneChOpt
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
TxFullCANSupport, HwCancelTx
ChannelAmount
TxFullAmount
TxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_CancelTx( Can_HwHandleType Hth, PduIdType PduId )
{
  /* ----- Local Variables ---------------------------------------------- */
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
  CAN_CHANNEL_CANTYPE_LOCAL
  tCanTxCancellationParaStruct txCancellationPara;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (Hth >= Can_GetSizeOfMailbox())
  { /* #20 Check Hth is in range */
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#  if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
  if ((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE)) /* COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG */
#  else
  if ((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE)) /* COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG */
#  endif
  { /* #30 Check Hth is FullCAN or BasicCAN */
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
# endif
  {
# if !defined( C_SINGLE_RECEIVE_CHANNEL ) /* otherwise 'channel' is a define */
    channel = Can_GetMailboxController(Hth);
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
    if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
    { /* #40 Check parameter controller is in range */
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
    if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_FAILURE */
    { /* #60 Check parameter controller is valid */
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#  endif
    if (!CanHL_IsControllerInit(channel))
    { /* #70 Check controller is initialized */
      errorId = CAN_E_UNINIT;
    }
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      txCancellationPara.mailboxHandle = Hth;
      txCancellationPara.mailboxElement = 0u;
      txCancellationPara.activeSendObject = CanHL_GetActiveSendObject(txCancellationPara.mailboxHandle, txCancellationPara.mailboxElement);

# if defined (C_ENABLE_TX_FULLCAN_OBJECTS)
      if ( Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
# endif
      { /* #100 is BasicCAN */
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
        for (; txCancellationPara.mailboxElement < Can_GetMailboxSize(Hth); txCancellationPara.mailboxElement++, txCancellationPara.activeSendObject++) /* PRQA S 3418 */ /* MD_Can_IncompleteForLoop */
# endif
        { /* #110 over all Multiplexed TX objects - search for handle */
          if (Can_GetActiveSendPdu(txCancellationPara.activeSendObject) == PduId)
          {
            if ((Can_GetActiveSendState(txCancellationPara.activeSendObject) == kCanBufferSend)
                )  /* COV_CAN_CANCEL_SW_STIMULATION */
            { /* #120 PDU found in active send list - handle found */
              /* #130 CANCEL_IN_HW is active - just suppress TX confirmation */
              Can_SetActiveSendState(txCancellationPara.activeSendObject, kCanBufferCancelSw); /* mark as cancelled by SW */ /* SBSW_CAN_HL04 */
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
              break;
# endif
            }
          }
        }
      }
# if defined (C_ENABLE_TX_FULLCAN_OBJECTS)
      else
      { /* #200 is FullCAN */
        if (Can_GetActiveSendPdu(txCancellationPara.activeSendObject) == PduId)
        {
          if ((Can_GetActiveSendState(txCancellationPara.activeSendObject) == kCanBufferSend)
             )  /* COV_CAN_CANCEL_SW_STIMULATION */
          { /* #210 mailbox to cancel is valid (PDU, handle, send state OK) */
            /* #220 CANCEL_FULLCAN_IN_HW is active - just suppress TX confirmation */
            Can_SetActiveSendState(txCancellationPara.activeSendObject, kCanBufferCancelSw); /* mark as cancelled by SW */ /* SBSW_CAN_HL04 */
          }
        }
      }
# endif
    }
    CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_WRITE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
#else /* CAN_ENABLE_CANCEL_SUPPORT_API */
  CAN_DUMMY_STATEMENT(Hth); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(PduId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* CAN_ENABLE_CANCEL_SUPPORT_API */
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */

#if (CAN_GET_STATUS == STD_ON)
/****************************************************************************
| NAME:             Can_GetStatus
****************************************************************************/
/*
|<DataModelStart>| Can_GetStatus
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, uint8, CODE) Can_GetStatus( uint8 Controller )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = CAN_STATUS_INCONSISTENT; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #20 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (!CanHL_IsControllerInit(channel))
  { /* #50 Check controller is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    CanLL_GetStatusBegin(CAN_CHANNEL_CANPARA_ONLY); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
    /* #100 set logical state as return value */
    canReturnCode = (uint8)Can_GetLogStatus(channel);
    if ( CanLL_HwIsBusOff(channel) ) /* COV_CAN_HARDWARE_FAILURE */
    { /* #150 set BUSOFF - BUSOFF can only happen on first HW channel (with TX objects) */
      canReturnCode |= CAN_STATUS_BUSOFF;
    }
# if defined(C_ENABLE_EXTENDED_STATUS) /* COV_CAN_EXTENDED_STATUS */
    {    
      if ( CanLL_HwIsPassive(channel) ) /* COV_CAN_HARDWARE_FAILURE */
      { /* #160 set Error Passive */
        canReturnCode |= CAN_STATUS_PASSIVE;
      }    
      if ( CanLL_HwIsWarning(channel) ) /* COV_CAN_HARDWARE_FAILURE */
      { /* #170 set Error Warning */
        canReturnCode |= CAN_STATUS_WARNING;
      }
    }
# endif /* C_ENABLE_EXTENDED_STATUS */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return (uint8)canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_GetControllerMode
****************************************************************************/
/*
|<DataModelStart>| Can_GetControllerMode
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerMode( uint8 Controller, Can_ControllerStatePtrType ControllerModePtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameters are valid */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #20 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (ControllerModePtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 get logical controller mode from state machine variable */
    if (!CanHL_IsControllerInit(channel))
    {
      *ControllerModePtr = CAN_CS_UNINIT; /* SBSW_CAN_HL51 */
    }
    else if (CanHL_IsStart(channel))
    {
      *ControllerModePtr = CAN_CS_STARTED; /* SBSW_CAN_HL51 */
    } 
    else if (CanHL_IsSleep(channel))
    {
      *ControllerModePtr = CAN_CS_SLEEP; /* SBSW_CAN_HL51 */
    }
    else /* default is:   if (CanHL_IsStop(channel)) */
    {
      *ControllerModePtr = CAN_CS_STOPPED; /* SBSW_CAN_HL51 */
    }
    canReturnCode = E_OK;
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_GETCTR_MODE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_GetControllerErrorState
****************************************************************************/
/*
|<DataModelStart>| Can_GetControllerErrorState
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerErrorState( uint8 Controller, Can_ErrorStatePtrType ErrorStatePtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (!CanHL_IsControllerInit(channel))
  { /* Check controller is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (ErrorStatePtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    CanLL_GetStatusBegin(CAN_CHANNEL_CANPARA_ONLY); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
    if ( CanLL_HwIsBusOff(channel) ) /* COV_CAN_HARDWARE_FAILURE */
    { /* #40 set BUSOFF */
      *ErrorStatePtr = CAN_ERRORSTATE_BUSOFF; /* SBSW_CAN_HL52 */
    } 
# if defined(C_ENABLE_EXTENDED_STATUS) /* COV_CAN_EXTENDED_STATUS */
    else if ( CanLL_HwIsPassive(channel) ) /* COV_CAN_HARDWARE_FAILURE */
    { /* #50 set Error Passive */
      *ErrorStatePtr = CAN_ERRORSTATE_PASSIVE; /* SBSW_CAN_HL52 */
    }
# endif /* C_ENABLE_EXTENDED_STATUS */
    else
    { /* #60 default return is ACTIVE */
      *ErrorStatePtr = CAN_ERRORSTATE_ACTIVE; /* SBSW_CAN_HL52 */
    }
    canReturnCode = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_GETCTR_STATE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_GetControllerTxErrorCounter
****************************************************************************/
/*
|<DataModelStart>| Can_GetControllerTxErrorCounter
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerTxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType TxErrorCounterPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (!CanHL_IsControllerInit(channel))
  { /* Check controller is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (TxErrorCounterPtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 get error counter from hardware */
# if defined( C_SINGLE_RECEIVE_CHANNEL )
    *TxErrorCounterPtr = CanTxActualErrorCounter(); /* SBSW_CAN_HL53 */
# else
    *TxErrorCounterPtr = CanTxActualErrorCounter(channel); /* SBSW_CAN_HL53 */
# endif
    canReturnCode = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_GETCTR_TXCNT_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_GetControllerRxErrorCounter
****************************************************************************/
/*
|<DataModelStart>| Can_GetControllerRxErrorCounter
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerRxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType RxErrorCounterPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (!CanHL_IsControllerInit(channel))
  { /* Check controller is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (RxErrorCounterPtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 get error counter from hardware */
# if defined( C_SINGLE_RECEIVE_CHANNEL )
    *RxErrorCounterPtr = CanRxActualErrorCounter(); /* SBSW_CAN_HL54 */
# else
    *RxErrorCounterPtr = CanRxActualErrorCounter(channel); /* SBSW_CAN_HL54 */
# endif
    canReturnCode = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_GETCTR_RXCNT_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#endif

#if defined(C_ENABLE_MIRROR_MODE)
/****************************************************************************
| NAME:             Can_SetMirrorMode
****************************************************************************/
/*
|<DataModelStart>| Can_SetMirrorMode
Relation_Context:
MirrorMode
Relation:
DevErrorDetect, OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_SetMirrorMode( uint8 Controller, CddMirror_MirrorModeType mirrorMode )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* #20 Check parameter controller is in range */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  { /* #30 set mirror mode for given controller */
    /* ----- Implementation ----------------------------------------------- */
    Can_SetMirrorModeState(channel, mirrorMode); /* SBSW_CAN_HL20 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif

#if defined(C_ENABLE_SILENT_MODE)
/****************************************************************************
| NAME:             Can_SetSilentMode
****************************************************************************/
/*
|<DataModelStart>| Can_SetSilentMode
Relation_Context:
SilentMode
Relation:
DevErrorDetect, OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetSilentMode( uint8 Controller, Can_SilentModeType silentMode )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  Std_ReturnType retval;
  errorId = CAN_E_NO_ERROR;
  retval = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* #20 Check parameter controller is in range */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  { /* #30 set silent mode for given controller */
    /* ----- Implementation ----------------------------------------------- */
    Can_SetSilentModeState(channel, silentMode); /* SBSW_CAN_HL20 */
    retval = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retval;
}
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
/****************************************************************************
| NAME:             Can_RamCheckExecute
****************************************************************************/
/*
|<DataModelStart>| Can_RamCheckExecute
Relation_Context:
Relation:
RamCheck, DevErrorDetect, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckExecute( uint8 Controller )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* #20 Check parameter controller is in range */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  { /* #30 Do RamCheck by execute reinitialization with activated check */
    uint8 transitionState;
    /* ----- Implementation ----------------------------------------------- */
    transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanExecuteRamCheck);
    CAN_DUMMY_STATEMENT(transitionState); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    { /* #40 check transition STOP (Reinit) is successful */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached */ /* SBSW_CAN_HL02 */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/****************************************************************************
| NAME:             Can_RamCheckEnableMailbox
****************************************************************************/
/*
|<DataModelStart>| Can_RamCheckEnableMailbox
Relation_Context:
Relation:
RamCheck, DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableMailbox( Can_HwHandleType htrh )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (htrh >= Can_GetSizeOfMailbox()) { /* CM_CAN_HL28 */
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #15 disable controller to force reinitialization afterwards in Can_RamCheckEnableController() */
    Can_SetLogStatus(Can_GetMailboxController(htrh), CAN_DEACTIVATE_CONTROLLER); /* SBSW_CAN_HL40 */
    /* #20 reactivate mailbox */
    Can_SetMailboxState(htrh, kCanOk); /* SBSW_CAN_HL34 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/****************************************************************************
| NAME:             Can_RamCheckEnableController
****************************************************************************/
/*
|<DataModelStart>| Can_RamCheckEnableController
Relation_Context:
RamCheck
Relation:
DevErrorDetect, OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableController( uint8 Controller )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* #20 Check parameter controller is in range */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 activate controller only when currently disabled */
    if ( (Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) == CAN_DEACTIVATE_CONTROLLER ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    {
      uint8 transitionState;
      /* #40 re-initialize to activate mailboxes and controller after RAM check issue */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)(~(CAN_DEACTIVATE_CONTROLLER))); /* SBSW_CAN_HL02 */
      transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);
      CAN_DUMMY_STATEMENT(transitionState); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
      { /* #40 check transition STOP (Reinit) is successful */
        Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached */ /* SBSW_CAN_HL02 */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif


#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_InitRxBasicCANSubSetMask
****************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE)  CanLL_InitRxBasicCANSubSetMask( CAN_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara, Can_HwHandleType hwObjHandle)
{
  vuint8 maskIdx;
  CanMsgObjStructPtr pCanCellMailbox;

  maskIdx = (vuint8)((initPara->mailboxHandle - Can_GetRxBasicHandleStart(canHwChannel)) + (initPara->initObject*CanNumberOfMaxBasicCAN));
  pCanCellMailbox = CAN_MAILBOX_PTR(hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  
  /* #10 Set acceptance mask and arbitration register */
# if defined( C_ENABLE_EXTENDED_ID )
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAR.reg16[0],                  Can_GetInitCodeL(maskIdx), 0xFFFFu, initPara ); /* SBSW_CAN_LL07 */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAMR.reg16[0],                 Can_GetInitMaskL(maskIdx), 0xFFFFu, initPara ); /* SBSW_CAN_LL07 */
#  if defined( C_ENABLE_MIXED_ID )
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAR.reg16[1],  C_OBJ_PRIO_16 | Can_GetInitCodeH(maskIdx), 0x3FFFu, initPara ); /* SBSW_CAN_LL07 */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAMR.reg16[1],                 Can_GetInitMaskH(maskIdx), 0x3FFFu, initPara ); /* SBSW_CAN_LL07 */
#  else /* ext_id only */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAR.reg16[1],  C_OBJ_PRIO_16 | C_EID_MASK_16 | Can_GetInitCodeH(maskIdx), 0x3FFFu, initPara ); /* SBSW_CAN_LL07 */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAMR.reg16[1], C_EID_MASK_16 | Can_GetInitMaskH(maskIdx), 0x3FFFu, initPara ); /* SBSW_CAN_LL07 */
#  endif
# else /* std_id only */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAR.reg16[1],  C_OBJ_PRIO_16 | Can_GetInitCodeH(maskIdx), 0x3FFFu, initPara ); /* SBSW_CAN_LL07 */
  CanLL_WriteReg16( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAMR.reg16[1], C_EID_MASK_16 | Can_GetInitMaskH(maskIdx), 0x3FFFu, initPara ); /* SBSW_CAN_LL07 */
# endif
}

/****************************************************************************
| NAME:             CanLL_InitRxBasicCANSubCloseMask
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE)  CanLL_InitRxBasicCANSubCloseMask(CAN_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara, Can_HwHandleType hwObjHandle) /* COV_CAN_NO_BASICCAN_FIFO_HANDLING */
{
  CanMsgObjStructPtr pCanCellMailbox;
  /* #10 Close the mask completely, no CAN ID will match */
  pCanCellMailbox = CAN_MAILBOX_PTR(hwObjHandle); /* PRQA S 2985 */ /* MD_Can_ConstValue */
  CanLL_WriteReg32( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAMR.reg32, C_MOAMR_CLOSE, 0x3FFFFFFFUL, initPara ); /* SBSW_CAN_LL07 */
  CanLL_WriteReg32( CAN_CHANNEL_CANPARA_FIRST &pCanCellMailbox->MoAR.reg32,  C_OBJ_PRIO_32, 0x3FFFFFFFUL, initPara ); /* SBSW_CAN_LL07 */
  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 4 END */
#endif

/****************************************************************************
| NAME:             CanLL_SetListCmd
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_SetListCmd(CAN_HW_CHANNEL_CANTYPE_FIRST CanModuleStructPtr pCanCellModule, vuint8 node, Can_HwHandleType hwObjHandle,  vuint16 PanCmd )
{
  vuint8 retVal = kCanOk;
  /* #10 Set panel command to configure the mailboxes */
  retVal &= CanLL_WaitForListReady(CAN_HW_CHANNEL_CANPARA_FIRST pCanCellModule); /* SBSW_CAN_LL03 */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
  pCanCellModule->PANAR  = (((vuint16)(node)) << 8) | ((vuint8)(hwObjHandle));   /* SBSW_CAN_LL03 */
  pCanCellModule->PANCMD = PanCmd;                                               /* SBSW_CAN_LL03 */
  return retVal;
}

/****************************************************************************
| NAME:             CanLL_WaitForListReady
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_WaitForListReady(CAN_HW_CHANNEL_CANTYPE_FIRST CanModuleStructPtr pCanCellModule ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  /* #10 Wait until the CAN cell is ready to receive the next command */
  vuint8 retVal = kCanOk;
#if defined( C_ENABLE_HW_LOOP_TIMER )
  CanLL_ApplCanTimerStart(kCanLoopListInit); /* SBSW_CAN_HL38 */
#endif
  do
  {
#if defined( C_ENABLE_HW_LOOP_TIMER )
    if ((vuint16)CanLL_ApplCanTimerLoop(kCanLoopListInit) == 0u) /* COV_CAN_HARDWARE_FAILURE */
    {
        retVal = kCanFailed;
        break;
    }
#endif
  }while ( (pCanCellModule->PANCMD & C_PAN_BUSY) == C_PAN_BUSY ); /* COV_CAN_PANEL_CMD */
#if defined( C_ENABLE_HW_LOOP_TIMER )
  CanLL_ApplCanTimerEnd(kCanLoopListInit); /* SBSW_CAN_HL38 */
#else
  CAN_HW_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  return retVal;
}

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/****************************************************************************
| NAME:             CanLL_IncSELPtr
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_IncSELPtr( CanMsgObjStructPtr pCanCellMailbox ) /* COV_CAN_NO_RXFIFO */
{
  /* #10 Increment Rx HW FIFO selection pointer */
  vuint8 MoFGPR_TOP = pCanCellMailbox->MoFGPR_TOP; /* ensure read order (MISRA) */
  if( pCanCellMailbox->MoFGPR_SEL == MoFGPR_TOP)
  {
    pCanCellMailbox->MoFGPR_SEL = pCanCellMailbox->MoFGPR_BOT; /* SBSW_CAN_LL06 */
  }
  else
  {
    pCanCellMailbox->MoFGPR_SEL = (vuint8)(pCanCellMailbox->MoFGPR_SEL+1u); /* SBSW_CAN_LL06 */
  }
}
#endif

/****************************************************************************
| NAME:             CanLL_Reset_MoCtr
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_Reset_MoCtr( CanChipMsgPtr16 regPtr, vuint16 value, vuint16 readMask, CanInitParaStructPtr initPara )
{
  /* #10 write register value */
  *regPtr = value; /* SBSW_CAN_HL35 */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) 
  if (initPara->doRamCheck == kCanExecuteRamCheck)
  {
    volatile vuint16 readBack;
    vuint8 result = kCanFalse;
    /* #20 read back value for RamCheck */
    readBack = *regPtr;
    if ((readBack & readMask) != (((vuint16)~value) & readMask)) /* COV_CAN_HARDWARE_FAILURE */
    {
      /* #30 return issue when read back value differs */
      result = kCanTrue;
    }
    initPara->isChRamCheckFail |= result; /* SBSW_CAN_HL36 */
  }
# else
  CAN_DUMMY_STATEMENT(readMask);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/****************************************************************************
| NAME:             CanLL_Set_MoCtr
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_Set_MoCtr( CanChipMsgPtr16 regPtr, vuint16 value, vuint16 readMask, CanInitParaStructPtr initPara )
{
  /* #10 write register value */
  *regPtr = value; /* SBSW_CAN_HL35 */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) 
  if (initPara->doRamCheck == kCanExecuteRamCheck)
  {
    volatile vuint16 readBack;
    vuint8 result = kCanFalse;
    /* #20 read back value for RamCheck */
    readBack = regPtr[-1];
    if ((readBack & readMask) != ((value) & readMask)) /* COV_CAN_HARDWARE_FAILURE */
    {
      /* #30 return issue when read back value differs */
      result = kCanTrue;
    }
    initPara->isChRamCheckFail |= result; /* SBSW_CAN_HL36 */
  }
# else
  CAN_DUMMY_STATEMENT(readMask);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

#if (CAN_SAFE_BSW == STD_ON)
/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_CheckGeneratedDataAccess()
****************************************************************************/
/*
|<DataModelStart>| CanLL_CheckGeneratedDataAccess
Relation_Context:
# from CanLL_InitBegin() #
ChannelAmount
Relation:
Variant, MultipleCanCells
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_CheckGeneratedDataAccess(CAN_CHANNEL_CANTYPE_ONLY)
{
  vuint8 retVal = kCanOk;
  CanChannelHandle physChannel = Can_GetNodeNum(canHwChannel); /* PRQA S 2842 */ /* MD_Can_Assertion */
  vuint8 physSrcIndex = Can_GetSrcNum(canHwChannel); /* PRQA S 2842 */ /* MD_Can_Assertion */
# if defined(C_ENABLE_MULTIPLE_CELLS)
  vuint8 cell, secondCellNodeOffset;
  cell = Can_GetCellInfoIdxOfCell(canHwChannel);
  secondCellNodeOffset = (vuint8)((cell == CAN_MULTICAN) ? 0u : 8u);
# endif
  /* #30 Check if the value of the accessed generated data is in the valid range for the current channel. */
# if defined(C_ENABLE_MULTIPLE_CELLS)
  if ((physChannel >= Can_GetMaxHwNodeAmountOfCellInfo(cell)) || (physSrcIndex >= Can_GetMaxHwNodeAmountOfCellInfo(cell))) /* CM_CAN_LL06 */ /* CM_CAN_LL07 */ /* COV_CAN_GENDATA_ERROR */
# else
  if ((physChannel >= CAN_MAX_HW_NODE_AMOUNT) || (physSrcIndex >= CAN_MAX_HW_NODE_AMOUNT)) /* CM_CAN_LL06 */ /* CM_CAN_LL07 */ /* COV_CAN_GENDATA_ERROR */
# endif
  {
    /* #40 If invalid value for the LogToPhys mapping is recognized set retVal to failed. */
    retVal = kCanFailed;
  }
# if defined(C_MULTIPLE_RECEIVE_CHANNEL) /* COV_CAN_LL_MULTIPLE_CHANNEL_ADDITIONAL_CHECK */
#  if defined(CAN_USE_PHYSTOLOG_MAPPING)
  /* #50 Check if the mapping of the physical channels to the corresponding logical channels is correct. */
#   if defined(C_ENABLE_MULTIPLE_CELLS)
  else if(Can_GetPhysToLogChannel(physChannel + secondCellNodeOffset) != canHwChannel) /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */ /* COV_CAN_GENDATA_ERROR */
#   else
  else if(Can_GetPhysToLogChannel(physChannel) != canHwChannel) /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */ /* COV_CAN_GENDATA_ERROR */
#   endif
  {
    /* #60 If invalid value for the PhysToLog mapping is recognized set retVal to failed. */
    retVal = kCanFailed;
  }
#  else
  else
  {
    /* #70 Determine the physical channel and check if it is mapped to an invalid logical channel. */
# if defined(C_ENABLE_MULTIPLE_CELLS)
    switch (physChannel + secondCellNodeOffset)
# else
    switch (physChannel)
# endif
    {
#   if defined(kCanPhysToLogChannelIndex_0) /* COV_CAN_CHANNEL_NOT_USED */
      case 0: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_0 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_1) /* COV_CAN_CHANNEL_NOT_USED */
      case 1: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_1 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_2) /* COV_CAN_CHANNEL_NOT_USED */
      case 2: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_2 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_3) /* COV_CAN_CHANNEL_NOT_USED */
      case 3: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_3 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_4) /* COV_CAN_CHANNEL_NOT_USED */
      case 4: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_4 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_5) /* COV_CAN_CHANNEL_NOT_USED */
      case 5: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_5 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_6) /* COV_CAN_CHANNEL_NOT_USED */
      case 6: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_6 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_7) /* COV_CAN_CHANNEL_NOT_USED */
      case 7: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_7 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_8) /* COV_CAN_CHANNEL_NOT_USED */
      case 8: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_8 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_9) /* COV_CAN_CHANNEL_NOT_USED */
      case 9: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_9 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_10) /* COV_CAN_CHANNEL_NOT_USED */
      case 10: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_10 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_11) /* COV_CAN_CHANNEL_NOT_USED */
      case 11: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_11 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_12) /* COV_CAN_CHANNEL_NOT_USED */
      case 12: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_12 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_13) /* COV_CAN_CHANNEL_NOT_USED */
      case 13: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_13 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_14) /* COV_CAN_CHANNEL_NOT_USED */
      case 14: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_14 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
#   if defined(kCanPhysToLogChannelIndex_15) /* COV_CAN_CHANNEL_NOT_USED */
      case 15: /* COV_CAN_CHANNEL_NOT_USED */
        if(kCanPhysToLogChannelIndex_15 != canHwChannel)  /* COV_CAN_CHANNEL_NOT_USED */
        {
          retVal = kCanFailed;
        }
        break;
#   endif
      default: /* COV_CAN_GENDATA_ERROR */
        retVal = kCanFailed;
        break;
    }
  }
#  endif /* CAN_USE_PHYSTOLOG_MAPPING */
# endif
  return retVal;
}
/* CODE CATEGORY 4 END */
#endif

/****************************************************************************
| NAME:             CanLL_ModeTransitionStart
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ModeTransitionStart(CAN_CHANNEL_CANTYPE_FIRST vuint8 silentMode)
{
  vuint16 ncr_local;
  CanNodeStructPtr pCanCellNode;
  pCanCellNode = CAN_NODE_PTR(Can_GetNodeNum(canHwChannel));
  /* #10 set mode according to configuration parameter */
  ncr_local = C_NCR_RESET;
#if !defined( C_ENABLE_ERROR_POLLING )
  ncr_local |=  C_NCR_ALIE;
#endif
#if defined( C_ENABLE_CAN_FD_USED )
  if (Can_GetIsChannelFd(channel))
  {
    ncr_local |= C_NCR_FDEN;
  }
#endif
#if defined( C_ENABLE_SILENT_MODE )
  if (silentMode == kCanTrue)
  {
    ncr_local |=  C_NCR_CALM;
  }
#else
  CAN_DUMMY_STATEMENT(silentMode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* #20 reset init to start can cell */
  pCanCellNode->NCR = ncr_local;  /* SBSW_CAN_LL01 */
  Can_SetHaltOfControllerData(canHwChannel, kCanFalse); /* SBSW_CAN_LL02 */
  Can_SetBusOffNotifiedOfControllerData(canHwChannel, kCanFalse); /* enable busoff detection after Init-flag is reset */ /* SBSW_CAN_LL02 */
  return kCanOk;
}

/****************************************************************************
| NAME:             CanLL_ModeTransitionStop
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ModeTransitionStop(CAN_CHANNEL_CANTYPE_ONLY)
{
  CanNodeStructPtr pCanCellNode;
  pCanCellNode = CAN_NODE_PTR(Can_GetNodeNum(canHwChannel));
  Can_SetHaltOfControllerData(canHwChannel, kCanOk);  /* SBSW_CAN_LL02 */
  /* #10 set init to stop can cell */
#if defined( C_ENABLE_CAN_FD_USED )
  if (Can_GetIsChannelFd(channel))
  {
    pCanCellNode->NCR = C_NCR_INIT | C_NCR_FDEN; /* SBSW_CAN_LL01 */
  }
  else
#endif
  {
    pCanCellNode->NCR = C_NCR_INIT; /* SBSW_CAN_LL01 */
  }
  return kCanOk;
}


#if defined( C_LL_INTERRUPT_ISR_ACTIVE )        /* ISR necessary; no pure polling configuration */
/* **************************************************************************
| NAME:             CanInterrupt<Name>
| CALLED BY:        CanIsr<Name>_<physicalChannelIndex>()
| PRECONDITIONS:
| INPUT PARAMETERS: canHwChannel
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt structure
|                   - check for the interrupt reason ( interrupt source )
|                   - work appropriate interrupt:
|                     + status/error interrupt (BUSOFF, wakeup, error warning)
|                     + basic can receive
|                     + full can receive
|                     + can transmit
|
|                   If an RX-Interrupt occurs while the CAN controller is in Sleep mode,
|                   a wakeup has to be generated.
|
|                   If an TX-Interrupt occurs while the CAN controller is in Sleep mode,
|                   an assertion has to be called and the interrupt has to be ignored.
|
|                   The name of BrsTimeStrt...() and BrsTimeStop...() can be adapted to
|                   really used name of the interrupt functions.
|
************************************************************************** */
/*
|<DataModelStart>| CanLL_CanInterruptDisable
Relation_Context:
# from Can_DisableControllerInterrupts #
IndividualPolling
TxPolling
RxPolling
StatusPolling
Relation:
OneChOpt
ChannelAmount
CanInterruptControl
UseNestedCANInterrupts
MultipleCanCells
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* CODE CATEGORY 1 START */
V_DEF_FUNC(V_NONE, void, CODE) CanInterrupt(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  CanObjectHandle hwObjHandle;
  vuint8  msgIdx, loopCounter;       /* access index for MSPND and MSID */
  vuint16 msid;         /* MSID register */
  vuint32 msgPndBit;    /* pending interrupt */
  CanModuleStructPtr pCanCellModule;
# if !defined( C_ENABLE_ERROR_POLLING)
  CanNodeStructPtr pCanCellNode;
  pCanCellNode = CAN_NODE_PTR(Can_GetNodeNum(canHwChannel));
# endif
# if (CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)
  Rtm_Start(RtmConf_RtmMeasurementPoint_CanInterrupt);
# endif

# if defined( C_ENABLE_NESTED_INTERRUPTS )
  CAN_ENABLE_GLOBAL_ISR();  /* nested on: enable Interrupts with higher priority */
# endif
  msgIdx=0;
  loopCounter=0;
  do
  { /* #10 loop over pending registers */
    pCanCellModule = CAN_MODULE_PTR;
# if defined( C_ENABLE_NESTED_INTERRUPTS )
    {
      CanDeclareGlobalInterruptOldStatus
      CanNestedGlobalInterruptDisable();
# endif
      pCanCellModule->MSIMask = Can_GetGlobalInterruptPendingMask((vuint8)(canHwChannel*CAN_MSPND_AMOUNT_MAX) + msgIdx); /* SBSW_CAN_LL03 */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
      msid = (vuint16)(pCanCellModule->MSID[msgIdx] & C_MSID_INDEX);
# if defined( C_ENABLE_NESTED_INTERRUPTS )
      CanNestedGlobalInterruptRestore();
    }
# endif
    if ((msid != C_MSID_RESET)) /* COV_CAN_STATUS_INTERRUPT_ONLY */
    { /* #20 for each pending interrupt, calculate the corresponding hwobject */
      loopCounter++;
      msgPndBit =   ((0x00000001UL)<<msid);                      /* calculate pending bit for mask */
      hwObjHandle = ((CanObjectHandle)msid + ((CanObjectHandle)msgIdx<<5)); /* calculate hwobject-index */ /* PRQA S 2983 */ /* MD_MSR_DummyStmt */

      /***************** Tx-Interrupts ***********************************************/
# if !defined( C_ENABLE_TX_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING )
      if ( (Can_GetTxInterruptPendingMask((vuint8)(canHwChannel*CAN_MSPND_AMOUNT_MAX) + msgIdx) & msgPndBit) == msgPndBit ) /* COV_CAN_TX_INTERRUPT */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
      { /* #30 Tx-Interrupt handling */
        pCanCellModule->MSPND[msgIdx] = ~msgPndBit; /* delete pending interrupt */ /* SBSW_CAN_LL03 */
        CanHL_TxConfirmation(CAN_CHANNEL_CANPARA_FIRST Can_GetMailboxHandle(hwObjHandle, canHwChannel), Can_GetMailboxElement(hwObjHandle, canHwChannel), hwObjHandle);
      }
      else
# endif
      {
      /***************** RxFull-Interrupts ***********************************************/
# if defined ( C_ENABLE_RX_FULLCAN_OBJECTS ) && (!defined (C_ENABLE_RX_FULLCAN_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING ))
        if ( (Can_GetRxFullInterruptPendingMask((vuint8)(canHwChannel*CAN_MSPND_AMOUNT_MAX) + msgIdx) & msgPndBit) == msgPndBit ) /* COV_CAN_INDIVIDUAL_POLLING */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
        { /* #40 RxFull-Interrupt handling */
          CanHL_FullCanMsgReceived( CAN_CHANNEL_CANPARA_FIRST Can_GetMailboxHandle(hwObjHandle, canHwChannel), hwObjHandle );
        }
        else
# endif
        {
        /***************** RxBasic-Interrupts ***********************************************/
# if defined ( C_ENABLE_RX_BASICCAN_OBJECTS ) && (!defined (C_ENABLE_RX_BASICCAN_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING ))
          if ( (Can_GetRxBasicInterruptPendingMask((vuint8)(canHwChannel*CAN_MSPND_AMOUNT_MAX) + msgIdx) & msgPndBit) == msgPndBit ) /* COV_CAN_INDIVIDUAL_POLLING */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
          { /* #50 RxBasic-Interrupt handling */
            CanHL_BasicCanMsgReceived( CAN_CHANNEL_CANPARA_FIRST Can_GetMailboxHandle(hwObjHandle, canHwChannel), hwObjHandle );
          }
          else
# endif
          {
            pCanCellModule->MSPND[msgIdx] = ~msgPndBit; /* delete pending interrupt */ /* SBSW_CAN_LL03 */
            Can_CallDetReportError(CAN_HW_ACCESS_ID, kErrorUnknownInterrupt);
          }
        }
      }
    } else {
      msgIdx++;
      loopCounter = 0;
    }
  }while((msgIdx<CAN_MSPND_AMOUNT) && (loopCounter < 32u)); /* COV_CAN_NOT_STIMULATEABLE */
# if !defined( C_ENABLE_ERROR_POLLING)
  /***************** Status-Interrupts *******************************************/
  if ( (pCanCellNode->NSR & C_NSR_ALERT) == C_NSR_ALERT ) /* COV_CAN_STATUS_INTERRUPT_ONLY */
  { /* #60 warning or busoff Status-Interrupt handling */
    pCanCellNode->NSR = pCanCellNode->NSR & ~C_NSR_ALERT; /* SBSW_CAN_LL01 */
    CanHL_ErrorHandling(CAN_CHANNEL_CANPARA_ONLY);
  }
# endif
# if (CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)
  Rtm_Stop(RtmConf_RtmMeasurementPoint_CanInterrupt);
# endif
} /* PRQA S 6030,6050,6080 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
/* CODE CATEGORY 1 END */
#endif

#define CAN_STOP_SEC_CODE  /*----------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/****************************************************************************/

/****************************************************************************/
/*  excluded Requirements                                                   */
/****************************************************************************/
/* part of other component: SPEC-1597 */
/* Currently no use-case / not supported: SPEC-1601, SPEC-1592, SPEC-1582 */

/****************************************************************************/
/*  MISRA deviations                                                        */
/****************************************************************************/
/* Justification for module-specific MISRA deviations:

MD_Can_Goto:
PRQA message 2001
  Reason: 'goto' statements are used to reduce code complexity.
  Risk: Incorrect jump.
  Prevention: Code inspection and runtime tests.

MD_Can_MultipleReturn:
PRQA message 2889
  Reason: Multiple return paths are used to reduce code complexity.
  Risk: Return a function too soon.
  Prevention: Code inspection and runtime tests.

MD_Can_ParameterName:
PRQA message 0784
  Reason: API parameter that is also used as a macro name is accepted for compatibility reasons.
  Risk: The macro can change the declaration unintentionally.
  Prevention: Relevant inconsistencies in function declarations, definitions and calls are detected by the compiler.

MD_Can_ConstValue:
PRQA message 2741, 2742, 2880, 2985, 2986, 2990, 2991, 2992, 2993, 2994, 2995, 2996
  Reason: Value is constant depending on configuration aspects or platform specific implementation. This leads to constant control expressions, unreachable code or redundant operations.
  Risk: Wrong or missing functionality.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_EmptyFunction:
PRQA message 2987
  Reason: Function is empty depending on configuration aspects and platform specific implementation.
  Risk: Function implementation missing.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_NoneConstParameterPointer:
PRQA message 3673
  Reason: Non-const pointer parameter is required by the internal interface or compatibility reasons but depending on the configuration or specific platform implementation the target may not always be modified.
  Risk: Read only data could be modified without intention.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_ModuleDefine:
PRQA message 0602, 0603
  Reason: Usage of reserved identifiers with leading underscores is accepted for compatibility reasons.
  Risk: Name conflicts.
  Prevention: Compile and link of the different variants in the component and integration test.

MD_Can_RedundantInit:
PRQA message 2981
  Reason: Reduce code complexity by using an explicit variable initializer that may be always modified before being used in some configurations.
  Risk: Unintended change of value.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_GlobalScope:
PRQA message 3218
  Reason: The usage of variables depends on configuration aspects and they may be used only once or defined globally to improve overview.
  Risk: None.
  Prevention: None.

MD_Can_ExternalScope:
PRQA message 1514, 3408, 3447, 3451, 3210
  Reason: The variable is used by other modules and can't be declared static.
  Risk: Name conflicts.
  Prevention: Compile and link of the different variants in the component and integration test.

MD_Can_GenData:
PRQA message 1533
  Reason: These constants are defined in a generated file and cannot be moved to the static source file.
  Risk: None.
  Prevention: None.

MD_Can_Union:
PRQA message 0750, 0759
  Reason: Using union type to handle different data accesses.
  Risk: Misinterpreted data.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_Assertion:
PRQA message 2842
  Reason: Assertion leads to apparent out of bounds indexing.
  Risk: Undefined behaviour.
  Prevention: Code inspection. Assertion itself detects out of bounds indexing.

MD_Can_PointerVoidCast:
PRQA message 0314, 0316
  Reason: API is defined with pointer to void parameter, so pointer has to be casted to or from void.
  Risk: Wrong data access or undefiend behavior for platforms where the byte alignment is not arbitrary.
  Prevention: Code inspection and test with the target compiler/platform in the component test.

MD_Can_PointerCast:
PRQA message 0310
  Reason: Different pointer type is used to access data.
  Risk: Wrong memory is accessed or alignment is incorrect.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_NoneVolatilePointerCast:
PRQA message 0312
  Reason: Cast to none volatile pointer.
  Risk: Incorrect multiple context access.
  Prevention: Code inspection checks that the value is not multiple accessed.

MD_Can_HwAccess:
PRQA message 0303
  Reason: Hardware access needs cast between a pointer to volatile object and an integral type.
  Risk: Access of unknown memory.
  Prevention: Runtime tests.

MD_Can_MixedSigns:
PRQA message 4393, 4394
  Reason: Casting from signed to unsigned types and vice versa is needed as different types are intentionally used.
  Risk: Value is changed during cast.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_IntegerCast:
PRQA message 4391, 4398, 4399, 4491
  Reason: Explicit cast to a different integer type.
  Risk: Value is changed during cast.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_CompilerAbstraction:
PRQA message 0342
  Reason: Glue operator used for compiler abstraction.
  Risk: Only K&R compiler support glue operator.
  Prevention: Compile test show whether compiler accept glue operator.

MD_Can_NoElseAfterIf:
PRQA message 2004
  Reason: No default handling needed for if-else-if here.
  Risk: Missing default handling.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_IncompleteForLoop:
PRQA message 3418
  Reason: Comma operator in for-loop header is used to get a compact code.
  Risk: Uninitialized variable.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_HL_UndefTypes:
ID 0841
  Reason: CBD types defined for CAN driver usage but should be not seen in other modules to avoid MSR-CBD mixture problems.
  Risk: None
  Prevention: None

MD_Can_NoDefaultInSwitch:
PRQA message 2002
  Reason: Return value is set beforehand and only modified within switch statement, nothing to do in default.
  Risk: Invalid return statement.
  Prevention: Return statement set beforehand.
  
*/

/****************************************************************************/
/*  Silent deviations                                                       */
/****************************************************************************/
/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_CAN_HL01
 \DESCRIPTION Write access to CanModeTransitionRequest with controller as index. Controller index is checked against sizeof CanModeTransitionRequest in Can_SetControllerMode(), Can_RamCheckExecute(), Can_MainFunction_Mode(), Can_Init() and Can_InitController().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL02
 \DESCRIPTION Write access to CanLogStatus with controller as index. Controller index is checked against sizeof CanLogStatus in Can_SetControllerMode(), CanHL_ErrorHandling(), Can_RamCheckEnableController(), Can_MainFunction_Mode(), Can_Init() and Can_InitController().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL04
 \DESCRIPTION Write access to CanActiveSendState with activeSendObject as index. activeSendObject is checked against size of ActiveSendObject in Can_CleanUpSendState(), CanHL_WritePrepare(), CanHL_InitTxFullCAN(), CanHL_InitTxBasicCAN(), CanHL_TxTaskCancelationHandling(), CanHL_TxConfirmation() and Can_CancelTx().
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL05
 \DESCRIPTION Write access to CanActiveSendPdu with activeSendObject as index. activeSendObject is checked against size of ActiveSendObject.
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL06
 \DESCRIPTION Call Can_GenericPrecopy() and CanIf_RxIndication() with parameter RX Queue data pointer. The data pointer is only used for read access and it is always a valid pointer (module local defined).
 \COUNTERMEASURE \R [CM_CAN_HL25]

\ID SBSW_CAN_HL07
 \DESCRIPTION Call Can_GenericPrecopy() and CanIf_RxIndication() with parameter Rx Struct data pointer. The data pointer is only used for read access. Parameter is of type P2CONST in API.
 \COUNTERMEASURE \N [CM_CAN_HL31]

\ID SBSW_CAN_HL08
 \DESCRIPTION Write access to CanIsBusOff with controller as index. Controller index is checked against sizeof CanIsBusOff in Can_SetControllerMode(), CanHL_ErrorHandling() and Can_Init().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL09
 \DESCRIPTION Write access to CanIsWakeup with controller as index. Controller index is checked against sizeof CanIsWakeup in CanHL_WakeUpHandling(), Can_CheckWakeup(), reinitialization and Can_Init().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL10
 \DESCRIPTION Write access to VersionInfo pointer within function Can_GetVersionInfo()
 \COUNTERMEASURE \N caller of Can_GetVersionInfo() has to ensure that VersionInfo pointer is valid. (global description available)

\ID SBSW_CAN_HL11
 \DESCRIPTION Write access to CanLastInitObject with controller as index. Controller index is checked against sizeof CanLastInitObject in Can_InitStruct(), Can_ChangeBaudrate(), Can_SetBaudrate() and Can_Init().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL12
 \DESCRIPTION Write access to CanInterruptCounter with controller as index. Controller index is checked against sizeof CanInterruptCounter in Can_Init(), Can_EnableControllerInterrupts() and Can_DisableControllerInterrupts()
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL16
 \DESCRIPTION Call CanLL_CanInterruptDisable() with parameter CanInterruptOldStatus as pointer (compiler secures used type in function declaration fitting to given pointer parameter type).
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL18
 \DESCRIPTION Write access to CanRxQueueBuffer with queue write index. Write index is checked against size of CanRxQueueBuffer.
 \COUNTERMEASURE \R [CM_CAN_HL24]

\ID SBSW_CAN_HL19
 \DESCRIPTION Write access to CanRxQueueBuffer.data with queue write index and data index. Write index is checked against size of CanRxQueueBuffer. (see also generator CM_CAN_HL04 qualified use case CSL02)
 \COUNTERMEASURE \R [CM_CAN_HL24]
                 \R [CM_CAN_HL17]

\ID SBSW_CAN_HL20
 \DESCRIPTION Write access to CanMirrorModeState with controller as index. Controller is checked against size of CanMirrorModeState.
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL22
 \DESCRIPTION Write access to ActiveSendData with activeSendData + length as index. Index is checked against size of table.
 \COUNTERMEASURE \R [CM_CAN_HL20]

\ID SBSW_CAN_HL23
 \DESCRIPTION Write access to ActiveSendObject stuct with activeSendObject as index. activeSendObject is checked against size of CanActiveSendObject.
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL24
 \DESCRIPTION Call Appl_GenericPreTransmit() with parameter PduInfoPtr_var pointer (module local defined).
 \COUNTERMEASURE \N The pointer is static and always valid.

\ID SBSW_CAN_HL25
 \DESCRIPTION Call CanIf_CancelTxConfirmation() with parameter CanActiveSendObject.PduInfo[activeSendObject] as pointer with activeSendObject as index. activeSendObject is checked against size of CanActiveSendObject.
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL26
 \DESCRIPTION Call CanHL_RxBasicMsgReceivedBegin(), CanHL_RxMsgReceivedNotification() and CanHL_RxBasicMsgReceivedEnd() with parameter rxBasicPara pointer (module local defined).
 \COUNTERMEASURE \N The pointer is static and always valid.

\ID SBSW_CAN_HL27
 \DESCRIPTION Call CanHL_RxFullMsgReceivedBegin(), CanHL_RxFullReceivedNotification() and CanHL_RxFullMsgReceivedEnd() with parameter rxFullPara pointer (module local defined).
 \COUNTERMEASURE \N The pointer is static and always valid.

\ID SBSW_CAN_HL29
 \DESCRIPTION Write access to rxBasicPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL30
 \DESCRIPTION Write access to rxFullPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL31
 \DESCRIPTION Call Initialization subroutines with initPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL32
 \DESCRIPTION Call Appl_GenericConfirmation and CanHL_SetCanPduInfo with canPdu pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL33
 \DESCRIPTION Write access to CanBusOffCounter with controller as index. Controller index is checked against sizeof CanBusOffCounter in Can_SetControllerMode(), CanHL_ErrorHandling() and Can_Init().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL34
 \DESCRIPTION Write access to CanMailboxState with mailbox handle as index. Index secured by ComStackLib [CM_CAN_HL29] and [CM_CAN_HL30] and checked against size of CanMailboxState.
 \COUNTERMEASURE \R [CM_CAN_HL28]

\ID SBSW_CAN_HL35
 \DESCRIPTION Call with pointer to CAN cell register for write and read access.
 \COUNTERMEASURE \N Caller ensures validity of pointer parameter.

\ID SBSW_CAN_HL36
 \DESCRIPTION Write access to initPara structure as pointer (local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL37
 \DESCRIPTION Call GetElapsedValue with timer value pointers as parameter (module local defined).
 \COUNTERMEASURE \N The timer values are static and always valid.

\ID SBSW_CAN_HL38
 \DESCRIPTION Call GetCounterValue with timer value (LoopTimeout) pointers as parameter. Controller index is checked against size of ControllerData, kCanLoopXXX as index in LoopTimeout table is always smaller than the dimension of the table given as static user type in ComStackLib and checked against this value.
 \COUNTERMEASURE \R [CM_CAN_HL01]
                 \R [CM_CAN_HL22]

\ID SBSW_CAN_HL39
 \DESCRIPTION Undefine preprocessor switch to stimulate user defined feature (only test purpose).
 \COUNTERMEASURE \N Redefinement activates a none documented feature.

\ID SBSW_CAN_HL40
 \DESCRIPTION Write access to CanLogStatus with controller as index. Controller is secured by qualified use-case CSL03 of ComStackLib.
 \COUNTERMEASURE \N [CM_CAN_HL02]

\ID SBSW_CAN_HL41
 \DESCRIPTION Write access to CanActiveSendState with activeSendObject as index. activeSendObject is temporary stored in a list of [1,3] elements where each element is initialized to a valid value and always written with size check before.
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL42
 \DESCRIPTION Write access to txPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL43
 \DESCRIPTION Write access to taskPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL44
 \DESCRIPTION Call task subroutines with taskPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL45
 \DESCRIPTION Call confirmation subroutines with txConfPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL46
 \DESCRIPTION Write access to txConfPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL47
 \DESCRIPTION Call cancellation subroutines with txCancellationPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL48
 \DESCRIPTION Write access to txCancellationPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL49
 \DESCRIPTION Call transmit subroutines with txPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL50
 \DESCRIPTION Write access to TxHwFifo member FillCount, WriteIndex and ReadIndex with Mailbox member TxHwFifo as Index. Index is checked against size of TxHwFifo array.
 \COUNTERMEASURE \R [CM_CAN_HL32]

\ID SBSW_CAN_HL51
 \DESCRIPTION Write access to ControllerModePtr pointer within function Can_GetControllerMode()
 \COUNTERMEASURE \N caller of Can_GetControllerMode() has to ensure that ControllerModePtr pointer is valid. (global description available)

\ID SBSW_CAN_HL52
 \DESCRIPTION Write access to ErrorStatePtr pointer within function Can_GetControllerErrorState()
 \COUNTERMEASURE \N caller of Can_GetControllerErrorState() has to ensure that ErrorStatePtr pointer is valid. (global description available)

\ID SBSW_CAN_HL53
 \DESCRIPTION Write access to TxErrorCounterPtr pointer within function Can_GetControllerTxErrorCounter()
 \COUNTERMEASURE \N caller of Can_GetControllerTxErrorCounter() has to ensure that TxErrorCounterPtr pointer is valid. (global description available)

\ID SBSW_CAN_HL54
 \DESCRIPTION Write access to RxErrorCounterPtr pointer within function Can_GetControllerRxErrorCounter()
 \COUNTERMEASURE \N caller of Can_GetControllerRxErrorCounter() has to ensure that RxErrorCounterPtr pointer is valid. (global description available)

\ID SBSW_CAN_HL55
 \DESCRIPTION A ComStackLib generated variable is accessed.
 \COUNTERMEASURE \N The variable is written using a generated macro of the CSL. It immediately dereferences the variables address without pointer arithmetic.

\ID SBSW_CAN_LL01
\DESCRIPTION Pointer write access to CAN Node register. The register structure is static and verified by review.
\COUNTERMEASURE \S [CM_CAN_LL01]
                \R [CM_CAN_HL01]
                \R [CM_CAN_LL06]

\ID SBSW_CAN_LL02
\DESCRIPTION Access to Can_SetHaltOfControllerData and Can_SetBusOffNotifiedOfControllerData with controller as index. Controller index is checked in: CanHL_ReInit, CanHL_ErrorHandling, Can_ChangeBaudrate, Can_SetBaudrate, Can_Init, Can_SetControllerMode, Can_RamCheckExecute, Can_RamCheckEnableController.
\COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_LL03
\DESCRIPTION Pointer write access to CAN Module register or passing as function parameter. The register structure is static and verified by review.
\COUNTERMEASURE \S [CM_CAN_LL01]

\ID SBSW_CAN_LL04
\DESCRIPTION Pointer write access to Clock Control register or passing as function parameter. The register structure is static and verified by review.
\COUNTERMEASURE \S [CM_CAN_LL01]

\ID SBSW_CAN_LL05
\DESCRIPTION Array write access to CAN Mailbox register. The register structure is static and verified by review. Array index is static or loop over static range, verified by review.
\COUNTERMEASURE  \S [CM_CAN_LL01]
                 \S [CM_CAN_LL04]
                 \R [CM_CAN_LL05]

\ID SBSW_CAN_LL06
\DESCRIPTION Pointer write access to CAN Mailbox Object register or passing as function parameter. The register structure is static and verified by review.
\COUNTERMEASURE  \S [CM_CAN_LL01]
                 \S [CM_CAN_LL04]
                 \R [CM_CAN_LL05]

\ID SBSW_CAN_LL07
\DESCRIPTION Passing CAN cell register pointer to CanLL_WriteReg*, CanLL_Set_MoCtr, CanLL_Reset_MoCtr. The register structure is static and verified by review.
             Passing initPara pointer to CanLL_WriteReg*, CanLL_Set_MoCtr, CanLL_Reset_MoCtr. The caller defines the struct locally and is always valid (pointer to a local stack variable).
\COUNTERMEASURE  \S [CM_CAN_LL01]
                 \S [CM_CAN_LL03]
                 \S [CM_CAN_LL04]
                 \R [CM_CAN_HL01]
                 \R [CM_CAN_LL05]
                 \R [CM_CAN_LL06]
                 
\ID SBSW_CAN_LL09
\DESCRIPTION Pointer write access to interrupt source register(ISR) or passing as function parameter.
\COUNTERMEASURE  \S [CM_CAN_LL02]
                 \R [CM_CAN_HL01]
                 \R [CM_CAN_LL07]

\ID SBSW_CAN_LL10
\DESCRIPTION Array write access to TmpRxMailbox with controller as index. Controller index is checked in: CanHL_BasicCanMsgReceived, CanHL_FullCanMsgReceived.
\COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_LL11
\DESCRIPTION Pointer write access to txConfPara, rxBasicPara, rxFullPara, txPara struct.
\COUNTERMEASURE \N Caller ensures valid pointer.

\ID SBSW_CAN_LL12
\DESCRIPTION Array write access to txConfPara struct. Array index is static and verified by review.
\COUNTERMEASURE \N Caller ensures valid pointer.

\ID SBSW_CAN_LL13
\DESCRIPTION Array write access to locally defined variable var_MoDR.
\COUNTERMEASURE \N Variable is locally defined, index is static, compiler ensures correct behavior.

\ID SBSW_CAN_LL14
\DESCRIPTION Passing CAN cell FD layout mailbox pointer and data pointer to CanLL_WriteFdData, CanLL_ReadFdData. The FD layout mailbox pointer structure is static and verified by review.
             Array index of the data pointer is static or loop over static range, verified by review. Data access index doesn't exceed message length, verified by review.
\COUNTERMEASURE \S [CM_CAN_LL01]
                \R [CM_CAN_LL04]
                \R [CM_CAN_LL05]

\ID SBSW_CAN_LL17
\DESCRIPTION Pointer write access to Can_GetCanInterruptOldStatus.
\COUNTERMEASURE \N Caller ensures valid pointer.

\ID SBSW_CAN_LL18
\DESCRIPTION Array write access to data pointer. 
\COUNTERMEASURE \N Array index loop over static range, verified by review. Frame length limited to FD mailbox layout.

\ID SBSW_CAN_LL19
 \DESCRIPTION Passing return value pointer to osIsInterruptSourceEnabled.
 \COUNTERMEASURE \N The pointer has a static type and always references a local variable.

SBSW_JUSTIFICATION_END */

/* Counter measurement description

\CM CM_CAN_HL01 A runtime check ensures controller index is always smaller than number of elements in arrays with controller amount as dimension (Qualified use-case CSL01 of ComStackLib size of ControllerData).
\CM CM_CAN_HL02 Qualified use-case CSL03 of ComStackLib (CanMailbox.ControllerConfigIdx is always in range of controller ControllerData)
\CM CM_CAN_HL03 A runtime check ensures activeSendObject index is in valid range for Can_ActiveSendObject table (Qualified use-case CSL01 of ComStackLib - Can_ActiveSendObject size is extended by CAN_MULTIPLEXED_TX_MAX within generator to allow an access to logObjHandle+CAN_MULTIPLEXED_TX_MAX).
\CM CM_CAN_HL17 A runtime check ensures DLC index is always smaller than the dimension of CanRxQueueBuffer.data.
\CM CM_CAN_HL18 A runtime check ensures HRH values is always in range of start stop index of the given mailbox type. (Qualified use-case CSL03 of ComStackLib - start-stop index fit to mailbox entrys)
\CM CM_CAN_HL20 A runtime check ensures size of ActiveSendData (dataByte). For CAN-FD it is checked against the size of the table. For none CAN-FD size is checked against 8 as defined.
\CM CM_CAN_HL22 A runtime check ensures source index for LoopTimeout array is always smaller than the dimension of LoopTimeout.
\CM CM_CAN_HL24 A runtime check ensures RxQueue write index is always smaller than the dimension of RxQueue (Qualified use-case CSL01 of ComStackLib).
\CM CM_CAN_HL25 A runtime check ensures RxQueue read index is always smaller than the dimension of RxQueue (Qualified use-case CSL01 of ComStackLib).
\CM CM_CAN_HL28 A runtime check ensures htrh index is always smaller than the dimension of CanMailboxState (Qualified use-case CSL01 of ComStackLib).
\CM CM_CAN_HL29 Qualified use-case CSL02 of ComStackLib (size of CanMailboxState == size of CanMailbox) 
\CM CM_CAN_HL30 Qualified use-case CSL03 of ComStackLib (CanMailbox - CanController Start/Stop HtrhIndex).
\CM CM_CAN_HL31 valid mailbox data area is assigned to rxStruct.pChipData pointer (Has to be given by LL implementation part).
\CM CM_CAN_HL32 A runtime check ensures TxHwFifo index is always smaller than the dimension of TxHwFifo (Qualified use-case CSL01 of ComStackLib).

\CM_CAN_LL01 The can cell kCanBaseAdr/Can_CellInfo.BaseAdr is verified by user review [SMI-1042].
\CM_CAN_LL02 The can cell kCanSRCAdr/Can_CellInfo.SrcAdr is verified by user review [SMI-1042].
\CM_CAN_LL03 The can cell CAN_MAX_HW_NODE_AMOUNT/Can_CellInfo.MaxHwNodeAmount is verified by user review [SMI-275008].
\CM_CAN_LL04 The can cell CAN_MAX_MAILBOX_AMOUNT/Can_CellInfo.MaxMailboxAmount is verified by user review [SMI-275008].
\CM_CAN_LL05 CAN_HWOBJ_SAFE_MASK limits mailbox access to the amount of available mailboxes.
\CM_CAN_LL06 A runtime check ensures that Can_GetNodeNum() returns a node smaller CAN_MAX_HW_NODE_AMOUNT/Can_CellInfo.MaxHwNodeAmount.
\CM_CAN_LL07 A runtime check ensures that Can_GetSrcNum() returns a node smaller CAN_MAX_HW_NODE_AMOUNT/Can_CellInfo.MaxHwNodeAmount.

*/

/****************************************************************************/
/*  Coverage Justification                                                  */
/****************************************************************************/
/* START_COVERAGE_JUSTIFICATION

\ID COV_CAN_COMPATIBILITY
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT TX xf xf
  \ACCEPT XF tf tf
  \REASON The condition checks whether a switch is defined and conditionally assigns a default value. This is used to ensure compatibility to older AUTOSAR/Component versions. 

\ID COV_CAN_INTERNAL
  \ACCEPT XF
  \ACCEPT TX
  \REASON This switch is always active within CAN driver context. Secure visibility of internal interface and cannot be stimulated to off while test. The code is verified by code inspection.

\ID COV_CAN_CANCEL_SW_STIMULATION
  \ACCEPT TF
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XX
  \ACCEPT TF tf xf
  \REASON It is not possible to stimulate a sw cancellation while the message is already start to send when hw cancellation is active. The code is verified by code inspection.

\ID COV_CAN_AMD_RUNTIME_MEASUREMENT
  \ACCEPT XF
  \REASON The feature AMD Runtime Measurement is not supported for SafeBSW. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_FINALMAGICNUMBER
  \ACCEPT TX
  \REASON Switch is always true is OK here no side effect will occur when switch is false verified by review.

\ID COV_CAN_SAFE_BSW_EXCLUSION
  \ACCEPT XF xf xf
  \REASON SafeBsw restricted feature will not be enforced to be deactivated or activated.

\ID COV_CAN_BUSOFF_NOT_IN_ALL_CONFIG
  \ACCEPT X
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT TF tf tx
  \ACCEPT TX tx tx
  \REASON BUSOFF not stimulated in each configruation. The behavior does not depend on each configuration variant but TCASE-274 takes long runtime and will not be executed for each configuration.   

\ID COV_CAN_WAKEUP_CHANNEL_NOT_IN_ALL_CONFIG
  \ACCEPT XF
  \ACCEPT TX
  \REASON Wakeup may be always activated or deactivated depend on configuration. Not all configurations contain activated or deactivated wakeup for at least one controller, but is sufficiantly tested in some configuations with both settings.

\ID COV_IMPLICITE_TXCANCEL
  \ACCEPT TX
  \REASON In some configurations there will be no recancellation but for this case there is no active code (empty else), so this is not really a test case.

---------------- LL ------------------

\ID COV_CAN_MULTIPLE_BASICCAN_TX
  \ACCEPT TF
  \ACCEPT TF tf tf
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_SLEEP_SUPPORT
  \ACCEPT XF
  \REASON The feature is platform specific. Tricore does not support sleep/wakeup.

\ID COV_CAN_WAKEUP_SUPPORT
  \ACCEPT XF
  \REASON The feature is platform specific. Tricore does not support sleep/wakeup.

\ID COV_CAN_TX_POLLING
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_POLLING
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_BASICCAN_POLLING
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_FULLCAN_POLLING
  \ACCEPT TF
  \REASON The feature configuration specific - fully supported.

\ID COV_CAN_ERROR_POLLING
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_WAKEUP_POLLING
  \ACCEPT XF
  \REASON The feature is platform specific. Tricore does not support sleep/wakeup.

\ID COV_CAN_INDIVIDUAL_POLLING
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XX
  \REASON Gendata failure OR FullCAN Rx raised the IR and BasicCAN Rx is configured as polling or vice versa.

\ID COV_CAN_TX_POLLING_OR_CANCEL_IN_HW_TASK
  \ACCEPT TF tf tf tx
  \ACCEPT TF tf tf xf
  \REASON The feature is platform specific - C_HL_ENABLE_CANCEL_IN_HW_TASK is always true or false.

\ID COV_CAN_GENERIC_CONFIRMATION_API2
  \ACCEPT TF
  \REASON The feature is platform and Project specific - fully supported.

\ID COV_CAN_FD_SUPPORT
  \ACCEPT TF
  \REASON The feature is platform and Project specific - fully supported.

\ID COV_CAN_MULTIPLE_BASICCAN
  \ACCEPT TF
  \REASON The feature is platform and Project specific - fully supported.

\ID COV_CAN_TX_FULLCAN_OBJECTS
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_FULLCAN_OBJECTS
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_HW_TRANSMIT_CANCELLATION
  \ACCEPT XF
  \REASON The feature is platform specific. Tricore does not support cancel.

\ID COV_CAN_CANCEL_IN_HW
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_HARDWARE_CANCELLATION
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_EXTENDED_ID
  \ACCEPT XF
  \ACCEPT TX
  \REASON Low level token is used for for different positions with different preprocessor context.

\ID COV_CAN_MIXED_ID
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_OVERRUN_NOTIFICATION
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_MULTIPLEXED_TRANSMISSION
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_TX_HW_FIFO
  \ACCEPT XF
  \REASON The feature is not supported.

\ID COV_CAN_RX_QUEUE
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_HW_LAYOUT_TXBASIC_FIRST
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_TX_FULLCAN_HWHANDLE_REVERSE
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_RX_FULLCAN_HWHANDLE_REVERSE
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_BASICCAN_HWHANDLE_REVERSE
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_EXTENDED_STATUS
  \ACCEPT TX
  \REASON The feature is platform specific - always active.

\ID COV_CAN_OVERRUN_IN_STATUS
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_RxBasicMsgReceivedBegin
  \ACCEPT TX
  \REASON The feature is platform specific - always active.

\ID COV_CAN_RxFullMsgReceivedBegin
  \ACCEPT TX
  \REASON The feature is platform specific - always active.

\ID COV_CAN_HW_EXIT_TRANSMIT
  \ACCEPT TX
  \REASON The feature is platform specific - always active.

\ID COV_CAN_HARDWARE_FAILURE
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XF xf
  \ACCEPT XF xf xf
  \ACCEPT TF tf tx
  \ACCEPT TF xf tf
  \ACCEPT XF xf xx
  \ACCEPT TF tf xf
  \ACCEPT TF tf tf xf
  \ACCEPT XF xf tf xf
  \ACCEPT XF xf xf xf xf
  \ACCEPT XF xf xf xf xf xf
  \ACCEPT XF xf xf xf xf xf xf xf xf xf
  \REASON The condition checks for hardware failures that cannot be stimulated. The code is verified by code inspection.

\ID COV_CAN_LL_HARDWARE_BEHAVIOUR
  \ACCEPT TX
  \REASON The condition checks for hardware depended return value. The return value is always true because hardware never fail here. The code is verified by code inspection.

\ID COV_CAN_GENDATA_FAILURE
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT TX tx tx
  \ACCEPT XF xf xf
  \ACCEPT TF tf xf
  \ACCEPT TF tx tf
  \ACCEPT TF xf tf
  \ACCEPT TF tx tf tf
  \ACCEPT TF xf tf xf tf
  \REASON The condition checks for generated data failures that cannot be simulated. The code is verified by code inspection.

\ID COV_CAN_GENDATA_NOT_IN_ALL_CONFIG
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT X
  \REASON Generated data does not contain all data sets but checked in code. Not encapsulated with preprocessor switch to simplify code.  

\ID COV_CAN_OS_USAGE
  \ACCEPT TX
  \ACCEPT TX xf tx
  \ACCEPT TX tx xf
  \ACCEPT XF
  \ACCEPT XF xf tx
  \ACCEPT XF tf tf
  \REASON Os may be used in component test or not. The code is verified by code inspection.

\ID COV_CAN_LOCK_ISR_BY_APPL
  \ACCEPT TX tf tf
  \ACCEPT TF xf tf 
  \REASON CAN interrupts never locked by application only within tests. It is not part of the component test to check application code. The code is verified by code inspection.

\ID COV_CAN_RAM_CHECK
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RAM_CHECK_EXTENDED
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_TIMEOUT_DURATION
  \ACCEPT TF
  \REASON Hardware loop time out is platform specific never reached.

\ID COV_CAN_TRANSITION_REQUEST
  \ACCEPT X
  \ACCEPT TX
  \ACCEPT XF
  \REASON Mode transition is platform specific always true or false.

\ID COV_CAN_BASICCAN_SEARCH_LINEAR
  \ACCEPT TX
  \ACCEPT TF tx tf
  \ACCEPT TX tx tx
  \REASON Received BasicCAN mailbox is always a valid object and found while search.

\ID COV_CAN_FULLCAN_SEARCH_LINEAR
  \ACCEPT TX
  \ACCEPT TF tx tf
  \REASON Received FullCAN mailbox is always a valid object and found while search.

\ID COV_CAN_RAM_CHECK_NO_STIMULATION
  \ACCEPT X
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XF xf xf
  \ACCEPT TF tf xf
  \REASON some configurations do not stimulate RamCheck by test suite, to check the standard CAN driver behavior.

\ID COV_CAN_SAFE_BSW
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_HWOBJINDIVPOLLING
  \ACCEPT TF
  \ACCEPT TX
  \REASON The feature is platform specific. For Tricore this is always true if CANFD Full is configured.

\ID COV_CAN_MISRA
  \ACCEPT XF
  \ACCEPT TX
  \REASON only used for MISRA analysis not active in production code.

\ID COV_CAN_MULTIPLE_DRIVERS
  \ACCEPT XF
  \ACCEPT TX
  \REASON The feature Multiple CAN drivers is not supported for SafeBSW (BETA feature). A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_FIFO_FULL_NOTIFICATION
  \ACCEPT XF
  \REASON The feature FIFO Full notification is development feature and not supported for SafeBSW. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_DISABLE_ISR_PROTOTYPE
  \ACCEPT TX
  \REASON The feature "Disable ISR Prototype" is not supported for SafeBSW. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_PRIOBYID
  \ACCEPT TX
  \ACCEPT TX xf xf
  \REASON The feature Prio By CAN ID is default and must not be deactivated for SafeBSW. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_EQUAL_CHANNEL_LAYOUT
  \ACCEPT TX
  \ACCEPT XF
  \REASON The test is executed on defined channels. The channel layout is equal for each channel.

\ID COV_CAN_BUSOFF_NOTIFICATION
  \ACCEPT XF tx xf xx
  \ACCEPT TF tx tf tx
  \ACCEPT TF tf tf tx
  \ACCEPT TF tf tf tf tf xf tf tf tf tf xx tx
  \REASON Busoff notification is called only for one time, set init flag is mandatory otherwise a hardware failure had happened, in STOP mode no busoff is possible -> defensive programming

\ID COV_CAN_DERIVATIVE_SWITCH
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XF xf xf
  \REASON Only one derivative can be tested for one time. To check supported derivatives, please look for the "Equivalent Hardware Checklist"

\ID COV_CAN_CANCLOCKDIVIDOR
  \ACCEPT TX
  \REASON Must be defined for ASR4 and SafeBSW. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_MCR
  \ACCEPT TX
  \ACCEPT TX tx tx
  \ACCEPT TX tf tx
  \REASON Must be defined for Aurix derivatives. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_GENDATA_ERROR
  \ACCEPT X
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XF xf xf
  \ACCEPT XF xf xf xf xf
  \REASON The condition checks for generated data failures that cannot be simulated. The code is verified by code inspection.

\ID COV_CAN_MULTIPLE_CELL_MASK
  \ACCEPT XF
  \ACCEPT TX
  \REASON The Hardware message object for multiple cells could only select one cell according to configuration.

\ID COV_CAN_CHANNEL_NOT_USED
  \ACCEPT X
  \ACCEPT XF
  \ACCEPT TX
  \REASON Depends on configuration, some channels are not used and/or not available in certain derivatives.

\ID COV_CAN_BASICCAN_FULLCAN_FD_TYPE_DIFFER
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XX
  \REASON In some configuration Basic CAN and Full CAN are with different FD type (e.g. Basic CAN FD FULL used while Full CAN use FD none). C_ENABLE_CAN_FD_FULL is defined then, which will cause some code not covered during runtime.

\ID COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG
  \ACCEPT TF tf tx
  \ACCEPT TF tx tf
  \ACCEPT TF tf tx tx
  \ACCEPT TF tx tf tf
  \ACCEPT TF tf tx tf
  \ACCEPT TF tf tf tx
  \ACCEPT TF tx tf tx
  \ACCEPT TF tf tf tx tf
  \ACCEPT TF tf tx tx tf
  \ACCEPT TF tx tf tx tf
  \REASON Generated data does not contain all data sets but checked in code. Not encapsulated with preprocessor switch to simplify code.
  
\ID COV_CAN_AURIX_DERIVATIVE
  \ACCEPT TX
  \ACCEPT XF tf tx
  \REASON Code only valid for AURIX derivatives, other derivatives not relevant. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_COM_STACK_LIB
  \ACCEPT TX
  \ACCEPT TF tx tf
  \REASON Comstacklib is obligatory for SAFE-BSW. Else path needed for compatibility with Canbedded

\ID COV_CAN_kCanISRPrio
  \ACCEPT XF
  \ACCEPT TX
  \REASON ISR Prio is used or not, not all 15 IR priorities are possible to be varied.

\ID COV_CAN_INTERRUPT_CONTROL
  \ACCEPT TX
  \ACCEPT TX xf xf
  \ACCEPT XF tf tf
  \REASON Interrupt control is always active. To deactivate this is a non documented, non safety feature. A precompile check ensures that the switch is not set.

\ID COV_CAN_NOT_STIMULATEABLE
  \ACCEPT XF xf xx
  \ACCEPT TF tf tx
  \ACCEPT XF xf tf xf
  \REASON some configurations do not stimulate timer loop.

\ID COV_NISO_PED
  \ACCEPT XF
  \REASON No hardware available yet which supports the feature NISO and PED

\ID COV_CAN_VSTDLIB_USE
  \ACCEPT XF
  \ACCEPT TX
  \REASON special use case, not configurable by generation tool

\ID COV_CAN_CORE0_USED
  \ACCEPT TX
  \ACCEPT XF tx xf
  \REASON The test is executed on one defined core. The behavior of the cores are equal.

\ID COV_CAN_DECISION_NOT_SWITCHABLE_WITHOUT_MULTIPLEBASICCAN
  \ACCEPT X
  \ACCEPT TX
  \ACCEPT XF
  \REASON If only one Rx/Tx Basic CAN message is configured, several parameter like object length, FIFO size or "polling" can not vary within one configuration.

\ID COV_CAN_DOUBLE_RECEPTION
  \ACCEPT XF
  \REASON Second message is received before the first is actually processed. For test, it is not possible to hit this time slot definitely.

\ID COV_CAN_TX_INTERRUPT
  \ACCEPT TX
  \ACCEPT XF
  \REASON If only Tx is configured with interrupt, this decision is always true. If Tx is only individual polling, , this decision is always false.

\ID COV_CAN_NO_RXFIFO
  \ACCEPT X
  \REASON If all Rx Basic CAN objects are configured as CANFD Full, no RX FIFO is available.

\ID COV_CAN_TESTSUITE_NOT_APPLICABLE_WITH_LOCKED_IR
  \ACCEPT TX
  \REASON This decision could only be stimulated if test suite would start up with locked global interrupts, this is not applicable.

\ID COV_CAN_PANEL_CMD
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT TF tf xf
  \REASON CPU needs to wait for CAN during writing a panel command. This may happen without any delay or not.

\ID COV_CAN_LL_MULTIPLE_CHANNEL_ADDITIONAL_CHECK
  \ACCEPT TX
  \REASON These are additional checks for multiple channel configurations. If single channel applies, these checks are not necessary.
  
\ID COV_CAN_BASICCAN_FULLCAN_FD_DATA_LEN_DIFFER
  \ACCEPT TX
  \ACCEPT XF
  \REASON In some configurations Basic CAN and Full CAN are with different FD data len (e.g. Basic CAN FD FULL used while Full CAN use FD BRS). C_ENABLE_CAN_FD_FULL is defined then, which will cause some code not covered during runtime.

\ID COV_CAN_NO_BASICCAN_FIFO_HANDLING
  \ACCEPT X
  \ACCEPT TX
  \REASON No basic can with with FIFO handling configured. This happens if in every basic can, at least one message, has a message length bigger than 8 (occurs in FD configurations).

\ID COV_CAN_STATUS_INTERRUPT_ONLY
  \ACCEPT TX
  \ACCEPT XF
  \REASON Rx/Tx pure polling. Busoff processing in ISR context.
  
\ID COV_CAN_FDMSG_WRITE_INDEX_CHECK
  \ACCEPT TF tf tx
  \REASON Ensure array index will not exceed FD data mailbox index, with valid data length the second condition is always true.

END_COVERAGE_JUSTIFICATION */ 

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 879 */

