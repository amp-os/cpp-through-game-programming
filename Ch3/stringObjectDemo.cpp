// String object demo

#include <iostream>
#include <string>

using std::string;

int main()
{
	string word1 = "Game";
	string word2("Over");
	string word3(3, '!');
	
	string phrase = word1 + " " + word2 + word3;
	std::cout << "The phrase is " << phrase << "\n\n";
	
	std::cout << "The phrase has " << phrase.size() << " characters.\n\n";
	
	std::cout << "The character at position 0 is: " << phrase[0] << ".\n\n";
	
	std::cout << "Changing that character...\n";
	phrase[0] = 'L';
	std::cout << "The phrase is now: " << phrase << ".\n\n";
	
	for (unsigned int i = 0; i < phrase.size(); i++) // string.size() returns unsigned int
	{
		std::cout << "Character at position " << i << " is: " << phrase[i] << std::endl;
	}
	
	std::cout << "\nThe sequence 'Over' begins at position: ";
	std::cout << phrase.find("Over") << std::endl;
	
	if (phrase.find("eggplant") == string::npos)
		std::cout << "\n'eggplant' is not present in the phrase.\n\n";
	
	phrase.erase(4, 5);
	std::cout << "The phrase is now " << phrase << std::endl;
	
	phrase.erase(4);
	std::cout << "\nThe phrase is now " << phrase << std::endl;
	
	phrase.erase();
	std::cout << "\nThe phrase is now " << phrase << std::endl;
	
	if (phrase.empty())
		std::cout << "\nThe phrase is empty.\n";
	
	return 0;
}