#pragma once

class Edge {
public:
	int a;
	int b;
	int cost;
	Edge(int a, int b, int cost) {
		this->a = a;
		this->b = b;
		this->cost = cost;
	}
};