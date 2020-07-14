#include "Common.h"

bool DecreasingCompare(int a, int b) {
	return b < a;
}

void TestVector() {


	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

	v.pop_back();
	v.push_back(11);
	cout << v[0];
	cout << "\nlength = " << v.size();
	vector<int>::iterator it;
	it = v.begin();
	advance(it, 2);

	v.insert(it, 123);
	cout << "\n";
	for (auto x : v)
		cout << x << " ";

	sort(v.begin(), v.end(), DecreasingCompare);

	cout << "Sorted \n";
	for (auto x : v)
		cout << x << " ";
}

void PrintMatrix(vector < vector<int>> a) {
	int m = a.size();
	int p = a[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

void MatrixMultiplication() {
	vector<vector<int> > a{ { 1, 2, 3 },
							  { 4, 5, 6 } };
	vector<vector<int> > b{ { 1, 2, 3, 4},
							  { 5, 6, 7, 8},
							  { 9, 10, 11, 12 } };

	// matrix a is m by n
	// matrix b is n by p
	int m = a.size();
	int n = a[0].size();
	int p = b[0].size();

	// check if multiplication is possible
	if (b.size() != n) {
		return;
	}


	vector<vector<int>> c; // initialize output array
	for (int i = 0; i < m; i++) { // loop through outer array
		vector<int> row; 
		for (int j = 0; j < p; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum += a[i][k] * b[k][j];
			}
			row.push_back(sum); // push the current sum onto the row
		}
		c.push_back(row); // add the fully created row onto c
	}

	PrintMatrix(c);

}