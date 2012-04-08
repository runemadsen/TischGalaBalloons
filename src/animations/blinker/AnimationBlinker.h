#pragma once

#include "Animation.h"
#include "ofxMidi.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "BalloonControllerBlink.h"

class AnimationBlinker : public Animation
{
public:
    
	AnimationBlinker(vector <string> imgNames);
	
	void setColors(vector <ofColor> colors);
	
    void update();
	void draw();
	void destroy();
	
	void setContrainRatio(bool constrain);
	
	BalloonController * getNewController(Balloon * model);
	
	void setFadeTime(int fadeTime);
	void setRandomAlpha(bool randomAlpha);
	
private:
	
	vector <string> _imgNames;
	vector <ofColor> _colors;
	
	int _fadeTime;
	bool _randomAlpha;
	bool _constrainRatio;
};


