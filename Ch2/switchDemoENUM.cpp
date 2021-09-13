// Difficulty Chooser

#include <iostream>

int main()
{
	enum difficulty {EASY = 1, REGULAR, HARD};

	std::cout << "Enter your preferred difficulty:" << std::endl;
	std::cout << EASY << " - EASY\n";
	std::cout << REGULAR << " - REGULAR\n";
	std::cout << HARD << " - HARD\n" << std::endl;
	
	int choice;
	std::cout << "Choice: ";
	std::cin >> choice;
	
	switch (choice)
	{
		case EASY:
			std::cout << "You picked EASY." << std::endl;
			break;
		case REGULAR:
			std::cout << "You picked REGULAR." << std::endl;
			break;
		case HARD:
			std::cout << "You picked HARD." << std::endl;
			break;
		default:
			std::cout << "I didn't recognise that choice." << std::endl;
	}
	
	return 0;
}