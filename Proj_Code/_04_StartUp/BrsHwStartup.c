
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
  \file  File:  BrsHwStartup.c
      Project:  Vector Basic Runtime System
       Module:  BrsHw for platform Aurix and AurixPlus
     Template:  This file is reviewed according to zBrs_Template@root[3.03.03]

  \brief Description:  This file contains the assembler part of the BRS StartUpCode.

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
  Torsten Schmidt               visto         Vector Informatik GmbH
  Bilal Parvez                  visbpz        Vector Informatik GmbH
  Andreas Kuehefuss             visakf        Vector Informatik GmbH
  Benjamin Walter               visbwa        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2019-04-30  visto   Initial creation
            2019-05-07  visbpz  Updating vLinkgen include and addind missing external declaration
            2019-07-03  visbpz  Adding vLinkGen ZeroInit loops
            2019-07-30  visakf  Remove extern void Brs_PreMainStartup(void); replace with include of BrsMainStartup.h
            2019-08-05  visbwa  Review according to Brs_Template 3.03.03. Removed compiler specific header files,
                                reworked compiler abstraction, added call of BrsMainExceptionStartup()
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
/*
 * Description: The BrsHw header provides all the necessary interfaces to
 *              the microcontroller hardware features like ports, timers, LEDs, ...
 */
#include "BrsHw.h"
#include "BrsMain.h"
#include "BrsMainStartup.h"
#include "vLinkGen_InitSections_Lcfg.h"

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/
#if defined (BRS_COMP_TASKING) 

#else
  #error "Unknown compiler specified!"
#endif

/**********************************************************************************************************************
  Compiler abstraction
**********************************************************************************************************************/
#if defined (BRS_COMP_TASKING)
  /**********************************************************************************/
  /* external symbols of context saving areas */
  /**********************************************************************************/
  extern int _lc_ub_csa_tc0[][16];  /* context save area core 0 begin */
  extern int _lc_ue_csa_tc0[][16];  /* context save area core 0 end   */


# if (BRS_CPU_CORE_AMOUNT > 1)
  extern int _lc_ub_csa_tc1[][16];  /* context save area core 1 begin */
  extern int _lc_ue_csa_tc1[][16];  /* context save area core 1 end   */
#endif  


# if (BRS_CPU_CORE_AMOUNT > 2)
  extern int _lc_ub_csa_tc2[][16];  /* context save area core 2 begin */
  extern int _lc_ue_csa_tc2[][16];  /* context save area core 2 end   */
#endif  

# if (BRS_CPU_CORE_AMOUNT > 3)
  extern int _lc_ub_csa_tc3[][16];  /* context save area core 3 begin */
  extern int _lc_ue_csa_tc3[][16];  /* context save area core 3 end   */
#endif  

# if (BRS_CPU_CORE_AMOUNT > 4)
  extern int _lc_ub_csa_tc4[][16];  /* context save area core 4 begin */
  extern int _lc_ue_csa_tc4[][16];  /* context save area core 4 end   */
#endif  


# if (BRS_CPU_CORE_AMOUNT > 5)
  extern int _lc_ub_csa_tc5[][16];  /* context save area core 5 begin */
  extern int _lc_ue_csa_tc5[][16];  /* context save area core 5 end   */
#endif  


  #define BRS_CSA_STARTADDRESS_CORE0  _lc_ub_csa_tc0
  #define BRS_CSA_ENDADDRESS_CORE0    _lc_ue_csa_tc0


# if (BRS_CPU_CORE_AMOUNT > 1)
  #define BRS_CSA_STARTADDRESS_CORE1  _lc_ub_csa_tc1
  #define BRS_CSA_ENDADDRESS_CORE1    _lc_ue_csa_tc1
#endif  

# if (BRS_CPU_CORE_AMOUNT > 2)
  #define BRS_CSA_STARTADDRESS_CORE2  _lc_ub_csa_tc2
  #define BRS_CSA_ENDADDRESS_CORE2    _lc_ue_csa_tc2
