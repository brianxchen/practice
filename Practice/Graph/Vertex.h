#pragma once
#include "../Common.h"

class Vertex {
public:
	string value;
	vector<Vertex*> outedges;
	int indegree;
	Vertex(string value) {
		this->value = value;
		indegree = 0;
	}
	void addVertex(Vertex* newVertex) {
		outedges.push_back(newVertex);
	}
};

