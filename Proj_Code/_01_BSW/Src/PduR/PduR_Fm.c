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
 *         File:  PduR_Fm.c
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
/* PRQA  S 4304 EOF */ /* MD_MSR_AutosarBoolean */
/* *INDENT-ON* */

#define PDUR_FM_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Bm.h"
#include "PduR_Fm.h"
#include "PduR_RmTp.h"
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

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

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetBmTxBufferRomIdxOfFmFifoElementRamSafe
 *********************************************************************************************************************/
 /*! \brief       Get the bmTxBuffer index of the fmFifoElement
 *   \details     -
 *   \param[in]   fmFifoElementRamIdx   Index of the FIFO element in Ram.
 *   \return                            bmTxBuffer index
 *   \pre         -
 *   \context     TASK|ISR1|ISR2
 *   \reentrant   TRUE
 *   \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferRomIdxOfFmFifoElementRamType, PDUR_CODE) PduR_Fm_GetBmTxBufferRomIdxOfFmFifoElementRamSafe(PduR_FmFifoElementRamIterType fmFifoElementRamIdx);
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRamSafe
 *********************************************************************************************************************/
/*! \brief       Gets the bmTxBufferInstance index of the fmFifoInstance with error checking
 *  \details     -
 *  \param[in]   fmFifoInstanceRomIdx   fmFifoInstance index
 *  \return                             bmTxBufferInstance index
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferInstanceRomIterType, PDUR_CODE) PduR_Fm_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRamSafe(PduR_FmFifoInstanceRomIterType fmFifoInstanceRomIdx);
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetFillLevelSafe
 *********************************************************************************************************************/
/*! \brief       Gets the fill level with error detection.
 *  \details     -
 *  \param[in]   fmFifoRamIdx    Id of the Fifo
 *  \return                      the fill level
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint16, PDUR_CODE) PduR_Fm_GetFillLevelSafe(PduR_FmFifoRamIterType fmFifoRamIdx);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if(PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_Init(void)
{
  {
    PduR_FmFifoRamIterType fmFifoRamIdx;
    for(fmFifoRamIdx = 0u; fmFifoRamIdx < PduR_GetSizeOfFmFifoRam(); fmFifoRamIdx++)
    {
# if(PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
      PduR_SetTpTxSmStateOfFmFifoRam(fmFifoRamIdx, PDUR_RM_TX_IDLE_TPTXSMSTATEOFFMFIFORAM);     /* SBSW_PDUR_CSL01 */
# endif
      PduR_SetPendingConfirmationsOfFmFifoRam(fmFifoRamIdx, 0u);        /* SBSW_PDUR_CSL01 */
      PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx, PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx));      /* SBSW_PDUR_CSL01 */
      PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRamIdx, PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx));     /* SBSW_PDUR_CSL01 */
      PduR_SetFillLevelOfFmFifoRam(fmFifoRamIdx, 0u);   /* SBSW_PDUR_CSL01 */
    }
  }
  {
    PduR_FmFifoElementRamIterType fmFifoElementRamIdx;
    for(fmFifoElementRamIdx = 0u; fmFifoElementRamIdx < PduR_GetSizeOfFmFifoElementRam(); fmFifoElementRamIdx++)
    {
      PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_NO_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM);      /* SBSW_PDUR_CSL01 */
      PduR_SetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, 0);      /* SBSW_PDUR_CSL01 */
    }
  }
  {
    PduR_FmFifoInstanceRamIterType fmFifoInstanceRamIdx;
    for(fmFifoInstanceRamIdx = 0u; fmFifoInstanceRamIdx < PduR_GetSizeOfFmFifoInstanceRam(); fmFifoInstanceRamIdx++)
    {
      PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(fmFifoInstanceRamIdx, PDUR_NO_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM);   /* SBSW_PDUR_CSL01 */
    }
  }
}
#endif

