// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person\Person.h"
#include "Matrix\VectorTest.h"
#include "BubbleSort\TestBubbleSort.h"
#include "HumanTower\HumanTower.h"
#include "LIS\RecursiveLIS.h"
#include "Recursion\Hanoi.h"



using namespace std;

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
    
    TestBubbleSort();

    int nums[] = { 1, 2, 3, 4 };
    cout << RecursiveLIS(nums, 4);
    //cout << GreedyLIS(nums, 4);
    MatrixMultiplication();

    //TestSorter();

    //TestVector();

    /*
    
    int a = 1;
    int b = 2;

    cout << "a = " << a << " b = " << b;

    swap(a, b);
    cout << "\na = " << a << " b = " << b;

    //swapPassByPointer(&a, &b);

    int nums[] = {1, 2, 5, 3, 4};

    //TestDestructors();

    
    */
}
