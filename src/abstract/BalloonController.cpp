#include "BalloonController.h"

/* Constructor
 ___________________________________________________________ */

BalloonController::BalloonController(Balloon * model) 
{
	_model = model;
	
	_offSet = 0;
	_useOffset = false;
	
	_midiNote = DISABLED;
}

/* Getter / Setter
 ___________________________________________________________ */

void BalloonController::setModel(Balloon * model) 
{ 
	_model = model; 
}

Balloon * BalloonController::getModel() 
{ 
	return _model; 
}

void BalloonController::setMidiNote(int midiNote)
{
	_midiNote = midiNote;
}

int BalloonController::getMidiNote()
{
	return _midiNote;
}