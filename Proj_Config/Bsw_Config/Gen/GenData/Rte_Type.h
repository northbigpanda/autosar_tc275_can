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
 *             File:  Rte_Type.h
 *           Config:  TC27x.dpa
 *      ECU-Project:  TC27x
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

# include "Rte.h"

/* PRQA S 1039 EOF */ /* MD_Rte_1039 */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_AAA_Angle
typedef uint8 AAA_Angle;

# define Rte_TypeDef_Button1_Control
typedef boolean Button1_Control;

# define Rte_TypeDef_Button1_State
typedef boolean Button1_State;

# define Rte_TypeDef_Button2_Control
typedef boolean Button2_Control;

# define Rte_TypeDef_Button2_State
typedef boolean Button2_State;

# define Rte_TypeDef_Button3_Control
typedef boolean Button3_Control;

# define Rte_TypeDef_Button3_State
typedef boolean Button3_State;

# define Rte_TypeDef_Button4_Control
typedef boolean Button4_Control;

# define Rte_TypeDef_Button4_State
typedef boolean Button4_State;

# define Rte_TypeDef_CrcSig_Pack_3
typedef uint8 CrcSig_Pack_3;

# define Rte_TypeDef_CrcSig_Pack_4
typedef uint32 CrcSig_Pack_4;

# define Rte_TypeDef_CrcSig_Pack_5
typedef uint32 CrcSig_Pack_5;

# define Rte_TypeDef_Led1_Control_1
typedef boolean Led1_Control_1;

# define Rte_TypeDef_Led1_State
typedef boolean Led1_State;

# define Rte_TypeDef_Led2_Control_1
typedef boolean Led2_Control_1;

# define Rte_TypeDef_Led2_State
typedef boolean Led2_State;

# define Rte_TypeDef_Led3_Control_1
typedef boolean Led3_Control_1;

# define Rte_TypeDef_Led3_State
typedef boolean Led3_State;

# define Rte_TypeDef_Led4_Control_1
typedef boolean Led4_Control_1;

# define Rte_TypeDef_Led4_State
typedef boolean Led4_State;

# define Rte_TypeDef_PowerMode
typedef uint8 PowerMode;

# define Rte_TypeDef_Sig_0x114_Used_10
typedef uint16 Sig_0x114_Used_10;

# define Rte_TypeDef_Sig_0x114_Used_6
typedef uint8 Sig_0x114_Used_6;

# define Rte_TypeDef_Sig_0x114_Used_7
typedef uint16 Sig_0x114_Used_7;

# define Rte_TypeDef_Sig_0x114_Used_8
typedef uint16 Sig_0x114_Used_8;

# define Rte_TypeDef_Sig_0x114_Used_9
typedef uint16 Sig_0x114_Used_9;

# define Rte_TypeDef_Sig_0x115_Used_1
typedef uint8 Sig_0x115_Used_1;

# define Rte_TypeDef_Sig_0x115_Used_2
typedef uint16 Sig_0x115_Used_2;

# define Rte_TypeDef_Sig_0x115_Used_3
typedef uint16 Sig_0x115_Used_3;

# define Rte_TypeDef_Sig_0x115_Used_4
typedef uint16 Sig_0x115_Used_4;

# define Rte_TypeDef_Sig_0x115_Used_5
typedef uint16 Sig_0x115_Used_5;

# define Rte_TypeDef_Sig_0x402_Used_1
typedef uint8 Sig_0x402_Used_1;

# define Rte_TypeDef_Sig_0x402_Used_2
typedef uint16 Sig_0x402_Used_2;

# define Rte_TypeDef_Sig_0x402_Used_3
typedef uint16 Sig_0x402_Used_3;

# define Rte_TypeDef_Sig_0x402_Used_4
typedef uint16 Sig_0x402_Used_4;

# define Rte_TypeDef_Sig_0x402_Used_5
typedef uint16 Sig_0x402_Used_5;

# define Rte_TypeDef_Sig_0x403_Used_1
typedef uint8 Sig_0x403_Used_1;

# define Rte_TypeDef_Sig_0x403_Used_2
typedef uint16 Sig_0x403_Used_2;

