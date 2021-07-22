/*
	Implementation of a simple SQL database that supports insertion, queries, and
	dupe-checking.
*/

#include "TestDatabase.h"
#include "Table.h"

void testDatabase() {
	Table* t = new Table();
	t->InsertRow(new Row("a", "Brian", 18));
	t->InsertRow(new Row("b", "Fei", 48));
	t->InsertRow(new Row("c", "Grace", 21));
	t->Dump();

	Row* row = t->QueryByAge(21);
	row->Dump();

	row = t->QueryByName("Fei");
	row->Dump();

	int a = t->InsertRow(new Row("d", "Jessica", 18));
	printf("%d\n", a);

	int b = t->InsertRow(new Row("e", "Brian", 24));
	printf("%d\n", b);
}