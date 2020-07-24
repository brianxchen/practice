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

vector<vector<int>> Create2DArray(int a, int b) {
    vector<vector<int>> TwoD = vector<vector<int>>();
    for (int i = 0; i < a; i++) {
        vector<int> row = vector<int>();
        for (int j = 0; j < b; j++) {
            row.push_back(0);
        }
        TwoD.push_back(row);
    }
    return TwoD;
}
vector<vector<tuple<int, int, char>>> Create2DTupleArray(int a, int b) {
    vector<vector<tuple<int, int, char>>> TwoD = vector<vector<tuple<int, int, char>>>();
    for (int i = 0; i < a; i++) {
        vector<tuple<int, int, char>> row = vector<tuple<int, int, char>>();
        for (int j = 0; j < b; j++) {
            row.push_back(tuple<int, int, char>(0, 0, '*'));
        }
        TwoD.push_back(row);
    }
    return TwoD;
}

int GetElement(vector<vector<int>> f, int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }
    return f[i][j];
}

int LongestCommonSubsequence(string a, string b) {
    int m = a.length();
    int n = b.length();

    vector<vector<int>> f = Create2DArray(m, n);

    vector<vector<tuple<int, int, char>>> backtrack = Create2DTupleArray(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                f[i][j] = GetElement(f, i - 1, j - 1) + 1;
                backtrack[i][j] = tuple<int, int, char>(i - 1, j - 1, a[i]);
            }
            else {
                if (GetElement(f, i - 1, j) >= GetElement(f, i, j - 1)) {
                    f[i][j] = GetElement(f, i - 1, j);
                    backtrack[i][j] = tuple<int, int, char>(i - 1, j, '-');
                }
                else {
                    f[i][j] = GetElement(f, i, j - 1);
                    backtrack[i][j] = tuple<int, int, char>(i, j - 1, '-');
                }
            }
            cout << i << ", " << j << " currently at " << get<0>(backtrack[i][j]) << ", " << get<1>(backtrack[i][j]) << ", char = " << get<2>(backtrack[i][j]) << "\n";
        }
    }


    string answer;
    int y = m - 1;
    int x = n - 1;
    while (x >= 0 && y >= 0) {
        tuple<int, int, char> tempBacktrack = backtrack[y][x];
        char temp = get<2>(tempBacktrack);
        cout << "currently at " << y << ", " << x << ", char = " << temp <<  "\n";
        if (temp != '-') {
            answer = temp + answer;
        }
        
        x = get<1>(tempBacktrack);
        y = get<0>(tempBacktrack);
    }


    cout << answer << "\n";

    return f[m - 1][n - 1];
}
int main()
{
    cout << LongestCommonSubsequence("acbdea", "abcda");
    //primitives(); 
    //Test();
    //TestKnapsack();
}
