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

#if !defined(CAN_LOCAL_H)
#define  CAN_LOCAL_H

/***************************************************************************/
/* Include                                                                 */
/***************************************************************************/
/* \trace SPEC-1583 */
#include "SchM_Can.h"
#include "Can.h"         /* include also all needed types */

/***************************************************************************/
/* Version Check                                                           */
/***************************************************************************/
/* \trace SPEC-20329 */
/* not the SW version but all file versions that represent the SW version are checked */
#if (CAN_COREVERSION           != 0x0800u) /* \trace SPEC-1699 */
# error "Header file are inconsistent!"
#endif
#if (CAN_RELEASE_COREVERSION   != 0x01u)
# error "Header file are inconsistent!"
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

/* PRQA S 3453 EOF */ /* MD_MSR_FctLikeMacro */

/***************************************************************************/
/* compatibility defines                                                   */
/***************************************************************************/
#if defined(C_ENABLE_MIXED_ID) || defined(C_ENABLE_EXTENDED_ID)
# define CAN_ID_IDE_MASK            0x80000000UL
# define CAN_ID_FD_MASK             0x40000000UL /* \trace SPEC-50553 */
# define CAN_ID_MASK                0x1FFFFFFFUL
# define CAN_ID_MASK_STD            0x000007FFUL
# define CAN_ID_UNUSED_MASK         0x20000000UL
#else
# define CAN_ID_IDE_MASK            0x0000U
# define CAN_ID_FD_MASK             0x4000U /* \trace SPEC-50553 */
# define CAN_ID_MASK                0x07FFU
# define CAN_ID_MASK_STD            0x07FFU
# define CAN_ID_UNUSED_MASK         0x3800U
#endif
#define kCanAllChannels  ((CanChannelHandle)0xFFU)

#if !defined(C_DRV_INTERNAL) /* COV_CAN_INTERNAL */
# error "Can_Local.h should only be included by Can.c"
#endif
/* real amount of controllers in this system (LT and PB) */
#define kCanNumberOfChannels  Can_GetControllerMax()
/* if kCanNumberOfChannels used to declare a table/dimension this table has to be generated to be also Link-Time-capable */
/*  -> see ESCAN00028069 controller-amount has to be Link-Time-capable */
/* real amount of controllers in this system (LT and PB) */
#define kCanNumberOfHwChannels  kCanNumberOfChannels

#if defined( C_SINGLE_RECEIVE_CHANNEL )
/* have to be done here to avoid declaration of "channel" in Can.h */
# define channel                                ((CanChannelHandle)0)
# define canHwChannel                           ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STARTINDEX(ch)       ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STOPINDEX(ch)        ((CanChannelHandle)0)
#else
# define channel                                Controller
# define canHwChannel                           Controller
# define CAN_HL_HW_CHANNEL_STARTINDEX(ch)       (ch)
# define CAN_HL_HW_CHANNEL_STOPINDEX(ch)        (ch)
#endif
#if !defined(CAN_TRANSITION_CHECK) /* COV_CAN_COMPATIBILITY */
# define CAN_TRANSITION_CHECK STD_ON /* default may be deactivated by user configuration */
#endif
#if !defined(CAN_REINIT_START) /* COV_CAN_COMPATIBILITY */
# define CAN_REINIT_START STD_OFF
#endif

#if !defined(CAN_OS_TICK2MS) /* COV_CAN_COMPATIBILITY */
# error "CAN_OS_TICK2MS() should be defined to OS_TICKS2MS_<counterShortName>() macro from OS"
#endif
#if !defined(CAN_OS_COUNTER_ID) /* COV_CAN_COMPATIBILITY */
# error "CAN_OS_COUNTER_ID should be defined to 'counterShortName' from OS"
#endif

#if !defined(CAN_ID_MASK_IN_GENERIC_CALLOUT) /* COV_CAN_COMPATIBILITY */
# define CAN_ID_MASK_IN_GENERIC_CALLOUT (CAN_ID_IDE_MASK | CAN_ID_FD_MASK | CAN_ID_MASK)
/* May be changed to mask out FD-bit: (CAN_ID_IDE_MASK | CAN_ID_MASK) */
#endif

/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
/* for variable Can_ActiveSendState */
#define kCanBufferFree              (uint8)0xFF     /* mark objects as free */
#define kCanBufferCancel            (uint8)0xFE     /* mark object as currently cancelling */
#define kCanBufferCancelSw          (uint8)0xFD
#define kCanBufferSend              (uint8)0x01     /* occupied send object */

/* HL return values */
#define kCanFailed                  (uint8)0x00     /* similar to CAN_NOT_OK but value may differ --> converted in HL (LL only use kCan...) */
#define kCanOk                      (uint8)0x01     /* similar to CAN_OK */
#define kCanRequested               (uint8)0x03

#define kCanFalse                   kCanFailed
#define kCanTrue                    kCanOk

#define Can_GetControllerMax()                        Can_GetSizeOfControllerData()
#define Can_GetCanToCanIfChannelMapping(Index)        Can_GetCanIfChannelId((Index))

/* ControllerConfig */
#define Can_GetCanControllerDefaultBaudrate(logCh)    Can_GetCanControllerDefaultBaudrateOfControllerConfig(logCh)
#define Can_GetCanControllerDefaultBaudrateIdx(logCh) Can_GetCanControllerDefaultBaudrateIdxOfControllerConfig(logCh)
#if !defined(Can_GetMailboxRxBasicLengthOfControllerConfig) /* If no Object is available ComStackLib do not generate start-stop index */
# define Can_GetMailboxRxBasicLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxRxBasicStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxRxBasicEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetRxBasicHandleMax(logCh)                Can_GetMailboxRxBasicLengthOfControllerConfig(logCh)
#define Can_GetRxBasicHandleStart(logCh)              (Can_HwHandleType)Can_GetMailboxRxBasicStartIdxOfControllerConfig(logCh)
#define Can_GetRxBasicHandleStop(logCh)               (Can_HwHandleType)Can_GetMailboxRxBasicEndIdxOfControllerConfig(logCh)
#define Can_GetRxBasicHwStart(logCh)                  Can_GetRxBasicHwStartOfControllerConfig(logCh)
#define Can_GetRxBasicHwStop(logCh)                   Can_GetRxBasicHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxRxFullLengthOfControllerConfig)
# define Can_GetMailboxRxFullLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxRxFullStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxRxFullEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetRxFullHandleMax(logCh)                 Can_GetMailboxRxFullLengthOfControllerConfig(logCh)
#define Can_GetRxFullHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxRxFullStartIdxOfControllerConfig(logCh)
#define Can_GetRxFullHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxRxFullEndIdxOfControllerConfig(logCh)
#define Can_GetRxFullHwStart(logCh)                   Can_GetRxFullHwStartOfControllerConfig(logCh)
#define Can_GetRxFullHwStop(logCh)                    Can_GetRxFullHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxTxBasicLengthOfControllerConfig) /* COV_CAN_GENDATA_FAILURE */
# define Can_GetMailboxTxBasicLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxTxBasicStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxTxBasicEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetTxBasicHandleMax(logCh)                Can_GetMailboxTxBasicLengthOfControllerConfig(logCh)
#define Can_GetTxBasicHandleStart(logCh)              (Can_HwHandleType)Can_GetMailboxTxBasicStartIdxOfControllerConfig(logCh)
#define Can_GetTxBasicHandleStop(logCh)               (Can_HwHandleType)Can_GetMailboxTxBasicEndIdxOfControllerConfig(logCh)
#define Can_GetTxBasicHwStart(logCh)                  Can_GetTxBasicHwStartOfControllerConfig(logCh)
#define Can_GetTxBasicHwStop(logCh)                   Can_GetTxBasicHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxTxFullLengthOfControllerConfig)
# define Can_GetMailboxTxFullLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxTxFullStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxTxFullEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetTxFullHandleMax(logCh)                 Can_GetMailboxTxFullLengthOfControllerConfig(logCh)
#define Can_GetTxFullHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxTxFullStartIdxOfControllerConfig(logCh)
#define Can_GetTxFullHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxTxFullEndIdxOfControllerConfig(logCh)
#define Can_GetTxFullHwStart(logCh)                   Can_GetTxFullHwStartOfControllerConfig(logCh)
#define Can_GetTxFullHwStop(logCh)                    Can_GetTxFullHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxUnusedLengthOfControllerConfig)  /* COV_CAN_GENDATA_FAILURE */
# define Can_GetMailboxUnusedLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxUnusedStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxUnusedEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetUnusedHandleMax(logCh)                 Can_GetMailboxUnusedLengthOfControllerConfig(logCh)
#define Can_GetUnusedHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxUnusedStartIdxOfControllerConfig(logCh)
#define Can_GetUnusedHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxUnusedEndIdxOfControllerConfig(logCh)
#define Can_GetUnusedHwStart(logCh)                   Can_GetUnusedHwStartOfControllerConfig(logCh)
#define Can_GetUnusedHwStop(logCh)                    Can_GetUnusedHwStopOfControllerConfig(logCh)

/* Mailbox */
/* GetMailboxSize: logical size of mailbox - use LL specific generated data to get hardware object size if needed */
#define Can_GetMailboxSize(htrh)                      Can_GetMailboxSizeOfMailbox(htrh)
#define Can_GetMailboxHwHandle(htrh)                  Can_GetHwHandleOfMailbox(htrh)
#define Can_GetMailboxIDValue(htrh)                   Can_GetIDValueOfMailbox(htrh)
#define Can_GetMailboxType(htrh)                      Can_GetMailboxTypeOfMailbox(htrh)
#define Can_GetMailboxDataLen(htrh)                   Can_GetMaxDataLenOfMailbox(htrh)
#define Can_GetMailboxFdPadding(htrh)                 Can_GetFdPaddingOfMailbox(htrh)
#define Can_GetMailboxController(htrh)                (CanChannelHandle)Can_GetControllerConfigIdxOfMailbox(htrh)
#define Can_GetMailboxActiveSendObject(htrh)          Can_GetActiveSendObjectOfMailbox(htrh)
#define Can_GetMailboxActiveSendData(htrh)            Can_GetActiveSendDataOfMailbox(htrh)
#define Can_GetMailboxMemSecObjIndex(htrh)            Can_GetMemorySectionsIndexOfMailbox(htrh)
#define Can_IsMailboxIndivPolling(htrh)               Can_IsIsIndivPollingOfMailbox(htrh)
#define Can_GetMailboxTxHwFifo(htrh)                  Can_GetTxHwFifoOfMailbox(htrh)

/* MemorySectionInfo */
#define Can_GetMemSecAddress(memSec)                  Can_GetMemoryStartAddressOfMemorySectionInfo(memSec)
#define Can_GetMemSecStartIndex(memSec)               Can_GetMemorySectionStartOfMemorySectionInfo(memSec)

/* MemorySectionObjects */
#define Can_GetMemSecObjHwHandle(memSecObj)           Can_GetHwHandleOfMemorySectionObjects(memSecObj)
#define Can_GetMemSecObjMailboxElement(memSecObj)     Can_GetMailboxElementOfMemorySectionObjects(memSecObj)
#define Can_GetMemSecObjMailboxHandle(memSecObj)      Can_GetMailboxHandleOfMemorySectionObjects(memSecObj)
#define Can_IsMemSecObjIndivPolling(memSecObj)        Can_IsIsIndivPollingOfMemorySectionObjects(memSecObj)

