#pragma once

#include "ofMain.h"
#include "Balloon.h"
#include "Constants.h"

class BalloonController
{
	
public:
	
	BalloonController(Balloon * model);
	
	virtual void update() {}
	virtual void draw() {}
	virtual void noteOn() {}
	virtual void noteOff() {}
	virtual void reset() {}
	virtual void destroy() {}
	
	void setModel(Balloon * model);
	void setMidiNote(int midiNote);
	
	Balloon * getModel();
	int getMidiNote();
	
	void setUseOffset(bool useOffset) { _useOffset = useOffset; }
	void setOffset(int offSet) { _offSet = offSet; }
	
protected:
	
	Balloon * _model;
	int _midiNote;
	int _offSet;
	int _useOffset;
};