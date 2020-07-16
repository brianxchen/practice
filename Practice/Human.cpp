#include "Human.h"

Human::Human(int height, int weight, string name) {
	this->height = height;
	this->weight = weight;
	this->name = name;
}

string Human::ToString() {
	return "[" + name + "," + std::to_string(height) + "," + std::to_string(weight) + "]";
}