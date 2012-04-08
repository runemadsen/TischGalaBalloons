#include "AnimationVideos.h"

/* Constructor
 ___________________________________________________________ */

AnimationVideos::AnimationVideos(vector <string> videoNames)
{
	_videoNames = videoNames;
	_usingControllers = true;
}

/* Update
 ___________________________________________________________ */

void AnimationVideos::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationVideos::draw()
{
	ofSetColor(255, 255, 255);
	
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->draw();
	}
}

void AnimationVideos::wasSelected()
{
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->noteOn();
	}
}

void AnimationVideos::wasDeselected()
{
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->reset();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationVideos::getNewController(Balloon * model)
{		
	int modulo = _controllers.size() % _videoNames.size();
	
	BalloonControllerVideo * b = new BalloonControllerVideo(_videoNames[modulo], model);
	b->setUseOffset(_useOffset);
	b->setOffset(_offSet);
	return b;
}

void AnimationVideos::newMidiMessage(ofxMidiEventArgs& eventArgs)
{
	
}

/* Destroy
 ___________________________________________________________ */

void AnimationVideos::destroy()
{	
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}



