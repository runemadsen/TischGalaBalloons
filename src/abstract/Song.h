#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "Balloon.h"
#include "Animation.h"

class Song
{
	
public:
    
    Song();
	
	void update();
	void draw();
	void updateControllers(vector <Balloon *> balloons);
	void newMidiMessage(ofxMidiEventArgs& eventArgs);
	void changeAnimation(int num);
	
	Animation * currentAnimation();
	
	virtual void createAnimations() {}
	virtual void destroyAnimations();
	
	void setMask(ofImage * mask);
	void setBoundsOffset(ofRectangle * bounds, int offSet);
	
	int getBank() { return _bank; }
	void setBank(int bank) { _bank = bank - 1; /* bank change 1 from ableton is 0 */ }
	
	string getName() { return _name; }
	
protected:
	
	string _name;
	
	int _bank;
	int _selectedAnimation;
	vector <Animation *> _animations;
	bool _loaded;
	
};