#pragma once
#include "../Common.h"
#include "SearchContext.h"

class Node {
	public:
		string name;
		int age;
		vector<Node*> children;
		Node(string name, int age, vector<Node*> children) {
			this->name = name;
			this->age = age;
			this->children = children;
		}
		~Node() {
			cout << "Destructing " << this->name << endl;
			for (vector<Node*>::iterator it = this->children.begin(); it != this->children.end(); ++it)
			{
				delete *it;
			}
		}
};

