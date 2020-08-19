#pragma once
#include "Common.h"
#include "AbstractMemorizer.h"
#include "MapMemorizer.h"

class SearchContext {
public:
	string name;
	int age;
	bool done;
	SearchContext(string name){
		this->name = name;
		this->done = 0;
	}
};