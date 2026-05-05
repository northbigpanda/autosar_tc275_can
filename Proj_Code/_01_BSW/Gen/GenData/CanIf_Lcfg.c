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
 *            Module: CanIf
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2024-01-29 21:13:43
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#define CANIF_LCFG_SOURCE

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanNm Header Files  */ 
#include "CanNm_Cfg.h"
#include "CanNm_Cbk.h"
 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE

#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/




 /** 
  \brief  Wake-up validation function.
*/

FUNC(void, CANIF_APPL_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType CanWakeupEvents);

#define CANIF_STOP_SEC_APPL_CODE

#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MappedTxBuffersConfigEndIdx                                                                           MappedTxBuffersConfigStartIdx                                                                                 Referable Keys */
  { /*     0 */                          1u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,                            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CtrlStatesIdx                                                                           PduIdFirst                           PduIdLast                           TxBufferCfgIdx                                                                              TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,         0u  /* Unused, TxPduId 0 */,        0u  /* Unused, TxPduId 7 */,                                     0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034 */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx] */
  { /*     1 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,         1u  /* RxPduId */          ,        6u  /* RxPduId  */         , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_b9b38c08_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MailBoxConfigIdx                                                                      Referable Keys */
  { /*     0 */               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                                 Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanNm_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanNm_RxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanTp_RxIndication] */
  { /*     3 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ }   /* [PduR_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  IsCanNmRxPdu              TRUE: CAN-Nm Rx-PDU (for Wakeup validation), FALSE: No CAN-Nm Rx-PDU
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxPduCanId                                                                     RxPduMask                                                     UpperPduId                                       IsCanNmRxPdu  RxIndicationFctListIdx                                RxPduDlc                                    Comment                                                                      Referable Keys */
  { /*     0 */    0x0600u  /* Lower CanId of range: XB_SUP_A_bafba356_Rx, 2.0- or FD-PDU */ ,   0x66FFu  /* Upper CanId of range: XB_SUP_A_bafba356_Rx */ , CanNmConf_CanNmRxPdu_DBCNetWork_CAN_9b3bc41d_Rx, TRUE        ,                     1u  /* CanNm_RxIndication */    ,       8u  /* DLC-Check is enabled */ },  /* [PDU: XB_SUP_A_bafba356_Rx, Lower CanId of range: 0x600]         */  /* [CanIfConf_CanIfRxPduCfg_XB_SUP_A_bafba356_Rx] */
  { /*     1 */    0x07DFu  /* Meg_FunDiag_Tp_oDBCNetWork_c3b25a60_Rx, 2.0- or FD-PDU */     ,   0x07FFu  /* Meg_FunDiag_Tp_oDBCNetWork_c3b25a60_Rx */     , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_e39092f8     , FALSE       ,                     2u  /* CanTp_RxIndication */    ,       8u  /* DLC-Check is enabled */ },  /* [PDU: Meg_FunDiag_Tp_oDBCNetWork_c3b25a60_Rx, CanId: 0x7df]      */  /* [CanIfConf_CanIfRxPduCfg_Meg_FunDiag_Tp_oDBCNetWork_c3b25a60_Rx] */
  { /*     2 */    0x0701u  /* Meg_PhyDiag_Tp_oDBCNetWork_a8746177_Rx, 2.0- or FD-PDU */     ,   0x07FFu  /* Meg_PhyDiag_Tp_oDBCNetWork_a8746177_Rx */     , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_eb22513d , FALSE       ,                     2u  /* CanTp_RxIndication */    ,       8u  /* DLC-Check is enabled */ },  /* [PDU: Meg_PhyDiag_Tp_oDBCNetWork_a8746177_Rx, CanId: 0x701]      */  /* [CanIfConf_CanIfRxPduCfg_Meg_PhyDiag_Tp_oDBCNetWork_a8746177_Rx] */
  { /*     3 */    0x0403u  /* SupC_Function_2_oDBCNetWork_e1b16d9f_Rx, 2.0- or FD-PDU */    ,   0x07FFu  /* SupC_Function_2_oDBCNetWork_e1b16d9f_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_755dbb0e        , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: SupC_Function_2_oDBCNetWork_e1b16d9f_Rx, CanId: 0x403]     */  /* [CanIfConf_CanIfRxPduCfg_SupC_Function_2_oDBCNetWork_e1b16d9f_Rx] */
  { /*     4 */    0x0402u  /* SupC_Function_1_oDBCNetWork_51474a89_Rx, 2.0- or FD-PDU */    ,   0x07FFu  /* SupC_Function_1_oDBCNetWork_51474a89_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_10b1802d        , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: SupC_Function_1_oDBCNetWork_51474a89_Rx, CanId: 0x402]     */  /* [CanIfConf_CanIfRxPduCfg_SupC_Function_1_oDBCNetWork_51474a89_Rx] */
  { /*     5 */    0x0401u  /* SupB_Button_Control_oDBCNetWork_b59ad01b_Rx, 2.0- or FD-PDU */,   0x07FFu  /* SupB_Button_Control_oDBCNetWork_b59ad01b_Rx */, PduRConf_PduRSrcPdu_PduRSrcPdu_f8af96ce        , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: SupB_Button_Control_oDBCNetWork_b59ad01b_Rx, CanId: 0x401] */  /* [CanIfConf_CanIfRxPduCfg_SupB_Button_Control_oDBCNetWork_b59ad01b_Rx] */
  { /*     6 */    0x0400u  /* SupB_Led_Control_oDBCNetWork_aacf6ceb_Rx, 2.0- or FD-PDU */   ,   0x07FFu  /* SupB_Led_Control_oDBCNetWork_aacf6ceb_Rx */   , PduRConf_PduRSrcPdu_PduRSrcPdu_495de942        , FALSE       ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */ }   /* [PDU: SupB_Led_Control_oDBCNetWork_aacf6ceb_Rx, CanId: 0x400]    */  /* [CanIfConf_CanIfRxPduCfg_SupB_Led_Control_oDBCNetWork_aacf6ceb_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TrcvModeIndicationFctType, CANIF_CONST) CanIf_TrcvModeIndicationFctPtr = CanSM_TransceiverModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvToCtrlMap
**********************************************************************************************************************/
/** 
  \var    CanIf_TrcvToCtrlMap
  \brief  Indirection table: logical transceiver index to CAN controller index.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TrcvToCtrlMapType, CANIF_CONST) CanIf_TrcvToCtrlMap[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrcvToCtrlMap                                          */
  /*     0 */             0u  /* CAN controller handle ID (upper) */
};
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxBufferPrioByCanIdBaseIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                            Referable Keys */
  { /*     0 */                         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034 */,                                             8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034 */,                                             8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034 */,                                               0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034 */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduConfigIdx                                                                                        Referable Keys */
  { /*     0 */             0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Meg_ResDiag_Tp_oDBCNetWork_d97dd71a_Tx */    },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
  { /*     1 */             1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Meg_NmTx_oDBCNetWork_c0e25960_Tx */          },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
  { /*     2 */             2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_2_oDBCNetWork_c7f1c344_Tx */   },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
  { /*     3 */             3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_1_oDBCNetWork_7707e452_Tx */   },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
  { /*     4 */             4u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Angle_oDBCNetWork_8a58a84d_Tx */        },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
  { /*     5 */             5u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_PowerMode_oDBCNetWork_d8135f5e_Tx */    },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
  { /*     6 */             6u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Button_State_oDBCNetWork_cea719eb_Tx */ },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
  { /*     7 */             7u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Led_State_oDBCNetWork_f5d8795b_Tx */    }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanNm_TxConfirmation                  ,  /* [CanNm_TxConfirmation] */
  /*     2 */ CanTp_TxConfirmation                  ,  /* [CanTp_TxConfirmation] */
  /*     3 */ PduR_CanIfTxConfirmation                 /* [PduR_CanIfTxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CanId    UpperLayerTxPduId                                               IsTxPduTruncation  CtrlStatesIdx                                                                           MailBoxConfigIdx                                                                TxConfirmationFctListIdx                                  TxPduLength        Comment                                                      Referable Keys */
  { /*     0 */ 0x0751u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_eb22513d                    , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: Meg_ResDiag_Tp_oDBCNetWork_d97dd71a_Tx]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meg_ResDiag_Tp_oDBCNetWork_d97dd71a_Tx] */
  { /*     1 */ 0x0601u, CanNmConf_CanNmTxPdu_Meg_NmTx_oDBCNetWork_5d9e34f5_Tx         , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */,                       1u  /* CanNm_TxConfirmation */    ,          8u },  /* [PDU: Meg_NmTx_oDBCNetWork_c0e25960_Tx]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meg_NmTx_oDBCNetWork_c0e25960_Tx] */
  { /*     2 */ 0x0115u, PduRConf_PduRDestPdu_SupA_Function_2_oDBCNetWork_4ba02fa7_Tx  , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: SupA_Function_2_oDBCNetWork_c7f1c344_Tx]   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_2_oDBCNetWork_c7f1c344_Tx] */
  { /*     3 */ 0x0114u, PduRConf_PduRDestPdu_SupA_Function_1_oDBCNetWork_10b79eb2_Tx  , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: SupA_Function_1_oDBCNetWork_7707e452_Tx]   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_1_oDBCNetWork_7707e452_Tx] */
  { /*     4 */ 0x0113u, PduRConf_PduRDestPdu_SupA_Angle_oDBCNetWork_418b1596_Tx       , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: SupA_Angle_oDBCNetWork_8a58a84d_Tx]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Angle_oDBCNetWork_8a58a84d_Tx] */
  { /*     5 */ 0x0112u, PduRConf_PduRDestPdu_SupA_PowerMode_oDBCNetWork_910ccf57_Tx   , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: SupA_PowerMode_oDBCNetWork_d8135f5e_Tx]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_PowerMode_oDBCNetWork_d8135f5e_Tx] */
  { /*     6 */ 0x0111u, PduRConf_PduRDestPdu_SupA_Button_State_oDBCNetWork_eea6565b_Tx, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: SupA_Button_State_oDBCNetWork_cea719eb_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Button_State_oDBCNetWork_cea719eb_Tx] */
  { /*     7 */ 0x0110u, PduRConf_PduRDestPdu_SupA_Led_State_oDBCNetWork_e7f688d3_Tx   , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94 */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx */,                       3u  /* PduR_CanIfTxConfirmation */,          8u }   /* [PDU: SupA_Led_State_oDBCNetWork_f5d8795b_Tx]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Led_State_oDBCNetWork_f5d8795b_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element       Description
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxQueueIdx                                                                                        Comment                                                                                Referable Keys */
  { /*     0 */         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Meg_ResDiag_Tp_oDBCNetWork_d97dd71a_Tx */    },  /* [Meg_ResDiag_Tp_oDBCNetWork_d97dd71a_Tx, BasicCAN TxPdu with Tx-buffer]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meg_ResDiag_Tp_oDBCNetWork_d97dd71a_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
  { /*     1 */         1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Meg_NmTx_oDBCNetWork_c0e25960_Tx */          },  /* [Meg_NmTx_oDBCNetWork_c0e25960_Tx, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meg_NmTx_oDBCNetWork_c0e25960_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
  { /*     2 */         2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_2_oDBCNetWork_c7f1c344_Tx */   },  /* [SupA_Function_2_oDBCNetWork_c7f1c344_Tx, BasicCAN TxPdu with Tx-buffer]   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_2_oDBCNetWork_c7f1c344_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
  { /*     3 */         3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_1_oDBCNetWork_7707e452_Tx */   },  /* [SupA_Function_1_oDBCNetWork_7707e452_Tx, BasicCAN TxPdu with Tx-buffer]   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_1_oDBCNetWork_7707e452_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
  { /*     4 */         4u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Angle_oDBCNetWork_8a58a84d_Tx */        },  /* [SupA_Angle_oDBCNetWork_8a58a84d_Tx, BasicCAN TxPdu with Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Angle_oDBCNetWork_8a58a84d_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
  { /*     5 */         5u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_PowerMode_oDBCNetWork_d8135f5e_Tx */    },  /* [SupA_PowerMode_oDBCNetWork_d8135f5e_Tx, BasicCAN TxPdu with Tx-buffer]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_PowerMode_oDBCNetWork_d8135f5e_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
  { /*     6 */         6u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Button_State_oDBCNetWork_cea719eb_Tx */ },  /* [SupA_Button_State_oDBCNetWork_cea719eb_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Button_State_oDBCNetWork_cea719eb_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
  { /*     7 */         7u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SupA_Led_State_oDBCNetWork_f5d8795b_Tx */    }   /* [SupA_Led_State_oDBCNetWork_f5d8795b_Tx, BasicCAN TxPdu with Tx-buffer]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Led_State_oDBCNetWork_f5d8795b_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_WakeUpConfig
  \brief  Wake-up source configuration
  \details
  Element                Description
  Controller             CAN controller handle ID
  WakeUpSource           Wake-up source identifier
  WakeUpTargetAddress    Logical handle ID of target (CAN controller / transceiver)
  WakeUpTargetModule     Target for wake-up source: CAN controller / transceiver
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_WakeUpConfigType, CANIF_CONST) CanIf_WakeUpConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Controller  WakeUpSource  WakeUpTargetAddress  WakeUpTargetModule              Comment */
  { /*     0 */         0u,          32u,                  0u, CANIF_WAKEUPREQUEST_TRCV }   /* [Only CanTrcvWakeupSource ] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpValidationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_WakeUpValidationFctType, CANIF_CONST) CanIf_WakeUpValidationFctPtr = EcuM_ValidateWakeupEvent;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element                  Description
  CtrlMode                 Controller mode.
  PduMode                  PDU mode state.
  WakeUpValidationState    Wake-up validation state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_DBCNetWork_78f82e94] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_50204034] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meg_ResDiag_Tp_oDBCNetWork_d97dd71a_Tx] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meg_NmTx_oDBCNetWork_c0e25960_Tx] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_2_oDBCNetWork_c7f1c344_Tx] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Function_1_oDBCNetWork_7707e452_Tx] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Angle_oDBCNetWork_8a58a84d_Tx] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_PowerMode_oDBCNetWork_d8135f5e_Tx] */
  /*     6 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Button_State_oDBCNetWork_cea719eb_Tx] */
  /*     7 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SupA_Led_State_oDBCNetWork_f5d8795b_Tx] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



