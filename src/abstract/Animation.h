#pragma once

#include "ofMain.h"
#include "Balloon.h"
#include "BalloonController.h"
#include "ofxMidi.h"

class Animation
{
	
public:
    
    Animation();
	
	void setMidiNotes(vector <int> midiNotes);
	void setBalloons(vector <Balloon *> points);
	void compareBalloonsToControllers();
	
	virtual void update() {}
	virtual void draw() {}
	virtual void newMidiMessage(ofxMidiEventArgs& eventArgs);
	
	virtual void wasSelected() {}
	virtual void wasDeselected();
	
	virtual void destroy() {}
	
	virtual void allOn();
	virtual void allOff();
	
	virtual void setMask(ofImage * mask) {}
	virtual void setBounds(ofRectangle * bounds) {}
	
	void setUseOffset(bool useOffset);
	void setOffset(int offSet);
	
protected:
	
	virtual BalloonController * getNewController(Balloon * model) { }
	
	vector <Balloon *> _points;
	vector <BalloonController *> _controllers;
	
	bool _usingControllers;
	
	vector <int> _midiNotes;
	
	int _offSet;
	bool _useOffset;
};