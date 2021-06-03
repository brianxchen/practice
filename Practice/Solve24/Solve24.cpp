#include "Item24.h"
#include "Solve24.h"

int count24 = 0;
std::map<string, int> solutions;

bool equals(float a, float b) {
	return abs(a - b) < 0.0001;
}

// Check if map contains key (C++17) to de-dupe
bool contains(map<string, int>& m, string& key) {
	return m.find(key) == m.end();
}

void Solver24(vector<Item24*> items) {
	// End condition
	if (items.size() == 1) {
		if (equals(24, items[0]->value) && contains(solutions, items[0]->expression)) {
			solutions[items[0]->expression] = 1; // Set map to include this expression
			count24++;
			cout << "#" + to_string(count24) + ": " + items[0]->expression + "\n";
		}
		return;
	}

	// Outer loop to select first number
	for (int i = 0; i < items.size(); i++) {
		// Inner loop to select second number 
		for (int j = 0; j < items.size(); j++) {
			if (i == j) continue; // Don't test the same number against itself
			// Iterate through each operation
			for (int op = 0; op < 4; op++) {
				bool bail = false;
				Item24* newItem = new Item24();
				newItem->lastOp = op;
				switch (op) {
					case 0:
						// For normalization reasons, bail if first # < second #
						if (items[i]->value < items[j]->value) {
							bail = true;
							break;
						}
						newItem->value = items[i]->value + items[j]->value;
						newItem->expression = items[i]->expression + "+" + items[j]->expression;
						break;
					case 1:
						newItem->value = items[i]->value - items[j]->value;
						newItem->expression = items[i]->expression + "-";
						// Add parentheses *if* the last operation was + or -
						if (items[j]->lastOp == 0 || items[j]->lastOp == 1) {
							newItem->expression += "(";
						}
						newItem->expression += items[j]->expression;
						if (items[j]->lastOp == 0 || items[j]->lastOp == 1) {
							newItem->expression += ")";
						}
						break;
					case 2: 
						if (items[i]->value < items[j]->value) {
							bail = true;
							break;
						}
						newItem->value = items[i]->value * items[j]->value;
						newItem->expression = "";
						if (items[i]->lastOp == 0 || items[i]->lastOp == 1) {
							newItem->expression += "(";
						}
						newItem->expression += items[i]->expression;
						if (items[i]->lastOp == 0 || items[i]->lastOp == 1) {
							newItem->expression += ")";
						}

						newItem->expression += "*";

						if (items[j]->lastOp == 0 || items[j]->lastOp == 1) {
							newItem->expression += "(";
						}
						newItem->expression += items[j]->expression;
						if (items[j]->lastOp == 0 || items[j]->lastOp == 1) {
							newItem->expression += ")";
						}

						break;
					case 3:
						newItem->value = items[i]->value / items[j]->value;
						newItem->expression = "";
						if (items[i]->lastOp == 0 || items[i]->lastOp == 1) {
							newItem->expression += "(";
						}
						newItem->expression += items[i]->expression;
						if (items[i]->lastOp == 0 || items[i]->lastOp == 1) {
							newItem->expression += ")";
						}

						newItem->expression += "/";

						if (items[j]->lastOp != -1) {
							newItem->expression += "(";
						}
						newItem->expression += items[j]->expression;
						if (items[j]->lastOp != -1) {
							newItem->expression += ")";
						}
						break;
					}
				if (bail) continue;

				// Create new array to recurse with
				vector<Item24*> newItems;
				newItems.push_back(newItem);
				for (int k = 0; k < items.size(); k++) {
					if (k != i && k != j) { // If you haven't used i or j
						newItems.push_back(items[k]); // add items[k] to array
					}
				}
				Solver24(newItems);
			}
		}
	}
}

void Solve24() {
	vector<Item24*> cards;
	
	cards.push_back(new Item24(4, "4"));
	cards.push_back(new Item24(6, "6"));
	cards.push_back(new Item24(6, "6"));
	cards.push_back(new Item24(10, "10"));
	/*
	cards.push_back(new Item24(11, "11"));
	cards.push_back(new Item24(7, "7"));
	cards.push_back(new Item24(5, "5"));
	cards.push_back(new Item24(1, "1"));
	
	cards.push_back(new Item24(6, "6"));
	cards.push_back(new Item24(6, "6"));
	cards.push_back(new Item24(6, "6"));
	cards.push_back(new Item24(6, "6"));
	*/
	Solver24(cards);
	if (count24 == 0) cout << "No solutions\n";
}