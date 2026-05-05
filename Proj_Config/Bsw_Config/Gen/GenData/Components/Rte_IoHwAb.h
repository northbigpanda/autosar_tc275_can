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
 *             File:  Rte_IoHwAb.h
 *           Config:  TC27x.dpa
 *      ECU-Project:  TC27x
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  Application header file for SW-C <IoHwAb>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_IOHWAB_H
# define RTE_IOHWAB_H

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

# include "Rte_IoHwAb_Type.h"
# include "Rte_DataHandleType.h"


# define IoHwAb_START_SEC_CODE
# include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read
#  define RTE_RUNNABLE_IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write
#  define RTE_RUNNABLE_IoHwAb_IoHwAbRunnable IoHwAb_IoHwAbRunnable
# endif

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write(IOHWAB_BOOL IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write(IOHWAB_BOOL IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write(IOHWAB_BOOL IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write(IOHWAB_BOOL IoHwAbOperationArgument); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, IoHwAb_CODE) IoHwAb_IoHwAbRunnable(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define IoHwAb_STOP_SEC_CODE
# include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IoHwAbCSIf_Button1_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_Button2_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_Button3_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_Button4_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_KL15_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_LED1_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_LED2_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_LED3_IoHwAbApplicationError (1U)

#  define RTE_E_IoHwAbCSIf_LED4_IoHwAbApplicationError (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_IOHWAB_H */

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
