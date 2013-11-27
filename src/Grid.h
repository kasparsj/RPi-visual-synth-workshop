#pragma once

#include "ofMain.h"

class Grid: public ofNode {
	
public:
	
	Grid() {
		_startHue = 0;
		_endHue = 1;
		_startSat = 0;
		_endSat = 1;
		_startBri = 0;
		_endBri = 1;
	}

	void draw();
	
	float getResolution() { return _resolution; }
	void setResolution(float perc) { _resolution = perc; }
	
	float getColorRes() { return _colorRes; }
	void setColorRes(float perc) { _colorRes = perc; }

	float getVCount() { return _vCount; }
	void setVCount(float perc) { _vCount = perc; }
	float getVWidth() { return _vWidth; }
	void setVWidth(float perc) { _vWidth = perc; }
	float getVColors() { return _vColors; }
	void setVColors(float perc) { _vColors = perc; }

	float getHCount() { return _hCount; }
	void setHCount(float perc) { _hCount = perc; }
	float getHWidth() { return _hWidth; }
	void setHWidth(float perc) { _hWidth = perc; }
	float getHColors() { return _hColors; }
	void setHColors(float perc) { _hColors = perc; }
	
	float getHueOffset() { return _hueOffset; }
	void setHueOffset(float perc) { _hueOffset = perc; }
	float getSatOffset() { return _startSat; }
	void setSatOffset(float perc) { _startSat = perc; }
	float getBriOffset() { return _startBri; }
	void setBriOffset(float perc) { _startBri = perc; }

//	float getStartHue() { return _startHue; }
//	void setStartHue(float perc) { _startHue = perc; }
//	float getEndHue() { return _endHue; }
//	void setEndHue(float perc) { _endHue = perc; }
//
//	float getStartSat() { return _startSat; }
//	void setStartSat(float perc) { _startSat = perc; }
//	float getEndSat() { return _endSat; }
//	void setEndSat(float perc) { _endSat = perc; }
//
//	float getStartBri() { return _startBri; }
//	void setStartBri(float perc) { _startBri = perc; }
//	float getEndBri() { return _endBri; }
//	void setEndBri(float perc) { _endBri = perc; }
	
private:
	
	void drawVLine(int, int, int);
	void drawHLine(int, int, int);
	float getX(int, int);
	float getY(int, int);
	float getHInterval(int);
	float getVInterval(int);
	float getWidth(int);
	float getHeight(int);
	int getColor(int, int);
	int getIntervalValue(int, int, int, int);
	int triangleWave(int, int);
	
	float _resolution;
	float _colorRes;
	
	float _vCount;
	float _vWidth;
	float _vColors;

	float _hCount;
	float _hWidth;
	float _hColors;
	
	float _hueOffset;

	float _startHue;
	float _endHue;
	float _startSat;
	float _endSat;
	float _startBri;
	float _endBri;
};