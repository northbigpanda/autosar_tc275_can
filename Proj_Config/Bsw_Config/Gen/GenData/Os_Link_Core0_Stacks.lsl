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
 *              File: Os_Link_Core0_Stacks.lsl
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
/**********************************************************************************************************************
 *  STACK SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_KERNEL_STACKS )
group OS_CORE0_STACKS_GROUP(ordered, contiguous, fill)
{

/* Stack: OsCore0_Error (1024 Byte) */
group OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_ERROR_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Init (1024 Byte) */
group OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_INIT_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Isr_Core (1024 Byte) */
group OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Kernel (1024 Byte) */
group OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_KERNEL_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio30 (1024 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio4294967295 (1024 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio50 (1024 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_GROUP";

/* Stack: OsTask_App10ms_Core0 (1024 Byte) */
group OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT";
}
"_OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_GROUP";
"_OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT_GROUP";

/* Stack: OsTask_Bsw5ms_Core0 (1024 Byte) */
group OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT";
}
"_OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_GROUP";
"_OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT_GROUP";

} /* OS_CORE0_STACKS_GROUP */
"_OS_CORE0_STACKS_START" = "_lc_gb_OS_CORE0_STACKS_GROUP";
"_OS_CORE0_STACKS_END" = "_lc_ge_OS_CORE0_STACKS_GROUP" - 1;
"_OS_CORE0_STACKS_LIMIT" = "_lc_ge_OS_CORE0_STACKS_GROUP";
"_OS_CORE0_STACKS_END_ALIAS" = (("_lc_ge_OS_CORE0_STACKS_GROUP")&~0xF0000000)|0xD0000000;
"_OS_CORE0_STACKS_LIMIT_ALIAS" = (("_lc_ge_OS_CORE0_STACKS_GROUP")&~0xF0000000)|0xD0000000;

#endif

#ifdef OS_LINK_KERNEL_STACKS
# undef OS_LINK_KERNEL_STACKS
#endif


