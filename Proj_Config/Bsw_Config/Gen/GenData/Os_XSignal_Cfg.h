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
 *              File: Os_XSignal_Cfg.h
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
#ifndef OS_XSIGNAL_CFG_H
# define OS_XSIGNAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether the X-Signal module is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_XSIGNAL                          (STD_ON)

/*! Defines whether cross core calls shall be performed asynchronous (STD_ON) or not (STD_OFF). */
# define OS_CFG_XSIG_USEASYNC                    (STD_OFF)

/* X-Signal defines for core: OsCore0 */
# define OS_CFG_NUM_XSIG_OSCORE0_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE0_SEND0_XSIGNALISR_OSCORE1_RECV0_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE0_SEND1_XSIGNALISR_OSCORE2_RECV0_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE0_PORTS     (2uL)

/* X-Signal defines for core: OsCore1 */
# define OS_CFG_NUM_XSIG_OSCORE1_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE1_SEND0_XSIGNALISR_OSCORE0_RECV0_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE1_SEND1_XSIGNALISR_OSCORE2_RECV1_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE1_PORTS     (2uL)

/* X-Signal defines for core: OsCore2 */
# define OS_CFG_NUM_XSIG_OSCORE2_ISRS     (1uL)
# define OS_CFG_SIZE_OSCORE2_SEND0_XSIGNALISR_OSCORE0_RECV1_BUFFER     (2uL)
# define OS_CFG_SIZE_OSCORE2_SEND1_XSIGNALISR_OSCORE1_RECV1_BUFFER     (2uL)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE2_PORTS     (2uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_XSIGNAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_XSignal_Cfg.h
 *********************************************************************************************************************/
