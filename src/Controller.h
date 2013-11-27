#pragma once

#include "Mediator.h"

class Controller {
	
public:
	
	explicit Controller(Mediator* mediator);
	virtual void setup() = 0;
	virtual void update() = 0;
	
protected:
	
	Mediator* mediator;
};