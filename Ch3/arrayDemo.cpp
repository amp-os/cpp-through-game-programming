// Array demo

#include <iostream>
#include <string>

int main()
{
	const int MAX_ITEMS = 10;
	std::string inventory[MAX_ITEMS];
	
	int numItems = 0;
	inventory[numItems++] = "sword";
	inventory[numItems++] = "shield";
	inventory[numItems++] = "armour";
	
	std::cout << "Your items:\n";
	for (int i = 0; i < numItems; i++)
	{
		std::cout << inventory[i] << std::endl;
	}
	
	std::cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";
	
	std::cout << "\nYour items:\n";
	for (int i = 0; i < numItems; i++)
	{
		std::cout << inventory[i] << std::endl;
	}
	
	std::cout << "\nThe item name '" << inventory[0] << "' has ";
	std::cout << inventory[0].size() << " letters in it.\n";
	
	std::cout << "\nYou find a healing potion.";
	if (numItems < MAX_ITEMS)
	{
		inventory[numItems++] = "healing potion";
	}	
	else
	{
		std::cout << "You have too many items and can't carry another.";
	}
	
	std::cout << "\nYour items:\n";
	for (int i = 0; i < numItems; i++)
	{
		std::cout << inventory[i] << std::endl;
	}	
	return 0;
}