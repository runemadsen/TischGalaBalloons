#include "ScreenSaver.h"

ScreenSaver::ScreenSaver()
{
	_name = "Screensaver";
}

void ScreenSaver::createAnimations()
{
	/*-------------------------------------------------------------
	 Letters
	 --------------------------------------------------------------*/
	
	vector <string> imgNames;
	imgNames.push_back("letters/o.png");
	imgNames.push_back("letters/h.png");
	imgNames.push_back("letters/l.png");
	imgNames.push_back("letters/a.png");
	imgNames.push_back("letters/n.png");
	imgNames.push_back("letters/d.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	
	AnimationSweep * animation1 = new AnimationSweep(imgNames);
	_animations.push_back(animation1);
	
	/*-------------------------------------------------------------
	 Planets
	 --------------------------------------------------------------*/
	
	imgNames.clear();
	imgNames.push_back("planets/earth.png");
	imgNames.push_back("planets/jupiter.png");
	imgNames.push_back("planets/mars.png");
	imgNames.push_back("planets/mercury.png");
	imgNames.push_back("planets/neptune.png");
	imgNames.push_back("planets/pluto.png");
	imgNames.push_back("planets/saturn.png");
	imgNames.push_back("planets/uranus.png");
	imgNames.push_back("planets/venus.png");
	
	AnimationImages * animation2 = new AnimationImages(imgNames);
	_animations.push_back(animation2);
	
	/*-------------------------------------------------------------
	 Houses
	 --------------------------------------------------------------*/
	
	vector <string> videoNames;
	videoNames.push_back("houses/peachCasa2.mov");
	videoNames.push_back("houses/pinkCasa2.mov");
	videoNames.push_back("houses/purpleCasa2.mov");
	
	AnimationVideos * animation3 = new AnimationVideos(videoNames);
	_animations.push_back(animation3);
	
	
	_loaded = true;
}