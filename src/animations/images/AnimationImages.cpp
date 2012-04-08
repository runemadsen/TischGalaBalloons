#include "AnimationImages.h"

/* Constructor
 ___________________________________________________________ */

AnimationImages::AnimationImages(vector <string> imgNames)
{
	_usingControllers = true;
	
	_imgNames = imgNames;
}

/* Update
 ___________________________________________________________ */

void AnimationImages::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationImages::draw()
{
	ofSetColor(255, 255, 255);
	
	ofEnableAlphaBlending();
	
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->draw();
	}
	
	ofDisableAlphaBlending();
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationImages::getNewController(Balloon * model)
{		
	int modulo = _controllers.size() % _imgNames.size();
	
	BalloonControllerImage * b = new BalloonControllerImage(_imgNames[modulo], model);
	
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationImages::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}



