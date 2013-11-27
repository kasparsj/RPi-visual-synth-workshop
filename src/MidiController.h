#pragma once

#include "Controller.h"
#include "ofxMidi.h"

class MidiController : public Controller, public ofxMidiListener {
	
public:
	
	explicit MidiController(Mediator* mediator) : Controller(mediator) {
		setup();
	}
	void setup() override;
	void update() override;
	
private:
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
	
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	std::string controllerName;
	bool controllerFound;
};