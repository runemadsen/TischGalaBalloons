#include "AnimationSequence.h"

/* Constructor
 ___________________________________________________________ */

AnimationSequence::AnimationSequence(string prefix, string filetype, int startIndex, int endIndex, int numDigits)
{
	_usingControllers = true;
    
    sequence.loadSequence(prefix, filetype, startIndex, endIndex, numDigits);
    sequence.preloadAllFrames();
    sequence.setFrameRate(30);
}

/* Update
 ___________________________________________________________ */

void AnimationSequence::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationSequence::draw()
{
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->draw();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationSequence::getNewController(Balloon * model)
{	    
	BalloonControllerSequence * b = new BalloonControllerSequence(&sequence, model);
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationSequence::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}



