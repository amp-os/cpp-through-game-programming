// Hangman

/*
Create group of words

Select word at random


While the user hasn't guessed the word
and hasn't used too many incorrect letter guesses:
Loop:
	Show the user the state of the word
	Say how many incorrect guesses are left
	Show the letters that have been guessed
	Get the user's guess
		Check if the letter has already been guessed
		If so, loop
	Add letter to group of used letters
	Check if letter is part of word
	If yes:
		Tell player it is correct
		Update state of the word
	If no:
		Tell player it is incorrect
		Increment number of incorrect guesses
Too many guesses:
	You lose
Correct word:
	You win
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <cctype>

char getLetter(std::string& usedLetters)
{
	char guess;
		do
		{
			std::cout << "Guess a letter: ";
			std::cin >> guess;
			guess = std::toupper(guess);
			
			if (usedLetters.find(guess) != std::string::npos)
				std::cout << "\nYou've already guessed that letter, try again.\n";
		} while (usedLetters.find(guess) != std::string::npos);
	return guess;
}

bool checkForLetter(char guess, const std::string& TARGET_WORD, std::string& guessState)
{
	bool retVal;
	if (TARGET_WORD.find(guess) != std::string::npos)
	{
		std::cout << "\nYou got one! " << guess << " is in the word.\n";
		retVal = true;
		for (int i = 0; i < TARGET_WORD.length(); i++)
		{
			if (TARGET_WORD[i] == guess)
			{
				guessState[i] = guess;
			}
		}
	}
	else
	{
		std::cout << "\nWRONG! No " << guess << "s in here!\n";
		retVal = false;
	}
	return retVal;
}

int main()
{
	// Setup
	const int MAX_WRONG = 8;
	
	std::vector<std::string> wordPool;
	wordPool.push_back("GUESS");
	wordPool.push_back("HANGMAN");
	wordPool.push_back("DIFFICULT");
	wordPool.push_back("RACECAR");
	wordPool.push_back("ONYX");
	
	// Select a word
	std::random_device rd;
	std::mt19937 g(rd());
	shuffle(wordPool.begin(), wordPool.end(), g);
	const std::string TARGET_WORD = wordPool[0];
	
	// Game tracking variables
	int wrongGuesses = 0;
	std::string guessState(TARGET_WORD.length(), '-');
	std::string usedLetters = "";
	
	std::cout << "Welcome to Hangman.\n";
	
	
	while ((wrongGuesses < MAX_WRONG) && (guessState != TARGET_WORD))
	{
		std::cout << "So far, the word is:\n";
		std::cout << guessState << std::endl;
		std::cout << "You have guessed the following letters:\n";
		std::cout << usedLetters << std::endl;
		std::cout << "You have " << MAX_WRONG - wrongGuesses << " wrong guesses left.\n\n";
		
		// Get user input
		char guess = getLetter(usedLetters);
		
		usedLetters += guess;
		
		if (!checkForLetter(guess, TARGET_WORD, guessState))
			wrongGuesses++;
		
	}
	if (wrongGuesses == MAX_WRONG)
	{
		std::cout << "\nYou've been hanged!\n";
	}
	else
	{
		std::cout << "\nYou guessed it!\n";
	}
	std::cout << "The word was " << TARGET_WORD << std::endl;
	
	return 0;
}
	

