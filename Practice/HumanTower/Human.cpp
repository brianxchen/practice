#include "Human.h"

Human::Human(int height, int weight, string name) {
	this->height = height;
	this->weight = weight;
	this->name = name;
}

string Human::ToString() {
	return "[" + name + "," + to_string(height) + "," + to_string(weight) + "]";
}