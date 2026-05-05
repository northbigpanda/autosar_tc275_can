/* ********************************************************************************************************************
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
 */
/*! \addtogroup Dem_IumprIF
 *  \{
 *  \file       Dem_IumprIF_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of the Obd Iumpr subcomponent which manages calculation of the IUMPR ratios.
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vector Informatik GmbH
 *  Anna Bosch                    visanh        Vector Informatik GmbH
 *  Stefan Huebner                vishrs        Vector Informatik GmbH
 *  Thomas Dedler                 visdth        Vector Informatik GmbH
 *  Alexander Ditte               visade        Vector Informatik GmbH
 *  Matthias Heil                 vismhe        Vector Informatik GmbH
 *  Erik Jeglorz                  visejz        Vector Informatik GmbH
 *  Friederike Schulze            visfrs        Vector Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vector Informatik GmbH
 *  Fabian Wild                   viszfa        Vector Informatik GmbH
 *  Erwin Stamm                   visern        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_IUMPRIF_IMPLEMENTATION_H)
#define DEM_IUMPRIF_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_IumprIF_Interface.h"

/* ------------------------------------------------------------------------- */
#include "Dem_Cfg_Definitions.h"
#include "Dem_Mem_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Filename declaration */
#define DEM_IUMPRIF_IMPLEMENTATION_FILENAME "Dem_IumprIF_Implementation.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_IumprIF_Properties
 * \{
 */


/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_IumprIF_Private
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_IumprIF_Public
 * \{
 */

#if ((DEM_FEATURE_NEED_IUMPR == STD_ON) && (DEM_CFG_SUPPORT_500MI_DENOMINATOR == STD_ON))
/* ****************************************************************************
% Dem_IumprIF_Test500MileDenominatorConfigured()
*****************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_IumprIF_Test500MileDenominatorConfigured(
  void
  )
{
  boolean lRetVal;

  lRetVal = (boolean)(Dem_Cfg_GetSizeOfStartIdx500miDenRatioTable() != 0U);  
  return lRetVal;
}
#endif

#if ((DEM_FEATURE_NEED_IUMPR == STD_ON) && (DEM_CFG_SUPPORT_500MI_DENOMINATOR == STD_ON))
/* ****************************************************************************
% Dem_IumprIF_Update500MileGeneralDenominatorReached()
*****************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_IumprIF_Update500MileGeneralDenominatorReached(
  void
  )
{
  uint8 lRatioStatus;
  Dem_RatioIdIndexType lRatioIndex;
  Dem_Cfg_ObdRatioIdIterType lRatioIter;

  /* Update the general denominator condition reached status of all 500 miles denominators */
  for (Dem_Cfg_Obd500MileDenominatorIterInit(&lRatioIter);                                                                       /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_Obd500MileDenominatorIterExists(&lRatioIter) == TRUE;                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_Obd500MileDenominatorIterNext(&lRatioIter))                                                                       /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
    
    lRatioIndex = Dem_Cfg_Obd500MileDenominatorIterGet(&lRatioIter);                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */
    lRatioStatus = Dem_Mem_GetIumprStatus(lRatioIndex);                                    

    if (DEM_IUMPRIF_TEST_IUMPR_500MI_GENDEN_CONDITIONS_REACHED(lRatioStatus) == FALSE)
    {
      lRatioStatus = DEM_IUMPRIF_SET_IUMPR_500MI_GENDEN_CONDITIONS_REACHED(lRatioStatus);
      Dem_Mem_SetIumprStatus(lRatioIndex, lRatioStatus);                                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
    }

    Dem_LeaveCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)
/* ****************************************************************************
% Dem_IumprIF_TestGeneralDenominatorIncrementConditionFulfilled()
*****************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_IumprIF_TestGeneralDenominatorIncrementConditionFulfilled(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex
  )
{
  boolean lRetVal;

# if (DEM_CFG_SUPPORT_500MI_DENOMINATOR == STD_ON)   
  uint8 lRatioDenominator;
  uint8 lRatioStatus;
  lRatioDenominator = Dem_Cfg_ObdIumprDenGroup(RatioIndex);
  lRatioStatus = Dem_Mem_GetIumprStatus(RatioIndex);
# endif 

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(RatioIndex)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */

# if (DEM_CFG_SUPPORT_500MI_DENOMINATOR == STD_ON)   
  if (lRatioDenominator == DEM_IUMPR_DEN_500MI)
  {
    lRetVal = (boolean)(DEM_IUMPRIF_TEST_IUMPR_500MI_GENDEN_CONDITIONS_REACHED(lRatioStatus) == TRUE);                        
  }
  else
# endif
  {
    lRetVal = (boolean)(DEM_ESM_TEST_IUMPR_GENDEN_CONDITIONS_REACHED(Dem_Mem_GetGeneralDenominatorStatus()) == TRUE);                       
  }

  return lRetVal;
}
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_IUMPRIF_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_IumprIF_Implementation.h
 *********************************************************************************************************************/
