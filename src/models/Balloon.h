#pragma once

#include "ofMain.h"

class Balloon
{
	
public:
	
	Balloon();
	
	void setID(int id);
	void setCenterX(float x);
	void setCenterY(float y);
	void setScale(float scaleWidth, float scaleHeight);
		
	int getID();
	float getCenterX();
	float getCenterY();
	float getTopLeftX();
	float getTopLeftY();
	float getWidth();
	float getHeight();
	float getScaleWidth();
	float getScaleHeight();
	
	ofRectangle getBoundsFromSize(float width, float height, bool keepProportions = true);

private:
	
	ofRectangle _bounds;
	float _scaleWidth;
	float _scaleHeight;
	int _id;
};