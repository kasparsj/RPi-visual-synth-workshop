//
//  SoundController.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 11/10/2013.
//
//

#include "SoundController.h"

void SoundController::setup() {
	fft.setup(16384);
	
	mediator->setResolution(1);
	mediator->setDuration(0.5);
}

void SoundController::update() {
	fft.update();
	
	int vCount = 0, hCount = 0;
	float vWidth = 0, hWidth = 0;
	
	vector<float>& buffer = fft.getBins();
	int n = MIN(BINS, buffer.size());
	for (int i = 0; i < n; i++) {
		if (buffer[i] >= .5) {
			if (i >= BINS/2) {
				vCount++;
				vWidth += (buffer[i]-.5)/.5;
			}
			else {
				hCount++;
				hWidth += (buffer[i]-.5)/.5;
			}
		}
	}
	
	mediator->setVCount((float)vCount/BINS);
	mediator->setVWidth(vCount > 0 ? vWidth/vCount : 0);
	mediator->setHCount((float)hCount/BINS);
	mediator->setHWidth(hCount > 0 ? hWidth/hCount : 0);
	
	mediator->update();
}