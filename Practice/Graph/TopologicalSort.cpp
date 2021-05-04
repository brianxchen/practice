#include "Vertex.h"
#include "VertexQueue.h"
#include "TopologicalSort.h"

void printIndegrees(vector<Vertex*> vertices) {
	for (int i = 0; i < vertices.size(); i++) {
		printf("%s: %d \n", vertices[i]->value.c_str(), vertices[i]->indegree);
	}
}

void TopologicalSort(vector<Vertex*> vertices) {
	// Calculates indegrees of all vertices
	for (int i = 0; i < vertices.size(); i++) {
		for (int j = 0; j < vertices[i]->outedges.size(); j++) {
			vertices[i]->outedges[j]->indegree++;
		}
	}
	printIndegrees(vertices);

	VertexQueue* q = new VertexQueue;

	// Puts initial 0-in degreed vertices in queue
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->indegree == 0) {
			q->push(vertices[i]);
		}
	}

	// Pop vertices from queue until empty
	while (!q->empty()) {
		Vertex* v = q->front();
		for (int i = 0; i < v->outedges.size(); i++) {
			// Decrement the indegree of each of the outedges
			v->outedges[i]->indegree--;
			
			// Add to the queue if, after decrementing, the outedge's indegree is now 0
			if (v->outedges[i]->indegree == 0) {
				q->push(v->outedges[i]);
			}
		}
		printf("%s ", v->value.c_str());
		q->pop();
	}
}

void solveDAG() {
	Vertex* a = new Vertex("A");
	Vertex* b = new Vertex("B");
	Vertex* c = new Vertex("C");
	Vertex* d = new Vertex("D");
	Vertex* e = new Vertex("E");
	Vertex* f = new Vertex("F");
	Vertex* g = new Vertex("G");
	Vertex* h = new Vertex("H");
	a->addVertex(g);
	a->addVertex(c);
	b->addVertex(c);
	d->addVertex(e);
	d->addVertex(f);
	c->addVertex(e);
	e->addVertex(f);
	f->addVertex(g);
	g->addVertex(h);

	vector<Vertex*> vertices;
	vertices.push_back(a);
	vertices.push_back(b);
	vertices.push_back(c);
	vertices.push_back(d);
	vertices.push_back(e);
	vertices.push_back(f);
	vertices.push_back(g);
	vertices.push_back(h);

	TopologicalSort(vertices);
}