#pragma once
#include "AbstractMemorizer.h"


class MapMemorizer : public AbstractMemorizer{
public:
	map<string, int> m;
	MapMemorizer() {
	}
	void Set(string key, int value) {
		m[key] = value;
	}
	int Get(string key) {
		if (m.count(key) == 0) {
			return -1;
		}
		return m[key];
	}
};