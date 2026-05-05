/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PduR_Bm.c
 *      Project:  Gw_AsrPduRCfg5
 *       Module:  MICROSAR PDU Router
 *    Generator:  Configurator 5
 *
 *  Description:  Vector implementation of AUTOSAR PDU Router
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA S 3453 EOF */ /* MD_MSR_FctLikeMacro */
/* PRQA S 4558 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA S 2995 EOF */ /* MD_CSL_ConstantValueAsDefine */
/* *INDENT-ON* */

#define PDUR_BM_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Bm.h"
#include "PduR_Lock.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#define PduR_Core_MemCpyRamToRam(d, s, l)    VStdMemCpyRamToRam((d), (s), (l))
#define PduR_Core_MemCpyRomToRam(d, s, l)    VStdMemCpyRomToRam((d), (s), (l))

# if(PDUR_BMTXBUFFERRAM == STD_ON)
#define PduR_Bm_GetLengthOfBmTxBuffer(Index)                       (PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(Index) - (PduR_BmTxBufferArrayRamIterType) 1u)
#define PduR_Bm_GetInboundBmTxBufferArrayEndIdxOfBmTxBuffer(Index) (PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(Index) - (PduR_BmTxBufferArrayRamIterType) 1u)
# endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

#if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init_TxBuffer
 *********************************************************************************************************************/
/*! \brief      This function initializes the BufferManager TxBuffer
 *  \details     -
 *  \pre        PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \note       The function must be called on task level and has not to be interrupted.
 *              by other administrative function calls.
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Init_TxBuffer(void);
#endif

#if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init_TxBufferInstance
 *********************************************************************************************************************/
/*! \brief      This function initializes the BufferManager TxBuffer Instance
 *  \details     -
 *  \pre        PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \note       The function must be called on task level and has not to be interrupted.
 *              by other administrative function calls.
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Init_TxBufferInstance(void);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Put_Between_WriteIdx_EndIdx
 *********************************************************************************************************************/
/*! \brief      The WriteId leading. Add data up to the buffer end.
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx  read index in the transport protocol Tx buffer
 *  \param[in]  pduLength                length to copy
 *  \param[in]  sduDataPtr               data pointer
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Put_Between_WriteIdx_EndIdx(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                       CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Put_Between_WriteIdx_ReadIdx
 *********************************************************************************************************************/
/*! \brief      The WriteId lagging the ReadIdx. Add data to the buffer in this range.
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx  read index in the transport protocol Tx buffer
 *  \param[in]  pduLength                length to copy
 *  \param[in]  sduDataPtr               data pointer
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Put_Between_WriteIdx_ReadIdx(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_READ4WRITE state.
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx  read index in the transport protocol Tx buffer
 *  \param[in]  pduLength                length to copy
 *  \param[in]  sduDataPtr               data pointer
 *  \return     BUFREQ_OK                State change action was successful.
 *              BUFREQ_E_NOT_OK          State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                               CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the EMPTY or WRITE4READ state.
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx  read index in the transport protocol Tx buffer
 *  \param[in]  pduLength                length to copy
 *  \param[in]  sduDataPtr               data pointer
 *  \return     BUFREQ_OK                State change action was successful.
 *              BUFREQ_E_NOT_OK          State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Get_Between_ReadIdx_WriteIdx
 *********************************************************************************************************************/
/*! \brief      The ReadIdx lagging the WriteIdx. Get data in this range.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx instance Idx.
 *  \param[in]  pduLength                length to copy.
 *  \param[in]  sduDataPtr               data pointer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Get_Between_ReadIdx_WriteIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Get_Between_ReadIdx_EndIdx
 *********************************************************************************************************************/
/*! \brief      The ReadIdx is leading. Get data up to the buffer end.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx instance Idx.
 *  \param[in]  pduLength                length to copy.
 *  \param[in]  sduDataPtr               data pointer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Get_Between_ReadIdx_EndIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                      CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_WRITE4READ state.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx instance Idx.
 *  \param[in]  pduLength              length to copy.
 *  \param[in]  sduDataPtr             data pointer.
 *  \return     BUFREQ_OK              State change action was successful.
 *              BUFREQ_E_NOT_OK        State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                               CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE
 *********************************************************************************************************************/
/*! \brief      Helper function which handles the BUFFER_FULL and READ4WRITE state.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx instance Idx
 *  \param[in]  pduLength              length to copy
 *  \param[in]  sduDataPtr             data pointer
 *  \return     BUFREQ_OK              State change action was successful.
 *              BUFREQ_E_NOT_OK        State change action was not successful.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                                       PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_WriteIdx
 *********************************************************************************************************************/
/*! \brief      Set WriteIdx to buffer start Idx.
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx   read index in the transport protocol Tx buffer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_WriteIdx(PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearBufferSize
 *********************************************************************************************************************/
/*! \brief      Get the free buffer size which is available without doing a wrap around.
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx  index to the BmTxBuffer element
 *  \return     the calculated free buffer size
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearBufferSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_InstanceReadIdx
 *********************************************************************************************************************/
