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
 *            Module: vLinkGen
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_InitSections_Cfg.h
 *   Generation Time: 2024-02-04 23:11:09
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
**********************************************************************************************************************/

#ifndef VLINKGEN_INITSECTIONS_CFG_H
# define VLINKGEN_INITSECTIONS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Number of memory region blocks to be always intialized with zeros. */
# define VLINKGEN_ZERO_INIT_BLOCK_COUNT               1uL
/*! Number of memory region blocks to be intialized with zeros after a hard reset only. */
# define VLINKGEN_ZERO_INIT_BLOCK_COUNT_HARD_RESET    1uL
/*! Number of memory region blocks to be intialized with zeros directly after startup. */
# define VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP       1uL

/*! Number of section groups to be always initialized with concrete data. */
# define VLINKGEN_DATA_INIT_AREA_COUNT                3uL
/*! Number of section groups to be always intialized with zeros. */
# define VLINKGEN_ZERO_INIT_AREA_COUNT                4uL
/*! Number of section groups to be intialized with zeros after a hard reset only. */
# define VLINKGEN_ZERO_INIT_AREA_COUNT_HARD_RESET     1uL
/*! Number of section groups to be intialized with zeros directly after startup. */
# define VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP        1uL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#endif /* VLINKGEN_INITSECTIONS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_InitSections_Cfg.h
 *********************************************************************************************************************/
