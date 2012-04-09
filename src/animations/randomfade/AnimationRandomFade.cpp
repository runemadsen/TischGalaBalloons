#include "AnimationRandomFade.h"

/* Constructor
 ___________________________________________________________ */

AnimationRandomFade::AnimationRandomFade(vector <string> imgNames)
{
	_usingControllers = true;
	
	_imgNames = imgNames;
	
	ofColor color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	_colors.push_back(color);
    
    _duration = 200;
    _delay = 0;
}

/* Update
 ___________________________________________________________ */

void AnimationRandomFade::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationRandomFade::draw()
{
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->draw();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationRandomFade::getNewController(Balloon * model)
{	
	int modulo = _controllers.size() % _imgNames.size();
    
	BalloonControllerFade * b = new BalloonControllerFade(_imgNames[modulo], model);
	
	modulo = _controllers.size() % _colors.size();
	b->setColor(_colors[modulo]);
    b->setDuration(_duration);
    b->setStart(round(ofRandom(0, _duration)));
    b->setDelayBetween(_delay);
	
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationRandomFade::destroy()
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

void AnimationRandomFade::setColors(vector <ofColor> colors)
{
	_colors.clear();
	_colors = colors;
}

void AnimationRandomFade::setDuration(int duration)
{
	_duration = duration;
}

void AnimationRandomFade::setDelayBetween(int delay)
{
    _delay = delay;
}