/*! \brief     Helper function to perform a wrap around for the instance specific read idx.
 *  \details    -
 *  \param[in] bmTxBufferInstanceRomIdx instance Idx.
 *  \pre        -
 *  \note      get data from buffer.
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_InstanceReadIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_WithWrapAround
 *********************************************************************************************************************/
/*! \brief      Perform wrap around handling for WriteIdx.
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx  read index in the transport protocol Tx buffer.
 *  \param[in]  pduLength              length to copy.
 *  \param[in]  sduDataPtr              data pointer.
 *  \pre        -
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_PutData_WithWrapAround(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, SduDataPtrType sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_WithWrapAround
 **********************************************************************************************************************/
/*! \brief      Perform a wrap around handling for instance ReadIdx.
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx  instance Idx.
 *  \param[in]  pduLength              length to copy.
 *  \param[in]  sduDataPtr             data pointer.
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_GetData_WithWrapAround(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                      SduDataPtrType sduDataPtr);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam
 **********************************************************************************************************************/
/*! \brief      Get BmTxBufferArrayRamRead Idx Of BmTxBufferRam
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx Buffer Idx.
 *  \return     Buffer read index
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferRamType, PDUR_CODE) PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam (PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamSafe
 **********************************************************************************************************************/
/*! \brief      Get BmTxBufferArrayRamRead Idx Of BmTxBufferInstanceRam with safe check
 *  \details    -
 *  \param[in]  bmTxBufferInstanceRomIdx Buffer instance Idx.
 *  \return     Buffer instance read index
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType, PDUR_CODE) PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamSafe(PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferInstanceRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe
 **********************************************************************************************************************/
/*! \brief      Get BmTxBufferArrayRamWrite Idx Of BmTxBufferRam with safe check
 *  \details    -
 *  \param[in]  bmTxBufferRomIdx Buffer Idx.
 *  \return     Buffer write index
 *  \pre        -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType, PDUR_CODE) PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(PduR_BmTxBufferRomIterType bmTxBufferRomIdx);
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked
 *********************************************************************************************************************/
/*! \brief       This function returns the currently read BmTxBufferArrayRamReadIdx
 *  \details     -
 *  \param[in]   bmTxBufferInstanceRomIdx   instance Idx.
 *  \param[out]  bmTxBufferArrayRamReadIdx  The BmTxBufferArrayRam read index
 *  \return      E_OK                       the read BmTxBufferArrayRamReadIdx is valid and can be used
 *               E_NOT_OK                   the read BmTxBufferArrayRamReadIdx is invalid and can not be used
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType* bmTxBufferArrayRamReadIdx);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init_TxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Init_TxBuffer(void)
{
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx;
  for(bmTxBufferRomIdx = 0u; bmTxBufferRomIdx < PduR_GetSizeOfBmTxBufferRam(); bmTxBufferRomIdx++)
  {
    PduR_Bm_ResetTxBuffer(bmTxBufferRomIdx);
  }
}
#endif

#if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init_TxBufferInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Init_TxBufferInstance(void)
{
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx;
  for(bmTxBufferInstanceRomIdx = 0u; bmTxBufferInstanceRomIdx < PduR_GetSizeOfBmTxBufferInstanceRam(); bmTxBufferInstanceRomIdx++)
  {
    PduR_Bm_ResetTxBufferInstance(bmTxBufferInstanceRomIdx);
  }
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamIterType bmLinearBufferSize = PduR_Bm_GetLinearBufferSize(bmTxBufferRomIdx);

  if(bmLinearBufferSize > pduLength)
  {
    PduR_Bm_Put_Between_WriteIdx_EndIdx(bmTxBufferRomIdx, pduLength, sduDataPtr); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  else if(bmLinearBufferSize == pduLength)
  {
    PduR_Bm_Put_Between_WriteIdx_EndIdx(bmTxBufferRomIdx, pduLength, sduDataPtr); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    if (PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx) != PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx)) /* COV_PDUR_IF_ONLY */
    {
      PduR_Bm_Switch_WriteIdx(bmTxBufferRomIdx);
    }
  }
  else if(PduR_Bm_GetTotalBufferSize(bmTxBufferRomIdx) >= pduLength)
  {
    PduR_Bm_PutData_WithWrapAround(bmTxBufferRomIdx, pduLength, sduDataPtr); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  else
  {
    /* Tp will never request more buffer than the PDUR has provided */
    retVal = BUFREQ_E_NOT_OK;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_EnableBmTxBufferInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_EnableBmTxBufferInstance(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  if(bmTxBufferInstanceRomIdx > PduR_GetBmTxBufferInstanceRomEndIdxOfBmTxBufferRom(bmTxBufferRomIdx))   /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_RMTP_ASSIGNASSOCIATEDBUFFER2DESTINATION, PDUR_E_FATAL);
  }
  else
  {
    PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearBufferSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearBufferSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferRamType bmTxBufferArrayRamReadIdxOfBmTxBufferRam = PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx);
  PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType bmTxBufferArrayRamWriteIdxOfBmTxBufferRam = PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx);

  switch (PduR_Bm_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      if (PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx) == bmTxBufferArrayRamReadIdxOfBmTxBufferRam)
      {
        retVal = PduR_Bm_GetInboundBmTxBufferArrayEndIdxOfBmTxBuffer(bmTxBufferRomIdx) - bmTxBufferArrayRamWriteIdxOfBmTxBufferRam;
      }
      else
      {
        retVal = (PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx)) - bmTxBufferArrayRamWriteIdxOfBmTxBufferRam;
      }
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = (bmTxBufferArrayRamReadIdxOfBmTxBufferRam - 1u) - bmTxBufferArrayRamWriteIdxOfBmTxBufferRam;
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:      /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      if (PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx) == bmTxBufferArrayRamReadIdxOfBmTxBufferRam)
      {
        retVal = PduR_Bm_GetInboundBmTxBufferArrayEndIdxOfBmTxBuffer(bmTxBufferRomIdx) - bmTxBufferArrayRamWriteIdxOfBmTxBufferRam;
      }
      else
      {
        retVal = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx) - bmTxBufferArrayRamWriteIdxOfBmTxBufferRam;
      }
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType, PDUR_CODE) PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamSafe(PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferInstanceRomIdx)
{
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx = PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx);

