#include "BalloonControllerFade.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerFade::BalloonControllerFade(string imgName, Balloon * model) : BalloonController(model)
{
	timer.setUpDown(true);
	timer.setState(-1);
	timer.setDuration(200);
	timer.setTime(0);
	
	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	
	_img.loadImage(imgName);
}

void BalloonControllerFade::setStartNum(int num)
{
	timer.setTime(num);
}

/* Update
 ___________________________________________________________ */

void BalloonControllerFade::update()
{
	timer.tick();
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerFade::draw()
{
	ofRectangle bounds = _model->getBoundsFromSize(_img.getWidth(), _img.getHeight());
	
	float alpha = Quad::easeIn(timer.getTime(), 0, 255, timer.getDuration());
	
	ofEnableAlphaBlending();
	
	ofSetColor(_color.r, _color.g, _color.b, alpha);
	
	_img.draw(bounds.x, bounds.y, bounds.width, bounds.height);
	
	ofDisableAlphaBlending();
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerFade::noteOn()
{
	//timer.setState(1);
	
	//timer.setTime(400);
	
	//timer.setState(-1);
}

void BalloonControllerFade::noteOff()
{
	//timer.setState(-1);
}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerFade::destroy()
{	
	if(_img.getTextureReference().bAllocated())
	{
		_img.clear();
	}
}

/* Getter / Setter
 ___________________________________________________________ */

void BalloonControllerFade::setColor(ofColor color)
{
	_color = color;
}