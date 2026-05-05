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
 *              File: Os_Stack_Cfg.h
 *   Generation Time: 2024-02-03 23:56:52
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#ifndef OS_STACK_CFG_H
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_OFF)

/* Configured stack sizes (Total: 23552 Byte) */
# define OS_CFG_SIZE_OSCORE0_ERROR_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO30_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO50_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_ERROR_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_TASK_PRIO50_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_ERROR_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_TASK_PRIO50_STACK     (1024uL)
# define OS_CFG_SIZE_OSTASK_APP10MS_CORE0_STACK     (1024uL)
# define OS_CFG_SIZE_OSTASK_APP10MS_CORE1_STACK     (1024uL)
# define OS_CFG_SIZE_OSTASK_APP10MS_CORE2_STACK     (1024uL)
# define OS_CFG_SIZE_OSTASK_BSW5MS_CORE0_STACK     (1024uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
