#include "testApp.h"

/* Setup
-------------------------------------------------------------- */

void testApp::setup()
{
	ofSetWindowTitle("Tisch Galla");
    ofSetFrameRate(60);
    
    keyControl = false;
	oPressed = false;
	shouldStartSong = true;
	currentSong = 0;
	oldSong = 0;
    
    stage.loadImage("stage.png");
	ofBackground(0, 0, 0);
	ofEnableSmoothing();
	
	sensing = new Sensing();
	
	songs.push_back(new TischGalla());
	songs[0]->createAnimations();
	
	//songs.push_back(new ScreenSaver());
	//songs[13]->setBank(20);
}

/* Update
-------------------------------------------------------------- */

void testApp::update()
{
    if(shouldStartSong)
	{
		songs[oldSong]->destroyAnimations();
		songs[currentSong]->createAnimations();
		sensing->forceUpdateControllers();
	}
	
	sensing->update();
	
	if(sensing->shouldUpdateControllers())
	{
		songs[currentSong]->updateControllers(sensing->getBalloons());
	}
	
	if(shouldStartSong)
	{
		songs[currentSong]->changeAnimation(0);
		shouldStartSong = false;
	}
	
	songs[currentSong]->update();
}

/* Draw
-------------------------------------------------------------- */

void testApp::draw()
{
	ofSetColor(255, 255, 255);
    stage.draw(0, 0);
	songs[currentSong]->draw();
	sensing->draw();
    //string frameNum = ofToString(ofGetFrameNum());  
    //ofSaveScreen("render/file" +frameNum + ".png");
    //cout << "rendered " << frameNum << endl;
}

/* Change song
-------------------------------------------------------------- */

void testApp::changeSong(int bankNum)
{	
	if (bankNum >= 0) 
	{
        for(int i = 0; i < songs.size(); i++)
		{
			if(bankNum == songs[i]->getBank())
			{
				oldSong = currentSong;
				currentSong = i;
				shouldStartSong = true;
				
				cout << "-----> SONG CHANGED: " << songs[currentSong]->getName() << endl;
				
				break;
			}
		}
	}
}

/* Keypressed
 -------------------------------------------------------------- */

void testApp::keyPressed  (int key)
{
    sensing->keyPressed(key);
	
	if(keyControl)
	{
		// change song manually
		if (key == 356) // left arrow
		{
			int prevSong = currentSong - 1 < 0 ? 0 : currentSong - 1; 
			
			changeSong(songs[prevSong]->getBank());
		}
		else if(key == 358) // right arrow
		{
			int nextSong = currentSong + 1 >= songs.size() ? songs.size() - 1 : currentSong + 1;
			
			changeSong(songs[nextSong]->getBank());
		}
		
		// change animation manually
		if(key > '0' && key <= '9')
		{
			int convert = key - '0';
			
			convert = convert - 1;
			
			songs[currentSong]->changeAnimation(convert);
		}
		
		// Blink all balloons in animation
		if(key == 'o')
		{
			if (!oPressed) 
			{
				songs[currentSong]->currentAnimation()->allOn();
				
				oPressed = true;
			}
		}
	}
	
	// fullscreen
	if (key =='f' || key=='F') 
	{
		ofToggleFullscreen();
	} 
	
	// Enable keyControl
	if (key =='k') 
	{
		keyControl = !keyControl;
		
		string output = keyControl ? "Enabled" : "Disabled";
		
		cout << ":::::::::::: KeyControl " << output << " ::::::::::::" << endl;
		
	}
}


void testApp::keyReleased(int key)
{
    // Blink all balloons in animation
	if(key == 'o')
	{
		if(oPressed)
		{
			songs[currentSong]->currentAnimation()->allOff();
            
			oPressed = false;
		}
	}
}


void testApp::mouseMoved(int x, int y ){}

void testApp::mouseDragged(int x, int y, int button) {
    sensing->mouseDragged(x, y, button);
}

void testApp::mousePressed(int x, int y, int button) {
    sensing->mousePressed(x, y, button);
}

void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}

void testApp::exit() {
    sensing->exit();
    delete sensing;
    
    for(int i = 0; i < songs.size(); i++)
    {
        songs[i]->destroyAnimations();
        delete songs[i];
    }
    
    songs.clear();
}