/* VAR */
#define Can_GetLastInitObject(Index)                   Can_GetLastInitObjectOfControllerData(Index)
#define Can_SetLastInitObject(Index, Value)            Can_SetLastInitObjectOfControllerData(Index, Value)
#define Can_GetCanInterruptOldStatus(Index)            Can_GetCanInterruptOldStatusOfControllerData(Index)
#define Can_SetCanInterruptOldStatus(Index, Value)     Can_SetCanInterruptOldStatusOfControllerData(Index, Value)
#define Can_GetCanInterruptCounter(Index)              Can_GetCanInterruptCounterOfControllerData(Index)
#define Can_SetCanInterruptCounter(Index, Value)       Can_SetCanInterruptCounterOfControllerData(Index, Value)
#define Can_IsIsWakeup(Index)                          Can_IsIsWakeupOfControllerData(Index)
#define Can_SetIsWakeup(Index, Value)                  Can_SetIsWakeupOfControllerData(Index, Value)
#define Can_IsIsBusOff(Index)                          Can_IsIsBusOffOfControllerData(Index)
#define Can_SetIsBusOff(Index, Value)                  Can_SetIsBusOffOfControllerData(Index, Value)
#define Can_GetModeTransitionRequest(Index)            Can_GetModeTransitionRequestOfControllerData(Index)
#define Can_SetModeTransitionRequest(Index, Value)     Can_SetModeTransitionRequestOfControllerData(Index, Value)
#define Can_GetBusOffTransitionRequest(Index)          Can_GetBusOffTransitionRequestOfControllerData(Index)
#define Can_SetBusOffTransitionRequest(Index, Value)   Can_SetBusOffTransitionRequestOfControllerData(Index, Value)
#define Can_GetRamCheckTransitionRequest(Index)        Can_GetRamCheckTransitionRequestOfControllerData(Index)
#define Can_SetRamCheckTransitionRequest(Index, Value) Can_SetRamCheckTransitionRequestOfControllerData(Index, Value)
/* controller states */
#define Can_GetLogStatus(Index)                        Can_GetLogStatusOfControllerData(Index)
#define Can_SetLogStatus(Index, Value)                 Can_SetLogStatusOfControllerData(Index, Value)
#define Can_GetCanLoopTimeout(ch, Index)               (Can_GetLoopTimeoutOfControllerData(ch))[(Index)]
#define Can_GetMirrorModeState(Index)                  Can_GetMirrorModeStateOfControllerData(Index)
#define Can_SetMirrorModeState(Index, Value)           Can_SetMirrorModeStateOfControllerData(Index, Value)
#define Can_GetSilentModeState(Index)                  Can_GetSilentModeStateOfControllerData(Index)
#define Can_SetSilentModeState(Index, Value)           Can_SetSilentModeStateOfControllerData(Index, Value)
/* ActiveSend */
#define Can_GetActiveSendPdu(Index)                    Can_GetPduOfActiveSendObject(Index)
#define Can_SetActiveSendPdu(Index, Value)             Can_SetPduOfActiveSendObject(Index, Value)
#define Can_GetActiveSendState(Index)                  Can_GetStateOfActiveSendObject(Index)
#define Can_SetActiveSendState(Index, Value)           Can_SetStateOfActiveSendObject(Index, Value)
#define Can_GetActiveSendPduInfo(Index)                Can_GetPduInfoOfActiveSendObject(Index)
#define Can_GetActiveSendId(Index)                     (Can_GetPduInfoOfActiveSendObject(Index)).id
#define Can_SetActiveSendId(Index, Value)              (Can_GetPduInfoOfActiveSendObject(Index)).id = (Value)
#define Can_GetActiveSendLength(Index)                 (Can_GetPduInfoOfActiveSendObject(Index)).length
#define Can_SetActiveSendLength(Index, Value)          (Can_GetPduInfoOfActiveSendObject(Index)).length = (Value)
#define Can_GetActiveSendSdu(Index)                    (Can_GetPduInfoOfActiveSendObject(Index)).sdu
#define Can_SetActiveSendSdu(Index, Value)             (Can_GetPduInfoOfActiveSendObject(Index)).sdu = (Value)
#define Can_GetActiveSendSwPduHandle(Index)            (Can_GetPduInfoOfActiveSendObject(Index)).swPduHandle
#define Can_SetActiveSendSwPduHandle(Index, Value)     (Can_GetPduInfoOfActiveSendObject(Index)).swPduHandle = (Value)
/* Use already ComStackLib name #define Can_GetActiveSendData(Index)                   Can_GetActiveSendData(Index) */
/* TxHwFifo */
#define Can_GetTxHwFifoWriteIndex(fifo)                Can_GetWriteIndexOfTxHwFifo(fifo)
#define Can_SetTxHwFifoWriteIndex(fifo, Value)         Can_SetWriteIndexOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoWriteIndex(fifo)                Can_IncWriteIndexOfTxHwFifo(fifo)
#define Can_GetTxHwFifoReadIndex(fifo)                 Can_GetReadIndexOfTxHwFifo(fifo)
#define Can_SetTxHwFifoReadIndex(fifo, Value)          Can_SetReadIndexOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoReadIndex(fifo)                 Can_IncReadIndexOfTxHwFifo(fifo)
#define Can_GetTxHwFifoFillCount(fifo)                 Can_GetFillCountOfTxHwFifo(fifo)
#define Can_SetTxHwFifoFillCount(fifo, Value)          Can_SetFillCountOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoFillCount(fifo)                 Can_IncFillCountOfTxHwFifo(fifo)
#define Can_DecTxHwFifoFillCount(fifo)                 Can_DecFillCountOfTxHwFifo(fifo)


#if defined(C_ENABLE_MULTIPLE_CELLS)
#define Can_GetMailboxHandle(HwObj, Channel)           Can_GetMemSecObjMailboxHandle(HwObj + (CanObjectHandle)Can_GetMemSecStartIndex(Can_GetCellInfoIdxOfCell(Channel)))
#define Can_GetMailboxElement(HwObj, Channel)          Can_GetMemSecObjMailboxElement(HwObj+ (CanObjectHandle)Can_GetMemSecStartIndex(Can_GetCellInfoIdxOfCell(Channel)))
#else
#define Can_GetMailboxHandle(HwObj, Channel)           Can_GetMemSecObjMailboxHandle(HwObj)
#define Can_GetMailboxElement(HwObj, Channel)          Can_GetMemSecObjMailboxElement(HwObj)
#endif
#define Can_GetIsChannelFd(Channel)                    (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(Channel)) != CAN_NONE)

/***************************************************************************/
/* Default switches                                                        */
/* Automatic define settings, depending on user configuration in can_cfg.h */
/***************************************************************************/
#define C_HL_DISABLE_OVERRUN_IN_STATUS

#define C_HL_DISABLE_HW_RANGES_FILTER

#define C_HL_ENABLE_IDTYPE_IN_ID

/* Specify the ID tables which contain the ID type */
# define C_LL_RX_IDTYPE_TABLE      CanRxId0
# define C_LL_TX_IDTYPE_TABLE      CanTxId0

#define C_HL_DISABLE_DUMMY_FCT_CALL

#define C_HL_DISABLE_TX_MSG_DESTROYED

#define C_HL_DISABLE_CANCEL_IN_HW_TASK

#define C_HL_DISABLE_HW_EXIT_TRANSMIT

#define C_HL_ENABLE_CAN_IRQ_DISABLE

#define C_HL_DISABLE_ADJUST_RXHANDLE

#define C_HL_DISABLE_REJECT_UNWANTED_IDTYPE

#define C_HL_DISABLE_REJECT_REMOTE_FRAME

#define C_HL_DISABLE_REJECT_REMOTE_FRAME_FULLCAN

#define C_HL_ENABLE_REJECT_ILLEGAL_DLC

#define C_HL_DISABLE_COPROCESSOR_SUPPORT


#define C_HL_DISABLE_AVOID_REENTRANT_APPLCANCANCELNOTIFICATION

# if (CAN_FD_NISO == STD_ON) /* COV_NISO_PED */
# define C_ENABLE_FD_NISO
# else
# define C_DISABLE_FD_NISO
# endif
# if (CAN_FD_PED == STD_ON) /* COV_NISO_PED */
# define C_ENABLE_FD_PED  
# else
# define C_DISABLE_FD_PED    
# endif  

/* default defines for advanced Interrupt control */
#if !defined(C_ENABLE_NESTED_INTERRUPTS) && !defined(C_DISABLE_NESTED_INTERRUPTS) /* COV_CAN_INTERRUPT_CONTROL */
#  define C_ENABLE_NESTED_INTERRUPTS
#endif

#if !defined(C_ENABLE_CAN_INTERRUPT_CONTROL) && !defined(C_DISABLE_CAN_INTERRUPT_CONTROL) /* COV_CAN_INTERRUPT_CONTROL */
#  define C_ENABLE_CAN_INTERRUPT_CONTROL
#endif


#define C_DISABLE_TX_ACTUAL_MACROS

/***************************************************************************/
/* macros                                                                  */
/***************************************************************************/
#define C_DLC_M           ((vuint8)0x0Fu)

/* Transmit priority is set in the upper 2 bits, EID/SID is set in the bit below prio */
#define C_EID_MASK_16     ((vuint16)kCanIdTypeExt)
#define C_EID_MASK_32     (((vuint32)kCanIdTypeExt) << 16)
#define C_EID_NOT_MASK_16 kCanIdTypeExtMask


#define kCanNumberOfUsedCanRxIdTables 2u
#define kCanNumberOfUsedCanTxIdTables 2u

/* macros to set DLC and ID in RX-,TX-structures -------------------------- */
/* MK... macros are used by the generation tool to fill the RX and TX structures */
/* In case the IDE bit is located in the ID registers, this bit has to be handled as must match.
   In general, this is done by setting the IDE bit to 0 in the .._MASK_.. macros.
*/

#define MK_RX_RANGE_MASK_IDSTD0(id)   ( MK_STDID0(id) )
#define MK_RX_RANGE_MASK_IDSTD1(id)   ( 0x00u )
/* macros with postfix 2-4 not used */

#define MK_RX_RANGE_CODE_IDSTD0(id)   ( MK_STDID0(id) & C_PRIO_NOT_MASK_16 )
#define MK_RX_RANGE_CODE_IDSTD1(id)   ( 0x00u )
/* macros with postfix 2-4 not used */

#define MK_RX_RANGE_MASK_IDEXT0(id)   ( MK_EXTID0(id) & C_EID_NOT_MASK_16 )
#define MK_RX_RANGE_MASK_IDEXT1(id)   ( MK_EXTID1(id) )
/* macros with postfix 2-4 not used */

#define MK_RX_RANGE_CODE_IDEXT0(id)   ( MK_EXTID0(id) & C_PRIO_NOT_MASK_16 )
#define MK_RX_RANGE_CODE_IDEXT1(id)   ( MK_EXTID1(id) )
/* macros with postfix 2-4 not used */

