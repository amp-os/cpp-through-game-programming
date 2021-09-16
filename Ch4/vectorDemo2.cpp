// Vector demo

#include <iostream>
#include <string>
#include <vector>

void printItems(std::vector<std::string>& inventory, std::vector<std::string>::const_iterator& iter)
{
	std::cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
		std::cout << *iter << std::endl;
}

int main()
{
	std::vector<std::string> inventory;
	inventory.push_back("sword");
	inventory.push_back("shield");
	inventory.push_back("armour");
	
	std::vector<std::string>::iterator myIterator;
	std::vector<std::string>::const_iterator iter;
	
	std::cout << "You have " << inventory.size() << " items.\n";
	
	printItems(inventory, iter);
	
	std::cout << "\nYou trade your sword for a battle axe.";
	myIterator = inventory.begin();
	*myIterator = "battle axe";
	std::cout << "\nThe " << *myIterator << " has " << myIterator->size() << " letters.\n";
	
	printItems(inventory, iter);
	
	std::cout << "\nYou loot a crossbow.\n";
	inventory.insert(inventory.begin(), "crossbow");
	std::cout << "\n" << *myIterator << "\n";
	printItems(inventory, iter);
	
	std::cout << "\nYour shield has been damaged.";
	inventory.erase(inventory.begin() + 2);
	
	printItems(inventory, iter);
	
	std::cout << "\nYou were robbed of all your possessions by a thief.";
	inventory.clear();
	
	if (inventory.empty())
		std::cout << "\nYou have no items.\n";
	else
		std::cout << "\nYou have at least one item.\n";
	
	return 0;
}