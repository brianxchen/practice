#pragma once
#include "Row.h"

class TreeNode {
public:
	Row* value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(Row* value, TreeNode* left, TreeNode* right) {
		this->value = value;
		this->left = left;
		this->right = right;
	}
};