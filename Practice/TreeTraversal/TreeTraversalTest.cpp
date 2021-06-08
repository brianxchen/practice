#include "TreeTraversalTest.h"
#include "TreeNode.h"
#include "StackItem.h"
/*
	Tree traversal implementations with a recursive algorithm and an iterative
	algorithm (using a stack).

	in order traversal: left, self, right
	pre order traversal: self, left, right
	post order traversal: left, right, self
	-- note that left always goes before right! the difference is only in 
	when self is printed

*/
TreeNode* createTree() {
	TreeNode* b = new TreeNode("because");
	TreeNode* l = new TreeNode("like");
	TreeNode* I = new TreeNode("I");
	TreeNode* s = new TreeNode("Seattle");
	TreeNode* i = new TreeNode("is");
	TreeNode* w = new TreeNode("weather");
	TreeNode* g = new TreeNode("good");
	TreeNode* t = new TreeNode("the");

	b->left = l;
	b->right = i;
	l->left = I;
	l->right = s;
	i->left = w;
	i->right = g;
	w->left = t;

	return b;
}
void recursiveInOrder(TreeNode* node, string& resultingString) {
	if (node == NULL) {
		return;
	}
	recursiveInOrder(node->left, resultingString);
	resultingString += node->word + " ";
	recursiveInOrder(node->right, resultingString);
}
void recursivePreOrder(TreeNode* node, string& resultingString) {
	if (node == NULL) {
		return;
	}
	resultingString += node->word + " ";
	recursivePreOrder(node->left, resultingString);
	recursivePreOrder(node->right, resultingString);
}
void recursivePostOrder(TreeNode* node, string& resultingString) {
	if (node == NULL) {
		return;
	}
	recursivePostOrder(node->left, resultingString);
	recursivePostOrder(node->right, resultingString);
	resultingString += node->word + " ";
}

string iterativeInOrder(TreeNode* node) {
	string resultingString = "";
	stack<StackItem*> s;
	StackItem* stackRoot = new StackItem(1, createTree());
	s.push(stackRoot);
	while (!s.empty()) {
		StackItem* item = s.top();
		s.pop();
		if (item->operation == 0) {
			resultingString += item->node->word + " ";
		}
		else {
			if (item->node != NULL) {
				s.push(new StackItem(1, item->node->right));
				s.push(new StackItem(0, item->node));
				s.push(new StackItem(1, item->node->left));
			}
		}
	}
	return resultingString;
}
string iterativePreOrder(TreeNode* node) {
	string resultingString = "";
	stack<StackItem*> s;
	StackItem* stackRoot = new StackItem(1, createTree());
	s.push(stackRoot);
	while (!s.empty()) {
		// c++ makes popping and peeking different methods oops
		// top() returns stackitem, pop() returns void
		StackItem* item = s.top();
		s.pop();
		if (item->operation == 0) {
			resultingString += item->node->word + " ";
		}
		else {
			if (item->node != NULL) {
				// stack is backwards
				s.push(new StackItem(1, item->node->right));
				s.push(new StackItem(1, item->node->left));
				s.push(new StackItem(0, item->node));

			}
		}
	}
	return resultingString;
}

string iterativePostOrder(TreeNode* node) {
	string resultingString = "";
	stack<StackItem*> s;
	StackItem* stackRoot = new StackItem(1, createTree());
	s.push(stackRoot);
	while (!s.empty()) {
		StackItem* item = s.top();
		s.pop();
		if (item->operation == 0) {
			resultingString += item->node->word + " ";
		}
		else {
			if (item->node != NULL) {
				// stack is backwards
				s.push(new StackItem(0, item->node));
				s.push(new StackItem(1, item->node->right));
				s.push(new StackItem(1, item->node->left));
			}
		}
	}
	return resultingString;
}
void testTree() {
	string resultingString = "";
	recursiveInOrder(createTree(), resultingString);
	printf("In order: %s\n", resultingString.c_str());

	resultingString = "";
	recursivePreOrder(createTree(), resultingString);
	printf("Pre order: %s\n", resultingString.c_str());

	resultingString = "";
	recursivePostOrder(createTree(), resultingString);
	printf("Post order: %s\n", resultingString.c_str());

	printf("Iterative in order: %s\n", iterativeInOrder(createTree()).c_str());
	printf("Iterative pre order: %s\n", iterativePreOrder(createTree()).c_str());
	printf("Iterative post order: %s\n", iterativePostOrder(createTree()).c_str());

}