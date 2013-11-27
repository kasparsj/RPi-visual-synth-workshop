#pragma once

#include "Tweener.h"

class ToTweener : public Tweener {

public:
    ToTweener(Grid* grid) : Tweener(grid) {}
	
private:
	void setResolution(float perc) override;
	void setVCount(float perc) override;
	void setVWidth(float perc) override;
	void setVColors(float perc) override;
	void setHCount(float perc) override;
	void setHWidth(float perc) override;
	void setHColors(float perc) override;
	void setColorRes(float perc) override;
	void setHueOffset(float perc) override;
	void setSatOffset(float perc) override;
	void setBriOffset(float perc) override;
	
};