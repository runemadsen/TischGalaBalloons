#include "BalloonControllerImage.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerImage::BalloonControllerImage(string imgName, Balloon * model) : BalloonController(model)
{
	_img.loadImage(imgName);
}

/* Update
 ___________________________________________________________ */

void BalloonControllerImage::update()
{
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerImage::draw()
{
	ofFill();
	ofSetColor(0, 0, 0, 255);
	ofEllipse(_model->getCenterX(), _model->getCenterY(), _model->getWidth(), _model->getHeight());
	
	ofRectangle bounds = _model->getBoundsFromSize(_img.getWidth(), _img.getHeight());
	
	ofSetColor(255, 255, 255, 255);
	
	_img.draw(bounds.x, bounds.y, bounds.width, bounds.height);
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerImage::noteOn()
{

}

void BalloonControllerImage::noteOff()
{

}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerImage::destroy()
{	
	if(_img.getTextureReference().bAllocated())
	{
		_img.clear();
	}
}