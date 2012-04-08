#include "Song.h"

/* Constructor
___________________________________________________________ */

Song::Song()
{	
	_bank = 0;
	_selectedAnimation = 0;
	_loaded = false;
}

/* Update
___________________________________________________________ */

void Song::update()
{
	if(_animations.size() > 0 && _loaded) 
	{
		_animations[_selectedAnimation]->update();
	}
}

void Song::updateControllers(vector <Balloon *> balloons)
{
	if(_loaded)
	{
		for(int i = 0; i < _animations.size(); i++) 
		{
			_animations[i]->setBalloons(balloons);
			_animations[i]->compareBalloonsToControllers();
		}
	}
}

/* Draw
___________________________________________________________ */

void Song::draw()
{
	if(_loaded)
	{
		if(_animations.size() > 0) 
		{
			_animations[_selectedAnimation]->draw();
		}
	}
}

void Song::destroyAnimations()
{
	_loaded = false;
	
	for(int i = 0; i < _animations.size(); i++)
	{
		_animations[i]->destroy();
		delete _animations[i];
	}
	
	_animations.clear();
}

/* New MIDI message
___________________________________________________________ */

void Song::newMidiMessage(ofxMidiEventArgs& eventArgs)
{
	if(_loaded)
	{
		if(eventArgs.status == MIDI_PROGRAM_CHANGE)
		{
			if (eventArgs.byteOne < _animations.size()) 
			{
				changeAnimation(eventArgs.byteOne);
			}
		}
		else 
		{
			if(_animations.size() > 0) 
			{	
				_animations[_selectedAnimation]->newMidiMessage(eventArgs);
			}
		}
	}
}

void Song::changeAnimation(int num)
{
	if (num >= 0 && num < _animations.size() && _loaded) 
	{
		_animations[_selectedAnimation]->wasDeselected();
		
		_selectedAnimation = num;
		_animations[_selectedAnimation]->wasSelected();
		
		cout << "--> ANIMATION CHANGED: " << _selectedAnimation + 1 << endl;
	}
}

Animation * Song::currentAnimation()
{
	return _animations[_selectedAnimation];
}

void Song::setMask(ofImage * mask)
{
	for(int i = 0; i < _animations.size(); i++) 
	{
		_animations[i]->setMask(mask);
	}
}

void Song::setBoundsOffset(ofRectangle * bounds, int offSet)
{
	for(int i = 0; i < _animations.size(); i++) 
	{
		_animations[i]->setBounds(bounds);
		_animations[i]->setOffset(offSet);
	}
}

