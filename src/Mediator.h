#pragma once

#include "Grid.h"

class Mediator {
	
public:
	Mediator(Grid* grid);
	virtual void update() {}
	
	virtual void setResolution(float perc) {
		grid->setResolution(perc);
	}
	virtual void setColorRes(float perc) {
		grid->setColorRes(perc);
	}
	
	virtual void setVCount(float perc) {
		grid->setVCount(perc);
	}
	virtual void setVWidth(float perc) {
		grid->setVWidth(perc);
	}
	virtual void setVColors(float perc) {
		grid->setVColors(perc);
	}
	
	virtual void setHCount(float perc) {
		grid->setHCount(perc);
	}
	virtual void setHWidth(float perc) {
		grid->setHWidth(perc);
	}
	virtual void setHColors(float perc) {
		grid->setHColors(perc);
	}
	
	virtual void setHueOffset(float perc) {
		grid->setHueOffset(perc);
	}
	virtual void setSatOffset(float perc) {
		grid->setSatOffset(perc);
	}
	virtual void setBriOffset(float perc) {
		grid->setBriOffset(perc);
	}
	
	virtual void setDuration(float perc) {
		duration = perc;
	}
	
protected:
	Grid* grid;
	float duration;
};