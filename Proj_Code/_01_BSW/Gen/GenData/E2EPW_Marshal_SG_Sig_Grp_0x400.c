/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_SG_Sig_Grp_0x400.c
 ** Tue, 05-May-2026, 14:33:30
 **/

/******************************************************************
 * MISRA RULE 19.1 VIOLATION:
 * Error Message : Msg(4:5087) #include statements in a file
 *   should only be preceded by other preprocessor directives or
 *   comments.
 * Justification : Inclusion of MemMap.h is AUTOSAR specific.
 ******************************************************************/
/* PRQA S 5087 EOF */
/******************************************************************
 * MISRA RULE 11.4 VIOLATION:
 * Error Message : Msg(4:0310) Casting to different object pointer
 *   type.
 * Justification : Marshal code works on direct byte access for
 *   different application types.
 ******************************************************************/
/* PRQA S 0310 EOF */
/******************************************************************
 * MISRA RULE 10.1 VIOLATION:
 * Error Message : Msg(4:3757) Implicit conversion: int to unsigned
 *   char.
 * Justification : Marshal code generator ensures no loss of data
 *   during endianness conversion.
 ******************************************************************/
/* PRQA S 3757 EOF */

#include "Rte_AppComRx.h"
#include "E2EPW_Marshal_SG_Sig_Grp_0x400.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_SG_Sig_Grp_0x400
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_SG_Sig_Grp_0x400
    ( P2CONST (SG_Sig_Grp_0x400, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal CrcSig_Pack_0 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CrcSig_Pack_0);
    ppa[1]  = (src[0] << 4) & 0xf0;

    /* packing signal CrcSig_Pack_1 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CrcSig_Pack_1);
    ppa[2]  = src[2];
    ppa[3]  = src[1];
    ppa[4]  = src[0];

    /* packing signal CrcSig_Pack_2 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->CrcSig_Pack_2);
    ppa[5]  = (src[2] << 4) & 0xf0;
    ppa[5] |= (src[1] >> 4) & 0x0f;
    ppa[6]  = (src[1] << 4) & 0xf0;
    ppa[6] |= (src[0] >> 4) & 0x0f;
    ppa[7] &= 0x0f;
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* packing signal Led1_Control */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Led1_Control);
    ppa[1] |= src[0] & 0x01;

    /* packing signal Led2_Control */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Led2_Control);
    ppa[1] |= (src[0] << 1) & 0x02;

    /* packing signal Led3_Control */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Led3_Control);
    ppa[1] |= (src[0] << 2) & 0x04;

    /* packing signal Led4_Control */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->Led4_Control);
    ppa[1] |= (src[0] << 3) & 0x08;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
