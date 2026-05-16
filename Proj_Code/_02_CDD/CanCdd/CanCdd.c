
#include "Cdd_Cbk.h"

uint8 Rec_Meg_Cnt = 0;
uint8 Send_Meg_Cnt = 0;

FUNC(void, CDD_CODE) Xwxz_Cdd_Can_RxConfirmation(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CDD_APPL_DATA) PduInfoPtr)
{
    Rec_Meg_Cnt++;
    if (Rec_Meg_Cnt >=127)
    {
        Rec_Meg_Cnt = 0;
    }

    (void)RxPduId;
    (void)PduInfoPtr;
    

}


FUNC(void, CDD_CODE) Xwxz_Cdd_Can_TxConfirmation(PduIdType TxPduId)
{
    Send_Meg_Cnt++;
    if (Send_Meg_Cnt >=127)
    {
        Send_Meg_Cnt = 0;
    }
   (void)TxPduId;   
   
}