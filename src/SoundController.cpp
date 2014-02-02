//
//  SoundController.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 11/10/2013.
//
//

#include "SoundController.h"

vector<string> SoundController::getDeviceList() {
	vector<string> deviceList;
	vector<ofSoundDevice> devices = ofSoundStreamListDevices();
	for (int i=0; i<devices.size(); i++) {
		if (devices[i].inputChannels > 0) {
			deviceList.push_back(devices[i].deviceName);			
		}
	}
	return deviceList;
}

void SoundController::setup(unsigned int deviceID) {
	fft.setup(deviceID, BUFFER_SIZE);
	fft.setUseNormalization(FALSE);
	
	fftSmoothed = new float[BUFFER_SIZE];
}

void SoundController::tearDown() {
	fft.tearDown();
	if (fftSmoothed != NULL) {
		delete fftSmoothed;
		fftSmoothed = NULL;
	}
}

void SoundController::setSmoothing(unsigned int perc) {
	smoothing = perc;
}

void SoundController::setThreshold(unsigned int perc) {
	threshold = perc;
}

void SoundController::update() {
	if (fftSmoothed == NULL) {
		return;
	}
	
	fft.update();
	
	int vCount = 0, hCount = 0;
	float vWidth = 0, hWidth = 0;
	
	vector<float>& buffer = fft.getBins();
	int n = MIN(BINS, buffer.size());
	
	float maxSound = 0;
	
	for (int i = 0; i < n; i++) {
		fftSmoothed[i] *= (100-smoothing)/100.f;
		if (fftSmoothed[i] < buffer[i]) {
			fftSmoothed[i] = buffer[i];
		}
		
		avgSound += buffer[i];
		if (buffer[i] > maxSound) {
			maxSound = buffer[i];
		}
	}
	avgSound /= n;
	
	if (maxSound > 0) {
		for (int i = 0; i < n; i++) {
			if (fftSmoothed[i] >= (threshold/200.f)) {
				if (i >= n/2) {
					vCount++;
					vWidth += fftSmoothed[i]/maxSound;
				}
				else {
					hCount++;
					hWidth += fftSmoothed[i]/maxSound;
				}
			}
		}
		//cout << (float)vCount/BINS << endl;
		mediator->setVCount((float)vCount/BINS);
		mediator->setVWidth(vCount > 0 ? vWidth/vCount : 0);
		mediator->setHCount((float)hCount/BINS);
		mediator->setHWidth(hCount > 0 ? hWidth/hCount : 0);
		
		mediator->update();
	}
}

void SoundController::draw() {
	plot(fft.getBins(), 128);
}

void SoundController::plot(vector<float>& buffer, float scale) {
	int n = MIN(1024, buffer.size());
	
	// debug
	//	ostringstream oss;
	//	if (!buffer.empty())
	//	{
	//		// Convert all but the last element to avoid a trailing ","
	//		copy(buffer.begin(), buffer.end()-1,
	//				  ostream_iterator<int>(oss, ","));
	//
	//		// Now add the last element with no delimiter
	//		oss << buffer.back();
	//	}
	//	cout << oss.str() << endl << endl << buffer.size() << endl << endl;
	// end of debug
	
	ofPushMatrix();
	ofTranslate(0, scale);
	ofScale(1, -scale);
	ofBeginShape();
	for (int i = 0; i < n; i++) {
		ofVertex(i, buffer[i]);
	}
	ofEndShape();
	ofPopMatrix();
}