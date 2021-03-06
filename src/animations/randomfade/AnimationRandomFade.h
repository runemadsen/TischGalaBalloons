#pragma once

#include "Animation.h"
#include "ofxMidi.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "BalloonControllerFade.h"

class AnimationRandomFade : public Animation
{
public:
    
	AnimationRandomFade(vector <string> imgNames);
	
	void setColors(vector <ofColor> colors);
    void setDuration(int duration);
    void setDelayBetween(int delay);
    void setReverse(bool reverse);
    void setUseBackground(bool useBackground);
	
    void update();
	void draw();
	void destroy();
	
	BalloonController * getNewController(Balloon * model);
	
private:
	
    bool _reverse;
    bool _useBackground;
    int _delay;
    int _duration;
	vector <string> _imgNames;
	vector <ofColor> _colors;
};


