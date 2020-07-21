#include <iostream>
#include "Person\Person.h"
#include "Matrix\VectorTest.h"
#include "BubbleSort\TestBubbleSort.h"
#include "HumanTower\HumanTower.h"
#include "LIS\RecursiveLIS.h"
#include "Recursion\Hanoi.h"
#include "Bridge\BuildBridge.h"
#include "Knapsack\Knapsack.h"
#include "Leetcode/Leetcode.h"
#include "Common.h"

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

void primitives() {
    cout << "sizeof(void*) = " << sizeof(void*) << "\n";
    cout << "sizeof(int) = " << sizeof(int) << "\n";
    cout << "sizeof(short) = " << sizeof(short) << "\n";
    cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << "\n";
    cout << "sizeof(long) = " << sizeof(long) << "\n";
    cout << "sizeof(long long) = " << sizeof(long long) << "\n";
    cout << "sizeof(bool) = " << sizeof(bool) << "\n";

    char a = -1;
    printf("a = %02X\n", a);

    short b = 300;
    printf("b = %d\n", b);
    short* pb = &b;
    char* pc = (char*) pb;
    *pc = *pc | 0x10;
    printf("b = %d\n", b);

    pc++;
    *pc = *pc | 0x20;
    printf("b = %d\n", b);


    int d = -10;
    printf("int d = %d\n", d);
    printf("d = %02X\n", d);
    char* pd = (char*) &d;
    pd += 3;
    *pd = *pd & 0x7F;
    printf("d = %d\n", d);

    if (3) {
        cout << "hi1";
    }
    if (-1){
        cout << "hi2";
    }
    if (0) {
        cout << "hi3";
    }

}

int main()
{
    primitives(); 
    //Test();
    //TestKnapsack();
}
