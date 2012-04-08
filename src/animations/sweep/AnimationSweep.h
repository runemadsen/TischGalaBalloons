#pragma once

#include "Animation.h"
#include "ofxMidi.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "BalloonControllerSweep.h"

class AnimationSweep : public Animation
{
public:
    
	AnimationSweep(vector <string> imgNames);
	
	void setColors(vector <ofColor> colors);
	
    void update();
	void draw();
	void destroy();
	
	BalloonController * getNewController(Balloon * model);
	
private:
	
	vector <string> _imgNames;
	vector <ofColor> _colors;
};


