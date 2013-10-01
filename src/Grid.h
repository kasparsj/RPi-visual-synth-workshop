#pragma once

#include "ofMain.h"

class Grid: public ofNode {
	public:
		void draw();
		unsigned int getHLines() { return _hLines; }
		unsigned int getVLines() { return _vLines; }
		void setHLines(int value) { _hLines = MAX(0, value); }
		void setVLines(int value) { _vLines = MAX(0, value); }
	
	private:
		unsigned int _vLines;
		unsigned int _hLines;
};