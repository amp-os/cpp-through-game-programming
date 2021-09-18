// Give me a number

#include <iostream>
#include <string>

int askNumber(int high, int low = 1);

int main()
{
	int number = askNumber(5);
	std::cout << "Thanks for entering " << number << "\n\n";
	
	number = askNumber(10, 5);
	std::cout << "Thanks for entering " << number << "\n\n";
	
	return 0;
}

int askNumber(int high, int low)
{
	int num;
	do
	{
		std::cout << "Enter a number" << " (" << low << " - " << high << "): ";
		std::cin >> num;
	} while (num > high || num < low);
	
	return num;
}