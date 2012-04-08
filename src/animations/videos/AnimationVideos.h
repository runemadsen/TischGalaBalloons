#pragma once

#include "Animation.h"
#include "ofxMidi.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "BalloonControllerVideo.h"

class AnimationVideos : public Animation
{
public:
    
	AnimationVideos(vector <string> videoNames);
	
    void update();
	void draw();
	void wasSelected();
	void wasDeselected();
	void destroy();
	
	void newMidiMessage(ofxMidiEventArgs& eventArgs);
	BalloonController * getNewController(Balloon * model);
	
private:
	
	vector <string> _videoNames;
	
};