# if (PDUR_MIXED_ASIL_ERROR_CHECK == STD_ON) /* COV_PDUR_VAR_MIXED_ASIL_ERROR_CHECKS */
  PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRomType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PduR_BmTxBufferArrayRamStartIdxOfBmTxBufferRomType startIdxOfBuffer = PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);
  PduR_BmTxBufferArrayRamEndIdxOfBmTxBufferRomType endIdxOfBuffer = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx);

  if((bmTxBufferArrayRamReadIdx >= endIdxOfBuffer) && (bmTxBufferArrayRamReadIdx != PDUR_NO_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM))
  {
    bmTxBufferArrayRamReadIdx = endIdxOfBuffer - 1u;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
  if((bmTxBufferArrayRamReadIdx < startIdxOfBuffer) && (bmTxBufferArrayRamReadIdx != PDUR_NO_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM))
  {
    bmTxBufferArrayRamReadIdx = startIdxOfBuffer;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
# endif

  return bmTxBufferArrayRamReadIdx;
}
# endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr) /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx;

  if(PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(bmTxBufferInstanceRomIdx, &bmTxBufferArrayRamReadIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
  {
    switch (PduR_Bm_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, bmTxBufferArrayRamReadIdx))
    {
      case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
      {
        retVal = PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
        break;
      }
      case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
      case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
      {
        retVal = PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
        break;
      }
      case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:     /* COV_PDUR_ONLY_TT_SINGLE_BUFFER */
      {
        if(pduLength == 0u)
        {
          retVal = BUFREQ_OK;
        }
        else
        {
          /* nothing to do no data available */
          retVal = BUFREQ_E_BUSY;
        }
        break;
      }
      default:   /* COV_PDUR_MISRA */
        break;
    }
  }

  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType, PDUR_CODE) PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
{
  PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType bmTxBufferArrayRamWriteIdxOfBmTxBufferRam = PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx);

# if (PDUR_MIXED_ASIL_ERROR_CHECK == STD_ON) /* COV_PDUR_VAR_MIXED_ASIL_ERROR_CHECKS */
  PduR_BmTxBufferArrayRamStartIdxOfBmTxBufferRomType startIdxOfBuffer = PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);
  PduR_BmTxBufferArrayRamEndIdxOfBmTxBufferRomType endIdxOfBuffer = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx);

  if(bmTxBufferArrayRamWriteIdxOfBmTxBufferRam > endIdxOfBuffer)
  {
    bmTxBufferArrayRamWriteIdxOfBmTxBufferRam = endIdxOfBuffer - 1u;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
  if(bmTxBufferArrayRamWriteIdxOfBmTxBufferRam < startIdxOfBuffer)
  {
    bmTxBufferArrayRamWriteIdxOfBmTxBufferRam = startIdxOfBuffer;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
# endif

  return bmTxBufferArrayRamWriteIdxOfBmTxBufferRam;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Get_Between_ReadIdx_WriteIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Get_Between_ReadIdx_WriteIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                        CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx;

  if(PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(bmTxBufferInstanceRomIdx, &bmTxBufferArrayRamReadIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
  {
    /* ----- Development Error Checks ------------------------------------- */
    if((bmTxBufferArrayRamReadIdx + pduLength) > PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx)))   /* COV_PDUR_FATAL_ERROR */
    {
      errorId = PDUR_E_FATAL;
    }
    else
    {
      /* Dequeue Data */
      PduR_Core_MemCpyRamToRam(sduDataPtr, PduR_GetAddrBmTxBufferArrayRam(bmTxBufferArrayRamReadIdx), pduLength);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_RAM2RAM */
      PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, bmTxBufferArrayRamReadIdx + pduLength); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
  # if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_GET_BETWEEN_READIDX_WRITEIDX, errorId);
  }
  # endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE
 *********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData_StateHandler_BUFFER_FULL_OR_READ4WRITE(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx,
                                                                                                       PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamIterType bmLinearDataSizeInstance =  PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx);
  PduR_BmTxBufferArrayRamIterType bmTotalDataSizeInstance = PduR_Bm_GetTotalDataSizeInstance(bmTxBufferInstanceRomIdx);
  
  /* main Tx buffer element */
  if (bmLinearDataSizeInstance == pduLength)
  {
    if(bmLinearDataSizeInstance == bmTotalDataSizeInstance) /* COV_PDUR_IF_ONLY */
    {
      PduR_Bm_Get_Between_ReadIdx_EndIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    }
    else
    {
      PduR_Bm_Get_Between_ReadIdx_EndIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      PduR_Bm_Switch_InstanceReadIdx(bmTxBufferInstanceRomIdx);
    }
  }
  else if(bmLinearDataSizeInstance > pduLength)
  {
    PduR_Bm_Get_Between_ReadIdx_EndIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  else if(bmTotalDataSizeInstance >= pduLength)
  {
    PduR_Bm_GetData_WithWrapAround(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  else
  {
    retVal = BUFREQ_E_BUSY;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Get_Between_ReadIdx_EndIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Get_Between_ReadIdx_EndIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                      CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRomType bmTxBufferRomIdx;
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx;

  if(PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(bmTxBufferInstanceRomIdx, &bmTxBufferArrayRamReadIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
  {
    /* ----- Development Error Checks ------------------------------------- */
    if((bmTxBufferArrayRamReadIdx + pduLength) > (PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx))))   /* COV_PDUR_FATAL_ERROR */
    {
      errorId = PDUR_E_FATAL;
    }
    else
    {
      /* Dequeue Data */
      PduR_Core_MemCpyRamToRam(sduDataPtr, PduR_GetAddrBmTxBufferArrayRam(bmTxBufferArrayRamReadIdx), pduLength);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_RAM2RAM */
      bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);

      if ((bmTxBufferArrayRamReadIdx + pduLength) == PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx))
      {
        PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      }
      else
      {
        PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, (bmTxBufferArrayRamReadIdx + pduLength));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
      }
    }
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_GET_BETWEEN_READIDX_ENDIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ
 *********************************************************************************************************************/
/*!
 *Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_GetData_StateHandler_BUFFER_WRITE4READ(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                               CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamIterType bmLinearDataSizeInstance =  PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx);

  if(bmLinearDataSizeInstance >= pduLength)
  {
    PduR_Bm_Get_Between_ReadIdx_WriteIdx(bmTxBufferInstanceRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  else
  {
    /* not enough data available */
    retVal = BUFREQ_E_BUSY;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Put_Between_WriteIdx_ReadIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Put_Between_WriteIdx_ReadIdx(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType bmTxBufferArrayRamWriteIdxOfBmTxBufferRam = PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx);

  /* ----- Development Error Checks ------------------------------------- */
  if((bmTxBufferArrayRamWriteIdxOfBmTxBufferRam + pduLength) > PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx))      /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    /* Dequeue Data */
    PduR_Core_MemCpyRamToRam(PduR_GetAddrBmTxBufferArrayRam(bmTxBufferArrayRamWriteIdxOfBmTxBufferRam), sduDataPtr, pduLength);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_RAM2RAM */
    PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx, (bmTxBufferArrayRamWriteIdxOfBmTxBufferRam + pduLength));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_PUT_BETWEEN_WRITEIDX_READIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE
 *********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength,
                                                                                               CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamIterType bmLinearBufferSize = PduR_Bm_GetLinearBufferSize(bmTxBufferRomIdx);

  if(bmLinearBufferSize >= pduLength)
  {
    PduR_Bm_Put_Between_WriteIdx_ReadIdx(bmTxBufferRomIdx, pduLength, sduDataPtr);       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  }
  else
  {
    /* Not enough free buffer space available. Tp will never request more buffer than the PDUR has provided */
    retVal = BUFREQ_E_NOT_OK;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Put_Between_WriteIdx_EndIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Put_Between_WriteIdx_EndIdx(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)      /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint8 errorId = PDUR_E_NO_ERROR;      /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType bmTxBufferArrayRamWriteIdxOfBmTxBufferRam = PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx);

  /* ----- Development Error Checks ------------------------------------- */
  if((bmTxBufferArrayRamWriteIdxOfBmTxBufferRam + pduLength) > (PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx)))     /* COV_PDUR_FATAL_ERROR */
  {
    errorId = PDUR_E_FATAL;
  }
  else
  {
    /* Enqueue Data */
    PduR_Core_MemCpyRamToRam(PduR_GetAddrBmTxBufferArrayRam(bmTxBufferArrayRamWriteIdxOfBmTxBufferRam), sduDataPtr, pduLength);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_PDUR_MEM_CPY_RAM2RAM */
    PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx, (bmTxBufferArrayRamWriteIdxOfBmTxBufferRam + pduLength));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)        /* COV_PDUR_FATAL_ERROR */
  {
    PduR_Det_ReportError(PDUR_FCT_GW_BUFMGR_PUT_BETWEEN_WRITEIDX_ENDIDX, errorId);
  }
