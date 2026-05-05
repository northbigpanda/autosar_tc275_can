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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Kernel_Lcfg.h
 *   Generation Time: 2024-01-10 07:48:04
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_KERNEL_LCFG_H
# define OS_HAL_KERNEL_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_Core_Cfg.h"
# include "Os_Core_Types.h"

/* Os hal dependencies */
# include "Os_Hal_Context_Types.h"
# include "Os_Hal_Lcfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! AUTOSAR OS-Core identifier.
 * \details Logical Core IDs for all configured AUTOSAR cores.
 *          Notation: OS_COREASRCOREIDX_<X> = <Y>, where
 *            - X equals the ECUC core ID and
 *            - Y is a continuous core ID number running from 0 to OS_COREASRCOREID_COUNT-1.
 */
typedef enum
{
  OS_COREASRCOREIDX_0 = 0, /* OsCore0 */
  OS_COREASRCOREIDX_1 = 1, /* OsCore1 */
  OS_COREASRCOREIDX_2 = 2, /* OsCore2 */
  OS_COREASRCOREIDX_COUNT = 3
} Os_CoreAsrCoreIdx;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for cores. */
extern CONSTP2CONST(Os_CoreConfigType, OS_CONST, OS_CONST) OsCfg_CoreRefs[OS_COREID_COUNT + 1];              /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

/*! Object reference table for cores (sorted by physical ID). */
extern CONSTP2CONST(Os_CoreConfigType, OS_CONST, OS_CONST) OsCfg_CorePhysicalRefs[OS_CFG_COREPHYSICALID_COUNT + 1u];

/*! Object reference table for HAL kernel stacks. */
extern CONSTP2CONST(Os_Hal_ContextStackConfigType, OS_CONST, OS_CONST) OsCfg_Stack_KernelStacks[OS_CFG_COREPHYSICALID_COUNT + 1u]; 

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_KERNEL_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Kernel_Lcfg.h
 *********************************************************************************************************************/
