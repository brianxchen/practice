#pragma once
#include "..\Common.h"


class Human {
public:
	Human(int height, int weight, string name);
	int height;
	int weight;
	string name;
	string ToString();
};