#define MK_STDID0(id)            (C_OBJ_PRIO_16 | (vuint16)(((id) & (vuint16)0x07FFu) << 2))
#define MK_STDID1(id)            ((vuint16)0x0000u)
/* macros with postfix 2-4 not used */

#define MK_EXTID0(id)            (C_OBJ_PRIO_16 | C_EID_MASK_16 | (vuint16)(((id)&(vuint32)0x1FFF0000UL) >> 16) )
#define MK_EXTID1(id)            ((vuint16) (id))
/* macros with postfix 2-4 not used */

#define MK_TX_DLC(dlc)       ((dlc) & C_DLC_M)
#define MK_TX_DLC_EXT(dlc)   (MK_TX_DLC(dlc))

/* extract  DLC from register format to logical format */
#define XT_TX_DLC(dlc)       ((vuint8)((dlc) & C_DLC_M))

/* The macros CanRxActualIdRawx() have to provide the register context of the ID registers.
   It is not necessary to mask any bits. These macros are for internal use only and masking
   will be done in can_hls.c
*/

# define CanRxActualIdRaw0(rxStruct)   (((rxStruct)->pChipMsgObj->MoAR.reg16[1]))
#if defined( C_ENABLE_EXTENDED_ID )
# define CanRxActualIdRaw1(rxStruct)   (((rxStruct)->pChipMsgObj->MoAR.reg16[0]))
/* macros with postfix 2-4 not used */
#else
/* macros with postfix 1-4 not used */
#endif

/* Macros for CAN message access within ApplCanMsgReceived() or PreCopy() function */
#define CanRxActualExtId(rxStruct)         (((rxStruct)->pChipMsgObj->MoAR.reg32) & 0x1FFFFFFFUL )
#if defined( C_ENABLE_EXTENDED_ID )
# define CanRxActualIdExtHi(rxStruct)      (((rxStruct)->pChipMsgObj->MoAR.reg8[3]) & 0x1Fu )
# define CanRxActualIdExtMidHi(rxStruct)   (((rxStruct)->pChipMsgObj->MoAR.reg8[2]) & 0xFFu )
# define CanRxActualIdExtMidLo(rxStruct)   (((rxStruct)->pChipMsgObj->MoAR.reg8[1]) & 0xFFu )
# define CanRxActualIdExtLo(rxStruct)      (((rxStruct)->pChipMsgObj->MoAR.reg8[0]) & 0xFFu )
#endif

#define CanRxActualStdId(rxStruct)       ((vuint16)((((rxStruct)->pChipMsgObj->MoAR.reg16[1])>>2) & 0x07FFu))

#define CanRxActualData(rxStruct, i)     ((rxStruct)->pChipData[i])
#define CanRxActualDLC(rxStruct)         (CAN_DLC2LEN(((rxStruct)->pChipMsgObj->MoFCR_DLC) & C_DLC_M))
#define CanRxActualFdType(rxStruct)      (((rxStruct)->pChipMsgObj->MoFCR_Mode) & kCanFdTypeFd)
#define CanRxActualIdType(rxStruct)      (((rxStruct)->pChipMsgObj->MoAR.reg16[1]) & C_EID_MASK_16)

#if defined(MISRA_CHECK) /* COV_CAN_MISRA */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualErrorCounter",0303 /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualErrorCounter",0303 /* MD_Can_HwAccess */
#endif
#if defined (C_SINGLE_RECEIVE_CHANNEL )
# define CanRxActualErrorCounter()        (((V_DEF_P2SFR_CAN(volatile, vuint8, AUTOMATIC))Can_GetNodeAdr(0u))[0x14])
# define CanTxActualErrorCounter()        (((V_DEF_P2SFR_CAN(volatile, vuint8, AUTOMATIC))Can_GetNodeAdr(0u))[0x15])
#else
# define CanRxActualErrorCounter(ch)      (((V_DEF_P2SFR_CAN(volatile, vuint8, AUTOMATIC))Can_GetNodeAdr(ch))[0x14])
# define CanTxActualErrorCounter(ch)      (((V_DEF_P2SFR_CAN(volatile, vuint8, AUTOMATIC))Can_GetNodeAdr(ch))[0x15])
#endif

/* Macros for CAN message access within GenericConfirmation() function */
#define CanTxActualExtId(txStruct)        (((txStruct)->pChipMsgObj->MoAR.reg32) & 0x1FFFFFFFUL )
#define CanTxActualStdId(txStruct)        ((vuint16)((((txStruct)->pChipMsgObj->MoAR.reg16[1])>>2) & 0x07FFu))

#define CanTxActualData(txStruct, i)      ((txStruct)->pChipData[i])
#define CanTxActualDLC(txStruct)          (CAN_DLC2LEN(((txStruct)->pChipMsgObj->MoFCR_DLC) & C_DLC_M))
#define CanTxActualFdType(txStruct)       (((txStruct)->pChipMsgObj->MoFCR_Mode) & kCanFdTypeFd)
#define CanTxActualIdType(txStruct)           (((txStruct)->pChipMsgObj->MoAR.reg16[1]) & C_EID_MASK_16)
/* Macros for CAN message access within PreTransmit() function */
#define CanTxWriteActExtId(txStruct, id)   { ((CanChipMsgPtr)((txStruct).pChipData[0x08])) = ((C_OBJ_PRIO_32 | C_EID_MASK_32 | ((id) & 0x1FFFFFFFUL)));  }
#define CanTxWriteActId(txStruct, id)      { ((CanChipMsgPtr16)((txStruct).pChipData[0x0A])) = MK_STDID0((id));   }
#define CanTxWriteActDLC(txStruct, dlc)    { ((txStruct).pChipData[0x0D]) = ((vuint8) (dlc));}


#if defined( C_ENABLE_CAN_FD_FULL )
/* if FD Full is used, the actual length will be stored instead of the DLC */
#define CanMsgTransmitSetDlc(pCanMsgTransmitStruct, len)                { (pCanMsgTransmitStruct)->DlcRaw = (len); }
#else
#define CanMsgTransmitSetDlc(pCanMsgTransmitStruct, len)                { (pCanMsgTransmitStruct)->DlcRaw = MK_TX_DLC((len)); }
#endif
#define CanMsgTransmitSetData(pCanMsgTransmitStruct, dataByte, msgData) { (pCanMsgTransmitStruct)->DataFld[dataByte] = (msgData); }

/* macros for buffer access */
#define StartRxReadSync()          (VStdSuspendAllInterrupts())
#define EndRxReadSync()            (VStdResumeAllInterrupts())

#define StartRxWriteSync()         (VStdSuspendAllInterrupts())
#define EndRxWriteSync()           (VStdResumeAllInterrupts())

#define StartTxReadSync()
#define EndTxReadSync()

#define StartTxWriteSync()         (VStdSuspendAllInterrupts())
#define EndTxWriteSync()           (VStdResumeAllInterrupts())

#define StartRxWriteCANSync()
#define EndRxWriteCANSync()

#define StartRxReadCANSync()
#define EndRxReadCANSync()

#define StartRxFullCANReadSync(Obj)             
#define EndRxFullCANReadSync(Obj)              

#define StartRxFullCANWriteSync(obj)          
#define EndRxFullCANWriteSync(obj)           

/* macros for flag access */
#define CanStartFlagWriteSync()    (VStdSuspendAllInterrupts())
#define CanEndFlagWriteSync()      (VStdResumeAllInterrupts())

#define CAN_HL_MIN(x, y) (((x)>(y)) ? (y) : (x)) /* COV_CAN_GENDATA_FAILURE */
#define CAN_HL_MAX(x, y) (((x)<(y)) ? (y) : (x)) /* COV_CAN_GENDATA_FAILURE */

/***************************************************************************************************/
/* Macros for dummy statements */
#if !defined(CAN_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
# if defined(V_ENABLE_USE_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
#  define CAN_DUMMY_STATEMENT(x) (x) = (x) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# else
#  define CAN_DUMMY_STATEMENT(x)
# endif
#endif
#if !defined(CAN_DUMMY_STATEMENT_CONST) /* COV_CAN_COMPATIBILITY */
# if defined(V_ENABLE_USE_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
#  define CAN_DUMMY_STATEMENT_CONST(x) (void)(x)
# else
#  define CAN_DUMMY_STATEMENT_CONST(x)
# endif
#endif

/***************************************************************************************************/
/* Macros for DET and assertions */
#if (CAN_DEV_ERROR_REPORT == STD_ON) /* \trace SPEC-1404, SPEC-1696 */
/* \trace SPEC-1725, SPEC-1403, SPEC-1568 */
# define Can_CallDetReportError(api, err) ((void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, (api), (err)))
# define assertHardware(a, b, c)  if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertInternal(a, b, c)  if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertUser(a, b, c)      if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertGen(a, b, c)       if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define C_ENABLE_HARDWARE_CHECK
# define C_ENABLE_INTERNAL_CHECK
# define C_ENABLE_USER_CHECK
# define C_ENABLE_GEN_CHECK
#else
# define Can_CallDetReportError(api, err)
# define assertHardware(a, b, c)
# define assertInternal(a, b, c)
# define assertUser(a, b, c)
# define assertGen(a, b, c)
#endif

/***************************************************************************************************/
/* Macros for Critical Area 0 abstraction */

#define CanDeclareGlobalInterruptOldStatus
/* CAN_EXCLUSIVE_AREA_0 called only by LL code */
#define CanSingleGlobalInterruptDisable()     SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanSingleGlobalInterruptRestore()     SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()
#define CanGlobalInterruptDisable()           SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanGlobalInterruptRestore()           SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()
#define CanNestedGlobalInterruptDisable()     SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanNestedGlobalInterruptRestore()     SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()

/***************************************************************************************************/
/* Macros for LL-HLL compatibility */

