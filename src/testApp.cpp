#include "testApp.h"
#include "ToTweener.h"
#include "FromTweener.h"
#include "MidiController.h"
#include "OscController.h"
#include "SoundController.h"

const string testApp::OFF = "off";
const string testApp::MIDI_MEDIATOR = OFF;
const string testApp::OSC_MEDIATOR = OFF;
const string testApp::SOUND_MEDIATOR = Mediator::DIRECT;

testApp::testApp(ofxArgs* args) {
	this->args = args;
}

//--------------------------------------------------------------
void testApp::setup() {
	bool hasArgs = args->contains("-midi") || args->contains("-osc") || args->contains("-sound") || args->contains("-f");
	string midi = MIDI_MEDIATOR;
	string osc = OSC_MEDIATOR;
	string sound = SOUND_MEDIATOR;
	bool fullscreen = DEFAULT_FULLSCREEN;
	if (hasArgs) {
		midi = args->contains("-midi") ? args->getString("midi") : OFF;
		osc = args->contains("-osc") ? args->getString("osc") : OFF;
		sound = args->contains("-midi") ? args->getString("sound") : OFF;
		fullscreen = args->contains("-f");
	}
	
	if (midi != OFF) {
		controllers.push_back(new MidiController(getMediator(midi)));
	}
	
	if (osc != OFF) {
		controllers.push_back(new OscController(getMediator(osc)));
	}
	
	if (sound != OFF) {
		ofSetVerticalSync(true);
		controllers.push_back(new SoundController(getMediator(sound)));
	}
	
	if (fullscreen) {
		ofSetFullscreen(true);
	}
}

Mediator* testApp::getMediator(string type) {
	if (type == Tweener::TO) {
		return new ToTweener(&grid);
	}
	else if (type == Tweener::FROM) {
		return new FromTweener(&grid);
	}
	else {
		return new Mediator(&grid);
	}
}

//--------------------------------------------------------------
void testApp::update() {
	
	for (int i=0; i<controllers.size(); i++) {
		controllers[i]->update();
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	//ofBackgroundGradient(bgStartColor, bgEndColor);
	
	grid.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	//ofLog() << "key: " << key;
	switch (key) {
		case 'f':
			ofToggleFullscreen();
			break;
//		case 356: // left
//			grid.setHCount(grid.getHCount()-0.01);
//			break;
//		case 357: // up
//			grid.setVCount(grid.getVCount()+0.01);
//			break;
//		case 358: // right
//			grid.setHCount(grid.getHCount()+0.01);
//			break;
//		case 359: // down
//			grid.setVCount(grid.getVCount()-0.01);
//			break;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
