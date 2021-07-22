#pragma once
#include "../Common.h"
#include "Row.h"
#include "Index.h"

class Table {
private:
	vector<Row*> rows;
	Index* ageIndex;
	Index* nameIndex;
public:
	Table();
	int InsertRow(Row* row);
	void Dump();
	Row* QueryByAge(int age);
	Row* QueryByName(string name);
};

