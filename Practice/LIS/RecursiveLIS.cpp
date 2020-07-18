#include "RecursiveLIS.h"

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