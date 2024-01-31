/*
 * messages.h
 *
 * Created: 02.04.2021 1:06:34
 *  Author: Рабочий
 */ 

/***************************************************
 *      v2.0.0
 ************************************************* */

#ifndef MESSAGES_H_
#define MESSAGES_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "system_settings.h"



typedef enum e_MsgMode{
    MsgMode_NOT_ACTIVE,
    MsgMode_SET,
    MsgMode_ACTIVE
}MsgMode;

typedef bool MsgBoxAvailable;


/*****************************************************************************
 *
 *    Structures for passing messages between tasks
 *
 **************************************************************************** */
typedef struct st_MsgData
{
    uint8_t CommandID;
	void * data = nullptr;
} MsgData;		        //data structure in messages

//the structure of the message itself
typedef struct MsgObj
{
        MsgBoxAvailable MsgUsed;
        MsgMode MsgStatus;
        MsgData Param;
}MsgObj;

class InputMsgObj;

class OutputMsgObj
{
	public:
	OutputMsgObj();
	void SendMsgWParam(MsgData Param);  //send data message
	void SendMsgWOParam();              //send message WITHOUT data

	private:
	MsgObj * Msg;

	friend	void Connect(InputMsgObj * Input, OutputMsgObj* Output);
};

class InputMsgObj
{
	public:
		InputMsgObj();
		bool CheckMessage();          //checking if a message has arrived at the input
		uint8_t GetMsgCmdID();        //read command from message
		MsgData GetMessageParam();
		
	
	private:
		MsgObj *Msg;
		
	friend void Connect(InputMsgObj * Input, OutputMsgObj* Output);
			
};


extern OutputMsgObj comBroadcastMsg;

void InitMessages(void);
void ProcessMessages(void);
void Connect(InputMsgObj * Input, OutputMsgObj* Output);



#endif /* MESSAGES_H_ */
