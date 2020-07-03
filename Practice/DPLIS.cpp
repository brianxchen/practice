#include "DPLIS.h"

int exposedFromLIS = 1;


int LIS(int* a, int length) {

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

    delete[] f;
    return overallMax;
}