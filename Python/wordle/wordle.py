import random
from collections import defaultdict
from tqdm import tqdm
import matplotlib.pyplot as plt
class wordle:
    def __init__(self):
        with open("words.txt") as f:
            words = f.read().splitlines()
            word = random.choice(words)
        words_set = set(words)
        self.words = words
        self.words_set = words_set

        self.max_guesses = 15

        # print(word)
        # word is the correct answer
        self.word = word
        self.guesses_used = 0
        self.possible_words = words_set

    def parse_guess(self, guess, words_set, word=None):
        w = word or self.word
        if len(guess) != len(w):
            return "Invalid length"
        if guess not in words_set:
            return "Invalid guess (not a word)"
        output_code = []
        for i in range(len(guess)):
            if guess[i] == w[i]:
                output_code.append(0)
            elif guess[i] in w:
                output_code.append(1)
            else:
                output_code.append(2)
        # self.guesses_used += 1
        return output_code

    def code_to_labelled_word(self, code, word):
        """
        Given the wordle "labels", output the formatted response

        code: list of 0, 1, 2s. 
        0: letter is in the word, correct position
        1: letter is in the word, incorrect position
        2: letter is not in the word
        """
        output = ""
        for i in range(len(code)):
            char = word[i]
            if code[i] == 0:
                output = output + ' [' + char + ']'
            elif code[i] == 1:
                output = output + ' (' + char + ')'
            else:
                output = output + ' <' + char + '>'
        return output

    def play(self):
        self.guesses_used = 0
        print("Enter a guess: ")
        while self.guesses_used < self.max_guesses:
            guess = input("")
            output = self.parse_guess(guess.lower(), self.words_set)
            print(output)
            if guess.lower() == self.word:
                print("You win!")
                return
        print("You lose. The word was: " + self.word)
        
    def solve_naive(self):
        """
        Solve naively.
        """
        guess = "crane"
        while(self.guesses_used < self.max_guesses):
            print(f"Guess {self.guesses_used + 1}: {guess}")
            if guess == self.word:
                print(f"Solved in {self.guesses_used + 1} guesses")
                return

            outcome = self.parse_guess(guess)
            print(self.code_to_labelled_word(outcome, guess))
            new_possible_words = set()
            for word in self.possible_words:
                if word == guess:
                    continue
                is_valid = True
                for i, color in enumerate(outcome):
                    if color == 0 and word[i] != guess[i]:
                        is_valid = False
                        break
                    elif color == 1 and guess[i] not in word:
                        is_valid = False
                        break

                if is_valid:
                    new_possible_words.add(word)
            self.possible_words = new_possible_words

            # Choose next guess randomly out of the set of possible words
            possible_outcomes = defaultdict()
            word_outcomes = defaultdict()
            for word in self.words_set:
                # For each possible next guess, calculate all possible outcomes
                for possible_word in self.possible_words:
                    outcome = self.parse_guess(possible_word, word)
                    if outcome not in possible_outcomes:
                        possible_outcomes[outcome] = 1
                    else:
                        possible_outcomes[outcome] += 1
                
                # Now check how many of the remaining words fit for each guess
                for possible_word in self.possible_words:
                    if outcome not in word_outcomes:
                        word_outcomes[outcome] = 1
                    else:
                        word_outcomes[outcome] += 1

            guess = random.choice(list(self.possible_words))

    def solve(self, verbose=True):
        """
        Solve using information gain.
        """

        # Starting guess can be changed
        guess = "crane"
        words_set_temp = set(w for w in self.words_set)
        possible_words_temp = words_set_temp
        while self.guesses_used < self.max_guesses:
            if verbose:
                print(f"Guess {self.guesses_used + 1}: {guess}")
            # print(f"Best next guess: {best_guess}")
            outcome = self.parse_guess(guess, words_set_temp)
            if verbose:
                print(self.code_to_labelled_word(outcome, guess))
            if guess == self.word:
                if verbose:
                    print(f"Solved in {self.guesses_used + 1} guesses")
                return
            
            new_possible_words = set()
            for word in possible_words_temp:
                is_valid = True
                for i, color in enumerate(outcome):
                    if color == 0 and word[i] != guess[i]:
                        is_valid = False
                        break
                    elif color == 1 and guess[i] not in word:
                        is_valid = False
                        break
                    elif color == 2 and guess[i] in word:
                        is_valid = False
                        break
                if is_valid and word != guess:
                    new_possible_words.add(word)

            possible_words_temp = new_possible_words
            self.guesses_used += 1

            # don't guess the same answer twice
            words_set_temp.remove(guess)

            if verbose:
                print(f"Number of possible words: {len(self.possible_words)}")

            # Simulate feedback for all possible remaining words
            possible_outcomes = defaultdict(int)
            for word in possible_words_temp:
                outcome = tuple(self.parse_guess(word, words_set_temp)) # Save outcome as tuple to use as key
                # print(f"DEBUG {outcome}")
                possible_outcomes[outcome] += 1  # Count occurrences of each outcome

            best_guess = None
            best_outcome_division = float('inf')

            for word in possible_words_temp: # tqdm(possible_words_temp):
                # for each word in the dictionary, calculate the possible outcomes
                outcome_distribution = defaultdict(int)

                for possible_word in possible_words_temp:
                    outcome = tuple(self.parse_guess(word, possible_word))  # Simulate outcome
                    # print(f"outcome for {word} given {possible_word}: {outcome}")
                    outcome_distribution[outcome] += 1
                # print(f"outcome_distribution for {word} ={outcome_distribution}")
                outcome_division = len(outcome_distribution)

                # the ideal guess minimizes the size of the outcome distribution
                if outcome_division < best_outcome_division:
                    best_outcome_division = outcome_division
                    best_guess = word

            # print(f"guesses used: {self.guesses_used}")
            guess = best_guess

            """
            if len(self.possible_words) < 10:
                print(f"Words left: {list(self.possible_words)}")
            """

    def test(self):
        """
        Test average solve length for all words
        """
        total = 0
        guesses = []
        num_tests = len(self.words)
        for word in tqdm(self.words[:num_tests]):
            self.word = word
            self.guesses_used = 0
            self.words_set = self.words_set
            self.possible_words = self.words_set
            self.solve(verbose=False)
            total += self.guesses_used
            guesses.append(self.guesses_used)
        print(f"Average guesses: {total/num_tests}")
        plt.hist(guesses, bins=range(min(guesses), max(guesses)))
        plt.show()

w = wordle()
w.test()