/***************************************************************************************************/
/* Macros for ProtectedMode / PeripheralAccess */
# if defined ( C_ENABLE_USER_MODE_OS )
#  define CAN_WRITE_PROTECTED_REG8(area, regAdr, val)         osWritePeripheral8((area), (uint32)(regAdr), (val))
#  define CAN_WRITE_PROTECTED_REG16(area, regAdr, val)        osWritePeripheral16((area), (uint32)(regAdr), (val))
#  define CAN_WRITE_PROTECTED_REG32(area, regAdr, val)        osWritePeripheral32((area), (uint32)(regAdr), (val))
#  define CAN_WRITE_PROTECTED_REG8_RESET(area, regAdr, bits)  osModifyPeripheral8((area), (uint32)(regAdr), (uint8)~(bits), (uint8)0x00u)
#  define CAN_WRITE_PROTECTED_REG16_RESET(area, regAdr, bits) osModifyPeripheral16((area), (uint32)(regAdr), (uint16)~(bits), (uint16)0x0000u)
#  define CAN_WRITE_PROTECTED_REG32_RESET(area, regAdr, bits) osModifyPeripheral32((area), (uint32)(regAdr), (uint32)~(bits), (uint32)0x00000000UL)
#  define CAN_WRITE_PROTECTED_REG8_SET(area, regAdr, bits)    osModifyPeripheral8((area), (uint32)(regAdr), (uint8)0xFFu, (bits))
#  define CAN_WRITE_PROTECTED_REG16_SET(area, regAdr, bits)   osModifyPeripheral16((area), (uint32)(regAdr), (uint16)0xFFFFu, (bits))
#  define CAN_WRITE_PROTECTED_REG32_SET(area, regAdr, bits)   osModifyPeripheral32((area), (uint32)(regAdr), (uint32)0xFFFFFFFFUL, (bits))
#  define CAN_READ_PROTECTED_REG8(area, regAdr)               osReadPeripheral8((area), (uint32)(regAdr))
#  define CAN_READ_PROTECTED_REG16(area, regAdr)              osReadPeripheral16((area), (uint32)(regAdr))
#  define CAN_READ_PROTECTED_REG32(area, regAdr)              osReadPeripheral32((area), (uint32)(regAdr))
# endif
# if defined ( C_ENABLE_USER_MODE_APPL )
#  define CAN_WRITE_PROTECTED_REG8(area, regAdr, val)         ApplCanWriteProtectedRegister8((regAdr), (uint8)0xFFu, (val))
#  define CAN_WRITE_PROTECTED_REG16(area, regAdr, val)        ApplCanWriteProtectedRegister16((regAdr), (uint16)0xFFFFu, (val))
#  define CAN_WRITE_PROTECTED_REG32(area, regAdr, val)        ApplCanWriteProtectedRegister32((regAdr), (uint32)0xFFFFFFFFUL, (val))
#  define CAN_WRITE_PROTECTED_REG8_RESET(area, regAdr, bits)  ApplCanWriteProtectedRegister8((regAdr), (bits), (uint8)0x00u)
#  define CAN_WRITE_PROTECTED_REG16_RESET(area, regAdr, bits) ApplCanWriteProtectedRegister16((regAdr), (bits), (uint16)0x0000u)
#  define CAN_WRITE_PROTECTED_REG32_RESET(area, regAdr, bits) ApplCanWriteProtectedRegister32((regAdr), (bits), (uint32)0x00000000UL)
#  define CAN_WRITE_PROTECTED_REG8_SET(area, regAdr, bits)    ApplCanWriteProtectedRegister8((regAdr), (bits), (bits))
#  define CAN_WRITE_PROTECTED_REG16_SET(area, regAdr, bits)   ApplCanWriteProtectedRegister16((regAdr), (bits), (bits))
#  define CAN_WRITE_PROTECTED_REG32_SET(area, regAdr, bits)   ApplCanWriteProtectedRegister32((regAdr), (bits), (bits))
#  define CAN_READ_PROTECTED_REG8(area, regAdr)               ApplCanReadProtectedRegister8((regAdr))
#  define CAN_READ_PROTECTED_REG16(area, regAdr)              ApplCanReadProtectedRegister16((regAdr))
#  define CAN_READ_PROTECTED_REG32(area, regAdr)              ApplCanReadProtectedRegister32((regAdr))
# endif
# if !defined(C_ENABLE_USER_MODE_OS) && !defined(C_ENABLE_USER_MODE_APPL)
#  define CAN_WRITE_PROTECTED_REG8(area, regAdr, val)         *(regAdr) = (val)
#  define CAN_WRITE_PROTECTED_REG16(area, regAdr, val)        *(regAdr) = (val)
#  define CAN_WRITE_PROTECTED_REG32(area, regAdr, val)        *(regAdr) = (val)
#  define CAN_WRITE_PROTECTED_REG8_RESET(area, regAdr, bits)  *(regAdr) &= (uint8)~(bits)
#  define CAN_WRITE_PROTECTED_REG16_RESET(area, regAdr, bits) *(regAdr) &= (uint16)~(bits)
#  define CAN_WRITE_PROTECTED_REG32_RESET(area, regAdr, bits) *(regAdr) &= (uint32)~(bits)
#  define CAN_WRITE_PROTECTED_REG8_SET(area, regAdr, bits)    *(regAdr) |= (bits)
#  define CAN_WRITE_PROTECTED_REG16_SET(area, regAdr, bits)   *(regAdr) |= (bits)
#  define CAN_WRITE_PROTECTED_REG32_SET(area, regAdr, bits)   *(regAdr) |= (bits)
#  define CAN_READ_PROTECTED_REG8(area, regAdr)               *(regAdr)
#  define CAN_READ_PROTECTED_REG16(area, regAdr)              *(regAdr)
#  define CAN_READ_PROTECTED_REG32(area, regAdr)              *(regAdr)
# endif

/***************************************************************************/
/* error codes                                                             */
/***************************************************************************/
/* error numbers for User Assertions 0x20-0x3f - hardware dependent */

/* error numbers for Generation tool Assertions 0x60-0x7f - hardware dependent */
#define kErrorBasicCANMask                   ((vuint8)0x60u)
#define kErrorInterruptMaskTable             ((vuint8)0x61u)
#define kErrorMailboxLayout                  ((vuint8)0x62u)

/* error numbers for Hardware Assertions 0xa0-0xbf - hardware depended */
#define kErrorUnknownInterrupt               ((vuint8)0xa0u)
#define kErrorUnknownISRPriority             ((vuint8)0xa1u)

/* error numbers for Internal Assertions 0xe0-0xff - hardware dependent */

/***************************************************************************/
/* CAN-Hardware Data Definitions                                           */
/***************************************************************************/

/***************************************************************************/
/* Special switches need by CAN driver                                     */
/***************************************************************************/

/***************************************************************************/
/* Defines / data types / structures / unions                              */
/***************************************************************************/

/* Define CAN Chip hardware; segment must be located in locater file    */
/* register layout of the can chip                                      */
/* Structure describing CAN receive buffer. */
/* ESCAN00073593 struct is not defined as volatile because the generated one for ASR is not too */
typedef  struct tCanMsgObj
{                             /* 1000h + 0x20 * m */
  vuint8  MoFCR_Mode;         /*!< Message Object Function Control Register; Section: Message Mode Control    +0x00 */
  vuint8  MoFCR_Gate;         /*!< Message Object Function Control Register; Section: Gateway                 +0x01 */
  vuint8  MoFCR_IE;           /*!< Message Object Function Control Register; Section: interrupts              +0x02 */
  vuint8  MoFCR_DLC;          /*!< Message Object Function Control Register; Section: DLC                     +0x03 */
  vuint8  MoFGPR_BOT;         /*!< Message Object FIFO Pointer Register; Section Bottom Pointer               +0x04 */
  vuint8  MoFGPR_TOP;         /*!< Message Object FIFO Pointer Register; Section Top Pointer                  +0x05 */
  vuint8  MoFGPR_CUR;         /*!< Message Object FIFO Pointer Register; Section Current Pointer              +0x06 */
  vuint8  MoFGPR_SEL;         /*!< Message Object FIFO Pointer Register; Section Select Pointer               +0x07 */
  vuint16 MoIPR;              /*!< Message Object Interrupt Pointer Register                                  +0x08 */
  vuint16 reserved;
  union
  { /* PRQA S 0750 */ /* MD_Can_Union */
    vuint32    reg32;         /*!< Message Object Acceptance Mask Register 32 bit access                      +0x0C */
    vuint16    reg16[2];      /*!< Message Object Acceptance Mask Register 16 bit access                      +0x0C */
    vuint8     reg8 [4];      /*!< Message Object Acceptance Mask Register 8 bit access                       +0x0C */
  } MoAMR;                    /*!< Message Object Acceptance Mask Register                                    +0x0C */
  vuint32 MoDR[2];            /*!< Message Object Data Register    2x 32 bit                                  +0x10 */
  union
  { /* PRQA S 0750 */ /* MD_Can_Union */
    vuint32    reg32;         /*!< Message Object Arbitration Register 32 bit access                          +0x18 */
    vuint16    reg16[2];      /*!< Message Object Arbitration Register 16 bit access                          +0x18 */
    vuint8     reg8 [4];      /*!< Message Object Arbitration Register 8 bit access                           +0x18 */
  } MoAR;                     /*!< Message Object Arbitration Register                                        +0x18 */
  vuint16 MoCtrL;             /*!< Message Object Control Register Low                                        +0x1C */
  vuint16 MoCtrH;             /*!< Message Object Control Register Low                                        +0x1E */
} tCanMsgObjStruct;  /* CAN_MSG_OBJ_PTR */

#if defined(C_ENABLE_CAN_FD_FULL)
typedef  struct tCanFdMsgObj
{                             /* 1000h + 0x20 * m */ 
  vuint32 MoDR[7];            /*!< Message Object Data Register    7x 32 bit                                  +0x00 */
  vuint16 MoCtrL;             /*!< Message Object Control Register Low                                        +0x1C */
  vuint16 MoCtrH;             /*!< Message Object Control Register High                                       +0x1E */
} tCanFdMsgObjStruct;  /* CAN_MSG_OBJ_PTR */
#endif


V_DEF_P2SFR_CAN_TYPE(volatile, tCanMsgObjStruct) CanMsgObjStructPtr;
#if defined(C_ENABLE_CAN_FD_FULL)
V_DEF_P2SFR_CAN_TYPE(volatile, tCanFdMsgObjStruct) CanFdMsgObjStructPtr;
#endif

typedef volatile struct tCanNode
{
  vuint16 NCR;                /*!< Node Control Register                                          +0x00 */
  vuint16 reserved1;
  vuint16 NSR;                /*!< Node Status Register                                           +0x04 */
  vuint16 reserved2;
  vuint16 NIPR;               /*!< Node Interrupt Pointer Register                                +0x08 */
  vuint16 reserved3;
  vuint16 NPCR;               /*!< Node Port Control Register                                     +0x0C */
  vuint16 reserved4;
  vuint32 NBTR;               /*!< Node Bit Timing Register                                       +0x10 */
  vuint8  NECnt_Rec;          /*!< Node Error Counter Register section "Receive error counter"    +0x14 */ 
  vuint8  NECnt_Tec;          /*!< Node Error Counter Register section "Transmit error counter"   +0x15 */ 
  vuint8  NECnt_EWRNLVL;      /*!< Node Error Counter Register section "Error warning level"      +0x16 */
  vuint8  reserved6;          /*!< Node Error Counter Register section not used                   +0x17 */
  vuint32 NFCR;               /*!< Node Frame Counter                                             +0x18 */
#if defined( C_ENABLE_CAN_FD_USED )
  vuint8  reserved7[0x1C];
  vuint32 FNBTR;              /*!< Fast Node Bit Timing register                                  +0x38 */
  vuint32 NTDCR;              /*!< Node Transmitter Delay Compensation Register                   +0x3C */
  vuint8  reserved8[0xC0];    /* up to next node */
#else
  vuint8  reserved7[0xE4];    /* up to next Node */
#endif
} tCanNodeStruct;  /* CAN_NODE_PTR */

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanNodeStruct) CanNodeStructPtr;

