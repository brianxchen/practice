#pragma once
#include "..\Common.h"
#include "MazeCell.h"

vector<int> dx = { 1, 2, 2, 1, -1, -2, -2, -1 };
vector<int> dy = { 2, 1, -1, -2, -2, -1, 1, 2 };

class KnightTour {
public:
	int startX;
	int startY;
	int endX;
	int endY;
	bool done;
	vector<tuple<int, int>> path;
	vector<vector<MazeCell>> cells;
	KnightTour(vector<vector<MazeCell>> cells, int startX, int startY) {
		this->cells = cells;
		this->startX = startX;
		this->startY = startY;
		this->done = false;
	}
	void Move(int currX, int currY) {
		cells[currY][currX].Visited = true;
		//printf("At %d, %d\n", currX, currY);
		path.push_back(tuple<int, int>(currX, currY));
		if (path.size() == 64) {
			cout << "done" << endl;
			for (auto position : path) {
				printf("[%d, %d]\n", get<0>(position), get<1>(position));
			}
			done = true;
			return;
		}


		for (int i = 0; i < 8; i++) {
			int newX = currX + dx[i];
			int newY = currY + dy[i];
			if (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7 && !cells[newY][newX].Visited) {
				Move(newX, newY);
				if (done) {
					return;
				}
			}
		}
		path.pop_back();
		cells[currY][currX].Visited = false;
	}
	void Solve() {
		Move(startX, startY);
	}
};

void TestKnightTour() {
	KnightTour m({
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
		}
	, 0, 0);
	m.Solve();

}