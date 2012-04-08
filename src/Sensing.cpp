#include "Sensing.h"

/* Constructor
 ___________________________________________________________ */

Sensing::Sensing()
{
	_head.loadImage("head.png");
	_recordMode = false;
	
	_selectedBalloon = DISABLED;
	_idcount = 0;
	
	_balloonsUpdateFinished = false;	
	
	_offSet = 0;
}

/* Update
 ___________________________________________________________ */

void Sensing::update()
{	
}

/* Draw
 ___________________________________________________________ */

void Sensing::draw()
{	
	if(_recordMode)
	{
		vector <Balloon *> balloons = getBalloons();
		
		for(int i = 0; i < balloons.size(); i++)
		{
			// draw circle around
			ofSetColor(0, 0, 255);
			ofFill();
			ofEllipse(balloons[i]->getCenterX(), balloons[i]->getCenterY(), balloons[i]->getWidth(),balloons[i]->getHeight());
            ofSetColor(255, 255, 255);
			ofNoFill();
			ofEllipse(balloons[i]->getCenterX(), balloons[i]->getCenterY(), balloons[i]->getWidth(), balloons[i]->getHeight());
			
			ofRectangle bounds = balloons[i]->getBoundsFromSize(_head.getWidth(), _head.getHeight());
			
			ofSetColor(255, 255, 255, 255);
			
			//ofEnableAlphaBlending();
			//_head.draw(bounds.x, bounds.y + _offSet, bounds.width, bounds.height);
			//ofDisableAlphaBlending();
			
			ofSetColor(0, 255, 0);
			
			if(i == _selectedBalloon)	
			{
				drawBalloon(balloons[i]->getCenterX(), balloons[i]->getCenterY(), 0x000FF00);
			}
			else
			{
				drawBalloon(balloons[i]->getCenterX(), balloons[i]->getCenterY(), 0xFF0000);
			}
		}	
	}
}

void Sensing::drawBalloon(float xPos, float yPos, int color)
{
	// draw bulleye
	ofSetColor(color);
	
	ofFill();
	ofCircle(xPos, yPos, 3);
	
	ofNoFill();
	ofCircle(xPos, yPos, 3);
	ofCircle(xPos, yPos, 8);
}

/* Mouse
___________________________________________________________ */

void Sensing::mousePressed(int xPos, int yPos, int button)
{	
	if(_recordMode)
	{
		checkClick(xPos, yPos);
	}
}

void Sensing::mouseDragged(int xPos, int yPos, int button)
{
	if(_recordMode && _selectedBalloon != DISABLED)
	{
		_balloons[_selectedBalloon]->setCenterX(xPos);
		_balloons[_selectedBalloon]->setCenterY(yPos);
	}
}

void Sensing::checkClick(float xPos, float yPos)
{
	int index = isClickWithinBalloon(xPos, yPos);
	
	if(index == DISABLED)
	{
		if (_selectedBalloon == DISABLED) 
		{
			Balloon * newBalloon = new Balloon();
			newBalloon->setCenterX(xPos);
			newBalloon->setCenterY(yPos);
			newBalloon->setID(_idcount);
			
			_balloons.push_back(newBalloon);
			
			_idcount++;
		}
		else 
		{
			_selectedBalloon = DISABLED;
		}
	}
	else 
	{
		_selectedBalloon = index;
	}
}

/* Utilities
___________________________________________________________ */

int Sensing::isClickWithinBalloon(float xPos, float yPos)
{	
	for(int i = 0; i < _balloons.size(); i++)
	{
		if(fabs(xPos - _balloons[i]->getCenterX()) < POINT_MARGIN && fabs(yPos - _balloons[i]->getCenterY()) < POINT_MARGIN)
		{
			return i;
		}
	}
	
	return DISABLED;
}

void Sensing::deleteSelectedBalloon()
{
	if(_selectedBalloon != DISABLED)
	{
		delete _balloons[_selectedBalloon];
		_balloons.erase(_balloons.begin() + _selectedBalloon);
		_selectedBalloon = DISABLED;
	}
}

/* Loading / Saving
 ___________________________________________________________ */

void Sensing::loadBalloons()
{
	if(_xml.loadFile(XML_FILE))
	{
		for(int i = 0; i<_balloons.size(); i++)
		{
			delete _balloons[i];
		}
		
		_balloons.clear();
		
		if(_xml.pushTag("points", 0))
		{
			for(int i = 0; i < _xml.getNumTags("point"); i++) 
			{
				Balloon * point = new Balloon();
				point->setID(_idcount);
				point->setCenterX( (float) _xml.getAttribute("point", "x", 0, i) );
				point->setCenterY( (float) _xml.getAttribute("point", "y", 0, i) );
				point->setScale( (float) _xml.getAttribute("point", "scalewidth", 1.00, i), (float) _xml.getAttribute("point", "scaleheight", 1.00, i));
				_balloons.push_back(point);
				
				_idcount++;
			}
			
			_xml.popTag();
		}
		
		_offSet = _xml.getAttribute("offset", "headOffset", 0, 0);
	}
	
	_balloonsUpdateFinished = true;
	
	cout << ":::::::::::: Balloons were loaded ::::::::::::" << endl;
}

