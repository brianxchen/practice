#include "Table.h"

// Two comparer functions that are passed by pointer into the Index constructor. 
// This allows us to have different checking algorithms depending on the index type.
int ageCompareFunction(Row* a, Row* b) {
	if (a->age == b->age) {
		return 0;
	}
	else if (a->age < b->age) {
		return -1;
	}
	else {
		return 1;
	}
}
int nameCompareFunction(Row* a, Row* b){
	return a->name.compare(b->name);
}
Table::Table() {
	ageIndex = new Index(ageCompareFunction, false);
	nameIndex = new Index(nameCompareFunction, true);
}
int Table::InsertRow(Row* row) {
	rows.push_back(row);
	int ageIndexResult = ageIndex->AddRow(row);
	int nameIndexResult = nameIndex->AddRow(row);
	if (ageIndexResult == SUCCESS && nameIndexResult == SUCCESS) {
		return SUCCESS;
	}
	else {
		return INDEX_DUPE;
	}
}
void Table::Dump() {
	for (int i = 0; i < rows.size(); i++) {
		printf("%d: %s, %s, %d\n", i, rows[i]->user_id.c_str(), rows[i]->name.c_str(), rows[i]->age);
	}
}
Row* Table::QueryByAge(int age) {
	return ageIndex->FindByAge(age);
}
Row* Table::QueryByName(string name) {
	return nameIndex->FindByName(name);
}