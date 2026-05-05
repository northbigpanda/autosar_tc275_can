#include "Dcm.h"
#include "Com.h"
//#include "Dcm_CoreTypes.h"
#if 1
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
	Dcm_EcuStartModeType ret = 0;
	return ret;
}


FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
	Std_ReturnType ret = 0;
	
	return ret;
}


FUNC(void, DCM_CALLOUT_CODE) Dcm_Confirmation(Dcm_IdContextType idContext
		,PduIdType dcmRxPduId
		,Dcm_ConfirmationStatusType status)
{
	
}
#endif
