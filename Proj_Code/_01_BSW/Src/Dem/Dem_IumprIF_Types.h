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
 *  \file       Dem_IumprIF_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Types of the Obd Iumpr subcomponent which manages calculation of the IUMPR ratios.
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

#if !defined (DEM_IUMPRIF_TYPES_H)
#define DEM_IUMPRIF_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*!
 * \defgroup  Dem_IumprIFDenominatorStatus  Macros encoding ratio specific denominator states
 * Macros encoding ratio specific denominator states
 * \{
 */
# define DEM_IUMPRIF_IUMPR_500MI_GENDEN_CONDITIONS_REACHED       ((uint8)(0x80U))  /*!< General Denominator is fulfilled since incrementing 500 Miles denominator */
# define DEM_IUMPRIF_IUMPR_500MI_GENDEN_CONDITIONS_REACHED_MASK  ((uint8)(0x7fU))  /*!< Reset mask for General Denominator is fulfilled since incrementing 500 Miles denominator */
/*!
 * \}
 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/
/*! Test general denominator conditions fulfilled since 500 miles increment */
# define DEM_IUMPRIF_TEST_IUMPR_500MI_GENDEN_CONDITIONS_REACHED(Status) \
                                       (((Status) & DEM_IUMPRIF_IUMPR_500MI_GENDEN_CONDITIONS_REACHED) != 0)                     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set general denominator conditions fulfilled since 500 miles increment */
# define DEM_IUMPRIF_SET_IUMPR_500MI_GENDEN_CONDITIONS_REACHED(Status)  \
                                       ((uint8)((Status) | DEM_IUMPRIF_IUMPR_500MI_GENDEN_CONDITIONS_REACHED))                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset general denominator conditions fulfilled since 500 miles increment */
# define DEM_IUMPRIF_RESET_IUMPR_500MI_GENDEN_CONDITIONS_REACHED(Status) \
                                       ((uint8)((Status) & DEM_IUMPRIF_IUMPR_500MI_GENDEN_CONDITIONS_REACHED_MASK))              /* PRQA S 3453 */ /* MD_MSR_19.7 */
/* ******************************************************************************************************************** 
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#endif /* DEM_IUMPRIF_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_IumprIF_Types.h
 *********************************************************************************************************************/
