#include "BalloonControllerVideo.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerVideo::BalloonControllerVideo(string videoname, Balloon * model) : BalloonController(model)
{	
	head.loadMovie(videoname);
	//head.setFrame(ofRandom(1, head.getTotalNumFrames()));
	
	_shouldPlay = false;
}

/* Update
 ___________________________________________________________ */

void BalloonControllerVideo::update()
{
	head.idleMovie();
	
	if(_shouldPlay)
	{
		if(head.getCurrentFrame() != 1)
		{
			head.setFrame(1);
		}
		
		head.play();
		
		_shouldPlay = false;
	}
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerVideo::draw()
{
	ofFill();
	ofSetColor(0, 0, 0, 255);
	ofEllipse(_model->getCenterX(), _model->getCenterY(), _model->getWidth(), _model->getHeight());
	
	ofRectangle bounds = _model->getBoundsFromSize(head.getWidth(), head.getHeight());
	
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	
	head.draw(bounds.x, bounds.y, bounds.width, bounds.height);
	ofDisableAlphaBlending();
}

void BalloonControllerVideo::reset()
{
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerVideo::noteOn()
{
	_shouldPlay = true;
}

void BalloonControllerVideo::noteOff()
{
	
}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerVideo::destroy()
{	
	head.close();
}