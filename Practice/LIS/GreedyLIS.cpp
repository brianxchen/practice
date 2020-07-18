#include "GreedyLIS.h"


int GreedyLIS(int* a, int length) {
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