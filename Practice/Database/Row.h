#pragma once
#include "../Common.h"

class Row {
public:
	string user_id;
	string name;
	int age;
	Row(string user_id, string name, int age) {
		this->user_id = user_id;
		this->name = name;
		this->age = age;
	}
	void Dump() {
		printf("%s, %s, %d\n", user_id.c_str(), name.c_str(), age);
	}
};

