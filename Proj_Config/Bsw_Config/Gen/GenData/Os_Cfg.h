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
 *              File: Os_Cfg.h
 *   Generation Time: 2024-02-05 14:39:15
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

#ifndef OS_CFG_H
# define OS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define OS_CFG_MAJOR_VERSION                    (2u)

/*! Configuration minor version identification. */
# define OS_CFG_MINOR_VERSION                    (36u)

/*! Defines which platform is used. */
# define OS_CFG_PLATFORM_TRICOREAURIX     (STD_ON)

/*! Defines which derivative group is configured. */
# define OS_CFG_DERIVATIVEGROUP_TC27X     (STD_ON)

/*! Defines which derivative is configured. */
# define OS_CFG_DERIVATIVE_TC27X     (STD_ON)

/*! Defines which compiler is configured. */
# define OS_CFG_COMPILER_TASKING     (STD_ON)

/*! Defines whether access macros to get context related information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_PARAMETERACCESS              (STD_OFF)

/*! Defines whether access macros to get service ID information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_GETSERVICEID                 (STD_OFF)

/*! Defines whether the pre-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_PRETASKHOOK                      (STD_OFF)

/*! Defines whether the post-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_POSTTASKHOOK                     (STD_OFF)

/*! Defines whether the OS shall call the panic hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PANICHOOK                        (STD_OFF)

/*! Defines whether the system startup hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOK_SYSTEM               (STD_OFF)

/*! Defines whether the system shutdown hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOK_SYSTEM              (STD_OFF)

/*! Defines whether the system error hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOK_SYSTEM                 (STD_ON)

/*! Defines whether the system protection hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK_SYSTEM            (STD_OFF)

/*! Defines whether backward compatibility defines are needed (STD_ON) or not (STD_OFF). */
# define OS_CFG_PERIPHERAL_COMPATIBILITY         (STD_OFF)

/* OS application modes */
# define DONOTCARE     ((AppModeType)0)
# define OS_APPMODE_NONE     ((AppModeType)0)
# define OSDEFAULTAPPMODE     ((AppModeType)1)
# define OS_APPMODE_ANY     ((AppModeType)255)

/*! Defines whether EVENT is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_EVENT                            (STD_ON)

/* Event masks */
# define Rte_Ev_Cyclic2_OsTask_App10ms_Core2_0_5ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_OsTask_Bsw5ms_Core0_0_5ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_OsTask_App10ms_Core0_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_RunS2_EcuM_EcuM_MainFunction     ((EventMaskType)1uLL)
# define Rte_Ev_Run_AppCtrl1_AppCtrl1_MainFuntion     ((EventMaskType)2uLL)
# define Rte_Ev_Run_AppCtrl2_AppCtrl2_MainFunction     ((EventMaskType)2uLL)
# define Rte_Ev_Run_IoHwAb_IoHwAb_IoHwAbRunnable     ((EventMaskType)2uLL)

/* Software counter timing macros */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Cfg.h
 *********************************************************************************************************************/

