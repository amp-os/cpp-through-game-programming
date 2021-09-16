// My list

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::cout << "Here you can keep a list.\n";
	
	std::vector<std::string> myList;
	std::cout << "Add an item by typing 'add x', where x is your item.\n";
	std::cout << "Remove an item by typing 'remove x'.\n";
	std::cout << "To exit type 'quit'.\n";
	
	std::string input;
	
	while (input.find("quit") != 0)
	{
		if (myList.empty())
		{
			std::cout << "The list is currently empty.\n";
		}
		else
		{
			std::cout << "The current list:\n";
			for (int i = 0; i < myList.size(); i++)
			{
				std::cout << i + 1 << ".\t" << myList[i] << std::endl;
			}
		}
		
		std::cout << "\nType an instruction: ";
		std::getline(std::cin, input);
				
		if (input.find("add ") == 0)
		{
			std::cout << "Adding " << input.erase(0, 4) << std::endl; // remove the first four char ('add ')
			myList.push_back(input);
		}
		else if (input.find("remove ") == 0)
		{
			std::string search = input.erase(0, 7); // remove first 7 char ('remove ')
			std::vector<std::string>::iterator iter;
			std::vector<std::string>::iterator iterator;
			bool found = false;
			
			for (iter = myList.begin(); iter != myList.end(); iter++)
			{
				if (*iter == search)
				{
					iterator = iter;
					found = true;
				}
			}
			if (found)
			{
				std::cout << "Removed " << *iterator << std::endl;
				myList.erase(iterator);
			}
			else
			{
				std::cout << "I couldn't find that to remove.\n";
			}
		}	
	}
	std::cout << "You have quit. Your list will not be saved.\n";

	return 0;
}