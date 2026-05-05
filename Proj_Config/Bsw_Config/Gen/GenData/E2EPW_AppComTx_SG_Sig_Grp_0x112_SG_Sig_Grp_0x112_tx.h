/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_AppComTx_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112_tx.h
 ** Mon, 29-Jan-2024, 23:17:10
 **/

#ifndef E2EPW_AppComTx_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112_TX_H
#define E2EPW_AppComTx_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112_TX_H

#include "Rte_Type.h"
#include "E2E_P01.h"

#define AppComTx_START_SEC_CODE
#include "AppComTx_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112_tx ()
 * Description:   Initialize the E2Elib transmission-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, AppComTx_CODE) E2EPW_WriteInit_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112 (void);

/**********************************************************
 * Function name: E2EPW_Get_SenderState_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112 ()
 * Description:   Returns a pointer to the current E2Elib
 *                transmission-state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01ProtectStateType
                  , AppComTx_VAR_NOINIT
                  , AppComTx_CODE
                  )
    E2EPW_Get_ProtectState_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112 (void);

/**********************************************************
 * Function name: E2EPW_Write_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112 (SG_Sig_Grp_0x112 *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, AppComTx_CODE) E2EPW_Write_SG_Sig_Grp_0x112_SG_Sig_Grp_0x112
    (P2VAR (SG_Sig_Grp_0x112, AUTOMATIC, AppComTx_VAR_INIT) AppData);

#define AppComTx_STOP_SEC_CODE
#include "AppComTx_MemMap.h"

#endif
/*  << EOF >>  */
