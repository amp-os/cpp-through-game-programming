// Get number

#include <iostream>

int getNumber(const char* prompt = "Enter a number: ")
{
	int num;	
	std::cout << prompt;
	std::cin >> num;
	return num;
}

int getNum(const char* prompt)
{
	int num;	
	std::cout << prompt;
	std::cin >> num;
	return num;
}

int getNum()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	return num;
}

int main()
{
	int num = getNumber();
	std::cout << "You entered " << num << "\n\n";
	num = getNumber("Enter another: ");
	std::cout << "You entered " << num << "\n\n";
	
	num = getNum();
	std::cout << "You entered " << num << "\n\n";	
	num = getNum("Enter another: ");
	std::cout << "You entered " << num << "\n\n";	
	
	return 0;
}