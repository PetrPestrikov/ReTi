/*
 * Buttons.h
 *
 * Created: 14.04.2021 4:53:34
 *  Author: PestrikovPP
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_


#include <ReTi/SYSTEM/fms_timers.h>
#include <stdint.h>
#include <stddef.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"

#define MAX_BUTTONS 	3

#define DEBOUNCE_TIME 	20 //debounce time in ms

#define HOLD_TIME 		2000 //Time for Hold event

typedef enum ButState{
	Presed,
	Released
	}ButState;
	
typedef enum ButMode{
	Ready,
	Debounce
}ButMode;

typedef enum ButEvent{
	PresedEvent = 1,
	ReleasedEvent =2,
	HoldEvent = 4,
	DoubleClickEvent = 8,
	NO_Event = 16
}ButEvent;

typedef enum USEStatus{
	Use = 0,
	Unuse = 1
}USEStatus;

#define HI_LOGIC_LEVEL  true
#define LOW_LOGIC_LEVEL false




class button 
{
	public:
	button();
	soft_timer timer;					//debounce timer
	
	ButState CurrentState;				//current state pressed or released
	ButState _CurrentState;				//previous state pressed or released
	
	ButEvent CurrEvent;					//current event
	uint8_t EnabledEvents;				//allowed button events (in one byte as masks)
	
	virtual ButState ReadButState();			//read the current state of the button
	virtual void EnableEvent(ButEvent Event);	//button event resolution
	virtual void DisableEvent(ButEvent Event);	//disable button event
	virtual ButEvent ReadButEvent();			//was there an event
	
	virtual void ButtonHandler(void);			//Handles the current state of a particular button and changes events

	static uint8_t numb;
};

class DiscretButton : public button
{
	public:
		DiscretButton(bool PresedLogicLevel, uint32_t  PORT, uint8_t pin);
		virtual ButState ReadButState();			//read the current state of the button
		virtual void EnableEvent(ButEvent Event);	//enable button event
		virtual void DisableEvent(ButEvent Event);	//disable button event
		virtual ButEvent ReadButEvent();			//was there an event
		virtual void ButtonHandler(void);
		
	private:
		uint32_t PORT;					    //port address to which the button is connected
		uint8_t pin;						//pin number in the port to which the button is connected
		bool PresedLogicLevel;				//logic level of the pressed button (depends on the connection scheme)
		ButMode Mode;
			
};


void InitButtons(void);
void ProcessButtons(void);




#endif /* BUTTONS_H_ */
