#include "TischGalla.h"

TischGalla::TischGalla()
{
	_name = "Tisch Galla";
}

void TischGalla::createAnimations()
{	
    AnimationEmpty * empty = new AnimationEmpty();
    empty->setTransitionTime(1000);
	_animations.push_back(empty);
    
    /* 2) Stars
     --------------------------------------------------------------*/
	
	AnimationSequence * starsAnimation = new AnimationSequence("stars_masked/stars_loop.", "png", 1, 494, 3);
    starsAnimation->setTransitionTime(800);
	_animations.push_back(starsAnimation);
    
    /* 3) Spare Slow Lights
     --------------------------------------------------------------*/
    
    vector <string> lights;
	lights.push_back("balloon3.png");
    
	AnimationRandomFade * delayLights = new AnimationRandomFade(lights);
    delayLights->setDuration(500);
    delayLights->setDelayBetween(1000);
    delayLights->setTransitionTime(500);
    _animations.push_back(delayLights);
    
    /* 4) Full Static lights
     --------------------------------------------------------------*/
    
	AnimationImages * fullStatic = new AnimationImages(lights);
    fullStatic->setTransitionTime(500);
    _animations.push_back(fullStatic);
    
    /* 5) Full Slow Lights
     --------------------------------------------------------------*/
    
    AnimationRandomFade * noDelayLights = new AnimationRandomFade(lights);
	noDelayLights->setDuration(500);
    noDelayLights->setTransitionTime(500);
    _animations.push_back(noDelayLights); 
    
    /* 6) Full Fast Lights
     --------------------------------------------------------------*/
    
    vector <string> goldlights;
	goldlights.push_back("balloongold.png");
    
    AnimationRandomFade * fastLights = new AnimationRandomFade(goldlights);
	fastLights->setDuration(300);
    fastLights->setTransitionTime(500);
    _animations.push_back(fastLights); 
    
    /* 7) Flow
     --------------------------------------------------------------*/
	
    vector <string> words;
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("letters/f.png");
    words.push_back("letters/l.png");
    words.push_back("letters/o.png");
    words.push_back("letters/w.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("letters/f.png");
    words.push_back("letters/l.png");
    words.push_back("letters/o.png");
    words.push_back("letters/w.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
	AnimationRandomFade * wordsAnimation = new AnimationRandomFade(words);
    wordsAnimation->setUseBackground(true);
    wordsAnimation->setDuration(500);
    wordsAnimation->setTransitionTime(400);
	_animations.push_back(wordsAnimation);
    
    /* 8) Breathe
     --------------------------------------------------------------*/
	
    words.clear();
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("letters/b.png");
    words.push_back("letters/r.png");
    words.push_back("letters/e.png");
    words.push_back("letters/a.png");
    words.push_back("letters/t.png");
    words.push_back("letters/h.png");
    words.push_back("letters/e.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("letters/b.png");
    words.push_back("letters/r.png");
    words.push_back("letters/e.png");
    words.push_back("letters/a.png");
    words.push_back("letters/t.png");
    words.push_back("letters/h.png");
    words.push_back("letters/e.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
    words.push_back("balloon3.png");
	AnimationRandomFade * breatheAnimation = new AnimationRandomFade(words);
    breatheAnimation->setUseBackground(true);
    breatheAnimation->setDuration(500);
    breatheAnimation->setTransitionTime(1000);
	_animations.push_back(breatheAnimation);
    
    /* 9) Gray Heads
     --------------------------------------------------------------*/
    
    vector <string> grayheads;
	grayheads.push_back("grayheads/430316.png");
    grayheads.push_back("grayheads/555317.png");
    grayheads.push_back("grayheads/alexa.png");
    grayheads.push_back("grayheads/alisonwien.png");
    grayheads.push_back("grayheads/chrisbryan.png");
    grayheads.push_back("grayheads/cody.png");
    grayheads.push_back("grayheads/headshot.png");
    grayheads.push_back("grayheads/img6871.png");
    grayheads.push_back("grayheads/img7378.png");
    grayheads.push_back("grayheads/kalimcburney.png");
    grayheads.push_back("grayheads/kaylakleinman.png");
    grayheads.push_back("grayheads/keithleroyal.png");
    grayheads.push_back("grayheads/kristenleigh.png");
    grayheads.push_back("grayheads/mdejohn.png");
    grayheads.push_back("grayheads/meghan.png");
    grayheads.push_back("grayheads/mialongenecker.png");
    grayheads.push_back("grayheads/mollyhoran.png");
    grayheads.push_back("grayheads/test.png");
    grayheads.push_back("grayheads/sc01f408b5.png");
    grayheads.push_back("grayheads/megangriffith.png");
    grayheads.push_back("grayheads/emily.png");
    grayheads.push_back("grayheads/caroline.png");
    
    AnimationRandomFade * grayHeadAnimation = new AnimationRandomFade(grayheads);
    grayHeadAnimation->setDuration(500);
    grayHeadAnimation->setDelayBetween(1000);
    grayHeadAnimation->setTransitionTime(500);
	_animations.push_back(grayHeadAnimation);
    
    /* 10) Full Static Faces
     --------------------------------------------------------------*/
    
	AnimationImages * fullStaticHeads = new AnimationImages(grayheads);
    fullStaticHeads->setTransitionTime(500);
    _animations.push_back(fullStaticHeads);

    
    /* 11) Color Heads
     --------------------------------------------------------------*/
    
    vector <string> heads;
	heads.push_back("heads/430316.png");
    heads.push_back("heads/555317.png");
    heads.push_back("heads/alexa.png");
    heads.push_back("heads/alisonwien.png");
    heads.push_back("heads/chrisbryan.png");
    heads.push_back("heads/cody.png");
    heads.push_back("heads/headshot.png");
    heads.push_back("heads/img6871.png");
    heads.push_back("heads/img7378.png");
    heads.push_back("heads/kalimcburney.png");
    heads.push_back("heads/kaylakleinman.png");
    heads.push_back("heads/keithleroyal.png");
    heads.push_back("heads/kristenleigh.png");
    heads.push_back("heads/mdejohn.png");
    heads.push_back("heads/meghan.png");
    heads.push_back("heads/mialongenecker.png");
    heads.push_back("heads/mollyhoran.png");
    heads.push_back("heads/test.png");
    heads.push_back("heads/sc01f408b5.png");
    heads.push_back("heads/megangriffith.png");
    heads.push_back("heads/emily.png");
    heads.push_back("heads/caroline.png");

    AnimationImages * fullStaticColorHeads = new AnimationImages(heads);
    fullStaticColorHeads->setTransitionTime(500);
    _animations.push_back(fullStaticColorHeads);
    
    
	_loaded = true;	
}