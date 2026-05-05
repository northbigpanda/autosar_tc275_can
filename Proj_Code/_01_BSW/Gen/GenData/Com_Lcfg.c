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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.c
 *   Generation Time: 2026-05-05 14:33:42
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA  S 1881 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 1882 EOF */ /* MD_MSR_AutosarBoolean */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"

#include "Rte_Cbk.h"

#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
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
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x0000u   /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_2_oSupC_Function_1_oDBCNetWork_67363b0a_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_3_oSupC_Function_1_oDBCNetWork_5b56d802_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_4_oSupC_Function_1_oDBCNetWork_ee74713a_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_5_oSupC_Function_1_oDBCNetWork_d2149232_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_2_oSupC_Function_2_oDBCNetWork_5a0c40db_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_3_oSupC_Function_2_oDBCNetWork_666ca3d3_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_4_oSupC_Function_2_oDBCNetWork_d34e0aeb_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_5_oSupC_Function_2_oDBCNetWork_ef2ee9e3_RxInitValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt32
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt32Type, COM_CONST) Com_ConstValueUInt32[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt32      Referable Keys */
  /*     0 */       0x00000000u   /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_1_oSupB_Led_Control_oDBCNetWork_e21b7252_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_2_oSupB_Led_Control_oDBCNetWork_f1334b21_RxInitValue] */
};
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x01u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led1_Control_oSupB_Led_Control_oDBCNetWork_48297120_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led2_Control_oSupB_Led_Control_oDBCNetWork_9bb26ddb_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led3_Control_oSupB_Led_Control_oDBCNetWork_d53b6672_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led4_Control_oSupB_Led_Control_oDBCNetWork_e7f5526c_RxInitValue] */
  /*     1 */            0x00u   /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_0_oSupB_Led_Control_oDBCNetWork_ecfc9a83_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Checksum_0x400_oSupB_Led_Control_oDBCNetWork_1c8bf5dc_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Counter_0x400_oSupB_Led_Control_oDBCNetWork_2dd3ae1e_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button1_Control_oSupB_Button_Control_oDBCNetWork_cbcdfbc4_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button2_Control_oSupB_Button_Control_oDBCNetWork_f3f670b7_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button3_Control_oSupB_Button_Control_oDBCNetWork_52cff459_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button4_Control_oSupB_Button_Control_oDBCNetWork_83816651_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_1_oSupC_Function_1_oDBCNetWork_23971e12_RxInitValue, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_1_oSupC_Function_2_oDBCNetWork_1ead65c3_RxInitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                   Description
  InitValueUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  InitValueIdx              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  RxPduInfoIdx              the index of the 1:1 relation pointing to Com_RxPduInfo
  ShdBufferIdx              the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TmpBufferIdx              the index of the 0:1 relation pointing to Com_TmpRxShdBufferUInt8,Com_TmpRxShdBufferUInt16,Com_TmpRxShdBufferUInt32,Com_TmpRxShdBufferUInt64,Com_TmpRxShdBufferSInt8,Com_TmpRxShdBufferSInt16,Com_TmpRxShdBufferSInt32,Com_TmpRxShdBufferSInt64,Com_TmpRxShdBufferFloat32,Com_TmpRxShdBufferFloat64
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[23] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitValueUsed  ApplType                           BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  ShdBufferIdx  StartByteInPduPosition  TmpBufferIdx        Referable Keys */
  { /*     0 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         12u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           1u,           1u,           1u,                     1u,           5u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_0_oSupB_Led_Control_oDBCNetWork_ecfc9a83_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     1 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       24u,         32u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         3u,           4u,           0u,           1u,           1u,                     2u,           0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_1_oSupB_Led_Control_oDBCNetWork_e21b7252_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     2 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       20u,         60u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,           1u,           3u,                     5u,           1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_2_oSupB_Led_Control_oDBCNetWork_f1334b21_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     3 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,          8u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           1u,           3u,                     1u,           6u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led1_Control_oSupB_Led_Control_oDBCNetWork_48297120_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     4 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,          9u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           1u,           5u,                     1u,           1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led2_Control_oSupB_Led_Control_oDBCNetWork_9bb26ddb_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     5 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         10u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           1u,           7u,                     1u,           4u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led3_Control_oSupB_Led_Control_oDBCNetWork_d53b6672_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     6 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         11u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           1u,           9u,                     1u,           3u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led4_Control_oSupB_Led_Control_oDBCNetWork_e7f5526c_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     7 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           1u,           1u,          11u,                     0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Checksum_0x400_oSupB_Led_Control_oDBCNetWork_1c8bf5dc_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     8 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         56u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           7u,           1u,           1u,          13u,                     7u,           2u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Counter_0x400_oSupB_Led_Control_oDBCNetWork_2dd3ae1e_Rx, /ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     9 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         48u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           6u,           1u,           0u,          15u,                     6u,           3u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button1_Control_oSupB_Button_Control_oDBCNetWork_cbcdfbc4_Rx, /ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx] */
  { /*    10 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         49u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           6u,           1u,           0u,          17u,                     6u,           0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button2_Control_oSupB_Button_Control_oDBCNetWork_f3f670b7_Rx, /ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx] */
  { /*    11 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         50u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           6u,           1u,           0u,          19u,                     6u,           1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button3_Control_oSupB_Button_Control_oDBCNetWork_52cff459_Rx, /ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx] */
  { /*    12 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,         51u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           6u,           1u,           0u,          21u,                     6u,           2u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button4_Control_oSupB_Button_Control_oDBCNetWork_83816651_Rx, /ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx] */
  { /*    13 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,          4u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           1u,           2u,          23u,                     0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_1_oSupC_Function_1_oDBCNetWork_23971e12_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx] */
  { /*    14 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       12u,          8u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           1u,           0u,           2u,           1u,                     0u,           3u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_2_oSupC_Function_1_oDBCNetWork_67363b0a_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx] */
  { /*    15 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,           2u,           3u,                     2u,           1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_3_oSupC_Function_1_oDBCNetWork_5b56d802_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx] */
  { /*    16 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,           2u,           5u,                     4u,           2u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_4_oSupC_Function_1_oDBCNetWork_ee74713a_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx] */
  { /*    17 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,           2u,           7u,                     6u,           0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_5_oSupC_Function_1_oDBCNetWork_d2149232_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx] */
  { /*    18 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,          4u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           1u,           3u,          25u,                     0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_1_oSupC_Function_2_oDBCNetWork_1ead65c3_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx] */
  { /*    19 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       12u,          8u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           1u,           0u,           3u,           9u,                     0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_2_oSupC_Function_2_oDBCNetWork_5a0c40db_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx] */
  { /*    20 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,           3u,          11u,                     2u,           3u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_3_oSupC_Function_2_oDBCNetWork_666ca3d3_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx] */
  { /*    21 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,           3u,          13u,                     4u,           2u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_4_oSupC_Function_2_oDBCNetWork_d34e0aeb_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx] */
  { /*    22 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,           3u,          15u,                     6u,           1u }   /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_5_oSupC_Function_2_oDBCNetWork_ef2ee9e3_Rx, /ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[23] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */               9u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*     1 */              10u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*     2 */              11u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*     3 */              12u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*     4 */               0u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*     5 */               1u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*     6 */               2u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*     7 */               3u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*     8 */               4u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*     9 */               5u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*    10 */               6u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*    11 */               7u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*    12 */               8u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*    13 */              13u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*    14 */              14u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*    15 */              15u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*    16 */              16u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*    17 */              17u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*    18 */              18u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */
  /*    19 */              19u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */
  /*    20 */              20u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */
  /*    21 */              21u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */
  /*    22 */              22u   /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxCbkFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxCbkFuncPtr
  \brief  Function pointer table containing configured notification and invalid notifications function pointer for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComRxCbkType, COM_CONST) Com_RxCbkFuncPtr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxCbkFuncPtr                                                               Referable Keys */
  /*     0 */ Rte_COMCbk_SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx    /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_RxAck] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduGrpVectorStartIdx */
  { /*     0 */                   0u },
  { /*     1 */                   0u },
  { /*     2 */                   0u },
  { /*     3 */                   0u }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                    Description
  RxAccessInfoIndUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd
  RxAccessInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxAccessInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxDefPduBufferStartIdx     the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  Type                       Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxAccessInfoIndUsed  RxAccessInfoIndEndIdx  RxAccessInfoIndStartIdx  RxDefPduBufferStartIdx  Type                              Referable Keys */
  { /*     0 */                TRUE,                    4u,                      0u,                     0u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Rx_d3c0144f] */
  { /*     1 */                TRUE,                   13u,                      4u,                     8u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Rx_d3c0144f] */
  { /*     2 */                TRUE,                   18u,                     13u,                    16u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Rx_d3c0144f] */
  { /*     3 */                TRUE,                   23u,                     18u,                    24u, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Rx_d3c0144f] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigGrpInfo
  \brief  Contains all relevant information for Rx signal groups.
  \details
  Element                          Description
  ShdBufferRequired            
  RxAccessInfoGrpSigIndEndIdx      the end index of the 0:n relation pointing to Com_RxAccessInfoGrpSigInd
  RxAccessInfoGrpSigIndStartIdx    the start index of the 0:n relation pointing to Com_RxAccessInfoGrpSigInd
  RxCbkFuncPtrAckIdx               the index of the 0:1 relation pointing to Com_RxCbkFuncPtr
  RxPduInfoIdx                     the index of the 1:1 relation pointing to Com_RxPduInfo
  SignalProcessing             
  StartBytePosition                Least significant byte position of first group signal within the ComIPdu.
  ValidDlc                         Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxSigGrpInfoType, COM_CONST) Com_RxSigGrpInfo[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ShdBufferRequired  RxAccessInfoGrpSigIndEndIdx  RxAccessInfoGrpSigIndStartIdx  RxCbkFuncPtrAckIdx                       RxPduInfoIdx  SignalProcessing                             StartBytePosition  ValidDlc        Referable Keys */
  { /*     0 */              TRUE,                          9u,                            0u,                                      0u,           1u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO,                0u,       8u },  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx] */
  { /*     1 */              TRUE,                         13u,                            9u, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO,           0u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO,                6u,       7u },  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx] */
  { /*     2 */              TRUE,                         18u,                           13u, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO,           2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO,                0u,       8u },  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx] */
  { /*     3 */              TRUE,                         23u,                           18u, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO,           3u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO,                0u,       8u }   /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigGrpInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxSigGrpInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxSigGrpInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxSigGrpInfoIndType, COM_CONST) Com_RxSigGrpInfoInd[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxSigGrpInfoInd      Referable Keys */
  /*     0 */               1u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*     1 */               0u,  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*     2 */               2u,  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*     3 */               3u   /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  Periodic      TRUE if transmission mode contains a cyclic part.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic  TimePeriod        Referable Keys */
  { /*     0 */     TRUE,        40u },  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  { /*     1 */     TRUE,         2u }   /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element          Description
  InitMode         Initial transmission mode selector of the Tx I-PDU.
  TxModeTrueIdx    the index of the 1:1 relation pointing to Com_TxModeTrue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitMode  TxModeTrueIdx        Referable Keys */
  { /*     0 */     TRUE,            1u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  { /*     1 */     TRUE,            1u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  { /*     2 */     TRUE,            1u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  { /*     3 */     TRUE,            1u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  { /*     4 */     TRUE,            0u }   /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  Periodic      TRUE if transmission mode contains a cyclic part.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic  TimePeriod        Referable Keys */
  { /*     0 */     TRUE,        40u },  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  { /*     1 */     TRUE,         2u }   /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduGrpVectorStartIdx */
  { /*     0 */                   1u },
  { /*     1 */                   1u },
  { /*     2 */                   1u },
  { /*     3 */                   1u },
  { /*     4 */                   1u }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                   Description
  TxPduInitValueUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  TxBufferLength            the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx      the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx    the start index of the 0:n relation pointing to Com_TxPduInitValue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduInitValueUsed  TxBufferLength  TxPduInitValueEndIdx  TxPduInitValueStartIdx        Referable Keys */
  { /*     0 */               TRUE,             8u,                   8u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  { /*     1 */               TRUE,             8u,                  16u,                     8u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  { /*     2 */               TRUE,             8u,                  24u,                    16u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  { /*     3 */               TRUE,             8u,                  32u,                    24u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  { /*     4 */               TRUE,             8u,                  40u,                    32u }   /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[40] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x14u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     1 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     2 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     3 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     4 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     5 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     6 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     7 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     8 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*     9 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    10 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    11 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    12 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    13 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    14 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    15 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    16 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*    17 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*    18 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*    19 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*    20 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*    21 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*    22 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*    23 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*    24 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    25 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    26 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    27 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    28 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    29 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    30 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    31 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    32 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  /*    33 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  /*    34 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  /*    35 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  /*    36 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  /*    37 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  /*    38 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  /*    39 */           0x00u   /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpInfo
  \brief  Contains all relevant information for Tx Signal Groups.
  \details
  Element                           Description
  TxSigGrpMaskUsed                  TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask
  PduOffset                         Byte offset relative to the PDU the signal group is starting.
  TransferProperty              
  TxBufferEndIdx                    the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferSigGrpInTxIPDUEndIdx      the end index of the 1:n relation pointing to Com_TxBuffer
  TxBufferSigGrpInTxIPDUStartIdx    the start index of the 1:n relation pointing to Com_TxBuffer
  TxBufferStartIdx                  the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx                      the index of the 1:1 relation pointing to Com_TxPduInfo
  TxSigGrpMaskEndIdx                the end index of the 0:n relation pointing to Com_TxSigGrpMask
  TxSigGrpMaskStartIdx              the start index of the 0:n relation pointing to Com_TxSigGrpMask
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigGrpInfoType, COM_CONST) Com_TxSigGrpInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxSigGrpMaskUsed  PduOffset  TransferProperty                            TxBufferEndIdx  TxBufferSigGrpInTxIPDUEndIdx  TxBufferSigGrpInTxIPDUStartIdx  TxBufferStartIdx  TxPduInfoIdx  TxSigGrpMaskEndIdx  TxSigGrpMaskStartIdx        Referable Keys */
  { /*     0 */             TRUE,        0u, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,            41u,                          25u,                            24u,              40u,           3u,                16u,                  15u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led3_State_oSupA_Led_State_oDBCNetWork_dc39af74_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led4_State_oSupA_Led_State_oDBCNetWork_df70c2cf_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led2_State_oSupA_Led_State_oDBCNetWork_13a7b8bc_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led1_State_oSupA_Led_State_oDBCNetWork_987486a5_Tx] */
  { /*     1 */             TRUE,        4u, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,            42u,                          13u,                            12u,              41u,           1u,                16u,                  15u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button4_State_oSupA_Button_State_oDBCNetWork_2704068b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button2_State_oSupA_Button_State_oDBCNetWork_bcd40645_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button3_State_oSupA_Button_State_oDBCNetWork_315cfba7_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button1_State_oSupA_Button_State_oDBCNetWork_f13c0622_Tx] */
  { /*     2 */             TRUE,        0u, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,            50u,                          40u,                            32u,              42u,           4u,                16u,                   8u },  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/SupA_Checksum_0x112_oSupA_PowerMode_oDBCNetWork_3f776c50_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/SupA_Counter_0x112_oSupA_PowerMode_oDBCNetWork_5e5c6751_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/PowerMode_oSupA_PowerMode_oDBCNetWork_c3b722c7_Tx] */
  { /*     3 */             TRUE,        0u, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,            51u,                           1u,                             0u,              50u,           0u,                 1u,                   0u },  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x113_oSupA_Angle_oDBCNetWork_c5c2558a_Tx/AAA_Angle_oSupA_Angle_oDBCNetWork_1adb3bf0_Tx] */
  { /*     4 */             TRUE,        0u, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,            59u,                          24u,                            16u,              51u,           2u,                 9u,                   1u }   /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_1_oSupA_Function_1_oDBCNetWork_6c3a7273_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_3_oSupA_Function_1_oDBCNetWork_14fbb463_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_5_oSupA_Function_1_oDBCNetWork_9db9fe53_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_2_oSupA_Function_1_oDBCNetWork_289b576b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_4_oSupA_Function_1_oDBCNetWork_a1d91d5b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_6_oSupA_Function_1_oDBCNetWork_d918db4b_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_TxSigGrpInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigGrpInfoIndType, COM_CONST) Com_TxSigGrpInfoInd[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxSigGrpInfoInd      Referable Keys */
  /*     0 */               3u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     1 */               1u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*     2 */               4u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  /*     3 */               0u,  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*     4 */               2u   /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpMask
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpMask
  \brief  Signal group mask needed to copy interlaced signal groups to the Tx PDU buffer.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigGrpMaskType, COM_CONST) Com_TxSigGrpMask[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxSigGrpMask      Referable Keys */
  /*     0 */         0x3Fu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x113_oSupA_Angle_oDBCNetWork_c5c2558a_Tx] */
  /*     1 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx] */
  /*     2 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx] */
  /*     3 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx] */
  /*     4 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx] */
  /*     5 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx] */
  /*     6 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx] */
  /*     7 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx] */
  /*     8 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx] */
  /*     9 */         0x07u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*    10 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*    11 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*    12 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*    13 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*    14 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*    15 */         0x0Fu   /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  TxSigGrpInfoUsed          TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxSigGrpInfo
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
  TxSigGrpInfoIdx           the index of the 0:1 relation pointing to Com_TxSigGrpInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[18] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxSigGrpInfoUsed  ApplType                        BitLength  BitPosition  BusAcc                              ByteLength  BytePosition  StartByteInPduPosition  TxBufferEndIdx  TxBufferStartIdx  TxPduInfoIdx  TxSigGrpInfoIdx        Referable Keys */
  { /*     0 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,          0u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           0u,                     0u,            41u,              40u,           3u,              0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led1_State_oSupA_Led_State_oDBCNetWork_987486a5_Tx, /ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  { /*     1 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,          1u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           0u,                     0u,            41u,              40u,           3u,              0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led2_State_oSupA_Led_State_oDBCNetWork_13a7b8bc_Tx, /ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  { /*     2 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,          2u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           0u,                     0u,            41u,              40u,           3u,              0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led3_State_oSupA_Led_State_oDBCNetWork_dc39af74_Tx, /ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  { /*     3 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,          3u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           0u,                     0u,            41u,              40u,           3u,              0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led4_State_oSupA_Led_State_oDBCNetWork_df70c2cf_Tx, /ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  { /*     4 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,         32u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           4u,                     4u,            42u,              41u,           1u,              1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button1_State_oSupA_Button_State_oDBCNetWork_f13c0622_Tx, /ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  { /*     5 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,         33u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           4u,                     4u,            42u,              41u,           1u,              1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button2_State_oSupA_Button_State_oDBCNetWork_bcd40645_Tx, /ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  { /*     6 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,         34u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           4u,                     4u,            42u,              41u,           1u,              1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button3_State_oSupA_Button_State_oDBCNetWork_315cfba7_Tx, /ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  { /*     7 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        1u,         35u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           4u,                     4u,            42u,              41u,           1u,              1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button4_State_oSupA_Button_State_oDBCNetWork_2704068b_Tx, /ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  { /*     8 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        3u,          8u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           1u,                     1u,            44u,              43u,           4u,              2u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/PowerMode_oSupA_PowerMode_oDBCNetWork_c3b722c7_Tx, /ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  { /*     9 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,          0u,         COM_BYTE_BUSACCOFTXSIGINFO,         1u,           0u,                     0u,            43u,              42u,           4u,              2u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/SupA_Checksum_0x112_oSupA_PowerMode_oDBCNetWork_3f776c50_Tx, /ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  { /*    10 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4u,         56u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           7u,                     7u,            50u,              49u,           4u,              2u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/SupA_Counter_0x112_oSupA_PowerMode_oDBCNetWork_5e5c6751_Tx, /ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx] */
  { /*    11 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6u,          0u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           0u,                     0u,            51u,              50u,           0u,              3u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x113_oSupA_Angle_oDBCNetWork_c5c2558a_Tx/AAA_Angle_oSupA_Angle_oDBCNetWork_1adb3bf0_Tx, /ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  { /*    12 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4u,          4u,         COM_NBIT_BUSACCOFTXSIGINFO,         0u,           0u,                     0u,            52u,              51u,           2u,              4u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_1_oSupA_Function_1_oDBCNetWork_6c3a7273_Tx, /ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  { /*    13 */             TRUE, COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,          8u, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1u,           1u,                     0u,            53u,              51u,           2u,              4u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_2_oSupA_Function_1_oDBCNetWork_289b576b_Tx, /ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  { /*    14 */             TRUE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,         24u,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2u,           3u,                     2u,            55u,              53u,           2u,              4u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_3_oSupA_Function_1_oDBCNetWork_14fbb463_Tx, /ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  { /*    15 */             TRUE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,         40u,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2u,           5u,                     4u,            57u,              55u,           2u,              4u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_4_oSupA_Function_1_oDBCNetWork_a1d91d5b_Tx, /ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  { /*    16 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         48u,         COM_BYTE_BUSACCOFTXSIGINFO,         1u,           6u,                     6u,            58u,              57u,           2u,              4u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_5_oSupA_Function_1_oDBCNetWork_9db9fe53_Tx, /ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
  { /*    17 */             TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,         56u,         COM_BYTE_BUSACCOFTXSIGINFO,         1u,           7u,                     7u,            59u,              58u,           2u,              4u }   /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_6_oSupA_Function_1_oDBCNetWork_d918db4b_Tx, /ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredFctPtrCache
**********************************************************************************************************************/
/** 
  \var    Com_RxDeferredFctPtrCache
  \brief  Cache for deferred Rx (invalid) notification.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeferredFctPtrCacheType, COM_VAR_NOINIT) Com_RxDeferredFctPtrCache[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupB_Button_Control_oDBCNetWork_0c40490d_Rx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Rx_d3c0144f] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupB_Led_Control_oDBCNetWork_eb16948d_Rx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Rx_d3c0144f] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_1_oDBCNetWork_e81ccab2_Rx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Rx_d3c0144f] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SupC_Function_2_oDBCNetWork_55d6a67c_Rx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Rx_d3c0144f] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[16];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_2_oSupC_Function_1_oDBCNetWork_67363b0a_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_2_oSupC_Function_1_oDBCNetWork_67363b0a_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_2_oSupC_Function_1_oDBCNetWork_67363b0a_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_3_oSupC_Function_1_oDBCNetWork_5b56d802_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_3_oSupC_Function_1_oDBCNetWork_5b56d802_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_3_oSupC_Function_1_oDBCNetWork_5b56d802_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_4_oSupC_Function_1_oDBCNetWork_ee74713a_Rx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_4_oSupC_Function_1_oDBCNetWork_ee74713a_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_4_oSupC_Function_1_oDBCNetWork_ee74713a_Rx_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_5_oSupC_Function_1_oDBCNetWork_d2149232_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_5_oSupC_Function_1_oDBCNetWork_d2149232_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_5_oSupC_Function_1_oDBCNetWork_d2149232_Rx_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_2_oSupC_Function_2_oDBCNetWork_5a0c40db_Rx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_2_oSupC_Function_2_oDBCNetWork_5a0c40db_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_2_oSupC_Function_2_oDBCNetWork_5a0c40db_Rx_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_3_oSupC_Function_2_oDBCNetWork_666ca3d3_Rx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_3_oSupC_Function_2_oDBCNetWork_666ca3d3_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_3_oSupC_Function_2_oDBCNetWork_666ca3d3_Rx_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_4_oSupC_Function_2_oDBCNetWork_d34e0aeb_Rx] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_4_oSupC_Function_2_oDBCNetWork_d34e0aeb_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_4_oSupC_Function_2_oDBCNetWork_d34e0aeb_Rx_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_5_oSupC_Function_2_oDBCNetWork_ef2ee9e3_Rx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_5_oSupC_Function_2_oDBCNetWork_ef2ee9e3_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_5_oSupC_Function_2_oDBCNetWork_ef2ee9e3_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt32
  \brief  Rx Signal and Group Signal Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt32Type, COM_VAR_NOINIT) Com_RxSigBufferUInt32[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_1_oSupB_Led_Control_oDBCNetWork_e21b7252_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_1_oSupB_Led_Control_oDBCNetWork_e21b7252_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_1_oSupB_Led_Control_oDBCNetWork_e21b7252_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_2_oSupB_Led_Control_oDBCNetWork_f1334b21_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_2_oSupB_Led_Control_oDBCNetWork_f1334b21_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_2_oSupB_Led_Control_oDBCNetWork_f1334b21_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[26];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_0_oSupB_Led_Control_oDBCNetWork_ecfc9a83_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_0_oSupB_Led_Control_oDBCNetWork_ecfc9a83_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_0_oSupB_Led_Control_oDBCNetWork_ecfc9a83_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led1_Control_oSupB_Led_Control_oDBCNetWork_48297120_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led1_Control_oSupB_Led_Control_oDBCNetWork_48297120_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led1_Control_oSupB_Led_Control_oDBCNetWork_48297120_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led2_Control_oSupB_Led_Control_oDBCNetWork_9bb26ddb_Rx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led2_Control_oSupB_Led_Control_oDBCNetWork_9bb26ddb_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led2_Control_oSupB_Led_Control_oDBCNetWork_9bb26ddb_Rx_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led3_Control_oSupB_Led_Control_oDBCNetWork_d53b6672_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led3_Control_oSupB_Led_Control_oDBCNetWork_d53b6672_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led3_Control_oSupB_Led_Control_oDBCNetWork_d53b6672_Rx_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led4_Control_oSupB_Led_Control_oDBCNetWork_e7f5526c_Rx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led4_Control_oSupB_Led_Control_oDBCNetWork_e7f5526c_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led4_Control_oSupB_Led_Control_oDBCNetWork_e7f5526c_Rx_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Checksum_0x400_oSupB_Led_Control_oDBCNetWork_1c8bf5dc_Rx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Checksum_0x400_oSupB_Led_Control_oDBCNetWork_1c8bf5dc_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Checksum_0x400_oSupB_Led_Control_oDBCNetWork_1c8bf5dc_Rx_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Counter_0x400_oSupB_Led_Control_oDBCNetWork_2dd3ae1e_Rx] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Counter_0x400_oSupB_Led_Control_oDBCNetWork_2dd3ae1e_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Counter_0x400_oSupB_Led_Control_oDBCNetWork_2dd3ae1e_Rx_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button1_Control_oSupB_Button_Control_oDBCNetWork_cbcdfbc4_Rx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button1_Control_oSupB_Button_Control_oDBCNetWork_cbcdfbc4_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button1_Control_oSupB_Button_Control_oDBCNetWork_cbcdfbc4_Rx_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button2_Control_oSupB_Button_Control_oDBCNetWork_f3f670b7_Rx] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button2_Control_oSupB_Button_Control_oDBCNetWork_f3f670b7_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button2_Control_oSupB_Button_Control_oDBCNetWork_f3f670b7_Rx_RxSignalBufferRouting] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button3_Control_oSupB_Button_Control_oDBCNetWork_52cff459_Rx] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button3_Control_oSupB_Button_Control_oDBCNetWork_52cff459_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button3_Control_oSupB_Button_Control_oDBCNetWork_52cff459_Rx_RxSignalBufferRouting] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button4_Control_oSupB_Button_Control_oDBCNetWork_83816651_Rx] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button4_Control_oSupB_Button_Control_oDBCNetWork_83816651_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button4_Control_oSupB_Button_Control_oDBCNetWork_83816651_Rx_RxSignalBufferRouting] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_1_oSupC_Function_1_oDBCNetWork_23971e12_Rx] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_1_oSupC_Function_1_oDBCNetWork_23971e12_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_1_oSupC_Function_1_oDBCNetWork_23971e12_Rx_RxSignalBufferRouting] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_1_oSupC_Function_2_oDBCNetWork_1ead65c3_Rx] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_1_oSupC_Function_2_oDBCNetWork_1ead65c3_Rx_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_1_oSupC_Function_2_oDBCNetWork_1ead65c3_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_SigGrpEventFlag
**********************************************************************************************************************/
/** 
  \var    Com_SigGrpEventFlag
  \brief  Flag is set if a group signal write access caused a triggered event.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_SigGrpEventFlagType, COM_VAR_NOINIT) Com_SigGrpEventFlag[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt16
  \brief  Temporary Rx Group Signal Shadow Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TmpRxShdBufferUInt16Type, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt16[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_5_oSupC_Function_1_oDBCNetWork_d2149232_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_2_oSupC_Function_2_oDBCNetWork_5a0c40db_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_3_oSupC_Function_1_oDBCNetWork_5b56d802_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_5_oSupC_Function_2_oDBCNetWork_ef2ee9e3_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_4_oSupC_Function_1_oDBCNetWork_ee74713a_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_4_oSupC_Function_2_oDBCNetWork_d34e0aeb_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_2_oSupC_Function_1_oDBCNetWork_67363b0a_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_3_oSupC_Function_2_oDBCNetWork_666ca3d3_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt32
  \brief  Temporary Rx Group Signal Shadow Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TmpRxShdBufferUInt32UType, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt32;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_1_oSupB_Led_Control_oDBCNetWork_e21b7252_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_2_oSupB_Led_Control_oDBCNetWork_f1334b21_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt8
  \brief  Temporary Rx Group Signal Shadow Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TmpRxShdBufferUInt8Type, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt8[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button2_Control_oSupB_Button_Control_oDBCNetWork_f3f670b7_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Checksum_0x400_oSupB_Led_Control_oDBCNetWork_1c8bf5dc_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x402_oSupC_Function_1_oDBCNetWork_20ce0e3b_Rx/Sig_0x402_Used_1_oSupC_Function_1_oDBCNetWork_23971e12_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x403_oSupC_Function_2_oDBCNetWork_a16481fd_Rx/Sig_0x403_Used_1_oSupC_Function_2_oDBCNetWork_1ead65c3_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button3_Control_oSupB_Button_Control_oDBCNetWork_52cff459_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led2_Control_oSupB_Led_Control_oDBCNetWork_9bb26ddb_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button4_Control_oSupB_Button_Control_oDBCNetWork_83816651_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/SupB_Counter_0x400_oSupB_Led_Control_oDBCNetWork_2dd3ae1e_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x401_oSupB_Button_Control_oDBCNetWork_41809065_Rx/Button1_Control_oSupB_Button_Control_oDBCNetWork_cbcdfbc4_Rx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led4_Control_oSupB_Led_Control_oDBCNetWork_e7f5526c_Rx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led3_Control_oSupB_Led_Control_oDBCNetWork_d53b6672_Rx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/CrcSig_Pack_0_oSupB_Led_Control_oDBCNetWork_ecfc9a83_Rx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x400_oSupB_Led_Control_oDBCNetWork_6275ac6f_Rx/Led1_Control_oSupB_Led_Control_oDBCNetWork_48297120_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[59];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x113_oSupA_Angle_oDBCNetWork_c5c2558a_TxSigGrpInTxIPDU] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_TxSigGrpInTxIPDU] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_TxSigGrpInTxIPDU] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_TxSigGrpInTxIPDU] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_TxSigGrpInTxIPDU] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_TxSigGrpInTxIPDU] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_TxSigGrpInTxIPDU] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_TxSigGrpInTxIPDU] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_TxSigGrpInTxIPDU] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led3_State_oSupA_Led_State_oDBCNetWork_dc39af74_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led4_State_oSupA_Led_State_oDBCNetWork_df70c2cf_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led2_State_oSupA_Led_State_oDBCNetWork_13a7b8bc_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x110_oSupA_Led_State_oDBCNetWork_89d57c9b_Tx/Led1_State_oSupA_Led_State_oDBCNetWork_987486a5_Tx] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button4_State_oSupA_Button_State_oDBCNetWork_2704068b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button2_State_oSupA_Button_State_oDBCNetWork_bcd40645_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button3_State_oSupA_Button_State_oDBCNetWork_315cfba7_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x111_oSupA_Button_State_oDBCNetWork_062df960_Tx/Button1_State_oSupA_Button_State_oDBCNetWork_f13c0622_Tx] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/SupA_Checksum_0x112_oSupA_PowerMode_oDBCNetWork_3f776c50_Tx] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/PowerMode_oSupA_PowerMode_oDBCNetWork_c3b722c7_Tx] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x112_oSupA_PowerMode_oDBCNetWork_bbf37b55_Tx/SupA_Counter_0x112_oSupA_PowerMode_oDBCNetWork_5e5c6751_Tx] */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x113_oSupA_Angle_oDBCNetWork_c5c2558a_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x113_oSupA_Angle_oDBCNetWork_c5c2558a_Tx/AAA_Angle_oSupA_Angle_oDBCNetWork_1adb3bf0_Tx] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_1_oSupA_Function_1_oDBCNetWork_6c3a7273_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_2_oSupA_Function_1_oDBCNetWork_289b576b_Tx] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_2_oSupA_Function_1_oDBCNetWork_289b576b_Tx] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_3_oSupA_Function_1_oDBCNetWork_14fbb463_Tx] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_3_oSupA_Function_1_oDBCNetWork_14fbb463_Tx] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_4_oSupA_Function_1_oDBCNetWork_a1d91d5b_Tx] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_4_oSupA_Function_1_oDBCNetWork_a1d91d5b_Tx] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_5_oSupA_Function_1_oDBCNetWork_9db9fe53_Tx] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx, /ActiveEcuC/Com/ComConfig/SG_Sig_Grp_0x114_oSupA_Function_1_oDBCNetWork_fe007f55_Tx/Sig_0x114_Used_6_oSupA_Function_1_oDBCNetWork_d918db4b_Tx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Angle_oDBCNetWork_e5909e4f_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Button_State_oDBCNetWork_390399bb_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Function_1_oDBCNetWork_312706bd_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SupA_Led_State_oDBCNetWork_43576f7c_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SupA_PowerMode_oDBCNetWork_b77edafa_Tx, /ActiveEcuC/Com/ComConfig/XB_SUP_A_oDBCNetWork_Tx_859ab3c9] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

