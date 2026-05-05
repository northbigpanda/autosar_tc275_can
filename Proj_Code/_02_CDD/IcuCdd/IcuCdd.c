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
 *             File:  IcuCdd.c
 *           Config:  E:/Embedded_Software_Develop/Project/Tc275_MultiCore_Proj/Code_Edit/XB_Tc275_Mulcore/Proj_Config/Bsw_Config/Cfg/TC27x.dpa
 *        SW-C Type:  IcuCdd
 *  Generation Time:  2024-02-05 18:00:38
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  C-Code implementation template for SW-C <IcuCdd>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * IOHWAB_BOOL
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 *********************************************************************************************************************/

#include "Rte_IcuCdd.h"
#include "Icu_17_GtmCcu6.h"
#include "Dio.h"
#include "Dio_Cfg.h"
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
 * IOHWAB_BOOL: Boolean
 * boolean: Boolean (standard type)
 *
 *********************************************************************************************************************/

#include "IcuCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IcuCdd_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IcuCdd_Init_doc
 *********************************************************************************************************************/
uint8 Get_Button1_PushState(void);

static uint8 Debounce_Cnt = 5;
static boolean But_Push_Flag = 0;
static boolean Revert_flag = 0;

#define IcuCdd_START_SEC_CODE


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, IcuCdd_CODE) IcuCdd_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IcuCdd_Init
 *********************************************************************************************************************/
	Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_IcuChannel_0);
	Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_IcuChannel_0);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}



/**********************************************************************************************************************
 *
 * Runnable Entity Name: IcuCdd_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAbCS_Button1_IoHwAbOp_Button1_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAbCSIf_Button1_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IcuCdd_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, IcuCdd_CODE) IcuCdd_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IcuCdd_MainFunction
 *********************************************************************************************************************/

	Get_Button1_PushState();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
uint8 Get_Button1_PushState(void)
{
	boolean Butt_Push = 0;
	IOHWAB_BOOL Button1_PushState;

	IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read(&Button1_PushState);

	if(But_Push_Flag == 1)
	{
		Debounce_Cnt--;
		if(Debounce_Cnt == 0)
		{
			if(Button1_PushState == STD_LOW)
			{
				/* Valid push */
				//Revert_flag = (~Revert_flag);
				//Dio_WriteChannel(DioConf_DioChannel_LED1, Revert_flag);
				Butt_Push = 1;
			}
			else
			{
				/* Invalid push */
			}

			/* Start new push*/
			But_Push_Flag = 0;
			Debounce_Cnt = 5;

			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_IcuChannel_0);
			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_IcuChannel_0);

		}
		else
		{
			/* Wait for debounce */
		}
	}
	else
	{
		/* No push of button*/
	}

	return Butt_Push;
}

void CANRX_15_4_ICU_Notification(void)
{
	IOHWAB_BOOL Button1_PushState;

	IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read(&Button1_PushState);

	if(Button1_PushState == STD_LOW)
	{
		But_Push_Flag = 1;
		Icu_17_GtmCcu6_DisableEdgeDetection(IcuConf_IcuChannel_IcuChannel_0);
		Icu_17_GtmCcu6_DisableNotification(IcuConf_IcuChannel_IcuChannel_0);
	}
	else
	{

	}
}

#define IcuCdd_STOP_SEC_CODE
#include "IcuCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
