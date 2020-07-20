#pragma once
#include "..\Common.h"

class City {
	public:
		City(int north, int south);
		int north;
		int south;
		string ToString();
};