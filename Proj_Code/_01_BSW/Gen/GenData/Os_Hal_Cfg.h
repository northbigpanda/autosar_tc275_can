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
 *              File: Os_Hal_Cfg.h
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

                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CFG_H
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2u)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (19u)

/* ISR core and level definitions */
# define OS_ISR_CANISR_0_CORE      (0)
# define OS_ISR_CANISR_0_LEVEL     (100)
# define OS_ISR_CANISR_1_CORE      (0)
# define OS_ISR_CANISR_1_LEVEL     (10)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE0_CORE      (0)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE0_LEVEL     (23)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE1_CORE      (1)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE1_LEVEL     (24)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE2_CORE      (2)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE2_LEVEL     (55)
# define OS_ISR_GTMTIM2SR7_ISR_CORE      (0)
# define OS_ISR_GTMTIM2SR7_ISR_LEVEL     (9)
# define OS_ISR_XSIGNALISR_OSCORE0_CORE      (0)
# define OS_ISR_XSIGNALISR_OSCORE0_LEVEL     (22)
# define OS_ISR_XSIGNALISR_OSCORE1_CORE      (1)
# define OS_ISR_XSIGNALISR_OSCORE1_LEVEL     (34)
# define OS_ISR_XSIGNALISR_OSCORE2_CORE      (2)
# define OS_ISR_XSIGNALISR_OSCORE2_LEVEL     (44)

/* Hardware counter timing macros */

/* Counter timing macros and constants: SystemTimer_Core0 */
# define OSMAXALLOWEDVALUE_SystemTimer_Core0     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer_Core0            (1uL)
# define OSTICKSPERBASE_SystemTimer_Core0        (80000uL)
# define OSTICKDURATION_SystemTimer_Core0        (1000000uL)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_SystemTimer_Core0)
# define OSMINCYCLE            (OSMINCYCLE_SystemTimer_Core0)
# define OSTICKSPERBASE        (OSTICKSPERBASE_SystemTimer_Core0)
# define OSTICKDURATION        (OSTICKDURATION_SystemTimer_Core0)

/*! Macro OS_NS2TICKS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer_Core0(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer_Core0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer_Core0(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer_Core0 was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_SystemTimer_Core0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer_Core0(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer_Core0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer_Core0(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer_Core0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/* Counter timing macros and constants: SystemTimer_Core1 */
# define OSMAXALLOWEDVALUE_SystemTimer_Core1     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer_Core1            (1uL)
# define OSTICKSPERBASE_SystemTimer_Core1        (80000uL)
# define OSTICKDURATION_SystemTimer_Core1        (1000000uL)

/*! Macro OS_NS2TICKS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer_Core1(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer_Core1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer_Core1(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer_Core1 was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_SystemTimer_Core1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer_Core1(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer_Core1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer_Core1(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer_Core1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/* Counter timing macros and constants: SystemTimer_Core2 */
# define OSMAXALLOWEDVALUE_SystemTimer_Core2     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_SystemTimer_Core2            (1uL)
# define OSTICKSPERBASE_SystemTimer_Core2        (80000uL)
# define OSTICKDURATION_SystemTimer_Core2        (1000000uL)

/*! Macro OS_NS2TICKS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer_Core2(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer_Core2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer_Core2(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_SystemTimer_Core2 was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_SystemTimer_Core2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer_Core2(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer_Core2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer_Core2(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer_Core2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */




/* CAT0 and CAT1 ISR core and level definitions */



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
