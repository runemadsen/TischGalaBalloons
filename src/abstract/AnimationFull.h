#pragma once

#include "ofMain.h"
#include "Animation.h"

class AnimationFull : public Animation
{

protected:
	
	AnimationFull();
	
	void setMask(ofImage * mask);
	void setBounds(ofRectangle * bounds);
	
	void setUseMask(bool useMask) { _useMask = useMask; }
	
	ofRectangle * _bounds;
	
	ofImage * _mask;
	
	bool _useMask;
};