# endif
  PDUR_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_WriteIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_WriteIdx(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
{
  PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx, PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Switch_InstanceReadIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_Switch_InstanceReadIdx(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  /* main Tx buffer element */
  PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRomType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx));       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */

  PDUR_DUMMY_STATEMENT(bmTxBufferRomIdx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData_WithWrapAround
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_PutData_WithWrapAround(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, SduDataPtrType sduDataPtr)
{
  PduR_BmTxBufferArrayRamIterType pduLengthHead, pduLengthTail;
  pduLengthTail = PduR_Bm_GetLinearBufferSize(bmTxBufferRomIdx);
  pduLengthHead = pduLength - pduLengthTail;
  PduR_Bm_Put_Between_WriteIdx_EndIdx(bmTxBufferRomIdx, pduLengthTail, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_Bm_Switch_WriteIdx(bmTxBufferRomIdx);
  PduR_Bm_Put_Between_WriteIdx_ReadIdx(bmTxBufferRomIdx, pduLengthHead, &sduDataPtr[pduLengthTail]);     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetData_WithWrapAround
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_Bm_GetData_WithWrapAround(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, SduDataPtrType sduDataPtr)
{
  PduR_BmTxBufferArrayRamIterType pduLengthHead, pduLengthTail;
  pduLengthTail = PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx);
  pduLengthHead = pduLength - pduLengthTail;
  PduR_Bm_Get_Between_ReadIdx_EndIdx(bmTxBufferInstanceRomIdx, pduLengthTail, sduDataPtr);        /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
  PduR_Bm_Switch_InstanceReadIdx(bmTxBufferInstanceRomIdx);
  PduR_Bm_Get_Between_ReadIdx_WriteIdx(bmTxBufferInstanceRomIdx, pduLengthHead, &sduDataPtr[pduLengthTail]);    /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
}
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#if(PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_Init(void)
{
  /* Init Buffer manager */
  PduR_Bm_Init_TxBuffer();
  PduR_Bm_Init_TxBufferInstance();
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferRamType, PDUR_CODE) PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
{
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx;
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType slowestInstanceReadIndex = PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);
  PduR_BmTxBufferArrayRamIterType maxTotalDataSizeInstance = 0;

  for(bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);
      bmTxBufferInstanceRomIdx < PduR_GetBmTxBufferInstanceRomEndIdxOfBmTxBufferRom(bmTxBufferRomIdx); bmTxBufferInstanceRomIdx++)
  {
    PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx = 0;

    if(PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(bmTxBufferInstanceRomIdx, &bmTxBufferArrayRamReadIdx) == E_OK) /* PRQA S 2991 */ /* MD_PduR_2991 */ /* COV_PDUR_IF_ONLY */ /* SBSW_PDUR_STACK_VARIABLE */
    {
      PduR_BmTxBufferArrayRamIterType bmTotalDataSizeInstance = PduR_Bm_GetTotalDataSizeInstance(bmTxBufferInstanceRomIdx);

      if(bmTotalDataSizeInstance >= maxTotalDataSizeInstance) /* COV_PDUR_IF_ONLY */
      {
        maxTotalDataSizeInstance = bmTotalDataSizeInstance;   /* PRQA S 2983 */ /* MD_PduR_2983 */
        slowestInstanceReadIndex = bmTxBufferArrayRamReadIdx; /* maximum amount of data -> slowest read instance */
      }
    }
  }
  return slowestInstanceReadIndex;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetPduRBufferStateOfBmTxBufferInstanceRam
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_PduRBufferStateOfBmTxBufferInstanceRamType, PDUR_CODE) PduR_Bm_GetPduRBufferStateOfBmTxBufferInstanceRam(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx)
    {
      PduR_PduRBufferStateOfBmTxBufferInstanceRamType retVal;

      PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRomType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
      PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType bmTxBufferArrayRamWriteIdx = PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx);
      PduR_BmTxBufferArrayRamStartIdxOfBmTxBufferRomType bmTxBufferArrayRamStartIdx = PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);

      if(bmTxBufferArrayRamReadIdx == bmTxBufferArrayRamWriteIdx)
      {
        retVal = PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM;
      }
      else if (bmTxBufferArrayRamReadIdx == (bmTxBufferArrayRamWriteIdx + 1u))
      {
        retVal = PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM;
      }
      else if ((bmTxBufferArrayRamStartIdx == bmTxBufferArrayRamReadIdx) && (PduR_Bm_GetInboundBmTxBufferArrayEndIdxOfBmTxBuffer(bmTxBufferRomIdx) == bmTxBufferArrayRamWriteIdx))
      {
        retVal = PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM;
      }
      else if (bmTxBufferArrayRamReadIdx > bmTxBufferArrayRamWriteIdx)
      {
        retVal = PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM;
      }
      else /* (bmTxBufferArrayRamReadIdx < bmTxBufferArrayRamWriteIdx) */
      {
        retVal = PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM;
      }

      return retVal;
    }
