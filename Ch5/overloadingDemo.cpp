// Overloading demo

#include <iostream>
#include <string>

int triple(int num);
std::string triple(std::string text);

int main()
{
	std::cout << "Tripling 5: " << triple(5) << "\n\n";
	std::cout << "Tripling 'gamer': " << triple("gamer") << "\n\n";
	
	return 0;
}

int triple(int num)
{
	return (num * 3);
}

std::string triple(std::string text)
{
	return (text + text + text);
}