#include "Song.h"

/* Constructor
___________________________________________________________ */

Song::Song()
{	
	_bank = 0;
	_selectedAnimation = 0;
	_loaded = false;
    
    _state = NORMAL;
}

/* Update
___________________________________________________________ */

void Song::update()
{
	if(_animations.size() > 0 && _loaded) 
	{
        if(_state == TRANSITION)
        {
            _transitionTimer.tick();
            float opacity = _transitionTimer.getPercent();
            _animations[_selectedAnimation]->setOpacity(1 - opacity);
            _animations[_transitionTo]->setOpacity(opacity);
            _animations[_transitionTo]->update();
            
            if(_transitionTimer.getTime() >= _transitionTimer.getDuration())
            {
                _state = NORMAL;
                _animations[_selectedAnimation]->wasDeselected();
                _selectedAnimation = _transitionTo;
                cout << "Finished transition \n";
            }
        }
        
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
            if(_state == TRANSITION)
            {
                _animations[_transitionTo]->draw();
            }
                
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
        _transitionTo = num;
		_animations[_transitionTo]->wasSelected();
        
        _transitionTimer.setDuration(_animations[_selectedAnimation]->getTransitionTime());
		
		cout << "--> TRANSITIONING: " << _transitionTo + 1 << endl;
        
        _transitionTimer.setTime(0);
        _transitionTimer.setState(1);
        _state = TRANSITION;
	}
}

void Song::nextAnimation()
{
    int goTo = _selectedAnimation + 1;
    
    if(_state == TRANSITION)
    {
        goTo = _transitionTo + 1;
    }
        
    changeAnimation(goTo);
}

void Song::prevAnimation()
{
    int goTo = _selectedAnimation - 1;
    
    if(_state == TRANSITION)
    {
        goTo = _transitionTo - 1;
    }
    
    changeAnimation(goTo);
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

