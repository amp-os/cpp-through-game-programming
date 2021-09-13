// While Loop

#include <iostream>

int main()
{
	char again = 'y';
	while (again == 'y')
	{
		std::cout << "\nYou just played a fantastic game.";
		std::cout << "\nDo you want to play again? (y/n): ";
		std::cin >> again;
	}
	std::cout << "You have selected no." << std::endl;
	return 0;
}