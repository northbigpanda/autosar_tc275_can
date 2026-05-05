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
 *             File:  Rte_AppComRx.h
 *           Config:  TC27x.dpa
 *      ECU-Project:  TC27x
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  Application header file for SW-C <AppComRx>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_APPCOMRX_H
# define RTE_APPCOMRX_H

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

# include "Rte_AppComRx_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400(P2VAR(SG_Sig_Grp_0x400, AUTOMATIC, RTE_APPCOMRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComRx_SG_Sig_Grp_0x401_SG_Sig_Grp_0x401(P2VAR(SG_Sig_Grp_0x401, AUTOMATIC, RTE_APPCOMRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComRx_SG_Sig_Grp_0x402_SG_Sig_Grp_0x402(P2VAR(SG_Sig_Grp_0x402, AUTOMATIC, RTE_APPCOMRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AppComRx_SG_Sig_Grp_0x403_SG_Sig_Grp_0x403(P2VAR(SG_Sig_Grp_0x403, AUTOMATIC, RTE_APPCOMRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400(P2CONST(SG_Sig_Grp_0x400, AUTOMATIC, RTE_APPCOMRX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401(P2CONST(SG_Sig_Grp_0x401, AUTOMATIC, RTE_APPCOMRX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComRx_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402(P2CONST(SG_Sig_Grp_0x402, AUTOMATIC, RTE_APPCOMRX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AppComRx_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403(P2CONST(SG_Sig_Grp_0x403, AUTOMATIC, RTE_APPCOMRX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 Rte_Read_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400
#  define Rte_Read_SG_Sig_Grp_0x401_SG_Sig_Grp_0x401 Rte_Read_AppComRx_SG_Sig_Grp_0x401_SG_Sig_Grp_0x401
#  define Rte_Read_SG_Sig_Grp_0x402_SG_Sig_Grp_0x402 Rte_Read_AppComRx_SG_Sig_Grp_0x402_SG_Sig_Grp_0x402
#  define Rte_Read_SG_Sig_Grp_0x403_SG_Sig_Grp_0x403 Rte_Read_AppComRx_SG_Sig_Grp_0x403_SG_Sig_Grp_0x403


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 Rte_IsUpdated_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400
#  define Rte_IsUpdated_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400 Rte_Write_AppComRx_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400
#  define Rte_Write_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401 Rte_Write_AppComRx_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401
#  define Rte_Write_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402 Rte_Write_AppComRx_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402
#  define Rte_Write_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403 Rte_Write_AppComRx_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403


# endif /* !defined(RTE_CORE) */


# define AppComRx_START_SEC_CODE
# include "AppComRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AppComRx_Init AppComRx_Init
#  define RTE_RUNNABLE_AppComRx_MainFunction AppComRx_MainFunction
# endif

FUNC(void, AppComRx_CODE) AppComRx_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, AppComRx_CODE) AppComRx_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define AppComRx_STOP_SEC_CODE
# include "AppComRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_APPCOMRX_H */

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
