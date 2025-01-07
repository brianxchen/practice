import random

class wordle:
    def __init__(self):
        with open("words.txt") as f:
            words = f.read().splitlines()
            word = random.choice(words)
        words_set = set(words)
        self.words = words
        self.words_set = words_set

        self.max_guesses = 15

        print(word)
        # word is the correct answer
        self.word = word
        self.guesses_used = 0
        self.possible_words = words_set

    def parse_guess(self, guess):
        if len(guess) != len(self.word):
            return "Invalid length"
        if guess not in self.words_set:
            return "Invalid guess (not a word)"
        output_code = []
        for i in range(len(guess)):
            if guess[i] == self.word[i]:
                output_code.append(0)
            elif guess[i] in self.word:
                output_code.append(1)
            else:
                output_code.append(2)
        self.guesses_used += 1
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
            output = self.parse_guess(guess.lower())
            print(output)
            if guess.lower() == self.word:
                print("You win!")
                return
        print("You lose. The word was: " + self.word)
        
    def solve(self):
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

            # print(f"Number of possible words: {len(self.possible_words)}")
            # Choose next guess randomly out of the set of possible words
            guess = random.choice(list(self.possible_words))

w = wordle()
w.solve()

