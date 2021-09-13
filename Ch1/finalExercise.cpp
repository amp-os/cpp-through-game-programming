// Final Exercise

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	const int GOLD_PIECES = 900;
	int adventurers, killed, survivors;
	string leader;
	
	//get user input
	cout << "Welcome to Lost Fortune\n\n";
	cout << "Please enter the following for your personalised adventure\n";
	cout << "Enter a number: ";
	cin >> adventurers;
	
	cout << "Enter a smaller number: ";
	cin >> killed;
	
	survivors = adventurers - killed;
	
	cout << "Enter your last name: ";
	cin >> leader; // No whitespace allowed!
	
	//tell the story
	
	cout << "\nA brave group of " << adventurers << " set out on a quest ";
	cout << "-- in search of the lost treasure of the Cats. ";
	cout << "The group was lead by legendary explorer " << leader << ".\n";
	cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
	cout << "All fought bravely under " << leader << "'s command,";
	cout << "and the ogres were defeated, but at a cost. ";
	cout << "Of the adventurers, " << killed << " were killed, leaving just ";
	cout << survivors << " survivors.\n";
	cout << "The party was about to turn back, but while looting the ogres' corpses,";
	cout << " esteemed leader " << leader << " found a map leading to ";
	cout << "the treasure of the Cats. ";
	cout << GOLD_PIECES << " pieces of gold were found and split between the ";
	cout << survivors << " party members.\n" << leader << " held on to the remaining ";
	cout << GOLD_PIECES % survivors << " pieces." << endl;

	return 0;
}