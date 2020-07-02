// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

int RecursiveLISHelper(int i, int* a, int length, int* pOverallMax, int* saved) {
    if (saved[i] != -1) { // if already memorized don't recalculate
        return saved[i];
    }

    int maxSoFarEndAtI = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) {
            maxSoFarEndAtI = std::max(maxSoFarEndAtI, RecursiveLISHelper(j, a, length, pOverallMax, saved) + 1);
        }
    }
    printf("i = %d, max so far at I = %d\n", i, maxSoFarEndAtI);
    saved[i] = maxSoFarEndAtI; // update saved memory

    // update overall max - remember *pOverallMax changes the value @ the memory location
    *pOverallMax = std::max(maxSoFarEndAtI, *pOverallMax); 
    return maxSoFarEndAtI;
}
int RecursiveLIS(int* a, int length) {
    int* saved = new int[length];

    // Initialize array w/ -1
    for (int i = 0; i < length; i++) {
        saved[i] = -1;
    }
    saved[0] = 1; // Boundary condition i = 0 is known

    int overallMax = -1; // Minimize initial overallmax

    // passing in pointer to overallMax because it's dereferenced in the helper
    RecursiveLISHelper(length - 1, a, length, &overallMax, saved);
    return overallMax;
}

int LIS(int *a, int length) {

    int* f = new int[length]; // saved results of LIS that ends at i
    int overallMax = -1;

    for (int i = 0; i < length; i++) { // loop through all possible i
        int maxSoFarEndAtI = 1; // minimum length of I is 1
        for (int j = 0; j < i; j++) { // compares subproblems to i
            if (a[j] < a[i]) { // check validity of subproblem
                printf("f[j] + 1 = %d\n", f[j] + 1);

                // update maxsofar if f[j] + 1 is greater.
                // f[j] + 1 because f[j] is the greatest subproblem, so 
                // one more jump is needed to get to i.
                maxSoFarEndAtI = std::max(maxSoFarEndAtI, f[j] + 1);
                
            }
            printf("Max so far ending at %d = %d\n", i, maxSoFarEndAtI);
        }
        f[i] = maxSoFarEndAtI; // Update solution array 
        overallMax = std::max(overallMax, maxSoFarEndAtI); // update overallmax
    }
    return overallMax;
}
int GreedyLIS(int *a, int length) {
    int sol = 0;
    printf("Size of array is %d\n", length);

    for (int i = 0; i < length; i++) {
        int currNum = a[i];
        int currMax = 1;
        for (int j = i + 1; j < length; j++) {
            if (a[j] > currNum) {
                currNum = a[j];
                currMax++;
            }
        }
        sol = std::max(currMax, sol);
    }
    return sol;
}

int main()
{
    std::cout << "Hello World!\n";

    int nums[] = {1, 2, 5, 3, 4};

    //printf("Size of array = %d\n", sizeof(nums) / sizeof(nums[0]));

    printf("Longest subsequence is %d\n", RecursiveLIS(nums, sizeof(nums) / sizeof(nums[0])));
}
