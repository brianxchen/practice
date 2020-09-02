#include "FamilyPicture.h"

int people = 5;
int seats = 4;
int solution = 0;
bool seatedPeople[5] = { false };
string nameArray[5] = { "Fei", "Yan", "Grace", "Brian", "Jessica" };
int familyAnswer[5] = { 0 };

void PrintFamily() { 
	solution++;
	cout << "#" << solution << ": ";
	for (int i = 0; i < seats; i++) {
		cout << nameArray[familyAnswer[i]] << " ";
	}
	cout << "\n";
}

void PlacePerson(int index) {
	if (index == seats) {
		PrintFamily();
		return;
	}
	for (int i = 0; i < people; i++) {
		if (!seatedPeople[i]) {
			familyAnswer[index] = i;
			seatedPeople[i] = true;
			PlacePerson(index + 1);
			seatedPeople[i] = false;
		}
	}
}



void TestFamilyPicture() {
	PlacePerson(0);
}