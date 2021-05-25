#include "FSATest.h"
#include "FSA.h"
/*
	Test implementation for a finite state automata for regex (regular expressions).
	This is conceptually just a graph with linkages between nodes representing possible
	characters to be added and nodes representing "states" of the string.
	
	So, the graph will always have a start and end node.
*/

// Helper function
bool MatchHelper(State* currentState, string s, int index, State* endState) {
	// End condition: if we are checking the last character of s
	if (index == s.length()) {
		// Returns true IF we have arrived at the last state of the FSA;
		// if not, returns false
		return currentState == endState;
	}

	// Recurses through each transition from currentState
	for (int i = 0; i < currentState->transitions.size(); i++) {
		// Only recurse if the next character in s matches the condition for advancing from currentState
		if (currentState->transitions[i]->condition == s[index]) {
			// recurse with index + 1

			// a future organizational thing to implement is to put currState, endState, and string s
			// into a context object
			bool matched = MatchHelper((State*) (currentState->transitions[i]->destination), s, index + 1, endState);
			if (matched) {
				return true;
			}
		}
	}
	return false;
}

// Driver function
bool Match(FSA* fsa, string s) {
	return MatchHelper(fsa->start, s, 0, fsa->termination);
}
// this helper function builds the fsa of "ab*c"
FSA* BuildFSA() {
	State* s0 = new State("s0");
	State* s1 = new State("s1");
	State* s2 = new State("s2");
	s0->addTransition(new Transition('a', s1));
	s1->addTransition(new Transition('b', s1));
	s1->addTransition(new Transition('c', s2));
	s0->printState();
	s1->printState();
	s2->printState();

	return new FSA(s0, s2);
}
void testFSA() {
	FSA* f = BuildFSA();
	printf("ab: %d\n", Match(f, "ab"));
	printf("abc: %d\n", Match(f, "abc"));
	printf("abbc: %d\n", Match(f, "abbc"));
	printf("ac: %d\n", Match(f, "ac"));

}