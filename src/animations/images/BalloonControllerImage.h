#pragma once

#include "ofMain.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "Constants.h"

class BalloonControllerImage : public BalloonController
{
	
public:
	
	BalloonControllerImage(string imgName, Balloon * model);
	
	void loadImage(string imgPath);
	
	void update();
	void draw();
	void destroy();
	
	void noteOn();
	void noteOff();
	
private:
	
	ofImage _img;	
};