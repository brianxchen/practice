// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "VectorTest.h"
#include "AbstractComparer.h"
#include "AgeComparerIncreasing.h"
#include "HumanTower.h"

using namespace std;

void Hanoi(int n, string source, string intermediate, string destination) {
    if (n == 1) {
        cout << source << "->" << destination << "\n";
        return;
    }
    Hanoi(n - 1, source, destination, intermediate);
    Hanoi(1, source, intermediate, destination);
    Hanoi(n - 1, intermediate, source, destination); 
}


void swapPeopleByReference(Person& a, Person& b) {
    Person temp = a;
    a = b;
    b = temp;
}

void printPeople(vector<Person> people) {
    for (auto x : people) {
        cout << "\n" << x.ToString();
    }
}

typedef bool compareFunc(Person a, Person b);

bool compareByAgeDecreasing(Person a, Person b) {
    return a.age < b.age;
}

bool compareByAgeIncreasing(Person a, Person b) {
    return a.age > b.age;
}

bool compareByNameLengthIncreasing(Person a, Person b) {
    return a.name.length() > b.name.length();
}

void BubbleSortWithCompareFunc(vector<Person>& people, compareFunc compare) {
    int len = people.size();
    for (int top = len - 1; top > 0; top--) {
        for (int curr = 0; curr < top; curr++) {
            cout << "comparing " << curr << " with " << curr + 1 << "\n";
            if (compare(people[curr], people[curr + 1])) {
                swapPeopleByReference(people[curr], people[curr + 1]);
            }
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

void swapPassByPointer(int* x, int* y)
{
    int z = *x;
    *x = *y;
    *y = z;
}


void swapPassByReference(int& x, int& y)
{
    int z = x;
    x = y;
    y = z;
}

int part(vector<int>& nums, int low, int high) {
    int pivot = nums[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i], nums[high]);
    return i + 1;
}

void quicksort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int p = part(nums, low, high);
        quicksort(nums, low, p - 1);
        quicksort(nums, p + 1, high);
    }
}

void printArr(vector<int> nums) {
    for (auto x : nums) cout << x << "\n";
}

int main()
{

    vector<Person> people;
    people.push_back(Person(1, "Ad", true));
    people.push_back(Person(2, "Badfs", true));
    people.push_back(Person(3, "C", true));
    people.push_back(Person(4, "Ddgsdgsg", true));

    TestHumanTower();

    //BubbleSortWithCompareFunc(people, compareByNameLengthIncreasing);
    
    AgeComparerIncreasing a;

    BubbleSortWithCompareObject(people, a);

    printPeople(people);

    //Hanoi(3, "A", "B", "C");


    //MatrixMultiplication();

    //TestSorter();

    //TestVector();
    /*
    int a = 1;
    int b = 2;

    cout << "a = " << a << " b = " << b;

    swap(a, b);
    cout << "\na = " << a << " b = " << b;

    //swapPassByPointer(&a, &b);

    //int nums[] = {1, 2, 5, 3, 4};

    //TestDestructors();

    
    */
}
