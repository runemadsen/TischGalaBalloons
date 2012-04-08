#pragma once

#include "Animation.h"
#include "ofxMidi.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "BalloonControllerImage.h"

class AnimationImages : public Animation
{
public:
    
	AnimationImages(vector <string> imgNames);
	
    void update();
	void draw();
	void destroy();
	
	BalloonController * getNewController(Balloon * model);
	
private:
	
	vector <string> _imgNames;
	
};


