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
 *             File:  IoHwAb.c
 *           Config:  E:/Embedded_Software_Develop/Project/Tc275_MultiCore_Proj/Code_Edit/XB_Tc275_Mulcore/Proj_Config/Bsw_Config/Cfg/TC27x.dpa
 *        SW-C Type:  IoHwAb
 *  Generation Time:  2024-02-05 15:42:29
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  CBD1600956
 *
 *      Description:  C-Code implementation template for SW-C <IoHwAb>
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
 *
 * Runnable Entities:
 * ==================
 * IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_Button1_Read' of the Client/Server Port Prototype 'IoHwAbCS_Button1'.
 *
 * IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_Button2_Read' of the Client/Server Port Prototype 'IoHwAbCS_Button2'.
 *
 * IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_Button3_Read' of the Client/Server Port Prototype 'IoHwAbCS_Button3'.
 *
 * IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_Button4_Read' of the Client/Server Port Prototype 'IoHwAbCS_Button4'.
 *
 * IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_KL15_Read' of the Client/Server Port Prototype 'IoHwAbCS_KL15'.
 *
 * IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Write
 *   Runnable Entity for calling the Operation 'IoHwAbOp_KL15_Write' of the Client/Server Port Prototype 'IoHwAbCS_KL15'.
 *
 * IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_LED1_Read' of the Client/Server Port Prototype 'IoHwAbCS_LED1'.
 *
 * IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write
 *   Runnable Entity for calling the Operation 'IoHwAbOp_LED1_Write' of the Client/Server Port Prototype 'IoHwAbCS_LED1'.
 *
 * IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_LED2_Read' of the Client/Server Port Prototype 'IoHwAbCS_LED2'.
 *
 * IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write
 *   Runnable Entity for calling the Operation 'IoHwAbOp_LED2_Write' of the Client/Server Port Prototype 'IoHwAbCS_LED2'.
 *
 * IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_LED3_Read' of the Client/Server Port Prototype 'IoHwAbCS_LED3'.
 *
 * IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write
 *   Runnable Entity for calling the Operation 'IoHwAbOp_LED3_Write' of the Client/Server Port Prototype 'IoHwAbCS_LED3'.
 *
 * IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read
 *   Runnable Entity for calling the Operation 'IoHwAbOp_LED4_Read' of the Client/Server Port Prototype 'IoHwAbCS_LED4'.
 *
 * IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write
 *   Runnable Entity for calling the Operation 'IoHwAbOp_LED4_Write' of the Client/Server Port Prototype 'IoHwAbCS_LED4'.
 *
 *********************************************************************************************************************/

#include "Rte_IoHwAb.h"
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