#endif  

# if (BRS_CPU_CORE_AMOUNT > 3)
  #define BRS_CSA_STARTADDRESS_CORE3  _lc_ub_csa_tc3
  #define BRS_CSA_ENDADDRESS_CORE3    _lc_ue_csa_tc3
#endif  

# if (BRS_CPU_CORE_AMOUNT > 4)
  #define BRS_CSA_STARTADDRESS_CORE4  _lc_ub_csa_tc4
  #define BRS_CSA_ENDADDRESS_CORE4    _lc_ue_csa_tc4
#endif  


# if (BRS_CPU_CORE_AMOUNT > 5)
  #define BRS_CSA_STARTADDRESS_CORE5  _lc_ub_csa_tc5
  #define BRS_CSA_ENDADDRESS_CORE5    _lc_ue_csa_tc5
#endif  


 


 



  /**********************************************************************************/
  /* compiler generated stack symbols used during startup */
  /* BRS_STARTUPSTACK_CORE<x> must be the end address */
  /**********************************************************************************/
  
  
  
  extern __far void _lc_ue_istack_tc0[];
  
# if (BRS_CPU_CORE_AMOUNT > 1)
  extern __far void _lc_ue_istack_tc1[];
#endif  
  
# if (BRS_CPU_CORE_AMOUNT > 2)
  extern __far void _lc_ue_istack_tc2[];
#endif  
# if (BRS_CPU_CORE_AMOUNT > 3)
  extern __far void _lc_ue_istack_tc3[];
#endif  
# if (BRS_CPU_CORE_AMOUNT > 4)
  extern __far void _lc_ue_istack_tc4[];
#endif  
# if (BRS_CPU_CORE_AMOUNT > 5)
  extern __far void _lc_ue_istack_tc5[];
#endif  
  
  
  #define BRS_STARTUPSTACK_CORE0  _lc_ue_istack_tc0
  
# if (BRS_CPU_CORE_AMOUNT > 1)
  #define BRS_STARTUPSTACK_CORE1  _lc_ue_istack_tc1
#endif  
# if (BRS_CPU_CORE_AMOUNT > 2)
  #define BRS_STARTUPSTACK_CORE2  _lc_ue_istack_tc2
#endif  
# if (BRS_CPU_CORE_AMOUNT > 3)
  #define BRS_STARTUPSTACK_CORE3  _lc_ue_istack_tc3
#endif  
# if (BRS_CPU_CORE_AMOUNT > 4)
  #define BRS_STARTUPSTACK_CORE4  _lc_ue_istack_tc4
#endif
# if (BRS_CPU_CORE_AMOUNT > 5)
  #define BRS_STARTUPSTACK_CORE5  _lc_ue_istack_tc5
#endif
  /**********************************************************************************/
  /* external symbols of trap vectors */
  /**********************************************************************************/


  extern __far void _lc_u_trap_tab_tc0[];


# if (BRS_CPU_CORE_AMOUNT > 1)
  extern __far void _lc_u_trap_tab_tc1[];

#endif


# if (BRS_CPU_CORE_AMOUNT > 2)
  extern __far void _lc_u_trap_tab_tc2[];

#endif

# if (BRS_CPU_CORE_AMOUNT > 3)
  extern __far void _lc_u_trap_tab_tc3[];

#endif

# if (BRS_CPU_CORE_AMOUNT > 4)
  extern __far void _lc_u_trap_tab_tc4[];

#endif

# if (BRS_CPU_CORE_AMOUNT > 5)
  extern __far void _lc_u_trap_tab_tc5[];

#endif



  #define BRS_TRAPTAB_CORE0  _lc_u_trap_tab_tc0

# if (BRS_CPU_CORE_AMOUNT > 1)
  #define BRS_TRAPTAB_CORE1  _lc_u_trap_tab_tc1

