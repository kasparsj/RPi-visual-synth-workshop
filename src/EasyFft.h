#pragma once

#include "ofxFft.h"

class EasyFft : ofBaseApp {
public:
	EasyFft() : useNormalization(true) {
	};

    void setup(int deviceID = 0,
			int bufferSize = 512,
            fftWindowType windowType = OF_FFT_WINDOW_HAMMING,
            fftImplementation implementation = OF_FFT_FFTW,
            int audioBufferSize = 256,
            int audioSampleRate = 48000);
	void tearDown();
    void setUseNormalization(bool useNormalization);
    void update();
    vector<float>& getAudio();
    vector<float>& getBins();

    void audioReceived(float* input, int bufferSize, int nChannels);

    ofxFft* fft = 0;

private:
	ofSoundStream soundStream;
    bool useNormalization;
    ofMutex soundMutex;
    vector<float> audioFront, audioMiddle, audioBack, audioRaw;
    vector<float> bins;

    void normalize(vector<float>& data);
};