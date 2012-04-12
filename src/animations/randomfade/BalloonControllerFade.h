#pragma once

#include "ofMain.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "Constants.h"
#include "Tools.h"
#include "Quad.h"

class BalloonControllerFade : public BalloonController
{
	
public:
	
	BalloonControllerFade(string imgName, Balloon * model);
	
	void update();
	void draw();
	
	void noteOn();
	void noteOff();
	
	void destroy();
	
	void setColor(ofColor color);
    void setDuration(int duration);
    void setStart(int start);	
    void setDelayBetween(int delay);
    void setReverse(bool reverse);
    
private:
	
	ofImage _img;
	ofColor _color;
    
	PTimer timer;
    PTimer _delayTimer;
    
    enum { FADING, DELAYING };
    
    bool _reverse;
    int _state;
    long _delayStart;
};