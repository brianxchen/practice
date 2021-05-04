#pragma once
#include "..\Common.h"
#include "Heap.h"
#include "HeapNode.h"

#define INFINITY 999999999

class DijkstraSolver {
public:
	vector<vector<int>> AdjacentMatrix;
	vector<HeapNode*> costs;
	Heap* priorityQueue;
	vector<string> cityNames;
	int numCities;
	DijkstraSolver(vector<vector<int>> AdjacentMatrix) {
		this->AdjacentMatrix = AdjacentMatrix;
		this->numCities = AdjacentMatrix.size();

		cityNames.push_back("SEA");
		cityNames.push_back("SF");
		cityNames.push_back("LA");
		cityNames.push_back("CHI");
		cityNames.push_back("STL");
		cityNames.push_back("NYC");
		cityNames.push_back("ATL");

		// fill out priorityQueue with current minimum costs to get to each city
		priorityQueue = new Heap();
		HeapNode* heapnode = new HeapNode(0, 0);
		costs.push_back(heapnode);
		priorityQueue->addNode(heapnode);

		for (int i = 1; i < numCities; i++) {
			heapnode = new HeapNode(i, INFINITY);
			costs.push_back(heapnode);
			priorityQueue->addNode(heapnode);
		}
	}
	void SolveDijkstra(int destinationID) {
		while (true) {
			// store + print the node we are checking
			HeapNode* top = priorityQueue->peekTop();
			printf("Shortest path to city %d = %d\n", top->cityID, top->cost);

			// end condition if we have arrived at the destination
			if (top->cityID == destinationID) {
				break;
			}

			// pop the first city
			priorityQueue->extractTop();

			// this is the actual algorithm, it's p simple
			// loop through the i-th row of the adjacency matrix to compare the cost with
			// the minimum cost in the costs matrix
			for (int i = 0; i < numCities; i++) {
				// only compare if the value isn't 0 (because 0 means no path)
				if (AdjacentMatrix[top->cityID][i] != 0) {

					// alternative cost is the cost it takes to get to top + cost to next city
					int altCost = top->cost + AdjacentMatrix[top->cityID][i];

					// adjust the minimum cost if it's less than the current min cost
					if (altCost < costs[i]->cost) {
						priorityQueue->adjustCost(costs[i], altCost);
						costs[i]->cost = altCost;
					}
				}
			}
		}
	}
};

void testDijkstra() {
	/*DijkstraSolver* d = new DijkstraSolver({
		{0, 137, 0, 157, 0, 237, 0},
		{137, 0, 98, 179, 274, 0, 0},
		{0, 98, 0, 0, 206, 0, 130},
		{157, 179, 0, 0, 206, 111, 0},
		{0, 274, 206, 206, 0, 197, 157},
		{237, 0, 0, 111, 197, 0, 83},
		{0, 0, 130, 0, 157, 83, 0}
		});
		*/
	DijkstraSolver* dtest = new DijkstraSolver({
	{0, 1, 0, 157, 0, 237, 0},
	{1, 0, 98, 2, 274, 0, 0},
	{0, 98, 0, 0, 4, 0, 5},
	{157, 2, 0, 0, 3, 111, 0},
	{0, 274, 4, 3, 0, 197, 157},
	{237, 0, 0, 111, 197, 0, 83},
	{0, 0, 5, 0, 157, 83, 0}
		});
	dtest->SolveDijkstra(6);
}