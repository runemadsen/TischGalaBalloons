#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "Constants.h"
#include "Balloon.h"

#define VIDEO_WIDTH 320.0
#define VIDEO_HEIGHT 240.0
#define VIDEO_X 22.0
#define VIDEO_Y 133.0
#define VIDEO_SCALE 2.0
#define POINT_MARGIN 20
#define NORMALIZED_SELECT 0.004
#define XML_FILE "points.xml"

class Sensing  
{
	
public:
	
	Sensing();
	
	void update();
	void draw();
    void exit();
	
	void mousePressed(int x, int y, int button);
	void mouseDragged(int x, int y, int button);
	
	void toggleMapFromScreen();
	
	vector <Balloon *> getBalloons();
	
	void drawBalloon(float xPos, float yPos, int color);
	void loadBalloons();
	void saveBalloons();
	
	void keyPressed(int key);
	
	bool shouldUpdateControllers();
	
	void forceUpdateControllers();
	
	bool getRecordMode();
	int getOffset();
	
private:
	
	void checkClick(float xPos, float yPos);
	int isClickWithinBalloon(float xPos, float yPos);
	void deleteSelectedBalloon();
	
	vector <Balloon *> _balloons;
	int _selectedBalloon;
	
	bool _balloonsUpdateFinished;
	bool _recordMode;

	int _idcount;
	int _offSet;
	
	ofxXmlSettings _xml;
	
	ofImage _head;
};