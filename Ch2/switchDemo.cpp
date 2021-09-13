// Difficulty Chooser

#include <iostream>

int main()
{
	std::cout << "Enter your preferred difficulty:" << std::endl;
	std::cout << "1 - EASY\n";
	std::cout << "2 - REGULAR\n";
	std::cout << "3 - HARD\n" << std::endl;
	
	int choice;
	std::cout << "Choice: ";
	std::cin >> choice;
	
	switch (choice)
	{
		case 1:
			std::cout << "You picked EASY." << std::endl;
			break;
		case 2:
			std::cout << "You picked REGULAR." << std::endl;
			break;
		case 3:
			std::cout << "You picked HARD." << std::endl;
			break;
		default:
			std::cout << "I didn't recognise that choice." << std::endl;
	}
	
	return 0;
}