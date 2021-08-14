#pragma once
#include "Minimax.h"

class MinimaxNode {
public:
	vector<int> state;
	int score;
	int decision;
	MinimaxNode(vector<int> state);
};