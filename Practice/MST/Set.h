#pragma once
#include "SetElement.h"

class Set {
public:
	vector<SetElement*> Elements;
	Set() {
	}
	void PrintSet() {
		for (int i = 0; i < Elements.size(); i++) {
			printf("%d ", Elements[i]->cityID);
		}
		printf("\n");
	}
	void AddElement(SetElement* element) {
		this->Elements.push_back(element);
	}
	void Union(Set* s) {
		for (int i = 0; i < s->Elements.size(); i++) {
			AddElement(s->Elements[i]);
		}
	}
};

void testSet2() {
	Set* a = new Set();
	a->AddElement(new SetElement(1));
	a->AddElement(new SetElement(2));
	a->AddElement(new SetElement(3));
	a->AddElement(new SetElement(4));
	a->PrintSet();
	Set* b = new Set();
	b->AddElement(new SetElement(5));
	b->AddElement(new SetElement(6));
	b->AddElement(new SetElement(7));
	b->AddElement(new SetElement(8));
	a->Union(b);
	a->PrintSet();
}