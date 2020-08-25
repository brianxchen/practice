#pragma once
#include "..\Common.h"

class EightQueens {
public:
	bool done;
	vector<tuple<int, int>> solution;
	vector<bool> colOccupied;
	vector<bool> diagAOccupied;
	vector<bool> diagBOccupied;
	EightQueens() {
		for (int i = 0; i < 8; i++) {
			this->colOccupied.push_back(false);
		}
		for (int i = 0; i < 15; i++) {
			this->diagAOccupied.push_back(false);
			this->diagBOccupied.push_back(false);
		}
		done = false;
	}
	
	bool isValid(int col, int row) {
		return !colOccupied[col] && !diagAOccupied[col - row + 7] && !diagBOccupied[col + row];
	}

	void PlaceQueenOnRow(int row){
		if (row == 8) {
			for (auto coordinate : solution) {
				printf("[%d, %d]\n", get<0>(coordinate), get<1>(coordinate));
			}
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (get<1>(solution[i]) == j) {
						cout << "*";
					}
					else {
						cout << ".";
					}
				}
				cout << "\n";
			}
			done = true;
			return;
		}
		for (int col = 0; col < 8; col++) {
			if (isValid(col, row)) {
				colOccupied[col] = true;
				diagAOccupied[col - row + 7] = true;
				diagBOccupied[col + row] = true;
				solution.push_back(tuple<int, int>(row, col));
				PlaceQueenOnRow(row + 1);
				if (done) {
					return;
				}
				colOccupied[col] = false;
				diagAOccupied[col - row + 7] = false;
				diagBOccupied[col + row] = false;
				solution.pop_back();
			}
		}
	}

	void Solve() {
		PlaceQueenOnRow(0);
	}
};

void TestEightQueens() {
	EightQueens solver;
	solver.Solve();
}