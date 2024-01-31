/*
 * Buttons.cpp
 *
 * Created: 14.04.2021 4:53:49
 *  Author: Рабочий
 */ 

#include "Buttons.h"

button * ButtonsMas[MAX_BUTTONS];

uint8_t button :: numb = 0;

void InitButtons(void)
{

}

void ProcessButtons(void)
{
    for ( uint32_t i = 0; i< button :: numb; i++)  //go through all the buttons
    {
        ButtonsMas[i]->ButtonHandler(); //handle button state
    }
}

button ::button ()
{
	CurrentState = Released;
	_CurrentState = Released;
	 CurrEvent = NO_Event;					//current event
	 EnabledEvents = 0;
}

ButState button::ReadButState()
{
	return _CurrentState;
}

ButEvent button::ReadButEvent()
{
	return CurrEvent;
}

void button::EnableEvent(ButEvent Event)
{
	EnabledEvents |=Event;
}

void button::DisableEvent(ButEvent Event)
{
	EnabledEvents &= ~Event;
}

void button:: ButtonHandler()
{
	
}

DiscretButton :: DiscretButton(bool PresedLogicLevel, uint32_t PORT, uint8_t pin)
{
    ButtonsMas[button :: numb] = this;
    button :: numb++;

      this->EnableEvent(PresedEvent);
      this->EnableEvent(ReleasedEvent);

      this->PresedLogicLevel = PresedLogicLevel;
      this->pin = pin;
      Mode = Ready;
}

ButState DiscretButton::ReadButState()
{
	ButState RetVal;
	int32_t test = GPIOPinRead(PORT, pin);
	if(test)
	{
		if(PresedLogicLevel == HI_LOGIC_LEVEL)
		    {
		        RetVal = Presed;
		    }
		else RetVal = Released;
	}
	else
		{
			if(PresedLogicLevel == HI_LOGIC_LEVEL)
			    {
			        RetVal = Released;
			    }
			else RetVal = Presed;
		}
	
	return RetVal;
}

ButEvent DiscretButton::ReadButEvent()
{
	return CurrEvent;
}

void DiscretButton::EnableEvent(ButEvent Event)
{
	EnabledEvents |=Event;
}

void DiscretButton::DisableEvent(ButEvent Event)
{
	EnabledEvents &= ~Event;
}

void DiscretButton:: ButtonHandler()
{
	//The button can be in two modes.
	//ready - the button is ready to respond to pressing
	//waiting - after changing the current level, a timer is started and for this time the button does not respond to changes
	
	CurrEvent = NO_Event;
	
	//read the current value of the button
	CurrentState = ReadButState();
	
	switch(Mode)
	{
	/////////////////////////////////////////////////
		case Ready:
		{
			//if current and previous are not equal
			if(_CurrentState != CurrentState)
			{
				//start the timer
				Mode = Debounce;
				timer.ResetTimer();
				timer.StartTimer();
			}
			else //if the states have not changed
			{
				if(CurrentState == Presed)
				{
					if(timer.GetTimer() >= HOLD_TIME)
					{
						if((EnabledEvents & HoldEvent) == HoldEvent) CurrEvent = HoldEvent;
						timer.StopTimer();
					}
				}				
			}
			
			
			
		break;
		}
	/////////////////////////////////////////////////
		case Debounce:
		{
			if(timer.GetTimer() >= DEBOUNCE_TIME)
			{
				Mode = Ready;
				timer.StopTimer();
				//if current and previous are still not equal
				if(_CurrentState != CurrentState)
				{
					//fix the click and the event, if it is allowed
					_CurrentState = CurrentState;
					if(CurrentState == Presed)
					{
						if((EnabledEvents & Presed) == Presed) CurrEvent = PresedEvent;
						//start a timer to track the hold event
						timer.ResetTimer();
						timer.StartTimer();
					}
					if(CurrentState == Released)
					{
						if( (EnabledEvents & Released) == Released) CurrEvent = ReleasedEvent;
					}
				}
			}
		break;
		}
	/////////////////////////////////////////////////
	}	
}
