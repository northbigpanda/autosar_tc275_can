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
 *              File: vLinkGen_InitSections_Lcfg.c
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

#define VLINKGEN_INITSECTIONS_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vLinkGen_InitSections_Lcfg.h"

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

/*! Memory region blocks to be always intialized with zeros. */
const vLinkGen_MemArea vLinkGen_ZeroInitBlocksArray[VLINKGEN_ZERO_INIT_BLOCK_COUNT] =
{
  {
    /* .start = */ (uint32)0uL,
    /* .end   = */ (uint32)0uL,
    /* .core  = */ (uint32)0uL
  }
};

/*! Memory region blocks to be always intialized with zeros. */
const vLinkGen_MemAreaSet vLinkGen_ZeroInitBlocks =
{
  /* .num   = */ VLINKGEN_ZERO_INIT_BLOCK_COUNT,
  /* .areas = */ vLinkGen_ZeroInitBlocksArray
};

/*! Memory region blocks to be intialized with zeros after a hard reset only. */
const vLinkGen_MemArea vLinkGen_ZeroInitBlocksArrayHardReset[VLINKGEN_ZERO_INIT_BLOCK_COUNT_HARD_RESET] =
{
  {
    /* .start = */ (uint32)0uL,
    /* .end   = */ (uint32)0uL,
    /* .core  = */ (uint32)0uL
  }
};

/*! Memory region blocks to be intialized with zeros after a hard reset only. */
const vLinkGen_MemAreaSet vLinkGen_ZeroInitBlocksHardReset =
{
  /* .num   = */ VLINKGEN_ZERO_INIT_BLOCK_COUNT_HARD_RESET,
  /* .areas = */ vLinkGen_ZeroInitBlocksArrayHardReset
};

/*! Memory region blocks to be initialized with zeros directly after reset. */
const vLinkGen_MemArea vLinkGen_ZeroInitBlocksArrayStartup[VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP] =
{
  {
    /* .start = */ (uint32)0uL,
    /* .end   = */ (uint32)0uL,
    /* .core  = */ (uint32)0uL
  }
};

/*! Memory region blocks to be initialized with zeros directly after reset. */
const vLinkGen_MemAreaSet vLinkGen_ZeroInitBlocksStartup =
{
  /* .num   = */ VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP,
  /* .areas = */ vLinkGen_ZeroInitBlocksArrayStartup
};

/*! Section groups to be always initialized with concrete data. */
const vLinkGen_RamMemArea vLinkGen_DataInitAreasArray[VLINKGEN_DATA_INIT_AREA_COUNT] =
{
  {
    /* .start    = */ (uint32)_OS_DATA_SHARED_INIT_START,
    /* .end      = */ (uint32)_OS_DATA_SHARED_INIT_LIMIT,
    /* .romstart = */ (uint32)_OS_DATA_SHARED_INIT_ROM_START,
    /* .romend   = */ (uint32)_OS_DATA_SHARED_INIT_ROM_LIMIT,
    /* .core     = */ (uint32)0uL
  },
  {
    /* .start    = */ (uint32)_Data_Default_INIT_START,
    /* .end      = */ (uint32)_Data_Default_INIT_LIMIT,
    /* .romstart = */ (uint32)_Data_Default_INIT_ROM_START,
    /* .romend   = */ (uint32)_Data_Default_INIT_ROM_LIMIT,
    /* .core     = */ (uint32)0uL
  },
  {
    /* .start    = */ (uint32)0uL,
    /* .end      = */ (uint32)0uL,
    /* .romstart = */ (uint32)0uL,
    /* .romend   = */ (uint32)0uL,
    /* .core     = */ (uint32)0uL
  }
};

/*! Section groups to be always initialized with concrete data. */
const vLinkGen_RamMemAreaSet vLinkGen_DataInitAreas =
{
  /* .num   = */ VLINKGEN_DATA_INIT_AREA_COUNT,
  /* .areas = */ vLinkGen_DataInitAreasArray
};

/*! Section groups to be always intialized with zeros. */
const vLinkGen_MemArea vLinkGen_ZeroInitAreasArray[VLINKGEN_ZERO_INIT_AREA_COUNT] =
{
  {
    /* .start = */ (uint32)_Bss_Default_START,
    /* .end   = */ (uint32)_Bss_Default_END,
    /* .core  = */ (uint32)0uL
  },
  {
    /* .start = */ (uint32)_Bss_Default_Core1_START,
    /* .end   = */ (uint32)_Bss_Default_Core1_END,
    /* .core  = */ (uint32)1uL
  },
  {
    /* .start = */ (uint32)_Bss_Default_Core2_START,
    /* .end   = */ (uint32)_Bss_Default_Core2_END,
    /* .core  = */ (uint32)2uL
  },
  {
    /* .start = */ (uint32)0uL,
    /* .end   = */ (uint32)0uL,
    /* .core  = */ (uint32)0uL
  }
};

/*! Section groups to be always intialized with zeros. */
const vLinkGen_MemAreaSet vLinkGen_ZeroInitAreas =
{
  /* .num   = */ VLINKGEN_ZERO_INIT_AREA_COUNT,
  /* .areas = */ vLinkGen_ZeroInitAreasArray
};

/*! Section groups to be intialized with zeros after a hard reset only. */
const vLinkGen_MemArea vLinkGen_ZeroInitAreasArrayHardReset[VLINKGEN_ZERO_INIT_AREA_COUNT_HARD_RESET] =
{
  {
    /* .start = */ (uint32)0uL,
    /* .end   = */ (uint32)0uL,
    /* .core  = */ (uint32)0uL
  }
};

/*! Section groups to be intialized with zeros after a hard reset only. */
const vLinkGen_MemAreaSet vLinkGen_ZeroInitAreasHardReset =
{
  /* .num   = */ VLINKGEN_ZERO_INIT_AREA_COUNT_HARD_RESET,
  /* .areas = */ vLinkGen_ZeroInitAreasArrayHardReset
};

/*! Section groups to be intialized with zeros directly after reset. */
const vLinkGen_MemArea vLinkGen_ZeroInitAreasArrayStartup[VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP] =
{
  {
    /* .start = */ (uint32)0uL,
    /* .end   = */ (uint32)0uL,
    /* .core  = */ (uint32)0uL
  }
};

/*! Section groups to be initialized with zeros directly after reset. */
const vLinkGen_MemAreaSet vLinkGen_ZeroInitAreasStartup =
{
  /* .num   = */ VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP,
  /* .areas = */ vLinkGen_ZeroInitAreasArrayStartup
};

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_InitSections_Lcfg.c
 *********************************************************************************************************************/
