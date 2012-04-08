#include "BalloonControllerBlink.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerBlink::BalloonControllerBlink(string imgName, Balloon * model) : BalloonController(model)
{
	_img.loadImage(imgName);
}

/* Update
 ___________________________________________________________ */

void BalloonControllerBlink::update()
{
	timer.tick();
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerBlink::draw()
{
	ofFill();
	ofSetColor(0, 0, 0, 255);
	ofEllipse(_model->getCenterX(), _model->getCenterY(), _model->getWidth(), _model->getHeight());
	
	ofRectangle bounds = _model->getBoundsFromSize(_img.getWidth(), _img.getHeight(), _constrainRatio);
	
	float alpha = Quad::easeOut(timer.getTime(), 0, 255, timer.getDuration());
	
	ofEnableAlphaBlending();
	
	ofSetColor(_color.r, _color.g, _color.b, alpha);
	
	_img.draw(bounds.x, bounds.y, bounds.width, bounds.height);
	
	ofDisableAlphaBlending();
}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerBlink::destroy()
{	
	if(_img.getTextureReference().bAllocated())
	{
		_img.clear();
	}
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerBlink::noteOn()
{	
	if(_randomAlpha)
	{
		timer.setTime(ofRandom(timer.getDuration() / 2, timer.getDuration()));
	}
	else 
	{
		timer.setTime(timer.getDuration());
	}

}

void BalloonControllerBlink::noteOff()
{
	timer.setState(-1);
}

/* Getter / Setter
 ___________________________________________________________ */

void BalloonControllerBlink::setColor(ofColor color)
{
	_color = color;
}

void BalloonControllerBlink::setFadeTime(int fadeTime)
{
	timer.setDuration(fadeTime);
}

void BalloonControllerBlink::setRandomAlpha(bool randomAlpha)
{
	_randomAlpha = randomAlpha;
}

void BalloonControllerBlink::setConstrainRatio(bool constrain)
{
	_constrainRatio = constrain;
}