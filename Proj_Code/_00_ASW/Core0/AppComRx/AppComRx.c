/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  AppComRx.c
 *           Config:  E:/Embedded_Software_Develop/Project/Tc275_MultiCore_Proj/Code_Edit/XB_Tc275_Mulcore/_01_BSW/Cfg/TC27x.dpa
 *        SW-C Type:  AppComRx
 *  Generation Time:  2024-01-27 16:38:52
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  C-Code implementation template for SW-C <AppComRx>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_AppComRx.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Sig_Test04_10: Integer in interval [0...255]
 * Sig_Test04_11: Integer in interval [0...255]
 * Sig_Test04_12: Integer in interval [0...255]
 * Sig_Test04_8: Integer in interval [0...255]
 * Sig_Test04_9: Integer in interval [0...255]
 * Sig_Test10_10: Integer in interval [0...255]
 * Sig_Test10_11: Integer in interval [0...255]
 * Sig_Test10_12: Integer in interval [0...255]
 * Sig_Test10_8: Integer in interval [0...255]
 * Sig_Test10_9: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * Sig_Test04_1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF0x12 (0U)
 *   Cx1_ON (1U)
 *   Cx2_Reserve (2U)
 * Sig_Test04_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF0x12 (0U)
 *   Cx1_ON (1U)
 *   Cx2_Reserve (2U)
 * Sig_Test10_1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 *   Cx2_Reserve (2U)
 * Sig_Test10_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF0x12 (0U)
 *   Cx1_ON (1U)
 *   Cx2_Reserve (2U)
 *
 * Record Types:
 * =============
 * SG_Sig_Grp_0x126: Record with elements
 *   Sig_Test04_1 of type Sig_Test04_1
 *   Sig_Test04_2 of type Sig_Test04_2
 *   Sig_Test04_3 of type Sig_Test04_8
 *   Sig_Test04_4 of type Sig_Test04_9
 *   Sig_Test04_5 of type Sig_Test04_10
 *   Sig_Test04_6 of type Sig_Test04_11
 *   Sig_Test04_7 of type Sig_Test04_12
 * SG_Sig_Grp_0x128: Record with elements
 *   Sig_Test10_1 of type Sig_Test10_1
 *   Sig_Test10_2 of type Sig_Test10_2
 *   Sig_Test10_3 of type Sig_Test10_8
 *   Sig_Test10_4 of type Sig_Test10_9
 *   Sig_Test10_5 of type Sig_Test10_10
 *   Sig_Test10_6 of type Sig_Test10_11
 *   Sig_Test10_7 of type Sig_Test10_12
 *
 *********************************************************************************************************************/


#define AppComRx_START_SEC_CODE
#include "AppComRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AppComRx_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AppComRx_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AppComRx_CODE) AppComRx_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AppComRx_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AppComRx_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_Sig_Grp_0x126_SG_Sig_Grp_0x126(SG_Sig_Grp_0x126 *data)
 *   Std_ReturnType Rte_Read_SG_Sig_Grp_0x128_SG_Sig_Grp_0x128(SG_Sig_Grp_0x128 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SG_Sig_Grp_0x126_AppSR_S_SG_Sig_Grp_0x126(const SG_Sig_Grp_0x126 *data)
 *   Std_ReturnType Rte_Write_SG_Sig_Grp_0x128_AppSR_S_SG_Sig_Grp_0x128(const SG_Sig_Grp_0x128 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AppComRx_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AppComRx_CODE) AppComRx_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AppComRx_MainFunction
 *********************************************************************************************************************/
  SG_Sig_Grp_0x400 SG_Sig_Grp_0x400_Read;
  SG_Sig_Grp_0x400 SG_Sig_Grp_0x401_Read;
  SG_Sig_Grp_0x400 SG_Sig_Grp_0x402_Read;
  SG_Sig_Grp_0x400 SG_Sig_Grp_0x403_Read;

  Rte_Read_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400(&SG_Sig_Grp_0x400_Read);
  Rte_Read_SG_Sig_Grp_0x401_SG_Sig_Grp_0x401(&SG_Sig_Grp_0x401_Read);
  Rte_Read_SG_Sig_Grp_0x402_SG_Sig_Grp_0x402(&SG_Sig_Grp_0x402_Read);
  Rte_Read_SG_Sig_Grp_0x403_SG_Sig_Grp_0x403(&SG_Sig_Grp_0x403_Read);

  Rte_Write_SG_Sig_Grp_0x400_SR_S_SG_Sig_Grp_0x400(&SG_Sig_Grp_0x400_Read);
  Rte_Write_SG_Sig_Grp_0x401_SR_S_SG_Sig_Grp_0x401(&SG_Sig_Grp_0x401_Read);
  Rte_Write_SG_Sig_Grp_0x402_SR_S_SG_Sig_Grp_0x402(&SG_Sig_Grp_0x402_Read);
  Rte_Write_SG_Sig_Grp_0x403_SR_S_SG_Sig_Grp_0x403(&SG_Sig_Grp_0x403_Read);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AppComRx_STOP_SEC_CODE
#include "AppComRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
