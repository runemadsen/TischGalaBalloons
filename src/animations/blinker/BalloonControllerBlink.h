#pragma once

#include "ofMain.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "Constants.h"
#include "Tools.h"
#include "Quad.h"

class BalloonControllerBlink : public BalloonController
{
	
public:
	
	BalloonControllerBlink(string imgName, Balloon * model);
	
	void update();
	void draw();
	
	void noteOn();
	void noteOff();
	
	void destroy();
	
	void setColor(ofColor color);
	void setFadeTime(int fadeTime);
	void setRandomAlpha(bool randomAlpha);
	void setConstrainRatio(bool constrain);
	
private:
	
	ofImage _img;
	ofColor _color;
	
	bool _constrainRatio;
	
	PTimer timer;
	
	bool _randomAlpha;
};