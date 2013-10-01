#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	midiIn.listPorts(); // via instance
	midiIn.openPort(0);
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add testApp as a listener
	midiIn.addListener(this);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	grid.draw();
}

//--------------------------------------------------------------
void testApp::newMidiMessage(ofxMidiMessage& msg) {
	// make a copy of the latest message
	midiMessage = msg;
	
	//ofLog() << "control: " << midiMessage.control << " value: " << midiMessage.value;
	switch (midiMessage.control) {
		case 8:
			grid.setHLines(midiMessage.value);
			break;
		case 9:
			grid.setVLines(midiMessage.value);
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	//ofLog() << "key: " << key;
	switch (key) {
		case 356: // left
			grid.setHLines(grid.getHLines()-1);
			break;
		case 357: // up
			grid.setVLines(grid.getVLines()+1);
			break;
		case 358: // right
			grid.setHLines(grid.getHLines()+1);
			break;
		case 359: // down
			grid.setVLines(grid.getVLines()-1);
			break;
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
