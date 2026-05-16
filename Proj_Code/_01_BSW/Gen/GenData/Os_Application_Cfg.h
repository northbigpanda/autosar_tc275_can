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
 *              File: Os_Application_Cfg.h
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
#ifndef OS_APPLICATION_CFG_H 
# define OS_APPLICATION_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Number of application objects: SystemApplication_OsCore0 */
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS             (4uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS           (1uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS              (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS               (5uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS           (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS              (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS              (5uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES           (0uL)

/* Number of application objects: SystemApplication_OsCore1 */
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ALARMS             (2uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_COUNTERS           (1uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_HOOKS              (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_ISRS               (2uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_CAT1ISRS           (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SCHTS              (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_TASKS              (3uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE1_SERVICES           (0uL)

/* Number of application objects: SystemApplication_OsCore2 */
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ALARMS             (2uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_COUNTERS           (1uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_HOOKS              (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_ISRS               (2uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_CAT1ISRS           (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SCHTS              (0uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_TASKS              (3uL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE2_SERVICES           (0uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_APPLICATION_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Application_Cfg.h
 *********************************************************************************************************************/
