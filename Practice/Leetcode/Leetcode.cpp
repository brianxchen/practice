/*
    Leetcode solutions
*/
#include "Leetcode.h"

int singleNumber(vector<int>& nums) {
    int a = 0;
    for(auto x : nums) {
        a ^= x;
    }
    return a;
}

bool isPerfectSquare(int n) {
    int i = 1;
    while (n > 0) {
        n -= i;
        i += 2;
        if (!n) return true;
    }
    return false;
}

int mySqrt(int x) {
    if (x == 0) return 0;
    long low = 1, high = x;

    while (low <= high) {
        long mid = (low + high) / 2;
        long temp = mid * mid;
        if (temp == x) return mid;
        else if (temp < x) low = mid + 1;
        else high = mid - 1;
    }
    return low - 1;
}

double myPow(double x, int n) {
    double res = 1;
    while (n != 0) {
        if (n % 2 == 1) { // Check base 2 digit
            res = n > 0 ? res * x : res / x; // Multiply if > 0, divide if < 0
        }
        x *= x; // update x
        n /= 2; // get next digit/update n
    }
    return res;
}

void Test() {
    cout << mySqrt(8);
}