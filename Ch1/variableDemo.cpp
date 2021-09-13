// Variable Demo

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int score;
	double distance;
	char playAgain;
	bool shieldsUp;
	
	short lives, aliensKilled; // short means short int
	
	score = 0;
	distance = 1200.76;
	playAgain = 'y';
	shieldsUp = true;
	lives = 3;
	aliensKilled = 10;
	double engineTemp = 6572.89;
	
	cout << "\nscore " << score << endl; // escape sequence
	cout << "distance: " << distance << endl;
	cout << "playAgain: " << playAgain << endl;
	cout << "shieldsUp: " << shieldsUp << endl; // true prints as "1"
	cout << "lives: " << lives << endl;
	cout << "aleinsKilled: " << aliensKilled << endl;
	cout << "engineTemp: " << engineTemp << endl;
	
	int fuel;
	cout << "\nHow much fuel? ";
	cin >> fuel;
	cout << "fuel: " << fuel << endl;
	
	typedef unsigned short int ushort;
	ushort bonus = 10;
	cout << "\nbonue: " << bonus << endl;
	
	return 0;
}