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
 *            Module: IoHwAb
 *           Program: MSR_Vector_SLP4
 *          Customer: China FAW Group Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC297TA
 *    License Scope : The usage is restricted to CBD1600956_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IoHwAb_Cfg.h
 *   Generation Time: 2024-02-05 14:17:56
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/


#if (!defined IOHWAB_CFG_H)
#define IOHWAB_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/

/* ===== MODULE INCLUDES ================================================== */

/* ===== SCHM INCLUDE ===================================================== */ 
#include "SchM_IoHwAb.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/* ===== VERSION IDENTIFICATION =========================================== */
#define IOHWAB_CFG_MAJOR_VERSION  (6u) 
#define IOHWAB_CFG_MINOR_VERSION  (1u) 
#define IOHWAB_CFG_PATCH_VERSION  (0u) 



/* ====== API CONFIGURATION =============================================== */

#define IOHWAB_VERSION_INFO_API                 (STD_OFF)
#define IOHWAB_USE_INIT_FUNCTION                (STD_ON)

/* ====== CONFIGURATION FOR DEVELOPMENT MODE ============================== */

#define IOHWAB_DEV_ERROR_DETECT                 (STD_ON)



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


#define IoHwAb_GlobalSuspend() SchM_Enter_IoHwAb_IOHWAB_EXCLUSIVE_AREA_0()
#define IoHwAb_GlobalRestore() SchM_Exit_IoHwAb_IOHWAB_EXCLUSIVE_AREA_0()



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* Prototypes of Sender/Receiver functions can be found in Rte_IoHwAb.h */

/* Prototypes of Client/Server functions can be found in Rte_IoHwAb.h */

/* Prototypes of Handler functions can be found in Rte_IoHwAb.h */



#endif /* (!defined IOHWAB_CFG_H) */
/**********************************************************************************************************************
 *  END OF FILE: IoHwAb_Cfg.h
 **********************************************************************************************************************/