#if (PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_Peek
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
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_Peek(PduR_FmFifoRamIterType fmFifoRamIdx, P2VAR(PduR_FmFifoElementRamIterType, AUTOMATIC, PDUR_APPL_DATA) fmFifoElementRamIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* FifoElements in the queue? */
  while(PduR_Fm_GetFillLevelSafe(fmFifoRamIdx) > 0u)
  {
    PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_Fm_IncrementReadIndex(fmFifoRamIdx);

    if(PduR_Fm_IsFifoElementAllocated(fmFifoElementRamReadIdx) == E_OK)
    {
      *fmFifoElementRamIdx = fmFifoElementRamReadIdx;   /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
      retVal = E_OK;
      break;
    }
  }
  return retVal;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_IsFifoElementAllocated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
*********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_IsFifoElementAllocated(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx;

  /* Is a TxBuffer assigned to the FifoElement? */
  return PduR_Fm_GetCurrentlyUsedBmTxBufferRomIdxByFmFifoElementIdx(fmFifoElementRamIdx, &bmTxBufferRomIdx); /* SBSW_PDUR_STACK_VARIABLE */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_AssignTxBuffer2FifoElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_AssignTxBuffer2FifoElement(PduR_FmFifoElementRamIterType fmFifoElementRamWriteIdx, PduR_BmTxBufferRomIdxOfFmFifoElementRamType bmTxBufferRomIdx)
{
  PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx, bmTxBufferRomIdx);       /* SBSW_PDUR_CSL03 */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_ReleaseFifoElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_ReleaseFifoElement(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_BmTxBufferRomIterType bmTxBufferRomIdx;

  /* Reset (optional) referenced TxBuffer */
  if(PduR_Fm_GetCurrentlyUsedBmTxBufferRomIdxByFmFifoElementIdx(fmFifoElementRamIdx, &bmTxBufferRomIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
  {
    PduR_Bm_ResetTxBuffer(bmTxBufferRomIdx);
  }

  PduR_SetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, 0);  /* SBSW_PDUR_CSL03 */
  /* Release Tx buffer Fifo Element connection */
  PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx, PDUR_NO_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM);  /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetCurrentlyUsedBmTxBufferRomIdxByFmFifoElementIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_GetCurrentlyUsedBmTxBufferRomIdxByFmFifoElementIdx(PduR_FmFifoElementRamIterType fmFifoElementRamIdx, P2VAR(PduR_BmTxBufferRomIterType, AUTOMATIC, PDUR_APPL_DATA) bmTxBufferRomIdx)
{
  Std_ReturnType retVal;
  PduR_BmTxBufferRomIterType readBmTxBufferRomIdx = PduR_Fm_GetBmTxBufferRomIdxOfFmFifoElementRamSafe(fmFifoElementRamIdx);

  if(readBmTxBufferRomIdx == PDUR_NO_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    *bmTxBufferRomIdx = readBmTxBufferRomIdx; /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    retVal = E_OK;
  }

  return retVal;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetBmTxBufferRomIdxOfFmFifoElementRamSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferRomIdxOfFmFifoElementRamType, PDUR_CODE) PduR_Fm_GetBmTxBufferRomIdxOfFmFifoElementRamSafe(PduR_FmFifoElementRamIterType fmFifoElementRamIdx)
{
  PduR_BmTxBufferRomIdxOfFmFifoElementRamType bmTxBufferRomIdx = PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(fmFifoElementRamIdx);

# if (PDUR_MIXED_ASIL_ERROR_CHECK == STD_ON) /* COV_PDUR_VAR_MIXED_ASIL_ERROR_CHECKS */
  PduR_SizeOfBmTxBufferInstanceRomType sizeOfBmTxBufferRom = PduR_GetSizeOfBmTxBufferRom();

  if((bmTxBufferRomIdx >= sizeOfBmTxBufferRom) && (bmTxBufferRomIdx != PDUR_NO_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM))
  {
    bmTxBufferRomIdx = 0;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
# endif

  return bmTxBufferRomIdx;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRamSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(PduR_BmTxBufferInstanceRomIterType, PDUR_CODE) PduR_Fm_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRamSafe(PduR_FmFifoInstanceRomIterType fmFifoInstanceRomIdx)
{
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(fmFifoInstanceRomIdx);

# if (PDUR_MIXED_ASIL_ERROR_CHECK == STD_ON) /* COV_PDUR_VAR_MIXED_ASIL_ERROR_CHECKS */
  PduR_SizeOfBmTxBufferInstanceRomType sizeOfBmTxBufferInstanceRom = PduR_GetSizeOfBmTxBufferInstanceRom();

  if((bmTxBufferInstanceRomIdx >= sizeOfBmTxBufferInstanceRom) && (bmTxBufferInstanceRomIdx != PDUR_NO_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM))
  {
    bmTxBufferInstanceRomIdx = 0;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
# endif

  return bmTxBufferInstanceRomIdx;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetCurrentlyUsedBmTxBufferInstanceIdxByRmGDestIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
  *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_GetCurrentlyUsedBmTxBufferInstanceIdxByRmGDestIdx(PduR_RmGDestRomIterType rmGDestRomIdx, P2VAR(PduR_BmTxBufferInstanceRomIterType, AUTOMATIC, PDUR_APPL_DATA) bmTxBufferInstanceRomIdx)
{
  Std_ReturnType retVal;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_BmTxBufferInstanceRomIterType readBmTxBufferInstanceRomIdxOfFmFifoInstance = PduR_Fm_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRamSafe(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));

  if(readBmTxBufferInstanceRomIdxOfFmFifoInstance == PDUR_NO_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM) /* COV_PDUR_ROBUSTNESS */
  {
    retVal = E_NOT_OK;
  }
  else
  {
    *bmTxBufferInstanceRomIdx = readBmTxBufferInstanceRomIdxOfFmFifoInstance; /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    retVal = E_OK;
  }

  return retVal;
}
#endif

# if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_IncrementReadIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
  *********************************************************************************************************************/
FUNC(PduR_FmFifoElementRamIterType, PDUR_CODE) PduR_Fm_IncrementReadIndex(PduR_FmFifoRamIterType fmFifoRamIdx)
{
  PduR_FmFifoElementRamReadIdxOfFmFifoRamType fmFifoElementRamReadIdx = PduR_Fm_GetFmFifoElementRamReadIdxOfFmFifoRamSafe(fmFifoRamIdx);

  /* Get next element */
  if(fmFifoElementRamReadIdx >= ((PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRamIdx) - 1u)))
  {
    /* Wrap-around */
    fmFifoElementRamReadIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx);
  }
  else
  {
    fmFifoElementRamReadIdx++;
  }
  PduR_DecFillLevelOfFmFifoRam(fmFifoRamIdx);       /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */
  PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx, fmFifoElementRamReadIdx);      /* SBSW_PDUR_IDX_PARAM_INTERNAL_FUNCTION */

  return fmFifoElementRamReadIdx;
}
#endif

# if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_IncrementWriteIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
  *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_IncrementWriteIndex(PduR_FmFifoRamIterType fmFifoRamIdx)
{
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamWriteIdx = PduR_Fm_GetFmFifoElementRamWriteIdxSafe(fmFifoRamIdx); /* PRQA S 2842 */ /* MD_PduR_2842 */

  /* Get next fifo element */ /* Check if the write Idx is at the end (EndIdx -1) */
  if(fmFifoElementRamWriteIdx >= (PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRamIdx) - 1u))      /* COV_PDUR_ONLY_SHARED_OR_DEDICATED_BUFFER */
  {
    /* Wrap-around */
    fmFifoElementRamWriteIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx);
  }
  else
  {
    fmFifoElementRamWriteIdx++;
  }
  /* Update global FifoElement write pointer. This pointer points to the next available Fifo element. */
  PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRamIdx, fmFifoElementRamWriteIdx);        /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL03 */
}
#endif

