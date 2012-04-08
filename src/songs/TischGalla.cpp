#include "TischGalla.h"

TischGalla::TischGalla()
{
	_name = "Tisch Galla";
}

void TischGalla::createAnimations()
{	
	/*-------------------------------------------------------------
	 sweeping tisch logo
	 --------------------------------------------------------------*/
	
    vector <string> imgNames;
	imgNames.push_back("tisch.png");
	AnimationRandomFade * animation1 = new AnimationRandomFade(imgNames);
	_animations.push_back(animation1);
	
	_loaded = true;	
}