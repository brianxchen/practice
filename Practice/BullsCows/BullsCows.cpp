#include "../Common.h"
#include "BullsCows.h"
/*
	Implementation for the "bulls and cows" game
	https://en.wikipedia.org/wiki/Bulls_and_Cows

	plus a computer that can solve it in an average	of 8 guesses.

	Rules: 4-digit number ("target") is chosen. 
	The player guesses a 4 digit number and is given 2 numbers
	in return - the "bulls" and "cows". Bulls are digits that are
	in the correct location and have the correct value. Cows are 
	any remaining digits that are in the incorrect location but 
	do match one of the remaining digits' values.

	A digit cannot count as both a cow and a bull. For example,
	if the target was 3555 and the guess was 3333, there is one bull 
	and zero cows.
*/

// Returns a preprocessed array that counts how many of each digit
// are in a given int. 
vector<int> CountDigits(int x) {
	vector<int> output (10, 0);
	for (int i = 0; i < 4; i++) {
		int d = x % 10;
		output[d] = output[d] + 1;
		x /= 10;
	}
	return output;
}

// Calculates the number of bulls and cows given a target and guess.
// Puts the result in a tuple for returning
tuple<int, int> CalculateBullsCows(int target, int guess) {
	// Preprocess target and guess
	vector<int> targetCount = CountDigits(target);
	vector<int> guessCount = CountDigits(guess);
	int bulls = 0;
	int cows = 0;
	
	// Cow count is the min of targetCount and guessCount
	for (int i = 0; i < 10; i++) {
		cows += min(targetCount[i], guessCount[i]);
	}

	// Checking bulls is easy
	for (int i = 0; i < 4; i++) {
		int targetDigit = target % 10;
		int guessDigit = guess % 10;
		if (targetDigit == guessDigit) {
			bulls += 1;
		}
		target /= 10;
		guess /= 10;
	}
	
	// Digit can't be both a cow and a bull, and 
	// all bulls are cows, so subtract bulls from cows
	cows -= bulls;
	tuple<int, int> output{ cows, bulls };
	return output;
}

// This returns us the first 
int findFirstCandidate(vector<bool> candidates) {
	for (int i = 0; i < 10000; i++) {
		if (candidates[i]) {
			return i;
		}
	}
}
/*
	The idea with the solver is that we will have a bool array of size 10,000,
	with each possible guess from 0-9999 having a location.
	We will systematically eliminate candidates for our next guess by setting 
	the corresponding location to "false".
	
	We will first guess 0000. After getting a bull/cow count, we will compare the 
	bull/cow count between our guess and every remaining "true" value of the array
	with the bull/cow count that we were returned from our actual guess.
	
	If the two are equal, then we do not set that location to false because it could
	potentially be the target. 

	If the two are not equal, the value of the candidate array we are at definitely cannot
	be the target. Thus, we can set that to "false".

	After going through the entire candidate array, we will do the loop again with the next 
	"true" value in the candidate array. We will do this until we get 4 bulls (aka a match),
	which will be the target.	
*/
int solveBullsCows(int target) {
	int guessCount = 0;
	vector<bool> candidates(10000, true);
	while (true) {
		int guess = findFirstCandidate(candidates);
		tuple<int, int> output = CalculateBullsCows(target, guess);
		int cows = get<0>(output);
		int bulls = get<1>(output);
		guessCount++;
		//printf("%d: Target = %d, guess = %d, cows = %d, bulls = %d\n", guessCount, target, guess, cows, bulls);
		if (bulls == 4) {
			return guessCount;
		}
		// Now start eliminating candidates that cannot be target
		for (int i = 0; i < 10000; i++) {
			if (!candidates[i]) {
				continue;
			}
			tuple<int, int> temp = CalculateBullsCows(guess, i);
			int tempCows = get<0>(temp);
			int tempBulls = get<1>(temp);
			if (!(tempCows == cows && tempBulls == bulls)) {
				candidates[i] = false;
			}
		}
	}
	return guessCount;
}
void testBullsCows() {
	CalculateBullsCows(1234, 1234);
	CalculateBullsCows(3555, 3333);
	CalculateBullsCows(3355, 5533);
	CalculateBullsCows(0, 123);
	int globalCount = 0;
	for (int target = 0; target < 10000; target++) {
		int count = solveBullsCows(target);
		printf("target = %d, count = %d\n", target, count);
		globalCount += count;
	}
	globalCount /= 10000;
	printf("Global average = %d\n", globalCount);
	
	// solveBullsCows(3562);
}