/**********************************************************************************************************************
 * PduR_Fm_PutFifo
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
#if (PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_PutFifo(PduR_RmGDestRomIterType rmGDest, PduR_RmDestRomIterType rmDest, PduLengthType pduLength, SduDataPtrType sduDataPtr)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDest));
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType fmFifoElementRamWriteIdx = PduR_Fm_GetFmFifoElementRamWriteIdxSafe(fmFifoRomIdx);

  if(PduR_Fm_IsFifoElementAllocated(fmFifoElementRamWriteIdx) != E_OK)
  {
    PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType allocatedTxBufferIdxPtr = 0u;
    PduLengthType bufferSizePtr = 0u;

    if(PduR_Bm_AllocateTxBuffer(fmFifoRomIdx, pduLength, 0u, &bufferSizePtr, &allocatedTxBufferIdxPtr, FALSE) == BUFREQ_OK)     /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    {
      PduR_IncFillLevelOfFmFifoRam(fmFifoRomIdx); /* SBSW_PDUR_CSL03 */
      PduR_Fm_IncrementWriteIndex(fmFifoRomIdx);

      PduR_Fm_AssignTxBuffer2FifoElement(fmFifoElementRamWriteIdx, allocatedTxBufferIdxPtr);
      PduR_SetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamWriteIdx, (PduR_RmDestRomIdxOfFmFifoElementRamType) rmDest);   /* SBSW_PDUR_CSL01 */

      {
        PduR_BmTxBufferRomIterType bmTxBufferRomIdx;

        if(PduR_Fm_GetCurrentlyUsedBmTxBufferRomIdxByFmFifoElementIdx(fmFifoElementRamWriteIdx, &bmTxBufferRomIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
        {
          (void) PduR_Bm_PutData(bmTxBufferRomIdx, pduLength, sduDataPtr);      /* SBSW_PDUR_STACK_VARIABLE */
          retVal = E_OK;
        }
      }
    }
  }
  return retVal;
}
#endif

