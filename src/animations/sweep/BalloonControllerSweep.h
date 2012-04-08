#pragma once

#include "ofMain.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "Constants.h"
#include "Tools.h"
#include "Quad.h"

class BalloonControllerSweep : public BalloonController
{
	
public:
	
	BalloonControllerSweep(string imgName, Balloon * model);
	
	void update();
	void draw();
	
	void noteOn();
	void noteOff();
	
	void destroy();
	
	void setStartNum(int num);
	void setColor(ofColor color);
	
private:
	
	ofImage _img;
	ofColor _color;
	
	PTimer timer;
};