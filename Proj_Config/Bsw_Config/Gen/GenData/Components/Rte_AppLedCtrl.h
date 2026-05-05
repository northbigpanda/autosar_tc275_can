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
 *             File:  Rte_AppLedCtrl.h
 *           Config:  TC27x.dpa
 *      ECU-Project:  TC27x
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  Application header file for SW-C <AppLedCtrl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_APPLEDCTRL_H
# define RTE_APPLEDCTRL_H

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

# include "Rte_AppLedCtrl_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppLedCtrl_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400(P2VAR(SG_Sig_Grp_0x400, AUTOMATIC, RTE_APPLEDCTRL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110(P2CONST(SG_Sig_Grp_0x110, AUTOMATIC, RTE_APPLEDCTRL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400 Rte_Read_AppLedCtrl_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110 Rte_Write_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_KL15_IoHwAbOp_KL15_Read IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_LED1_IoHwAbOp_LED1_Read IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write(IOHWAB_BOOL IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_LED1_IoHwAbOp_LED1_Write IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_LED2_IoHwAbOp_LED2_Read IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write(IOHWAB_BOOL IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_LED2_IoHwAbOp_LED2_Write IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_LED3_IoHwAbOp_LED3_Read IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write(IOHWAB_BOOL IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_LED3_IoHwAbOp_LED3_Write IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_LED4_IoHwAbOp_LED4_Read IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write(IOHWAB_BOOL IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAbCS_LED4_IoHwAbOp_LED4_Write IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write


# endif /* !defined(RTE_CORE) */


# define AppLedCtrl_START_SEC_CODE
# include "AppLedCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AppLedCtrl_Init AppLedCtrl_Init
#  define RTE_RUNNABLE_AppLedCtrl_MainFunction AppLedCtrl_MainFunction
# endif

FUNC(void, AppLedCtrl_CODE) AppLedCtrl_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, AppLedCtrl_CODE) AppLedCtrl_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define AppLedCtrl_STOP_SEC_CODE
# include "AppLedCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IoHwAbCSIf_KL15_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_LED1_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_LED2_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_LED3_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_LED4_IoHwAbApplicationError (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_APPLEDCTRL_H */

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
