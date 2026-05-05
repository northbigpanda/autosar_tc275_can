
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  BrsMainStartup.c
      Project:  Vector Basic Runtime System
       Module:  BrsMain

  \brief Description:  Vector Basic Runtime System module source for startup routines.

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Steffen Frank                 visfsn        Vector Informatik GmbH
  Benjamin Walter               visbwa        Vector Informatik GmbH
  Senol Cendere                 visces        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2017-11-14  visfsn  Initial creation
  01.01.00  2018-03-27  visbwa  Renamed BrsAsrStartup into BrsStartup, added version check, reworked includes,
                                added example code text
  01.01.01  2018-05-16  visbwa  Added extern declaration of brsHwZeroRamAreaSet and brsHwInitRamAreaSet
  01.01.02  2018-07-02  visces  Removed outdated brsHwZeroRamAreaSet and brsHwInitRamAreaSet
  01.02.00  2018-08-16  visbwa  Replaced include of RamInitSections.h by vLinkGen_RamInitSections.h (vLinkGen used!)
  01.03.00  2018-10-08  visbwa  Changed include of BrsCfg.h into vBrsCfg.h in BrsMainStartup.h (vBaseEnv 1.1.0)
  01.04.00  2019-05-06  visbwa  Support for vLinkGen 1.04.00 (renamed struct names of vlinkGen areas),
                                added support for zero init blocks, renamed Brs_RamZeroInit() to Brs_MemoryZeroInit(),
                                renamed Brs_RomToRamInit() to Brs_MemoryInit(), check for missing hard reset detection
  01.04.01  2019-05-10  visbwa  Changed include of vLinkGen header to support new vLinkGen file structure
  01.04.02  2019-07-22  visbwa  Added check for configured VLINKGEN_ZERO_INIT_BLOCK_COUNT_HARD_RESET
  01.05.00  2019-08-07  visbwa  Added InitPattern parameter to Brs_MemoryZeroInit() and added the new configuration
                                values for the init pattern to the depending calls,
                                added sample implementation for Hard-reset blocks and areas
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "BrsMainStartup.h"
#include "BrsHw.h"
#include "BrsMain.h"

#include "vLinkGen_InitSections_Lcfg.h"

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
#if (BRSMAINSTARTUP_VERSION != 0x0105u)
  #error "Header and source file are inconsistent!"
#endif
#if (BRSMAINSTARTUP_BUGFIX_VERSION != 0x00u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/
#if !defined (BRS_INIT_PATTERN_BLOCKS)           || \
    !defined (BRS_INIT_PATTERN_HARDRESET_BLOCKS) || \
    !defined (BRS_INIT_PATTERN_AREAS)            || \
    !defined (BRS_INIT_PATTERN_HARDRESET_AREAS)
  #error "Your environment is missing the mandatory init pattern. They should be generated out of vBRS in Configurator5."
#endif

/**********************************************************************************************************************
  DEFINITION + MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL CONST VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL CONST VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  PROTOTYPES OF GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  PROTOTYPES OF LOCAL FUNCTIONS
**********************************************************************************************************************/
void Brs_MemoryZeroInit(const vLinkGen_MemAreaSet *, uint32, uint32);
void Brs_MemoryInit(const vLinkGen_RamMemAreaSet *, uint32);

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/

/*****************************************************************************/
/**
 * @brief      Unified routine for Pre Main() Startup.
 * @pre        Stack pointer needs to be initilialized in StartUpCode before.
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from assembler startup code
 *             Called by all cores
 *             All APIs are called with current Core ID
 */
