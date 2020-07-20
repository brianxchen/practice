#include "Knapsack.h"
#include "KnapsackItem.h"

int Knapsack(vector<KnapsackItem> items, int capacity) {
	int len = items.size();
	
	vector<int> f (capacity + 1); // solution array needs to store up to f[capacity]
	f[0] = 0;

	for (int i = 1; i <= capacity; i++) {
		int maxValue = f[i-1]; // max so far is at least f[i-1] - this is when the i-th slot is not occupied
		
		// Now consider all the cases when the i-th slot is already occupied
		for (int j = 0; j < len; j++) {
			if (items[j].size <= i) { // check whether size is greater than the remaining i
				maxValue = max(maxValue, f[i - items[j].size] + items[j].value);
			}
		}
		f[i] = maxValue; // Final update should only happen once
	}
	return f[capacity];
}

void TestKnapsack() {
	vector<KnapsackItem> items;
	items.push_back(KnapsackItem(10, 50, "a"));
	items.push_back(KnapsackItem(5, 7, "a"));
	items.push_back(KnapsackItem(100, 2, "a"));
	items.push_back(KnapsackItem(1, 8, "a"));
	cout << Knapsack(items, 15);

}