# endif	
	
#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetPduRBufferStateOfBmTxBufferRam
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_PduRBufferStateOfBmTxBufferRamType, PDUR_CODE) PduR_Bm_GetPduRBufferStateOfBmTxBufferRam (PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
    {
      PduR_PduRBufferStateOfBmTxBufferRamType retVal;

      PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType bmTxBufferArrayRamWriteIdx = PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx);
      PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx = PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx);
      PduR_BmTxBufferArrayRamStartIdxOfBmTxBufferRomType bmTxBufferArrayRamStartIdx = PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);

      if(bmTxBufferArrayRamReadIdx == bmTxBufferArrayRamWriteIdx)
      {
        retVal = PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM;
      }
      else if (bmTxBufferArrayRamReadIdx == (bmTxBufferArrayRamWriteIdx + 1u))
      {
        retVal = PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM;
      }
      else if ((bmTxBufferArrayRamStartIdx == bmTxBufferArrayRamReadIdx) && (PduR_Bm_GetInboundBmTxBufferArrayEndIdxOfBmTxBuffer(bmTxBufferRomIdx) == bmTxBufferArrayRamWriteIdx))
      {
        retVal = PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM;
      }
      else if (bmTxBufferArrayRamReadIdx > bmTxBufferArrayRamWriteIdx)
      {
        retVal = PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM;
      }
      else /* (bmTxBufferArrayRamReadIdx < bmTxBufferArrayRamWriteIdx) */
      {
        retVal = PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM;
      }

      return retVal;
    }
# endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutData(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, PduR_BmTxBufferArrayRamIterType pduLength, CONST(SduDataPtrType, AUTOMATIC) sduDataPtr)
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_Bm_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx))
  {
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_PutData_StateHandler_BUFFER_EMPTY_OR_WRITE4READ(bmTxBufferRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_PutData_StateHandler_BUFFER_READ4WRITE(bmTxBufferRomIdx, pduLength, sduDataPtr);       /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      if(pduLength == 0u)
      {
        retVal = BUFREQ_OK;
      }
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }

  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_PutDataAsPtr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_PutDataAsPtr(PduR_BmTxBufferRomIterType bmTxBufferRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)      /* COV_PDUR_IF_ONLY */
{
  info->SduDataPtr = PduR_GetAddrBmTxBufferArrayRam(PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx));      /* SBSW_PDUR_STACK_VARIABLE */
  info->SduLength = (PduLengthType) PduR_Bm_GetLinearBufferSize(bmTxBufferRomIdx);    /* SBSW_PDUR_STACK_VARIABLE */
  return PduR_Bm_PutData(bmTxBufferRomIdx, info->SduLength, info->SduDataPtr);        /* SBSW_PDUR_STACK_VARIABLE */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_ResetTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_ResetTxBuffer(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)
{
  PduR_SetRxLengthOfBmTxBufferRam(bmTxBufferRomIdx, 0u);   /* SBSW_PDUR_CSL01 */
  PduR_SetAllocatedOfBmTxBufferRam(bmTxBufferRomIdx, FALSE); /* SBSW_PDUR_CSL01 */
  PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(bmTxBufferRomIdx, (PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(bmTxBufferRomIdx)));     /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
  PduR_Bm_ResetTxBufferInstance
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_ResetTxBufferInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)
{
  PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, PDUR_NO_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM); /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */ /* PRQA S 2841 */ /* MD_PduR_2841 */
}
#endif

