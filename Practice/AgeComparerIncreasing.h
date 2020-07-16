#pragma once
#include "Person.h"
#include "AbstractComparer.h"


class AgeComparerIncreasing : public AbstractComparer {
	public:
		bool Compare(Person a, Person b);
};

