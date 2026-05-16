/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Cdd
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Cdd_Cbk.h
 *   Generation Time: 2026-05-16 22:28:40
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/



#if !defined (CDD_CBK_H)
# define CDD_CBK_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"



/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CDD_USE_DUMMY_STATEMENT
#define CDD_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CDD_DUMMY_STATEMENT
#define CDD_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CDD_DUMMY_STATEMENT_CONST
#define CDD_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CDD_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CDD_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CDD_ATOMIC_VARIABLE_ACCESS
#define CDD_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CDD_PROCESSOR_TC27X
#define CDD_PROCESSOR_TC27X
#endif
#ifndef CDD_COMP_TASKING
#define CDD_COMP_TASKING
#endif
#ifndef CDD_GEN_GENERATOR_MSR
#define CDD_GEN_GENERATOR_MSR
#endif
#ifndef CDD_CPUTYPE_BITORDER_LSB2MSB
#define CDD_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CDD_CONFIGURATION_VARIANT_PRECOMPILE
#define CDD_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CDD_CONFIGURATION_VARIANT_LINKTIME
#define CDD_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CDD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CDD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CDD_CONFIGURATION_VARIANT
#define CDD_CONFIGURATION_VARIANT CDD_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CDD_POSTBUILD_VARIANT_SUPPORT
#define CDD_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CDD_COMIF  STD_ON
#define CDD_COMIF_RX  STD_ON
#define CDD_COMIF_TX  STD_ON
#define CDD_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_PDUR_UL_COMIF  STD_OFF
#define CDD_PDUR_UL_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_PDUR_UL_COMTP  STD_OFF

#define CDD_PDUR_LL_COMIF  STD_OFF
#define CDD_PDUR_LL_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_PDUR_LL_COMTP  STD_OFF

#define CDD_SOADUL_COMIF_RX  STD_OFF
#define CDD_SOADUL_COMIF_TRIGGERTRANSMIT  STD_OFF
#define CDD_SOADUL_COMIF_TXCONFIRMATION   STD_OFF

#define CDD_SOADUL_COMTP_RX  STD_OFF
#define CDD_SOADUL_COMTP_TX  STD_OFF





/**
 * \defgroup CddHandleIdsComIfUpperLayerRx Handle IDs of handle space ComIfUpperLayerRx.
 * \brief CddComIfUpperLayerContribution Rx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CddConf_CddComIfUpperLayerRxPdu_CddComIfUpperLayerRxPdu       0
/**\} */

/**
 * \defgroup CddHandleIdsComIfUpperLayerTx Handle IDs of handle space ComIfUpperLayerTx.
 * \brief CddComIfUpperLayerContribution Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CddConf_CddComIfUpperLayerTxPdu_CddComIfUpperLayerTxPdu       0
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# define CDD_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */
/*lint -restore */


/*! \defgroup ProvidedCddCddCommunicationInterface Provided Cdd interface to a communication hardware abstraction layer
    \brief    These services have to be provided by the Cdd if a communication hardware abstraction layer is used as lower layer. */
/*\{*/

#if (CDD_COMIF_RX == STD_ON)
/**********************************************************************************************************************
  Xwxz_Cdd_Can_RxConfirmation
**********************************************************************************************************************/
/*! \brief         The function is called to indicate the complete reception of a RX I-PDU.
    \param[in]     RxPduId      id of the CddComIfUpperLayerRxPdu.
    \param[in]     PduInfoPtr   Payload information of the received I-PDU (pointer to data and data length).
    \return        none
    \pre           The Cdd is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Xwxz_Cdd_Can_RxConfirmation call for the same RxPduId.
    \note          The function is called by a communication hardware abstraction layer .
**********************************************************************************************************************/
FUNC(void, CDD_CODE) Xwxz_Cdd_Can_RxConfirmation(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CDD_APPL_DATA) PduInfoPtr);
#endif

#if (CDD_COMIF_TX == STD_ON)
/**********************************************************************************************************************
  Xwxz_Cdd_Can_TxConfirmation
**********************************************************************************************************************/
/*! \brief         The function is called to confirm the transmission of an I-PDU.
    \param[in]     TxPduId      id of the CddComIfUpperLayerTxPdu.
    \return        none
    \pre           The Cdd is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Xwxz_Cdd_Can_TxConfirmation call for the same TxPduId.
    \note          The function is called by a communication hardware abstraction layer .
**********************************************************************************************************************/
FUNC(void, CDD_CODE) Xwxz_Cdd_Can_TxConfirmation(PduIdType TxPduId);
#endif

#if (CDD_COMIF_TRIGGERTRANSMIT == STD_ON)
/* there is no TriggerTransmit function configured in the communication hardware abstraction layer  */
#endif

/*\}*/





# define CDD_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */
/*lint -restore */

#endif  /* CDD_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Cdd_Cbk.h
**********************************************************************************************************************/


