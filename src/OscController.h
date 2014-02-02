#pragma once

#include "Controller.h"
#include "ofxOsc.h"

class OscController : public Controller {
	
public:
	
	static const unsigned int PORT = 10000;
	
	explicit OscController(Mediator* mediator) : Controller(mediator) {
	}
	virtual void setup(unsigned int portNumber);
	virtual void update() override;

private:
	
	bool isOpen = false;
	ofxOscReceiver receiver;
	
};