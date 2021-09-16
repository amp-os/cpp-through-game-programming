// Vector algorithm demo

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void printScores(std::vector<int>& scores)
{
	std::cout << "\nHigh Scores:\n";
	
	for (std::vector<int>::const_iterator iter = scores.begin(); iter != scores.end(); iter++)
		std::cout << *iter << std::endl;
}

int main()
{	
	std::cout << "Creating a list of scores.";
	std::vector<int> scores;
	scores.push_back(7500);
	scores.push_back(3500);
	scores.push_back(1500);
	
	printScores(scores);
	
	std::cout << "\nFinding a score,";
	int score;
	std::cout << "\nEnter a score to find: ";
	std::cin >> score;
	
	std::vector<int>::const_iterator finder;
	finder = std::find(scores.begin(), scores.end(), score);
	if (finder != scores.end())
		std::cout << "Score found.\n";
	else
		std::cout << "Score not found.\n";
	
	std::cout << "\nRandomising scores.";
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(scores.begin(), scores.end(), g);
	
	printScores(scores);
	
	std::cout << "\nSorting scores.";
	std::sort(scores.begin(), scores.end());
	
	printScores(scores);
	
	return 0;
}