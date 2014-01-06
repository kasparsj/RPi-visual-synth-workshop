#pragma once

#include "Controller.h"
#include "ofxEasyFft.h"

class SoundController : public Controller {

public:
	
	static const unsigned int RESOLUTION = 100;
	static const unsigned int SMOOTHING = 96;
	
	SoundController(Mediator* mediator) : Controller(mediator) {
		setup();
	}
	void setup() override;
	void setResolution(unsigned int perc);
	void update() override;
	
private:
	
	static const int BUFFER_SIZE = 16384;
	static const int BINS = 1024;
	
	unsigned int resolution;
	float avgSound;
	float* fftSmoothed;
	
	ofxEasyFft fft;
	
};