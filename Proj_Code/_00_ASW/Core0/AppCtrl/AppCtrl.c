/*
 * AppCtrl.c
 *
 *  Created on: 2023��8��8��
 *      Author: Administrator
 */


/*
 * AppCtrl.c
 *
 *  Created on: 2023��5��17��
 *      Author: Administrator
 */


#include "Rte_AppCtrl.h"
#include "IfxStm_reg.h"

Sig_0x402_Used_2 g_Sig_0x402_Used_2_Last = 0;

FUNC(void, AppCtrl_CODE) AppCtrl_Init(void)
{

}

void Sys_Wait_Us(uint32 Wtime)
{
	static uint32 SysCurrentTime = 0;
	static uint32 SysRunTime = 0;
	static uint32 CurrentWTime = 0;

	SysCurrentTime = (((uint32)STM0_TIM0.U) / 80);
	do{
		SysRunTime = (((uint32)STM0_TIM0.U) / 80);
		if(SysRunTime >= SysCurrentTime)
		{
			CurrentWTime = SysRunTime - SysCurrentTime;
		}
		else
		{
			CurrentWTime = SysRunTime + ((uint32)4294967295 - SysCurrentTime);
		}
	}while(CurrentWTime < Wtime);

}

void Sys_Wait_Ms(uint32 Wtime)
{
	static uint32 SysCurrentTime = 0;
	static uint32 SysRunTime = 0;
	static uint32 CurrentWTime = 0;


	SysCurrentTime = (((uint32)STM0_TIM0.U) / 80);
	do{
		SysRunTime = (((uint32)STM0_TIM0.U) / 80);
		if(SysRunTime >= SysCurrentTime)
		{
			CurrentWTime = SysRunTime - SysCurrentTime;
		}
		else
		{
			CurrentWTime = SysRunTime + ((uint32)4294967295 - SysCurrentTime);
		}
	}while(CurrentWTime < (uint32)(Wtime * 1000));
}

FUNC(void, AppCtrl_CODE) AppCtrl_MainFunction(void)
{
	IOHWAB_BOOL KL15State;
  	float32 Angle = 4.5;

	SG_Sig_Grp_0x112 SG_Sig_Grp_0x112_AppCtrl = {0};
	SG_Sig_Grp_0x113 SG_Sig_Grp_0x113_AppCtrl = {0};
  	SG_Sig_Grp_0x114 SG_Sig_Grp_0x114_AppCtrl = {0};
	Sig_0x114_Used_6 Sig_0x114_Used_6_AppCtrl = 7;
	SG_Sig_Grp_0x402 SG_Sig_Grp_0x402_AppCtrl = {0};
	Trigger_Msg_Type Trigger_Msg_State_AppCtrl = FALSE;
	


	IoHwAb_IoHwAbCS_KL15_IoHwAbOp_KL15_Read(&KL15State);
	if(KL15State == STD_HIGH)
	{
		SG_Sig_Grp_0x112_AppCtrl.PowerMode = 1;
	}
	else
	{
		SG_Sig_Grp_0x112_AppCtrl.PowerMode = 0;
	}

	SG_Sig_Grp_0x113_AppCtrl.AAA_Angle = (uint8)((sint32)((Angle + 10)/0.5));

	SG_Sig_Grp_0x114_AppCtrl.Sig_0x114_Used_1 = 1;
	SG_Sig_Grp_0x114_AppCtrl.Sig_0x114_Used_2 = 2;
	SG_Sig_Grp_0x114_AppCtrl.Sig_0x114_Used_3 = 3;
	SG_Sig_Grp_0x114_AppCtrl.Sig_0x114_Used_4 = 4;
	SG_Sig_Grp_0x114_AppCtrl.Sig_0x114_Used_5 = 5;
	
	


	Rte_Write_AppCtrl_SG_Sig_Grp_0x112_SR_S_SG_Sig_Grp_0x112(&SG_Sig_Grp_0x112_AppCtrl);
	Rte_Write_AppCtrl_SG_Sig_Grp_0x113_SR_S_SG_Sig_Grp_0x113(&SG_Sig_Grp_0x113_AppCtrl);
	Rte_Write_AppCtrl_SG_Sig_Grp_0x114_SR_S_SG_Sig_Grp_0x114(&SG_Sig_Grp_0x114_AppCtrl);
	Rte_Write_AppCtrl_Sig_0x114_Used_SR_S_Sig_0x114_Used_6(Sig_0x114_Used_6_AppCtrl);

	Rte_Read_SG_Sig_Grp_0x402_SR_R_SG_Sig_Grp_0x402(&SG_Sig_Grp_0x402_AppCtrl);
	if(SG_Sig_Grp_0x402_AppCtrl.Sig_0x402_Used_2 != g_Sig_0x402_Used_2_Last)
	{
		g_Sig_0x402_Used_2_Last = SG_Sig_Grp_0x402_AppCtrl.Sig_0x402_Used_2;
		Trigger_Msg_State_AppCtrl = TRUE;
		Rte_Write_AppCtrl_Trigger_Msg_State_SR_S_Trigger_Msg_State(Trigger_Msg_State_AppCtrl);
	}
	else
	{
		Trigger_Msg_State_AppCtrl = FALSE;
		Rte_Write_AppCtrl_Trigger_Msg_State_SR_S_Trigger_Msg_State(Trigger_Msg_State_AppCtrl);
	}

	
	
}




