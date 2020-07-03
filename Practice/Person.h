#pragma once
#include "Common.h"

class Person {
	public:
		Person();
		Person(int age, string name, bool isMale);
		void Print();
	private:
		int age;
		string name;
		bool isMale;
};

void TestPerson();