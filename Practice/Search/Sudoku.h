#pragma once
#include "../Common.h"

int board[9][9] = { 
	{5, 3, 0, 0, 7, 0, 0, 0, 0},
	{6, 0, 0, 1, 9, 5, 0, 0, 0},
	{0, 9, 8, 0, 0, 0, 0, 6, 0},
	{8, 0, 0, 0, 6, 0, 0, 0, 3},
	{4, 0, 0, 8, 0, 3, 0, 0, 1},
	{7, 0, 0, 0, 2, 0, 0, 0, 6},
	{0, 6, 0, 0, 0, 0, 2, 8, 0},
	{0, 0, 0, 4, 1, 9, 0, 0, 5},
	{0, 0, 0, 0, 8, 0, 0, 7, 9}
};

bool rows[9][10] = { false };
bool cols[9][10] = { false };
bool boxes[3][3][10] = { false };



void PrintSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
	cout << "\n\n";
}

bool isValid(int row, int col, int i) {
	if (rows[row][i] == true) {
		return false;
	}
	if (cols[col][i] == true) {
		return false;
	}
	if (boxes[row / 3][col / 3][i] == true) {
		return false;
	}
	return true;
}

void PlaceNumber(int cellID) {
	if (cellID < 4) {
		PrintSudoku();
	}
	if(cellID == 81){
		PrintSudoku();
		return;
	}
	int row = cellID / 9;
	int col = cellID % 9;
	if (board[row][col] != 0) {
		PlaceNumber(cellID + 1);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (isValid(row, col, i)) {
			rows[row][i] = true;
			cols[col][i] = true;
			boxes[row / 3][col / 3][i] = true;
			board[row][col] = i;
			PlaceNumber(cellID + 1);
			board[row][col] = 0;
			rows[row][i] = false;
			cols[col][i] = false;
			boxes[row / 3][col / 3][i] = false;
		}
	}
}

void SudokuSolver() {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			int value = board[row][col];
			if (value != 0) {
				rows[row][value] = true;
				cols[col][value] = true;
				boxes[row / 3][col / 3][value] = true;
			}
		}
	}
	PlaceNumber(0);
}