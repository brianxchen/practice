#pragma once
#include "Common.h"

class Person {
	public:
		Person();
		Person(int age, string name, bool isMale);
		string ToString();
		void Print();
		~Person();
		int age;
		string name;
		bool isMale;
};

void TestPerson();

void TestDestructors();

void TestSorter();
