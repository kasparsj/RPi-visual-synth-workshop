#pragma once

#include "Mediator.h"
#include "Grid.h"
#include "ofxTween.h"

class Tweener : public Mediator {
	
public:
	static const string TO;
	static const string FROM;
	
	Tweener(Grid* grid) : Mediator(grid) {};
	void update() override;
	
protected:
    static const int SHORT_TWEEN = 10000;
    static const int LONG_TWEEN = 15000;
	
	ofxTween resolutionTween;
	ofxTween colorResTween;
	
	ofxTween hCountTween;
	ofxTween hWidthTween;
	ofxTween hColorsTween;
	
	ofxTween vCountTween;
	ofxTween vWidthTween;
	ofxTween vColorsTween;
	
	ofxTween hueOffsetTween;
	ofxTween satOffsetTween;
	ofxTween briOffsetTween;

    map<string, ofxEasing*> easings;

    template <class T>
    ofxEasing* getEasing() {
        string type = typeid(T).name();
        if (easings.find(type) == easings.end()) {
            easings[type] = new T();
        }
        return easings[type];
    }
};