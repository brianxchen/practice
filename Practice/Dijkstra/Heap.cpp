#include "Heap.h"

void testHeap() {
	Heap* h = new Heap();
	h->addNode(new HeapNode(1, 40));
	HeapNode* nodetwo = new HeapNode(2, 60);
	h->addNode(nodetwo);
	h->addNode(new HeapNode(3, 10));
	HeapNode* nodefour = new HeapNode(4, 80);
	h->addNode(nodefour);
	h->addNode(new HeapNode(5, 20));
	h->addNode(new HeapNode(6, 30));
	h->addNode(new HeapNode(7, 90));
	h->addNode(new HeapNode(8, 100));
	h->addNode(new HeapNode(9, 50));
	h->addNode(new HeapNode(0, 70));

	h->adjustCost(nodetwo, 15);
	h->adjustCost(nodefour, 45);

	while (!h->isEmpty()) {
		cout << h->peekTop()->cost << endl;
		h->extractTop();
	}

}