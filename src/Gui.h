#pragma once

#include "ofConstants.h"
#include "ofxUI.h"
#include "ofLog.h"
#include "MidiController.h"
#include "OscController.h"
#include "SoundController.h"

class Gui {
	
public:
	
	Gui(int height, Grid* grid, SoundController* sound, MidiController* midi, OscController* osc) {
		_height = height;
		this->grid = grid;
		this->sound = sound;
		this->midi = midi;
		this->osc = osc;
	}
	void setup();
	void setGridGui();
	void setSoundGui();
	void initSound();
	void setMidiGui();
	void initMidi();
	void setOscGui();
	void guiEvent(ofxUIEventArgs &e);
	void toggleVisible();
	void exit();
	
private:
	
	int _height;
	Grid* grid;
	SoundController* sound;
	MidiController* midi;
	OscController* osc;
	ofxUICanvas *gridGui;
	ofxUICanvas *soundGui;
	ofxUICanvas *midiGui;
	ofxUICanvas *oscGui;
	ofxUIDropDownList* midiDropDown;
	ofxUIDropDownList* soundDropDown;
	
};