#endif
# if (BRS_CPU_CORE_AMOUNT > 2)
  #define BRS_TRAPTAB_CORE2  _lc_u_trap_tab_tc2
#endif

# if (BRS_CPU_CORE_AMOUNT > 3)
  #define BRS_TRAPTAB_CORE3  _lc_u_trap_tab_tc3
#endif


# if (BRS_CPU_CORE_AMOUNT > 4)

  #define BRS_TRAPTAB_CORE4  _lc_u_trap_tab_tc4

#endif
# if (BRS_CPU_CORE_AMOUNT > 5)

  #define BRS_TRAPTAB_CORE5  _lc_u_trap_tab_tc5
#endif


  /**********************************************************************************/
  /* external symbols of interrupt vectors */
  /**********************************************************************************/


  extern __far void _lc_u_int_tab_tc0[];


# if (BRS_CPU_CORE_AMOUNT > 1)
  extern __far void _lc_u_int_tab_tc1[];
#endif

# if (BRS_CPU_CORE_AMOUNT > 2)
  extern __far void _lc_u_int_tab_tc2[];
#endif
# if (BRS_CPU_CORE_AMOUNT > 3)
  extern __far void _lc_u_int_tab_tc3[];
#endif
# if (BRS_CPU_CORE_AMOUNT > 4)
  extern __far void _lc_u_int_tab_tc4[];

#endif


# if (BRS_CPU_CORE_AMOUNT > 5)
  extern __far void _lc_u_int_tab_tc5[];
#endif

  #define BRS_INTVECTTAB_CORE0  _lc_u_int_tab_tc0

# if (BRS_CPU_CORE_AMOUNT > 1)
  #define BRS_INTVECTTAB_CORE1  _lc_u_int_tab_tc1
#endif

# if (BRS_CPU_CORE_AMOUNT > 2)
  #define BRS_INTVECTTAB_CORE2  _lc_u_int_tab_tc2
#endif

# if (BRS_CPU_CORE_AMOUNT > 3)
  #define BRS_INTVECTTAB_CORE3  _lc_u_int_tab_tc3
#endif
# if (BRS_CPU_CORE_AMOUNT > 4)
  #define BRS_INTVECTTAB_CORE4  _lc_u_int_tab_tc4
#endif
# if (BRS_CPU_CORE_AMOUNT > 5)
  #define BRS_INTVECTTAB_CORE5  _lc_u_int_tab_tc5
#endif

