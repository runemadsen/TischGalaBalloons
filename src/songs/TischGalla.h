#pragma once

#include "Song.h"
#include "AnimationRandomFade.h"
#include "AnimationBlinker.h"
#include "AnimationEmpty.h"

class TischGalla : public Song
{
public:
    
	TischGalla();
	
	void createAnimations();
};


