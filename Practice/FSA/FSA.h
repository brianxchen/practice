#pragma once
#include "State.h"
class FSA {
public:
	State* start;
	State* termination;
	FSA(State* start, State* termination) {
		this->start = start;
		this->termination = termination;
	}
};

void testFSA();