// Vector demo

#include <iostream>
#include <string>
#include <vector>

void printItems(std::vector<std::string>& inventory)
{
	std::cout << "\nYour items:\n";
	for (int i = 0; i < inventory.size(); i++)
		std::cout << inventory[i] << std::endl;
}

int main()
{
	std::vector<std::string> inventory;
	inventory.push_back("sword");
	inventory.push_back("shield");
	inventory.push_back("armour");
	
	std::cout << "You have " << inventory.size() << " items.\n";
	
	printItems(inventory);
	
	std::cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";
	std::cout << "\nThe " << inventory[0] << " has " << inventory[0].size() << " letters.\n";
	
	printItems(inventory);
	
	std::cout << "\nYour armour has been damaged.";
	inventory.pop_back();
	
	printItems(inventory);
	
	std::cout << "\nYou were robbed of all your possessions by a thief.";
	inventory.clear();
	
	if (inventory.empty())
		std::cout << "\nYou have no items.\n";
	else
		std::cout << "\nYou have at least one item.\n";
	
	return 0;
}