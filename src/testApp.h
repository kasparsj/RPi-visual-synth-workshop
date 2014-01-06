#pragma once

#include "ofMain.h"
#include "ofxArgs.h"
#include "Gui.h"
#include "Grid.h"
#include "MidiController.h"
#include "OscController.h"
#include "SoundController.h"
#include "Mediator.h"
#include "Tweener.h"

class testApp : public ofBaseApp {
	
public:
	
	testApp(ofxArgs* args);
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
private:
	
	static const bool DEFAULT_FULLSCREEN = false;
	
	ofxArgs* args;
	Gui* gui;
	Grid* grid;
	MidiController* midi;
	OscController* osc;
	SoundController* sound;
	
//	ofColor bgStartColor;
//	ofColor bgEndColor;
};
