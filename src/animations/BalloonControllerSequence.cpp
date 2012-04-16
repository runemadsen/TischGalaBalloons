#include "BalloonControllerSequence.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerSequence::BalloonControllerSequence(ofxImageSequence * sequence, Balloon * model) : BalloonController(model)
{
    _sequence = sequence;
    _startTime = ofRandom(0, 500);
}

/* Update
 ___________________________________________________________ */

void BalloonControllerSequence::update()
{    
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerSequence::draw()
{
    ofRectangle bounds = _model->getBoundsFromSize(_sequence->getWidth(), _sequence->getHeight());
	
	ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 255 * _opacity);
	_sequence->getFrameForTime(_startTime + ofGetElapsedTimef())->draw(bounds.x, bounds.y, bounds.width, bounds.height);
	ofDisableAlphaBlending();
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerSequence::noteOn() {}
void BalloonControllerSequence::noteOff() {}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerSequence::destroy()
{	
}