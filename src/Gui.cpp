//
//  Gui.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 06/01/2014.
//
//

#include "Gui.h"

void Gui::setup() {
	setGridGui();
	setSoundGui();
	setMidiGui();
	setOscGui();
}

void Gui::setGridGui() {
	float dim = 16;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 255-xInit;

	gridGui = new ofxUICanvas(0, 0, length+xInit, _height);
	gridGui->addWidgetDown(new ofxUILabel("PANEL 1: GRID", OFX_UI_FONT_LARGE));
//    gridGui->addWidgetDown(new ofxUILabel("Press 'h' to Hide GUIs", OFX_UI_FONT_LARGE));
//	
//    gridGui->addSpacer(length-xInit, 2);
//    gridGui->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));
	
	gridGui->addWidgetDown(new ofxUILabel("Resolution", OFX_UI_FONT_MEDIUM));
	gridGui->addSlider("RESOLUTION", 0, 1, grid->getResolution(), length-xInit, dim);
	
	gridGui->addWidgetDown(new ofxUILabel("VCount", OFX_UI_FONT_MEDIUM));
	gridGui->addSlider("VCOUNT", 0, 1, grid->getVCount(), length-xInit, dim);
	
	gridGui->addWidgetDown(new ofxUILabel("VWidth", OFX_UI_FONT_MEDIUM));
	gridGui->addSlider("VWIDTH", 0, 1, grid->getVWidth(), length-xInit, dim);
	
	gridGui->addWidgetDown(new ofxUILabel("HCount", OFX_UI_FONT_MEDIUM));
	gridGui->addSlider("HCOUNT", 0, 1, grid->getHCount(), length-xInit, dim);
	
	gridGui->addWidgetDown(new ofxUILabel("HWidth", OFX_UI_FONT_MEDIUM));
	gridGui->addSlider("HWIDTH", 0, 1, grid->getHWidth(), length-xInit, dim);
	
	gridGui->addWidgetDown(new ofxUILabel("VColors", OFX_UI_FONT_MEDIUM));
	gridGui->addSlider("VCOLORS", 0, 1, grid->getVColors(), length-xInit, dim);
	
	gridGui->addWidgetDown(new ofxUILabel("HColors", OFX_UI_FONT_MEDIUM));
	gridGui->addSlider("HCOLORS", 0, 1, grid->getHColors(), length-xInit, dim);
	
	gridGui->addWidgetDown(new ofxUILabel("Color resolution", OFX_UI_FONT_MEDIUM));
	gridGui->addSlider("COLORES", 0, 1, grid->getColorRes(), length-xInit, dim);
	
	ofAddListener(gridGui->newGUIEvent, this, &Gui::guiEvent);
	
	gridGui->loadSettings("GUI/grid.xml");
}

void Gui::setSoundGui() {
	float dim = 16;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 255-xInit;

	soundGui = new ofxUICanvas(length+xInit+2, 0, length+xInit, _height);
	soundGui->addWidgetDown(new ofxUILabel("PANEL 2: SOUND", OFX_UI_FONT_LARGE));
	
    soundGui->addSpacer(length-xInit, 2);
	soundGui->addWidgetDown(new ofxUILabel("Sound", OFX_UI_FONT_MEDIUM));
	
	vector<string> values = sound->getDeviceList();
	values.insert(values.begin(), "-- none --");
	soundDropDown = soundGui->addDropDownList("SOUND", values);
	soundDropDown->setShowCurrentSelected(true);
	soundDropDown->setAutoClose(true);
	soundDropDown->triggerEvent(soundDropDown->getToggles()[0]);
	
	soundGui->addWidgetDown(new ofxUIButton( "Refresh", false, dim, dim));
	
	soundGui->addWidgetDown(new ofxUILabel("Smoothing", OFX_UI_FONT_MEDIUM));
	soundGui->addIntSlider("SMOOTHING", 0, 100, sound->SMOOTHING, length-xInit, dim);
	
	soundGui->addWidgetDown(new ofxUILabel("Threshold", OFX_UI_FONT_MEDIUM));
	soundGui->addIntSlider("THRESHOLD", 0, 100, sound->THRESHOLD, length-xInit, dim);
	
	ofAddListener(soundGui->newGUIEvent, this, &Gui::guiEvent);
	
	soundGui->loadSettings("GUI/sound.xml");
	
	// loadSettings won't select for real
	vector<ofxUILabelToggle *> toggles = soundDropDown->getToggles();
	for (int i=0; i<toggles.size(); i++) {
		if (toggles[i]->getValue()) {
			soundDropDown->triggerEvent(toggles[i]);
		}
	}
}

void Gui::initSound() {
	int selectedIndex = soundDropDown->getSelectedIndeces()[0];
	if (selectedIndex > 0) {
		sound->setup(selectedIndex-1);
	}
	else {
		sound->tearDown();
	}
}

