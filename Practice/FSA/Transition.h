#pragma once
#include "State.h"
class Transition {
public:
	char condition;
	void* destination;
	Transition(char condition, void* destination) {
		this->condition = condition;
		this->destination = destination;
	}
};