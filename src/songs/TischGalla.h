#pragma once

#include "Song.h"
#include "AnimationRandomFade.h"
#include "AnimationBlinker.h"
#include "AnimationEmpty.h"
#include "AnimationSequence.h"
#include "AnimationImages.h"

class TischGalla : public Song
{
public:
    
	TischGalla();
	
	void createAnimations();
};