void Gui::setMidiGui() {
	float dim = 16;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 255-xInit;
	
	midiGui = new ofxUICanvas(length*2+xInit*2+4, 0, length+xInit, _height);
	midiGui->addWidgetDown(new ofxUILabel("PANEL 3: MIDI", OFX_UI_FONT_LARGE));
	
	midiGui->addSpacer(length-xInit, 2);
	midiGui->addWidgetDown(new ofxUILabel("Midi", OFX_UI_FONT_MEDIUM));
	
	vector<string> values = midi->getPortList();
	values.insert(values.begin(), "-- none --");
	midiDropDown = midiGui->addDropDownList("MIDI", values);
	midiDropDown->setShowCurrentSelected(true);
	midiDropDown->setAutoClose(true);
	midiDropDown->triggerEvent(soundDropDown->getToggles()[0]);
	
	midiGui->addWidgetDown(new ofxUIButton( "Refresh", false, dim, dim));
	
	ofAddListener(midiGui->newGUIEvent, this, &Gui::guiEvent);
	
	midiGui->loadSettings("GUI/midi.xml");
	
	// loadSettings won't select for real
	vector<ofxUILabelToggle *> toggles = midiDropDown->getToggles();
	for (int i=0; i<toggles.size(); i++) {
		if (toggles[i]->getValue()) {
			midiDropDown->triggerEvent(toggles[i]);
		}
	}
}

void Gui::initMidi() {
	int selectedIndex = midiDropDown->getSelectedIndeces()[0];
	if (selectedIndex > 0) {
		midi->setup(selectedIndex-1);
	}
	else {
		midi->tearDown();
	}
}

void Gui::setOscGui() {
	float dim = 16;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 255-xInit;
	
	oscGui = new ofxUICanvas(length*3+xInit*3+6, 0, length+xInit, _height);
	oscGui->addWidgetDown(new ofxUILabel("PANEL 4: OSC", OFX_UI_FONT_LARGE));
	
	oscGui->addSpacer(length-xInit, 2);
    oscGui->addWidgetDown(new ofxUILabel("OSC Port", OFX_UI_FONT_MEDIUM));
    oscGui->addWidgetDown(new ofxUINumberDialer(1025, 65535, osc->PORT, 1, "OSC", OFX_UI_FONT_MEDIUM));
	
	ofAddListener(oscGui->newGUIEvent, this, &Gui::guiEvent);
	
	oscGui->loadSettings("GUI/osc.xml");
}

void Gui::guiEvent(ofxUIEventArgs &e) {
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	
//	ofxUIWidget* parent = e.widget->getParent();
//	if (parent != NULL && parent->getKind() == OFX_UI_WIDGET_DROPDOWNLIST) {
//		ofxUILabelToggle* toggle = (ofxUILabelToggle *) e.widget;
//		if (!toggle->getValue()) {
//			return;
//		}
//		name = parent->getName();
//	}
	
	cout << "got event from: " << name << endl;

	if (name == "RESOLUTION") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		grid->setResolution(slider->getValue());
	}
	else if (name == "VCOUNT") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		grid->setVCount(slider->getValue());
	}
	else if (name == "VWIDTH") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		grid->setVWidth(slider->getValue());
	}
	else if (name == "HCOUNT") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		grid->setHCount(slider->getValue());
	}
	else if (name == "HWIDTH") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		grid->setHWidth(slider->getValue());
	}
	else if (name == "VCOLORS") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		grid->setVColors(slider->getValue());
	}
	else if (name == "HCOLORS") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		grid->setHColors(slider->getValue());
	}
	else if (name == "COLORES") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		grid->setColorRes(slider->getValue());
	}
	else if (name == "SOUND") {
		initSound();
	}
	else if (name == "SMOOTHING") {
		ofxUIIntSlider *slider = (ofxUIIntSlider *) e.widget;
		sound->setSmoothing(slider->getValue());
	}
	else if (name == "THRESHOLD") {
		ofxUIIntSlider *slider = (ofxUIIntSlider *) e.widget;
		sound->setThreshold(slider->getValue());
	}
	else if (name == "MIDI") {
		initMidi();
	}
	else if (name == "Refresh") {
		midiDropDown->clearToggles();
		midiDropDown->addToggles(midi->getPortList());
	}
	else if (name == "OSC") {
		ofxUINumberDialer *numberDialer = (ofxUINumberDialer *) e.widget;
		osc->setup(numberDialer->getValue());
	}
}

void Gui::toggleVisible() {
	gridGui->toggleVisible();
	soundGui->toggleVisible();
	midiGui->toggleVisible();
	oscGui->toggleVisible();
}

void Gui::exit() {
	gridGui->saveSettings("GUI/grid.xml");
	soundGui->saveSettings("GUI/sound.xml");
	midiGui->saveSettings("GUI/midi.xml");
	oscGui->saveSettings("GUI/osc.xml");
	delete gridGui;
	delete soundGui;
	delete midiGui;
	delete oscGui;
}