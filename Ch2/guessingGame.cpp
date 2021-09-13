// Guess the number

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	// seed rng
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	// generate target number
	int target = (std::rand() % 100) + 1;

	// variables
	int guess, count = 0;
	
	std::cout << "\nI'm thinking of a number between 1 and 100..." << std::endl;;
	
	do
	{
		std::cout << "Take a guess: ";
		std::cin >> guess;
		count++;
		
		if (guess < target)
		{
			std::cout << "Too low!\n" << std::endl;
		}
		else if (guess > target)
		{
			std::cout << "Too high!\n" << std::endl;
		}
		else if (guess == target)
		{
			std::cout << "Bang on! You took " << count << " guesses." << std::endl;
		}
	} while (guess != target);
	
	
	return 0;
}