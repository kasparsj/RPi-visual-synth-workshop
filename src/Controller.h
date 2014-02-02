#pragma once

#include "Mediator.h"

class Controller {
	
public:
	
	explicit Controller(Mediator* mediator) {
		setMediator(mediator);
	}
	virtual void update()  {
		mediator->update();
	}
	void setMediator(Mediator* mediator) {
		this->mediator = mediator;
	}
	
protected:
	
	Mediator* mediator = NULL;
	
};