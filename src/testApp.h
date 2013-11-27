#pragma once

#include "ofMain.h"
#include "ofxArgs.h"
#include "Grid.h"
#include "Controller.h"
#include "Mediator.h"
#include "Tweener.h"

class testApp : public ofBaseApp {
	
public:
	
	testApp(ofxArgs* args);
	void setup();
	void update();
	void draw();

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
	
	static const string OFF;
	static const string MIDI_MEDIATOR;
	static const string OSC_MEDIATOR;
	static const string SOUND_MEDIATOR;
	static const bool DEFAULT_FULLSCREEN = false;
	
	ofxArgs* args;
	
	Grid grid;
	Mediator* mediator;
	vector<Controller*> controllers;
	
	Mediator* getMediator(string type);
	
//	ofColor bgStartColor;
//	ofColor bgEndColor;
};
