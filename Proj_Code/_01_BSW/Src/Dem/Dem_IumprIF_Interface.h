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
/*! \ingroup    Dem_Master
 *  \defgroup   Dem_IumprIF Dem_IumprIF
 *  \{
 *  \file       Dem_IumprIF_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Interface of the Obd Iumpr subcomponent which manages calculation of the IUMPR ratios.
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

#if !defined (DEM_IUMPRIF_INTERFACE_H)
#define DEM_IUMPRIF_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_IumprIF_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_IumprIF_Properties Properties
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_IumprIF_Private Private Methods
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_IumprIF_Public Public Methods
 * \{
 */

#if ((DEM_FEATURE_NEED_IUMPR == STD_ON) && (DEM_CFG_SUPPORT_500MI_DENOMINATOR == STD_ON))
/* ****************************************************************************
* Dem_IumprIF_Test500MileDenominatorConfigured()
*****************************************************************************/
/*!
* \brief         Tests whether the variant has a 500 miles denominator configured.
*
* \details       Tests whether the variant has a 500 miles denominator configured.
*
* \return        TRUE
*                Configuration has a 500 miles denominator configured.
*                FALSE
*                Configuration has no 500 miles denominator configured.
*
* \pre           -
* \config        (DEM_FEATURE_NEED_IUMPR == STD_ON)
*                 && (DEM_CFG_SUPPORT_500MI_DENOMINATOR == STD_ON)
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_IumprIF_Test500MileDenominatorConfigured(
  void
  );
#endif

#if ((DEM_FEATURE_NEED_IUMPR == STD_ON) && (DEM_CFG_SUPPORT_500MI_DENOMINATOR == STD_ON))
/* ****************************************************************************
* Dem_IumprIF_Update500MileGeneralDenominatorReached()
*****************************************************************************/
/*!
* \brief         Updates the general denominator reached since last increment
*                status for 500 miles denominators.
*
* \details       Updates the general denominator reached since last increment
*                status for 500 miles denominators.
*
* \pre           -
* \config        (DEM_FEATURE_NEED_IUMPR == STD_ON)
*                 && (DEM_CFG_SUPPORT_500MI_DENOMINATOR == STD_ON)
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_IumprIF_Update500MileGeneralDenominatorReached(
  void
  );
#endif

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)
/* ****************************************************************************
* Dem_IumprIF_TestGeneralDenominatorIncrementConditionFulfilled()
*****************************************************************************/
/*!
* \brief         Tests whether the general denominator conditions to increment 
*                ratio specific denominator are reached
*
* \details       Tests whether the general denominator conditions to increment 
*                ratio specific denominator are reached
*
* \param[in]     RatioIndex
*                Unique handle of the Ratio
*
* \return        TRUE
*                Condition to increment denominator is fulfilled.
*                FALSE
*                Condition to increment denominator is not fulfilled.
*
* \pre           -
* \config        (DEM_FEATURE_NEED_IUMPR == STD_ON)
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_IumprIF_TestGeneralDenominatorIncrementConditionFulfilled(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex
  );
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_IUMPRIF_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_IumprIF_Interface.h
 *********************************************************************************************************************/
