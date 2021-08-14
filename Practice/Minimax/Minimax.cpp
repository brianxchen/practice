#include "Minimax.h"
#include "MinimaxNode.h"
/*
	Minimax algorithm for playing tic tac toe.

	The algorithm will recursively traverse the entire tree of
	possible tic tac toe boards. It will assign "scores" to each
	depending on whether it would lead to a human win, computer win,
	or draw. It will then make a decision based on which next move
	would maximize the score.
*/

// Putting the calculated states in a map will allow us to
// look up any random board quickly to find the best move.
map<vector<int>, MinimaxNode*> m;

void printNode(MinimaxNode* node) {
	printf("%d%d%d\n", node->state[0], node->state[1], node->state[2]);
	printf("%d%d%d\n", node->state[3], node->state[4], node->state[5]);
	printf("%d%d%d\n", node->state[6], node->state[7], node->state[8]);
	printf("Score = %d, decision = %d\n\n", node->score, node->decision);
}
void printBoard(vector<int> state) {
	printf("%d%d%d\n", state[0], state[1], state[2]);
	printf("%d%d%d\n", state[3], state[4], state[5]);
	printf("%d%d%d\n", state[6], state[7], state[8]);
}

// This is an ugly function that checks whether a board has a win or not.
// Obviously this could be cleaned up/made more efficient but it's not really 
// important in terms of learning the basics of minimax, so whatever
int calculateScore(vector<int>& state) {
	if (state[0] == 1 && state[1] == 1 && state[2] == 1 ||
		state[3] == 1 && state[4] == 1 && state[5] == 1 ||
		state[6] == 1 && state[7] == 1 && state[8] == 1 ||
		state[0] == 1 && state[3] == 1 && state[6] == 1 ||
		state[1] == 1 && state[4] == 1 && state[7] == 1 ||
		state[2] == 1 && state[5] == 1 && state[8] == 1 ||
		state[0] == 1 && state[4] == 1 && state[8] == 1 ||
		state[2] == 1 && state[4] == 1 && state[6] == 1 ){
		return 1;
	}
	if (state[0] == 2 && state[1] == 2 && state[2] == 2 ||
		state[3] == 2 && state[4] == 2 && state[5] == 2 ||
		state[6] == 2 && state[7] == 2 && state[8] == 2 ||
		state[0] == 2 && state[3] == 2 && state[6] == 2 ||
		state[1] == 2 && state[4] == 2 && state[7] == 2 ||
		state[2] == 2 && state[5] == 2 && state[8] == 2 ||
		state[0] == 2 && state[4] == 2 && state[8] == 2 ||
		state[2] == 2 && state[4] == 2 && state[6] == 2) {
		return -1;
	}
	
	return 0;
}

// Recursion helper to fill out the decision tree
void makeTreeHelper(MinimaxNode* node) {
	// check the map to see if we've already processed this state
	if (m.find(node->state) != m.end()) {
		return;
	}

	int score = calculateScore(node->state);

	if (score != 0) {
		// game over, either win or lose
		node->score = score;
		node->decision = -2; // just a debugging thing, doesn't matter what we put in here
		return;
	}
	
	// if computer's move - the "max" part of minimax
	if (node->state[9] == 1) {
		int maxScore = -100;
		int bestMove = -1;
		// Loop through all possible move locations
		for (int i = 0; i < 9; i++) {
			// skip if not empty
			if (node->state[i] != 0) {
				continue;
			}
			vector<int> childState = node->state;
			// mark this square
			childState[i] = 1;
			// toggle move
			childState[9] = 3 - node->state[9];
			// recurse
			MinimaxNode* childNode = new MinimaxNode(childState);
			makeTreeHelper(childNode);
			// update max score if applicable
			if (childNode->score > maxScore) {
				maxScore = childNode->score;
				bestMove = i;
			}
		}
		// update actual node values
		node->score = maxScore;
		node->decision = bestMove;
	}

	// the "mini" part of minimax - do the same thing for the other side except
	// calculate the minimum so it knows what to avoid
	else {
		int minScore = 100;
		int bestMove = -1;
		for (int i = 0; i < 9; i++) {
			if (node->state[i] != 0) {
				// if not empty
				continue;
			}
			vector<int> childState = node->state;
			childState[i] = 2;
			childState[9] = 3 - node->state[9];
			MinimaxNode* childNode = new MinimaxNode(childState);
			makeTreeHelper(childNode);

			if (childNode->score < minScore) {
				minScore = childNode->score;
				bestMove = i;
			}
		}
		node->score = minScore;
		node->decision = bestMove;
	}

	// remember to update the map!
	m[node->state] = node;
	// printNode(node);
}

// recursion driver
MinimaxNode* makeTree() {
	// state 0-8 define the board. 0 = empty, 1 = computer occupied, 2 = human occupied
	vector<int> rootState(10, 0);

	// state 9 says whose move it is. 1 = computer, 2 = human
	rootState[9] = 1;

	MinimaxNode* root = new MinimaxNode(rootState);
	makeTreeHelper(root);
	printNode(root);
	return root;
}

// checks if game is over - either all squares filled or someone won
bool isDone(vector<int> board) {
	int score = calculateScore(board);
	if (score != 0) {
		return true;
	}
	for (int i = 0; i < 9; i++) {
		if (board[i] == 0) {
			return false;
		}
	}
	return true;
}

// driver
void playTTT(MinimaxNode* root) {
	vector<int> board(10, 0);
	board[9] = 1;
	while (true) {
		MinimaxNode* node = m[board];
		board[node->decision] = 1;
		printBoard(board);
		if (isDone(board)) {
			break;
		}
		cout << "Make your move: ";
		int move;
		cin >> move;
		board[move] = 2;
		printBoard(board);
		printf("\n");
		if (isDone(board)) {
			break;
		}
	}
}
void testMinimax() {
	MinimaxNode* root = makeTree();
	playTTT(root);
}