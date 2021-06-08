#pragma once
#include "../Common.h"

class TreeNode {
public:
	string word;
	TreeNode* left;
	TreeNode* right;
	TreeNode(string word) {
		this->word = word;
		this->left = NULL;
		this->right = NULL;
	}
};