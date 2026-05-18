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
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.c
 *   Generation Time: 2026-05-19 00:07:01
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#define PDUR_LCFG_SOURCE

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Fm.h"
#include "PduR_IFQ.h"
#include "PduR_Sm.h"
#include "PduR_RmIf.h"
#include "PduR_RmTp.h"
#include "PduR_RmTp_TxInst.h"
#include "SchM_PduR.h"
#if(PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/* Include headers with callbacks */
#include "PduR_CanIf.h"
#include "PduR_CanTp.h"
#include "PduR_Com.h"
#include "PduR_Dcm.h"


/**********************************************************************************************************************
 * LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* Exclusive Area Wrapper functions */
static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void);
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void);
  
/**********************************************************************************************************************
 * LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA
 *********************************************************************************************************************/
/* \trace SPEC-663, SPEC-661 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_ExclusiveAreaRom
**********************************************************************************************************************/
/** 
  \var    PduR_ExclusiveAreaRom
  \brief  PduR Exclusive Area Locks
  \details
  Element    Description
  Lock       Lock function
  Unlock     Unlock function
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_ExclusiveAreaRomType, PDUR_CONST) PduR_ExclusiveAreaRom[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Lock                                        Unlock                                           Referable Keys */
  { /*     0 */ PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0, PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0 }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRLock_PduRExclusiveArea] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_MmRom
