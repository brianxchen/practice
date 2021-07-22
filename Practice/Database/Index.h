#pragma once
#include "Row.h"
#include "TreeNode.h"
#define SUCCESS 0
#define INDEX_DUPE 1

// typedef the compare function pointer so we can pass it into functions
// now we can treat "CompareFunction" as a type
typedef int (*CompareFunction) (Row*, Row*);

class Index {
private:
	TreeNode* root;
	CompareFunction f;
	bool unique;
public:
	Index(CompareFunction f, bool unique);
	int AddRow(Row* row);
	Row* FindByAge(int age);
	Row* FindByName(string name);
};