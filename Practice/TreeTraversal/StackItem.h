#pragma once
#include "TreeNode.h"
class StackItem {
public:
	int operation; // 0 = print, 1 = process
	TreeNode* node;
	StackItem(int operation, TreeNode* node) {
		this->operation = operation;
		this->node = node;
	}
};