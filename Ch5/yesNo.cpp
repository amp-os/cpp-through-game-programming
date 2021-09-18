// Yes or No

#include <iostream>
#include <string>

char askYesNo1();
char askYesNo2(std::string);
int main()
{
	char answer1 = askYesNo1();
	std::cout << "Thanks for answering: " << answer1 << "\n\n";
	
	char answer2 = askYesNo2("Do you wish to save your game?");
	std::cout << "Thanks for answering: " << answer2 << "\n\n";
	
	return 0;
}

char askYesNo1()
{
	char response1;
	do
	{
		std::cout << "Please enter 'y' or 'n': ";
		std::cin >> response1;
	} while (response1 != 'y' && response1 != 'n');
	return response1;
}

char askYesNo2(std::string question)
{
	char response2;
	do
	{
		std::cout << question << " (y/n): ";
		std::cin >> response2;
	} while (response2 != 'y' && response2 != 'n');
	
	return response2;
}