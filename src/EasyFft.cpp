#include "EasyFft.h"

void EasyFft::setup(int deviceID, int bufferSize, fftWindowType windowType, fftImplementation implementation, int audioBufferSize, int audioSampleRate) {
    if(bufferSize < audioBufferSize) {
        ofLogFatalError() << "Fft bufferSize (" << bufferSize << ") must be less than the audioBufferSize (" << audioBufferSize << ")";
    }
	
	if (fft == NULL) {
		fft = ofxFft::create(bufferSize, windowType, implementation);
	}
	else {
		tearDown();
	}

    bins.resize(fft->getBinSize());

    audioFront.resize(bufferSize);
    audioMiddle.resize(bufferSize);
    audioBack.resize(bufferSize);
    audioRaw.resize(bufferSize);

	soundStream.setDeviceID(deviceID);
	soundStream.setup(this, 0, 2, audioSampleRate, audioBufferSize, 2);
}

void EasyFft::tearDown() {
	soundStream.close();
}

void EasyFft::setUseNormalization(bool useNormalization) {
    this->useNormalization = useNormalization;
}

void EasyFft::update() {
    soundMutex.lock();
    audioFront = audioMiddle;
    soundMutex.unlock();

    fft->setSignal(&audioFront[0]);
    float* curFft = fft->getAmplitude();
    copy(curFft, curFft + fft->getBinSize(), bins.begin());
    normalize(bins);
}

vector<float>&EasyFft::getAudio() {
    return audioFront;
}

vector<float>&EasyFft::getBins() {
    return bins;
}

void EasyFft::audioReceived(float* input, int bufferSize, int nChannels) {
	if(audioRaw.size() > bufferSize) {
        copy(audioRaw.begin() + bufferSize, audioRaw.end(), audioRaw.begin()); // shift old
    }
    copy(input, input + bufferSize, audioRaw.end() - bufferSize); // push new
    copy(audioRaw.begin(), audioRaw.end(), audioBack.begin());
    normalize(audioBack);
	
    soundMutex.lock();
    audioMiddle = audioBack;
    soundMutex.unlock();
}

void EasyFft::normalize(vector<float>& data) {
    if(useNormalization) {
        float maxValue = 0;
        for(int i = 0; i < data.size(); i++) {
            if(abs(data[i]) > maxValue) {
                maxValue = abs(data[i]);
            }
        }
        for(int i = 0; i < data.size(); i++) {
            data[i] /= maxValue;
        }
    }
}
