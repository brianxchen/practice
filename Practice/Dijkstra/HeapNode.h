#pragma once
#include "../Common.h"

class HeapNode {
public:
	int cityID;
	int cost;
	HeapNode(int cityID, int cost) {
		this->cityID = cityID;
		this->cost = cost;
	}
};

