//
//  Gui.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 06/01/2014.
//
//

#include "Gui.h"

void Gui::setup() {
	float dim = 16;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 255-xInit;
	
	canvas = new ofxUICanvas(0, 0, length+xInit, _height);
	canvas->addWidgetDown(new ofxUILabel("PANEL 1: BASICS", OFX_UI_FONT_LARGE));
    canvas->addWidgetDown(new ofxUILabel("Press 'h' to Hide GUIs", OFX_UI_FONT_LARGE));
	
    canvas->addSpacer(length-xInit, 2);
    canvas->addWidgetDown(new ofxUILabel("FPS", OFX_UI_FONT_MEDIUM));
    canvas->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));
	
    canvas->addSpacer(length-xInit, 2);
	canvas->addWidgetDown(new ofxUILabel("Midi", OFX_UI_FONT_MEDIUM));
	midiDropDown = canvas->addDropDownList("MIDI", midi->getPortList());
	canvas->addWidgetDown(new ofxUIButton( dim, dim, false, "Refresh"));
	
	canvas->addSpacer(length-xInit, 2);
    canvas->addWidgetDown(new ofxUILabel("OSC Port", OFX_UI_FONT_MEDIUM));
    canvas->addWidgetDown(new ofxUINumberDialer(1025, 65535, osc->PORT, 1, "OSC", OFX_UI_FONT_MEDIUM));

	canvas->addWidgetDown(new ofxUILabel("Sound", OFX_UI_FONT_MEDIUM));
	canvas->addIntSlider("SOUND", 0, 100, sound->RESOLUTION, length-xInit,dim);
    
	ofAddListener(canvas->newGUIEvent, this, &Gui::guiEvent);
	
	canvas->loadSettings("GUI/guiSettings.xml");
	
	initMidi();
}

void Gui::initMidi() {
	if (midiDropDown->getSelectedIndeces().size()) {
		midi->openPort(midiDropDown->getSelectedIndeces()[0]);
	}
}

void Gui::guiEvent(ofxUIEventArgs &e) {
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	cout << "got event from: " << name << endl;

	if (name == "MIDI") {
		initMidi();
	}
	else if (name == "Refresh") {
		midiDropDown->clearToggles();
		midiDropDown->addToggles(midi->getPortList());
	}
	else if (name == "OSC") {
		ofxUINumberDialer *numberDialer = (ofxUINumberDialer *) e.widget;
		osc->openPort(numberDialer->getValue());
	}
	else if (name == "SOUND") {
		ofxUIIntSlider *slider = (ofxUIIntSlider *) e.widget;
		sound->setResolution(slider->getValue());
	}
}

void Gui::toggleVisible() {
	canvas->toggleVisible();
}

void Gui::exit() {
	canvas->saveSettings("GUI/guiSettings.xml");
	delete canvas;
}