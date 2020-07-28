#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

class Position {
	public:
		int i;
		int j;
		Position(int i, int j) {
			this->i = i;
			this->j = j;
		}
		string GetString() {
			return "[" + to_string(i) + ", " + to_string(j) + "]";
		}
};