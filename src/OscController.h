#pragma once

#include "Controller.h"
#include "ofxOsc.h"

class OscController : public Controller {
	
public:
	
	explicit OscController(Mediator* mediator) : Controller(mediator) {
		setup();
	}
	virtual void setup() override;
	virtual void update() override;

private:
	
	static const int PORT = 10000;
	
	ofxOscReceiver receiver;
};