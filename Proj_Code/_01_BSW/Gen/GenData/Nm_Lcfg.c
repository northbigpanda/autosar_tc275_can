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
 *            Module: Nm
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Nm_Lcfg.c
 *   Generation Time: 2026-05-16 22:28:41
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
 * [Warning] NM01500 - Conflicting 'Passive Mode Enabled' parameters. 
 * - [Reduced Severity due to User-Defined Parameter] 'Passive Mode Enabled' parameter must not exist at the same time in NmGlobalFeatures and in NmChannelConfig containers. Please delete one of the instances.
 * Erroneous configuration elements:
 * /ActiveEcuC/Nm/CN_DBCNetWork_9ed72b09[0:NmPassiveModeEnabled](value=false) (DefRef: /MICROSAR/Nm/NmChannelConfig/NmPassiveModeEnabled)
 * /ActiveEcuC/Nm/NmGlobalConfig/NmGlobalFeatures[0:NmPassiveModeEnabled](value=false) (DefRef: /MICROSAR/Nm/NmGlobalConfig/NmGlobalFeatures/NmPassiveModeEnabled)
 *********************************************************************************************************************/
/* \trace SPEC-19583 */

#define NM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nm_Cfg.h"

/**********************************************************************************************************************
 *  END OF FILE: Nm_Lcfg.c
 *********************************************************************************************************************/