#else
  /**********************************************************************************/
  /* external symbols of context saving areas */
  /**********************************************************************************/
  extern uint32 __CSA_BEGIN_CPU0_;
  extern uint32 __CSA_END_CPU0_;
  extern uint32 __CSA_BEGIN_CPU1_;
  extern uint32 __CSA_END_CPU1_;
  extern uint32 __CSA_BEGIN_CPU2_;
  extern uint32 __CSA_END_CPU2_;
  extern uint32 __CSA_BEGIN_CPU3_;
  extern uint32 __CSA_END_CPU3_;
  extern uint32 __CSA_BEGIN_CPU4_;
  extern uint32 __CSA_END_CPU4_;
  extern uint32 __CSA_BEGIN_CPU5_;
  extern uint32 __CSA_END_CPU5_;
  #define BRS_CSA_STARTADDRESS_CORE0  &__CSA_BEGIN_CPU0_
  #define BRS_CSA_STARTADDRESS_CORE1  &__CSA_BEGIN_CPU1_
  #define BRS_CSA_STARTADDRESS_CORE2  &__CSA_BEGIN_CPU2_
  #define BRS_CSA_STARTADDRESS_CORE3  &__CSA_BEGIN_CPU3_
  #define BRS_CSA_STARTADDRESS_CORE4  &__CSA_BEGIN_CPU4_
  #define BRS_CSA_STARTADDRESS_CORE5  &__CSA_BEGIN_CPU5_
  #define BRS_CSA_ENDADDRESS_CORE0    &__CSA_END_CPU0_
  #define BRS_CSA_ENDADDRESS_CORE1    &__CSA_END_CPU1_
  #define BRS_CSA_ENDADDRESS_CORE2    &__CSA_END_CPU2_
  #define BRS_CSA_ENDADDRESS_CORE3    &__CSA_END_CPU3_
  #define BRS_CSA_ENDADDRESS_CORE4    &__CSA_END_CPU4_
  #define BRS_CSA_ENDADDRESS_CORE5    &__CSA_END_CPU5_

  /**********************************************************************************/
  /* compiler generated stack symbols used during startup */
  /* BRS_STARTUPSTACK_CORE<x> must be the end address */
  /**********************************************************************************/
  extern uint32 __STARTUPSTACK_CORE0;
  extern uint32 __STARTUPSTACK_CORE1;
  extern uint32 __STARTUPSTACK_CORE2;
  extern uint32 __STARTUPSTACK_CORE3;
  extern uint32 __STARTUPSTACK_CORE4;
  extern uint32 __STARTUPSTACK_CORE5;
  #define BRS_STARTUPSTACK_CORE0  &__STARTUPSTACK_CORE0
  #define BRS_STARTUPSTACK_CORE1  &__STARTUPSTACK_CORE1
  #define BRS_STARTUPSTACK_CORE2  &__STARTUPSTACK_CORE2
  #define BRS_STARTUPSTACK_CORE3  &__STARTUPSTACK_CORE3
  #define BRS_STARTUPSTACK_CORE4  &__STARTUPSTACK_CORE4
  #define BRS_STARTUPSTACK_CORE5  &__STARTUPSTACK_CORE5

  /**********************************************************************************/
  /* external symbols of trap vectors */
  /* OS symbols are used */
  /**********************************************************************************/

  extern uint32 _OS_EXCVEC_CORE0_CODE_START;
  extern uint32 _OS_EXCVEC_CORE1_CODE_START;
  extern uint32 _OS_EXCVEC_CORE2_CODE_START;
  extern uint32 _OS_EXCVEC_CORE3_CODE_START;
  extern uint32 _OS_EXCVEC_CORE4_CODE_START;
  extern uint32 _OS_EXCVEC_CORE5_CODE_START;
  #define BRS_TRAPTAB_CORE0  &_OS_EXCVEC_CORE0_CODE_START
  #define BRS_TRAPTAB_CORE1  &_OS_EXCVEC_CORE1_CODE_START
  #define BRS_TRAPTAB_CORE2  &_OS_EXCVEC_CORE2_CODE_START
  #define BRS_TRAPTAB_CORE3  &_OS_EXCVEC_CORE3_CODE_START
  #define BRS_TRAPTAB_CORE4  &_OS_EXCVEC_CORE4_CODE_START
  #define BRS_TRAPTAB_CORE5  &_OS_EXCVEC_CORE5_CODE_START

  /**********************************************************************************/
  /* external symbols of interrupt vectors */
  /* OS symbols are used */
  /**********************************************************************************/

  extern uint32 _OS_INTVEC_CORE0_CODE_START;
  extern uint32 _OS_INTVEC_CORE1_CODE_START;
  extern uint32 _OS_INTVEC_CORE2_CODE_START;
  extern uint32 _OS_INTVEC_CORE3_CODE_START;
  extern uint32 _OS_INTVEC_CORE4_CODE_START;
  extern uint32 _OS_INTVEC_CORE5_CODE_START;
  #define BRS_INTVECTTAB_CORE0  &_OS_INTVEC_CORE0_CODE_START
  #define BRS_INTVECTTAB_CORE1  &_OS_INTVEC_CORE1_CODE_START
  #define BRS_INTVECTTAB_CORE2  &_OS_INTVEC_CORE2_CODE_START
  #define BRS_INTVECTTAB_CORE3  &_OS_INTVEC_CORE3_CODE_START
  #define BRS_INTVECTTAB_CORE4  &_OS_INTVEC_CORE4_CODE_START
  #define BRS_INTVECTTAB_CORE5  &_OS_INTVEC_CORE5_CODE_START
