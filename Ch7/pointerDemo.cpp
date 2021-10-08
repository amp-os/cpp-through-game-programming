#include <iostream>

int main()
{
	int a = 10;
	int& b = a;
	int* c = &b;
	
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << c << std::endl;
	
	return 0;
}