// Word jumble

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;

int main()
{
	// SET UP
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{	{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"laboured", "Going slow, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."} };
	
	// set up random
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	// set up game conditions
	int choice = std::rand() % NUM_WORDS;
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];
	
	int score = theWord.length();
	
	// jumble word
	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
	int index1 = std::rand() % length;
	int index2 = std::rand() % length;
	char temp = jumble[index1];
	jumble[index1] = jumble[index2];
	jumble[index2] = temp;
	}
	
	// CONSOLE OUTPUT set up
	
	std::cout << "\tWORD JUMBLE\n\n";
	std::cout << "Unscramble the letters to make a word.\n";
	std::cout << "Enter 'hint' for a hint.\n";
	std::cout << "Enter 'quit' to quit the game.\n\n";
	std::cout << "The jumble is: " << jumble;
	
	string guess;
	std::cout << "\n\nTake a guess: ";
	std::cin >> guess;
	
	// GAME LOOP
	
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			std::cout << theHint;
			score -= 5;
		}
		else
			std::cout << "That's not it.";
		
		std::cout << "\n\nYour guess: ";
		std::cin >> guess;
	}
	
	if (guess == theWord)
		std::cout << "You got it, well done!\nYou scored " << score << std::endl;
	
	std::cout << "Thanks for playing." << std::endl;
	
	return 0;
}