
#pragma once
#include "..\Person\Person.h"
#include "AgeComparerIncreasing.h"


bool AgeComparerIncreasing::Compare(Person& a, Person& b){
	cout << "Inside agecomparerincreasing";
	return a.age < b.age;
}