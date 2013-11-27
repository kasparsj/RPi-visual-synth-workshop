//
//  Grid.cpp
//  mySketch
//
//  Created by Kaspars Jaudzems on 30/09/2013.
//
//

#include "Grid.h"

void Grid::draw() {
	int i, j;
	
	int vCountNum = round(_vCount*MAX(1, ofGetWidth()*_resolution));
	int hCountNum = round(_hCount*MAX(1, ofGetHeight()*_resolution));
	
	int vColors = MAX(1, round(_vColors * 255*_colorRes));
	int hColors = MAX(1, round(_hColors * 255*_colorRes));

	for (i=0; i<vCountNum; i=i+2) {
		drawVLine(i, vCountNum, vColors);
	}
	
	for (i=0; i<hCountNum; i=i+2) {
		drawHLine(i, hCountNum, hColors);
	}
	
	for (i=1; i<vCountNum; i=i+2) {
		drawVLine(i, vCountNum, vColors);
	}
	
	for (i=1; i<hCountNum; i=i+2) {
		drawHLine(i, hCountNum, hColors);
	}
}

void Grid::drawVLine(int i, int count, int colors) {
	int j = i-floor(count/2);
	ofSetHexColor(getColor(j, colors));
	ofRect(getX(j, count), 0, getWidth(count), ofGetHeight());
}

void Grid::drawHLine(int i, int count, int colors) {
	int j = i-floor(count/2);
	ofSetHexColor(getColor(j, colors));
	ofRect(0, getY(j, count), ofGetWidth(), getHeight(count));
}

float Grid::getX(int i, int count) {
	float interval = getVInterval(count);
	return ofGetWidth()/2.f + interval*i - getWidth(count)/2.f;
}

float Grid::getY(int i, int count) {
	float interval = getHInterval(count);
	return ofGetHeight()/2.f + interval*i-getHeight(count)/2.f;
}

float Grid::getVInterval(int count) {
	return (float) ofGetWidth()/count;
}

float Grid::getHInterval(int count) {
	return (float) ofGetHeight()/count;
}

float Grid::getWidth(int count) {
	return MAX(1, _vWidth*getVInterval(count));
}

float Grid::getHeight(int count) {
	return MAX(1, _hWidth*getHInterval(count));
}

int Grid::getColor(int i, int count) {
	ofColor color;
	int startHue = round(255*_startHue);
	int startSat = round(255*_startSat);
	int startBri = round(255*_startBri);
	if (count == 1) {
		color.setHsb(startHue, startSat, startBri);
	}
	else {
		int endHue = round(255*_endHue);
		int endSat = round(255*_endSat);
		int endBri = round(255*_endBri);
		int hue = getIntervalValue(i, count, startHue, endHue);
		int sat = getIntervalValue(i, count, startSat, endSat);
		int bri = getIntervalValue(i, count, startBri, endBri);
		// hue offset
		int hueOffset = round(255*_hueOffset);
		hue = hueOffset + hue;
		if (hue > 255) hue -= 255;
		// translate to black/white opposites
		sat = round(((float) (sat <= 127 ? sat : (255-sat))/127)*255);
		//ofLog() << "i: " << i << " color: " << index << "/" << count << " hue:" << hue << " sat: " << sat << " bri: " << bri;
		color.setHsb(hue, sat, bri);
	}
	return color.getHex();
//	return startColor+interval*ABS(whichColor);
//	return startColor+(range*sin(ofDegToRad((color/count)*90)));
}

int Grid::getIntervalValue(int i, int count, int start, int end) {
	int range = (end - start);
	int interval = range / (count-1);
	//ofLog() << "range: " << range << " interval: " << interval;
	int index;
	if (count == 2) {
		index = ABS(i%2);
	}
	else {
		index = triangleWave(ABS(i), (count-1));
	}
	return start+interval*index;
}

int Grid::triangleWave(int i, int count) {
	return count - abs(i % (2*count) - count);
}
