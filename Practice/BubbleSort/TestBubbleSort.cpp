#include "TestBubbleSort.h"

typedef bool compareFunc(const Person& a, const Person& b);

bool compareByAgeDecreasing(const Person& a, const Person& b) {
    return a.age < b.age;
}

bool compareByAgeIncreasing(const Person& a, const Person& b) {
    return a.age > b.age;
}

bool compareByNameLengthIncreasing(const Person& a, const Person& b) {
    return a.name.length() > b.name.length();
}



void swapPeopleByReference(Person& a, Person& b) {
    Person temp = a;
    a = b;
    b = temp;
}

void printPeople(const vector<Person>& people) {
    for (auto x : people) {
        cout << "\n" << x.ToString();
    }
}


void BubbleSortWithCompareFunc(vector<Person>& people, compareFunc compare) {
    int len = people.size();
    for (int top = len - 1; top > 0; top--) {
        bool swapped = false;
        for (int curr = 0; curr < top; curr++) {
            cout << "comparing " << curr << " with " << curr + 1 << "\n";
            if (compare(people[curr], people[curr + 1])) {
                swapPeopleByReference(people[curr], people[curr + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void BubbleSortWithCompareObject(vector<Person>& people, AbstractComparer& comparer) {
    int len = people.size();
    for (int top = len - 1; top > 0; top--) {
        for (int curr = 0; curr < top; curr++) {
            cout << "comparing " << curr << " with " << curr + 1 << "\n";
            if (comparer.Compare(people[curr], people[curr + 1])) {
                swapPeopleByReference(people[curr], people[curr + 1]);
            }
        }
    }
}

void TestBubbleSort() {

    vector<Person> people;
    people.push_back(Person(1, "Ad", true));
    people.push_back(Person(2, "Badfs", true));
    people.push_back(Person(3, "C", true));
    people.push_back(Person(4, "Ddgsdgsg", true));

    BubbleSortWithCompareFunc(people, compareByNameLengthIncreasing);

    AgeComparerIncreasing a;

    BubbleSortWithCompareObject(people, a);

    printPeople(people);
}