#if (PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_RemoveElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_RemoveElement(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_FmFifoRamIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_Fm_GetFmFifoElementRamReadIdxOfFmFifoRamSafe(fmFifoRomIdx);
  PduR_BmTxBufferInstanceRomIterType bmTxBufferInstanceRomIdx;

  PduR_Fm_ReleaseFifoElement(fmFifoElementRamReadIdx);
  if(PduR_Fm_GetCurrentlyUsedBmTxBufferInstanceIdxByRmGDestIdx(rmGDestRomIdx, &bmTxBufferInstanceRomIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
  {
    PduR_Bm_ResetTxBufferInstance(bmTxBufferInstanceRomIdx);
  }
  (void) PduR_Fm_IncrementReadIndex(fmFifoRomIdx);
}
#endif

#if (PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetNextElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_GetNextElement(PduR_RmGDestRomIterType rmGDestRomIdx, P2VAR(PduR_RmDestRomIterType, AUTOMATIC, PDUR_APPL_DATA) rmDestRomIdx, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_FmFifoElementRamIterType fmFifoElementRamReadIdx = PduR_Fm_GetFmFifoElementRamReadIdxOfFmFifoRamSafe(PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx)));

  if(PduR_Fm_IsFifoElementAllocated(fmFifoElementRamReadIdx) == E_OK)
  {
    PduR_BmTxBufferRomIterType bmTxBufferRomIdx;

    if(PduR_Fm_GetCurrentlyUsedBmTxBufferRomIdxByFmFifoElementIdx(fmFifoElementRamReadIdx, &bmTxBufferRomIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
    {
      PduR_BmTxBufferInstanceRomStartIdxOfBmTxBufferRomType bmTxBufferInstanceRomIdx = PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(bmTxBufferRomIdx);

      PduR_Bm_EnableBmTxBufferInstance(bmTxBufferRomIdx, bmTxBufferInstanceRomIdx);
      PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx), bmTxBufferInstanceRomIdx);       /* SBSW_PDUR_CSL03 */

      if(PduR_Fm_GetRmDestRomIdxOfFmFifoElementRamSafe(fmFifoElementRamReadIdx, rmDestRomIdx) == E_OK) /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */ /* COV_PDUR_ROBUSTNESS */ /* PRQA S 2995, 2991 */ /* MD_PduR_2995_2996, MD_PduR_2991 */
      {
        PduR_Bm_CopyDataAsPtr(bmTxBufferInstanceRomIdx, info, PduR_Bm_GetLinearDataSizeInstance(bmTxBufferInstanceRomIdx));       /* SBSW_PDUR_API_CALL_FORWARDING_ID_AND_PTR */
        retVal = E_OK;
      }
    }
  }

  return retVal;
}
#endif

