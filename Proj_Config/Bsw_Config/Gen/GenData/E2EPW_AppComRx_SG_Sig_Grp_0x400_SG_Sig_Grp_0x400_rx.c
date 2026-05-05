/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_rx.c
 ** Mon, 29-Jan-2024, 23:17:10
 **/

/**********************************************************
 * MISRA RULE 14.1 VIOLATION:
 * Error Message : Msg(4:1503) The function '<name>' is
 *   defined but is not used within this project.
 * Justification : Library functions
 **********************************************************/
/* PRQA S 1503 EOF */
/**********************************************************
 * MISRA RULE 19.1 VIOLATION:
 * Error Message : Msg(4:5087) #include statements in a
 *   file should only be preceded by other preprocessor
 *   directives or comments.
 * Justification : Inclusion of MemMap file is AUTOSAR
 *   specific
 **********************************************************/
/* PRQA S 5087 EOF */
/**********************************************************
 * MISRA VIOLATION: 'Metrics VOCF<=4' VIOLATION:
 * Code-structure based on by AUTOSAR 'Spec.of EndtoEnd
 * Communication Protection', R3.2.1 V1.2.0./
 * and '893.061.D_End-to-End Kommunikationsabsicherung_v1.5'
 **********************************************************/
#include "Rte_AppComRx.h"
#include "E2EPW_Marshal_SG_Sig_Grp_0x400.h"
#include "E2EPW_CheckDeserial_SG_Sig_Grp_0x400.h"
#include "E2EPW_AppComRx_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_rx.h"
#ifndef STATIC
    #define STATIC static
#endif

#define AppComRx_START_SEC_VAR_INIT_UNSPECIFIED
#include "AppComRx_MemMap.h"

STATIC VAR (E2E_P01CheckStateType, AppComRx_VAR_INIT)
    StateVal_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 =
{
      0                        /* LastValidCounter */
    , 0                        /* MaxDeltaCounter  */
    , TRUE                     /* WaitForFirstData */
    , FALSE                    /* NewDataAvailable */
    , 0                        /* LostData */
    , E2E_P01STATUS_NONEWDATA  /* Status */
    , 0                        /* SyncCounter */
    , 0                        /* NoNewOrRepeatedCounter */
};

STATIC P2VAR ( E2E_P01CheckStateType
             , AppComRx_VAR_INIT
             , AppComRx_VAR_INIT
             )
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 =
        &StateVal_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400;

#define AppComRx_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "AppComRx_MemMap.h"

#define AppComRx_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "AppComRx_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ppa_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC VAR (uint8, AppComRx_VAR_NOINIT)
    ppa_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_au8 [8];

#define AppComRx_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "AppComRx_MemMap.h"

#define AppComRx_START_SEC_CONST_UNSPECIFIED
#include "AppComRx_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ConfigVal_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC CONST (E2E_P01ConfigType, AppComRx_CONST)
    ConfigVal_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 =
{
      56
    , 0
    , 13124
    , 12
    , E2E_P01_DATAID_BOTH
    , 64
    , 2
    , 15
    , 1
};

#define AppComRx_STOP_SEC_CONST_UNSPECIFIED
#include "AppComRx_MemMap.h"

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
FUNC (void, AppComRx_CODE) E2EPW_ReadInit_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 (void)
{
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 = &StateVal_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400;
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->LastValidCounter = 0;
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->MaxDeltaCounter  = 0;
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->WaitForFirstData = TRUE;
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->NewDataAvailable = FALSE;
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->LostData         = 0;
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->Status           = E2E_P01STATUS_NONEWDATA;
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->SyncCounter      = 0;
    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->NoNewOrRepeatedDataCounter = 0;
}

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
FUNC_P2VAR ( E2E_P01CheckStateType
           , AppComRx_VAR_NOINIT
           , AppComRx_CODE
           )
    E2EPW_Get_CheckState_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 (void)
{
    return State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400;
}

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
FUNC (uint32, AppComRx_CODE) E2EPW_Read_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400
    ( P2VAR (SG_Sig_Grp_0x400, AUTOMATIC, AppComRx_VAR_INIT) AppData)
{
    VAR (uint8, AUTOMATIC) ret_u8;
    VAR (uint8, AUTOMATIC) ret_rte_u8 = RTE_E_OK;

    VAR (uint32, AUTOMATIC) status_ok_u32 =
           (0<<31)                         /* Deserial-Check */
        |  ((E2E_P01STATUS_OK & 0x7F)<<24) /* ReceiverStatus */
        |  (E2E_E_OK<<16)                  /* Protection Wrapper */
        |  (RTE_E_OK<<8)                   /* Rte_Read */
        |  (E2E_E_OK);                     /* E2E_...Check */
    VAR (uint32, AUTOMATIC) status_u32 = status_ok_u32;

    P2CONST (E2E_P01ConfigType, AUTOMATIC, AppComRx_CONST)
        Config_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 = &ConfigVal_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400;

    State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->NewDataAvailable =
        Rte_IsUpdated_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 ();

    if ((State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->NewDataAvailable != FALSE))
    {
        if (AppData == NULL_PTR)
        {
            ret_u8 = E2E_E_INPUTERR_NULL;
            status_u32 &= 0xFF00FFFFU;
            status_u32 |= (((uint32)ret_u8)<<16);
        }

        if (status_u32 == status_ok_u32)
        {
            /* Return-value of Rte_Read does not affect
               following workflow.
            */
            ret_rte_u8 = Rte_Read_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400 (AppData);
        }

        if (status_u32 == status_ok_u32)
        {
            ret_u8 = E2EPW_CheckDeserial_SG_Sig_Grp_0x400 (AppData);
            status_u32 &= 0x7FFFFFFFU;
            status_u32 |= (((uint32)ret_u8)<<31);
        }

        if (status_u32 == status_ok_u32)
        {
            uint16 crcoffset_u16 = Config_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->CRCOffset >> 3u;
            uint16 cntoffset_u16 = Config_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->CounterOffset >> 3u;
            E2EPW_Marshal_SG_Sig_Grp_0x400 ( AppData, ppa_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_au8 );
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL.
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1*/
            ppa_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_au8[crcoffset_u16]  = AppData->SupB_Checksum_0x400;
            ppa_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_au8[cntoffset_u16] &= (uint8)0xf0;
            ppa_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_au8[cntoffset_u16] |= AppData->SupB_Counter_0x400;
        }
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Check
                     ( Config_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400
                     , State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400
                     , ppa_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400_au8
                     );
        status_u32 &= 0x80FFFF00U;
        status_u32 |= ret_u8;
        status_u32 |= (uint32)(State_SG_Sig_Grp_0x400_SG_Sig_Grp_0x400->Status<<24);
    }

    status_u32 &= 0xFFFF00FFU;
    status_u32 |= (((uint32)ret_rte_u8)<<8);

    return status_u32;
}

#define AppComRx_STOP_SEC_CODE
#include "AppComRx_MemMap.h"
/*  << EOF >>  */
