// Dice roll

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	// seed rng
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	int randomNumber = std::rand();
	
	// limit rn to 1-6
	int die = (randomNumber % 6) + 1;
	
	std::cout << "You rolled " << die << std::endl;
	
	return 0;
}