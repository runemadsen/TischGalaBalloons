/*
 *  AnimationFull.cpp
 *  2tracks
 *
 *  Created by Rune Madsen on 7/16/10.
 *  Copyright 2010 New York University. All rights reserved.
 *
 */

#include "AnimationFull.h"

/* Constructor
 ___________________________________________________________ */

AnimationFull::AnimationFull()
{
	_useMask = true;
}

void AnimationFull::setMask(ofImage * mask)
{
	_mask = mask;
}

void AnimationFull::setBounds(ofRectangle * bounds)
{
	_bounds = bounds;
}
