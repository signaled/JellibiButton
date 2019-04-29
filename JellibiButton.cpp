#include "arduino.h"
#include "JellibiButton.h"

JellibiButton::JellibiButton()
: _nPinNumber(0)
, _bRepeatFlag(false)
, _nLastRepeatTime(millis())
, _nCurState(HIGH)
{
}

void JellibiButton::Init(int nPin, bool bRepeat/* = false*/)
{
	_nPinNumber = nPin;
	_bRepeatFlag = bRepeat;
	pinMode(_nPinNumber, INPUT);
}

bool JellibiButton::Check() 
{
	bool bEvent = false;
	int nCurState = digitalRead(_nPinNumber);
	if (nCurState) 
	{
		_nCurState = nCurState;
	} 
	else 
	{ 
		if (nCurState != _nCurState) // Event Occured 
		{
			_nCurState = nCurState;
			_nLastRepeatTime = millis();    
			bEvent = true;
		} 
		else if (_bRepeatFlag) 
		{  // Repeat Check
			int cur = millis();
			if (cur > _nLastRepeatTime + _REPEAT_INTERVAL_) 
			{
				_nLastRepeatTime = cur;  
				bEvent = true;
			}
		}
	}
	return bEvent;
}

