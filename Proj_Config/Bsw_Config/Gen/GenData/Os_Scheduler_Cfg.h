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
 *              File: Os_Scheduler_Cfg.h
 *   Generation Time: 2024-02-03 23:46:01
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#ifndef OS_SCHEDULER_CFG_H
# define OS_SCHEDULER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines the number of all task queues. */
# define OS_CFG_NUM_TASKQUEUES                   (7u)

/* Number of task queue activation slots: OsCore0 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE0_SLOTS     (2u)

/* Number of task queue activation slots: OsCore1 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE1_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE1_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE1_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE1_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE1_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE1_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE1_SLOTS     (2u)

/* Number of task queue activation slots: OsCore2 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE2_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE2_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE2_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE2_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE2_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE2_SLOTS     (1u)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE2_SLOTS     (2u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_SCHEDULER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Cfg.h
 *********************************************************************************************************************/
