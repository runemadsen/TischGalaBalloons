#pragma once

#include "Animation.h"
#include "ofxMidi.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "BalloonControllerSequence.h"
#include "ofxImageSequence.h"

class AnimationSequence : public Animation
{
public:
    
	AnimationSequence(string prefix, string filetype, int startIndex, int endIndex, int numDigits);
	
    void update();
	void draw();
	void destroy();
	
	BalloonController * getNewController(Balloon * model);
    
    ofxImageSequence sequence;
};


