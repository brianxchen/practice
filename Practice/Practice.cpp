#include <iostream>
#include "Leetcode\Leetcode.h"
#include "Common.h"
#include "Complex.h"
#include "MyString.h"


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

void printArr(vector<int> nums) {
    for (auto x : nums) cout << x << "\n";
}

int main()
{

    vector<int> nums { -2, 1, -3, 4, -1, 2, 1, -5, 4 };


    //primitives(); 
    //Test();
    //TestKnapsack();
}
