// Mad lib

#include <iostream>
#include <string>

std::string askText(std::string prompt);
int askNumber(std::string prompt);
void tellStory(std::string& name, std::string& noun, int& number, std::string& bodyPart, std::string& verb);

int main()
{
	std::cout << "Welcome to Mad Lib.\n\n";
	std::cout << "Answer the following questions.\n";
	std::string name = askText("Please enter a name: ");
	std::string noun = askText("Enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	std::string bodyPart = askText("Enter a body part: ");
	std::string verb = askText("Enter a verb: ");
	
	tellStory(name, noun, number, bodyPart, verb);
	
	return 0;
}

std::string askText(std::string prompt)
{
	std::string text;
	std::cout << prompt;
	std::cin >> text;
	return text;
}

int askNumber(std::string prompt)
{
	int num;
	std::cout << prompt;
	std::cin >> num;
	return num;
}

void tellStory(std::string& name, std::string& noun, int& number, std::string& bodyPart, std::string& verb)
{
	std::cout << "\nHere's your story:\n";
	std::cout << "The famous explorer ";
	std::cout << name;
	std::cout << " had nearly given up a life-long quest to find\n";
	std::cout << "The Lost City of " << noun;
	std::cout << " when one day, the ";
	std::cout << noun;
	std::cout << " found the explorer.\n";
	std::cout << "Surrounded by ";
	std::cout << number;
	std::cout << " " << noun;
	std::cout << ", a tear came to " << name << "'s ";
	std::cout << bodyPart << ".\n";
	std::cout << "After all this time, the quest was finally over. ";
	std::cout << "And then, the ";
	std::cout << noun << "\n";
	std::cout << "promptly devoured " << name << ".\n";
	std::cout << "The moral of the story? Be careful what you " << verb << " for.\n";
}