void Sensing::saveBalloons()
{	
	_xml.clear();
	
	_xml.addTag("points");
	_xml.pushTag("points", 0);
	
	for(int i = 0; i < _balloons.size(); i++)
	{
		_xml.addTag("point");
		_xml.addAttribute("point", "x", ofToString(_balloons[i]->getCenterX(), 1), i);
		_xml.addAttribute("point", "y", ofToString(_balloons[i]->getCenterY(), 1), i);
		_xml.addAttribute("point", "scalewidth", ofToString(_balloons[i]->getScaleWidth(), 2), i);
		_xml.addAttribute("point", "scaleheight", ofToString(_balloons[i]->getScaleHeight(), 2), i);
	}
	
	_xml.popTag();
	
	_xml.addTag("offset");
	_xml.addAttribute("offset", "headOffset", ofToString(_offSet, 1), 0);
	
	_xml.saveFile(XML_FILE);
	
	cout << ":::::::::::: Balloons were saved ::::::::::::" << endl;
}

void Sensing::forceUpdateControllers()
{
	_balloonsUpdateFinished = true;
}

/* Getters / Setters
___________________________________________________________ */

vector <Balloon *> Sensing::getBalloons()
{
	vector <Balloon *> norm;
	
	for(int i = 0; i < _balloons.size(); i++)
	{
		Balloon * newPoint = new Balloon();
		newPoint->setID(_balloons[i]->getID());
		newPoint->setCenterX(_balloons[i]->getCenterX());
		newPoint->setCenterY(_balloons[i]->getCenterY());
		
		/*if(i == _selectedBalloon)
		{
			_balloons[_selectedBalloon]->setScale( _scaleWidthSelected, _scaleHeightSelected);
		}*/
		
		newPoint->setScale(_balloons[i]->getScaleWidth(), _balloons[i]->getScaleHeight());
		
		norm.push_back(newPoint);
	}
	
	return norm;
}

bool Sensing::shouldUpdateControllers()
{
	if(_balloonsUpdateFinished)
	{
		_balloonsUpdateFinished = false;
		
		return true;
	}
	
	return false;
}

void Sensing::toggleMapFromScreen()
{
	_recordMode = !_recordMode;
	
	if(!_recordMode)
	{
		_balloonsUpdateFinished = true;
		
		_selectedBalloon = DISABLED;
	}
	
	string output = _recordMode ? "On" : "Off";
	
	cout << ":::::::::::: Record Mode: " << output << " ::::::::::::" << endl;
}

bool Sensing::getRecordMode()
{
	return _recordMode;
}

int Sensing::getOffset()
{
	return _offSet;
} 

/* Key press
 ___________________________________________________________ */

void Sensing::keyPressed(int key)
{	
	
	if (key == 'r') 
	{
		toggleMapFromScreen();
	}
	else if (key == 'S') 
	{
		saveBalloons();
	}	
	else if (key == 'L') 
	{
		loadBalloons();
	}
	
	if(_recordMode)
	{
		// delete
		if(key == 127)
		{
			deleteSelectedBalloon();
		}
		// right arrow
		else if (key == 358) 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setCenterX( _balloons[_selectedBalloon]->getCenterX() + 1 );
			}
		}
		// left arrow
		else if (key == 356) 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setCenterX( _balloons[_selectedBalloon]->getCenterX() - 1 );
			}
		}
		// up arrow
		else if (key == 357) 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setCenterY( _balloons[_selectedBalloon]->getCenterY() - 1 );
			}
		}
		// down arrow
		else if (key == 359) 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setCenterY( _balloons[_selectedBalloon]->getCenterY() + 1 );
			}
		}
		else if (key == 'w') 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setScale(_balloons[_selectedBalloon]->getScaleWidth() - 0.01, _balloons[_selectedBalloon]->getScaleHeight());
			}
		}
		else if (key == 'q') 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setScale(_balloons[_selectedBalloon]->getScaleWidth() + 0.01, _balloons[_selectedBalloon]->getScaleHeight());
			}
		}
		else if (key == 'x') 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setScale(_balloons[_selectedBalloon]->getScaleWidth(), _balloons[_selectedBalloon]->getScaleHeight() - 0.01);
			}
		}
		else if (key == 'z') 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setScale(_balloons[_selectedBalloon]->getScaleWidth(), _balloons[_selectedBalloon]->getScaleHeight() + 0.01);
			}
		}
		else if (key == 's') 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setScale(_balloons[_selectedBalloon]->getScaleWidth() - 0.01, _balloons[_selectedBalloon]->getScaleHeight() - 0.01);
			}
		}
		else if (key == 'a') 
		{
			if(_selectedBalloon != DISABLED)
			{
				_balloons[_selectedBalloon]->setScale(_balloons[_selectedBalloon]->getScaleWidth() + 0.01, _balloons[_selectedBalloon]->getScaleHeight() + 0.01);
			}
		}
		else if (key == 'o') 
		{
			_offSet++;
		}
		else if (key == 'i') 
		{
			_offSet--;
		}
	}
}

/* Exit
 ___________________________________________________________ */

void Sensing::exit()
{
    for(int i = 0; i < _balloons.size(); i++)
    {
        delete _balloons[i];
    }
    
    _balloons.clear();
}