#if ((PDUR_BMTXBUFFERRAM == STD_ON) && (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON))
/**********************************************************************************************************************
 * PduR_Bm_GetTotalDataSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalDataSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx) /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferRamType bmTxBufferArrayRamReadIdxOfBmTxBufferRam = PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx);

  switch (PduR_Bm_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:        /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx) - bmTxBufferArrayRamReadIdxOfBmTxBufferRam;
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM: /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal =
        PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(bmTxBufferRomIdx) - (bmTxBufferArrayRamReadIdxOfBmTxBufferRam -
                                                                             PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx));
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_GetLengthOfBmTxBuffer(bmTxBufferRomIdx);
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = 0u;
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetLinearDataSizeInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetLinearDataSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx) /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx;

  if(PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(bmTxBufferInstanceRomIdx, &bmTxBufferArrayRamReadIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
  {
    switch (PduR_Bm_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, bmTxBufferArrayRamReadIdx))
    {
      case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
      {
        retVal = PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx) - bmTxBufferArrayRamReadIdx;
        break;
      }
      case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
      {
        retVal = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx) - bmTxBufferArrayRamReadIdx;
        break;
      }
      case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
      {
        if ((PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx) + 1u) == bmTxBufferArrayRamReadIdx)
        {/* first full condition */
          retVal = PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(bmTxBufferRomIdx) - bmTxBufferArrayRamReadIdx;
        }
        else
        {/* second full condition */
          retVal = PduR_Bm_GetLengthOfBmTxBuffer(bmTxBufferRomIdx);
        }
        break;
      }
      case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:     /* COV_PDUR_BUFFER_CALCULATION */
      {
        retVal = 0u;
        break;
      }
      default:   /* COV_PDUR_MISRA */
        break;
    }
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PDUR_CODE) PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType* bmTxBufferArrayRamReadIdx)
{
  Std_ReturnType retVal;
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType readBmTxBufferArrayRamReadIdx = PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamSafe(bmTxBufferInstanceRomIdx);

  if (readBmTxBufferArrayRamReadIdx == PDUR_NO_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    *bmTxBufferArrayRamReadIdx = readBmTxBufferArrayRamReadIdx; /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    retVal = E_OK;
  }

  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalBufferSize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalBufferSize(PduR_BmTxBufferRomIterType bmTxBufferRomIdx)        /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

  switch (PduR_Bm_GetPduRBufferStateOfBmTxBufferRam(bmTxBufferRomIdx))
  {
    case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_GetLengthOfBmTxBuffer(bmTxBufferRomIdx) - (PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx) - PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx));
      break;
    }
    case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERRAM:        /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferRam(bmTxBufferRomIdx) - PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx) - (PduR_BmTxBufferArrayRamIterType) 1u;
      break;
    }
    case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERRAM:      /* COV_PDUR_BUFFER_CALCULATION */
    {
      retVal = 0u;
      break;
    }
    case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERRAM:
    {
      retVal = PduR_Bm_GetLengthOfBmTxBuffer(bmTxBufferRomIdx);
      break;
    }
    default:   /* COV_PDUR_MISRA */
      break;
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Bm_GetTotalDataSizeInstance
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_BmTxBufferArrayRamIterType, PDUR_CODE) PduR_Bm_GetTotalDataSizeInstance(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)  /* PRQA S 1505 */ /* MD_PduR_1505 */
{
  PduR_BmTxBufferArrayRamIterType retVal = 0u;  /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx);
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx = PduR_Bm_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamSafe(bmTxBufferInstanceRomIdx);

  if(PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(bmTxBufferInstanceRomIdx, &bmTxBufferArrayRamReadIdx) == E_OK) /* COV_PDUR_ROBUSTNESS */ /* SBSW_PDUR_STACK_VARIABLE */
  {
    switch (PduR_Bm_GetPduRBufferStateOfBmTxBufferInstanceRam(bmTxBufferInstanceRomIdx, bmTxBufferArrayRamReadIdx))
    {
      case PDUR_BUFFER_WRITE4READ_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:        /* COV_PDUR_BUFFER_CALCULATION */
      {
        retVal = PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx) - bmTxBufferArrayRamReadIdx;
        break;
      }
      case PDUR_BUFFER_READ4WRITE_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
      {
          retVal =
            (PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx))) -
            (bmTxBufferArrayRamReadIdx - PduR_Bm_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRamSafe(bmTxBufferRomIdx));
        break;
      }
      case PDUR_BUFFER_FULL_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:
      {
        retVal = PduR_Bm_GetLengthOfBmTxBuffer(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx));
        break;
      }
      case PDUR_BUFFER_EMPTY_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM:     /* COV_PDUR_BUFFER_CALCULATION */
      {
        retVal = 0u;
        break;
      }
      default:   /* COV_PDUR_MISRA */
        break;
    }
  }
  return retVal;
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON )
/**********************************************************************************************************************
 * PduR_Bm_AllocateTxBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Bm_AllocateTxBuffer(PduR_FmFifoRomIterType fmFifoRomIdx,
                                                            PduLengthType pduLength,
                                                            PduLengthType metaDataLength,
                                                            P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr,
                                                            P2VAR(PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType, AUTOMATIC, PDUR_APPL_DATA) allocatedTxBufferIdxPtr,
                                                            boolean considerSmallerBuffer)
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* Get the assigned FifoElement */
  PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType lastSuitableBmTxBufferRomIdx = 0u;
  boolean lastSuitableBmTxBufferRomIdxFound = FALSE;
  PduR_BmTxBufferIndRomIterType bmTxBufferRomIndIdx;

  {
    PduR_BmTxBufferIndRomIterType bmTxBufferRomIndStartId = PduR_GetBmTxBufferIndRomStartIdxOfFmFifoRom(fmFifoRomIdx);
    PduR_BmTxBufferIndRomIterType bmTxBufferRomIndEndIdx = PduR_GetBmTxBufferIndRomEndIdxOfFmFifoRom(fmFifoRomIdx);

# if (PDUR_SPINLOCKRAM == STD_ON)
    PduR_Lock_LockBuffersByFmFifo(fmFifoRomIdx);
# endif
    {
      for(bmTxBufferRomIndIdx = bmTxBufferRomIndStartId; bmTxBufferRomIndIdx < bmTxBufferRomIndEndIdx; bmTxBufferRomIndIdx++) /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
      {
        PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfBmTxBufferIndRom(bmTxBufferRomIndIdx);
        /* Buffer available? */
        if(!PduR_IsAllocatedOfBmTxBufferRam(bmTxBufferRomIdx)) /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
        {
          if(PduR_Bm_GetLengthOfBmTxBuffer(bmTxBufferRomIdx) >= ((PduR_BmTxBufferArrayRamIterType) pduLength + (PduR_BmTxBufferArrayRamIterType) metaDataLength)) /* COV_PDUR_IF_SDU_LENGTH_HANDLING */
          {
            /* Initialize buffer and assign to FifoElement */
            PduR_SetAllocatedOfBmTxBufferRam(bmTxBufferRomIdx, TRUE);     /* SBSW_PDUR_CSL03 */
            PduR_SetRxLengthOfBmTxBufferRam(bmTxBufferRomIdx, pduLength); /* SBSW_PDUR_CSL03 */
            *allocatedTxBufferIdxPtr = bmTxBufferRomIdx; /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
            /* Assign amount of available buffer */
            *bufferSizePtr = (PduLengthType) PduR_Bm_GetLengthOfBmTxBuffer(bmTxBufferRomIdx); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
            retVal = BUFREQ_OK;
            break;
          }
          else if(considerSmallerBuffer == TRUE) /* COV_PDUR_MISRA */
          {
            /* This buffer is not large enough to hold the complete message but the buffer is available and could be used in case no other buffer is available. Reason: the buffer is large enough to hold at least one tpChunk. */
            lastSuitableBmTxBufferRomIdx = bmTxBufferRomIdx;
            lastSuitableBmTxBufferRomIdxFound = TRUE;
          }
          else
          {
            /* nothing to be done */
          }
        }
      }
      /* No suitable buffer found which is large enough to store the full TP PDU. Use ring buffer mechanism (routing-on-the-fly) instead. */
      if(retVal != BUFREQ_OK) /* COV_PDUR_IF_SDU_LENGTH_HANDLING */
      {
        /* The received TP PDU is larger than the largest available TP buffer element. The routing is executed using a ring buffer mechanism (routing on the fly) that allows a smaller receive buffer. */
        if(lastSuitableBmTxBufferRomIdxFound == TRUE) /* COV_PDUR_IF_SDU_LENGTH_HANDLING */
        {
          /* Routing is possible, but the gateway will use the ring-buffer mechanism to perform routing. Routing must not be 1:N routing. */
          /* Initialize buffer and assign to FifoElement */
          PduR_SetAllocatedOfBmTxBufferRam(lastSuitableBmTxBufferRomIdx, TRUE);     /* SBSW_PDUR_CSL03 */
          PduR_SetRxLengthOfBmTxBufferRam(lastSuitableBmTxBufferRomIdx, pduLength); /* SBSW_PDUR_CSL03 */
          *allocatedTxBufferIdxPtr = lastSuitableBmTxBufferRomIdx; /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
          /* Assign amount of available buffer */
          *bufferSizePtr = (PduLengthType) PduR_Bm_GetTotalBufferSize(lastSuitableBmTxBufferRomIdx); /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
          retVal = BUFREQ_OK;
        }
        else
        {
          /* Currently no buffer is available that would allow routing of a routing relation with the configured chunk size. 1:N routing relations can only be routed if a buffer of the I-PDU size is available. 1:1 routing relation can be routed principally but not at the current time. Prevented by validation! */
          retVal = BUFREQ_E_NOT_OK;
        }
      }
    }
# if (PDUR_SPINLOCKRAM == STD_ON)
    PduR_Lock_UnlockBuffersByFmFifo(fmFifoRomIdx);
# endif
  }
  return retVal;
}       /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON )
/**********************************************************************************************************************
 * PduR_Bm_CopyDataAsPtr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Bm_CopyDataAsPtr(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduR_BmTxBufferArrayRamIterType length)    /* COV_PDUR_ONLY_TT_SINGLE_BUFFER */
{
  PduR_BmTxBufferArrayRamIterType bmLinearDataSizeInstance;
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType bmTxBufferArrayRamReadIdx;

  if(PduR_Bm_GetBmTxBufferArrayRamReadIdxByBmTxBufferInstanceRomIdxChecked(bmTxBufferInstanceRomIdx, &bmTxBufferArrayRamReadIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
  {
    info->SduDataPtr = PduR_GetAddrBmTxBufferArrayRam(bmTxBufferArrayRamReadIdx);        /* SBSW_PDUR_STACK_VARIABLE */
    bmLinearDataSizeInstance = PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx);

    if(length > bmLinearDataSizeInstance)      /* COV_PDUR_ROBUSTNESS */
    {
      info->SduLength = (PduLengthType) bmLinearDataSizeInstance;      /* SBSW_PDUR_STACK_VARIABLE */
    }
    else
    {
      info->SduLength = (PduLengthType) length;   /* SBSW_PDUR_STACK_VARIABLE */
    }
  }
}
#endif

#if (PDUR_BMTXBUFFERRAM == STD_ON )
/**********************************************************************************************************************
 * PduR_Bm_GetActualPduLengthToBeRouted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduLengthType, PDUR_CODE) PduR_Bm_GetActualPduLengthToBeRouted(PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx)     /* COV_PDUR_IF_ONLY */
{
  return PduR_GetRxLengthOfBmTxBufferRam(PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(bmTxBufferInstanceRomIdx));
}

#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */

/* module specific MISRA deviations:
     MD_PduR_2841: Dereference of an invalid pointer value.
     Reason:       QAC cannot determine whether the pointer value is correct. The callers of this function guarantee, that the index is always in bound.
     Risk:         No risk.
     Prevention:   No prevention necessary.
*/

/* *INDENT-ON* */
/**********************************************************************************************************************
 *  END OF FILE: PduR_Bm.c
 *********************************************************************************************************************/
