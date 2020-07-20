#include "City.h"

City::City(int north, int south) {
	this->north = north;
	this->south = south;
}

string City::ToString() {
	return "[" + to_string(north) + "," + to_string(south) + "]";
}
