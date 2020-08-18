#include "Node.h"
#include "NodeQueue.h"
#include "SearchContext.h"


void DFSHelper(Node* node, SearchContext& context) {
	cout << "Visiting " << node->name << endl;
	if (node->name == context.name) {
		context.age = node->age;
		context.done = 1;
		return;
	}
	for (vector<Node*>::iterator it = node->children.begin(); it != node->children.end(); ++it)
	{
		DFSHelper(*it, context);
		if (context.done) {
			return;
		}
	}

}

int DFS(Node* root, string target) {
	SearchContext context(target);
	DFSHelper(root, context);
	return context.age;
}

void BFSHelper(Node* root, SearchContext& context) {
	NodeQueue q;
	q.push(root);

	while (!q.empty()) {
		Node* node = q.front();
		q.pop();
		if (node->name == context.name) {
			context.age = node->age;
			break;
		}
		for (vector<Node*>::iterator it = node->children.begin(); it != node->children.end(); ++it)
		{
			if (*it != NULL) {
				q.push(*it);
			}
		}

		cout << node->name << endl;
	}
}

int BFS(Node* root, string target) {
	SearchContext context(target);
	BFSHelper(root, context);
	return context.age;
}

void DFSStackHelper(Node* node, SearchContext& context) {
	stack<Node*> s;
	s.push(node);

	while (!s.empty()) {
		Node* node = s.top();
		s.pop();
		if (node->name == context.name) {
			context.age = node->age;
			break;
		}
		for (vector<Node*>::iterator it = node->children.begin(); it != node->children.end(); ++it)
		{
			if (*it != NULL) {
				s.push(*it);
			}
		}

		cout << node->name << endl;
	}
}

int DFSStack(Node* root, string target) {
	SearchContext context(target);
	DFSStackHelper(root, context);
	return context.age;
}

void TestSearch() {
	Node* DSUS = new Node("Director Sale US", 40, vector<Node*>());
	Node* DSCA = new Node("Director Sale Canada", 41, vector<Node*>());
	Node* DSCH = new Node("Director Sale China", 42, vector<Node*>());
	Node* VPSA = new Node("VP Sale", 50, vector<Node*>{DSUS, DSCA, DSCH});

	Node* DMBE = new Node("DevManager Backend", 35, vector<Node*>());
	Node* DMFE = new Node("DevManager FrontEnd", 36, vector<Node*>());
	Node* DMUI = new Node("DevManager UI", 37, vector<Node*>());
	Node* DMMO = new Node("DevManager Mobile", 38, vector<Node*>());
	Node* VPEG = new Node("VP Eng", 51, vector<Node*>{DMBE, DMFE, DMUI, DMMO});

	Node* TAUS = new Node("Talent Acquisition US", 27, vector<Node*>());
	Node* TACA = new Node("Talent Acquisition CA", 28, vector<Node*>());
	Node* VPHR = new Node("VP HR", 52, vector<Node*>{TAUS, TACA});

	Node* CEO = new Node("CEO", 30, vector<Node*>{VPSA, VPEG, VPHR});

	cout << DFSStack(CEO, "DevManager FrontEnd") << endl;
	delete CEO;
	// since memory is already returned to heap, accessing again will crash
	// cout << VPHR->name;

}