#pragma once

#include "Controller.h"
#include "ofxEasyFft.h"

class SoundController : public Controller {

public:
	
	SoundController(Mediator* mediator) : Controller(mediator) {
		setup();
	}
	void setup() override;
	void update() override;
	
private:
	
	static const int BINS = 1024;
	
	ofxEasyFft fft;
	
};