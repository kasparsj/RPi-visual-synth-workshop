#include "Tweener.h"

const string Tweener::TO = "to";
const string Tweener::FROM = "from";

void Tweener::update() {
	try {
		grid->setResolution(resolutionTween.update());
		grid->setColorRes(colorResTween.update());
		
		grid->setVCount(vCountTween.update());
		grid->setVWidth(vWidthTween.update());
		grid->setVColors(vColorsTween.update());
		
		grid->setHCount(hCountTween.update());
		grid->setHWidth(hWidthTween.update());
		grid->setHColors(hColorsTween.update());
		
		grid->setHueOffset(hueOffsetTween.update());
		grid->setSatOffset(satOffsetTween.update());
		grid->setBriOffset(briOffsetTween.update());
	}catch(Poco::SystemException) {
		ofLog() << "Poco::SystemException";
	}
}
