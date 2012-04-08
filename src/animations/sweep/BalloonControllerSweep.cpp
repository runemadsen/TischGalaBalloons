#include "BalloonControllerSweep.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerSweep::BalloonControllerSweep(string imgName, Balloon * model) : BalloonController(model)
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

void BalloonControllerSweep::setStartNum(int num)
{
	timer.setTime(num);
}

/* Update
 ___________________________________________________________ */

void BalloonControllerSweep::update()
{
	timer.tick();
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerSweep::draw()
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

void BalloonControllerSweep::noteOn()
{
	//timer.setState(1);
	
	//timer.setTime(400);
	
	//timer.setState(-1);
}

void BalloonControllerSweep::noteOff()
{
	//timer.setState(-1);
}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerSweep::destroy()
{	
	if(_img.getTextureReference().bAllocated())
	{
		_img.clear();
	}
}

/* Getter / Setter
 ___________________________________________________________ */

void BalloonControllerSweep::setColor(ofColor color)
{
	_color = color;
}