typedef volatile struct tCanModule
{
  vuint32 LIST[CAN_MAX_LIST];   /*!< List Register                                         +0x100 */
  vuint32 MSPND[CAN_MAX_MSPND]; /*!< Message Pending Register                              +0x140 */
  vuint32 MSID[CAN_MAX_MSID];   /*!< Message Index Register                                +0x180 */
  vuint32 MSIMask;              /*!< Message Index Mask Register                           +0x1C0 */
  vuint16 PANCMD;               /*!< Panel Control Register: Panel Command                 +0x1C4 */
  vuint16 PANAR;                /*!< Panel Control Register: Panel Argument 1              +0x1C6 */
  vuint16 MCR;                  /*!< Module Control Register                               +0x1C8 */
  vuint16 reserved1;
  vuint32 MITR;                 /*!< Module Interrupt Trigger Control Register  (unused)   +0x1CC */
  vuint8  reserved2[0x30];
} tCanModuleStruct;  /* CAN_MODUL_CTR_PTR */

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanModuleStruct) CanModuleStructPtr;

typedef volatile struct tCanController
{
  vuint16 CLC;                /* Clock control         +0x00 (only TriCore) */
  vuint8  reserved1[6];
  vuint32 ID;                 /* Cell id               +0x08 (unused / not all derivatives) */
  vuint32 FDR;                /* Clock Divider         +0x0c */
  vuint8  reserved2[0xB0];
  vuint32 Src[16];            /* Interrupt Service     +0xc0 (amount depend on derivatives - separate for MultiCan+) */
} tCanControllerStruct;  /* CAN_CONTROLLER_PTR */

typedef volatile struct tCanCell
{                                                   /* BaseAddress + ... */
  tCanControllerStruct Ctrl;                        /* 0     - 0x100 */
  tCanModuleStruct      Module;                       /* 0x100 - 0x1D0 */
  tCanNodeStruct       Node[CAN_MAX_NODE];          /* 0x200 - x(derivative) / include reserved */
#if defined(C_ENABLE_MULTIPLE_CELLS)
  tCanMsgObjStruct     Obj[CAN_MAX_MAILBOX_AMOUNT]; /* x - y (derivative) */
#else
  tCanMsgObjStruct     Obj[CAN_MAX_NUM_MSGOBJ];     /* x - y (derivative) */
#endif
} tCanCellStruct;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanCellStruct) CanCellStructPtr;

#if defined(MISRA_CHECK) /* COV_CAN_MISRA */
# pragma PRQA_MACRO_MESSAGES_OFF "canCellPtr",0303 /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CAN_MAILBOX_PTR",0303    /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CAN_FD_MAILBOX_PTR",0303 /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CAN_NODE_PTR",0303       /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CAN_MODULE_PTR",0303     /* MD_Can_HwAccess */
#endif 

#if defined(C_ENABLE_MULTIPLE_CELLS)
# define canCellPtr       ((CanCellStructPtr) (Can_GetBaseAdrOfCellInfo(Can_GetCellInfoIdxOfCell(canHwChannel))))
#else
# define canCellPtr       ((CanCellStructPtr) kCanBaseAdr)
#endif

#if (CAN_SAFE_BSW == STD_ON)
# if defined(C_ENABLE_MULTIPLE_CELLS)
#  define CAN_HWOBJ_SAFE_MASK(x)             ((x) & (vuint8)((Can_GetMaxMailboxAmountOfCellInfo(Can_GetCellInfoIdxOfCell(canHwChannel))) - 1u)) /* CM_CAN_LL05 */
# else
#  define CAN_HWOBJ_SAFE_MASK(x)             ((x) & (CAN_MAX_MAILBOX_AMOUNT - 1u)) /* CM_CAN_LL05 */
# endif
#else
# define CAN_HWOBJ_SAFE_MASK(x)              (x)
#endif

#define CAN_MAILBOX_PTR(x)     ((CanMsgObjStructPtr)&canCellPtr->Obj[(vuint8)CAN_HWOBJ_SAFE_MASK(x)]) /* CM_CAN_LL05 */
#define CAN_FD_MAILBOX_PTR(x)  ((CanFdMsgObjStructPtr) &canCellPtr->Obj[(vuint8)CAN_HWOBJ_SAFE_MASK(x)]) /* CM_CAN_LL05 */
#define CAN_NODE_PTR(x)        ((CanNodeStructPtr) &canCellPtr->Node[(vuint8)(x)])
#define CAN_MODULE_PTR         ((CanModuleStructPtr) &canCellPtr->Module)

#define CAN_MULTICAN                   0u
#define CAN_MULTICANR                  1u
#define CAN_MULTICANR_CH_OFFSET        8u
#define CAN_MULTICANR_MSGOBJ_OFFSET    256u
#if defined(C_ENABLE_MULTIPLE_CELLS)
# define CAN_MAX_NUM_MSGOBJ            (Can_GetMaxMailboxAmountOfCellInfo(Can_GetCellInfoIdxOfCell(canHwChannel)))
# if defined(C_ENABLE_CONFIGURE_SRC_ADDRESS) /* COV_CAN_AURIX_DERIVATIVE */
#  define kCanSRCAdr                   (Can_GetSrcAdrOfCellInfo(Can_GetCellInfoIdxOfCell(canHwChannel)))
# endif
#else /* single cell with either CAN_MULTICAN or CAN_MULTICANR */
# if (kCanNumberOfPhysChannels <= CAN_MULTICANR_CH_OFFSET)  /* COV_CAN_GENDATA_FAILURE */
#  define canll_channel_offset 0u
# else
#  define canll_channel_offset CAN_MULTICANR_CH_OFFSET
# endif
#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
# if( kCanNumberOfUsedCanRxIdTables > 4 ) /* COV_CAN_COMPATIBILITY */
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id); \
                                   (paraStruct)->idRaw4 = MK_STDID4(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id); \
                                   (paraStruct)->idRaw4 = MK_EXTID4(id)
# elif ( kCanNumberOfUsedCanRxIdTables > 3 ) /* COV_CAN_COMPATIBILITY */
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id)
# elif ( kCanNumberOfUsedCanRxIdTables > 2 ) /* COV_CAN_COMPATIBILITY */
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id)
# elif ( kCanNumberOfUsedCanRxIdTables > 1 ) /* COV_CAN_COMPATIBILITY */
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id)
# else
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id)
# endif
#endif

#if( kCanNumberOfUsedCanTxIdTables > 4 ) /* COV_CAN_COMPATIBILITY */
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id); \
                                   (paraStruct)->idRaw4 = MK_STDID4(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id); \
                                   (paraStruct)->idRaw4 = MK_EXTID4(id)
#elif ( kCanNumberOfUsedCanTxIdTables > 3 ) /* COV_CAN_COMPATIBILITY */
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id)
#elif ( kCanNumberOfUsedCanTxIdTables > 2 ) /* COV_CAN_COMPATIBILITY */
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id)
#elif ( kCanNumberOfUsedCanTxIdTables > 1 ) /* COV_CAN_COMPATIBILITY */
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id)
#else
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id)
#endif

/***************************************************************************/
/* Core - LowLevel API                                                     */
/***************************************************************************/
typedef struct sCanRxInfoStruct
{
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  CanObjectHandle   localMailboxHandle; 
  Can_IdType               localId; 
  uint8                    localDlc;
  /* LL specific part */
} tCanRxInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxInfoStruct, VAR_NOINIT) CanRxInfoStructPtr;

typedef struct sCanTxConfInfoStruct
{
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  /* LL specific part */
  VAR(tCanTmpMsgObjStruct, CAN_VAR_NOINIT) tmpMailbox;
} tCanTxConfInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxConfInfoStruct, VAR_NOINIT) CanTxConfInfoStructPtr;

typedef struct sCanInitParaStruct
{
  CanInitHandle     initObject;
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
  tCanRxId0                idRaw0;
# if( kCanNumberOfUsedCanRxIdTables > 1 ) /* COV_CAN_COMPATIBILITY */
  tCanRxId1                idRaw1;
# endif
# if( kCanNumberOfUsedCanRxIdTables > 2 ) /* COV_CAN_COMPATIBILITY */
  tCanRxId2                idRaw2;
# endif
# if( kCanNumberOfUsedCanRxIdTables > 3 ) /* COV_CAN_COMPATIBILITY */
  tCanRxId3                idRaw3;
# endif
# if( kCanNumberOfUsedCanRxIdTables > 4 ) /* COV_CAN_COMPATIBILITY */
  tCanRxId4                idRaw4;
# endif
  tCanIdType               idType;
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8                    doRamCheck;
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  uint8                    isChRamCheckFail;
# endif
#endif
  uint8                    isInitOk;
  /* LL specific part */
} tCanInitParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanInitParaStruct, VAR_NOINIT) CanInitParaStructPtr;

#define TxDataPtr Can_SduPtrType /* CBD compatibility */
typedef struct sCanTxTransmissionParaStruct
{
  /* logical formats */
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement; /* logical index within the mailbox for muxTx or FIFO element */
  CanObjectHandle   hwObjHandle;    /* set to the initial hwHandle by core but has to be modified by LL in case of muxTx or FIFO */
  CanObjectHandle   activeSendObject; /* index of the logical Tx mailbox (Tx * Element) */
  tCanTxId0                idRaw0;
#if( kCanNumberOfUsedCanTxIdTables > 1 ) /* COV_CAN_COMPATIBILITY */
  tCanTxId1                idRaw1;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 2 ) /* COV_CAN_COMPATIBILITY */
  tCanTxId2                idRaw2;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 3 ) /* COV_CAN_COMPATIBILITY */
  tCanTxId3                idRaw3;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 4 ) /* COV_CAN_COMPATIBILITY */
  tCanTxId4                idRaw4;
#endif
  tCanDlc                  dlcRaw;
  TxDataPtr                CanMemCopySrcPtr;
#if defined( C_ENABLE_CAN_FD_USED )
  tCanFdType               fdType;
  tCanFdBrsType            fdBrsType;
  uint8                    messageLen;
  uint8                    frameLen;
  uint8                    paddingVal;
#endif
  Can_PduType              pdu;
  /* LL specific part */
  #if defined( C_ENABLE_PRETRANSMIT_FCT )
  # if defined(C_ENABLE_CAN_FD_FULL)
  vuint32 tmpData[16];
  # else
  vuint32 tmpData[2];
  # endif
  #endif
} tCanTxTransmissionParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxTransmissionParaStruct, VAR_NOINIT) CanTxTransmissionParaStructPtr;

typedef struct sCanRxBasicParaStruct
{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
#if defined( C_ENABLE_OVERRUN )
  uint8                    isOverrun;
#endif
  tCanRxInfoStruct         rxStruct;
  /* LL specific part */
} tCanRxBasicParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxBasicParaStruct, VAR_NOINIT) CanRxBasicParaStructPtr;

typedef struct sCanRxFullParaStruct
{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
#if defined( C_ENABLE_FULLCAN_OVERRUN )
  uint8                    isOverrun;
#endif
  tCanRxInfoStruct         rxStruct;
  /* LL specific part */
} tCanRxFullParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxFullParaStruct, VAR_NOINIT) CanRxFullParaStructPtr;

#if defined( C_ENABLE_CANCEL_SUPPORT_API )
typedef struct
{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement; /* logical index within the mailbox for muxTx or FIFO element */
  CanObjectHandle   hwObjHandle;    /* set to the initial hwHandle by core but has to be modified by LL in case of muxTx or FIFO */
  CanObjectHandle   activeSendObject; /* index of the logical mailbox + muxTx or FIFO element 0..n */
  CanTransmitHandle   canHandleCurTxObj;
} tCanTxCancellationParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxCancellationParaStruct, VAR_NOINIT) CanTxCancellationParaStructPtr;
#endif

