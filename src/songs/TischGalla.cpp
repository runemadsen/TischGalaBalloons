#include "TischGalla.h"

TischGalla::TischGalla()
{
	_name = "Tisch Galla";
}

void TischGalla::createAnimations()
{	
	/* Delayed Tisch Logo
    --------------------------------------------------------------*/
	
    vector <string> imgNames;
	imgNames.push_back("tisch.png");
	AnimationRandomFade * animation1 = new AnimationRandomFade(imgNames);
    animation1->setDuration(200);
    animation1->setDelayBetween(1000);
	_animations.push_back(animation1);
    
    /* No Delayed Tisch Logo
     --------------------------------------------------------------*/
    
    AnimationRandomFade * animation2 = new AnimationRandomFade(imgNames);
	animation2->setDuration(150);
    _animations.push_back(animation2);
    
    /* Purple Tisch Logo
     --------------------------------------------------------------*/
    
    vector <string> inverted;
	inverted.push_back("tisch_inverted.png");
    
    vector <ofColor> colors;
	
	ofColor aColor;
	aColor.r = 122;
	aColor.g = 6;
	aColor.b = 211;
	colors.push_back(aColor);
	
	AnimationBlinker * animation3 = new AnimationBlinker(inverted);
	animation3->setColors(colors);
    animation3->setFadeTime(100);
	animation3->setRandomAlpha(true);
    _animations.push_back(animation3);
    
    /* All kinds of colors Tisch Logo
     --------------------------------------------------------------*/
    
	aColor.r = 66;
	aColor.g = 152;
	aColor.b = 46;
	colors.push_back(aColor);
    
    aColor.r = 212;
	aColor.g = 200;
	aColor.b = 14;
	colors.push_back(aColor);
    
    aColor.r = 212;
	aColor.g = 23;
	aColor.b = 14;
	colors.push_back(aColor);
	
	AnimationBlinker * animation4 = new AnimationBlinker(inverted);
	animation4->setColors(colors);
    animation4->setFadeTime(100);
	animation4->setRandomAlpha(true);
    _animations.push_back(animation4);
    
    /*-------------------------------------------------------------
	 Blinking white lights
	 --------------------------------------------------------------*/
	
    imgNames.clear();
	imgNames.push_back("balloon3.png");
	AnimationBlinker * animation5 = new AnimationBlinker(imgNames);
    animation5->setFadeTime(150);
    animation5->setRandomAlpha(true);
	_animations.push_back(animation5);
    
	_loaded = true;	
}