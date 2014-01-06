#include "testApp.h"
#include "ToTweener.h"

testApp::testApp(ofxArgs* args) {
	this->args = args;

	grid = new Grid(ofGetWidth(), ofGetHeight());
	
	midi = new MidiController(new ToTweener(grid));
	osc = new OscController(new ToTweener(grid));
	sound = new SoundController(new Mediator(grid));
	
	gui = new Gui(ofGetHeight(), midi, osc, sound);
}

//--------------------------------------------------------------
void testApp::setup() {
	
	//ofSetFrameRate(120.0f);
	//ofSetVerticalSync(true);
	
	gui->setup();
	
	bool fullscreen = args->contains("-f") ? true : DEFAULT_FULLSCREEN;
	
	if (fullscreen) {
		ofSetFullscreen(true);
	}
}

//--------------------------------------------------------------
void testApp::update() {
	midi->update();
	osc->update();
	sound->update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	//ofBackgroundGradient(bgStartColor, bgEndColor);
	
	grid->draw();
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
		case 'h':
            gui->toggleVisible();
			break;
//		case 356: // left
//			grid->setHCount(grid->getHCount()-0.01);
//			break;
//		case 357: // up
//			grid->setVCount(grid->getVCount()+0.01);
//			break;
//		case 358: // right
//			grid->setHCount(grid->getHCount()+0.01);
//			break;
//		case 359: // down
//			grid->setVCount(grid->getVCount()-0.01);
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
	grid->resize(w, h);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::exit() {
	gui->exit();
}
