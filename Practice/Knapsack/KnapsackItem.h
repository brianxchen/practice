#pragma once
#include "..\Common.h"

class KnapsackItem {
public:
	KnapsackItem(int size, int value, string name);
	int size;
	int value;
	string name;
};