# define Rte_TypeDef_Sig_0x403_Used_3
typedef uint16 Sig_0x403_Used_3;

# define Rte_TypeDef_Sig_0x403_Used_4
typedef uint16 Sig_0x403_Used_4;

# define Rte_TypeDef_Sig_0x403_Used_5
typedef uint16 Sig_0x403_Used_5;

# define Rte_TypeDef_SupA_Checksum_0x112
typedef uint8 SupA_Checksum_0x112;

# define Rte_TypeDef_SupA_Counter_0x112
typedef uint8 SupA_Counter_0x112;

# define Rte_TypeDef_SupB_Checksum_0x400_1
typedef uint8 SupB_Checksum_0x400_1;

# define Rte_TypeDef_SupB_Counter_0x400_1
typedef uint8 SupB_Counter_0x400_1;

# define Rte_TypeDef_Dcm_Data1ByteType
typedef uint8 Dcm_Data1ByteType[1];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[1];

# define Rte_TypeDef_SG_Sig_Grp_0x110
typedef struct
{
  Led1_State Led1_State;
  Led2_State Led2_State;
  Led3_State Led3_State;
  Led4_State Led4_State;
} SG_Sig_Grp_0x110;

# define Rte_TypeDef_SG_Sig_Grp_0x111
typedef struct
{
  Button1_State Button1_State;
  Button2_State Button2_State;
  Button3_State Button3_State;
  Button4_State Button4_State;
} SG_Sig_Grp_0x111;

# define Rte_TypeDef_SG_Sig_Grp_0x112
typedef struct
{
  PowerMode PowerMode;
  SupA_Checksum_0x112 SupA_Checksum_0x112;
  SupA_Counter_0x112 SupA_Counter_0x112;
} SG_Sig_Grp_0x112;

# define Rte_TypeDef_SG_Sig_Grp_0x113
typedef struct
{
  AAA_Angle AAA_Angle;
} SG_Sig_Grp_0x113;

# define Rte_TypeDef_SG_Sig_Grp_0x114
typedef struct
{
  Sig_0x114_Used_6 Sig_0x114_Used_1;
  Sig_0x114_Used_7 Sig_0x114_Used_2;
  Sig_0x114_Used_8 Sig_0x114_Used_3;
  Sig_0x114_Used_9 Sig_0x114_Used_4;
  Sig_0x114_Used_10 Sig_0x114_Used_5;
} SG_Sig_Grp_0x114;

# define Rte_TypeDef_SG_Sig_Grp_0x115
typedef struct
{
  Sig_0x115_Used_1 Sig_0x115_Used_1;
  Sig_0x115_Used_2 Sig_0x115_Used_2;
  Sig_0x115_Used_3 Sig_0x115_Used_3;
  Sig_0x115_Used_4 Sig_0x115_Used_4;
  Sig_0x115_Used_5 Sig_0x115_Used_5;
} SG_Sig_Grp_0x115;

# define Rte_TypeDef_SG_Sig_Grp_0x400
typedef struct
{
  CrcSig_Pack_3 CrcSig_Pack_0;
  CrcSig_Pack_4 CrcSig_Pack_1;
  CrcSig_Pack_5 CrcSig_Pack_2;
  Led1_Control_1 Led1_Control;
  Led2_Control_1 Led2_Control;
  Led3_Control_1 Led3_Control;
  Led4_Control_1 Led4_Control;
  SupB_Checksum_0x400_1 SupB_Checksum_0x400;
  SupB_Counter_0x400_1 SupB_Counter_0x400;
} SG_Sig_Grp_0x400;

# define Rte_TypeDef_SG_Sig_Grp_0x401
typedef struct
{
  Button1_Control Button1_Control;
  Button2_Control Button2_Control;
  Button3_Control Button3_Control;
  Button4_Control Button4_Control;
} SG_Sig_Grp_0x401;

