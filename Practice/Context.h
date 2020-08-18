#pragma once
#include "Common.h"
#include "AbstractMemorizer.h"
#include "MapMemorizer.h"

class Context {
	public:
		string a;
		string b;
		int overallMax;
		AbstractMemorizer* memorizer;
		Context(string a, string b) {
			this->a = a;
			this->b = b;
			overallMax = -1;
			memorizer = new MapMemorizer();
		}
};