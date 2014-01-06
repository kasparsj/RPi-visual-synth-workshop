#pragma once

#include "Controller.h"
#include "ofxMidi.h"

class MidiController : public Controller, public ofxMidiListener {
	
public:
	
	explicit MidiController(Mediator* mediator) : Controller(mediator) {
		setup();
	}
	void setup() override;
	vector<string>& getPortList();
	void openPort(unsigned int portNumber);
	
private:
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
	
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	std::string controllerName;
	bool controllerFound;
};