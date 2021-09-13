#include <iostream>

int main()
{
	char again;
	do
	{
		std::cout << "\nYou played an exciting game.";
		std::cout << "\nPlay again? (y/n): ";
		std::cin >> again;
	} while (again == 'y');
	
	std::cout << "\nYou said no.\n";
	
	return 0;
}