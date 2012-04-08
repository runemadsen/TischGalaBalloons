#include "AnimationBlinker.h"

/* Constructor
 ___________________________________________________________ */

AnimationBlinker::AnimationBlinker(vector <string> imgNames)
{
	_usingControllers = true;
	
	_imgNames = imgNames;
	
	_fadeTime = 20;
	_randomAlpha = false;
	_constrainRatio = true;
	
	ofColor color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	_colors.push_back(color);
}

/* Update
 ___________________________________________________________ */

void AnimationBlinker::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationBlinker::draw()
{
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->draw();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationBlinker::getNewController(Balloon * model)
{		
	int modulo = _controllers.size() % _imgNames.size();
	
	BalloonControllerBlink * b = new BalloonControllerBlink(_imgNames[modulo], model);
	
	modulo = _controllers.size() % _colors.size();
	
	b->setColor(_colors[modulo]);
	b->setFadeTime(_fadeTime);
	b->setRandomAlpha(_randomAlpha);
	b->setConstrainRatio(_constrainRatio);
	
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationBlinker::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}

/* Getter / Setter
 ___________________________________________________________ */

void AnimationBlinker::setColors(vector <ofColor> colors)
{
	_colors.clear();
	_colors = colors;
}

void AnimationBlinker::setContrainRatio(bool constrain)
{
	_constrainRatio = constrain;
}

void AnimationBlinker::setFadeTime(int fadeTime)
{
	_fadeTime = fadeTime;
}

void AnimationBlinker::setRandomAlpha(bool randomAlpha)
{
	_randomAlpha = randomAlpha;
}



