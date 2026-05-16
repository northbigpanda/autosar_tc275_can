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
 *            Module: Can
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Lcfg.c
 *   Generation Time: 2026-05-16 22:28:40
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/


#define CAN_LCFG_SOURCE

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "Can_Cfg.h"

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */


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
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanIfChannelId      Comment */
  /*     0 */              0u,  /* [CT_DBCNetWork_78f82e94] */
  /*     1 */              1u   /* [CT_DBCNetWork_Can0_5928070d] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                            Description
  CanControllerDefaultBaudrate   
  CanControllerDefaultBaudrateIdx
  MailboxRxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxRxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxRxFullEndIdx                the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxFullLength                the number of relations pointing to Can_Mailbox
  MailboxRxFullStartIdx              the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxTxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedEndIdx                the end index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedLength                the number of relations pointing to Can_Mailbox
  MailboxUnusedStartIdx              the start index of the 0:n relation pointing to Can_Mailbox
  RxBasicHwStart                 
  RxBasicHwStop                  
  RxFullHwStart                  
  RxFullHwStop                   
  TxBasicHwStart                 
  TxBasicHwStop                  
  TxFullHwStart                  
  TxFullHwStop                   
  UnusedHwStart                  
  UnusedHwStop                   
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CanControllerDefaultBaudrate  CanControllerDefaultBaudrateIdx  MailboxRxBasicEndIdx                                                                                                                                                         MailboxRxBasicLength                                                                                                                                                         MailboxRxBasicStartIdx                                                                                                                                                         MailboxRxFullEndIdx                                                                                                                                                                                 MailboxRxFullLength                                                                                                                                                        MailboxRxFullStartIdx                                                                                                                                                                                 MailboxTxBasicEndIdx                                                                                                                                                         MailboxTxBasicLength                                                                                                                                                         MailboxTxBasicStartIdx                                                                                                                                                         MailboxUnusedEndIdx                                                                                                                                                        MailboxUnusedLength                                                                                                                                                        MailboxUnusedStartIdx                                                                                                                                                        RxBasicHwStart  RxBasicHwStop  RxFullHwStart  RxFullHwStop  TxBasicHwStart  TxBasicHwStop  TxFullHwStart  TxFullHwStop  UnusedHwStart  UnusedHwStop        Comment                                   Referable Keys */
  { /*     0 */                         500u,                              0u,                   8u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                     7u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                                           7u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                  6u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                                             1u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                     0u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                 11u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                  1u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,                   10u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */     ,             7u,            9u,            1u,           7u,             0u,            1u,            0u,           0u,            9u,          20u },  /* [CT_DBCNetWork_78f82e94]      */  /* [/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94] */
  { /*     1 */                         500u,                              0u,                  10u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                     9u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */, CAN_NO_MAILBOXRXFULLENDIDXOFCONTROLLERCONFIG  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                  0u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */, CAN_NO_MAILBOXRXFULLSTARTIDXOFCONTROLLERCONFIG  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                   9u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                     8u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                 12u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                  1u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,                   11u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController) */,            21u,           23u,           21u,          21u,            20u,           21u,           20u,          20u,           23u,          27u }   /* [CT_DBCNetWork_Can0_5928070d] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_GlobalInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_GlobalInterruptPendingMask
  \brief  Mask of all interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_GlobalInterruptPendingMaskType, CAN_CONST) Can_GlobalInterruptPendingMask[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     GlobalInterruptPendingMask      Comment */
  /*     0 */                 0x000001FFu,  /* [CT_DBCNetWork_78f82e94, Mailbox 0-31] */
  /*     1 */                 0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 32-63] */
  /*     2 */                 0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 64-95] */
  /*     3 */                 0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 96-127] */
  /*     4 */                 0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 128-159] */
  /*     5 */                 0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 160-191] */
  /*     6 */                 0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 192-223] */
  /*     7 */                 0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 224-255] */
  /*     8 */                 0x00700000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 0-31] */
  /*     9 */                 0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 32-63] */
  /*    10 */                 0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 64-95] */
  /*    11 */                 0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 96-127] */
  /*    12 */                 0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 128-159] */
  /*    13 */                 0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 160-191] */
  /*    14 */                 0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 192-223] */
  /*    15 */                 0x00000000u   /* [CT_DBCNetWork_Can0_5928070d, Mailbox 224-255] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitBT
**********************************************************************************************************************/
/** 
  \var    Can_InitBT
  \brief  Bit timing.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitBTType, CAN_CONST) Can_InitBT[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitBT       Comment */
  /*     0 */  0x164Fu,  /* [CT_DBCNetWork_78f82e94 - CanControllerBaudrateConfig] */
  /*     1 */  0x164Fu   /* [CT_DBCNetWork_Can0_5928070d - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitCodeH
**********************************************************************************************************************/
/** 
  \var    Can_InitCodeH
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitCodeHType, CAN_CONST) Can_InitCodeH[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitCodeH      Comment */
  /*     0 */    0x1800u,  /* [CT_DBCNetWork_78f82e94 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     1 */    0x0000u   /* [CT_DBCNetWork_Can0_5928070d - CanControllerBaudrateConfig, CanFilterMask_Can0] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitCodeL
**********************************************************************************************************************/
/** 
  \var    Can_InitCodeL
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitCodeLType, CAN_CONST) Can_InitCodeL[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitCodeL      Comment */
  /*     0 */      0x00u,  /* [CT_DBCNetWork_78f82e94 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     1 */      0x00u   /* [CT_DBCNetWork_Can0_5928070d - CanControllerBaudrateConfig, CanFilterMask_Can0] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitMaskH
**********************************************************************************************************************/
/** 
  \var    Can_InitMaskH
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitMaskHType, CAN_CONST) Can_InitMaskH[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitMaskH      Comment */
  /*     0 */    0x3C00u,  /* [CT_DBCNetWork_78f82e94 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     1 */    0x2000u   /* [CT_DBCNetWork_Can0_5928070d - CanControllerBaudrateConfig, CanFilterMask_Can0] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitMaskL
**********************************************************************************************************************/
/** 
  \var    Can_InitMaskL
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitMaskLType, CAN_CONST) Can_InitMaskL[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitMaskL      Comment */
  /*     0 */      0x00u,  /* [CT_DBCNetWork_78f82e94 - CanControllerBaudrateConfig, CanFilterMask] */
  /*     1 */      0x00u   /* [CT_DBCNetWork_Can0_5928070d - CanControllerBaudrateConfig, CanFilterMask_Can0] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectBaudrate      Comment */
  /*     0 */                500u,  /* [CT_DBCNetWork_78f82e94 - CanControllerBaudrateConfig] */
  /*     1 */                500u   /* [CT_DBCNetWork_Can0_5928070d - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectStartIndex      Comment */
  /*     0 */                    0u,  /* [CT_DBCNetWork_78f82e94] */
  /*     1 */                    1u,  /* [CT_DBCNetWork_Can0_5928070d] */
  /*     2 */                    2u   /* [stop index] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitPortSel
**********************************************************************************************************************/
/** 
  \var    Can_InitPortSel
  \brief  Receive input selection.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitPortSelType, CAN_CONST) Can_InitPortSel[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitPortSel      Comment */
  /*     0 */           1u,  /* [CT_DBCNetWork_78f82e94] */
  /*     1 */           1u   /* [CT_DBCNetWork_Can0_5928070d] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsrOsId
**********************************************************************************************************************/
/** 
  \var    Can_IsrOsId
  \brief  OS Symbolic Name Value for all controller interrupts.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_IsrOsIdType, CAN_CONST) Can_IsrOsId[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     IsrOsId       Comment */
  /*     0 */ CanIsr_1 ,  /* [CT_DBCNetWork_78f82e94 / Node1] */
  /*     1 */ CanIsr_0    /* [CT_DBCNetWork_Can0_5928070d / Node0] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  IDValue            
  ActiveSendObject   
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_ControllerConfig
  HwHandle           
  HwHandleStop       
  MailboxSize        
  MailboxType        
  MaxDataLen         
  MemorySectionsIndex
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IDValue  ActiveSendObject  ControllerConfigIdx                                                                  HwHandle  HwHandleStop  MailboxSize  MailboxType                                MaxDataLen  MemorySectionsIndex        Comment                                                     Referable Keys */
  { /*     0 */ 0x0000u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       0u,           1u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  0u },  /* [CN_DBCNetWork_9ed72b09_Tx]                     */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_9ed72b09_Tx (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     1 */ 0x07DFu,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       1u,           2u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  1u },  /* [CN_DBCNetWork_b9b38c08_Rx_Meg_FunDiag_Tp]      */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_b9b38c08_Rx_Meg_FunDiag_Tp (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     2 */ 0x0701u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       2u,           3u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  2u },  /* [CN_DBCNetWork_b9b38c08_Rx_Meg_PhyDiag_Tp]      */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_b9b38c08_Rx_Meg_PhyDiag_Tp (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     3 */ 0x0403u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       3u,           4u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  3u },  /* [CN_DBCNetWork_b9b38c08_Rx_SupC_Function_2]     */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_b9b38c08_Rx_SupC_Function_2 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     4 */ 0x0402u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       4u,           5u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  4u },  /* [CN_DBCNetWork_b9b38c08_Rx_SupC_Function_1]     */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_b9b38c08_Rx_SupC_Function_1 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     5 */ 0x0401u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       5u,           6u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  5u },  /* [CN_DBCNetWork_b9b38c08_Rx_SupB_Button_Control] */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_b9b38c08_Rx_SupB_Button_Control (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     6 */ 0x0400u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       6u,           7u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  6u },  /* [CN_DBCNetWork_b9b38c08_Rx_SupB_Led_Control]    */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_b9b38c08_Rx_SupB_Led_Control (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     7 */ 0x0000u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       7u,           9u,          2u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  7u },  /* [CN_DBCNetWork_b9b38c08_Rx_NM]                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_b9b38c08_Rx_NM (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     8 */ 0x0000u,               1u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d */,      20u,          21u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                 20u },  /* [CN_DBCNetWork_Can0_7c554129_Tx]                */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_Can0_7c554129_Tx (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*     9 */ 0x0000u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d */,      21u,          23u,          2u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                 21u },  /* [CN_DBCNetWork_Can0_3e6cf38a_Rx]                */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DBCNetWork_Can0_3e6cf38a_Rx (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*    10 */ 0x0000u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 */     ,       9u,          20u,         11u,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0u,                  9u },  /* []                                              */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_78f82e94 (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
  { /*    11 */ 0x0000u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d */,      23u,          27u,          4u,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0u,                 23u }   /* []                                              */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DBCNetWork_Can0_5928070d (DefRef: /MICROSAR/Can_TricoreMultican/Can/CanConfigSet/CanController)] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionInfo
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionInfo
  \brief  Memory section description
  \details
  Element               Description
  MemoryStartAddress
  MemorySectionStart
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MemorySectionInfoType, CAN_CONST) Can_MemorySectionInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MemoryStartAddress  MemorySectionStart        Comment */
  { /*     0 */        0xF0018000u,                 0u },  /* [MemorySection: Memory_CanCell] */
  { /*     1 */        0x00000000u,                27u }   /* [MemorySection: Memory_CanCellR] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionObjects
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionObjects
  \brief  Memory section objects description
  \details
  Element           Description
  HwHandle      
  MailboxElement
  MailboxHandle 
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MemorySectionObjectsType, CAN_CONST) Can_MemorySectionObjects[27] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HwHandle  MailboxElement  MailboxHandle        Comment */
  { /*     0 */       0u,             0u,            0u },  /* [Memory_CanCell - CN_DBCNetWork_9ed72b09_Tx] */
  { /*     1 */       1u,             0u,            1u },  /* [Memory_CanCell - CN_DBCNetWork_b9b38c08_Rx_Meg_FunDiag_Tp] */
  { /*     2 */       2u,             0u,            2u },  /* [Memory_CanCell - CN_DBCNetWork_b9b38c08_Rx_Meg_PhyDiag_Tp] */
  { /*     3 */       3u,             0u,            3u },  /* [Memory_CanCell - CN_DBCNetWork_b9b38c08_Rx_SupC_Function_2] */
  { /*     4 */       4u,             0u,            4u },  /* [Memory_CanCell - CN_DBCNetWork_b9b38c08_Rx_SupC_Function_1] */
  { /*     5 */       5u,             0u,            5u },  /* [Memory_CanCell - CN_DBCNetWork_b9b38c08_Rx_SupB_Button_Control] */
  { /*     6 */       6u,             0u,            6u },  /* [Memory_CanCell - CN_DBCNetWork_b9b38c08_Rx_SupB_Led_Control] */
  { /*     7 */       7u,             0u,            7u },  /* [Memory_CanCell - CN_DBCNetWork_b9b38c08_Rx_NM] */
  { /*     8 */       8u,             1u,            7u },  /* [Memory_CanCell - CN_DBCNetWork_b9b38c08_Rx_NM] */
  { /*     9 */       9u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    10 */      10u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    11 */      11u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    12 */      12u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    13 */      13u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    14 */      14u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    15 */      15u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    16 */      16u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    17 */      17u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    18 */      18u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    19 */      19u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    20 */      20u,             0u,            8u },  /* [Memory_CanCell - CN_DBCNetWork_Can0_7c554129_Tx] */
  { /*    21 */      21u,             0u,            9u },  /* [Memory_CanCell - CN_DBCNetWork_Can0_3e6cf38a_Rx] */
  { /*    22 */      22u,             1u,            9u },  /* [Memory_CanCell - CN_DBCNetWork_Can0_3e6cf38a_Rx] */
  { /*    23 */      23u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    24 */      24u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    25 */      25u,             0u,            0u },  /* [Memory_CanCell - Unused] */
  { /*    26 */      26u,             0u,            0u }   /* [Memory_CanCell - Unused] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_NodeAdr
**********************************************************************************************************************/
/** 
  \var    Can_NodeAdr
  \brief  Physical node address.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_NodeAdrType, CAN_CONST) Can_NodeAdr[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     NodeAdr          Comment */
  /*     0 */  0xF0018300u,  /* [CT_DBCNetWork_78f82e94] */
  /*     1 */  0xF0018200u   /* [CT_DBCNetWork_Can0_5928070d] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_NodeNum
**********************************************************************************************************************/
/** 
  \var    Can_NodeNum
  \brief  Physical node.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_NodeNumType, CAN_CONST) Can_NodeNum[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     NodeNum      Comment */
  /*     0 */       1u,  /* [CT_DBCNetWork_78f82e94] */
  /*     1 */       0u   /* [CT_DBCNetWork_Can0_5928070d] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_PhysPrio
**********************************************************************************************************************/
/** 
  \var    Can_PhysPrio
  \brief  Interrupt priority.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_PhysPrioType, CAN_CONST) Can_PhysPrio[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PhysPrio             Comment */
  /*     0 */              10u,  /* [Physical channel 0] */
  /*     1 */              10u,  /* [Physical channel 1] */
  /*     2 */  CAN_NO_PHYSPRIO,  /* [dummy entry] */
  /*     3 */  CAN_NO_PHYSPRIO   /* [dummy entry] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_RxBasicInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_RxBasicInterruptPendingMask
  \brief  Mask of Rx BasicCAN interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_RxBasicInterruptPendingMaskType, CAN_CONST) Can_RxBasicInterruptPendingMask[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxBasicInterruptPendingMask      Comment */
  /*     0 */                  0x00000180u,  /* [CT_DBCNetWork_78f82e94, Mailbox 0-31] */
  /*     1 */                  0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 32-63] */
  /*     2 */                  0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 64-95] */
  /*     3 */                  0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 96-127] */
  /*     4 */                  0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 128-159] */
  /*     5 */                  0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 160-191] */
  /*     6 */                  0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 192-223] */
  /*     7 */                  0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 224-255] */
  /*     8 */                  0x00600000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 0-31] */
  /*     9 */                  0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 32-63] */
  /*    10 */                  0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 64-95] */
  /*    11 */                  0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 96-127] */
  /*    12 */                  0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 128-159] */
  /*    13 */                  0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 160-191] */
  /*    14 */                  0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 192-223] */
  /*    15 */                  0x00000000u   /* [CT_DBCNetWork_Can0_5928070d, Mailbox 224-255] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_RxFullInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_RxFullInterruptPendingMask
  \brief  Mask of Rx FullCAN interrupt objects.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_RxFullInterruptPendingMaskType, CAN_CONST) Can_RxFullInterruptPendingMask[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxFullInterruptPendingMask      Comment */
  /*     0 */                       0x7Eu,  /* [CT_DBCNetWork_78f82e94, Mailbox 0-31] */
  /*     1 */                       0x00u,  /* [CT_DBCNetWork_78f82e94, Mailbox 32-63] */
  /*     2 */                       0x00u,  /* [CT_DBCNetWork_78f82e94, Mailbox 64-95] */
  /*     3 */                       0x00u,  /* [CT_DBCNetWork_78f82e94, Mailbox 96-127] */
  /*     4 */                       0x00u,  /* [CT_DBCNetWork_78f82e94, Mailbox 128-159] */
  /*     5 */                       0x00u,  /* [CT_DBCNetWork_78f82e94, Mailbox 160-191] */
  /*     6 */                       0x00u,  /* [CT_DBCNetWork_78f82e94, Mailbox 192-223] */
  /*     7 */                       0x00u,  /* [CT_DBCNetWork_78f82e94, Mailbox 224-255] */
  /*     8 */                       0x00u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 0-31] */
  /*     9 */                       0x00u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 32-63] */
  /*    10 */                       0x00u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 64-95] */
  /*    11 */                       0x00u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 96-127] */
  /*    12 */                       0x00u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 128-159] */
  /*    13 */                       0x00u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 160-191] */
  /*    14 */                       0x00u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 192-223] */
  /*    15 */                       0x00u   /* [CT_DBCNetWork_Can0_5928070d, Mailbox 224-255] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SrcNum
**********************************************************************************************************************/
/** 
  \var    Can_SrcNum
  \brief  Interrupt source register.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_SrcNumType, CAN_CONST) Can_SrcNum[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SrcNum      Comment */
  /*     0 */      1u,  /* [CT_DBCNetWork_78f82e94] */
  /*     1 */      0u   /* [CT_DBCNetWork_Can0_5928070d] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_TxInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_TxInterruptPendingMask
  \brief  Mask of Tx interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_TxInterruptPendingMaskType, CAN_CONST) Can_TxInterruptPendingMask[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxInterruptPendingMask      Comment */
  /*     0 */             0x00000001u,  /* [CT_DBCNetWork_78f82e94, Mailbox 0-31] */
  /*     1 */             0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 32-63] */
  /*     2 */             0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 64-95] */
  /*     3 */             0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 96-127] */
  /*     4 */             0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 128-159] */
  /*     5 */             0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 160-191] */
  /*     6 */             0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 192-223] */
  /*     7 */             0x00000000u,  /* [CT_DBCNetWork_78f82e94, Mailbox 224-255] */
  /*     8 */             0x00100000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 0-31] */
  /*     9 */             0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 32-63] */
  /*    10 */             0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 64-95] */
  /*    11 */             0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 96-127] */
  /*    12 */             0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 128-159] */
  /*    13 */             0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 160-191] */
  /*    14 */             0x00000000u,  /* [CT_DBCNetWork_Can0_5928070d, Mailbox 192-223] */
  /*    15 */             0x00000000u   /* [CT_DBCNetWork_Can0_5928070d, Mailbox 224-255] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  State      send state like cancelled or send activ
  Pdu        buffered PduId for confirmation or cancellation
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                      Description
  BusOffNotified               Controls BusOff notifications.
  BusOffTransitionRequest      CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01
  CanInterruptCounter          CAN interrupt disable counter for each controller
  Halt                         Reflects halt status of the controller.
  IsBusOff                     CAN state for each controller: busoff occur
  LastInitObject               last set baudrate for reinit
  LogStatus                    CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  ModeTransitionRequest        CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06
  RamCheckTransitionRequest    CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00
  CanInterruptOldStatus        last CAN interrupt status for restore interrupt for each controller
  LoopTimeout                  hw loop timeout for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_TmpRxMsgMailbox
**********************************************************************************************************************/
/** 
  \var    Can_TmpRxMsgMailbox
  \brief  Temporary buffer for received messages.
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(tCanTmpMsgObjStruct, CAN_VAR_NOINIT) Can_TmpRxMsgMailbox[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/




