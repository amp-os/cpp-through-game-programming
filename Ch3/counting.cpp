// Counter

#include <iostream>

int main()
{
	std::cout << "Counting forwards:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
	}
	
	std::cout << "\nCounting backwards:" << std::endl;
	for (int i = 9; i >= 0; i--)
	{
		std::cout << i << " ";
	}
	
	std::cout << "\nCounting in fives:" << std::endl;
	for (int i = 0; i <= 50; i += 5)
	{
		std::cout << i << " ";
	}
	
	std::cout << "\nCounting with null statements:" << std::endl;
	int count = 0;
	for ( ; count < 10; )
	{
		std::cout << count++ << " ";
	}
	
	std::cout << "\nCounting on a grid:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// Prints (i,j) in rows of 10
			std::cout << i << "," << j << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}