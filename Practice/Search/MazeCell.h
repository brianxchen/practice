#pragma once
#include "..\Common.h"

class MazeCell {
	public:
		bool isWall;
		bool Visited;
		MazeCell(bool isWall) {
			this->isWall = isWall;
			this->Visited = false;
		}
};