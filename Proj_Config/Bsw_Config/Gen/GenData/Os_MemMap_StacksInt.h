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
 *              File: Os_MemMap_StacksInt.h
 *   Generation Time: 2024-02-03 23:56:52
 *           Project: TC27x - Version 1.0
 *          Delivery: CBD1600956_D01
 *      Tool Version: DaVinci Configurator  5.20.35
 *
 *
 *********************************************************************************************************************/

                                                                                                                        /* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */

/**********************************************************************************************************************
 *  STACK SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE0_ERROR_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE0_ERROR_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE0_INIT_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE0_INIT_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE0_KERNEL_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE0_KERNEL_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE1_ERROR_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE1_ERROR_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE1_INIT_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE1_INIT_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE1_ISR_CORE_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE1_ISR_CORE_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE1_KERNEL_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE1_KERNEL_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE2_ERROR_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE2_ERROR_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE2_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE2_INIT_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE2_INIT_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE2_ISR_CORE_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE2_ISR_CORE_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE2_KERNEL_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE2_KERNEL_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear "OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align 8 /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma align restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */
