#include "Index.h"

Index::Index(CompareFunction f, bool unique) {
	root = NULL;
	this->f = f;
	this->unique = unique;
}

int Index::AddRow(Row* row) {
	
	// successfully added a row to the tree if we've advanced to a NULL node
	if(root == NULL){
		root = new TreeNode(row, NULL, NULL);
		return SUCCESS;
	}
	TreeNode* curr = root;
	while (true) {
		int compareResult = f(row, curr->value);
		if (compareResult == 0) {
			if (unique) {
				return INDEX_DUPE;
			}
			// if not unique, just go to the left
			if (curr->left == NULL) {
				curr->left = new TreeNode(row, NULL, NULL);
				break;
			}
			curr = curr->left;
		}
		else if (compareResult < 0) {
			if (curr->left == NULL) {
				curr->left = new TreeNode(row, NULL, NULL);
				break;
			}
			curr = curr->left;
		}
		else {
			if (curr->right == NULL) {
				curr->right = new TreeNode(row, NULL, NULL);
				break;
			}
			curr = curr->right;
		}
	}

	return SUCCESS;
}

Row* Index::FindByAge(int age) {
	TreeNode* curr = root;
	while (true) {
		if (age == curr->value->age) {
			return curr->value;
		}
		else if (age < curr->value->age) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
}

Row* Index::FindByName(string name) {
	TreeNode* curr = root;
	while (true) {
		int compareResult = name.compare(curr->value->name);
		if (compareResult == 0) {
			return curr->value;
		}
		else if (compareResult < 0) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
}