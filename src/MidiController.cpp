//
//  MidiController.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 11/10/2013.
//
//

#include "MidiController.h"

void MidiController::setup() {
	midiIn.listPorts(); // via instance
	
	controllerName = "UC-33 USB MIDI Controller";
	controllerFound = false;
	if ( midiIn.getNumPorts() > 0 ) {
		for ( int i = 0; i < midiIn.getNumPorts(); i++ ){
			if ( midiIn.getPortName(i).substr( 0,controllerName.length() ) == controllerName ) {
				controllerFound = true;
				midiIn.openPort( midiIn.getPortName(i) );
				cout << "controller found: " << midiIn.getPortName(i) << endl;
				break;
			}
		}
	}
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add testApp as a listener
	midiIn.addListener(this);
}

void MidiController::update() {
	
}

void MidiController::newMidiMessage(ofxMidiMessage& msg) {
	// make a copy of the latest message
	midiMessage = msg;
	
	//	ofLog() << "control: " << midiMessage.control << " value: " << midiMessage.value;
	
	float perc = midiMessage.value/127.0f;
	//ofLog() << "perc: " << perc;
	
	switch (midiMessage.control) {
		case 7: // MASTER F9
			mediator->setResolution(perc);
			break;
		case 8: // F1
			mediator->setVCount(perc);
			break;
		case 9: // F2
			mediator->setVWidth(perc);
			break;
		case 10: // F3
			mediator->setHCount(perc);
			break;
		case 12: // F4
			mediator->setHWidth(perc);
			break;
		case 13: // F5
			mediator->setVColors(perc);
			break;
		case 14: // F6
			mediator->setHColors(perc);
			break;
		case 15: // F7
			mediator->setColorRes(perc);
			break;
		case 16: // F8
			mediator->setDuration(perc);
			break;
		case 23: // C10
			mediator->setHueOffset(perc);
			break;
		case 39: // C18
			mediator->setSatOffset(perc);
			break;
		case 53: // C26
			mediator->setBriOffset(perc);
			break;
/*
		case 24: // C11
			// move these somewhere
			mediator->setStartHue(perc);
//			mediator->setEndHue(perc);
			break;
		case 29: // C16
			bgStartColor.set(bgStartColor.r, bgStartColor.g, perc*255);
			break;
		case 30: // C17
			bgEndColor.set(bgEndColor.r, bgEndColor.g, perc*255);
			break;
		case 40: // C19
			mediator->setEndSat(perc);
			break;
		case 45: // C24
			bgStartColor.set(bgStartColor.r, perc*255, bgStartColor.b);
			break;
		case 46: // C17
			bgEndColor.set(bgEndColor.r, perc*255, bgEndColor.b);
			break;
		case 54: // C27
			mediator->setEndBri(perc);
			break;
		case 59: // C32
			bgStartColor.set(perc*255, bgStartColor.g, bgStartColor.b);
			break;
		case 60: // C33
			bgEndColor.set(perc*255, bgEndColor.g, bgEndColor.b);
			break;
*/
	}
}