// Score Rater

#include <iostream>

int main()
{
	int score;
	std::cout << "Enter your high score: ";
	std::cin >> score;
	
	if (score >= 1000)
		std::cout << "1000 or more is good, man." << std::endl;
	else if (score >= 500)
		std::cout << "500 or more, you know, I'm proud of you." << std::endl;
	else if (score >= 250)
		std::cout << "You scored 250 or more, not bad!" << std::endl;
	else if (score)
		std::cout << "At least you didn't score zero." << std::endl;
	else
		std::cout << "Damn, not even one point..." << std::endl;
	
	return 0;
}