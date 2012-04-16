#pragma once

#include "ofMain.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "Constants.h"
#include "Tools.h"
#include "Quad.h"
#include "ofxImageSequence.h"

class BalloonControllerSequence : public BalloonController
{
	
public:
	
	BalloonControllerSequence(ofxImageSequence * sequence, Balloon * model);
	
	void update();
	void draw();
	
	void noteOn();
	void noteOff();
	
	void destroy();
    
private:
    
    ofxImageSequence * _sequence;
    int _startTime;
	
};