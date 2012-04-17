#include "BalloonControllerFade.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerFade::BalloonControllerFade(string imgName, Balloon * model) : BalloonController(model)
{
    _backgroundName = imgName;
    _backgroundName.insert(_backgroundName.length() - 4, "_bg");
    
	timer.setUpDown(true);
	timer.setDuration(200);
    timer.setTime(0);
    timer.setState(1);
    
    _delayTimer.setDuration(0);
    _delayTimer.setState(1);
    
    _state = FADING;
	
	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	
	_img.loadImage(imgName);
}

/* Update
 ___________________________________________________________ */

void BalloonControllerFade::update()
{    
    if(_state == FADING)
    {
        timer.tick();
        
        if(_delayTimer.getDuration() != 0 && timer.getTime() == 0)
        {
            timer.setTime(0);
            timer.setState(1);
            _state = DELAYING;
        }
    }
    else if(_state == DELAYING)
    {
        _delayTimer.tick();
        
        if(_delayTimer.getDuration() == _delayTimer.getTime())
        {
            _delayTimer.setTime(0);
            _state = FADING;
        }
    }
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerFade::draw()
{
	ofRectangle bounds = _model->getBoundsFromSize(_img.getWidth(), _img.getHeight());
    
    ofEnableAlphaBlending();
    
    if(_useBackground)
    {
        ofSetColor(_color.r, _color.g, _color.b, 255 * _opacity);
        _bgImg.draw(bounds.x, bounds.y, bounds.width, bounds.height);
    }
    
    float alpha = Quad::easeIn(timer.getTime(), 0, 255, timer.getDuration());
    if(_reverse) alpha = 255 - alpha;
    alpha = alpha * _opacity;
	
	ofSetColor(_color.r, _color.g, _color.b, alpha);
	
	_img.draw(bounds.x, bounds.y, bounds.width, bounds.height);
	
	ofDisableAlphaBlending();
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerFade::noteOn() {}
void BalloonControllerFade::noteOff() {}

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

void BalloonControllerFade::setReverse(bool reverse)
{
	_reverse = reverse;
}

void BalloonControllerFade::setDuration(int duration)
{
	timer.setDuration(duration);
}

void BalloonControllerFade::setStart(int start)
{
	timer.setTime(start);
}

void BalloonControllerFade::setDelayBetween(int delay)
{
    _delayTimer.setDuration(delay);
    
    // if delay is greater than 0 we start at a random delay
    if(delay > 0)
    {
        _state = DELAYING;
        _delayTimer.setTime(round(ofRandom(0, delay)));
        timer.setTime(0);
    }
}

void BalloonControllerFade::setUseBackground(bool useBackground)
{
	_useBackground = useBackground;
    
    if(_useBackground)
    {
        _bgImg.loadImage(_backgroundName);
    }
}