/*****************************************************************************/
void Brs_PreMainStartup(void)
{

#ifndef NO_WATCHDOG_DISABLE
    /*
     disable Safety watchdog & Cpu0 watchdog
    */
    if(BrsHw_GetCore()==0)
    {
      //safety_endinit_reset();
      BrsHwUnlockInit(0);
      SCU_WDTSCON1.U |= 0x00000008 ;
      BrsHwLockInit(0);
      //safety_endinit_set();
    }
    BrsHwUnlockInit(BrsHw_GetCore());
    MODULE_SCU.WDTCPU[BrsHw_GetCore()].CON1.U = 0x00000008;
    BrsHwLockInit(BrsHw_GetCore());
  
#endif


  BrsHw_PreInitClock(BrsHw_GetCore()); /* optional callout to power up the PLL for faster Memory initialization */
  BrsHw_PreZeroRamHook(BrsHw_GetCore()); /* optional, empty by default */

#if (VLINKGEN_ZERO_INIT_BLOCK_COUNT>1uL)
  /* vLinkGen_ZeroInitBlocks contains vLinkGen memory region blocks, configured with zero init policy "ALWAYS" */
  Brs_MemoryZeroInit(&vLinkGen_ZeroInitBlocks, BRS_INIT_PATTERN_BLOCKS, BrsHw_GetCore());
#endif

#if (VLINKGEN_ZERO_INIT_BLOCK_COUNT_HARD_RESET>1uL)
  #error "Reset detection not yet supported by this vBaseEnv version. Has to be implemented manually!"
  if (BrsHwGetResetReason() != BRSHW_RESET_SW)
  {
    /* vLinkGen_ZeroInitBlocksHardReset contains vLinkGen memory region blocks, configured with zero init policy "HARD_RESET" */
    Brs_MemoryZeroInit(&vLinkGen_ZeroInitBlocksHardReset, BRS_INIT_PATTERN_HARDRESET_BLOCKS, BrsHw_GetCore());
  }
#endif

#if (VLINKGEN_ZERO_INIT_AREA_COUNT>1uL)
  /* vLinkGen_ZeroInitAreas contains vLinkGen VarGroup sections, configured with zero init policy "ALWAYS" */
  Brs_MemoryZeroInit(&vLinkGen_ZeroInitAreas, BRS_INIT_PATTERN_AREAS, BrsHw_GetCore());
#endif

#if (VLINKGEN_ZERO_INIT_AREA_COUNT_HARD_RESET>1uL)
  #error "Reset detection not yet supported by this vBaseEnv version. Has to be implemented manually!"
  if (BrsHwGetResetReason() != BRSHW_RESET_SW)
  {
    /* vLinkGen_ZeroInitAreasHardReset contains vLinkGen VarGroup sections, configured with zero init policy "HARD_RESET" */
    Brs_MemoryZeroInit(&vLinkGen_ZeroInitAreasHardReset, BRS_INIT_PATTERN_AREAS, BrsHw_GetCore());
  }
#endif

  BrsHw_PreInitRamHook(BrsHw_GetCore()); /* optional, empty by default */

#if (VLINKGEN_DATA_INIT_AREA_COUNT>1uL)
  /* vLinkGen_DataInitAreas contains vLinkGen VarGroup sections, where an init data memory region block is configured (for initialized variables) */
  Brs_MemoryInit(&vLinkGen_DataInitAreas, BrsHw_GetCore());
#endif

  BrsHw_PreMainHook(BrsHw_GetCore()); /* optional, empty by default */

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
  if (BrsHw_GetCore() == BRSHW_INIT_CORE_ID)
  {
    BrsHw_UnlockCores(BrsHw_GetCore()); /* unlocks all previously locked cores */
  }
#endif





  main();
}

/*****************************************************************************/
/**
 * @brief      Generic routine for RAM zeroing.
 * @pre        -
 * @param[in]  memAreaSet shall point to the first element of a vLinkGen_MemAreaSet struct array
 * @param[in]  coreId shall describe the ID of the current CPU
 * @param[out] -
 * @return     -
 * @context    Function is called from Brs_PreMainStartup() to initialize memory ares,
 *             generated out of vLinkGen configuration
 */
/*****************************************************************************/
void Brs_MemoryZeroInit(const vLinkGen_MemAreaSet *memAreaSet, uint32 InitPattern, uint32 coreId)
{
  volatile uint32 *memPtr;
  uint8 i;

  for (i=0; i<memAreaSet->num; i++)
  {
    if (memAreaSet->areas[i].core==coreId && (memAreaSet->areas[i].end - memAreaSet->areas[i].start) > 0)
    {
      memPtr = (volatile uint32*)memAreaSet->areas[i].start;
      while ((uint32)memPtr < memAreaSet->areas[i].end)
      {
        *memPtr = InitPattern;
        memPtr++;
      }
    }
  }
}

/*****************************************************************************/
/**
 * @brief      Generic routine for ROM to RAM initialization.
 * @pre        -
 * @param[in]  memAreasSet shall point to the first element of a vLinkGen_RamMemAreaSet struct array
 * @param[in]  coreId shall describe the ID of the current CPU
 * @param[out] -
 * @return     -
 * @context    Function is called from Brs_PreMainStartup() to initialize memory ares,
 *             generated out of vLinkGen configuration
 */
/*****************************************************************************/
void Brs_MemoryInit(const vLinkGen_RamMemAreaSet *memAreasSet, uint32 coreId)
{
  volatile uint32 *memPtr;
  volatile uint32 *romPtr;
  uint8 i;
  for (i=0; i<memAreasSet->num; i++)
  {
    if (memAreasSet->areas[i].core==coreId && ((memAreasSet->areas[i].end - memAreasSet->areas[i].start) > 0))
    {
      if ((memAreasSet->areas[i].end - memAreasSet->areas[i].start) != (memAreasSet->areas[i].romend - memAreasSet->areas[i].romstart))
      {
        /* Defined size in rom does not match ram size */
        BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAINSTARTUP, (uint16)(__LINE__));
      }

      memPtr = (volatile uint32*)memAreasSet->areas[i].start;
      romPtr = (volatile uint32*)memAreasSet->areas[i].romstart;
      while ((uint32)memPtr < memAreasSet->areas[i].end)
      {
        *memPtr = *romPtr;
        memPtr++;
        romPtr++;
      }
    }
  }
}
