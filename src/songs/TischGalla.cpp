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
    
    /* Stars
     --------------------------------------------------------------*/
	
	AnimationSequence * starsAnimation = new AnimationSequence("stars_masked/stars_loop.", "png", 1, 494, 3);
    starsAnimation->setTransitionTime(800);
	_animations.push_back(starsAnimation);
    
    /* Spare Slow Lights
     --------------------------------------------------------------*/
    
    vector <string> lights;
	lights.push_back("balloon3.png");
    
	AnimationRandomFade * delayLights = new AnimationRandomFade(lights);
    delayLights->setDuration(500);
    delayLights->setDelayBetween(1000);
    delayLights->setTransitionTime(500);
    _animations.push_back(delayLights);
    
    /* Full Slow Lights
     --------------------------------------------------------------*/
    
    AnimationRandomFade * noDelayLights = new AnimationRandomFade(lights);
	noDelayLights->setDuration(500);
    noDelayLights->setTransitionTime(500);
    _animations.push_back(noDelayLights); 
    
    /* Full Fast Lights
     --------------------------------------------------------------*/
    
    AnimationRandomFade * fastLights = new AnimationRandomFade(lights);
	fastLights->setDuration(150);
    fastLights->setTransitionTime(500);
    _animations.push_back(fastLights); 
    
    /* Words
     --------------------------------------------------------------*/
	
    vector <string> words;
    words.push_back("words2/breathe.png");
    words.push_back("words2/time.png");
	AnimationRandomFade * wordsAnimation = new AnimationRandomFade(words);
    wordsAnimation->setDuration(500);
    wordsAnimation->setTransitionTime(1000);
    //wordsAnimation->setDelayBetween(1000);
	_animations.push_back(wordsAnimation);
    
    /* Gray Heads
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
    grayHeadAnimation->setDuration(200);
    grayHeadAnimation->setDelayBetween(1000);
    grayHeadAnimation->setTransitionTime(500);
	_animations.push_back(grayHeadAnimation);
    
    /* Color Heads
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

    AnimationRandomFade * colorHeads = new AnimationRandomFade(heads);
	colorHeads->setDuration(150);
    colorHeads->setDelayBetween(1000);
    colorHeads->setReverse(true);
    _animations.push_back(colorHeads);
    
    
	_loaded = true;	
}