typedef struct
{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement; /* logical index within the mailbox for muxTx or FIFO element */
  CanObjectHandle   hwObjHandle;    /* set to the initial hwHandle by core but has to be modified by LL in case of muxTx or FIFO */
  CanObjectHandle   activeSendObject; /* index of the logical mailbox + muxTx or FIFO element 0..n */
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  CanTxConfInfoStructPtr   txStructConf;
#endif
} tCanTxConfirmationParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxConfirmationParaStruct, VAR_NOINIT) CanTxConfirmationParaStructPtr;

typedef struct sCanTaskParaStruct
{
  CanObjectHandle mailboxHandle;
  CanObjectHandle hwObjHandle;
  /* LL specific part */
} tCanTaskParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTaskParaStruct, VAR_NOINIT) CanTaskParaStructPtr;
    
/***************************************************************************/
/* module global variable declaration                                      */
/***************************************************************************/

/***************************************************************************/
/* External Declarations                                                   */
/***************************************************************************/
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED  /*---------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /*----------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***************************************************************************/
/* local function prototypes (only internal usage)                         */
/***************************************************************************/
#define CAN_START_SEC_STATIC_CODE  /*--------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/************************************************************************************************************
 *  CanLL_WriteReg8()
 ***********************************************************************************************************/
/*! \brief         Write value and do RamCheck
 *  \details       Write the value of the hardware mailbox or controller register and read back for RamCheck. 
 *                 set initPara->isChRamCheckFail or initPara->isMbRamCheckFail in case of an HW issue to deactivate hardware.
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     regPtr           valid pointer to Register to be written.
 *  \param[in]     value            value to be written.
 *  \param[in]     readMask         mask to check the read back value.
 *  \param[in]     doRamCheck       execute the RAM check (kCanExecuteRamCheck, kCanSuppressRamCheck).
 *  \return        kCanTrue         RamCheck failed.
 *  \return        kCanFalse        RamCheck passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteReg8(CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr8 regPtr, vuint8 value, vuint8 readMask, CanInitParaStructPtr initPara);
/* CODE CATEGORY 4 END */

/************************************************************************************************************
 *  CanLL_WriteReg16()
 ***********************************************************************************************************/
/*! \brief         Write value and do RamCheck
 *  \details       Write the value of the hardware mailbox or controller register and read back for RamCheck. 
 *                 set initPara->isChRamCheckFail or initPara->isMbRamCheckFail in case of an HW issue to deactivate hardware.
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     regPtr           valid pointer to Register to be written.
 *  \param[in]     value            value to be written.
 *  \param[in]     readMask         mask to check the read back value.
 *  \param[in]     doRamCheck       execute the RAM check (kCanExecuteRamCheck, kCanSuppressRamCheck).
 *  \return        kCanTrue         RamCheck failed.
 *  \return        kCanFalse        RamCheck passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteReg16(CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr16 regPtr, vuint16 value, vuint16 readMask, CanInitParaStructPtr initPara);
/* CODE CATEGORY 4 END */

/************************************************************************************************************
 *  CanLL_WriteReg32()
 ***********************************************************************************************************/
/*! \brief         Write value and do RamCheck
 *  \details       Write the value of the hardware mailbox or controller register and read back for RamCheck. 
 *                 set initPara->isChRamCheckFail or initPara->isMbRamCheckFail in case of an HW issue to deactivate hardware.
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     regPtr           valid pointer to Register to be written.
 *  \param[in]     value            value to be written.
 *  \param[in]     readMask         mask to check the read back value.
 *  \param[in]     doRamCheck       execute the RAM check (kCanExecuteRamCheck, kCanSuppressRamCheck).
 *  \return        kCanTrue         RamCheck failed.
 *  \return        kCanFalse        RamCheck passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteReg32(CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr32 regPtr, vuint32 value, vuint32 readMask, CanInitParaStructPtr initPara);
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitBegin()
 *********************************************************************************************************************/
/*! \brief         Starts the channel initialization
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBegin( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
/**********************************************************************************************************************
 *  CanLL_InitBeginIsRegisterCorrupt()
 *********************************************************************************************************************/
/*! \brief         Performs the channel register RAM check
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanFalse           No corrupt register RAM found
 *                 kCanTrue            Register RAM is considered corrupt or failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginIsRegisterCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
#endif

/**********************************************************************************************************************
 *  CanLL_InitBeginSetRegisters()
 *********************************************************************************************************************/
/*! \brief         Performs the channel register initialization
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitMailboxTx()
 *********************************************************************************************************************/
/*! \brief         Initializes a transmit mailbox
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxTx( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

# if (defined( C_ENABLE_CAN_RAM_CHECK ))
/**********************************************************************************************************************
 *  CanLL_InitMailboxTxDeactivate()
 *********************************************************************************************************************/
/*! \brief         Deactivates a transmit mailbox if it is considered corrupt by the RAM check
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxTxDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
# endif


#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxFullCan()
 *********************************************************************************************************************/
/*! \brief         Initializes a receive FullCAN mailbox
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxFullCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

# if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxFullCanDeactivate()
 *********************************************************************************************************************/
/*! \brief         Deactivates a receive FullCAN mailbox if it is considered corrupt by the RAM check
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxRxFullCanDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
# endif

#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxBasicCan()
 *********************************************************************************************************************/
/*! \brief         Initializes a receive BasicCAN mailbox
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxBasicCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

# if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxBasicCanDeactivate()
 *********************************************************************************************************************/
/*! \brief         Deactivates a receive BasicCAN mailbox if it is considered corrupt by the RAM check
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxRxBasicCanDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
# endif
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */


/**********************************************************************************************************************
 *  CanLL_InitEndSetRegisters()
 *********************************************************************************************************************/
/*! \brief         Finishes the channel register initialization
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEndSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitEnd()
 *********************************************************************************************************************/
/*! \brief         Finishes the channel initialization
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_RAM_CHECK )
/**********************************************************************************************************************
 *  CanLL_InitIsMailboxCorrupt()
 *********************************************************************************************************************/
/*! \brief         Performs the RAM check for a mailbox
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanFalse           Mailbox is not corrupt
 *                 kCanTrue            Mailbox is considered corrupt or failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_InitIsMailboxCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
#endif


/**********************************************************************************************************************
 *  CanLL_InitPowerOn()
 *********************************************************************************************************************/
/*! \brief         Performs the hardware specific global module initialization
 *  \details       Called by CanInitPowerOn()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOn( void );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitMemoryPowerOn()
 *********************************************************************************************************************/
/*! \brief         Internal function, called by Can_InitMemory().
 *  \details       Performs the platform specific memory initialization.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMemoryPowerOn( void );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitPowerOnChannelSpecific()
 *********************************************************************************************************************/
/*! \brief         Performs the channel dependent hardware specific global module initialization
 *  \details       Called by CanInitPowerOn()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOnChannelSpecific( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_TxBegin()
 *********************************************************************************************************************/
/*! \brief         Perform start of transmission
 *  \details       Called by transmission to prepare send object
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_TxSetMailbox()
 *********************************************************************************************************************/
/*! \brief         Set mailbox data for transmission
 *  \details       Called by transmission to set ID, DLC
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_TxCopyToCan()
 *********************************************************************************************************************/
/*! \brief         Set mailbox data for transmission
 *  \details       Called by transmission to set data part in mailbox
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_TxStart()
 *********************************************************************************************************************/
/*! \brief         Trigger mailbox to start the transmission
 *  \details       Called by transmission to start transmission
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \return        kCanOk              No issue
 *                 kCanFailed          Issue occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_TxEnd()
 *********************************************************************************************************************/
/*! \brief         Perform end handling of the transmission
 *  \details       Called by transmission to finish transmission
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
#if defined( C_ENABLE_TX_POLLING )
/**********************************************************************************************************************
 *  CanLL_TxProcessPendings()
 *********************************************************************************************************************/
/*! \brief         Check pending of transmission object
 *  \details       Called by transmission to get pending flag of mailbox
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of confirmation task
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);
/* CODE CATEGORY 2 END */
#endif
/**********************************************************************************************************************
 *  CanLL_TxConfBegin()
 *********************************************************************************************************************/
/*! \brief         Perform start of confirmation
 *  \details       Called by confirmation
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txConfPara          Pointer to local variables of confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);
/* CODE CATEGORY 1 END */
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/**********************************************************************************************************************
 *  CanLL_TxConfSetTxConfStruct()
 *********************************************************************************************************************/
/*! \brief         Set confirmation struct
 *  \details       Called by confirmation to set confirmation data struct
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txConfPara          Pointer to local variables of confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);
/* CODE CATEGORY 1 END */
#endif
/**********************************************************************************************************************
 *  CanLL_TxConfEnd()
 *********************************************************************************************************************/
/*! \brief         Perform confirmation end handling
 *  \details       Called by confirmation
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txConfPara          Pointer to local variables of confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);
/* CODE CATEGORY 1 END */

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_RxBasicMsgReceivedBegin()
 *********************************************************************************************************************/
/*! \brief         Perform BasicCAN receive begin
 *  \details       Called by reception to begin handling
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \return        kCanOk              No Issue occur
 *                 kCanFailed          Issue occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_RxBasicReleaseObj()
 *********************************************************************************************************************/
/*! \brief         Release BasicCAN mailbox
 *  \details       Called by reception to release object
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_RxBasicMsgReceivedEnd()
 *********************************************************************************************************************/
/*! \brief         Release BasicCAN receive end
 *  \details       Called by reception to finish handling
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);
/* CODE CATEGORY 1 END */
# if defined( C_ENABLE_RX_BASICCAN_POLLING )
/**********************************************************************************************************************
 *  CanLL_RxBasicProcessPendings()
 *********************************************************************************************************************/
/*! \brief         Check BasicCAN receive pending
 *  \details       Called by reception to get mailbox pending state
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] taskPara            Pointer to local variables of reception task
 *  \return        kCanTrue            mailbox pending
 *                 kCanFailed          no pending
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);
/* CODE CATEGORY 2 END */
# endif /* C_ENABLE_RX_BASICCAN_POLLING */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_RxFullMsgReceivedBegin()
 *********************************************************************************************************************/
/*! \brief         Perform FullCAN receive begin
 *  \details       Called by reception to begin handling
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \return        kCanOk              No Issue occur
 *                 kCanFailed          Issue occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_RxFullReleaseObj()
 *********************************************************************************************************************/
/*! \brief         Release FullCAN mailbox
 *  \details       Called by reception to release object
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_RxFullMsgReceivedEnd()
 *********************************************************************************************************************/
/*! \brief         Release FullCAN receive end
 *  \details       Called by reception to finish handling
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);
/* CODE CATEGORY 1 END */
# if defined( C_ENABLE_RX_FULLCAN_POLLING )
/**********************************************************************************************************************
 *  CanLL_RxFullProcessPendings()
 *********************************************************************************************************************/
