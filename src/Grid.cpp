//
//  Grid.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 30/09/2013.
//
//

#include "Grid.h"

void Grid::draw() {
	float xInterval = ofGetWidth()/(_vLines+1);
	for (int i=1; i<=_vLines; i++) {
		ofLine(xInterval*i, 0, xInterval*i, ofGetHeight());
	}
	
	float yInterval = ofGetHeight()/(_hLines+1);
	for (int j=1; j<=_hLines; j++) {
		ofLine(0, yInterval*j, ofGetWidth(), yInterval*j);
	}
}