#endif /*BRS_COMP_x*/

typedef uint32 BRS_CSA_Element[16]; /* one CSA element consists of 16 x 32 bit */

extern void BrsHwUnlockInit(sint32);
extern void BrsHwLockInit(sint32);

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/

/* =========================================================================== */
/*                                                                             */
/* Description: Entry point for all cores                                      */
/*                                                                             */
/* =========================================================================== */
BRS_STARTUP_LABEL(brsStartupEntry)

void BRS_FORCE_ACTIVE brsStartupEntry_internal(void)
{
  uint32 CurrentCoreId = BRS_READ_COREID();
  uint32 AuxVariable = 0;
  uint32 SPAddressInit = 0;
  uint32 BTVAddressInit = 0;
  uint32 BIVAddressInit = 0;
  BRS_CSA_Element* CSAAddress = 0;
  uint32 CSA_Numbers = 0;

  switch(CurrentCoreId)
  {
    case (0):
      CSAAddress = (BRS_CSA_Element*)BRS_CSA_STARTADDRESS_CORE0;
      CSA_Numbers = ((uint32)BRS_CSA_ENDADDRESS_CORE0 - (uint32)BRS_CSA_STARTADDRESS_CORE0) / 64;
      SPAddressInit = (uint32)BRS_STARTUPSTACK_CORE0 & 0xfffffff8UL; /* align it on an 8 byte boundary */
      BTVAddressInit = (uint32)BRS_TRAPTAB_CORE0;
      BIVAddressInit = (uint32)BRS_INTVECTTAB_CORE0;
    break;
# if (BRS_CPU_CORE_AMOUNT > 1)
    case (1):
      CSAAddress = (BRS_CSA_Element*)BRS_CSA_STARTADDRESS_CORE1;
      CSA_Numbers = ((uint32)BRS_CSA_ENDADDRESS_CORE1 - (uint32)BRS_CSA_STARTADDRESS_CORE1) / 64;
      SPAddressInit = (uint32)BRS_STARTUPSTACK_CORE1 & 0xfffffff8UL; /* align it on an 8 byte boundary */
      BTVAddressInit = (uint32)BRS_TRAPTAB_CORE1;
      BIVAddressInit = (uint32)BRS_INTVECTTAB_CORE1;
    break;
# endif
# if (BRS_CPU_CORE_AMOUNT > 2)
    case (2):
      CSAAddress = (BRS_CSA_Element*)BRS_CSA_STARTADDRESS_CORE2;
      CSA_Numbers = ((uint32)BRS_CSA_ENDADDRESS_CORE2 - (uint32)BRS_CSA_STARTADDRESS_CORE2) / 64;
      SPAddressInit = (uint32)BRS_STARTUPSTACK_CORE2 & 0xfffffff8UL; /* align it on an 8 byte boundary */
      BTVAddressInit = (uint32)BRS_TRAPTAB_CORE2;
      BIVAddressInit = (uint32)BRS_INTVECTTAB_CORE2;
    break;
# endif
# if (BRS_CPU_CORE_AMOUNT > 3)
    case (3):
      CSAAddress = (BRS_CSA_Element*)BRS_CSA_STARTADDRESS_CORE3;
      CSA_Numbers = ((uint32)BRS_CSA_ENDADDRESS_CORE3 - (uint32)BRS_CSA_STARTADDRESS_CORE3) / 64;
      SPAddressInit = (uint32)BRS_STARTUPSTACK_CORE3 & 0xfffffff8UL; /* align it on an 8 byte boundary */
      BTVAddressInit = (uint32)BRS_TRAPTAB_CORE3;
      BIVAddressInit = (uint32)BRS_INTVECTTAB_CORE3;
    break;
# endif
# if (BRS_CPU_CORE_AMOUNT > 4)
    case (4):
      CSAAddress = (BRS_CSA_Element*)BRS_CSA_STARTADDRESS_CORE4;
      CSA_Numbers = ((uint32)BRS_CSA_ENDADDRESS_CORE4 - (uint32)BRS_CSA_STARTADDRESS_CORE4) / 64;
      SPAddressInit = (uint32)BRS_STARTUPSTACK_CORE4 & 0xfffffff8UL; /* align it on an 8 byte boundary */
      BTVAddressInit = (uint32)BRS_TRAPTAB_CORE4;
      BIVAddressInit = (uint32)BRS_INTVECTTAB_CORE4;
    break;
# endif
# if (BRS_CPU_CORE_AMOUNT > 5)
    case (6):
      CSAAddress = (BRS_CSA_Element*)BRS_CSA_STARTADDRESS_CORE5;
      CSA_Numbers = ((uint32)BRS_CSA_ENDADDRESS_CORE5 - (uint32)BRS_CSA_STARTADDRESS_CORE5) / 64;
      SPAddressInit = (uint32)BRS_STARTUPSTACK_CORE5 & 0xfffffff8UL; /* align it on an 8 byte boundary */
      BTVAddressInit = (uint32)BRS_TRAPTAB_CORE5;
      BIVAddressInit = (uint32)BRS_INTVECTTAB_CORE5;
    break;
# endif
    default:
    break;
  }

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize memory blocks and areas with zero                   */
/*                                                                             */
/* =========================================================================== */
#if defined (VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP)
# if (VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP>1uL)
  /* Loop over all entries of vLinkGen_ZeroInitBlocksArrayStartup and zero the configured memory blocks. */
  volatile uint32 *memPtr;
  for(uint8 blockNum = 0; blockNum < vLinkGen_ZeroInitBlocksStartup.num; blockNum++)
  {
    if(vLinkGen_ZeroInitBlocksStartup.areas[blockNum].core == CurrentCoreId &&
      (vLinkGen_ZeroInitBlocksStartup.areas[blockNum].end - vLinkGen_ZeroInitBlocksStartup.areas[blockNum].start) > 0)
    {
      memPtr = (volatile uint32 *)vLinkGen_ZeroInitBlocksStartup.areas[blockNum].start;
      while((uint32)memPtr < vLinkGen_ZeroInitBlocksStartup.areas[blockNum].end)
      {
        *memPtr = 0x0;
        memPtr++;
      }
    }
  }
# endif /*VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP>1uL*/

#else
  #error "Mandatory define VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP missing within vLinkGen configuration!"
#endif /*VLINKGEN_ZERO_INIT_BLOCK_COUNT_STARTUP*/

#if defined (VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP)
# if (VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP>1uL)
  /* Loop over all entries of vLinkGen_ZeroInitAreasArrayStartup and zero the configured memory areas. */
  volatile uint32 *memPtr2;
  for(uint8 areaNum = 0; areaNum < vLinkGen_ZeroInitAreasStartup.num; areaNum++)
  {
    if(vLinkGen_ZeroInitAreasStartup.areas[areaNum].core == CurrentCoreId &&
      (vLinkGen_ZeroInitAreasStartup.areas[areaNum].end - vLinkGen_ZeroInitAreasStartup.areas[areaNum].start) > 0)
    {
      memPtr2 = (volatile uint32 *)vLinkGen_ZeroInitAreasStartup.areas[areaNum].start;
      while((uint32)memPtr2 < vLinkGen_ZeroInitAreasStartup.areas[areaNum].end)
      {
        *memPtr2 = 0x0;
        memPtr2++;
      }
    }
  }
# endif /*VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP>1uL*/

#else
  #error "Mandatory define VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP missing within vLinkGen configuration!"
#endif /*VLINKGEN_ZERO_INIT_AREA_COUNT_STARTUP*/

#if (VLINKGEN_ZERO_INIT_BLOCK_COUNT_HARD_RESET>1uL)
  #error "Reset detection not yet supported by this vBaseEnv version. Has to be implemented manually!"
#endif

/* =========================================================================== */
/* Set stack pointer (compiler generated stack is used) */
/* =========================================================================== */
  BRS_SET_SP(SPAddressInit);

/* =========================================================================== */
/* Set the PSW to its reset value in case of a warm start */
/* =========================================================================== */
  BRS_MOVE_TO_CSFR(BRS_PSW_OFFSET, 0x00000B80UL);

/* =========================================================================== */
/* Set the PCXS and PCXO to its reset value in case of a warm start */
/* =========================================================================== */
  AuxVariable = BRS_MOVE_FROM_CSFR(BRS_PCXI_OFFSET);
  AuxVariable &= 0xfff00000UL;
  BRS_MOVE_TO_CSFR(BRS_PCXI_OFFSET, AuxVariable);

/* =========================================================================== */
/* initialize the CSAs (inlined function) */
/* aftwerwards function calls are possible */
/* =========================================================================== */
  BRS_CSA_Element* CSA;
  uint32 NumberOfCSA;
  uint32 pcxi_val = 0;    /* the last PCXI has to point to 0 */
  uint32 CSAReserve = 20; /* the LCX will be initalized to point to 20 CSAs before the very last CSA */
  uint32 seg_nr, seg_idx; /* auxiliary variables to assemble the PCXI value */

  if(CSAAddress != 0)
  {
    CSA = CSAAddress;
    for (NumberOfCSA=0; NumberOfCSA < CSA_Numbers; NumberOfCSA++) /* loop over all CSA elements */
    {
      *CSA[0] = pcxi_val; /* *CSA is equal to CSA[0] is equal to CSA.PCXI (it holds the PCXI value and has to point to the next PCXI) */

      /* now translate the current CSA address to a valid PCXI value which is used within the AURIX registers */
      seg_nr  = (((unsigned int)CSA >> 28) & 0xf) << 16;
      seg_idx = (((unsigned int)CSA >> 6) & 0xffff);
      pcxi_val = seg_nr | seg_idx;
      if (NumberOfCSA == CSAReserve) /* reserve CSAs for exception handling */
      {
        BRS_MOVE_TO_CSFR(BRS_LCX_OFFSET, pcxi_val);
      }
      CSA++; /* point to the next CSA */
    }
    BRS_MOVE_TO_CSFR(BRS_FCX_OFFSET, pcxi_val);
  }

/* =========================================================================== */
/* initialize BIV and BTV / endinit protected */
/* =========================================================================== */
  if((BTVAddressInit % 0x100) != 0)
  {
    /* the trap vector table must be aligned on a 256 byte boundary */
    for(;;);
  }
  if((BIVAddressInit % 0x2000) != 0)
  {
    /* the trap vector table must be aligned on a 8192 byte boundary */
    for(;;);
  }

  BrsHwUnlockInit(CurrentCoreId);
  BRS_MOVE_TO_CSFR(BRS_BTV_OFFSET, BTVAddressInit);
  BRS_MOVE_TO_CSFR(BRS_BIV_OFFSET, BIVAddressInit);
  BrsHwLockInit(CurrentCoreId);

/* =========================================================================== */
/*                                                                             */
/* Description: Jump to Brs_PreMainStartup() (BrsMainStartup.c)                */
/*                                                                             */
/* =========================================================================== */
  Brs_PreMainStartup();

/* =========================================================================== */
/*                                                                             */
/* Description: Jump to _BrsMainExceptionHandler() in case of an unexpected    */
/*              return from PreMain/main                                       */
/*                                                                             */
/* =========================================================================== */
  BrsMainExceptionStartup();
}