/*! \brief         Check FullCAN receive pending
 *  \details       Called by reception to get mailbox pending state
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] taskPara            Pointer to local variables of reception task
 *  \return        kCanTrue            mailbox pending
 *                 kCanFailed          no pending
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);
/* CODE CATEGORY 2 END */
# endif /* C_ENABLE_RX_FULLCAN_POLLING */
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

/**********************************************************************************************************************
 *  CanLL_ErrorHandlingBegin()
 *********************************************************************************************************************/
/*! \brief         Perform error handling begin
 *  \details       Called by error handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
/**********************************************************************************************************************
 *  CanLL_BusOffOccured()
 *********************************************************************************************************************/
/*! \brief         Check BusOff occur
 *  \details       Called by error handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \return        kCanTrue            BusOff occur
 *                 kCanFailed          no BusOff occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
/**********************************************************************************************************************
 *  CanLL_ErrorHandlingEnd()
 *********************************************************************************************************************/
/*! \brief         Perform error handling end
 *  \details       Called by error handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
#if defined( C_ENABLE_EXTENDED_STATUS )
/**********************************************************************************************************************
 *  CanLL_GetStatusBegin()
 *********************************************************************************************************************/
/*! \brief         Perform read out of status information
 *  \details       Called by GetStatus API
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 3 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_GetStatusBegin(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 3 END */
#endif
/**********************************************************************************************************************
 *  CanLL_ModeTransition()
 *********************************************************************************************************************/
/*! \brief         Perform mode change
 *  \details       Called by mode handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in]     mode                mode to be set
 *  \param[in]     busOffRecovery      BusOff recovery should be done or not
 *  \param[in]     ramCheck            RamCheck should be done or not
 *  \return        kCanOk              Successfully completed
 *                 kCanRequested       Mode not yet reached
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST vuint8 mode, vuint8 busOffRecovery, vuint8 ramCheck);
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_CAN_INTERRUPT_CONTROL ) /* COV_CAN_LOCK_ISR_BY_APPL */
/************************************************************************************************************
 *  CanLL_CanInterruptDisable()
 ***********************************************************************************************************/
/*! \brief         Disables CAN interrupts.
 *  \details       Stores current state and disables the individual CAN interrupt sources.
 *  \param[in]     canHwChannel              CAN channel
 *  \param[out]    localInterruptOldFlagPtr  Pointer to global variable that holds the interrupt state
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ***********************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptDisable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr);
/* CODE CATEGORY 1 END */

/************************************************************************************************************
 *  CanLL_CanInterruptRestore()
 ***********************************************************************************************************/
/*! \brief         Restores CAN interrupts.
 *  \details       Restores the previous state of the individual CAN interrupt sources.
 *  \param[in]     canHwChannel              CAN channel
 *  \param[in]     localInterruptOldFlag     Global variable that holds the interrupt state
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ***********************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptRestore(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOld localInterruptOldFlag);
/* CODE CATEGORY 1 END */
#endif


#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/************************************************************************************************************
*  CanLL_InitRxBasicCANSubSetMask()
************************************************************************************************************/
/*! \brief         set the mask and arbitration register
 *  \details       called out of init Rx Basic CAN objects function
 *  \param[in]     canHwChannel     CAN channel
 *  \param[in]     initInfo         pointer to a structure which contains all necessary informations for init
 *  \param[in]     hwObjHandle      actual hwobject to be configured
 *  \param[in]     Htrh             actual logical object to be configured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE)  CanLL_InitRxBasicCANSubSetMask( CAN_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara, Can_HwHandleType hwObjHandle);

/************************************************************************************************************
*  CanLL_InitRxBasicCANSubCloseMask()
************************************************************************************************************/
/*! \brief         close the hardware filter completely
 *  \details       called out of init Rx Basic CAN objects function
 *  \param[in]     canHwChannel     CAN channel
 *  \param[in]     initInfo         pointer to a structure which contains all necessary informations for init
 *  \param[in]     hwObjHandle      actual hwobject to be configured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE)  CanLL_InitRxBasicCANSubCloseMask(CAN_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara, Can_HwHandleType hwObjHandle);
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined(C_ENABLE_CAN_FD_FULL)
/************************************************************************************************************
 *  CanLL_ReadFdData()
 ***********************************************************************************************************/
/*! \brief         copy extended FD data
 *  \details       copy the extended data of FD frames to buffer
 *  \param[in]     pCanFdCellMailbox  pointer to CAN msg object which contains the extended data
 *  \param[in]     bufferPtr          pointer to a buffer where to copy the data to
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ReadFdData(CanFdMsgObjStructPtr pCanFdCellMailbox, volatile vuint32* bufferPtr);

/************************************************************************************************************
 *  CanLL_WriteFdData()
 ***********************************************************************************************************/
/*! \brief         copy extended FD data to HW
 *  \details       copy the extended data of FD frames to HW
 *  \param[in]     pCanFdCellMailbox  pointer to CAN msg object which contains the extended data
 *  \param[in]     bufferPtr          pointer to a buffer where to copy the data from
 *  \param[in]     paddingValue       pad unused data bytes with this value
 *  \param[in]     paddingIndex       index where the padding should begin from
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteFdData(CanFdMsgObjStructPtr pCanFdCellMailbox, volatile const vuint8* bufferPtr, vuint8 paddingValue, vuint8 paddingIndex);
#endif

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS ) || defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/************************************************************************************************************
 *  CanLL_CopyToTmpRxMailbox()
 ***********************************************************************************************************/
/*! \brief         copy mailbox to temp
 *  \details       copy mailbox information and data from HW to temporary object
 *  \param[in]     msgObjHandle   index of the CAN msg object to be copied
 *  \param[in]     copyFdData     indicates if FD data has to be considered for copy
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CopyToTmpRxMailbox(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle msgObjHandle, vuint8 copyFdData);
#endif

/************************************************************************************************************
 *  CanLL_WaitForListReady()
 ***********************************************************************************************************/
/*! \brief         Waits until the CAN cell is ready to receive the next command
 *  \details       Needed to synchronize CAN cell and CPU
 *  \param[in]     canHwChannel       CAN channel
 *  \param[in]     pCanCellModule     pointer to the CAN cell global module register
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_WaitForListReady(CAN_HW_CHANNEL_CANTYPE_FIRST CanModuleStructPtr pCanCellModule );

/************************************************************************************************************
 *  CanLL_SetListCmd()
 ***********************************************************************************************************/
/*! \brief         Assigns the CAN object functionality
 *  \details       The hardware object is assigned to a node list
 *  \param[in]     pCanCellModule        pointer to the CAN cell global module register
 *  \param[in]     node                  node list number
 *  \param[in]     hwObjHandle           CAN object handle
 *  \param[in]     PanCmd                Panel Command
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_SetListCmd(CAN_HW_CHANNEL_CANTYPE_FIRST CanModuleStructPtr pCanCellModule, vuint8 node, Can_HwHandleType hwObjHandle,  vuint16 PanCmd );

/************************************************************************************************************
 *  CanLL_IncSELPtr()
 ***********************************************************************************************************/
/*! \brief         Increment Rx HW FIFO selection pointer
 *  \details       FIFO is a software ring buffer
 *  \param[in]     pCanCellMailbox      pointer to the used mailbox
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_IncSELPtr( CanMsgObjStructPtr pCanCellMailbox );

/************************************************************************************************************
 *  CanLL_Reset_MoCtr()
 ***********************************************************************************************************/
/*! \brief         Register control function
 *  \details       reset register MOCTR and read back result if extended RAM check is active.
 *  \param[in]     Controller          CAN controller
 *  \param[in]     regPtr              vuint16 pointer to the corresponding register MOCTRCAN.
 *  \param[in]     value               pattern of bits to be cleared
 *  \param[in]     readMask            mask of bits to be verified
 *  \return        kCanTrue:           mailbox is corrupt
 *  \return        kCanFalse:          mailbox is not corrupt  
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_Reset_MoCtr( CanChipMsgPtr16 regPtr, vuint16 value, vuint16 readMask, CanInitParaStructPtr initPara );

/************************************************************************************************************
 *  CanLL_Set_MoCtr()
 ***********************************************************************************************************/
/*! \brief         Register control function
 *  \details       set register MOCTR and read back result if extended RAM check is active.
 *  \param[in]     Controller          CAN controller
 *  \param[in]     regPtr              vuint16 pointer to the corresponding register MOCTRCAN.
 *  \param[in]     value               pattern of bits to be cleared
 *  \param[in]     readMask            mask of bits to be verified
 *  \return        kCanTrue:           mailbox is corrupt
 *  \return        kCanFalse:          mailbox is not corrupt  
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_Set_MoCtr( CanChipMsgPtr16 regPtr, vuint16 value, vuint16 readMask, CanInitParaStructPtr initPara );

#if (CAN_SAFE_BSW == STD_ON)
/************************************************************************************************************
 *  CanLL_CheckGeneratedDataAccess()
***********************************************************************************************************/
/*! \brief         Accesses the generated data and validates it.
 *  \details       validate the generated node index and Safe Mask for message object index.
 *  \param[in]     Controller          CAN controller
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occurred
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_CheckGeneratedDataAccess(CAN_CHANNEL_CANTYPE_ONLY);
#endif

/************************************************************************************************************
 *  CanLL_ModeTransitionStart()
 ***********************************************************************************************************/
/*! \brief         Set to start mode.
 *  \details       set can cell to start mode.
 *  \param[in]     Controller          CAN controller
 *  \return        kCanTrue:           mode transition OK
 *  \return        kCanFalse:          mode transition failed
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ModeTransitionStart(CAN_CHANNEL_CANTYPE_FIRST vuint8 silentMode);

/************************************************************************************************************
 *  CanLL_ModeTransitionStop()
 ***********************************************************************************************************/
/*! \brief         Set to stop mode.
 *  \details       set can cell to stop mode.
 *  \param[in]     Controller          CAN controller
 *  \return        kCanTrue:           mode transition OK
 *  \return        kCanFalse:          mode transition failed
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ModeTransitionStop(CAN_CHANNEL_CANTYPE_ONLY);



#if defined(C_ENABLE_HW_LOOP_TIMER) /* always used for sync mode */
# if (CAN_HW_LOOP_SUPPORT_API == STD_OFF)
/************************************************************************************************************
 *  ApplCanTimerLoop()
 ***********************************************************************************************************/
/*! \brief         Time out monitoring
 *  \details       Service function to check (against generated maximum loop value) whether a hardware loop shall be continued or broken.
 *  \param[in]     Controller  CAN controller on which the hardware observation takes place. \n
 *                             (only if not using "Optimize for one controller")
 *  \param[in]     source      Source for the hardware observation.
 *  \return        CAN_NOT_OK  when loop shall be broken (observation stops) \n
 *                             CAN_NOT_OK should only be used in case of a time out occurs due to a hardware issue. \n
 *                             After this an appropriate error handling is needed (see chapter Hardware Loop Check / Time out Monitoring).
 *  \return        CAN_OK      when loop shall be continued (observation continues)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Please refer to chapter "Hardware Loop Check".
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) ApplCanTimerLoop(CAN_CHANNEL_CANTYPE_FIRST uint8 source);
# endif
#endif

/************************************************************************************************************
 *  CanHL_ModeTransition()
 ***********************************************************************************************************/
