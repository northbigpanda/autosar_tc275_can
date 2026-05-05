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
 *             File:  AppLedCtrl.c
 *           Config:  E:/Embedded_Software_Develop/Project/Tc275_MultiCore_Proj/Code_Edit/XB_Tc275_Mulcore/Proj_Config/Bsw_Config/Cfg/TC27x.dpa
 *        SW-C Type:  AppLedCtrl
 *  Generation Time:  2024-02-05 11:23:32
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  C-Code implementation template for SW-C <AppLedCtrl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_AppLedCtrl.h"


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
 * CrcSig_Pack_3: Integer in interval [0...255]
 * CrcSig_Pack_4: Integer in interval [0...4294967295]
 * CrcSig_Pack_5: Integer in interval [0...4294967295]
 * Led1_Control_1: Boolean
 * Led1_State: Boolean
 * Led2_Control_1: Boolean
 * Led2_State: Boolean
 * Led3_Control_1: Boolean
 * Led3_State: Boolean
 * Led4_Control_1: Boolean
 * Led4_State: Boolean
 * SupB_Checksum_0x400_1: Integer in interval [0...255]
 * SupB_Counter_0x400_1: Integer in interval [0...255]
 *
 * Record Types:
 * =============
 * SG_Sig_Grp_0x110: Record with elements
 *   Led1_State of type Led1_State
 *   Led2_State of type Led2_State
 *   Led3_State of type Led3_State
 *   Led4_State of type Led4_State
 * SG_Sig_Grp_0x400: Record with elements
 *   CrcSig_Pack_0 of type CrcSig_Pack_3
 *   CrcSig_Pack_1 of type CrcSig_Pack_4
 *   CrcSig_Pack_2 of type CrcSig_Pack_5
 *   Led1_Control of type Led1_Control_1
 *   Led2_Control of type Led2_Control_1
 *   Led3_Control of type Led3_Control_1
 *   Led4_Control of type Led4_Control_1
 *   SupB_Checksum_0x400 of type SupB_Checksum_0x400_1
 *   SupB_Counter_0x400 of type SupB_Counter_0x400_1
 *
 *********************************************************************************************************************/


#define AppLedCtrl_START_SEC_CODE
#include "AppLedCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AppLedCtrl_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AppLedCtrl_Init_doc
 *********************************************************************************************************************/
void Set_LED_State(SG_Sig_Grp_0x400 SG_Sig_Grp_0x400_Val);
void Get_LED_State(SG_Sig_Grp_0x110 * SG_Sig_Grp_0x110_Set);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AppLedCtrl_CODE) AppLedCtrl_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AppLedCtrl_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AppLedCtrl_MainFunction
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
 *   Std_ReturnType Rte_Read_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400(SG_Sig_Grp_0x400 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110(const SG_Sig_Grp_0x110 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AppLedCtrl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AppLedCtrl_CODE) AppLedCtrl_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AppLedCtrl_MainFunction
 *********************************************************************************************************************/
  SG_Sig_Grp_0x110 SG_Sig_Grp_0x110_LedCtrl = {0};
  SG_Sig_Grp_0x400 SG_Sig_Grp_0x400_LedCtrl = {0};

	Rte_Read_AppLedCtrl_SG_Sig_Grp_0x400_SR_R_SG_Sig_Grp_0x400(&SG_Sig_Grp_0x400_LedCtrl);

  Set_LED_State(SG_Sig_Grp_0x400_LedCtrl);
  Get_LED_State(&SG_Sig_Grp_0x110_LedCtrl);

  Rte_Write_AppLedCtrl_SG_Sig_Grp_0x110_SR_S_SG_Sig_Grp_0x110(&SG_Sig_Grp_0x110_LedCtrl);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

void Set_LED_State(SG_Sig_Grp_0x400 SG_Sig_Grp_0x400_Val)
{
  if(SG_Sig_Grp_0x400_Val.Led1_Control == 1)
  {
    IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write(STD_HIGH);
  }
  else
  {
    IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write(STD_LOW);
  }

  if(SG_Sig_Grp_0x400_Val.Led2_Control == 1)
  {
    IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write(STD_HIGH);
  }
  else
  {
    IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write(STD_LOW);
  }

  if(SG_Sig_Grp_0x400_Val.Led3_Control == 1)
  {
    IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write(STD_HIGH);
  }
  else
  {
    IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write(STD_LOW);
  }

  if(SG_Sig_Grp_0x400_Val.Led4_Control == 1)
  {
    IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write(STD_HIGH);
  }
  else
  {
    IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write(STD_LOW);
  }
}

void Get_LED_State(SG_Sig_Grp_0x110 * SG_Sig_Grp_0x110_Set)
{
  IOHWAB_BOOL Dio_Val;
  IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read(&Dio_Val);
  if(Dio_Val == STD_HIGH)
  {
    SG_Sig_Grp_0x110_Set->Led1_State = 1;
  }
  else
  {
    SG_Sig_Grp_0x110_Set->Led1_State = 0;
  }
	
  IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read(&Dio_Val);
  if(Dio_Val == STD_HIGH)
  {
    SG_Sig_Grp_0x110_Set->Led2_State = 1;
  }
  else
  {
    SG_Sig_Grp_0x110_Set->Led2_State = 0;
  }

  IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read(&Dio_Val);
  if(Dio_Val == STD_HIGH)
  {
    SG_Sig_Grp_0x110_Set->Led3_State = 1;
  }
  else
  {
    SG_Sig_Grp_0x110_Set->Led3_State = 0;
  }

  IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read(&Dio_Val);
  if(Dio_Val == STD_HIGH)
  {
    SG_Sig_Grp_0x110_Set->Led4_State = 1;
  }
  else
  {
    SG_Sig_Grp_0x110_Set->Led4_State = 0;
  }
}


#define AppLedCtrl_STOP_SEC_CODE
#include "AppLedCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
