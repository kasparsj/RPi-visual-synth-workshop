//
//  OscController.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 11/10/2013.
//
//

#include "OscController.h"

void OscController::setup(unsigned int portNumber) {
	receiver.setup(portNumber);
}

void OscController::update() {
	return;
	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		float value = m.getArgAsFloat(0);
		
		// check for mouse moved message
		if (m.getAddress() == "/vol1") {
			mediator->setVCount(value);
		}
		else if (m.getAddress() == "/vol2") {
			mediator->setVWidth(value);
		}
		else if (m.getAddress() == "/vol3") {
			mediator->setHCount(value);
		}
		else if (m.getAddress() == "/vol4") {
			mediator->setHWidth(value);
		}
		else if (m.getAddress() == "/vol5") {
			mediator->setVColors(value);
		}
		else if (m.getAddress() == "/vol6") {
			mediator->setHColors(value);
		}
		else if (m.getAddress() == "/pan1") {
			mediator->setResolution((1+value)/2);
		}
		else if (m.getAddress() == "/pan2") {
			mediator->setDuration((1+value)/2);
		}
		else if (m.getAddress() == "/pan3") {
			mediator->setColorRes((1+value)/2);
		}
		else if (m.getAddress() == "/pan4") {
			mediator->setHueOffset((1+value)/2);
		}
		else if (m.getAddress() == "/pan5") {
			mediator->setSatOffset((1+value)/2);
		}
		else if (m.getAddress() == "/pan6") {
			mediator->setBriOffset((1+value)/2);
		}
		isOpen = true;
	}
	
	if (isOpen) {
		mediator->update();
	}
}