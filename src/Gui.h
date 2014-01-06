#pragma once

#include "ofConstants.h"
#include "ofxUI.h"
#include "ofLog.h"
#include "MidiController.h"
#include "OscController.h"
#include "SoundController.h"

class Gui {
	
public:
	
	Gui(int height, MidiController* midi, OscController* osc, SoundController* sound) {
		_height = height;
		this->midi = midi;
		this->osc = osc;
		this->sound = sound;
	}
	void setup();
	void initMidi();
	void guiEvent(ofxUIEventArgs &e);
	void toggleVisible();
	void exit();
	
private:
	
	int _height;
	MidiController* midi;
	OscController* osc;
	SoundController* sound;
	ofxUICanvas *canvas;
	ofxUIDropDownList* midiDropDown;
	
};