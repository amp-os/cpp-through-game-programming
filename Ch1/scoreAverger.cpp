// Score average

#include <iostream>

int main()
{
	int score1, score2, score3;
	std::cout << "Welcome to the SCORE AVERAGIZER!" << std::endl;
	std::cout << "\nEnter your first score: ";
	std::cin >> score1;
	std::cout << "\nEnter your second score: ";
	std::cin >> score2;
std::cout << "\nEnter your third score: ";
	std::cin >> score3;
	
	float average = (score1 + score2 + score3) / 3.0;
	
	std::cout << "\nWOAH! On average you scored a phenomenal " << average << " points." << std::endl; 
	
	return 0;
}