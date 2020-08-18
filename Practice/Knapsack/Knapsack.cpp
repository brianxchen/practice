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

int KnapsackGetElement(vector<vector<int>> f, int i, int j) {
	if (j < 0) {
		cout << "j < 0";
		exit(1);
	}
	if (i < 0) {
		return 0;
	}
	return f[i][j];
}

int Knapsack01(vector<KnapsackItem> items, int capacity) {
	int len = items.size();

	vector<vector<int>> f;

	for (int i = 0; i < len; i++) {
		f.push_back(vector<int>());
		for (int j = 0; j <= capacity; j++) {
			int cell = KnapsackGetElement(f, i-1, j);
			if (j - items[i].size >= 0) {
				cell = max(cell,
					KnapsackGetElement(f, i-1, j - items[i].size) + items[i].value);
			}
			f[i].push_back(cell);
		}
	}

	return f[len - 1][capacity];
}

void TestKnapsack() {
	vector<KnapsackItem> items;
	items.push_back(KnapsackItem(10, 60, "a"));
	items.push_back(KnapsackItem(20, 100, "a"));
	items.push_back(KnapsackItem(30, 120, "a"));
	cout << Knapsack01(items, 50);

}

