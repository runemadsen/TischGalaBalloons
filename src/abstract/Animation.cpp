#include "Animation.h"

/* Constructor
___________________________________________________________ */

Animation::Animation()
{
	_usingControllers = false;
	
	_offSet = 0;
	_useOffset = false;
}

/* add / update / delete controllers with models
___________________________________________________________ */

void Animation::compareBalloonsToControllers()
{
	if(_usingControllers)
	{
		// first delete controllers with missing point
		for (int i = _controllers.size() - 1; i >= 0; i--) 
		{
			bool found = false;
			
			for (int j = 0; j < _points.size(); j++) 
			{
				if(_controllers[i]->getModel()->getID() == _points[j]->getID())
				{
					found = true;
					
					break;
				}
			}
			
			if(!found)
			{
				_controllers.erase(_controllers.begin() + i);
			}
		}
		
		// then update or create new controller
		for(int i = 0; i < _points.size(); i++)
		{
			bool found = false;
			
			for (int j = 0; j < _controllers.size(); j++) 
			{
				if(_points[i]->getID() == _controllers[j]->getModel()->getID())
				{
					_controllers[j]->setModel(_points[i]);
					
					found = true;
					
					break;
				}
			}
			
			if(!found)
			{				
				_controllers.push_back(getNewController(_points[i]));
				
				// automatically assign midi note
				if(_midiNotes.size() >= _controllers.size())
				{
					_controllers[_controllers.size() - 1]->setMidiNote(_midiNotes[_controllers.size() - 1]);
				}
			}
		}
	}
}

/* MIDI
 ___________________________________________________________ */

void Animation::newMidiMessage(ofxMidiEventArgs& eventArgs)
{
	if(_usingControllers)
	{
		BalloonController * b;
		
		for(int i = 0; i < _controllers.size(); i++)
		{
			if(_controllers[i]->getMidiNote() == eventArgs.byteOne)
			{
				if(eventArgs.status == MIDI_NOTE_ON)
				{
					_controllers[i]->noteOn();
				}
				else if(eventArgs.status == MIDI_NOTE_OFF) 
				{
					_controllers[i]->noteOff();
				}

				break;
			}
		}
	}
}

void Animation::wasDeselected()
{
	if(_usingControllers)
	{
		for(int i = 0; i < _controllers.size(); i++)
		{
			_controllers[i]->reset();
		}
	}
}

void Animation::setUseOffset(bool useOffset) 
{ 
	_useOffset = useOffset; 
	
	if(_usingControllers)
	{
		for (int i = 0; i < _controllers.size(); i++) 
		{
			_controllers[i]->setUseOffset(useOffset);
		}
	}
}

void Animation::setOffset(int offSet) 
{ 
	_offSet = offSet; 
	
	if(_usingControllers)
	{
		for (int i = 0; i < _controllers.size(); i++) 
		{
			_controllers[i]->setOffset(offSet);
		}
	}
}

/* All on / off
 ___________________________________________________________ */

void Animation::allOn()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->noteOn();
	}
}

void Animation::allOff()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->noteOff();
	}
}

/* Getter / Setter
___________________________________________________________ */

void Animation::setMidiNotes(vector <int> midiNotes)
{
	_midiNotes = midiNotes;
}

void Animation::setBalloons(vector <Balloon *> points)
{
	_points = points;
}
