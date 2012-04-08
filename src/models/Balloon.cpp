#include "Balloon.h"

/* Constructor
 ___________________________________________________________ */

Balloon::Balloon()
{
	_bounds.width = 64;
	_bounds.height = 64;
	
	_scaleWidth = 1; 
	_scaleHeight = 1; 
}

/* Getters
 ___________________________________________________________ */

int Balloon::getID() 
{ 
	return _id; 
}

float Balloon::getCenterX() 
{ 
	return _bounds.x; 
}

float Balloon::getCenterY() 
{ 
	return _bounds.y; 
}

float Balloon::getTopLeftX() 
{ 
	return _bounds.x - (_bounds.width / 2); 
}

float Balloon::getTopLeftY() 
{ 
	return _bounds.y - (_bounds.height / 2); 
}

float Balloon::getWidth() 
{ 
	return _bounds.width * _scaleWidth; 
}

float Balloon::getHeight() 
{ 
	return _bounds.height * _scaleHeight; 
}

float Balloon::getScaleWidth() 
{ 
	return _scaleWidth; 
}

float Balloon::getScaleHeight() 
{ 
	return _scaleHeight; 
}

ofRectangle Balloon::getBoundsFromSize(float width, float height, bool keepProportions)
{
	ofRectangle bounds;
	
	float wDiff = getWidth() / width;
	float hDiff = getHeight() / height;
	
	if(keepProportions)
	{
		if(wDiff < hDiff)
		{
			bounds.width = width * wDiff;
			bounds.height = height * wDiff;
		}
		else 
		{
			bounds.width = width * hDiff;
			bounds.height = height * hDiff;
		}
	}
	else 
	{
		bounds.width = width * wDiff;
		bounds.height = height * hDiff;
	}

	
	bounds.x = _bounds.x - (bounds.width / 2);
	bounds.y = _bounds.y - (bounds.height / 2);
	
	return bounds;
}

/* Setters
 ___________________________________________________________ */

void Balloon::setID(int id) 
{
	_id = id; 
}

void Balloon::setCenterX(float x) 
{ 
	_bounds.x = x; 
}

void Balloon::setCenterY(float y) 
{ 
	_bounds.y = y; 
}

void Balloon::setScale(float scaleWidth, float scaleHeight) 
{ 
	_scaleWidth = scaleWidth;
	_scaleHeight = scaleHeight;
}