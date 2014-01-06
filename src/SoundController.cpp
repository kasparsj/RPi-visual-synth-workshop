//
//  SoundController.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 11/10/2013.
//
//

#include "SoundController.h"

void SoundController::setup() {
	fft.setup(BUFFER_SIZE);
	fft.setUseNormalization(FALSE);
	
	mediator->setResolution(RESOLUTION/100.f);
	
	fftSmoothed = new float[BUFFER_SIZE];
}

void SoundController::setResolution(unsigned int perc) {
	resolution = perc;
	mediator->setResolution(perc/100.f);
}

void SoundController::update() {
	if (resolution > 0) {
		cout << "sound";
		fft.update();
		
		int vCount = 0, hCount = 0;
		float vWidth = 0, hWidth = 0;
		
		vector<float>& buffer = fft.getBins();
		int n = MIN(BINS, buffer.size());
		
		float maxSound = 0;
		
		for (int i = 0; i < n; i++) {
			
			fftSmoothed[i] *= SMOOTHING/100.f;
			if (fftSmoothed[i] < buffer[i]) {
				fftSmoothed[i] = buffer[i];
			}
			
			avgSound += buffer[i];
			if (buffer[i] > maxSound) {
				maxSound = buffer[i];
			}
		}
		avgSound /= n;
		
		for (int i = 0; i < n; i++) {
			if (fftSmoothed[i] >= 0.02) {
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
		
		mediator->setVCount((float)vCount/BINS);
		mediator->setVWidth(vCount > 0 ? vWidth/vCount : 0);
		mediator->setHCount((float)hCount/BINS);
		mediator->setHWidth(hCount > 0 ? hWidth/hCount : 0);
		
		mediator->update();
	}
}