# define Rte_TypeDef_SG_Sig_Grp_0x402
typedef struct
{
  Sig_0x402_Used_1 Sig_0x402_Used_1;
  Sig_0x402_Used_2 Sig_0x402_Used_2;
  Sig_0x402_Used_3 Sig_0x402_Used_3;
  Sig_0x402_Used_4 Sig_0x402_Used_4;
  Sig_0x402_Used_5 Sig_0x402_Used_5;
} SG_Sig_Grp_0x402;

# define Rte_TypeDef_SG_Sig_Grp_0x403
typedef struct
{
  Sig_0x403_Used_1 Sig_0x403_Used_1;
  Sig_0x403_Used_2 Sig_0x403_Used_2;
  Sig_0x403_Used_3 Sig_0x403_Used_3;
  Sig_0x403_Used_4 Sig_0x403_Used_4;
  Sig_0x403_Used_5 Sig_0x403_Used_5;
} SG_Sig_Grp_0x403;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint16 ComM_UserHandleType;

# define Rte_TypeDef_Dem_DTCGroupType
typedef uint32 Dem_DTCGroupType;

# define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;

# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;

# define Rte_TypeDef_Dem_RatioIdType
typedef uint16 Dem_RatioIdType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_IOHWAB_BOOL
typedef boolean IOHWAB_BOOL;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_BswM_ESH_Mode
typedef uint8 BswM_ESH_Mode;

# define Rte_TypeDef_BswM_ESH_RunRequest
typedef uint8 BswM_ESH_RunRequest;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;

# define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;

# define Rte_TypeDef_Dem_DTCOriginType
typedef uint16 Dem_DTCOriginType;

# define Rte_TypeDef_Dem_DTCSeverityType
typedef uint8 Dem_DTCSeverityType;

# define Rte_TypeDef_Dem_DTRControlType
typedef uint8 Dem_DTRControlType;

# define Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;

# define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;

# define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;

# define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;

# define Rte_TypeDef_Dem_InitMonitorReasonType
typedef uint8 Dem_InitMonitorReasonType;

# define Rte_TypeDef_Dem_IumprDenomCondIdType
typedef uint8 Dem_IumprDenomCondIdType;

# define Rte_TypeDef_Dem_IumprDenomCondStatusType
typedef uint8 Dem_IumprDenomCondStatusType;

# define Rte_TypeDef_Dem_IumprReadinessGroupType
typedef uint8 Dem_IumprReadinessGroupType;

# define Rte_TypeDef_Dem_MonitorStatusType
typedef uint8 Dem_MonitorStatusType;

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;

# define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;

# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;

# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_CrcSig_Pack_0
typedef uint8 CrcSig_Pack_0;

#  define Rte_TypeDef_CrcSig_Pack_1
typedef uint32 CrcSig_Pack_1;

#  define Rte_TypeDef_CrcSig_Pack_2
typedef uint32 CrcSig_Pack_2;

#  define Rte_TypeDef_Led1_Control
typedef boolean Led1_Control;

#  define Rte_TypeDef_Led2_Control
typedef boolean Led2_Control;

#  define Rte_TypeDef_Led3_Control
typedef boolean Led3_Control;

#  define Rte_TypeDef_Led4_Control
typedef boolean Led4_Control;

#  define Rte_TypeDef_Sig_0x114_Used_1
typedef uint8 Sig_0x114_Used_1;

#  define Rte_TypeDef_Sig_0x114_Used_2
typedef uint16 Sig_0x114_Used_2;

#  define Rte_TypeDef_Sig_0x114_Used_3
typedef uint16 Sig_0x114_Used_3;

#  define Rte_TypeDef_Sig_0x114_Used_4
typedef uint16 Sig_0x114_Used_4;

#  define Rte_TypeDef_Sig_0x114_Used_5
typedef uint16 Sig_0x114_Used_5;

#  define Rte_TypeDef_SupB_Checksum_0x400
typedef uint8 SupB_Checksum_0x400;

#  define Rte_TypeDef_SupB_Counter_0x400
typedef uint8 SupB_Counter_0x400;

#  define Rte_TypeDef_System_Run_Time
typedef uint8 System_Run_Time;

#  define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

#  define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

#  define Rte_TypeDef_ComM_Mode
typedef struct
{
  uint8 ComM_FULL_COM;
} ComM_Mode;

