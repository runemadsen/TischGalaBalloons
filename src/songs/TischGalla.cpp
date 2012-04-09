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
    
	_loaded = true;	
}