#include "..\Common.h"

/*
	Implementation of the KMP algorithim for finding a target substring within a larger string.
	This version returns once it's found the first occurence of this (but can easily be modified
	to return a list of matches).

	The broad idea is when searching through the text, we don't want to compare sections
	of the text and pattern that we "know" will match. This "know" part is just if we see
	a subsection of text that we know will match because it's repeated from some other part
	of pattern.

	This means that we can do some pre-processing of the pattern string 
	before searching through the text.

	The preprocessing will look through *pattern* (NOT text) looking for the longest section
	of string that matches the "prefix" string from the beginning. For example, for the string
	a b c x x x a b c (spacing is just for readability)
	corresponds with a prefix array of
	0 0 0 0 0 0 1 2 3
	-- Area of confusion here was where are we starting the comparison of 
	prefixArray[i] and prefixArray[prefixLength]? We always start the comparison from pattern[0]
	because we are trying to find where we'd shift the target forward in case of a mismatch.

	The next step is the comparison. This is relatively straightforward: we will compare
	text with pattern, and if we see a mismatch we check the prefixArray to find how far we
	can skip to to resume the comparison.

	For example, if we are searching the text
	zzzzabcxxxabyzzzzabcxxxabc
	when we get to ...abcxxxab and we see a mismatch with the following character (y), we will look
	at the prefixArray value of the index of the mismatch (in this case, it's 3). 
	We now resume the comparison, but instead of just shifting the index of what we're comparing by 1,
	we shift it by prefixArray[mismatchIndex]. This is the key improvement of the algorithm.


	Explanations:
	https://youtu.be/EL4ZbRF587g
	https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*/

/*
	This is the helper method that returns a prefixArray that stores the value of
	the longest prefix that ends at [index].
	It returns an int array (in C++ this is an int pointer)
*/
int* calcPrefixLength(string pattern) {
	int patternLength = pattern.length();
	int* prefixArray = new int[patternLength + 1];

	prefixArray[0] = -1; // we push everything forward by 1
	prefixArray[1] = 0; // because a *proper* substring cannot just be itself

	int prefixLength = 0;
	int i = 1;

	while (i < patternLength) {
		/* If pattern[i] = pattern[prefixLength], we upate both values 
		   and continue counting up the value of prefixLength.
		   We will keep doing this until it is no longer a prefix
		   when compared with the beginning of pattern.
		   */
		if (pattern[i] == pattern[prefixLength]) {
			prefixLength++;
			i++;
			prefixArray[i] = prefixLength;
		}
		// the following section is still a mystery to me I literally have
		// zero idea why its necessary :(
		else if (prefixLength > 0) {
			prefixLength = prefixArray[prefixLength];
		}
		// otherwise, we continue checking at i+1 then reset prefixArray[i] = 0
		else {
			i++;
			prefixArray[i] = 0;
		}
	}

	for (int i = 0; i < patternLength; i++) {
		printf("%d %c %d\n", i+1, pattern[i], prefixArray[i]);
	}
	return prefixArray;
}

/*
	Actual algorithm
*/
int KMP(string pattern, string text) {
	int patternIndex = 0;
	int textIndex = 0;

	int patternLength = pattern.length();
	int textLength = text.length();

	int* prefixLengths = calcPrefixLength(pattern);

	while (textIndex < textLength) {
		if (pattern[patternIndex] == text[textIndex]) {
			patternIndex++;
			textIndex++;

			// end condition
			if (patternIndex == patternLength) {
				return textIndex - patternIndex;
			}
		}
		// KMP trick - shift forward by prefixLength at the 
		// location that we stopped at.
		else {
			patternIndex = prefixLengths[patternIndex];
			if (patternIndex < 0) {
				patternIndex++;
				textIndex++;
			}
		}
	}

	return -1;
}

void testKMP() {
	printf("%d\n", KMP("ababababc", "mmmababababababmmmmmmmababababc"));
}