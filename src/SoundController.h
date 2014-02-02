#pragma once

#include "Controller.h"
#include "EasyFft.h"

class SoundController : public Controller {

public:
	
	static const unsigned int SMOOTHING = 96;
	static const unsigned int THRESHOLD = 0.02;
	
	SoundController(Mediator* mediator) : Controller(mediator) {
	}
	void setup(unsigned int deviceID);
	void tearDown();

    vector<string> getDeviceList();
	void setSmoothing(unsigned int perc);
	void setThreshold(unsigned int perc);
	void update() override;
	void draw();
	void plot(vector<float>& buffer, float scale);
	
private:
	
	static const int BUFFER_SIZE = 16384;
	static const int BINS = 1024;
	
	unsigned int smoothing;
	unsigned int threshold;
	
	float avgSound;
	float* fftSmoothed = 0;
	
	EasyFft fft;
	
};