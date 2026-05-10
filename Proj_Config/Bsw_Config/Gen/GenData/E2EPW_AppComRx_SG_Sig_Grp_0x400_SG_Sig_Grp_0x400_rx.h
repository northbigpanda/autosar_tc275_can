/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_rx.h
 ** Sun, 10-May-2026, 15:18:53
 **/

#ifndef E2EPW_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_RX_H
#define E2EPW_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_RX_H
#include "Rte_Type.h"
#include "E2E_P01.h"

#define AppComRx_START_SEC_CODE
#include "AppComRx_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_rx ()
 * Description:   Initialize the E2Elib receiver-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, AppComRx_CODE) E2EPW_ReadInit_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 (void);

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01CheckStateType
             , AppComRx_VAR_NOINIT
             , AppComRx_CODE
             )
    E2EPW_Get_CheckState_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 (void);

/**********************************************************
 * Function name: E2EPW_Read_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 (SG_Sig_Grp_0x400 * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, AppComRx_CODE) E2EPW_Read_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400
    ( P2VAR (SG_Sig_Grp_0x400, AUTOMATIC, AppComRx_VAR_INIT) AppData);

#define AppComRx_STOP_SEC_CODE
#include "AppComRx_MemMap.h"

#endif
/*  << EOF >>  */
