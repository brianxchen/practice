/*
	Archived solutions with notes
*/

#include "Leetcode.h"


void printArr(vector<int> nums) {
    for (auto x : nums) cout << x << "\n";
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
vector<vector<Position>> Create2DPositionArray(int a, int b) {
    vector<vector<Position>> TwoD = vector<vector<Position>>();
    for (int i = 0; i < a; i++) {
        vector<Position> row = vector<Position>();
        for (int j = 0; j < b; j++) {
            row.push_back(Position(0, 0));
        }
        TwoD.push_back(row);
    }
    return TwoD;
}

int GetRowElement(vector<int> row, int j) {
    if (j < 0) {
        return 0;
    }
    return row[j];
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

    vector<vector<Position>> backtrack = Create2DPositionArray(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                f[i][j] = GetElement(f, i - 1, j - 1) + 1;
                backtrack[i][j] = Position(i - 1, j - 1);
            }
            else {
                if (GetElement(f, i - 1, j) >= GetElement(f, i, j - 1)) {
                    f[i][j] = GetElement(f, i - 1, j);
                    backtrack[i][j] = Position(i - 1, j);
                }
                else {
                    f[i][j] = GetElement(f, i, j - 1);
                    backtrack[i][j] = Position(i, j - 1);
                }
            }
#ifdef _DEBUG
            printf("[%d, %d] -> [%d, %d]\n", i, j, backtrack[i][j].i, backtrack[i][j].j);
#endif
        }
        //    cout << LongestCommonSubstring("abcdefgxyz", "mmmabcdefgnnnxyzppp") << endl;
        //    cout << LongestCommonSubsequence("1a23b45c6d", "a7bc8d9") << endl;
    }


    string answer;
    Position curr = Position(m - 1, n - 1);
    while (curr.i >= 0 && curr.j >= 0) {
        if (a[curr.i] == b[curr.j]) {
            answer = a[curr.i] + answer;
        }
        curr = backtrack[curr.i][curr.j];
    }

    printf("%d: %s\n", f[m - 1][n - 1], answer.c_str());

    return f[m - 1][n - 1];
}

void foo() {
    cout << "foo";
}

int LongestCommonSubstring(string a, string b) {
    int m = a.length();
    int n = b.length();

    int overallMax = 0;

    vector<vector<int>> f = Create2DArray(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                f[i][j] = GetElement(f, i - 1, j - 1) + 1;
                overallMax = max(f[i][j], overallMax);
            }
            else {
                f[i][j] = 0;
            }
        }
    }
    return overallMax;

}



int LCSNo2DInitialize(string a, string b) {
    int m = a.length();
    int n = b.length();

    vector<vector<int>> f;

    for (int i = 0; i < m; i++) {

        f.push_back(vector<int>());

        for (int j = 0; j < n; j++) {
            int cell;
            if (a[i] == b[j]) {
                cell = GetElement(f, i - 1, j - 1) + 1;
            }
            else {
                if (GetElement(f, i - 1, j) >= GetElement(f, i, j - 1)) {
                    cell = GetElement(f, i - 1, j);
                }
                else {
                    cell = GetElement(f, i, j - 1);
                }
            }
            f[i].push_back(cell);
            printf("add [%d, %d]\n", i, j);
        }
    }

    printf("%d\n", f[m - 1][n - 1]);

    return f[m - 1][n - 1];
}



int StringLength(char* pChar) {
    int length = 0;
    while (*pChar != 0) {
        pChar++;
        length++;
    }
    return length;
}

void TestString() {
    char* str = new char[8];
    memset(str, 0, 8);
    str[0] = 'a';
    *(str + 1) = 'b';
    *(str + 2) = 'c';
    *(str + 3) = '\0';
    printf("%s\n", str);
    cout << StringLength(str);
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

int singleNumber(vector<int>& nums) {
    int a = 0;
    for (auto x : nums) {
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