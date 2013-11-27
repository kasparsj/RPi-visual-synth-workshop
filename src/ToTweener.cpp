#include "ToTweener.h"

void ToTweener::setResolution(float perc) {
	resolutionTween.setParameters(1, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getResolution(), perc, round(duration * SHORT_TWEEN), 0);
}

void ToTweener::setVCount(float perc) {
	vCountTween.setParameters(2, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getVCount(), perc, round(duration * LONG_TWEEN), 0);
}

void ToTweener::setVWidth(float perc) {
	vWidthTween.setParameters(3, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getVWidth(), perc, round(duration * SHORT_TWEEN), 0);
}

void ToTweener::setHCount(float perc) {
	hCountTween.setParameters(4, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getHCount(), perc, round(duration * LONG_TWEEN), 0);
}

void ToTweener::setHWidth(float perc) {
	hWidthTween.setParameters(5, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getHWidth(), perc, round(duration * SHORT_TWEEN), 0);
}

void ToTweener::setVColors(float perc) {
	vColorsTween.setParameters(6, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getVColors(), perc, round(duration * SHORT_TWEEN), 0);
}

void ToTweener::setHColors(float perc) {
	hColorsTween.setParameters(7, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getHColors(), perc, round(duration * SHORT_TWEEN), 0);
}

void ToTweener::setColorRes(float perc) {
	colorResTween.setParameters(8, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getColorRes(), perc, round(duration * SHORT_TWEEN), 0);
}

void ToTweener::setHueOffset(float perc) {
	hueOffsetTween.setParameters(9, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getHueOffset(), perc, round(duration * SHORT_TWEEN), 0);
}

// these are actually mapped to startSat and startBri
void ToTweener::setSatOffset(float perc) {
	satOffsetTween.setParameters(10, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getSatOffset(), perc, round(duration * SHORT_TWEEN), 0);
}

void ToTweener::setBriOffset(float perc) {
	briOffsetTween.setParameters(11, *getEasing<ofxEasingExpo>(), ofxTween::easeOut, grid->getBriOffset(), perc, round(duration * SHORT_TWEEN), 0);
}
