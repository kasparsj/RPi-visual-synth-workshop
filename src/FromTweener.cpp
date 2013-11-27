#include "FromTweener.h"

void FromTweener::setResolution(float perc) {
	// inverted!!!
	resolutionTween.setParameters(1, *getEasing<ofxEasingSine>(), ofxTween::easeIn, grid->getResolution(), perc, round(duration * SHORT_TWEEN), 0);
}

void FromTweener::setVCount(float perc) {
	vCountTween.setParameters(2, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * LONG_TWEEN), 0);
}

void FromTweener::setVWidth(float perc) {
	vWidthTween.setParameters(3, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * SHORT_TWEEN), 0);
}

void FromTweener::setHCount(float perc) {
	hCountTween.setParameters(4, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * LONG_TWEEN), 0);
}

void FromTweener::setHWidth(float perc) {
	hWidthTween.setParameters(5, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * SHORT_TWEEN), 0);
}

void FromTweener::setVColors(float perc) {
	vColorsTween.setParameters(6, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * SHORT_TWEEN), 0);
}

void FromTweener::setHColors(float perc) {
	hColorsTween.setParameters(7, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * SHORT_TWEEN), 0);
}

void FromTweener::setColorRes(float perc) {
	colorResTween.setParameters(8, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * SHORT_TWEEN), 0);
}

void FromTweener::setHueOffset(float perc) {
	hueOffsetTween.setParameters(9, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * SHORT_TWEEN), 0);
}

// these are actually mapped to startSat and startBri
void FromTweener::setSatOffset(float perc) {
	satOffsetTween.setParameters(10, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * SHORT_TWEEN), 0);
}

void FromTweener::setBriOffset(float perc) {
	briOffsetTween.setParameters(11, *getEasing<ofxEasingSine>(), ofxTween::easeIn, perc, TO, round(duration * SHORT_TWEEN), 0);
}