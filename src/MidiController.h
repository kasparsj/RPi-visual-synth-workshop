#pragma once

#include "Controller.h"
#include "ofxMidi.h"

class MidiController : public Controller, public ofxMidiListener {
	
public:
	
	MidiController(Mediator* mediator);
	void setup(unsigned int portNumber);
	void tearDown();
	void update() {
		
	}
	vector<string>& getPortList();
	
private:
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
	
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	std::string controllerName;
	bool controllerFound;
};