#include "TischGalla.h"

TischGalla::TischGalla()
{
	_name = "Tisch Galla";
}

void TischGalla::createAnimations()
{	
    /* Words
     --------------------------------------------------------------*/
	
    vector <string> words;
	words.push_back("words/act.png");
    words.push_back("words/be.png");
    words.push_back("words/breathe.png");
    words.push_back("words/dance.png");
    words.push_back("words/lyrics.png");
    words.push_back("words/music.png");
    words.push_back("words/sing.png");
    words.push_back("words/talk.png");
    words.push_back("words/theatre.png");
    words.push_back("words/tv.png");
    words.push_back("words/words.png");
	AnimationRandomFade * wordsAnimation = new AnimationRandomFade(words);
    wordsAnimation->setDuration(200);
    wordsAnimation->setDelayBetween(1000);
    wordsAnimation->setReverse(true);
	_animations.push_back(wordsAnimation);
    
    /* Heads Test
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
    AnimationRandomFade * headAnimation = new AnimationRandomFade(heads);
	headAnimation->setDuration(150);
    _animations.push_back(headAnimation);
    
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
	
	AnimationRandomFade * animation3 = new AnimationRandomFade(inverted);
	animation3->setColors(colors);
    animation3->setDuration(200);
    animation3->setDelayBetween(1000);
    _animations.push_back(animation3);
    
    /* No Delayed Purple Tisch Logo
     --------------------------------------------------------------*/
    
    AnimationRandomFade * noDelayPurple = new AnimationRandomFade(inverted);
	noDelayPurple->setDuration(150);
    noDelayPurple->setColors(colors);
    _animations.push_back(noDelayPurple);
    
    /* Purple Tisch Logo
     --------------------------------------------------------------*/
    
    vector <string> lights;
	lights.push_back("balloon3.png");
    
	AnimationRandomFade * delayLights = new AnimationRandomFade(lights);
    delayLights->setDuration(200);
    delayLights->setDelayBetween(1000);
    _animations.push_back(delayLights);
    
    /* No Delayed Purple Tisch Logo
     --------------------------------------------------------------*/
    
    AnimationRandomFade * noDelayLights = new AnimationRandomFade(lights);
	noDelayLights->setDuration(150);
    _animations.push_back(noDelayLights);
    
    /*-------------------------------------------------------------
	 Blinking white lights
	 --------------------------------------------------------------*/
	
	AnimationBlinker * animation5 = new AnimationBlinker(lights);
    animation5->setFadeTime(150);
    animation5->setRandomAlpha(true);
	_animations.push_back(animation5);
    

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
    
	_loaded = true;	
}