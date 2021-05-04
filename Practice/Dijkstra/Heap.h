#pragma once
#include "../Common.h"
#include "HeapNode.h"

class Heap {
public:
	vector<HeapNode*> nodes;
	map<HeapNode*, int> nodeIndexMap;
	Heap() {
	}

	void printHeap() {
		for (int i = 0; i < nodes.size(); i++) {
			printf("%d: CityId = %d, cost = %d, index = %d\n", i, nodes[i]->cityID, nodes[i]->cost, nodeIndexMap[nodes[i]]);
		}
	}
	int getParentIndex(int index) {
		if (index == 0) {
			return -1;
		}
		return (index - 1) / 2;
	}
	int getLeftChildIndex(int index) {
		int leftChildIndex = 2 * index + 1;
		if (leftChildIndex >= nodes.size()) {
			leftChildIndex = -1;
		}
		return leftChildIndex;
	}
	int getRightChildIndex(int index) {
		int rightChildIndex = 2 * index + 2;
		if (rightChildIndex >= nodes.size()) {
			rightChildIndex = -1;
		}
		return rightChildIndex;
	}

	// from a current index, move a heapnode up until the heap is restored
	void bubbleUp(int index) {
		while (true) {
			int parentIndex = getParentIndex(index);

			// if no parentindex (aka the current node is the head)
			if (parentIndex == -1) {
				// adjust the hashmap to account for this
				nodeIndexMap[nodes[index]] = index;
				break;
			}

			// if the current node is smaller than parentIndex, bubble up
			if (nodes[parentIndex]->cost > nodes[index]->cost) {

				// swap the nodes
				HeapNode* parentNode = nodes[parentIndex];
				HeapNode* currentNode = nodes[index];
				nodes[parentIndex] = currentNode;
				nodes[index] = parentNode;

				// swap the hashmap values
				nodeIndexMap[parentNode] = index;
				nodeIndexMap[currentNode] = parentIndex;

				index = parentIndex;
			}
			// otherwise, the heap is ok and we just update the hashmap to account for it
			else {
				nodeIndexMap[nodes[index]] = index;
				break;
			}
		}
	}

	// from current index, move node down until heap is restored
	void bubbleDown(int index) {
		while (true) {
			int leftChildIndex = getLeftChildIndex(index);
			int rightChildIndex = getRightChildIndex(index);
			if (leftChildIndex == -1) {
				// Leaf node
				break;
			}
			if (rightChildIndex == -1) {
				// left =/= -1, so only left child to compare with
				if (nodes[leftChildIndex]->cost < nodes[index]->cost) {
					HeapNode* leftNode = nodes[leftChildIndex];
					HeapNode* currentNode = nodes[index];
					nodes[leftChildIndex] = currentNode;
					nodes[index] = leftNode;

					nodeIndexMap[leftNode] = index;
					nodeIndexMap[currentNode] = leftChildIndex;

					index = leftChildIndex;
				}
				break;
			}

			// current node is smaller than both children so we're good
			if (nodes[index]->cost <= nodes[leftChildIndex]->cost && nodes[index]->cost <= nodes[rightChildIndex]->cost) {
				break;
			}

			// since we now know that current node is smaller than leftchild, we just need to compare 
			// left with right to see which one to swap with
			if (nodes[leftChildIndex]->cost < nodes[rightChildIndex]->cost) {
				HeapNode* leftNode = nodes[leftChildIndex];
				HeapNode* currentNode = nodes[index];
				nodes[leftChildIndex] = currentNode;
				nodes[index] = leftNode;

				nodeIndexMap[leftNode] = index;
				nodeIndexMap[currentNode] = leftChildIndex;

				index = leftChildIndex;
			}
			else {
				HeapNode* rightNode = nodes[rightChildIndex];
				HeapNode* currentNode = nodes[index];
				nodes[rightChildIndex] = currentNode;
				nodes[index] = rightNode;

				nodeIndexMap[rightNode] = index;
				nodeIndexMap[currentNode] = rightChildIndex;

				index = rightChildIndex;
			}
		}
	}
	void addNode(HeapNode* newNode) {
		nodes.push_back(newNode);
		int index = nodes.size() - 1;
		
		bubbleUp(index);
		//printHeap();
		//printf("\n");

	}
	void extractTop() {
		int size = nodes.size();

		HeapNode* topNode = nodes[0];
		HeapNode* lastNode = nodes[size - 1];
		nodeIndexMap.erase(topNode);
		nodes[0] = lastNode;
		nodeIndexMap[lastNode] = 0;
		nodes.resize(size - 1);

		int index = 0;
		
		bubbleDown(index);

		printHeap();
		printf("\n");

	}
	void adjustCost(HeapNode* targetNode, int newCost) {
		int index = nodeIndexMap[targetNode];
		int oldCost = nodes[index]->cost;
		if (oldCost == newCost) {
			return;
		}

		nodes[index]->cost = newCost;

		// bubble up the adjusted node up if the cost is smaller
		if (newCost < oldCost) {
			bubbleUp(index);
		}
		// otherwise bubble down
		else {
			bubbleDown(index);
		}
	}
	HeapNode* peekTop() {
		return nodes[0];
	}
	bool isEmpty() {
		return nodes.size() == 0;
	}
};

void testHeap();