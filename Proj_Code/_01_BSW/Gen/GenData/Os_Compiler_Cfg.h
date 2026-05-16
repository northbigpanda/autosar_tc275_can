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
 *              File: Os_Compiler_Cfg.h
 *   Generation Time: 2026-05-17 00:17:54
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] Cfg95301 - Os Interrupt Service Routine parameter invalid or different to configuration in BSW module 
 * - [Reduced Severity due to User-Defined Parameter] Either this parameter deviates from its definition in the /ActiveEcuC/Can Os Interrupt Service Routine or the definition of this parameter is invalid.
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/CanIsr_0 (DefRef: /MICROSAR/Os/OsIsr)
 * /ActiveEcuC/Os/CanIsr_0[0:OsIsrInterruptPriority](value=100) (DefRef: /MICROSAR/Os/OsIsr/OsIsrInterruptPriority)
 *********************************************************************************************************************/
#ifndef OS_COMPILER_CFG_H
# define OS_COMPILER_CFG_H

/**********************************************************************************************************************
 *  OS USER CALLOUT CODE SECTIONS
 *********************************************************************************************************************/

# define OS_CANISR_0_CODE
# define OS_CANISR_1_CODE
# define OS_DEFAULT_INIT_TASK_CODE
# define OS_DEFAULT_INIT_TASK_CORE1_CODE
# define OS_DEFAULT_INIT_TASK_CORE2_CODE
# define OS_GTMTIM2SR7_ISR_CODE
# define OS_OSTASK_APP10MS_CORE0_CODE
# define OS_OSTASK_APP10MS_CORE1_CODE
# define OS_OSTASK_APP10MS_CORE2_CODE
# define OS_OSTASK_APP_INIT_TASK_CODE
# define OS_OSTASK_BSW5MS_CORE0_CODE


#endif /* OS_COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Compiler_Cfg.h
 *********************************************************************************************************************/
 
