#include "FSATest.h"
#include "FSA.h"
#define EPSILON ('~')

// Define some macros that puts a dummy value cast as an FSA for certain special operators
#define LEFT_PAR ((FSA*) 1)
#define OR ((FSA*) 2)
/*
	Test implementation for a finite state automata for regex (regular expressions).
	This is conceptually just a graph with linkages between nodes representing possible
	characters to be added and nodes representing "states" of the string.
	
	So, the graph will always have a start and end node.

	FSA special operators:
	| - OR
	* - Repeat >= 0 times
	+ - Repeat > 0 times
	() - parantheses

	Examples:
	ab*c    matches to ac, abc, abbc, abbbc, etc
	(ab)*c  matches to c, abc, ababc, abababc, etc
	(ab)+c  matches to abc, ababc, etc
	(a|b)c  matches to ac, bc
	(a|b)*c matches to c, ac, bc, abc, bac, abbc, abac, ababc, etc 
*/

// Helper function
bool MatchHelper(State* currentState, string s, int index, State* endState) {
	// End condition: if we have made it to the endstate somehow
	if (currentState == endState) {
		// Returns true IF we have exactly consumed all the characters
		return index == s.length();
	}
	/*
		Note about the above check - I initially implemented it as 
		if(index == s.length()){
			return currentState == endState;
		}
		This didn't work for a regex like a|b. The reason is consider the 
		FSA that would be built from a|b - it would look like

		s0 -> (EPSILON)-> a (EPSILON)-> s1
		   -> (EPSILON)-> b (EPSILON)->
		
		When it reaches the second epsilon, index would equal s.length() because
		we have arrived at the end of the string, BUT the state is still on epsilon.
		That causes it to return FALSE simply because we haven't advanced forward the last
		epsilon.

		By switching the order of the statements, we only do this final check once we realize
		that we have arrived at the endState. That ensures that any last "free step" from
		an epsilon will be taken.
	*/

	// Recurses through each transition from currentState
	for (int i = 0; i < currentState->transitions.size(); i++) {
		bool matched = false;
		// Episilon transition - moves forward no matter what
		if (currentState->transitions[i]->condition == EPSILON) {
			// Index is same as before since we aren't moving forward a character in s
			matched = MatchHelper((State*)(currentState->transitions[i]->destination), s, index, endState);
			if (matched) {
				return true;
			}
			continue;
		}
		// Only recurse if the next character in s matches the condition for advancing from currentState
		if (currentState->transitions[i]->condition == s[index]) {
			// recurse with index + 1

			// a future organizational thing to implement is to put currState, endState, and string s
			// into a context object
			matched = MatchHelper((State*) (currentState->transitions[i]->destination), s, index + 1, endState);
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

// Returns an FSA with just one character.
// s0 -> char -> s1
FSA* BuildLiteralFSA(char lit) {
	State* s0 = new State("s0");
	State* s1 = new State("s1");
	s0->addTransition(new Transition(lit, s1));
	return new FSA(s0, s1);
}

void BuildFSAWithinParantheses(stack<FSA*>& FSAstack) {
	FSA* resultingFSA = NULL;
	bool isOrStack = false;
	while(!FSAstack.empty()) {
		FSA* fsa = FSAstack.top();
		FSAstack.pop();

		// if we see a left parantheses, we're at the end of a () so we just put everything in the stack
		if (fsa == LEFT_PAR) {
			FSAstack.push(resultingFSA);
			return;
		}

		// if this is the first item in the stack, just make resultingFSA = fsa
		if (resultingFSA == NULL) {
			resultingFSA = fsa;
			continue;
		}

		// set the OR flag if we see it
		if (fsa == OR) {
			isOrStack = true;
			continue;
		}

		// if we didn't see an OR, we can just append a transition to the end of fsa to the 
		// start of resultingFSA
		if (!isOrStack) {
			fsa->termination->addTransition(new Transition(EPSILON, resultingFSA->start));
			resultingFSA->start = fsa->start;		
		}

		/* if we did see an OR, we need to create a bunch of stuff 
		s0 -> (EPSILON) -> a (EPSILON) -> s1
		   -> (EPSILON) -> b (EPSILON) ->
		*/
		else {
			State* s0 = new State("s0");
			State* s1 = new State("s1");
			s0->addTransition(new Transition(EPSILON, resultingFSA->start));
			s0->addTransition(new Transition(EPSILON, fsa->start));
			resultingFSA->termination->addTransition(new Transition(EPSILON, s1));
			fsa->termination->addTransition(new Transition(EPSILON, s1));
			resultingFSA->start = s0;
			resultingFSA->termination = s1;
		}

	}
}
// this helper function builds the fsa of "ab*c"
FSA* BuildFSA() {
	State* s0 = new State("s0");
	State* s1 = new State("s1");
	State* s2 = new State("s2");
	s0->addTransition(new Transition('a', s1));
	s0->addTransition(new Transition(EPSILON, s1));
	s1->addTransition(new Transition('b', s1));
	s1->addTransition(new Transition('c', s2));
	s0->printState();
	s1->printState();
	s2->printState();

	return new FSA(s0, s2);
}
FSA* BuildFSAFromRegex(string regex) {
	// force the outmost paranetheses to exist
	regex = "(" + regex + ")";
	stack<FSA*> FSAs;
	for (int i = 0; i < regex.size(); i++) {
		char curr = regex[i];

		// Check intrinsic operators first
		switch (curr) {
			case '(':
				FSAs.push(LEFT_PAR);
				break;
			case '|':
				FSAs.push(OR);
				break;
			case ')':
				BuildFSAWithinParantheses(FSAs);
				break;
			default:
				// Now must be literal characters 
				FSAs.push(BuildLiteralFSA(curr));
		}
	}
	return FSAs.top();
}
void testFSA() {
	/*
	FSA* f = BuildFSA();
	printf("ab: %d\n", Match(f, "ab"));
	printf("abc: %d\n", Match(f, "abc"));
	printf("abbc: %d\n", Match(f, "abbc"));
	printf("bc: %d\n", Match(f, "bc"));
	printf("ac: %d\n", Match(f, "ac"));

	FSA* abcd = BuildFSAFromRegex("abcd");
	printf("abcd: %d\n", Match(abcd, "abcd"));
	*/
	FSA* aorborcord = BuildFSAFromRegex("a|b|c|d");
	printf("a: %d\n", Match(aorborcord, "a"));
	printf("c: %d\n", Match(aorborcord, "c"));


}