/*! \brief         Request mode transition
 *  \details       Handle/Request transition and wait asynchronous-short time.
 *                 Called by Can_SetControllerMode().
 *  \param[in]     Controller         CAN controller (Controller must be in valid range). \n
 *                                    (only if not using "Optimize for one controller") \n
 *  \param[in]     transitionRequest  transition request used to switch mode (kCanModeInit, kCanModeSleep, kCanModeWakeupStopReinit, \n
 *                                    kCanModeStopReinit, kCanModeStopReinitFast, kCanModeStart, kCanModeStartReinit, kCanModeSilent, \n
 *                                    kCanModeResetBusOffStart, kCanModeResetBusOffEnd). \n
 *  \param[in]     busOffRecovery     handling of the busoff behaviour (kCanFinishBusOffRecovery, kCanContinueBusOffRecovery). \n
 *  \param[in]     doRamCheck         do a RAM check while reinit or not (kCanExecuteRamCheck, kCanSuppressRamCheck). \n
 *  \return        kCanFailed         transition rejected
 *  \return        kCanRequested      transition requested but is ongoing asynchronous
 *  \return        kCanOk             transition finished successful
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_ModeTransition(CAN_CHANNEL_CANTYPE_FIRST uint8 transitionRequest, uint8 busOffRecovery, uint8 doRamCheck);

/************************************************************************************************************
 *  CanHL_NotifyTransition()
 ***********************************************************************************************************/
/*! \brief         notify about sucessful mode transition
 *  \details       notify to upper layer.
 *                 Called by Can_SetControllerMode().
 *  \param[in]     Controller         CAN controller (Controller must be in valid range). \n
 *                                    (only if not using "Optimize for one controller") \n
 *  \param[in]     canState           CAN controller mode to be switched to (CAN_STATUS_STOP, CAN_STATUS_START, CAN_STATUS_SLEEP). \n
 *  \param[in]     canIfState         CAN controller mode to be switched to (CANIF_CS_STOPPED, CANIF_CS_STARTED, CANIF_CS_SLEEP). \n
 *  \param[in]     transitionState    transition request state (kCanFailed, kCanRequested, kCanOk). \n
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_NotifyTransition(CAN_CHANNEL_CANTYPE_FIRST uint8 canState, CanIf_ControllerModeType canIfState, uint8 transitionState);


/************************************************************************************************************
 *  CanHL_WritePrepare()
 ***********************************************************************************************************/
/*! \brief         TX preparation
 *  \details       Search for BasicCAN object handle to transmit (Multiplexed TX) and backup data for cancel TX object if necessary.
 *                 calculate txPara member activeSendObject, and mailboxElement
 *                 Called by Can_Write().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in,out] txPara           mailbox information
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WritePrepare(CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);



/************************************************************************************************************
 *  CanHL_WriteStart()
 ***********************************************************************************************************/
/*! \brief         TX start
 *  \details       Write ID, DLC and Data to FullCAN or BasicCAN object and set transmit request
 *                 Called by Can_Write().
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in,out] txPara          mailbox information
 *  \return        CAN_NOT_OK      transmission failed.
 *  \return        CAN_OK          transmission successful.
 *  \return        CAN_BUSY        transition object busy - repeat it.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_WriteStart(CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

/************************************************************************************************************
 *  CanHL_GetActiveSendObject()
 ***********************************************************************************************************/
/*! \brief         Convert Handle
 *  \details       Hardware to logical Handle conversion.
 *  \param[in]     mailboxHandle   Handle to mailbox object
 *  \param[in]     mailboxElement  mailbox element
 *  \return        logical handle for the given hardware mailbox
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, CanObjectHandle, STATIC_CODE) CanHL_GetActiveSendObject(Can_HwHandleType mailboxHandle, Can_HwHandleType mailboxElement);


#if defined(C_ENABLE_CAN_RAM_CHECK)
/************************************************************************************************************
 *  CanHL_RamCheckMailboxNotification()
 ***********************************************************************************************************/
/*! \brief         RAM check
 *  \details       Notify upper layer in case of an HW issue and deactivate controller.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \param[in]     htrh             Hrh or Hth of the hardware object
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

/************************************************************************************************************
 *  CanHL_InitBegin()
 ***********************************************************************************************************/
/*! \brief         Start Initialization
 *  \details       LL implementation see token CanLL_InitBegin description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitBegin(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);

#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_InitTxFullCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize TX FullCAN
 *  \details       LL implementation see token CanLL_InitTxObj description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxFullCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

/************************************************************************************************************
 *  CanHL_InitTxBasicCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize TX BasicCAN
 *  \details       LL implementation see token CanLL_InitTxObj description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxBasicCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);


#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_InitRxFullCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize RX FullCAN
 *  \details       LL implementation see token CanLL_InitFullCANObj description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxFullCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
/************************************************************************************************************
 *  CanHL_InitRxBasicCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize RX BasicCAN
 *  \details       LL implementation see token CanLL_InitBasicCANObj description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxBasicCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

/************************************************************************************************************
 *  CanHL_InitEnd_InitMode()
 ***********************************************************************************************************/
/*! \brief         End Initialization
 *  \details       LL implementation see token CanLL_InitEnd_InitMode description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitEnd_InitMode(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/************************************************************************************************************
 *  CanHL_RxBasicCanPolling()
 ***********************************************************************************************************/
/*! \brief         RX BasicCAN polling
 *  \details       RX BasicCAN polling handling.
 *                 Called by Can_MainFunctionRead().
 *  \param[in]     Controller    CAN controller.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxBasicCanPolling(CAN_HW_CHANNEL_CANTYPE_ONLY);
# endif
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/************************************************************************************************************
 *  CanHL_RxFullCanPolling()
 ***********************************************************************************************************/
/*! \brief         RX FullCAN polling
 *  \details       RX FullCAN polling handling.
 *                 Called by Can_MainFunctionRead().
 *  \param[in]     Controller    CAN controller.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxFullCanPolling(CAN_HW_CHANNEL_CANTYPE_ONLY);
# endif
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
/************************************************************************************************************
 *  CanHL_RxMsgReceivedNotification()
 ***********************************************************************************************************/
/*! \brief         RX notification
 *  \details       RX queue and notification handling for BasicCAN and FullCAN reception.
 *                 Called by CanHL_BasicCanMsgReceived(),CanHL_FullCanMsgReceived().
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxStructPtr     include general rx info and all LL specific data.
 *  \return        errorId         error identifier reporting to DET
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANTYPE_FIRST CanRxInfoStructPtr rxStructPtr);
#endif

#if defined(C_ENABLE_RX_QUEUE)
/************************************************************************************************************
 *  CanHL_RxQueueExecution()
 ***********************************************************************************************************/
/*! \brief         RX queue
 *  \details       RX queue execution and notification.
 *                 Called by Can_MainFunction_Read().
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxQueueExecution(void);
#endif

#if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */
/************************************************************************************************************
 *  CanHL_TxConfirmationPolling()
 ***********************************************************************************************************/
/*! \brief         TX Confirmation intermediate call
 *  \details       intermediate call to do interrupt locks between polling call from LL and HL handling.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     mailboxHandle   mailbox handle
 *  \param[in]     mailboxElement  index of the mailboxElement (muxTx, FIFO)
 *  \param[in]     hwObjHandle     hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_TxConfirmationPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle);
#endif

/************************************************************************************************************
 *  CanHL_TxConfirmation()
 ***********************************************************************************************************/
/*! \brief         TX Confirmation handling
 *  \details       Called for a transmit or cancel event. Finish transmission by free send mailbox and call confirmation. \n
 *                 Called for FullCAN and BasicCAN handling.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     mailboxHandle   mailbox handle
 *  \param[in]     mailboxElement  index of the mailboxElement (muxTx, FIFO)
 *  \param[in]     hwObjHandle     transmitted hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_TxConfirmation(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle);


#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/************************************************************************************************************
 *  CanHL_SetCanPduInfo()
 ***********************************************************************************************************/
/*! \brief         copy the confirmation parameter info to the PduInfo struct
 *  \details       Called while confirmation handling to set data struct need for confirmation API2. \n
 *  \param[in,out] PduInfo             Pointer to local PduInfo struct
 *  \param[in]     txConfPara          Pointer to local variables of confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_SetCanPduInfo(Can_PduInfoPtrType_var PduInfo, CanTxConfirmationParaStructPtr txConfPara);
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/************************************************************************************************************
 *  CanHL_BasicCanMsgReceivedPolling()
 ***********************************************************************************************************/
/*! \brief         RX Indication intermediate call
 *  \details       intermediate call to do interrupt locks between polling call from LL and HL handling.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxMailboxHandle mailbox handle
 *  \param[in]     hwObjHandle     received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_BasicCanMsgReceivedPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
# endif

/************************************************************************************************************
 *  CanHL_BasicCanMsgReceived()
 ***********************************************************************************************************/
/*! \brief         Handle reception
 *  \details       Receive BasicCAN data and call indication function.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxMailboxHandle mailbox handle
 *  \param[in]     hwObjHandle     received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_BasicCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/************************************************************************************************************
 *  CanHL_FullCanMsgReceivedPolling()
 ***********************************************************************************************************/
/*! \brief         RX Indication intermediate call
 *  \details       intermediate call to do interrupt locks between polling call from LL and HL handling.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxMailboxHandle mailbox handle
 *  \param[in]     hwObjHandle     received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_FullCanMsgReceivedPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

/************************************************************************************************************
 *  CanHL_FullCanMsgReceived()
 ***********************************************************************************************************/
/*! \brief         Handle reception
 *  \details       Receive FullCAN data and call indication function.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxMailboxHandle mailbox handle
 *  \param[in]     hwObjHandle     received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_FullCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

/************************************************************************************************************
 *  CanHL_ErrorHandling()
 ***********************************************************************************************************/
/*! \brief         BUSOFF handling
 *  \details       Handler for bus off situation.
 *  \param[in]     Controller    CAN controller. \n
 *                               (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_ErrorHandling(CAN_HW_CHANNEL_CANTYPE_ONLY);



/************************************************************************************************************
 *  CanHL_ReInit()
 ***********************************************************************************************************/
/*! \brief         Initialization of controller specific CAN hardware.
 *  \details       Initialization of the CAN controller hardware registers and CAN driver variables. \n
 *                 after that the controller is fully initialized and can be swtiched to "STOP Mode".
 *  \param[in]     Controller            CAN controller. \n
 *                                       (only if not using "Optimize for one controller")
 *  \param[in]     doRamCheck            RAM check exectuion (kCanExecuteRamCheck, kCanSuppressRamCheck).
 *  \return        error                 return kCanFailed in case of issue or kCanOk if initialization pass.
 *  \pre           controller is ready to be configured (INIT mode).
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         no mode change must be done inside. No CAN bus depended hardware loops allowed.
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, uint8, STATIC_CODE) CanHL_ReInit(CAN_HW_CHANNEL_CANTYPE_FIRST uint8 doRamCheck);

#define CAN_STOP_SEC_STATIC_CODE  /*----------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* CAN_LOCAL_H */

/* End of channel */

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

