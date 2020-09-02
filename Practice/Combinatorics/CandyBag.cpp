#include "FamilyPicture.h"

int candies = 6;
int wantedCandies = 3;
int candySolution = 0;
string candyNames[6] = { "Chocolate", "Kiss", "Corn", "Bubble Tape", "Peeps", "Jawbreaker"};
int candyAnswer[6] = { 0 };

void PrintCandies() {
	candySolution++;
	cout << "#" << candySolution << ": ";
	for (int i = 0; i < wantedCandies; i++) {
		cout << candyNames[candyAnswer[i]] << " ";
	}
	cout << "\n";
}

void PickCandy(int index, int prevCandy) {
	if (index == wantedCandies) {
		PrintCandies();
		return;
	}
	for (int i = prevCandy + 1; i < candies - wantedCandies + index + 1; i++) {
		candyAnswer[index] = i;
		PickCandy(index + 1, i);
	}
}



void TestCandyBag() {
	PickCandy(0, -1);
}