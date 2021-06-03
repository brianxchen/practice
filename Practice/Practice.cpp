#include <iostream>
//#include "Leetcode\Leetcode.h"
#include "Common.h"
#include "Context.h"
#include "Search/EightQueens.h"
#include "Search/Sudoku.h"
#include "Combinatorics/CandyBag.h"
#include "Search/BoatProblem.h"
#include "Solve24/Solve24.h"
#include "Graph/TopologicalSort.h"
#include "Graph/TravelSalesmanSolver.h"
#include "Dijkstra/Heap.h"
#include "Dijkstra/DijkstraSolver.h"
#include "MST/MSTSolver.h"
#include "StringMatching/KMP.h"
#include "FSA/FSATest.h"
#include "Rectangles/RectangleSolver.h"
//#include "Combinatorics/FencePainting.h"
/*#include "Knapsack/Knapsack.h"
#include "MapMemorizer.h"
*/

int tempGetElement(vector<vector<int>> f, int i, int j) {
    if (i < 0 || j < 0) {
        return INT32_MAX;
    }
    return f[i][j];

}

int EditDistance(string a, string b) {
    int m = a.length();
    int n = b.length();

    vector<vector<int>> f;

    for (int i = 0; i <= m; i++) {
        f.push_back(vector<int>());
        for (int j = 0; j <= n; j++) {
            int cell;
            if (i == 0) {
                cell = j;
            }
            else if (j == 0) {
                cell = i;
            }
            else if (a[i-1] == b[j-1]) {
                cell = f[i - 1][j - 1];
            }
            else {
                int temp = min(f[i - 1][j], f[i][j - 1]);
                cell = min(temp, f[i-1][j-1]) + 1;
            }
            f[i].push_back(cell);
        }
    }
    return f[m][n];
}

int RecursiveLCSubstringHelper(int i, int j, Context& context) {

    string key = to_string(i) + "," + to_string(j);
    int savedValue = context.memorizer->Get(key);

    if (savedValue != -1) {
        return savedValue;
    }

    if (i < 0 || j < 0) {
        return 0;
    }

    int temp = RecursiveLCSubstringHelper(i - 1, j - 1, context);
    RecursiveLCSubstringHelper(i, j - 1, context);
    RecursiveLCSubstringHelper(i - 1, j, context);

    int ret = 0;

    if (context.a[i] == context.b[j]) {
        ret = temp + 1;
    }

    context.overallMax = max(context.overallMax, ret);

    printf("i = %d, j = %d, ret = %d, overallMax = %d\n", i, j, ret, context.overallMax);

    context.memorizer->Set(key, ret);
    return ret;
}

void RecursiveLCSubstring(string a, string b) {
    Context context(a, b);
    RecursiveLCSubstringHelper(a.length() - 1, b.length() - 1, context);
    cout << context.overallMax;
}

int main(int argc, char* argv[])
{
    vector<int> nums { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    //primitives(); 
    //Test();
    //TestKnapsack();

    //RecursiveLCSubstring("abc", "ab");
    //RecursiveLCSubstring("abcdefgxyz", "mmmbcdefgnnnxyzppp");
    
    //testMSTSolver();
    //testFSA();
    //TestEightQueens();
    SolveRectangles();
}
