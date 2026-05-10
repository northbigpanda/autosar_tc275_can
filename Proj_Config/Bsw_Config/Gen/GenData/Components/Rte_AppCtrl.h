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
 *             File:  Rte_AppCtrl.h
 *           Config:  TC27x.dpa
 *      ECU-Project:  TC27x
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  Application header file for SW-C <AppCtrl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_APPCTRL_H
# define RTE_APPCTRL_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_AppCtrl_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Sig_0x114_Used_6, RTE_VAR_INIT) Rte_AppCtrl_Sig_0x114_Used_SR_S_Sig_0x114_Used_6;
extern VAR(Trigger_Msg_Type, RTE_VAR_INIT) Rte_AppCtrl_Trigger_Msg_State_SR_S_Trigger_Msg_State;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Sig_0x114_Used_SR_S_Sig_0x114_Used_6 (0U)
#  define Rte_InitValue_Trigger_Msg_State_SR_S_Trigger_Msg_State (FALSE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppCtrl_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400(P2VAR(SG_Sig_Grp_0x400, AUTOMATIC, RTE_APPCTRL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppCtrl_SG_Sig_Grp_0x401_SR_R_SG_Sig_Grp_0x401(P2VAR(SG_Sig_Grp_0x401, AUTOMATIC, RTE_APPCTRL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppCtrl_SG_Sig_Grp_0x402_SR_R_SG_Sig_Grp_0x402(P2VAR(SG_Sig_Grp_0x402, AUTOMATIC, RTE_APPCTRL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppCtrl_SG_Sig_Grp_0x403_SR_R_SG_Sig_Grp_0x403(P2VAR(SG_Sig_Grp_0x403, AUTOMATIC, RTE_APPCTRL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppCtrl_SG_Sig_Grp_0x112_SR_S_SG_Sig_Grp_0x112(P2CONST(SG_Sig_Grp_0x112, AUTOMATIC, RTE_APPCTRL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppCtrl_SG_Sig_Grp_0x113_SR_S_SG_Sig_Grp_0x113(P2CONST(SG_Sig_Grp_0x113, AUTOMATIC, RTE_APPCTRL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppCtrl_SG_Sig_Grp_0x114_SR_S_SG_Sig_Grp_0x114(P2CONST(SG_Sig_Grp_0x114, AUTOMATIC, RTE_APPCTRL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400 Rte_Read_AppCtrl_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400
#  define Rte_Read_SG_Sig_Grp_0x401_SR_R_SG_Sig_Grp_0x401 Rte_Read_AppCtrl_SG_Sig_Grp_0x401_SR_R_SG_Sig_Grp_0x401
#  define Rte_Read_SG_Sig_Grp_0x402_SR_R_SG_Sig_Grp_0x402 Rte_Read_AppCtrl_SG_Sig_Grp_0x402_SR_R_SG_Sig_Grp_0x402
#  define Rte_Read_SG_Sig_Grp_0x403_SR_R_SG_Sig_Grp_0x403 Rte_Read_AppCtrl_SG_Sig_Grp_0x403_SR_R_SG_Sig_Grp_0x403


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SG_Sig_Grp_0x112_SR_S_SG_Sig_Grp_0x112 Rte_Write_AppCtrl_SG_Sig_Grp_0x112_SR_S_SG_Sig_Grp_0x112
#  define Rte_Write_SG_Sig_Grp_0x113_SR_S_SG_Sig_Grp_0x113 Rte_Write_AppCtrl_SG_Sig_Grp_0x113_SR_S_SG_Sig_Grp_0x113
#  define Rte_Write_SG_Sig_Grp_0x114_SR_S_SG_Sig_Grp_0x114 Rte_Write_AppCtrl_SG_Sig_Grp_0x114_SR_S_SG_Sig_Grp_0x114
#  define Rte_Write_Sig_0x114_Used_SR_S_Sig_0x114_Used_6 Rte_Write_AppCtrl_Sig_0x114_Used_SR_S_Sig_0x114_Used_6
#  define Rte_Write_AppCtrl_Sig_0x114_Used_SR_S_Sig_0x114_Used_6(data) (Rte_AppCtrl_Sig_0x114_Used_SR_S_Sig_0x114_Used_6 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Trigger_Msg_State_SR_S_Trigger_Msg_State Rte_Write_AppCtrl_Trigger_Msg_State_SR_S_Trigger_Msg_State
#  define Rte_Write_AppCtrl_Trigger_Msg_State_SR_S_Trigger_Msg_State(data) (Rte_AppCtrl_Trigger_Msg_State_SR_S_Trigger_Msg_State = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_KL15_IoHwAbOp_KL15_Read IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read


# endif /* !defined(RTE_CORE) */


# define AppCtrl_START_SEC_CODE
# include "AppCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AppCtrl_Init AppCtrl_Init
#  define RTE_RUNNABLE_AppCtrl_MainFunction AppCtrl_MainFunction
# endif

FUNC(void, AppCtrl_CODE) AppCtrl_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, AppCtrl_CODE) AppCtrl_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define AppCtrl_STOP_SEC_CODE
# include "AppCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IoHwAbCSIf_KL15_IoHwAbApplicationError (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_APPCTRL_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
