#pragma once
#include "..\Common.h"
#include "MazeCell.h"

vector<int> dx = { 0, 1, 0, -1 };
vector<int> dy = { 1, 0, -1, 0 };

class Maze{
	public:
		int startX;
		int startY;
		int endX;
		int endY;
		bool done;
		vector<tuple<int, int>> path;
		vector<vector<MazeCell>> cells;
		Maze(vector<vector<MazeCell>> cells, int startX, int startY, int endX, int endY) {
			this->cells = cells;
			this->startX = startX;
			this->startY = startY;
			this->endX = endX;
			this->endY = endY;
			this->done = false;
		}
		void Move(int currX, int currY) {
			cells[currY][currX].Visited = true;
			printf("At %d, %d\n", currX, currY);
			path.push_back(tuple<int, int>(currX, currY));
			if (currX == endX && currY == endY) {
				cout << "found" << endl;
				for(auto position : path) {
					printf("[%d, %d]\n", get<0>(position), get<1>(position));
				}
				done = true;
				return;
			}


			for (int i = 0; i < 4; i++) {
				int newX = currX + dx[i];
				int newY = currY + dy[i];
				if (newX >= 0 && newX <= 4 && newY >= 0 && newY <= 4 && !cells[newY][newX].isWall && !cells[newY][newX].Visited) {
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

void TestMaze() {
	Maze m({
				 {MazeCell(1), MazeCell(1), MazeCell(1), MazeCell(1), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(1), MazeCell(1), MazeCell(0) },
				 {MazeCell(1), MazeCell(0), MazeCell(1), MazeCell(1), MazeCell(0) },
				 {MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) },
				 {MazeCell(1), MazeCell(0), MazeCell(0), MazeCell(0), MazeCell(0) }
		}
		, 0, 1, 4, 0);
	m.Solve();

}