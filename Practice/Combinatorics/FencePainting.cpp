#include "FencePainting.h"

int panels = 5;
int colors = 3;
string colorArray[3] = { "red", "green", "blue" };
int answer[5] = { 0 };

void PrintResult() {
	for (auto x : answer) {
		cout << colorArray[x] << " ";
	}
	cout << "\n";
}

void PlaceFenceNumber(int index) {
	if (index == panels) {
		PrintResult();
		return;
	}
	for (int i = 0; i < colors; i++) {
		answer[index] = i;
		PlaceFenceNumber(index + 1);
	}
}

void TestFencePainting() {
	PlaceFenceNumber(0);
}