**********************************************************************************************************************/
/** 
  \var    PduR_MmRom
  \brief  Module manager: Contains all function pointers of the bordering modules.
  \details
  Element                         Description
  DestApplicationManagerRomIdx    the index of the 1:1 relation pointing to PduR_DestApplicationManagerRom
  MaskedBits                      contains bitcoded the boolean data of PduR_LoIfOfMmRom, PduR_LoTpOfMmRom, PduR_RmGDestRomUsedOfMmRom, PduR_UpIfOfMmRom, PduR_UpTpOfMmRom
  RmGDestRomEndIdx                the end index of the 0:n relation pointing to PduR_RmGDestRom
  RmGDestRomStartIdx              the start index of the 0:n relation pointing to PduR_RmGDestRom
  UpTpCopyRxDataFctPtr            Transport protocol CopyRxData function pointers
  UpTpCopyTxDataFctPtr            Transport protocol CopyTxData function pointers
  UpIfRxIndicationFctPtr          Upper layer communication interface Rx indication function pointers.
  UpIfTxConfirmationFctPtr        Upper layer communication interface Tx confimation function pointers
  UpTpStartOfReceptionFctPtr      Transport protocol StartOfReception function pointers
  UpTpTpRxIndicationFctPtr        Transport protocol TpRxIndication function pointers
  UpTpTpTxConfirmationFctPtr      Transport protocol TpTxConfimation function pointers
  LoIfTransmitFctPtr              Lower layer If transmit function pointers
  LoTpTransmitFctPtr              Lower layer Tp transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DestApplicationManagerRomIdx  MaskedBits  RmGDestRomEndIdx  RmGDestRomStartIdx  UpTpCopyRxDataFctPtr  UpTpCopyTxDataFctPtr  UpIfRxIndicationFctPtr  UpIfTxConfirmationFctPtr  UpTpStartOfReceptionFctPtr  UpTpTpRxIndicationFctPtr  UpTpTpTxConfirmationFctPtr  LoIfTransmitFctPtr  LoTpTransmitFctPtr        Comment                        Referable Keys */
  { /*     0 */                           0u,      0x14u,               7u,                 0u, NULL_PTR            , NULL_PTR            , NULL_PTR              , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , CanIf_Transmit    , NULL_PTR           },  /* [BswModule: CanIf] */  /* [/ActiveEcuC/PduR/CanIf, /ActiveEcuC/PduR] */
  { /*     1 */                           0u,      0x0Cu,               8u,                 7u, NULL_PTR            , NULL_PTR            , NULL_PTR              , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , NULL_PTR          , CanTp_Transmit     },  /* [BswModule: CanTp] */  /* [/ActiveEcuC/PduR/CanTp, /ActiveEcuC/PduR] */
  { /*     2 */                           0u,      0x06u,              12u,                 8u, NULL_PTR            , NULL_PTR            , Com_RxIndication      , Com_TxConfirmation      , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , NULL_PTR          , NULL_PTR           },  /* [BswModule: Com]   */  /* [/ActiveEcuC/PduR/Com, /ActiveEcuC/PduR] */
  { /*     3 */                           0u,      0x05u,              14u,                12u, Dcm_CopyRxData      , Dcm_CopyTxData      , NULL_PTR              , NULL_PTR                , Dcm_StartOfReception      , Dcm_TpRxIndication      , Dcm_TpTxConfirmation      , NULL_PTR          , NULL_PTR           }   /* [BswModule: Dcm]   */  /* [/ActiveEcuC/PduR/Dcm, /ActiveEcuC/PduR] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRom
  \brief  PduR RoutiongPathManager destPdu Table
  \details
  Element          Description
  RmGDestRomIdx    the index of the 1:1 relation pointing to PduR_RmGDestRom
  RmSrcRomIdx      the index of the 1:1 relation pointing to PduR_RmSrcRom
  RoutingType      Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRom[14] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                            Referable Keys */
  { /*     0 */            0u,          1u,      PDUR_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PduRDestPdu]                                             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can1ToCan0_PduR/PduRSrcPdu, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can1ToCan0_PduR/PduRDestPdu] */
  { /*     1 */            4u,         11u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SupA_Function_1_oDBCNetWork_10b79eb2_Tx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Function_1_oDBCNetWork_312706bd_Tx/PduRSrcPdu_045a4163, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Function_1_oDBCNetWork_312706bd_Tx/SupA_Function_1_oDBCNetWork_10b79eb2_Tx] */
  { /*     2 */            1u,          0u,      PDUR_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PduRDestPdu_1]                                           */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can0ToCan1_PduR/PduRSrcPdu_1, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can0ToCan1_PduR/PduRDestPdu_1] */
  { /*     3 */           10u,          4u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SupC_Function_1_oDBCNetWork_44e7ee76_Rx_10b1802d_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupC_Function_1_oDBCNetWork_44e7ee76_Rx/PduRSrcPdu_10b1802d, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupC_Function_1_oDBCNetWork_44e7ee76_Rx/SupC_Function_1_oDBCNetWork_44e7ee76_Rx_10b1802d_Rx] */
  { /*     4 */           12u,          6u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Meg_FunDiag_oDBCNetWork_245e23dc_Rx_1af6dabd_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_FunDiag_oDBCNetWork_245e23dc_Rx/PduRSrcPdu_1af6dabd, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_FunDiag_oDBCNetWork_245e23dc_Rx/Meg_FunDiag_oDBCNetWork_245e23dc_Rx_1af6dabd_Rx] */
  { /*     5 */            9u,          3u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SupB_Led_Control_oDBCNetWork_496a3ac6_Rx_495de942_Rx]    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupB_Led_Control_oDBCNetWork_496a3ac6_Rx/PduRSrcPdu_495de942, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupB_Led_Control_oDBCNetWork_496a3ac6_Rx/SupB_Led_Control_oDBCNetWork_496a3ac6_Rx_495de942_Rx] */
  { /*     6 */           13u,          7u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Meg_PhyDiag_oDBCNetWork_e94a8f4d_Rx_49b2840e_Rx]         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_PhyDiag_oDBCNetWork_e94a8f4d_Rx/PduRSrcPdu_49b2840e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_PhyDiag_oDBCNetWork_e94a8f4d_Rx/Meg_PhyDiag_oDBCNetWork_e94a8f4d_Rx_49b2840e_Rx] */
  { /*     7 */           11u,          5u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SupC_Function_2_oDBCNetWork_1ff05f63_Rx_755dbb0e_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupC_Function_2_oDBCNetWork_1ff05f63_Rx/PduRSrcPdu_755dbb0e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupC_Function_2_oDBCNetWork_1ff05f63_Rx/SupC_Function_2_oDBCNetWork_1ff05f63_Rx_755dbb0e_Rx] */
  { /*     8 */            7u,          8u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Meg_ResDiag_oDBCNetWork_1336e721_Tx]                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_ResDiag_oDBCNetWork_5467f8e5_Tx/PduRSrcPdu_9c32056b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_ResDiag_oDBCNetWork_5467f8e5_Tx/Meg_ResDiag_oDBCNetWork_1336e721_Tx] */
  { /*     9 */            6u,         13u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SupA_PowerMode_oDBCNetWork_910ccf57_Tx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_PowerMode_oDBCNetWork_b77edafa_Tx/PduRSrcPdu_a13e3769, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_PowerMode_oDBCNetWork_b77edafa_Tx/SupA_PowerMode_oDBCNetWork_910ccf57_Tx] */
  { /*    10 */            2u,          9u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SupA_Angle_oDBCNetWork_418b1596_Tx]                      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Angle_oDBCNetWork_e5909e4f_Tx/PduRSrcPdu_c6b821a9, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Angle_oDBCNetWork_e5909e4f_Tx/SupA_Angle_oDBCNetWork_418b1596_Tx] */
  { /*    11 */            5u,         12u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SupA_Led_State_oDBCNetWork_e7f688d3_Tx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Led_State_oDBCNetWork_43576f7c_Tx/PduRSrcPdu_de6a18d2, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Led_State_oDBCNetWork_43576f7c_Tx/SupA_Led_State_oDBCNetWork_e7f688d3_Tx] */
  { /*    12 */            3u,         10u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SupA_Button_State_oDBCNetWork_eea6565b_Tx]               */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Button_State_oDBCNetWork_390399bb_Tx/PduRSrcPdu_ed18513b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Button_State_oDBCNetWork_390399bb_Tx/SupA_Button_State_oDBCNetWork_eea6565b_Tx] */
  { /*    13 */            8u,          2u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM }   /* [PduRDestPdu: SupB_Button_Control_oDBCNetWork_a24295f7_Rx_f8af96ce_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupB_Button_Control_oDBCNetWork_a24295f7_Rx/PduRSrcPdu_f8af96ce, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupB_Button_Control_oDBCNetWork_a24295f7_Rx/SupB_Button_Control_oDBCNetWork_a24295f7_Rx_f8af96ce_Rx] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRom
  \brief  PduR RoutiongPathManager global destPdu Table
  \details
  Element                  Description
  DestHnd                  handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  Direction                Direction of this Pdu: Rx or Tx
  MmRomIdx                 the index of the 1:1 relation pointing to PduR_MmRom
  PduRDestPduProcessing    Is Processing Type of destination PDU.
  RmDestRomIdx             the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRom[14] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DestHnd                                                                     Direction                      MmRomIdx  PduRDestPduProcessing                             RmDestRomIdx        Comment                                                                               Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_Rout_Can1ToCan0_100ms_oDBCNetWork_Can0_8073c8b9_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           0u },  /* [Globale PduRDestPdu: Rout_Can1ToCan0_100ms_oDBCNetWork_Can0_c34bc869_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Rout_Can1ToCan0_100ms_oDBCNetWork_Can0_c34bc869_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     1 */     CanIfConf_CanIfTxPduCfg_Route_Can0ToCan1_100ms_oDBCNetWork_bd7918cc_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           2u },  /* [Globale PduRDestPdu: Route_Can0ToCan1_100ms_oDBCNetWork_a9bdfb29_Tx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Route_Can0ToCan1_100ms_oDBCNetWork_a9bdfb29_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     2 */                 CanIfConf_CanIfTxPduCfg_SupA_Angle_oDBCNetWork_8a58a84d_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          10u },  /* [Globale PduRDestPdu: SupA_Angle_oDBCNetWork_418b1596_Tx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_Angle_oDBCNetWork_418b1596_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     3 */          CanIfConf_CanIfTxPduCfg_SupA_Button_State_oDBCNetWork_cea719eb_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          12u },  /* [Globale PduRDestPdu: SupA_Button_State_oDBCNetWork_eea6565b_Tx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_Button_State_oDBCNetWork_eea6565b_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     4 */            CanIfConf_CanIfTxPduCfg_SupA_Function_1_oDBCNetWork_7707e452_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           1u },  /* [Globale PduRDestPdu: SupA_Function_1_oDBCNetWork_10b79eb2_Tx]            */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_Function_1_oDBCNetWork_10b79eb2_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     5 */             CanIfConf_CanIfTxPduCfg_SupA_Led_State_oDBCNetWork_f5d8795b_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          11u },  /* [Globale PduRDestPdu: SupA_Led_State_oDBCNetWork_e7f688d3_Tx]             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_Led_State_oDBCNetWork_e7f688d3_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     6 */             CanIfConf_CanIfTxPduCfg_SupA_PowerMode_oDBCNetWork_d8135f5e_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           9u },  /* [Globale PduRDestPdu: SupA_PowerMode_oDBCNetWork_910ccf57_Tx]             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_PowerMode_oDBCNetWork_910ccf57_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     7 */                                 CanTpConf_CanTpTxNSdu_CanTpTxNSdu_a51614e7, PDUR_TX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           8u },  /* [Globale PduRDestPdu: Meg_ResDiag_oDBCNetWork_1336e721_Tx]                */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Meg_ResDiag_oDBCNetWork_1336e721_Tx, /ActiveEcuC/PduR/CanTp] */
  { /*     8 */                ComConf_ComIPdu_SupB_Button_Control_oDBCNetWork_0c40490d_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       2u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          13u },  /* [Globale PduRDestPdu: SupB_Button_Control_oDBCNetWork_0c40490d_Rx]        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupB_Button_Control_oDBCNetWork_0c40490d_Rx, /ActiveEcuC/PduR/Com] */
  { /*     9 */                   ComConf_ComIPdu_SupB_Led_Control_oDBCNetWork_eb16948d_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       2u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           5u },  /* [Globale PduRDestPdu: SupB_Led_Control_oDBCNetWork_eb16948d_Rx]           */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/PduR/Com] */
  { /*    10 */                    ComConf_ComIPdu_SupC_Function_1_oDBCNetWork_e81ccab2_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       2u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           3u },  /* [Globale PduRDestPdu: SupC_Function_1_oDBCNetWork_e81ccab2_Rx]            */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/PduR/Com] */
  { /*    11 */                    ComConf_ComIPdu_SupC_Function_2_oDBCNetWork_55d6a67c_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       2u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           7u },  /* [Globale PduRDestPdu: SupC_Function_2_oDBCNetWork_55d6a67c_Rx]            */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/PduR/Com] */
  { /*    12 */      DcmConf_DcmDslProtocolRx_Meg_FunDiag_oDBCNetWork_8501a87a_Rx_bf5f7bb7, PDUR_RX_DIRECTIONOFRMGDESTROM,       3u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           4u },  /* [Globale PduRDestPdu: Meg_FunDiag_oDBCNetWork_8501a87a_Rx]                */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Meg_FunDiag_oDBCNetWork_8501a87a_Rx, /ActiveEcuC/PduR/Dcm] */
  { /*    13 */      DcmConf_DcmDslProtocolRx_Meg_PhyDiag_oDBCNetWork_e154eea6_Rx_9bc604ea, PDUR_RX_DIRECTIONOFRMGDESTROM,       3u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           6u }   /* [Globale PduRDestPdu: Meg_PhyDiag_oDBCNetWork_e154eea6_Rx]                */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Meg_PhyDiag_oDBCNetWork_e154eea6_Rx, /ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRom
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomLength      the number of relations pointing to PduR_RmDestRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRom[14] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MmRomIdx  RmDestRomLength  RmDestRomStartIdx  SrcHnd                                                                       Comment                                       Referable Keys */
  { /*     0 */       0u,              1u,                2u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_1]        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can0ToCan1_PduR/PduRSrcPdu_1] */
  { /*     1 */       0u,              1u,                0u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu]          */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can1ToCan0_PduR/PduRSrcPdu] */
  { /*     2 */       0u,              1u,               13u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_f8af96ce] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupB_Button_Control_oDBCNetWork_a24295f7_Rx/PduRSrcPdu_f8af96ce] */
  { /*     3 */       0u,              1u,                5u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_495de942] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupB_Led_Control_oDBCNetWork_496a3ac6_Rx/PduRSrcPdu_495de942] */
  { /*     4 */       0u,              1u,                3u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_10b1802d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupC_Function_1_oDBCNetWork_44e7ee76_Rx/PduRSrcPdu_10b1802d] */
  { /*     5 */       0u,              1u,                7u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_755dbb0e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupC_Function_2_oDBCNetWork_1ff05f63_Rx/PduRSrcPdu_755dbb0e] */
  { /*     6 */       1u,              1u,                4u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_1af6dabd] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_FunDiag_oDBCNetWork_245e23dc_Rx/PduRSrcPdu_1af6dabd] */
  { /*     7 */       1u,              1u,                6u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_49b2840e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_PhyDiag_oDBCNetWork_e94a8f4d_Rx/PduRSrcPdu_49b2840e] */
  { /*     8 */       3u,              1u,                8u, DcmConf_DcmDslProtocolTx_Meg_ResDiag_oDBCNetWork_5467f8e5_Tx_024d51d1 },  /* [PduRSrcPdu: PduRSrcPdu_9c32056b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_ResDiag_oDBCNetWork_5467f8e5_Tx/PduRSrcPdu_9c32056b] */
  { /*     9 */       2u,              1u,               10u,                    ComConf_ComIPdu_SupA_Angle_oDBCNetWork_e5909e4f_Tx },  /* [PduRSrcPdu: PduRSrcPdu_c6b821a9] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Angle_oDBCNetWork_e5909e4f_Tx/PduRSrcPdu_c6b821a9] */
  { /*    10 */       2u,              1u,               12u,             ComConf_ComIPdu_SupA_Button_State_oDBCNetWork_390399bb_Tx },  /* [PduRSrcPdu: PduRSrcPdu_ed18513b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Button_State_oDBCNetWork_390399bb_Tx/PduRSrcPdu_ed18513b] */
  { /*    11 */       2u,              1u,                1u,               ComConf_ComIPdu_SupA_Function_1_oDBCNetWork_312706bd_Tx },  /* [PduRSrcPdu: PduRSrcPdu_045a4163] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Function_1_oDBCNetWork_312706bd_Tx/PduRSrcPdu_045a4163] */
  { /*    12 */       2u,              1u,               11u,                ComConf_ComIPdu_SupA_Led_State_oDBCNetWork_43576f7c_Tx },  /* [PduRSrcPdu: PduRSrcPdu_de6a18d2] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Led_State_oDBCNetWork_43576f7c_Tx/PduRSrcPdu_de6a18d2] */
  { /*    13 */       2u,              1u,                9u,                ComConf_ComIPdu_SupA_PowerMode_oDBCNetWork_b77edafa_Tx }   /* [PduRSrcPdu: PduRSrcPdu_a13e3769] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_PowerMode_oDBCNetWork_b77edafa_Tx/PduRSrcPdu_a13e3769] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_RmTransmitFctPtr
  \brief  Internal routing manager Transmit functions.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RmTransmitFctPtr                  Referable Keys */
  /*     0 */ PduR_RmIf_RoutePdu           ,  /* [PduR_RmIf_RoutePdu] */
  /*     1 */ PduR_RmTp_Transmit_MultiDest    /* [PduR_RmTp_Transmit_MultiDest] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all informations to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element                Description
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RmTransmitFctPtrIdx        Referable Keys */
  { /*     0 */                  1u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meg_ResDiag_oDBCNetWork_5467f8e5_Tx/PduRSrcPdu_9c32056b] */
  { /*     1 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Angle_oDBCNetWork_e5909e4f_Tx/PduRSrcPdu_c6b821a9] */
  { /*     2 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Button_State_oDBCNetWork_390399bb_Tx/PduRSrcPdu_ed18513b] */
  { /*     3 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Function_1_oDBCNetWork_312706bd_Tx/PduRSrcPdu_045a4163] */
  { /*     4 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_Led_State_oDBCNetWork_43576f7c_Tx/PduRSrcPdu_de6a18d2] */
  { /*     5 */                  0u }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SupA_PowerMode_oDBCNetWork_b77edafa_Tx/PduRSrcPdu_a13e3769] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2Up
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2Up
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element               Description
  TxConfirmationUsed    True, if any of the source PduRDestPdus uses a TxConfirmation.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2Up[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxConfirmationUsed        Referable Keys */
  { /*     0 */              FALSE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Rout_Can1ToCan0_100ms_oDBCNetWork_Can0_c34bc869_Tx] */
  { /*     1 */              FALSE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Route_Can0ToCan1_100ms_oDBCNetWork_a9bdfb29_Tx] */
  { /*     2 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_Angle_oDBCNetWork_418b1596_Tx] */
  { /*     3 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_Button_State_oDBCNetWork_eea6565b_Tx] */
  { /*     4 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_Function_1_oDBCNetWork_10b79eb2_Tx] */
  { /*     5 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_Led_State_oDBCNetWork_e7f688d3_Tx] */
  { /*     6 */               TRUE }   /* [/ActiveEcuC/EcuC/EcucPduCollection/SupA_PowerMode_oDBCNetWork_910ccf57_Tx] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Initialized
**********************************************************************************************************************/
/** 
  \var    PduR_Initialized
  \brief  Initialization state of PduR. TRUE, if PduR_Init() has been called, else FALSE
*/ 
#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(PDUR_USE_INIT_POINTER == STD_ON)
P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) PduR_ConfigDataPtr = (const PduR_PBConfigType *) NULL_PTR;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */
  
/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define PDUR_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

/* Exclusive Area Wrapper functions */

/**********************************************************************************************************************
 * PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/
/*!
 * \internal
 * -  enter the EA  
 * \endinternal
 *********************************************************************************************************************/
static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void)
{
  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
}


/**********************************************************************************************************************
 * PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/
/*!
 * \internal
 * -  exit the EA  
 * \endinternal
 *********************************************************************************************************************/
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void)
{
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
}


/* Upper Layer Interface APIs */

/**********************************************************************************************************************
 * PduR_ComTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
  Std_ReturnType retVal = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_DcmTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
  Std_ReturnType retVal = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/* Communication Interface APIs */

/**********************************************************************************************************************
 * PduR_CanIfRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general communication interface TxConfirmation function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(PduIdType TxPduId) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
  PduR_LoIfTxConfirmation(TxPduId);
#endif
  PDUR_DUMMY_STATEMENT(TxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}




/* Transport Protocol APIs */

/**********************************************************************************************************************
 * PduR_CanTpStartOfReception
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call transport protocoll StartOfReception function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpStartOfReception(id, info, TpSduLength, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_SOR, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyRxData.
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyRxData(id, info, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYRX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);  			/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyTxData.
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if(PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyTxData(id, info, retry, availableDataPtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYTX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     				/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);  					/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);  				/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp RxIndication function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpRxIndication(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPRXIND, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp TxConfirmation function 
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpTxConfirmation(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPTXCFM, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/* CancelReceive global without UseTag API */

/* ChangeParameter global without UseTag  API */

/* Communication Interface / Transport Protocol APIs */

/* Communication Interface / Transport Protocol APIs */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


#define PDUR_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API is called with an Id and a pointer.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \N The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       The pointer is provided by the lower layer and is assumed to be valid. It is passed as is to the corresponding function. 

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API is called with an Id.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \R The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       
  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY
    \DESCRIPTION    The API call is forwarded to an internal function.
    \COUNTERMEASURE \N The parameter are checked in the called function.

 SBSW_JUSTIFICATION_END */
 
 /* COV_JUSTIFICATION_BEGIN
 
  \ID COV_PDUR_WRAPPER_FUNC
    \ACCEPT X
    \REASON Each neighbouring module call the same internal function. The call is covered by an other module. 
    
  \ID COV_PDUR_RX_OR_TX_ONLY_CONFIG
    \ACCEPT TX
    \REASON The API is mandatory if this Bsw module exists. In case of Rx or Tx only configs the API call is not forwarded to the internal function. 
 
 COV_JUSTIFICATION_END */
 

/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.c
 *********************************************************************************************************************/

