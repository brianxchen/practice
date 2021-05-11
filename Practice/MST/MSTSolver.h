#pragma once
#include "Set.h"
#include "Edge.h"

bool EdgeComparerFunction (Edge* i, Edge* j) { return (i->cost < j->cost); }

class MSTSolver {
public:
	vector<Edge*> edges;
	int vertexCount = -1;
	MSTSolver(vector<Edge*> edges) {
		this->edges = edges;
		// convenient way to find the vertex count of edges:
		// the largest vertex between edges a and edges b is the total count
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i]->a > vertexCount) {
				vertexCount = edges[i]->a;
			}
			if (edges[i]->b > vertexCount) {
				vertexCount = edges[i]->b;
			}
		}
		// plus one because we counted from 0
		vertexCount = vertexCount + 1;
	}
	void PrintGraph() {
		printf("vertexCount = %d\n", vertexCount);
		for (int i = 0; i < edges.size(); i++) {
			printf("%d to %d: %d\n", edges[i]->a, edges[i]->b, edges[i]->cost);
		}
		printf("\n");
	}
	void solveMST() {
		// create list of sets 
		vector<Set*> sets;

		// step one - sort the edges to find lowest edge cost
		std::sort(edges.begin(), edges.end(), EdgeComparerFunction);
		// make a new set for each element, these will be merged when we
		// start building the MST
		for (int i = 0; i < vertexCount; i++) {
			Set* set = new Set();
			set->AddElement(new SetElement(i));
			sets.push_back(set);
		}

		int totalCost = 0;
		int edgesAdded = 0;
		for (int i = 0; i < edges.size(); i++) {
			int a = edges[i]->a;
			int b = edges[i]->b;
			int cost = edges[i]->cost;

			// if a and b are already in the same set (already connected),
			// don't compare/merge the two
			if (sets[a] == sets[b]) {
				continue;
			}

			// merge the sets
			sets[a]->Union(sets[b]);

			// update every cityID in b to match that of a
			// this will make sure we don't merge elements in b again
			// since it's already connected to the MST
			for (int j = 0; j < sets[b]->Elements.size(); j++) {
				int cityIDofJinB = sets[b]->Elements[j]->cityID;
				sets[cityIDofJinB] = sets[a];
			}
			totalCost += cost;
			edgesAdded++;
			printf("Add edge from %d to %d: %d\n", a, b, cost);
			if (edgesAdded == vertexCount - 1) {
				printf("Total cost = %d\n", totalCost);
				break;
			}
		}
	}
};

void testMSTSolver() {
	// example graph in email called "MST solver graph example"
	vector<Edge*> edges;
	edges.push_back(new Edge(0, 1, 5));
	edges.push_back(new Edge(1, 2, 98));
	edges.push_back(new Edge(0, 5, 237));
	edges.push_back(new Edge(0, 3, 157));
	edges.push_back(new Edge(1, 3, 179));
	edges.push_back(new Edge(1, 4, 3));
	edges.push_back(new Edge(2, 4, 206));
	edges.push_back(new Edge(2, 6, 130));
	edges.push_back(new Edge(3, 4, 10));
	edges.push_back(new Edge(3, 5, 111));
	edges.push_back(new Edge(4, 5, 197));
	edges.push_back(new Edge(4, 6, 157));
	edges.push_back(new Edge(5, 6, 1));
	MSTSolver* m = new MSTSolver(edges);
	m->solveMST();
}