#pragma once
#include "../Common.h"
#include "Transition.h"
class State {
public:
	vector<Transition*> transitions;
	string name;
	State(string name) {
		this->name = name;
	}
	
	void addTransition(Transition* transition) {
		transitions.push_back(transition);
	}
	void printState() {
		printf("State: %s, transitions: ", name.c_str());
		for (int i = 0; i < transitions.size(); i++) {
			printf("%c->%s\n", transitions[i]->condition, ((State*) (transitions[i]->destination))->name.c_str());
		}
		printf("\n");
	}
};
