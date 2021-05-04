#pragma once
#include "../Common.h"

class Item24 {
public:
	float value;
	string expression;
	int lastOp;
	Item24() {

	}
	Item24(float value, string expression) {
		this->value = value;
		this->expression = expression;
		this->lastOp = -1;
	}
};