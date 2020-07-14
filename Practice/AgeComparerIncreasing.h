#pragma once
#include "Person.h"
#include "IComparer.h"


class AgeComparerIncreasing : public IComparer {
	public:
		AgeComparerIncreasing() {

		}
		bool Compare(Person a, Person b) override {
				cout << "Inside agecomparerincreasing";
				return a.age < b.age;
		}
};

