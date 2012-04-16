#include "BalloonControllerVideo.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerVideo::BalloonControllerVideo(string videoname, Balloon * model) : BalloonController(model)
{	
	vid.loadMovie(videoname);
	//vid.setFrame(ofRandom(1, vid.getTotalNumFrames()));
	
	_shouldPlay = false;
}

/* Update
 ___________________________________________________________ */

void BalloonControllerVideo::update()
{
	vid.idleMovie();
	
	if(_shouldPlay)
	{
		if(vid.getCurrentFrame() != 1)
		{
			vid.setFrame(1);
		}
		
		vid.play();
		
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
	
	ofRectangle bounds = _model->getBoundsFromSize(vid.getWidth(), vid.getHeight());
	
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	
	vid.draw(bounds.x, bounds.y, bounds.width, bounds.height);
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
	vid.close();
}