#if (PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetFillLevel
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(uint16, PDUR_CODE) PduR_Fm_GetFillLevel(PduR_RmGDestRomIterType rmGDestRomIdx) /* COV_PDUR_NO_DEFERRED_IF_ROUTING */
{
  return PduR_Fm_GetFillLevelSafe(PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx)));
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetFillLevelSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(uint16, PDUR_CODE) PduR_Fm_GetFillLevelSafe(PduR_FmFifoRamIterType fmFifoRamIdx) /* COV_PDUR_NO_DEFERRED_IF_ROUTING */
{
  uint16 fillLevel = PduR_GetFillLevelOfFmFifoRam(fmFifoRamIdx);

# if (PDUR_MIXED_ASIL_ERROR_CHECK == STD_ON) /* COV_PDUR_VAR_MIXED_ASIL_ERROR_CHECKS */
  PduR_FmFifoElementRamLengthOfFmFifoRomType fifoDepth = PduR_GetFmFifoElementRamLengthOfFmFifoRom(fmFifoRamIdx);

  if(fillLevel > fifoDepth)
  {
    fillLevel = fifoDepth;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
# endif

  return fillLevel;
}
#endif

#if (PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_FlushFiFo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Fm_FlushFiFo(PduR_RmGDestRomIterType rmGDestRomIdx)
{
  PduR_FmFifoRomIterType fmFifoRomIdx = PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(rmGDestRomIdx));
  PduR_FmFifoElementRamIterType fmFifoElementRamIdx;

  for(fmFifoElementRamIdx = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx); fmFifoElementRamIdx < PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRomIdx); fmFifoElementRamIdx++)
  {
    PduR_BmTxBufferRomIterType bmTxBufferRomIdx;

    /* Reset (optional) referenced TxBuffer */
    if(PduR_Fm_GetCurrentlyUsedBmTxBufferRomIdxByFmFifoElementIdx(fmFifoElementRamIdx, &bmTxBufferRomIdx) == E_OK) /* SBSW_PDUR_STACK_VARIABLE */ /* COV_PDUR_ROBUSTNESS */
    {
      PduR_Bm_ResetTxBuffer(bmTxBufferRomIdx);
      PduR_Bm_ResetTxBufferInstance(PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(bmTxBufferRomIdx));
    }
    PduR_Fm_ReleaseFifoElement(fmFifoElementRamIdx);
  }
  PduR_SetFillLevelOfFmFifoRam(fmFifoRomIdx, 0u);       /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL02 */
  PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRomIdx, PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx));  /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL02 */
  PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRomIdx, PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRomIdx)); /* PRQA S 2842 */ /* MD_PduR_2842 */ /* SBSW_PDUR_CSL02 */
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetFmFifoElementRamReadIdxOfFmFifoRamSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_FmFifoElementRamReadIdxOfFmFifoRamType, PDUR_CODE) PduR_Fm_GetFmFifoElementRamReadIdxOfFmFifoRamSafe(PduR_FmFifoRamIterType fmFifoRamIdx)
{
  PduR_FmFifoElementRamReadIdxOfFmFifoRamType readIdx = PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(fmFifoRamIdx);

# if (PDUR_MIXED_ASIL_ERROR_CHECK == STD_ON) /* COV_PDUR_VAR_MIXED_ASIL_ERROR_CHECKS */
  PduR_FmFifoElementRamStartIdxOfFmFifoRomType startIdxOfBuffer = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx);
  PduR_FmFifoElementRamEndIdxOfFmFifoRomType endIdxOfBuffer = PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRamIdx);

  if(readIdx >= endIdxOfBuffer)
  {
    readIdx = endIdxOfBuffer - 1u;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
  if(readIdx < startIdxOfBuffer)
  {
    readIdx = startIdxOfBuffer;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
# endif

  return readIdx;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetFmFifoElementRamWriteIdxSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(PduR_FmFifoElementRamWriteIdxOfFmFifoRamType, PDUR_CODE) PduR_Fm_GetFmFifoElementRamWriteIdxSafe(PduR_FmFifoRamIterType fmFifoRamIdx)
{
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType writeIdx = PduR_GetFmFifoElementRamWriteIdxOfFmFifoRam(fmFifoRamIdx);

# if (PDUR_MIXED_ASIL_ERROR_CHECK == STD_ON) /* COV_PDUR_VAR_MIXED_ASIL_ERROR_CHECKS */
  PduR_FmFifoElementRamStartIdxOfFmFifoRomType startIdxOfBuffer = PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(fmFifoRamIdx);
  PduR_FmFifoElementRamEndIdxOfFmFifoRomType endIdxOfBuffer = PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(fmFifoRamIdx);

  if(writeIdx >= endIdxOfBuffer)
  {
    writeIdx = endIdxOfBuffer - 1u;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
  if(writeIdx < startIdxOfBuffer)
  {
    writeIdx = startIdxOfBuffer;
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
  }
# endif

  return writeIdx;
}
#endif

#if (PDUR_FMFIFORAM == STD_ON)
/**********************************************************************************************************************
 * PduR_Fm_GetRmDestRomIdxOfFmFifoElementRamSafe
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Fm_GetRmDestRomIdxOfFmFifoElementRamSafe(PduR_FmFifoElementRamIterType fmFifoElementRamIdx, P2VAR(PduR_RmDestRomIterType, AUTOMATIC, PDUR_APPL_DATA) rmDestRomIdx)
{
  Std_ReturnType retVal = E_NOT_OK;     /* PRQA S 2981 */ /* MD_MSR_RetVal */
  PduR_RmDestRomIdxOfFmFifoElementRamType readRmDestRomIdx = PduR_GetRmDestRomIdxOfFmFifoElementRam(fmFifoElementRamIdx);

# if (PDUR_MIXED_ASIL_ERROR_CHECK == STD_ON) /* COV_PDUR_VAR_MIXED_ASIL_ERROR_CHECKS */
  if(readRmDestRomIdx >= PduR_GetSizeOfRmDestRom())
  {
    PduR_ReportRuntimeDetError(0xAAu, 0xAAu);
    retVal = E_NOT_OK;
  }
  else
# endif
  {
    *rmDestRomIdx = readRmDestRomIdx; /* SBSW_PDUR_VALID_PTR_ENSURED_BY_CALLING_FUNCTION */
    retVal = E_OK;
  }

  return retVal;
}
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: PduR_Fm.c
 *********************************************************************************************************************/