#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_Button1_Read> of PortPrototype <IoHwAbCS_Button1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_Button1_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Read (returns application error)
 *********************************************************************************************************************/
  if(Dio_ReadChannel(DioConf_DioChannel_Button1) == STD_HIGH)
  {
	  *IoHwAbOperationArgument = STD_HIGH;
  }
  else
  {
	  *IoHwAbOperationArgument = STD_LOW;
  }
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_Button2_Read> of PortPrototype <IoHwAbCS_Button2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_Button2_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Read (returns application error)
 *********************************************************************************************************************/
	if(Dio_ReadChannel(DioConf_DioChannel_Button2) == STD_HIGH)
	{
		*IoHwAbOperationArgument = STD_HIGH;
	}
	else
	{
		*IoHwAbOperationArgument = STD_LOW;
	}
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_Button3_Read> of PortPrototype <IoHwAbCS_Button3>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_Button3_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Read (returns application error)
 *********************************************************************************************************************/
	if(Dio_ReadChannel(DioConf_DioChannel_Button3) == STD_HIGH)
	{
		*IoHwAbOperationArgument = STD_HIGH;
	}
	else
	{
		*IoHwAbOperationArgument = STD_LOW;
	}
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_Button4_Read> of PortPrototype <IoHwAbCS_Button4>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_Button4_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Read (returns application error)
 *********************************************************************************************************************/
	if(Dio_ReadChannel(DioConf_DioChannel_Button4) == STD_HIGH)
	{
		*IoHwAbOperationArgument = STD_HIGH;
	}
	else
	{
		*IoHwAbOperationArgument = STD_LOW;
	}
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_KL15_Read> of PortPrototype <IoHwAbCS_KL15>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_KL15_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read (returns application error)
 *********************************************************************************************************************/
	if(Dio_ReadChannel(DioConf_DioChannel_KL15) == STD_HIGH)
	{
		*IoHwAbOperationArgument = STD_HIGH;
	}
	else
	{
		*IoHwAbOperationArgument = STD_LOW;
	}
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_LED1_Read> of PortPrototype <IoHwAbCS_LED1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_LED1_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Read (returns application error)
 *********************************************************************************************************************/
	if(Dio_ReadChannel(DioConf_DioChannel_LED1) == STD_HIGH)
	{
		*IoHwAbOperationArgument = STD_HIGH;
	}
	else
	{
		*IoHwAbOperationArgument = STD_LOW;
	}
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_LED1_Write> of PortPrototype <IoHwAbCS_LED1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write(IOHWAB_BOOL IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_LED1_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write(IOHWAB_BOOL IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED1_IoHwAbOp_LED1_Write (returns application error)
 *********************************************************************************************************************/
  Dio_WriteChannel(DioConf_DioChannel_LED1, IoHwAbOperationArgument);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_LED2_Read> of PortPrototype <IoHwAbCS_LED2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_LED2_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Read (returns application error)
 *********************************************************************************************************************/
	if(Dio_ReadChannel(DioConf_DioChannel_LED2) == STD_HIGH)
	{
		*IoHwAbOperationArgument = STD_HIGH;
	}
	else
	{
		*IoHwAbOperationArgument = STD_LOW;
	}
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_LED2_Write> of PortPrototype <IoHwAbCS_LED2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write(IOHWAB_BOOL IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_LED2_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write(IOHWAB_BOOL IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED2_IoHwAbOp_LED2_Write (returns application error)
 *********************************************************************************************************************/
  Dio_WriteChannel(DioConf_DioChannel_LED2, IoHwAbOperationArgument);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_LED3_Read> of PortPrototype <IoHwAbCS_LED3>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_LED3_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Read (returns application error)
 *********************************************************************************************************************/
	if(Dio_ReadChannel(DioConf_DioChannel_LED3) == STD_HIGH)
	{
		*IoHwAbOperationArgument = STD_HIGH;
	}
	else
	{
		*IoHwAbOperationArgument = STD_LOW;
	}
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_LED3_Write> of PortPrototype <IoHwAbCS_LED3>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write(IOHWAB_BOOL IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_LED3_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write(IOHWAB_BOOL IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED3_IoHwAbOp_LED3_Write (returns application error)
 *********************************************************************************************************************/
  Dio_WriteChannel(DioConf_DioChannel_LED3, IoHwAbOperationArgument);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_LED4_Read> of PortPrototype <IoHwAbCS_LED4>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read(IOHWAB_BOOL *IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_LED4_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Read (returns application error)
 *********************************************************************************************************************/
	if(Dio_ReadChannel(DioConf_DioChannel_LED4) == STD_HIGH)
	{
		*IoHwAbOperationArgument = STD_HIGH;
	}
	else
	{
		*IoHwAbOperationArgument = STD_LOW;
	}
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IoHwAbOp_LED4_Write> of PortPrototype <IoHwAbCS_LED4>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write(IOHWAB_BOOL IoHwAbOperationArgument)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAbCSIf_LED4_IoHwAbApplicationError
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write(IOHWAB_BOOL IoHwAbOperationArgument) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbCS_LED4_IoHwAbOp_LED4_Write (returns application error)
 *********************************************************************************************************************/
  Dio_WriteChannel(DioConf_DioChannel_LED4, IoHwAbOperationArgument);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_IoHwAbRunnable
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, IoHwAb_CODE) IoHwAb_IoHwAbRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_IoHwAbRunnable
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: runnable implementation:IoHwAb_MainFunction)  ****************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:IoHwAb_MainFunction_doc)  *****************************/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Write)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Write_doc)  **/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:IoHwAb_IoHwAbCS_Button1_IoHwAbOp_Button1_Write_doc)  **/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Write_doc)  **/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:IoHwAb_IoHwAbCS_Button3_IoHwAbOp_Button3_Write)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Write)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:IoHwAb_IoHwAbCS_Button4_IoHwAbOp_Button4_Write)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:IoHwAb_IoHwAbCS_Button2_IoHwAbOp_Button2_Write_doc)  **/


/***  End of saved code  ************************************************************************************/
#endif

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
