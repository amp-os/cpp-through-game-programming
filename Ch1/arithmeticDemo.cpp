// Expensive Calculator
// Demo of built in operations

#include <iostream>

int main()
{
	std::cout << "7 + 3 = " << 7 + 3 << std::endl;
	std::cout << "7 - 3 = " << 7 - 3 << std::endl;
	std::cout << "7 * 3 = " << 7 * 3 << std::endl;
	
	std::cout << "7 / 3 = " << 7 / 3 << std::endl;
	std::cout << "7.0 / 3.0 = " << 7.0 / 3.0 << std::endl;
	std::cout << "7.0 / 3 = " << 7.0 / 3 << std::endl;
	std::cout << "7 / 3.0 = " << 7 / 3.0 << std::endl;
	
	std::cout << "7 % 3 = " << 7 % 3 << std::endl;
	
	std::cout << "7 + 3 * 5 = " << 7 + 3 * 5 << std::endl;
	std::cout << "(7 + 3) * 5 = " << (7 + 3) * 5 << std::endl;
	
	return 0;
}