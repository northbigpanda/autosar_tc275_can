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
 *              File: vLinkGen_InitSections_Lcfg.h
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

#ifndef VLINKGEN_INITSECTIONS_LCFG_H
# define VLINKGEN_INITSECTIONS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"
# include "vLinkGen_InitSections_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Definition of a generic memory area to be initialized. */
typedef struct
{
  /*! Start address of the memory area. */
  uint32 start;
  /*! End address of the memory area. */
  uint32 end;
  /*! Core ID to perform the initialization. */
  uint32 core;
} vLinkGen_MemArea;

/*! Definition of a RAM memory area to be initialized with concrete data from ROM. */
typedef struct
{
  /*! Start address of the RAM memory area. */
  uint32 start;
  /*! End address of the RAM memory area. */
  uint32 end;
  /*! Start address of the ROM memory area containing the init data. */
  uint32 romstart;
  /*! End address of the ROM memory area containing the init data. */
  uint32 romend;
  /*! Core ID to perform the initialization. */
  uint32 core;
} vLinkGen_RamMemArea;

/*! Definition of a generic initialization table. */
typedef struct
{
  /*! Number of memory areas in this set. */
  uint8 num;
  /*! Table of generic memory areas. */
  const vLinkGen_MemArea *areas;
} vLinkGen_MemAreaSet;

/*! Definition of a ROM to RAM initialization table. */
typedef struct
{
  /*! Number of memory areas in this set. */
  uint8 num;
  /*! Table of ROM to RAM memory areas. */
  const vLinkGen_RamMemArea *areas;
} vLinkGen_RamMemAreaSet;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* Start/end address label declarations */
extern uint8 _OS_DATA_SHARED_INIT_START[];
extern uint8 _OS_DATA_SHARED_INIT_LIMIT[];
extern uint8 _OS_DATA_SHARED_INIT_ROM_START[];
extern uint8 _OS_DATA_SHARED_INIT_ROM_LIMIT[];
extern uint8 _Data_Default_INIT_START[];
extern uint8 _Data_Default_INIT_LIMIT[];
extern uint8 _Data_Default_INIT_ROM_START[];
extern uint8 _Data_Default_INIT_ROM_LIMIT[];
extern uint8 _Bss_Default_START[];
extern uint8 _Bss_Default_END[];
extern uint8 _Bss_Default_Core1_START[];
extern uint8 _Bss_Default_Core1_END[];
extern uint8 _Bss_Default_Core2_START[];
extern uint8 _Bss_Default_Core2_END[];

/*! Memory region blocks to be always intialized with zeros. */
extern const vLinkGen_MemArea vLinkGen_ZeroInitBlocksArray[VLINKGEN_ZERO_INIT_BLOCK_COUNT];
/*! Memory region blocks to be always intialized with zeros. */
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInitBlocks;
/*! Memory region blocks to be intialized with zeros after a hard reset only. */
extern const vLinkGen_MemArea vLinkGen_ZeroInitBlocksArrayHardReset[VLINKGEN_ZERO_INIT_BLOCK_COUNT_HARD_RESET];
/*! Memory region blocks to be intialized with zeros after a hard reset only. */
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInitBlocksHardReset;
/*! Memory region blocks to be initialized with zeros directly after reset. */
extern const vLinkGen_MemArea vLinkGen_ZeroInitBlocksArrayStartup[VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP];
/*! Memory region blocks to be initialized with zeros directly after reset. */
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInitBlocksStartup;

/*! Section groups to be always initialized with concrete data. */
extern const vLinkGen_RamMemArea vLinkGen_DataInitAreasArray[VLINKGEN_DATA_INIT_AREA_COUNT];
/*! Section groups to be always initialized with concrete data. */
extern const vLinkGen_RamMemAreaSet vLinkGen_DataInitAreas;
/*! Section groups to be always intialized with zeros. */
extern const vLinkGen_MemArea vLinkGen_ZeroInitAreasArray[VLINKGEN_ZERO_INIT_AREA_COUNT];
/*! Section groups to be always intialized with zeros. */
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInitAreas;
/*! Section groups to be intialized with zeros after a hard reset only. */
extern const vLinkGen_MemArea vLinkGen_ZeroInitAreasArrayHardReset[VLINKGEN_ZERO_INIT_AREA_COUNT_HARD_RESET];
/*! Section groups to be intialized with zeros after a hard reset only. */
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInitAreasHardReset;
/*! Section groups to be intialized with zeros directly after reset. */
extern const vLinkGen_MemArea vLinkGen_ZeroInitAreasArrayStartup[VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP];
/*! Section groups to be initialized with zeros directly after reset. */
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInitAreasStartup;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* VLINKGEN_INITSECTIONS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_InitSections_Lcfg.h
 *********************************************************************************************************************/