#  define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;

#  define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

#  define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(SG_Sig_Grp_0x110, RTE_CONST) Rte_C_SG_Sig_Grp_0x110_0;

extern CONST(SG_Sig_Grp_0x111, RTE_CONST) Rte_C_SG_Sig_Grp_0x111_0;

extern CONST(SG_Sig_Grp_0x112, RTE_CONST) Rte_C_SG_Sig_Grp_0x112_0;

extern CONST(SG_Sig_Grp_0x113, RTE_CONST) Rte_C_SG_Sig_Grp_0x113_0;

extern CONST(SG_Sig_Grp_0x114, RTE_CONST) Rte_C_SG_Sig_Grp_0x114_0;

extern CONST(SG_Sig_Grp_0x115, RTE_CONST) Rte_C_SG_Sig_Grp_0x115_0;

extern CONST(SG_Sig_Grp_0x400, RTE_CONST) Rte_C_SG_Sig_Grp_0x400_0;

extern CONST(SG_Sig_Grp_0x401, RTE_CONST) Rte_C_SG_Sig_Grp_0x401_0;

extern CONST(SG_Sig_Grp_0x402, RTE_CONST) Rte_C_SG_Sig_Grp_0x402_0;

extern CONST(SG_Sig_Grp_0x403, RTE_CONST) Rte_C_SG_Sig_Grp_0x403_0;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# include "Rte_DataHandleType.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned int Rte_BitType;
/**********************************************************************************************************************
 * type and extern declarations of RTE internal variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

# define RTE_STATE_UNINIT    (0U)
# define RTE_STATE_SCHM_INIT (1U)
# define RTE_STATE_INIT      (2U)

# define RTE_START_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState; /* PRQA S 3408 */ /* MD_Rte_3408 */
extern volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_StartTiming_InitState; /* PRQA S 0850, 3408 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_1; /* PRQA S 3408 */ /* MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_2; /* PRQA S 3408 */ /* MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(SG_Sig_Grp_0x111, RTE_VAR_INIT) Rte_AppButtonCtrl_SG_Sig_Grp_0x111_SR_S_SG_Sig_Grp_0x111; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x400, RTE_VAR_INIT) Rte_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x401, RTE_VAR_INIT) Rte_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x402, RTE_VAR_INIT) Rte_AppComRx_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x403, RTE_VAR_INIT) Rte_AppComRx_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x112, RTE_VAR_INIT) Rte_AppCtrl_SG_Sig_Grp_0x112_SR_R_SG_Sig_Grp_0x112; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x113, RTE_VAR_INIT) Rte_AppCtrl_SG_Sig_Grp_0x113_SR_R_SG_Sig_Grp_0x113; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x114, RTE_VAR_INIT) Rte_AppCtrl_SG_Sig_Grp_0x114_SR_R_SG_Sig_Grp_0x114; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x115, RTE_VAR_INIT) Rte_AppCtrl_SG_Sig_Grp_0x115_SR_R_SG_Sig_Grp_0x115; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SG_Sig_Grp_0x110, RTE_VAR_INIT) Rte_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ComM_ModeType, RTE_VAR_INIT) Rte_AppWakeUpCtrl_App_ComM_Mode_Request_Request_Mode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

typedef struct
{
  Rte_BitType Rte_ModeSwitchAck_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode_Ack : 1;
} Rte_SystemApplication_OsCore0_AckFlagsType;

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_SystemApplication_OsCore0_AckFlagsType, RTE_VAR_INIT) Rte_SystemApplication_OsCore0_AckFlags;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_ESH_Mode, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# endif /* defined(RTE_CORE) */

/**********************************************************************************************************************
 * extern declaration of RTE Update Flags for optimized macro implementation
 *********************************************************************************************************************/
typedef struct
{
  Rte_BitType Rte_RxUpdate_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 : 1;
  Rte_BitType Rte_RxUpdate_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_Sender : 1;
} Rte_SystemApplication_OsCore0_RxUpdateFlagsType;

# define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_SystemApplication_OsCore0_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_SystemApplication_OsCore0_RxUpdateFlags;

# define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

*/
