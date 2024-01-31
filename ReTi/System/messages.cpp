/*
 * messages.cpp
 *
 * Created: 02.04.2021 1:06:49
 *  Author: Рабочий
 */ 
#include "messages.h"

/***************************************************
 *      v2.0.0
 ************************************************* */


MsgObj Messages[MAX_MESSAGES];

OutputMsgObj comBroadcastMsg;

void InitMessages(void) {
    uint8_t i;
	for (i=0; i< MAX_MESSAGES; i++) {
		Messages[i].MsgStatus = MsgMode_NOT_ACTIVE;
		Messages[i].MsgUsed = false;
	}

}


void ProcessMessages(void)
{
    uint8_t i;
	for (i=0; i< MAX_MESSAGES; i++) {
		if (Messages[i].MsgStatus == MsgMode_ACTIVE) Messages[i].MsgStatus = MsgMode_NOT_ACTIVE;
		if (Messages[i].MsgStatus == MsgMode_SET) Messages[i].MsgStatus = MsgMode_ACTIVE;
	}

}

void Connect(InputMsgObj * Input, OutputMsgObj* Output)
{
	Input->Msg = Output->Msg;
}

OutputMsgObj :: OutputMsgObj()
{
    uint8_t i = 0;
	for(i=0; i< MAX_MESSAGES; i++)
	{
		if (Messages[i].MsgUsed == false )
		{
			Messages[i].MsgUsed = true;
			this->Msg = &Messages[i];
			break;
		}
	}
	
}

void OutputMsgObj ::SendMsgWParam(MsgData Param)
{
		if (Msg->MsgStatus == MsgMode_NOT_ACTIVE) {
			Msg->MsgStatus = MsgMode_SET;
			Msg->Param = Param;
		}
	
}

void OutputMsgObj ::SendMsgWOParam()
{
	if (Msg->MsgStatus == MsgMode_NOT_ACTIVE) {
		Msg->MsgStatus = MsgMode_SET;
	}
	
}

InputMsgObj :: InputMsgObj()
{
	Msg = NULL;
}

bool InputMsgObj::CheckMessage()
{
		if (Msg->MsgStatus == MsgMode_ACTIVE) {
			return true;
		}
		return false;
}


uint8_t InputMsgObj::GetMsgCmdID()
{
	return Msg->Param.CommandID;
}

MsgData  InputMsgObj::GetMessageParam()
{
	return Msg->Param;
}


